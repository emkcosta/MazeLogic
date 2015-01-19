

int PINS;

//Digital pins
//Use physical pin numbers?

//FOR DOORS...HIGH=CLOSED, LOW=OPEN
//Using ARDUNIO DUE

enum PINS {
  IR_home = 0,
  IR_arm1,
  IR_arm2,
  IR_arm3,
  IR_arm4,
  IR_arm5,
  IR_arm6,
  IR_arm7,
  DRh,
  DRh_MOV,
  DR1,
  DR1_MOV,
  DR2,
  DR2_MOV,
  DR3,
  DR3_MOV,
  DR4,
  DR4_MOV,
  DR5,
  DR5_MOV,
  DR6,
  DR6_MOV,
  DR7,
  DR7_MOV,
  
};

//different way to organize pins:
/*enum PINS {
  IR_home = A0,
  IR_arm1,
  IR_arm2,
  IR_arm3,
  IR_arm4,
  IR_arm5,
  IR_arm6 = 11,
  IR_arm7,
  DRh = 6,
  DRh = 8,
  DR1,
  DR1,
  DR2,
  DR2,
  DR2,
  DR3,
  DR4,
  DR4,
  DR5,
  DR5,
  DR6,
  DR6,
  DR7,
  DR7,
  DRh_MOV = 10,
  DR1_MOV,
  DR2_MOV,
  DR3_MOV,
  DR4_MOV,
  DR5_MOV,
  DR6_MOV,
  DR7_MOV,
};*/

void setup() {
  Serial.begin(9600);
  
  //INPUTS FROM ALL OF THE IR SENSORS
  pinMode(IR_home, INPUT); 
  pinMode(IR_arm1, INPUT); 
  pinMode(IR_arm2, INPUT); 
  pinMode(IR_arm3, INPUT); 
  pinMode(IR_arm4, INPUT); 
  pinMode(IR_arm5, INPUT); 
  pinMode(IR_arm6, INPUT); 
  pinMode(IR_arm7, INPUT); 
  
  //INPUTS AND OUTPUTS FROM ALL OF THE DOORS
  pinMode(DRh, OUTPUT);
  pinMode(DRh_MOV, INPUT); 
  pinMode(DR1, OUTPUT);
  pinMode(DR1_MOV, INPUT);
  pinMode(DR2, OUTPUT);
  pinMode(DR2_MOV, INPUT);
  pinMode(DR3, OUTPUT);
  pinMode(DR3_MOV, INPUT);
  pinMode(DR4, OUTPUT);
  pinMode(DR4_MOV, INPUT);
  pinMode(DR5, OUTPUT);
  pinMode(DR5_MOV, INPUT);
  pinMode(DR6, OUTPUT);
  pinMode(DR6_MOV, INPUT);
  pinMode(DR7, OUTPUT);
  pinMode(DR7_MOV, INPUT);
  
};


void loop() {
 
 //THIS FOR LOOP MIGHT BE FASTER
/*int DR_pins [] = {DRh_MOV, DR1_MOV, DR2_MOV, DR3_MOV, DR4_MOV, DR5_MOV, DR6_MOV, DR7_MOV}
for( int i = 0; i < sizeof(DR_pins) / 2; i++) {
   digitalRead( DR_pins [i]);
      if (digitalRead( DR_pins [i], HIGH) {
        Serial.println("Door [i] is in motion.");
      }
      else {
        Serial.println("Door [i] is NOT in motion.");
      }
 }
}*/
 
 
  //DOOR IS MOVING/NOT MOVING IF/ELSE STATEMENTS
 if( digitalRead(DRh_MOV, HIGH)) {
       Serial.println("Home door is in motion."); 
 }
 
 else{
   Serial.println("Home door is NOT in motion."); 
 }
 
 if( digitalRead(DR1_MOV, HIGH)) {
       Serial.println("Door 1 is in motion.");
 }
 
 else{
   Serial.println("Door 1 is NOT in motion."); 
 }
 
 if( digitalRead(DR2_MOV, HIGH)) {
       Serial.println("Door 2 is in motion.");
 }
 
 else{
   Serial.println("Door 2 is NOT in motion."); 
 }
 
 if( digitalRead(DR3_MOV, HIGH)) {
       Serial.println("Door 3 is in motion.");
 }
 
 else{
   Serial.println("Door 3 is NOT in motion."); 
 }
 
 if( digitalRead(DR4_MOV, HIGH)) {
       Serial.println("Door 4 is in motion.");
 }
 
 else{
   Serial.println("Door 4 is NOT in motion."); 
 }
 
 if( digitalRead(DR5_MOV, HIGH)) {
       Serial.println("Door 5 is in motion.");
 }
 
 else{
   Serial.println("Door 5 is NOT in motion."); 
 }
 
 if( digitalRead(DR6_MOV, HIGH)) {
       Serial.println("Door 6 is in motion.");
 }
 
 else{
   Serial.println("Door 6 is NOT in motion."); 
 }
 
 if( digitalRead(DR7_MOV, HIGH)) {
       Serial.println("Door 7 is in motion.");
 }
 
 else{
   Serial.println("Door 7 is NOT in motion."); 
 }

 

  //WHERE IS THE RAT LOCATED
  bool stateIR_home = digitalRead(IR_home);
    if(stateIR_home) {
          Serial.println("Rat is on distal end of home arm.");
                    //This is faster than a "for" loop
          digitalWrite(DRh, LOW;
          digitalWrite(DR1, LOW);
          digitalWrite(DR2, LOW);
          digitalWrite(DR3, LOW);
          digitalWrite(DR4, LOW);
          digitalWrite(DR5, LOW);
          digitalWrite(DR6, LOW);
          digitalWrite(DR7, LOW);
    }              
                   
    else {
          Serial.println("Rat is NOT on distal end of home arm.");
          {
            //CHECK IF RAT IS ON CENTER PLATFORM
            if( digitalRead(IR_home, LOW) && digitalRead(IR_arm1, LOW) 
                  && digitalRead(IR_arm2, LOW) && digitalRead(IR_arm3, LOW)
                  && digitalRead(IR_arm4, LOW) && digitalRead(IR_arm5, LOW)
                  && digitalRead(IR_arm6, LOW) && digitalRead(IR_arm7, LOW) ) {
               
                    Serial.println("The rat is not on the distal end of any arm and may be in center of maze.");
                  }
            
            //CHECK IF RAT IS ON ARM 1
             bool stateIR_arm1 = digitalRead(IR_arm1, HIGH);
             if(IR_arm1) {
               Serial.println("Rat is on distal end of arm 1.");
               digitalWrite(DRh, LOW);
               digitalWrite(DR1, LOW);
               digitalWrite(DR2, HIGH);
               digitalWrite(DR3, HIGH);
               digitalWrite(DR4, HIGH);
               digitalWrite(DR5, HIGH);
               digitalWrite(DR6, HIGH);
               digitalWrite(DR7, HIGH);
             }
             else {
               Serial.println("Rat is NOT on distal end of arm 1.");
             }
             
             //CHECK IF RAT IS ON ARM 2
             bool stateIR_arm2 = digitalRead(IR_arm2, HIGH);
             if(IR_arm2) {
               Serial.println("Rat is on distal end of arm 2.");
               digitalWrite(DRh, LOW);
               digitalWrite(DR1, HIGH);
               digitalWrite(DR2, LOW);
               digitalWrite(DR3, HIGH);
               digitalWrite(DR4, HIGH);
               digitalWrite(DR5, HIGH);
               digitalWrite(DR6, HIGH);
               digitalWrite(DR7, HIGH);
             }
             else {
               Serial.println("Rat is NOT on distal end of arm 2.");
             }
             
              //CHECK IF RAT IS ON ARM 3
             bool stateIR_arm3 = digitalRead(IR_arm3, HIGH);
             if(IR_arm3) {
               Serial.println("Rat is on distal end of arm 3.");
               digitalWrite(DRh, LOW);
               digitalWrite(DR1, HIGH);
               digitalWrite(DR2, HIGH);
               digitalWrite(DR3, LOW);
               digitalWrite(DR4, HIGH);
               digitalWrite(DR5, HIGH);
               digitalWrite(DR6, HIGH);
               digitalWrite(DR7, HIGH);
             }
             else {
               Serial.println("Rat is NOT on distal end of arm 3.");
             }
             
              //CHECK IF RAT IS ON ARM 4
             bool stateIR_arm4 = digitalRead(IR_arm4, HIGH);
             if(IR_arm4) {
               Serial.println("Rat is on distal end of arm 4.");
               digitalWrite(DRh, LOW);
               digitalWrite(DR1, HIGH);
               digitalWrite(DR2, HIGH);
               digitalWrite(DR3, HIGH);
               digitalWrite(DR4, LOW);
               digitalWrite(DR5, HIGH);
               digitalWrite(DR6, HIGH);
               digitalWrite(DR7, HIGH);
             }
             else {
               Serial.println("Rat is NOT on distal end of arm 4.");
             }
             
              //CHECK IF RAT IS ON ARM 5
             bool stateIR_arm5 = digitalRead(IR_arm5, HIGH);
             if(IR_arm5) {
               Serial.println("Rat is on distal end of arm 5.");
               digitalWrite(DRh, LOW);
               digitalWrite(DR1, HIGH);
               digitalWrite(DR2, HIGH);
               digitalWrite(DR3, HIGH);
               digitalWrite(DR4, HIGH);
               digitalWrite(DR5, LOW);
               digitalWrite(DR6, HIGH);
               digitalWrite(DR7, HIGH);
             }
             else {
               Serial.println("Rat is NOT on distal end of arm 5.");
             }
             
              //CHECK IF RAT IS ON ARM 6
             bool stateIR_arm6 = digitalRead(IR_arm6, HIGH);
             if(IR_arm6) {
               Serial.println("Rat is on distal end of arm 6.");
               digitalWrite(DRh, LOW);
               digitalWrite(DR1, HIGH);
               digitalWrite(DR2, HIGH);
               digitalWrite(DR3, HIGH);
               digitalWrite(DR4, HIGH);
               digitalWrite(DR5, HIGH);
               digitalWrite(DR6, LOW);
               digitalWrite(DR7, HIGH);
             }
             else {
               Serial.println("Rat is NOT on distal end of arm 6.");
             }
             
              //CHECK IF RAT IS ON ARM 7
             bool stateIR_arm7 = digitalRead(IR_arm7, HIGH);
             if(IR_arm2=7) {
               Serial.println("Rat is on distal end of arm 7.");
               digitalWrite(DRh, LOW);
               digitalWrite(DR1, HIGH);
               digitalWrite(DR2, HIGH);
               digitalWrite(DR3, HIGH);
               digitalWrite(DR4, HIGH);
               digitalWrite(DR5, HIGH);
               digitalWrite(DR6, HIGH);
               digitalWrite(DR7, LOW);
             }
             else {
               Serial.println("Rat is NOT on distal end of arm 7.");
             }
             
       
           }
    }
    
     
          
};
