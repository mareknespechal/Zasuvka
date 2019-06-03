void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
}

int prepinac() {
  if(digitalRead(3) == LOW) {
    return 1;  
  }
  else{
    if(digitalRead(4) == LOW) {
      return 0;
    }
    else {
      return 2;
    }
  }
}

void blikani() {
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);    
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(prepinac()) {
    case 0:
      digitalWrite(1, LOW);
      digitalWrite(2, LOW);
      break;
    case 1:
      blikani();
      digitalWrite(1, HIGH);
      break;
    case 2:
      if(digitalRead(0) == HIGH) {
        digitalWrite(2, HIGH);
        digitalWrite(1, HIGH);
      }
      else {
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
      }
      break;
  }
}
