#include "Arduino.h"
#include "RDOT_ECD.h"


RDOT_ECD::RDOT_ECD(int counter_electrode, int segments[], int number_of_segments, int counter_voltage, int switching_time)
{

  _counter_electrode = counter_electrode;
  _switching_time = switching_time;
  _counter_voltage = counter_voltage;
  _number_of_segments = number_of_segments;

  for (int i = 0; i < _number_of_segments; i++)
  {
    _segments[i] = segments[i];
    pinMode(_segments[i], INPUT);
  }    
  highImpMode();
}

void RDOT_ECD::highImpMode(){
  for (int i = 0; i < 7; i++)
  {
    pinMode(_segments[i], INPUT);
  }
}

void RDOT_ECD::init()
{
  //Build up voltage at the reference electrode. 
  pinMode(_counter_electrode, OUTPUT);
  analogWrite(_counter_electrode, _counter_voltage);
  delay(3000);
  bool reset[_number_of_segments];
  for (int i = 0; i < _number_of_segments; i++)
  {
    reset[i] = 0;
  }    
  set(reset);
}

void RDOT_ECD::set(bool next_state[])
{
  for (int i = 0; i < _number_of_segments; i++)
  {
    pinMode(_segments[i], OUTPUT);
    digitalWrite(_segments[i], next_state[i]);
    _current_state[i] = next_state[i];
  }
  delay(_switching_time);
  highImpMode();
}

void RDOT_ECD::refresh()
{
  for (int i = 0; i < _number_of_segments; i++)
  {
    pinMode(_segments[i], OUTPUT);
    digitalWrite(_segments[i], _current_state[i]);
  }
  delay(_switching_time/4); 
  highImpMode(); 
}

