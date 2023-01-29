/*---------------------------------------------------------------------------------------------*/
/* Fragment pliku base.h - pola oznaczone znakami zapytania należy uzupełnić odpowiednim kodem */
/*---------------------------------------------------------------------------------------------*/

#include <assert.h>	//Plik nagłówkowy niezbędny do poprawnego działania funkcji assert()
#include "exception.h"
#include <vector>
#include <iostream>

#define MAX_NUMBER_OF_SENSORS 5

class CBase
{
private:
	/*vector < CSensor* > Sensors;
	unsigned int max_size;	*/

	int vectorSize; 
	const CSensor** Sensors = new const CSensor*[MAX_NUMBER_OF_SENSORS];	//Wektor przechowujący adresy obiektów reprezentujących czujniki	
	unsigned int numSensors = 0;				//Zmienna określająca ilość dodanch adresów czujników		
						

 public:


	CBase(int vectorSiz = MAX_NUMBER_OF_SENSORS) : vectorSize(vectorSiz) {}		//Konstruktor

	friend ostream & operator << (ostream & os, const CBase & base)				
		{
			for (unsigned int i = 0; i < base.numSensors; ++i)
			{
				os << *base.Sensors[i];
			}
			return os;
		}


	~CBase()																	//Destruktor
	{
		delete[] Sensors;
	}

	CBase(const CBase& other)													//Konstruktor kopiujący
	{
		Sensors = new const CSensor*[other.vectorSize];
		for(unsigned int i = 0; i < other.numSensors; ++i)
		{
			this->Sensors[i] = other.Sensors[i];
		}
		vectorSize = other.vectorSize;
		numSensors = other.numSensors;
	}	

	const CBase& operator= (const CBase& other)									//Operator przypisania
	{
		const CSensor** anotherSensor = new const CSensor*[other.numSensors];
		delete[] Sensors;
		Sensors = anotherSensor;
		vectorSize = numSensors;
		for(unsigned int i = 0; i < numSensors; ++i)
		{
			Sensors[i] = other.Sensors[i];
		}
		return *this;
	} 

	const CBase& operator+= (const CSensor& other)									//Operator +=
		{
			this->setSensor(&other);
			return *this;
		} 


	const CBase& operator-= (const CSensor& other)									//Operator -=
			{
				bool removed = false;
				int offset = 0;
				const CSensor** temp = new const CSensor*[numSensors - 1];
				for (unsigned int i = 0; i < numSensors; ++i)
				{
					if(Sensors[i] != &other)
					{
						temp[offset] = Sensors[removed ? offset + 1: offset];	
						offset++;
					}
					else
					{
						removed = true;
					}	
				}
				if(removed)
				{
					Sensors = temp;
					numSensors--;
				}
				else
				{
					throw CException("Already removed!");
				}

				return *this;
			} 


	void setSensor(const CSensor* pSensor)											//Metoda dodająca adresy kolejnych czujników
	{
		if (MAX_NUMBER_OF_SENSORS > numSensors)
		{
			Sensors[numSensors] = pSensor;
			//Sensors.push_back(pSensor);
			++numSensors;
		}
		else
		{
			throw CException("CBase full!");
		}
	}

	void displayMeasurements()													//Metoda pobierająca i wyświetlająca w konsoli dane z czujników
	{
		for(unsigned int i=0; i<numSensors; ++i)
		{
			const CSensor* pSensor = Sensors[i];
			cout << "Current " << pSensor->getName() << ": " << pSensor->getMeasurement() << ' ' << pSensor->getUnit() << endl;
		}
		cout << endl;
	}

};







/*CBase(int size)										//Konstruktor vector
	{
		max_size = size;
	}

	~CBase()											//Destruktor vector
	{
		Sensors.clear();
	}
	
	CBase(const CBase &other)							//Konstruktor kopiujacy vector
	{
		Sensors = other.Sensors;
		max_size = other.max_size;
	}							
		
	const CBase& operator=(const CBase& other)				//Operator przypisania vector
	{
		if(this != &other)
		{
			vector < CSensor* > anotherSensor = other.Sensors;
			vector < CSensor* >().swap(Sensors);	//usuniecie i dealokacja wektora Sensors
			max_size = other.max_size;
			Sensors.swap(anotherSensor);
		}
		return *this;
	}

	void setSensor(CSensor* pSensor)			//Metoda dodająca adresy kolejnych czujników vector
	{
		unsigned int current_size = Sensors.size();
		if(current_size < max_size)
		{
			Sensors.push_back(pSensor);
		}
		else
		{
			throw CException("CBase full!");
		} 
	}

	void displayMeasurements()					//Metoda pobierająca i wyświetlająca w konsoli dane z czujników vector
	{
		unsigned current_size = Sensors.size();
		for(unsigned int i=0; i<current_size; ++i)
		{
			CSensor* pSensor = Sensors[i];
			cout << "Current " << pSensor->getName() << ": " << pSensor->getMeasurement() << ' ' << pSensor->getUnit() << endl;
		}
		cout << endl;
	} */