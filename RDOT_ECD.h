/*
	RDOT_ECD.h - Library for driving rdot's electrochromic display
	Created by Philip Holgersson - rdot AB, Nov 22, 2019
*/

#ifndef _RDOT_ECD
#define _RDOT_ECD

#include "Arduino.h"

class RDOT_ECD
{
	public:
		RDOT_ECD(int counter_electrode, int segments[], int number_of_segments, int counter_voltage, int switching_time);
		void init();
		void set(bool next_state[]);
		void setNumber(int digit);
		void refresh();
	private: 
		int _counter_electrode; 
		int _counter_voltage;
		int _number_of_segments;
		int _segments[20];
		int _switching_time;
		bool _current_state[20];
		bool _seven_seg_states[10][7]={
 			{1,1,1,0,1,1,1},
 			{1,0,0,0,0,0,1},
 			{0,1,1,1,0,1,1},
 			{1,1,0,1,0,1,1},
			{1,0,0,1,1,0,1},
			{1,1,0,1,1,1,0},	
			{1,1,1,1,1,1,0},
			{1,0,0,0,0,1,1},
			{1,1,1,1,1,1,1},
			{1,1,0,1,1,1,1}
		};
		void highImpMode();
};

#endif