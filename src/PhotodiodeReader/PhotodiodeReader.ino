const int readPin = A0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  bool state = digitalRead(readPin); 
    if(!state) {
          Serial.println("Non-blocked");
   
    }
    else {
          Serial.println("Blocked");
      
    }
}
