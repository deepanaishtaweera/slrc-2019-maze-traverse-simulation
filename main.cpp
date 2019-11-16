#include "maze_def.h"
#include "impl/colors.h"
#include "pose.h"
Pose pose;
#include "cells.h"
Cells cells;
#include "impl/motors.h"

// Remove when porting to robot
#include "print/print.h"
#include "print/grid.h"
#include "logic/go_to_color_cell.h"
#include "logic/navigate_to_cell.h"
void map_maze();

int main(){
  get_test_maze();

  print_node();

  map_maze();

  print_node();
	
  print_relative_cells();
  print_saved_cells();

  print_grid(get_x(pose.node_pose),get_y(pose.node_pose), pose.orientation);

	cells.set_cell_val();
	cells.set_color_indexes();

	print_cell_values();
	print_color_indexes();

	cells.set_dropping_order();
	// cells.droppingOrder[1]=GREEN_COLOR;
	// cells.droppingOrder[0]=RED_COLOR;
	// cells.droppingOrder[2]=BLUE_COLOR;


	cells.set_drop_indexes();
	// cells.redDropIndex = 0;
	// cells.blueDropIndex=1;
	// cells.greenDropIndex=2;

	print_drop_order();
	print_drop_indexes();
	

// //*** navigating robot to the required cell

// 	int nearest_node_x,nearest_node_y;
// 	tie(nearest_node_x,nearest_node_y)=get_nearest_node(get_x(pose.node_pose),get_y(pose.node_pose),7,3);

// 	cout<< get_x(pose.node_pose)<< " " << get_y(pose.node_pose) << " " << pose.orientation<<endl;
// 	cout<< nearest_node_x << " " << nearest_node_y << endl;

// 	navigate_to_target_cell(get_x(pose.node_pose),get_y(pose.node_pose),nearest_node_x,nearest_node_y);

// 	move_to_next_node();

// 	print_grid(get_x(pose.node_pose),get_y(pose.node_pose), pose.orientation);

	
// 	tie(nearest_node_x,nearest_node_y)=get_nearest_node(get_x(pose.node_pose),get_y(pose.node_pose),2,4);

// 	cout<< get_x(pose.node_pose)<< " " << get_y(pose.node_pose) << " " << pose.orientation<<endl;
// 	cout<< nearest_node_x << " " << nearest_node_y << endl;

// 	navigate_to_target_cell(get_x(pose.node_pose),get_y(pose.node_pose),nearest_node_x,nearest_node_y);


	drop_coins();


	//------------ D R O P   C O I N S   F U N C 2 ----------------
	// int nearest_node_x,nearest_node_y;
	// for(int color = 0; color<3; color = color + 1 )
  //  {
  //     //  cout << "value of color: " << cells.droppingOrder[color] << endl;
	// 		 if (cells.droppingOrder[color]==RED_COLOR){
	// 			 	int x,y,z;
	// 				cout << "red cell" << endl;
	// 				tie(x,y,z) = cells.redCells[cells.redDropIndex];
	// 				cout << x << " " << y << endl;		
	// 				tie(nearest_node_x,nearest_node_y)=get_nearest_node(get_x(pose.node_pose),get_y(pose.node_pose),x,y);

	// 		 }
	// 		 else if (cells.droppingOrder[color]==GREEN_COLOR){
	// 			 	int x,y,z;
	// 				cout << "green cell" << endl;
	// 				tie(x,y,z) = cells.greenCells[cells.greenDropIndex];
	// 				cout << x << " " << y << endl;
	// 				tie(nearest_node_x,nearest_node_y)=get_nearest_node(get_x(pose.node_pose),get_y(pose.node_pose),x,y);		
	// 		 }
	// 		 else{
	// 			 	int x,y,z;
	// 				cout << "blue cell" << endl;
	// 				tie(x,y,z) = cells.blueCells[cells.blueDropIndex];
	// 				cout << x << " " << y << endl;		
	// 				tie(nearest_node_x,nearest_node_y)=get_nearest_node(get_x(pose.node_pose),get_y(pose.node_pose),x,y);
	// 		 }			 		
	// 		navigate_to_target_cell(get_x(pose.node_pose),get_y(pose.node_pose),nearest_node_x,nearest_node_y);	 
	// 		print_grid(get_x(pose.node_pose),get_y(pose.node_pose), pose.orientation);

  //  }
	//------------------------------------------------------------------------------

	go_to_ending_node();

  print_grid(get_x(pose.node_pose),get_y(pose.node_pose), pose.orientation);

  return 0;
}


bool is_maze_mapped()
{
    int colorCellCount = 0;
		REP(x,0,8)
		{
        REP(y,0,8)
            {
							if (cells.color[x][y] != 0)
							{
									colorCellCount += 1;
							}
            }
        }
		if (colorCellCount == 9)
		{
			mapping_finished = true;
		}
    return mapping_finished;
}

void map_maze()
{
    while (mapping_finished == false)
    {
        REP(i, 0, 7)
        {
            move_to_next_node();
            if(is_maze_mapped()) break;
				}
        if(mapping_finished) break;
        // print_cell_values();
        turn_right_90();
        REP(i, 0, 2)
        {
            move_to_next_node();
            if(is_maze_mapped()) break;
        }
        if(mapping_finished) break;
        // print_cell_values();
        turn_right_90();
        REP(i, 0, 6)
        {
            move_to_next_node();
            if(is_maze_mapped()) break;
        }
        if(mapping_finished) break;
        // print_cell_values();
        turn_left_90();
        REP(i, 0, 2)
        {
            move_to_next_node();
            if(is_maze_mapped()) break;
        }
        if(mapping_finished) break;
        // print_cell_values();
        turn_left_90();
        REP(i, 0, 7)
        {
            move_to_next_node();
            if(is_maze_mapped()) break;
        }
        if(mapping_finished) break;
        // print_cell_values();
        turn_right_90();
        REP(i, 0, 2)
        {
            move_to_next_node();
            if(is_maze_mapped()) break;
        }
        if(mapping_finished) break;
        // print_cell_values();
        turn_right_90();
        REP(i, 0, 8)
        {
            move_to_next_node();
            if(is_maze_mapped()) break;
        }
        if(mapping_finished) break;
        // print_cell_values();
        turn_left_90();
        REP(i, 0, 2)
        {
            move_to_next_node();
            if(is_maze_mapped()) break;
        }
        if(mapping_finished) break;
        // print_cell_values();
        turn_left_90();
        REP(i, 0, 8)
        {
            move_to_next_node();
            if(is_maze_mapped()) break;
        }
        if(mapping_finished) break;
        // print_cell_values();
        mapping_finished = true;
    }
}

// void map_maze(){
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   turn_right_90();
//   move_to_next_node();
//   move_to_next_node();
//   turn_right_90();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   turn_left_90();
//   move_to_next_node();
//   move_to_next_node();
//   turn_left_90();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
// 	move_to_next_node();
//   turn_right_90();
//   move_to_next_node();
//   move_to_next_node();
//   turn_right_90();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
// 	move_to_next_node();
//   turn_left_90();
//   move_to_next_node();
//   move_to_next_node();
//   turn_left_90();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
//   move_to_next_node();
// 	mapping_finished = true;
// }
