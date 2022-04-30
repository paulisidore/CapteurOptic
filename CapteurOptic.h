/*
  CapteurOptic.h - Library for IR Sensor.
  Created by Paul Isidore A. NIAMIE, March 14, 2022.
  Released into the public domain.
*/

#ifndef CapteurOptic_h
#define CapteurOptic_h
#include "Arduino.h"

class CapteurOptic
{
  public:
    CapteurOptic(int pinInput,int EtatON,int EtatOFF,int Temp_Presence, int AddInputPullUp);
    int Etat();
    int Ready;
  private:
    int _pinInput;
    int BOUT_ON;
    int BOUT_OFF;
    unsigned long DUREE_PRESENCE_BOUT;
    int _INPUT;
    unsigned long last_detectTime=0;    
};

#endif

