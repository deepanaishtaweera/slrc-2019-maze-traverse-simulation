#ifndef GO_TO_COLOR_CELL_H
#define GO_TO_COLOR_CELL_H

#include "../cells.h"
#include "../basics.h"
#include "navigate_to_cell.h"

pair <int,int> get_nearest_node(int node_x,int node_y,int cell_x,int cell_y){
		int sub_val_x = node_x-cell_x;
		int sub_val_y = node_y-cell_y;
		if (sub_val_x<=0 && sub_val_y <=0){
			return make_pair(cell_x,cell_y);
		} 
		else if (sub_val_x<=0 && sub_val_y > 0){
			return make_pair(cell_x,cell_y+1);
		} 
		else if (sub_val_x>0 && sub_val_y <=0){
			return make_pair(cell_x+1,cell_y);
		} 
		else{
			return make_pair(cell_x+1,cell_y+1);
		} 
}

void drop_coins(){

	// Take indexes of drop cells of colors (Red,Blue,Green)
	int drop_red_cell_x=0,drop_red_cell_y=0,drop_red_val=0;
	tie(drop_red_cell_x,drop_red_cell_y,drop_red_val) = cells.redCells[cells.redDropIndex];

	int drop_green_cell_x,drop_green_cell_y,drop_green_val;
	tie(drop_green_cell_x,drop_green_cell_y,drop_green_val) = cells.greenCells[cells.greenDropIndex];

	int drop_blue_cell_x,drop_blue_cell_y,drop_blue_val;
	tie(drop_blue_cell_x,drop_blue_cell_y,drop_blue_val) = cells.blueCells[cells.blueDropIndex];

	int dropColor;

	int current_node_x,current_node_y,nearest_node_x,nearest_node_y,x_diff2,y_diff2 ;

	REP(i,0,3){
		dropColor = cells.droppingOrder[i];
		current_node_x = get_x(pose.node_pose);
		current_node_y = get_y(pose.node_pose);

		if (dropColor==RED_COLOR){
				tie(nearest_node_x,nearest_node_y)=get_nearest_node(current_node_x,current_node_y,drop_red_cell_x,drop_red_cell_y);
				cout << "red coin node: " << nearest_node_x << " "<<nearest_node_y << endl;

				navigate_to_target_cell(current_node_x,current_node_y,nearest_node_x,nearest_node_y);

				current_node_x = get_x(pose.node_pose);
				current_node_y = get_y(pose.node_pose);
				int sub_val_x_ = current_node_x - drop_red_cell_x;
				int sub_val_y_ = current_node_y - drop_red_cell_y;
				if (sub_val_x_ <= 0 && sub_val_y_ <= 0)
				{
					pose.turn_to(pose.orientation, NORTH);
				}
				else if (sub_val_x_ <= 0 && sub_val_y_ > 0)
				{
					pose.turn_to(pose.orientation, EAST);
				}
				else if (sub_val_x_ > 0 && sub_val_y_ <= 0)
				{
					pose.turn_to(pose.orientation, WEST);
				}
				else
				{
					pose.turn_to(pose.orientation, SOUTH);
				}				

				drop_coin_impl(dropColor);

				print_grid(get_x(pose.node_pose),get_y(pose.node_pose), pose.orientation);

	
				pose.go_to_node_in_front();

				print_grid(get_x(pose.node_pose),get_y(pose.node_pose), pose.orientation);

		}
		else if (dropColor==GREEN_COLOR){
			  tie(nearest_node_x,nearest_node_y)=get_nearest_node(current_node_x,current_node_y,drop_green_cell_x,drop_green_cell_y);
				cout << "green coin node: " << nearest_node_x << " "<<nearest_node_y << endl;
        navigate_to_target_cell(current_node_x,current_node_y,nearest_node_x,nearest_node_y);

				current_node_x = get_x(pose.node_pose);
				current_node_y = get_y(pose.node_pose);
				int sub_val_x_ = current_node_x - drop_green_cell_x;
				int sub_val_y_ = current_node_y - drop_green_cell_y;
				if (sub_val_x_ <= 0 && sub_val_y_ <= 0)
				{
					pose.turn_to(pose.orientation, NORTH);
				}
				else if (sub_val_x_ <= 0 && sub_val_y_ > 0)
				{
					pose.turn_to(pose.orientation, EAST);
				}
				else if (sub_val_x_ > 0 && sub_val_y_ <= 0)
				{
					pose.turn_to(pose.orientation, WEST);
				}
				else
				{
					pose.turn_to(pose.orientation, SOUTH);
				}				

				drop_coin_impl(dropColor);

  			print_grid(get_x(pose.node_pose),get_y(pose.node_pose), pose.orientation);
	
				pose.go_to_node_in_front();

  			print_grid(get_x(pose.node_pose),get_y(pose.node_pose), pose.orientation);
		}
		else{
			  tie(nearest_node_x,nearest_node_y)=get_nearest_node(current_node_x,current_node_y,drop_blue_cell_x,drop_blue_cell_y);

				cout << "blue coin node: " << nearest_node_x << " "<<nearest_node_y << endl;
        navigate_to_target_cell(current_node_x,current_node_y,nearest_node_x,nearest_node_y);

				current_node_x = get_x(pose.node_pose);
				current_node_y = get_y(pose.node_pose);
				int sub_val_x_ = current_node_x - drop_blue_cell_x;
				int sub_val_y_ = current_node_y - drop_blue_cell_y;
				if (sub_val_x_ <= 0 && sub_val_y_ <= 0)
				{
					pose.turn_to(pose.orientation, NORTH);
				}
				else if (sub_val_x_ <= 0 && sub_val_y_ > 0)
				{
					pose.turn_to(pose.orientation, EAST);
				}
				else if (sub_val_x_ > 0 && sub_val_y_ <= 0)
				{
					pose.turn_to(pose.orientation, WEST);
				}
				else
				{
					pose.turn_to(pose.orientation, SOUTH);
				}	
				
				drop_coin_impl(dropColor);

  			print_grid(get_x(pose.node_pose),get_y(pose.node_pose), pose.orientation);
	
				pose.go_to_node_in_front();

  			print_grid(get_x(pose.node_pose),get_y(pose.node_pose), pose.orientation);
		  }
	}
}




#endif