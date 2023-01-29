#include <iostream>
#include <unistd.h>	//Plik nagłówkowy, w kórym jest zadeklarowana użyta poniżej funkcja sleep()

#include "sensor.h"		//Plik nagłówkowy, w którym należy zadeklarować klasy reprezentujące czujniki
#include "base.h"		//Plik nagłówkowy, w kórym należy zadeklarować klasę reprezentującą stację bazową
#include "exception.h"	// Plik nagłówkowy zawierający definicję klasy wyjątku

using namespace std;

int main()
{
	const CTemperatureSensor TemperatureSensor(-35.0, -30.0);	//Utworzenie obiektu reprezentującego czujnik temperatury
	const CHumiditySensor HumiditySensor(95.0, 100.0);				//Utworzenie obiektu reprezentującego czujnik wilgotności
	const CPressureSensor PressureSensor(950, 1050);				//Utworzenie obiektu reprezentującego czujnik ciśnienia atmosferycznego
	const CTemperatureSensor TemperatureSensor2(-35.0, -30.0);	//Utworzenie obiektu reprezentującego czujnik temperatury
	const CHumiditySensor HumiditySensor2(95.0, 100.0);				//Utworzenie obiektu reprezentującego czujnik wilgotności
	const CPressureSensor PressureSensor2(950, 1050);				//Utworzenie obiektu reprezentującego czujnik ciśnienia atmosferycznego
	const CWindSensor WindSensor(0, 10000);		
	const CWindSensor WindSensor2(0, 10000);
	const CWindSensor WindSensor3(0, 10000);	
	const CWindSensor WindSensor4(0, 10000);				//Utworzenie obiektu reprezentującego czujnik prędkości wiatru
	const CInsolationSensor InsolationSensor(0, 1000);				//Utworzenie obiektu reprezentującego czujnik nasłonecznienia
	const CInsolationSensor InsolationSensor2(0, 1000);

	CBase Base1(5);	//Utworzenie pierwszego obiektu reprezentującego stację bazową

	try
	{
		Base1.setSensor(&TemperatureSensor);		//Przekazanie stacji bazowej adresu czujnika temperatury

	}
	catch (CException& e)
	{
		cout << "Adding sensors failed with message:" << e.GetMessage() << endl;
	}

	CBase Base2(Base1);										//Utworzenie drugiego obiektu reprezentujacego stacje bazowa jako kopii pierwszego
	//CBase Base2 = Base1;								//Wykorzystanie operatora przypisania
	try
	{	
		Base1.setSensor(&HumiditySensor);			//Przekazanie stacji bazowej adresu czujnika wilgotności
		Base1.setSensor(&PressureSensor);			//Przekazanie stacji bazowej adresu czujnika ciśnienia atmosferycznego
		Base1.setSensor(&TemperatureSensor2);
		Base1.setSensor(&HumiditySensor2);
		Base1.setSensor(&PressureSensor2);
		Base1.setSensor(&InsolationSensor);		
		Base1.setSensor(&InsolationSensor2);
		
	}
	catch (CException& e)
	{
		cout << "Adding sensors failed with message: 1" << e.GetMessage() << endl;
	}

	try
	{	
		Base2.setSensor(&InsolationSensor);		//Przekazanie stacji bazowej adresu czujnika nasłonecznienia
		Base2.setSensor(&InsolationSensor2);	
		Base2.setSensor(&WindSensor);
		Base2.setSensor(&WindSensor2);
		Base2.setSensor(&WindSensor3);
		Base2.setSensor(&WindSensor4);
		Base2.setSensor(&HumiditySensor);			//Przekazanie stacji bazowej adresu czujnika wilgotności
		Base2.setSensor(&PressureSensor);	
	}
	catch (CException& e)
	{
		cout << "Adding sensors failed with message: 2" << e.GetMessage() << endl;
	}

	//while(true)							//Pętla nieskończona (przerwanie programu wymaga użycia klwiszy Ctrl+C)
	{
		cout << "B1" << endl;
		Base1.displayMeasurements();		//Odczyt danych z czujników i wyświetlenie danych w konsoli
		cout << "B2" << endl;
		Base2.displayMeasurements();		//Odczyt danych z czujników i wyświetlenie danych w konsoli
		//sleep(3);								//3-sekundowa pauza
	};

	return 0;
}
