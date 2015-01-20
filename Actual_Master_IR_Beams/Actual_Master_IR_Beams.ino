int PINS;

//Digital pins
//Use physical pin numbers?

//FOR DOORS...HIGH=CLOSED, LOW=OPEN
//Using ARDUNIO DUE

enum PINS {
  IR_home = 0,//Distal IR photosensors on arms
  IR_arm1,
  IR_arm2,
  IR_arm3,
  IR_arm4,
  IR_arm5,
  IR_arm6,
  IR_arm7,
  IR_DRh,//Safety IR photosensors
  IR_DR1,
  IR_DR2,
  IR_DR3,
  IR_DR4,
  IR_DR5,
  IR_DR6,
  IR_DR7,
  DRh,//Door OPEN/CLOSE control pins
  DR1,
  DR2,
  DR3,
  DR4,
  DR5,
  DR6,
  DR7,
  DRh_MOV,//Door MOTION pins
  DR1_MOV,
  DR2_MOV,
  DR3_MOV,
  DR4_MOV,
  DR5_MOV,
  DR6_MOV,
  DR7_MOV,
  DRh_STOP,//Safety door STOP motion...JON WILL HAVE TO ADD
  DR1_STOP,
  DR2_STOP,
  DR3_STOP,
  DR4_STOP,
  DR5_STOP,
  DR6_STOP,
  DR7_STOP,
  
};

void setup() {
  Serial.begin(9600);
  
  //INPUTS FROM ALL OF THE IR SENSORS (ARMS AND DOORS)
  pinMode(IR_home, INPUT); 
  pinMode(IR_arm1, INPUT); 
  pinMode(IR_arm2, INPUT); 
  pinMode(IR_arm3, INPUT); 
  pinMode(IR_arm4, INPUT); 
  pinMode(IR_arm5, INPUT); 
  pinMode(IR_arm6, INPUT); 
  pinMode(IR_arm7, INPUT); 
  pinMode(IR_DRh, INPUT);
  pinMode(IR_DR1, INPUT);
  pinMode(IR_DR2, INPUT);
  pinMode(IR_DR3, INPUT);
  pinMode(IR_DR4, INPUT);
  pinMode(IR_DR5, INPUT);
  pinMode(IR_DR6, INPUT);
  pinMode(IR_DR7, INPUT);
  
  //INPUTS AND OUTPUTS FROM ALL OF THE DOORS
  pinMode(DRh, OUTPUT);
  pinMode(DR1, OUTPUT);
  pinMode(DR2, OUTPUT);
  pinMode(DR3, OUTPUT);
  pinMode(DR4, OUTPUT);
  pinMode(DR5, OUTPUT);
  pinMode(DR6, OUTPUT);
  pinMode(DR7, OUTPUT);
  pinMode(DRh_STOP, OUTPUT);
  pinMode(DR1_STOP, OUTPUT);
  pinMode(DR2_STOP, OUTPUT);
  pinMode(DR3_STOP, OUTPUT);
  pinMode(DR4_STOP, OUTPUT);
  pinMode(DR5_STOP, OUTPUT);
  pinMode(DR6_STOP, OUTPUT);
  pinMode(DR7_STOP, OUTPUT);
  pinMode(DRh_MOV, INPUT); 
  pinMode(DR1_MOV, INPUT);
  pinMode(DR2_MOV, INPUT);
  pinMode(DR3_MOV, INPUT);
  pinMode(DR4_MOV, INPUT);
  pinMode(DR5_MOV, INPUT);
  pinMode(DR6_MOV, INPUT);
  pinMode(DR7_MOV, INPUT);
  
  //Default states
  //I think we should have all the doors start OPEN, but the HOME door will start CLOSED 
  //because that is where the Rat will be starting
  digitalWrite(DRh_STOP, LOW);
  digitalWrite(DRh, HIGH);
  digitalWrite(DR1, LOW;
  digitalWrite(DR2, LOW);
  digitalWrite(DR3, LOW);
  digitalWrite(DR4, LOW);
  digitalWrite(DR5, LOW);
  digitalWrite(DR6, LOW);
  digitalWrite(DR7, LOW);
  

}


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

//WHERE IS THE RAT LOCATED?
  
  //CHECK IF RAT IS ON HOME ARM
  bool stateIR_home = digitalRead(IR_home);
    if(stateIR_home) {
          Serial.println("Rat is on distal end of home arm.");
                    //This is faster than a "for" loop
          digitalWrite(DRh, LOW);
          digitalWrite(DR1, LOW);
          digitalWrite(DR2, LOW);
          digitalWrite(DR3, LOW);
          digitalWrite(DR4, LOW);
          digitalWrite(DR5, LOW);
          digitalWrite(DR6, LOW);
          digitalWrite(DR7, LOW);
          
            //DOOR IS MOVING/NOT MOVING IF/ELSE STATEMENTS
            //Would making this into a "for" loop be good?
            //Should I include this everywhere after I tell the doors to open/close? 
            //So I can keep track of the doors' movements?
            //Can I tell the door to stop moving? How?
            
           //I only put the if statement for home door w/ the assumption that the only door
           //that will really matter for this safety feature is the door on the arm
           //that the rat is currently on. (I don't think it'll move fast enough
           //to get to another moving door).
           //Also, I don't think we should have a problem with doors closing in any other
           //situation because the rat will be facing away from center platform when it first
           //triggers other doors to close.
           if( digitalRead(DRh_MOV, HIGH) && digitalRead(IR_DRh, HIGH) ) {
                 Serial.println("WARNING: Rat is near moving home door."); 
                 digitalWrite(DRh_STOP, HIGH);
           }
    }
      
      //Saying the rat is not on the dital end of the home arm might not be 
      //entirely true. What if the rat is on the START platform?
      //The same goes for any other arm & its platform.     
      else {
          Serial.println("Rat is NOT on distal end of home arm.");
          { //CHECK IF RAT IS ON ARM 1
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
               
               if( digitalRead(DRh_MOV, HIGH) && digitalRead(IR_DRh, HIGH) ) {
                 Serial.println("WARNING: Rat is near moving home door."); 
                 digitalWrite(DRh_STOP, HIGH);
           }
           
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
             
            //CHECK IF RAT IS ON CENTER PLATFORM
            //Is this necessary?
            //I think it would be in terms of having the HOME DOOR close right after the Rat has
            //left the HOME arm 
            //But... how would I discriminate btwn the Rat just having left the HOME arm and 
            //the rat returning to it to finish a trial?
            if( digitalRead(IR_home, LOW) && digitalRead(IR_arm1, LOW) 
                  && digitalRead(IR_arm2, LOW) && digitalRead(IR_arm3, LOW)
                  && digitalRead(IR_arm4, LOW) && digitalRead(IR_arm5, LOW)
                  && digitalRead(IR_arm6, LOW) && digitalRead(IR_arm7, LOW) ) {
               
                    Serial.println("The rat is not on the distal end of any arm and may be in center of maze.");
                  }
       
           }
    }
    
     
          
}
