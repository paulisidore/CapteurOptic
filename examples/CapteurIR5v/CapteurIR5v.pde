#include <CapteurOptic.h>
//CapteurIR Signal de sorti connecté à Arduino Pin 5 ;
//CapteurOptic capteur(int pinInput,int EtatON=0,int EtatOFF=1,int Temp_Presence=500, int AddInputPullUp=1);

/* 
  Créer un capteur sur le port 5, 
  0 pour Etat Bas -> Objet Present et,
  1 EtatHaut pour absence d'objet, 
  100ms pour le temps de présence minimal, 
  1 pour auriser une resistance pullup sur le port
*/
/*
 * Connexion capteur Infra Rouge E18-D80NK.
 * Cable Marron: VCC 5V 
 * Cable Blue: GND
 * Cable Noir: Signal Retour a conntecter sur Arduino avec Resistance
 */
CapteurOptic capteur(5,0,1,100,1); 
int DetectionPrec=0;

void setup()
{
  Serial.println("Test du Capteur IR connecté au port 5") ;
  Serial.println("Placer un objet devant le capteur...");
}

void loop()
{
  if (capteur.Etat()){
    if (DetectionPrec==0){
      Serial.println("Un Objet est présent") ;
    }    
    DetectionPrec=1;
  }else{
    if (DetectionPrec==1){
      Serial.println("Objet absent du capteur.");
      DetectionPrec=0;
    }
  }

 
}

