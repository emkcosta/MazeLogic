const int IR_home_sensor = 11;
const int LED = 13;

void setup() {
 Serial.begin(9600);
 pinMode(IR_home_sensor, INPUT);
 pinMode(LED, OUTPUT);
}

void loop() {
  bool stateIR_home = digitalRead(IR_home_sensor);
    if(stateIR_home)
    {
       Serial.println("Rat is on distal end of home arm.");
       digitalWrite(LED, HIGH);//Turns on the LED when photodiode blocked
    }
    else
    {  
        Serial.println("Rat is not on distal end of home arm.");
        digitalWrite(LED, LOW);//Turns of the LED when photodiode not blocked
    }

}
//This works!
