#ifndef IMPL_MOTORS_H
#define IMPL_MOTORS_H

#include "colors.h"
#include "../basics.h"

void move_to_next_node(){
  // cout << "moved to next node" << endl;
  pose.go_to_node_in_front();
  // TODO : function to move robot forward & update colors

  //
	if (!mapping_finished){
		update_colors();
  	cells.set_cell_colors();
	}

}

void turn_right_90(){
  // cout << "turned right 90" << endl;
  pose.turn_clockwise();
  // TODO : function to turn robot right 90

  //
}

void turn_left_90(){
  // cout << "turned left 90" << endl;
  pose.turn_counter_clockwise();
  // TODO : function to turn robot left 90

  //
}

#endif
