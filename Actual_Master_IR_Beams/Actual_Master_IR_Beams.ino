#include <stdio.h>

//Digital pins
//Use physical pin numbers?

//FOR DOORS...HIGH=CLOSED, LOW=OPEN
//Using ARDUNIO DUE

#define NUM_ARMS 8


/******************************************************************************/
/* Enumerate the sorts of pins we have, both input and output                 */

enum PIN_TYPE
{ 
  DISTAL_SENSORS = 20,   // Start the enum at an int 
  SAFETY_SENSORS,        // we wouldn't reach by accident
  OPEN_CLOSE_CONTROL, 
  MOTION, 
  SAFETY_STOP 
};


/******************************************************************************/
/* Enumerate the arm numbers                                                  */
/* They are assumed to each apply for every PIN_TYPE,                         */
/* (So there is a home distal-sensor, and an arm_4 open_close_control, etc.   */

enum ARM_IND
{
  ARM_HOME = 50,      // Start the enum at an int
  ARM_1,              // at an int we wouldn't reach by accident
  ARM_2,              // and non-overlapping with PIN_TYPE
  ARM_3,
  ARM_4,
  ARM_5,
  ARM_6,
  ARM_7
};


/****************************************************************************/
/* Map the pin types and arms to specific hardware pins                     */
/* We never explicitly index into the array, instead we use                 */
/* the 'pin()' function                                                     */
/*                                                                          */
//                        h   1   2   3   4   5   6   7    // Arm number
//                       --  --  --  --  --  --  --  --                 
int pins[][NUM_ARMS] = {{20, 21, 14, 15, 16, 17, 18, 19},  // DISTAL_SENSORS
                        { 2,  3,  4,  5,  6,  7,  8,  9},  // SAFETY_SENSORS
                        {22, 25, 28, 31, 34, 37, 40, 43},  // OPEN_CLOSE_CONTROL
                        {23, 26, 29, 32, 35, 38, 41, 44},  // MOTION
                        {24, 27, 30, 33, 36, 39, 42, 45}}; // SAFETY_STOP



/******************************************************************************/
/* Use this function to look up the pin # of a given pin type and arm index   */
/* For example, to get the hardware pin of the home arm distal sensor, call:  */
/* pin( DISTAL_SENSOR, ARM_HOME )   -> 20                                     */

int pin( int t, int a){
  return pins[t - DISTAL_SENSORS][a - ARM_HOME];
}



/******************************************************************************/
/* Input sanitization for PIN_TYPE ints                                       */
bool pinOk( int t ){
  return (t >= DISTAL_SENSORS && t <= SAFETY_STOP);
}


/******************************************************************************/
/* Input satitization for ARM_IND ints                                        */
bool armOk( int a ){
  return (a >= ARM_HOME && a <= ARM_7);
}


/******************************************************************************/
/* Use setRow() to set all arms of a given PIN_TYPE to HIGH or LOW            */

void setRow(int pin_t, uint8_t b){

  // Make sure inputs are valid
  if( pinOk(pin_t) ){
    for (int i = ARM_HOME; i < NUM_ARMS + ARM_HOME; i++){
      digitalWrite ( pin(pin_t,i), b );
    }
  }
  else {
      Serial.println("WARNING: setRow: bad input");
  }
}


/******************************************************************************/
/* The same as setRow, but takes a single arm index to exclude                */
/* from the action. (e.g. useful for lowering all doors except the home door) */

void setRowExcludingPin( int pin_t, int arm_n, uint8_t b){

  // Make sure inputs are valid
  if ( pinOk(pin_t) && armOk(arm_n) ) {

      for (int i = ARM_HOME; i < NUM_ARMS + ARM_HOME; i++){
	if (i != arm_n) {
	  digitalWrite( pin(pin_t,arm_n), b );
	}
      }

  } 
  else {
      Serial.println("WARNING: setRowExcludingPin: bad input");
  }      

}


/******************************************************************************/
/* set the mode of all pins of PIN_TYPE to INPUT or OUTPUT                    */

void rowMode( int pin_t, uint8_t m ){

  // Make sure inputs are valid
  if ( pinOk(pin_t) && (m == INPUT || m == OUTPUT) ){
    for (int i = ARM_HOME; i < NUM_ARMS + ARM_HOME; i++){
      pinMode( pin(pin_t, i), m);
    }
  }
  else {
      Serial.println("WARNING: rowMode: bad input");
  }

}


/******************************************************************************/
/* For a given PIN_TYPE, which pin is currently HIGH?                         */
/* For example, which arm is moving?  whichArmInRow( MOVING );                */

int whichArmInRow( int pin_t ){

  int r = -1; // Sentinal value

  if (pinOk(pin_t)){
    for (int i = ARM_HOME; i < ARM_HOME + NUM_ARMS; i++){
      if (digitalRead( pin(pin_t,i) ) == HIGH){
	if (r > -1) {
	  Serial.println("WARNING: whichArmInRow found multiple HIGH values");
	}
	r = i;
      }
    }
  }
  else {
      Serial.println("WARNING: anyInRow: bad input");
  }

  return r;

}


/******************************************************************************/
/* Test whether rat is near a door marked Moving                              */

bool ratNearMovingDoor(){

  bool v = false;
  for (int i = ARM_HOME; i < ARM_HOME + NUM_ARMS; i++){
    bool ratHere    = digitalRead( pin(DISTAL_SENSORS, i) );
    bool motionHere = digitalRead( pin(MOTION, i) );
    v = v || (ratHere && motionHere);
  }
  return v;

}


/******************************************************************************/
/* Action to take in when rat is in a distal arm                              */

void ratDistalArmProtocol(){

  int i = whichArmInRow( DISTAL_SENSORS );

  // Close all the doors besides current-arm
  setRowExcludingPin( OPEN_CLOSE_CONTROL, i, HIGH );

  // Open home and current-arm
  digitalWrite( pin( OPEN_CLOSE_CONTROL, ARM_HOME ), LOW);
  digitalWrite( pin( OPEN_CLOSE_CONTROL, i )       , LOW);

}


void setup()
{
    Serial.begin(9600);

    //INPUTS FROM ALL OF THE IR SENSORS (ARMS AND DOORS)
    rowMode( DISTAL_SENSORS, INPUT );
    rowMode( SAFETY_SENSORS, INPUT );


    //INPUTS AND OUTPUTS FROM ALL OF THE DOORS
    rowMode( OPEN_CLOSE_CONTROL, OUTPUT );
    rowMode( SAFETY_STOP,        OUTPUT );

    //INPUTS FROM MOTION SENSORS (TODO: Is this right?)
    rowMode( MOTION, INPUT );

    //Default states
    //I think we should have all the doors start OPEN, but the HOME door will start CLOSED
    //because that is where the Rat will be starting
    setRow( SAFETY_STOP, LOW );
    digitalWrite( pin( OPEN_CLOSE_CONTROL, ARM_HOME ), HIGH );
    setRowExcludingPin( OPEN_CLOSE_CONTROL, ARM_HOME,  LOW );

}

void loop()
{

    //WHERE IS THE RAT LOCATED?

    //CHECK IF RAT IS ON HOME ARM
    if( digitalRead( pin( DISTAL_SENSORS, ARM_HOME ) ) == HIGH )
    {
        Serial.println("Rat is on distal end of home arm.");
        //Lower all the doors
	setRow( OPEN_CLOSE_CONTROL, LOW );

        //DOOR IS MOVING/NOT MOVING IF/ELSE STATEMENT
        if( ratNearMovingDoor() )
        {
            Serial.println("WARNING: Rat is near a moving door.");
	    setRow( SAFETY_STOP, HIGH );
        }
    }

    else
    {
        Serial.println("Rat is NOT on distal end of home arm.");
    }    
    
    //CHECK IF RAT IS ON EACH ARM, KEEP THAT ARM AND HOME ARM OPEN
    ratDistalArmProtocol();

    //CHECK IF RAT IS ON CENTER PLATFORM
    //Is this necessary?
    //I think it would be in terms of having the HOME DOOR close right after the Rat has
    //left the HOME arm
    //But... how would I discriminate btwn the Rat just having left the HOME arm and
    //the rat returning to it to finish a trial?
    if( whichArmInRow(DISTAL_SENSORS) < 0 )
    {

        Serial.println("The rat is not on the distal end of any arm and may be in center of maze.");
    }

}

