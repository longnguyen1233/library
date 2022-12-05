
/*
  Ultrasonic.cpp - Library for controlling ping sensors.
  Created by Chibuike I.P. Okpaluba, October 29, 2015.
  
  To be Used by Chibuike, Haun, and Fredick for a
  robotic car project.
 
  This code can only be used by Middlesex Engineering Staffs
  and Students
 
  For more information e-mail Chibuike at <chibuikepraise@gmail.com>
*/

#include "Arduino.h"
#include "Ultrasonic.h"


Ultrasonic::Ultrasonic(const int trigPin, const int echoPin, String unit)
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	_trigPin = trigPin;
	_echoPin = echoPin;
	unit.toUpperCase();
	if (unit == "MM")
	{
		_unit = 0;
	}
	else if(unit == "CM")
	{
		_unit = 1;
	}
	else
	{
		_unit = 2;
	}
	_duration = 0;
}

float Ultrasonic::microSecondsToCm(){
	// The speed of sound is 29 um/cm
	return _duration/29;
}

float Ultrasonic::microSecondsToMm(){
	// The speed of sound is 2.94117647 um/mm
	return _duration/(2.94117647);
}

float Ultrasonic::microSecondsToIn(){
	// The speed of sound is 74.7058824 um/in
	return _duration/(74.7058824);
}

float Ultrasonic::getDistance(){
	digitalWrite(_trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(5);
	digitalWrite(_trigPin, LOW);
	
	_duration = pulseIn(_echoPin, HIGH);
	_duration /= 2;
	
	if (_unit == 1)
	{
		return microSecondsToCm();
	}
	else if (_unit == 0)
	{
		return microSecondsToMm();
	}
	else
	{
		return microSecondsToIn();
	}
}