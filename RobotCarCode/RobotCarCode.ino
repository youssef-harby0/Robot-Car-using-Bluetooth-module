int incomingByte = 0,n;
byte Speed =50;
boolean SW =false;

void setup()
{
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
   if(incomingByte == 1) {
    SW = true;
    Buzzer();
    }
   else if(incomingByte == 0) {
    SW =false;
    Buzzer();
   }
  }
  
  if(SW){
      if(incomingByte == 6){
     Forward();
      }
      else if(incomingByte == 7){
     Back();
      }
      else if(incomingByte == 9){
     Left();
      }
      else if(incomingByte == 8){
     Right();
      }
      else if(incomingByte == 10){
      Dimmer();
      Stop();
      }
      else if((incomingByte == 2)||(incomingByte == 3)){  
     digitalWrite(2,(incomingByte & 1));
      }
      else if((incomingByte == 5)||(incomingByte == 4)){
     digitalWrite(11,(incomingByte & 1));
      }
  else if(incomingByte >= 15){
     Speed= incomingByte;
      }
}


}

void Forward(){
      analogWrite(10, Speed);
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      analogWrite(5, Speed);
      digitalWrite(7, HIGH);
      digitalWrite(6, LOW);
  }


  void Back(){
      analogWrite(10, Speed);
      digitalWrite(9, 0);
      digitalWrite(8, 1);
      analogWrite(5, Speed);
      digitalWrite(7, 0);
      digitalWrite(6, 1);
  }

    void Stop(){
      analogWrite(10, 0);
      digitalWrite(9, 0);
      digitalWrite(8, 0);
      analogWrite(5, 0);
      digitalWrite(7, 0);
      digitalWrite(6, 0);
  }


      void Right(){
      analogWrite(10, Speed*.75);
      digitalWrite(9, 0);
      digitalWrite(8, 1);
      analogWrite(5, (Speed)*.75);
      digitalWrite(7, 1);
      digitalWrite(6, 0);
      
  }

      void Left(){
      analogWrite(10, Speed*.75);
      digitalWrite(9, 1);
      digitalWrite(8, 0);
      analogWrite(5, (Speed)*.75);
      digitalWrite(7, 0);
      digitalWrite(6, 1);
  }

  void Dimmer(){
    for(int i =Speed ;  i>0 ; i--){
      analogWrite(10, i);
      analogWrite(5, i);
      delay(3);
      }
    } 


    void Buzzer(){
        for(n= 0;n<=255;n++){
    analogWrite(11,n);
    delay(2);
    }
    for(n= 0;n<=255;n++){
    analogWrite(11,n);
    delay(2);
    }
    analogWrite(11,0);
      
      }
