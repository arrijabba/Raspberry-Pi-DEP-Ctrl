/*
 * mainFn.cpp
 *
 *  Created on: Jul 5, 2016
 *      Author: arri-c
 */

//Summary of todo stuff
/*
 * timer: basis for timer is below, but the <chrono> implementation needs to be tested on the pi
 *
 * GPIOs:
 * settings for the in/out pins to be finalized when integrating pi with DAC.
 * this applies to changing value/type/power. once again, the base code is below
 *
 */

#include <iostream>
#include <chrono>

struct Electrode{

	unsigned long interval; 		//interval in ns
	unsigned long long timestamp; 	//timestamp in ns since epoch
	int value; 						//high or low
	int type;  						//waveform shape (if customizable)
	bool running;
	int start_pin; 					//so we can find GPIO relatively for each electrode
};

int main() {
/*
 * cmd line usage
 * ./dep interval_e1 type_e1 run_e1... interval_e4 type_e4 run_e4 total_runtime
 */

	//init

	struct Electrode e1; //NW
	struct Electrode e2; //NE
	struct Electrode e3; //SE
	struct Electrode e4; //SW

	setInterval(&e1,0); //replace with arg
	setWavetype(&e1,0); //replace with arg
	if(true){on(&e1);} else{off(&e1);} //replacing 'true' with arg

	setInterval(&e2,0); //replace with arg
	setWavetype(&e2,0); //replace with arg
	if(true){on(&e2);} else{off(&e2);} //replacing 'true' with arg

	setInterval(&e3,0); //replace with arg
	setWavetype(&e3,0); //replace with arg
	if(true){on(&e3);} else{off(&e3);} //replacing 'true' with arg

	setInterval(&e4,0); //replace with arg
	setWavetype(&e4,0); //replace with arg
	if(true){on(&e4);} else{off(&e4);} //replacing 'true' with arg

	//end init

	e1.timestamp = std::chrono::system_clock::now();
	e2.timestamp = std::chrono::system_clock::now();
	e3.timestamp = std::chrono::system_clock::now();
	e4.timestamp = std::chrono::system_clock::now();

    while(true)
    {
    	if(checkTime(&e1))
    	{
    		//switch value
    	}

    	if(checkTime(&e2))
    	{
    		//switch value
    	}

    	if(checkTime(&e3))
    	{
    		//switch value
    	}

    	if(checkTime(&e4))
    	{
    		//switch value
    	}
    }
}

void setInterval(Electrode* e, unsigned long interval)
{
	e->interval = interval;
}

void setWavetype(Electrode* e, int type)
{
	e->type = type;
	//GPIO change
}

void on(Electrode* e)
{
	e->running = true;
	//GPIO change
}

void off(Electrode* e)
{
	e->running = false;
	//GPIO change
}

void switch_val(Electrode* e)
{
	if(e->value == true)
	{
		e->value = false;
		//GPIO change
	}
	else
	{
		e->value = true;
		//GPIO change
	}
}

bool checkTime(Electrode* e)
{
	if(e->timestamp + e->interval == std::chrono::system_clock::now())
	{
		//good run.
		return true;
	}
	else if(e->timestamp + e->interval < std::chrono::system_clock::now())
	{
		//miss. time now is greater than latest run + interval
		//need this for testing accuracy
		//return true but log error

		return true;
	}
	else
	{
		return false;
	}
}
