/*-----------------------------------------------------------------------------------------------*/
/* Fragment pliku sensor.h - pola oznaczone znakami zapytania należy uzupełnić odpowiednim kodem */
/*-----------------------------------------------------------------------------------------------*/

#include <string>
using namespace std;

float getRandomNumber(float lowLimit, float highLimit)
{
	return ((float)random()/RAND_MAX * (highLimit-lowLimit)) + lowLimit;
}

class CSensor
{
private:
	float lowLimit;
	float highLimit;
	float Measurement;

	float makeMeasurement() const  {return getRandomNumber(lowLimit, highLimit);}

protected:
	void checkLimits(float lowL, float highL)
	{
		if(lowLimit < lowL)
			lowLimit = lowL;
		if(highLimit > highL)
			highLimit = highL;
	}

public:
	CSensor(float lowLimit, float highLimit) :
	lowLimit(lowLimit),
	highLimit(highLimit)
	{}

	friend ostream & operator << (ostream & os, const CSensor & sensor)
			{
				os << "Current " << sensor.getName() << ": " << sensor.getMeasurement() << ' ' << sensor.getUnit() << endl;
				return os;
			}

	float getMeasurement() const				////<--------
	{
		//Measurement = makeMeasurement();
		return makeMeasurement();
	}

	virtual string getName() const = 0;
	virtual string getUnit() const = 0;
};

class CTemperatureSensor : public CSensor
{
public:
	CTemperatureSensor(float lowLimit, float highLimit) : CSensor(lowLimit, highLimit)				//Konstruktor
    {
        const float lowL = -20;
        const float highL = 50;
        checkLimits(lowL, highL);
    }

    virtual string getName() const {return "temperature"; }				//// <---------
	virtual string getUnit() const {return "stopni Celsjusza"; }	
};
class CHumiditySensor : public CSensor
{
public:
	CHumiditySensor(float lowLimit, float highLimit) : CSensor(lowLimit, highLimit)				//Konstruktor
    {
        const float lowL = 0;
        const float highL = 80;
        checkLimits(lowL, highL);
    }	

	virtual string getName() const {return "humidity"; }
	virtual string getUnit() const {return "%"; }
};


class CPressureSensor : public CSensor
{
public:
	CPressureSensor(float lowLimit, float highLimit) : CSensor(lowLimit, highLimit)				//Konstruktor
    {
        const float lowL = 1000;
        const float highL = 1100;
        checkLimits(lowL, highL);
    }	

	virtual string getName() const {return "atmospheric pressure"; }
	virtual string getUnit() const {return "hPa"; }
};

class CWindSensor : public CSensor
{
public:
	CWindSensor(float lowLimit, float highLimit) : CSensor(lowLimit, highLimit)				//Konstruktor
    {
        const float lowL = 0;
        const float highL = 6;
        checkLimits(lowL, highL);
    }	

	virtual string getName() const {return "wind speed"; }
	virtual string getUnit() const{return "m/s"; }

};

class CInsolationSensor : public CSensor
{
public:
	CInsolationSensor(float lowLimit, float highLimit) : CSensor(lowLimit, highLimit)				//Konstruktor
    {
        const float lowL = 5;
        const float highL = 100;
        checkLimits(lowL, highL);
    }	

	virtual string getName() const {return "insolation"; }
	virtual string getUnit() const {return "W/m^2";}

};

