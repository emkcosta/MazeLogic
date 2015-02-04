#include <stdio.h>

//Digital pins
//Use physical pin numbers?

//FOR DOORS...HIGH=CLOSED, LOW=OPEN
//Using ARDUNIO DUE

enum PINS
{
    IR_home = 20,//Distal IR photosensors on arms
    IR_arm1 = 21,
    IR_arm2 = 14,
    IR_arm3,
    IR_arm4,
    IR_arm5,
    IR_arm6,
    IR_arm7,
    IR_DRh = 2,//Safety IR photosensors
    IR_DR1,
    IR_DR2,
    IR_DR3,
    IR_DR4,
    IR_DR5,
    IR_DR6,
    IR_DR7,
    DRh = 22,//Door OPEN/CLOSE control pins
    DR1 = 25,
    DR2 = 28,
    DR3 = 31,
    DR4 = 34,
    DR5 = 37,
    DR6 = 40,
    DR7 = 43,
    DRh_MOV = 23,//Door MOTION pins
    DR1_MOV = 26,
    DR2_MOV = 29,
    DR3_MOV = 32,
    DR4_MOV = 35,
    DR5_MOV = 38,
    DR6_MOV = 41,
    DR7_MOV = 44,

    //Specify STOP HIGH = EMERGENCY STOP
    DRh_STOP = 24,//Safety door STOP motion...JON WILL HAVE TO ADD
    DR1_STOP = 27,
    DR2_STOP = 30,
    DR3_STOP = 33,
    DR4_STOP = 36,
    DR5_STOP = 39,
    DR6_STOP = 42,
    DR7_STOP = 45,

};

void setup()
{
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
    digitalWrite(DR1_STOP, LOW);
    digitalWrite(DR2_STOP, LOW);
    digitalWrite(DR3_STOP, LOW);
    digitalWrite(DR4_STOP, LOW);
    digitalWrite(DR5_STOP, LOW);
    digitalWrite(DR6_STOP, LOW);
    digitalWrite(DR7_STOP, LOW);
    digitalWrite(DRh, HIGH);
    digitalWrite(DR1, LOW);
    digitalWrite(DR2, LOW);
    digitalWrite(DR3, LOW);
    digitalWrite(DR4, LOW);
    digitalWrite(DR5, LOW);
    digitalWrite(DR6, LOW);
    digitalWrite(DR7, LOW);


}


void loop()
{

    //WHERE IS THE RAT LOCATED?

    //CHECK IF RAT IS ON HOME ARM
    bool stateIR_home = digitalRead(IR_home);
    if(stateIR_home)
    {
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

        //DOOR IS MOVING/NOT MOVING IF/ELSE STATEMENT

        //Fix this nonsense using XCode:
        if( digitalRead(DRh_MOV) || digitalRead(DR1_MOV) || digitalRead(DR2_MOV)
                || digitalRead(DR3_MOV) || digitalRead(DR4_MOV) || digitalRead(DR5_MOV)
                || digitalRead(DR6_MOV) || digitalRead(DR7_MOV)
                && digitalRead(IR_DRh) || digitalRead(IR_DR1) || digitalRead(IR_DR2)
                || digitalRead(IR_DR3) || digitalRead(IR_DR4) || digitalRead(IR_DR5)
                || digitalRead(IR_DR6) || digitalRead(IR_DR7))
        {
            Serial.println("WARNING: Rat is near a moving door.");
            digitalWrite(DRh_STOP, HIGH);
            digitalWrite(DR1_STOP, HIGH);
            digitalWrite(DR2_STOP, HIGH);
            digitalWrite(DR3_STOP, HIGH);
            digitalWrite(DR4_STOP, HIGH);
            digitalWrite(DR5_STOP, HIGH);
            digitalWrite(DR6_STOP, HIGH);
            digitalWrite(DR7_STOP, HIGH);
        }
    }

    else
    {
        Serial.println("Rat is NOT on distal end of home arm.");
    }    
    
    //CHECK IF RAT IS ON ARM 1
    bool stateIR_arm1 = digitalRead(IR_arm1);
    if(stateIR_arm1)
    {
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
    else
    {
        Serial.println("Rat is NOT on distal end of arm 1.");
    }

    //CHECK IF RAT IS ON ARM 2
    bool stateIR_arm2 = digitalRead(IR_arm2);
    if(stateIR_arm2)
    {
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
    else
    {
        Serial.println("Rat is NOT on distal end of arm 2.");
    }

    //CHECK IF RAT IS ON ARM 3
    bool stateIR_arm3 = digitalRead(IR_arm3);
    if(stateIR_arm3)
    {
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
    else
    {
        Serial.println("Rat is NOT on distal end of arm 3.");
    }

    //CHECK IF RAT IS ON ARM 4
    bool stateIR_arm4 = digitalRead(IR_arm4);
    if(stateIR_arm4)
    {
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
    else
    {
        Serial.println("Rat is NOT on distal end of arm 4.");
    }

    //CHECK IF RAT IS ON ARM 5
    bool stateIR_arm5 = digitalRead(IR_arm5);
    if(stateIR_arm5)
    {
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
    else
    {
        Serial.println("Rat is NOT on distal end of arm 5.");
    }

    //CHECK IF RAT IS ON ARM 6
    bool stateIR_arm6 = digitalRead(IR_arm6);
    if(stateIR_arm6)
    {
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
    else
    {
        Serial.println("Rat is NOT on distal end of arm 6.");
    }

    //CHECK IF RAT IS ON ARM 7
    bool stateIR_arm7 = digitalRead(IR_arm7);
    if(stateIR_arm7)
    {
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
    else
    {
        Serial.println("Rat is NOT on distal end of arm 7.");
    }

    //CHECK IF RAT IS ON CENTER PLATFORM
    //Is this necessary?
    //I think it would be in terms of having the HOME DOOR close right after the Rat has
    //left the HOME arm
    //But... how would I discriminate btwn the Rat just having left the HOME arm and
    //the rat returning to it to finish a trial?
    if( !digitalRead(IR_home) && !digitalRead(IR_arm1)
            && !digitalRead(IR_arm2) && !digitalRead(IR_arm3)
            && !digitalRead(IR_arm4) && !digitalRead(IR_arm5)
            && !digitalRead(IR_arm6) && !digitalRead(IR_arm7) )
    {

        Serial.println("The rat is not on the distal end of any arm and may be in center of maze.");
    }

}

