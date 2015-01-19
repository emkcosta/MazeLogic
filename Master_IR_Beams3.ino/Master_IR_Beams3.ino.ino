#include <Stepper.h>

// THIS IS NOT NEEDED... IM NOT OPERATING 
//THE ACTUAL STEPPER MOTORS
//const float motorSteps = /*number of steps for this motor*/
//const int motorPin1 = A0
//const int motorPin2 = A1

int uStep;

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
  DR1_CLS = ,
  DR1_OPN,
  DR1_MOV,
  //DR2
  //DR3
  //DR4
  //DR5
  //DR6
  //DR7
  
};

//Stepper myStepper = Stepper(/*number of steps for this motor*/, motorPin1, motorPin2);
//I'll have to add more pins if this ARDUINO is controlling 
//more than one stepper motor

void setup() {
 // myStepper.setSpeed(/*RPMs*/); 
  //how to modify this when you have more than one stepper attached?
  Serial.begin(9600);
  //INPUTS: 
  pinMode(IR_home, INPUT); 
  pinMode(IR_arm1, INPUT); 
  pinMode(DRh_CLS, INPUT);
  pinMode(DRh_OPN, INPUT);
  pinMode(DRh_MOV, INPUT);
  pinMode(, OUTPUT);
  pinMode(, OUTPUT);
  
}

void loop() {
  
  bool stateIR_home = digitalRead(IR_home);
    if(stateIR_home) {
          Serial.println("Rat is on distal end of home arm");
                  {//do I need to write this bool state business
                    bool stateDR_home1 = digitalRead(DRh_OPN);
                    bool stateDR_home2 = digitalRead(DRh_CLS);
                    bool stateDR_home3 = digitalRead(DRh_MOV);
                    if(stateDR_home1) {
                      Serial.println("Home door is open.");
                    }
                    if(stateDR_home2); {
                      Serial.println("Home door is closed.");
                      //function to tell servant microcontrollers to open the door
                    }
                    if(stateDR_home3); {
                      Serial.println("Home door is moving.");
                    }
                  }
    //I need to open all of the doors
    //(or check if they are all open, at least)
          
    }
    
    //I don't know if I should be repetitive below, 
    //but it is my opinion that this loop should go whether the home door is 
    //open or close because it HAS TO ALWAYS BE OPEN
    //Is this loop ever going to be needed if I never program anything 
    //that asks for the Home Door to close?
    else {
          Serial.println("Rat is NOT on distal end of home arm");
           {//do I need to write this bool state business
                    bool stateDR_home1 = digitalRead(DRh_OPN);
                    bool stateDR_home2 = digitalRead(DRh_CLS);
                    bool stateDR_home3 = digitalRead(DRh_MOV);
                    if(stateDR_home1) {
                      Serial.println("Home door is open.");
                    }
                    if(stateDR_home2); {
                      Serial.println("Home door is closed.");
                      //function to tell servant microcontrollers to open the door
                    }
                    if(stateDR_home3); {
                      Serial.println("Home door is moving.");
                    }
                  }
    }
    
    //what is the way to do this without being repetitive for each arm?
  bool stateIR_arm1 = digitalRead(IR_arm1);
     if(stateIR_arm1) {
           Serial.println("Rat is on distal end of arm 1");
           {        bool stateDR_arm1_1 = digitalRead(DR1_OPN);
                    bool stateDR_arm1_2 = digitalRead(DR1_CLS);
                    bool stateDR_arm1_3 = digitalRead(DR1_MOV);
                    if(stateDR_arm1_1) {
                      Serial.println("Arm 1 door is open.");
                    }
                    if(stateDR_arm1_2) {
                      Serial.println("Arm 1 door is closed.");
                    }
                    if(stateDR_arm1_3) {
                      Serial.println("Arm 1 door is moving.");
                    }
           }
     }
     
    else {
      Serial.println("Rat is NOT on distal end of arm 1");
      //If it's not on distal end of arm 1, it could be in the center, another arm, or home
           {        bool stateDR_arm1_1 = digitalRead(DR1_OPN);
                    bool stateDR_arm1_2 = digitalRead(DR1_CLS);
                    bool stateDR_arm1_3 = digitalRead(DR1_MOV);
                    if(stateDR_arm1_1) {
                      Serial.println("Arm 1 door is open.");
                    }
                    if(stateDR_arm1_2) {
                      Serial.println("Arm 1 door is closed.");
                     
                    }
                    if(stateDR_arm1_3) {
                      Serial.println("Arm 1 door is moving.");
                    }
  
  //IS THE ABOVE CORRECT OR SHOULD I CONTINUE THE FOLLOWING...?
  //bool stateIR_arm1 = digitalRead(IR_arm1);
  //bool stateDR_arm1_1 = digitalRead(DR1_OPN);
  //bool stateDR_arm1_2 = digitalRead(DR1_CLS);
  //bool stateDR_arm1_3 = digitalRead(DR1_MOV);
      //if(stateIR_arm1 && stateDR_arm1_1) {
          //Serial.println("Rat is on distal end of arm 1 and arm 1 door is closed.");
           
    //I need to check which doors are open and make sure they all close
    //BUT not home & current arm
           
    }
    
    else {
           Serial.println("Rat is NOT on distal end of arm");
           
    }
  
           
}
