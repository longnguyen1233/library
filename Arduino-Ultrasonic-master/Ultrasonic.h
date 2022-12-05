
/*
 Ultrasonic.h - Library for controlling ping sensors
 Created by Chibuike I.P. Okpaluba October 29, 2015.
 ***************************************************
 To be Used by Chibuike, Haun, and Fredick for a
 robotic car project.
 
 This code can only be used by Middlesex Engineering Staffs
 and Students
 
 For more information e-mail Chibuike at <chibuikepraise@gmail.com>
*/


// Basically, this prevents problems if someone
// accidently #include's your library twice.

#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"

//the class definition goes here
class Ultrasonic
{
	public:
	  Ultrasonic(const int trigPin, const int echoPin, String unit);
	  float getDistance();
	private:
	  float microSecondsToIn();
	  float microSecondsToCm();
	  float microSecondsToMm();
	  int _trigPin;
	  int _echoPin;
	  float _duration;
	  unsigned int _unit;
};


#endif