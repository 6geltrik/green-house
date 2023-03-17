


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

void setup() { 
 pinMode(Pin0, OUTPUT);  
 pinMode(Pin1, OUTPUT);  
 pinMode(Pin2, OUTPUT);  
 pinMode(Pin3, OUTPUT);  
 pinMode(diakopin, INPUT);
 pinMode(upSensorPin,INPUT);
 pinMode(downSensorPin,INPUT);
} 
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
}
