#include <Stepper.h>


int PINS;

//Digital pins
enum PINS {
  IR_home = A0,
  IR_arm1,
  IR_arm2,
  IR_arm3,
  IR_arm4,
  IR_arm5,
  IR_arm6 = 11,
  IR_arm7,
  DRh_CLS = 6,
  DRh_OPN = 8,
  DRh_MOV = 10,
  DR1_CLS,
  DR1_OPN,
  DR1_MOV,
  DR2_CLS,
  DR2_OPN,
  DR2_MOV,
  DR3_CLS,
  DR3_OPN,
  DR3_MOV,
  DR4_CLS,
  DR4_OPN,
  DR4_MOV,
  DR5_CLS,
  DR5_OPN,
  DR5_MOV,
  DR6_CLS,
  DR6_OPN,
  DR6_MOV,
  DR7_CLS,
  DR7_OPN,
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
  DRh_CLS = 6,
  DRh_OPN = 8,
  DR1_CLS,
  DR1_OPN,
  DR2_CLS,
  DR2_OPN,
  DR3_CLS,
  DR3_OPN,
  DR4_CLS,
  DR4_OPN,
  DR5_CLS,
  DR5_OPN,
  DR6_CLS,
  DR6_OPN,
  DR7_CLS,
  DR7_OPN,
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
  pinMode(DRh_CLS, OUTPUT);
  pinMode(DRh_OPN, OUTPUT);
  pinMode(DRh_MOV, INPUT); 
  pinMode(DR1_CLS, OUTPUT);
  pinMode(DR1_OPN, OUTPUT);
  pinMode(DR1_MOV, INPUT);
  pinMode(DR2_CLS, OUTPUT);
  pinMode(DR2_OPN, OUTPUT);
  pinMode(DR2_MOV, INPUT);
  pinMode(DR3_CLS, OUTPUT);
  pinMode(DR3_OPN, OUTPUT);
  pinMode(DR3_MOV, INPUT);
  pinMode(DR4_CLS, OUTPUT);
  pinMode(DR4_OPN, OUTPUT);
  pinMode(DR4_MOV, INPUT);
  pinMode(DR5_CLS, OUTPUT);
  pinMode(DR5_OPN, OUTPUT);
  pinMode(DR5_MOV, INPUT);
  pinMode(DR6_CLS, OUTPUT);
  pinMode(DR6_OPN, OUTPUT);
  pinMode(DR6_MOV, INPUT);
  pinMode(DR7_CLS, OUTPUT);
  pinMode(DR7_OPN, OUTPUT);
  pinMode(DR7_MOV, INPUT);
  
};


void loop() {

 //Do I need to repeat these DOOR MOTION CHECKS 
 //after I write a command to OPN or CLS a door?
 //Or rather, I know that they need to be repeated,
 //but what is the best way to do it?
 
  //DOOR IS MOVING
 if( digitalRead(PIN, /*NUMBER OF DR1_MOV*/ <= PIN <= /*NUMBER OF DR7_MOV*/, HIGH)) {
       Serial.println("Door is in motion."); 
       //how to print the name of arm in this^^
 }
 
  //DOOR IS NOT MOVING
  if( digitalRead(PIN, /*NUMBER OF DR1_MOV*/ <= PIN <= /*NUMBER OF DR7_MOV*/, LOW)) {
   Serial.println("Door is NOT in motion."); 
   //how to print the name of arm in this^^
 }
 
  //WHERE IS THE RAT LOCATED
  bool stateIR_home = digitalRead(IR_home);
    if(stateIR_home) {
          Serial.println("Rat is on distal end of home arm.");
                    //I know the following is very repetitive, how would I fix it?
          digitalWrite(DRh_OPN);
          digitalWrite(DR1_OPN);
          digitalWrite(DR2_OPN);
          digitalWrite(DR3_OPN);
          digitalWrite(DR4_OPN);
          digitalWrite(DR5_OPN);
          digitalWrite(DR6_OPN);
          digitalWrite(DR7_OPN);
    }              
                   
    else {
          Serial.println("Rat is NOT on distal end of home arm.");
          {
             //Is there a way to make this loop less repetitive?
             
             //CHECK IF RAT IS ON ARM 1
             bool stateIR_arm1 = digitalRead(IR_arm1);
             if(IR_arm1) {
               Serial.println("Rat is on distal end of arm 1.");
               digitalWrite(DRh_OPN);
               digitalWrite(DR1_OPN);
               digitalWrite(DR2_CLS);
               digitalWrite(DR3_CLS);
               digitalWrite(DR4_CLS);
               digitalWrite(DR5_CLS);
               digitalWrite(DR6_CLS);
               digitalWrite(DR7_CLS);
             }
             else {
               Serial.println("Rat is NOT on distal end of arm 1.");
             }
             
             //CHECK IF RAT IS ON ARM 2
             bool stateIR_arm2 = digitalRead(IR_arm2);
             if(IR_arm2) {
               Serial.println("Rat is on distal end of arm 2.");
               digitalWrite(DRh_OPN);
               digitalWrite(DR2_OPN);
               digitalWrite(DR1_CLS);
               digitalWrite(DR3_CLS);
               digitalWrite(DR4_CLS);
               digitalWrite(DR5_CLS);
               digitalWrite(DR6_CLS);
               digitalWrite(DR7_CLS);
             }
             else {
               Serial.println("Rat is NOT on distal end of arm 2.");
             }
   //CONTINUE THIS LOOP OF CHECKING ARMS
       
           }
    }
    
     
          
};
