/**
 * Author:    Dipesh Banerjee
 * Created:   15.08.2022
 * Used in Drag and Drift Event
 **/

char t;
int a=125;
void setup() {
pinMode(11,OUTPUT);   //left motors reverse  
pinMode(10,OUTPUT);   //left motors forward  
pinMode(6,OUTPUT);  //right motors forward    
pinMode(5,OUTPUT);   //right motors reverse   
pinMode(13,OUTPUT);    //Led
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
digitalWrite(13,HIGH);   // LED blink

  if(t=='1'){
     a=105;
  }
  else if(t=='3'){
     a=140;
  }
  else if(t=='q'){
     a=225;
  }
  
  if(t == 'R'){            //move Right(Move motors in left clockwise direction and right motors in anticlockwise direction)
  analogWrite(11,a); 
  analogWrite(6,a);
  analogWrite(10,0);
  analogWrite(5,0);
 }
 
else if(t == 'L'){ //move Left(Motors in left side will rotate in anticlockwise direction and Motors in right in clockwise direction)
  //delay(1000);
  analogWrite(11,0);
  analogWrite(6,0);
  analogWrite(10,a);
  analogWrite(5,a);
  
}
else if (t=='F'){  // move forward(Move motors in clockwise direction)
  //delay(1000);
  analogWrite(11,0);
  analogWrite(6,a);
  analogWrite(10,a);
  analogWrite(5,0);
  
}
else if (t=='B'){  // move backward(Move motors in anticlockwise direction)
  //delay(1000);
  analogWrite(11,a);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(5,a);
}

else if (t=='S'){
  //delay(1000);
  analogWrite(11,0);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(5,0);
}
}
