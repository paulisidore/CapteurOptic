/*
  CapteurOptic.cpp -  Library for IR Sensor.
  Created by Paul Isidore A. NIAMIE, March 14, 2022.
  Released into the public domain.
*/

#include "Arduino.h"
#include "CapteurOptic.h"

CapteurOptic::CapteurOptic(int pinInput,int EtatON=0,int EtatOFF=1,int Temp_Presence=500, int AddInputPullUp=1)
{
  
  _pinInput = pinInput;
  BOUT_OFF=EtatOFF;
  BOUT_ON=EtatON;
  DUREE_PRESENCE_BOUT=Temp_Presence;

  _INPUT=INPUT_PULLUP ;
  if (AddInputPullUp==0){
    _INPUT=INPUT ;
  }
  last_detectTime=0;
  Ready=0;
  pinMode(pinInput, _INPUT);
  Ready=1 ;

}

int CapteurOptic::Etat(){
  static int Presence=0;

  int capBout=digitalRead(_pinInput);  
  if (capBout==BOUT_ON){    
    /* Gestion anti rebond */     
      if ((millis()-last_detectTime)>=DUREE_PRESENCE_BOUT){
        Presence=1 ;
        last_detectTime=millis() ;
      }    
  }else{
    Presence=0 ;    
  }
  return Presence ;
}
