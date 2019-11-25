#include <RDOT_ECD.h>
int segments[7] = {2,3,4,5,6,7,8};      //The work-pins connected to the display electrodes
int com = 9;                            //The common-pin connected to the display common electrode 
RDOT_ECD ECD(com, segments, sizeof(segments), 120, 2000); //Creating the ECD object

void setup() {
  ECD.init();                           //Initalizing the display (removing content)
}

void loop() {
  bool states1[7] = {1,1,1,1,1,1,1};    //All segments on
  bool states2[7] = {0,0,0,0,0,0,0};    //All segments off
 
  ECD.set(states1);                     //Turn on all segments
  delay(10000);                         //Wait for ten seconds

  ECD.set(states2);                     //Turn on all segments
  delay(10000);                         //Wait for ten seconds
}
