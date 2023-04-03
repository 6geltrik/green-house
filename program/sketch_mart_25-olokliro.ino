


// ορισμός ακίδων και μεταβλητών 
const int bat = A0; //μπαταρία 
const int rel1 = 2;
const int anem = A1; //ανεμογεννήτρια
const int rel2 = 3;
const int nero = A2; // νερό 
const int rel3 = 4; 
int bateis = 0;
int batmet = 0;
int anemeis = 0;
int anemet = 0;
int neroeis = 0;
int neromet = 0;

const int upSensorPin = A3;
const int downSensorPin = A4;
int diakopin = 9;
int Pin0 = 10; 
int Pin1 = 11; 
int Pin2 = 12; 
int Pin3 = 13; 
int vima = 0; 
boolean katensi = true;//
int diakopt = HIGH;
int upSensorRead = 0;
int downSensorRead = 0;
int upLightPct = 0;
int downLightPct = 0;
int degreeChange = 0;

 // είσοδοι, έξοδοι 
void setup() { 
 pinMode(Pin0, OUTPUT);  
 pinMode(Pin1, OUTPUT);  
 pinMode(Pin2, OUTPUT);  
 pinMode(Pin3, OUTPUT);  
 pinMode(diakopin, INPUT);
 pinMode(upSensorPin,INPUT);
 pinMode(downSensorPin,INPUT);
 
 pinMode(bat,INPUT); //μπαταρία 
pinMode(rel1,OUTPUT); 
digitalWrite(rel1,LOW);
pinMode(anem,INPUT); //ανεμογεννήτρια  
pinMode(rel2,OUTPUT);
pinMode(rel2,LOW);
}
 
// κυριο προγραμμα
 void loop() { 
  upSensorRead = analogRead(upSensorPin);
  downSensorRead = analogRead(downSensorPin);
  upLightPct = map(upSensorRead, 0, 1023, 0, 100);
  downLightPct = map(downSensorRead, 0, 1023, 0, 100);
  degreeChange = abs(upLightPct-downLightPct);
  diakopt = digitalRead(diakopin);

   if(upLightPct < 95 && downLightPct < 95) {
     "ανυπαρκτος ηλιος";
     
     if(diakopt == HIGH) { " stop"; } 
   
     if(diakopt == LOW) {
     (katensi,false); 
     vima=vima-1; }
 } 

   else if(upLightPct > downLightPct && degreeChange > 1) {
     (katensi,true); //κινητηρας προς τα πανω
     vima=vima+1;  
     } 

   else if (upLightPct < downLightPct && degreeChange > 1) {
     (katensi,false); // κινητηρας προς τα κατω
     vima=vima-1; //
     }

 switch(vima){ 
   case 0: 
     digitalWrite(Pin0, LOW);  
     digitalWrite(Pin1, LOW); 
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, HIGH); 
   break;  
   case 1: 
     digitalWrite(Pin0, LOW);  
     digitalWrite(Pin1, LOW); 
     digitalWrite(Pin2, HIGH); 
     digitalWrite(Pin3, HIGH); 
   break;  
   case 2: 
     digitalWrite(Pin0, LOW);  
     digitalWrite(Pin1, LOW); 
     digitalWrite(Pin2, HIGH); 
     digitalWrite(Pin3, LOW); 
   break;  
   case 3: 
     digitalWrite(Pin0, LOW);  
     digitalWrite(Pin1, HIGH); 
     digitalWrite(Pin2, HIGH); 
     digitalWrite(Pin3, LOW); 
   break;  
   case 4: 
     digitalWrite(Pin0, LOW);  
     digitalWrite(Pin1, HIGH); 
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, LOW); 
   break;  
   case 5: 
     digitalWrite(Pin0, HIGH);  
     digitalWrite(Pin1, HIGH); 
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, LOW); 
   break;  
     case 6: 
     digitalWrite(Pin0, HIGH);  
     digitalWrite(Pin1, LOW); 
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, LOW); 
   break;  
   case 7: 
     digitalWrite(Pin0, HIGH);  
     digitalWrite(Pin1, LOW); 
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, HIGH); 
   break;  
   default: 
     digitalWrite(Pin0, LOW);  
     digitalWrite(Pin1, LOW); 
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, LOW); 
   break;  
 }

 if(vima>7){ vima=0;  } 
 if(vima<0){ vima=7;  } 
 delay(1); 

   bateis = analogRead(bat); // έλεγχος μπαταρίας
  batmet = map(bateis,0,1023,0,50);
  if(batmet > 23){digitalWrite(rel1,LOW);}
  else{digitalWrite(rel1,HIGH);}
  
  anemeis = analogRead(anem); // ελεγχος ανεμογεννήτριας
  anemet = map(anemeis,0,1023,0,50);
  if(anemet>24){digitalWrite(rel2,LOW);}
  else{digitalWrite(rel2,HIGH);}

  neroeis = analogRead(nero); // ελεγχος νερό
  neromet = map(neroeis,0,1023,0,50);
  if(neromet>24){digitalWrite(rel3,LOW);}
  else{digitalWrite(rel3,HIGH);}
  delay(1);
}
