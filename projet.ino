
#define moteur_gauche_recule D1 /*recule */
#define moteur_gauche_avance D2
#define moteur_droite_avance D5
#define moteur_droite_recule D6 /*recule */

#define vitesse_moteur_gauche D4
#define vitesse_moteur_droite D3

#define capteur_gauche D7
#define capteur_droite D0

void setup(){
   Serial.begin(9600);
  pinMode(vitesse_moteur_gauche, OUTPUT); 
  pinMode(vitesse_moteur_droite, OUTPUT);
  analogWrite(vitesse_moteur_gauche, 150);
  analogWrite(vitesse_moteur_droite, 150);
  pinMode(moteur_gauche_recule, OUTPUT);
  pinMode(moteur_gauche_avance, OUTPUT);
  pinMode(moteur_droite_avance, OUTPUT);
  pinMode(moteur_droite_recule, OUTPUT);
  pinMode(capteur_gauche, INPUT);
  pinMode(capteur_droite, INPUT);
   
  
}

void loop(){
  /*1 noir 0:blanc capteu_gauche)*/
  Serial.println(digitalRead(capteur_droite));
   Serial.println(digitalRead(capteur_gauche));
 /* if ((digitalRead(capteur_gauche)==0) && (digitalRead(capteur_droite)==1)){
    /*Serial.println("noir");
    TurnLeft();
  }
  else if ((digitalRead(capteur_droite)==0)&& (digitalRead(capteur_gauche)==1)){
   /* Serial.println("noir1");
    TurnRight();
  }
  else*/
  
  if ((digitalRead(capteur_gauche)==1) && (digitalRead(capteur_droite)==0)){
    Serial.println("noir");
    TurnLeft();
  }
  else if ((digitalRead(capteur_droite)==1)&& (digitalRead(capteur_gauche)==0)){
    Serial.println("noir1");
    TurnRight();
  }
  else if ((digitalRead(capteur_gauche)==1)&&(digitalRead(capteur_droite)==1)){
    MotorForward();
  }
  else if((digitalRead(capteur_gauche)==0)&&(digitalRead(capteur_droite)==0)) {
    MotorStop();                   
  }
  delay(10);
/*forward*/
 /*digitalWrite(moteur_gauche_avance, HIGH);
  digitalWrite(moteur_droite_avance, HIGH);
  digitalWrite(moteur_gauche_recule, LOW);
  digitalWrite(moteur_droite_recule, LOW);
  }*/
 /* backward*/
 /* digitalWrite(moteur_gauche_avance, LOW);
  digitalWrite(moteur_droite_avance, LOW);
  digitalWrite(moteur_gauche_recule, HIGH);
  digitalWrite(moteur_droite_recule, HIGH);*/

}
void MotorForward() 
{
  digitalWrite(moteur_gauche_avance, HIGH);
  digitalWrite(moteur_droite_avance, HIGH);
  digitalWrite(moteur_gauche_recule, LOW);
  digitalWrite(moteur_droite_recule, LOW);
}
/*void MotorBackward(void)
{
  digitalWrite(moteur_gauche_avance, LOW);
  digitalWrite(moteur_droite_avance, LOW);
  digitalWrite(moteur_gauche_recule, HIGH);
  digitalWrite(moteur_droite_recule, HIGH);
}*/
void TurnLeft()
{
  digitalWrite(moteur_gauche_avance, LOW);
  digitalWrite(moteur_droite_avance, HIGH);
  digitalWrite(moteur_gauche_recule, HIGH);
  digitalWrite(moteur_droite_recule, LOW);
}
void TurnRight()
{
  digitalWrite(moteur_gauche_avance, HIGH);
  digitalWrite(moteur_droite_avance, LOW);
  digitalWrite(moteur_gauche_recule, LOW);
  digitalWrite(moteur_droite_recule, HIGH);
}
void MotorStop()
{
  digitalWrite(moteur_gauche_avance, LOW);
  digitalWrite(moteur_droite_avance, LOW);
  digitalWrite(moteur_gauche_recule, LOW);
  digitalWrite(moteur_droite_recule, LOW);
}
