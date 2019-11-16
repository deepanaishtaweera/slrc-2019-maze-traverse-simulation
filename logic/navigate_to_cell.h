#ifndef NAVIGATE_TO_CELL_H
#define NAVIGATE_TO_CELL_H

#include "../pose.h"
#include "../impl/motors.h"

// //Assumed that robot drop the coin from right side.
// void navigate_to_target_cell(int current_node_x,int current_node_y,int nearest_node_x,int nearest_node_y){
//     int x_diff = nearest_node_x - current_node_x;
//     int y_diff = nearest_node_y - current_node_y;
//     int orientation = pose.orientation;
//     if (x_diff>=0 && y_diff>=0){
//         if(x_diff==0 && y_diff==0){ //This case usally doesn't occur. This happens only when we ask to navigate to the same cell.
//             pose.turn_to(orientation,WEST);
//         }
// 				else{
// 					pose.turn_to(orientation,EAST);  //Assumed that robot drop the coin from right side.
// 					REP(i,0,x_diff){
// 							move_to_next_node();
// 					}
 
// 					turn_left_90();
// 					REP(i,0,y_diff){
// 							move_to_next_node();					
// 					}
// 				}

//     }

//     else if (x_diff>=0 && y_diff<0){

//         pose.turn_to(orientation,SOUTH);  //Assumed that robot drop the coin from right side.
//         REP(i,0,abs(y_diff)){
//             move_to_next_node();
//         }
// 				turn_left_90();
// 				REP(i,0,x_diff){
// 						move_to_next_node();					
//         }
//     }

//     else if (x_diff<0 && y_diff>=0){
//         pose.turn_to(orientation,NORTH);  //Assumed that robot drop the coin from right side.
//         REP(i,0,y_diff){
//             move_to_next_node();
//         }
//         turn_left_90();
//         REP(i,0,abs(x_diff)){
//             move_to_next_node();
//         }
//     }
//     else if (x_diff<0 && y_diff<0){
//         pose.turn_to(orientation,WEST);  //Assumed that robot drop the coin from right side.
//         REP(i,0,abs(x_diff)){
//             move_to_next_node();
//         }
//         turn_left_90();
//         REP(i,0,abs(y_diff)){
//             move_to_next_node();
//         }
//     }

// }

// //Assumed that robot drop the coin from right side.
// void navigate_to_target_cell(int current_node_x,int current_node_y,int nearest_node_x,int nearest_node_y){
//     int x_diff = nearest_node_x - current_node_x;
//     int y_diff = nearest_node_y - current_node_y;
//     int orientation = pose.orientation;
// 		if ( x_diff==0 && y_diff>0){
// 			pose.turn_to(orientation,NORTH);
// 			REP(i,0,y_diff){
// 					move_to_next_node();					
// 			}
// 		}
// 		else if(x_diff==0 && y_diff<0){
// 			pose.turn_to(orientation,SOUTH);
// 			REP(i,0,abs(y_diff)){
// 					move_to_next_node();					
// 			}
// 		}
// 		else if(x_diff==0 && y_diff==0) {
// 					pose.turn_to(orientation,WEST);

// 		}
// 		else if( y_diff==0 && x_diff>0){
// 			pose.turn_to(orientation,EAST);
// 			REP(i,0,x_diff){
// 					move_to_next_node();
// 			}
// 		}
// 		else if(y_diff==0 && x_diff<0){
// 		pose.turn_to(orientation,WEST);
// 		REP(i,0,abs(x_diff)){
// 				move_to_next_node();
// 			}
// 		}

// 		else if (x_diff>0 && y_diff>0){
// 					pose.turn_to(orientation,EAST);  //Assumed that robot drop the coin from right side.
// 					REP(i,0,x_diff){
// 							move_to_next_node();
// 					}

// 					turn_left_90();
// 					REP(i,0,y_diff){
// 							move_to_next_node();					
// 				}

//     }

//     else if (x_diff>0 && y_diff<0){

//         pose.turn_to(orientation,SOUTH);  //Assumed that robot drop the coin from right side.
//         REP(i,0,abs(y_diff)){
//             move_to_next_node();
//         }
// 				turn_left_90();
// 				REP(i,0,x_diff){
// 						move_to_next_node();					
//         }
//     }

//     else if (x_diff<0 && y_diff>0){
//         pose.turn_to(orientation,NORTH);  //Assumed that robot drop the coin from right side.
//         REP(i,0,y_diff){
//             move_to_next_node();
//         }
//         turn_left_90();
//         REP(i,0,abs(x_diff)){
//             move_to_next_node();
//         }
//     }
//     else if (x_diff<0 && y_diff<0){
//         pose.turn_to(orientation,WEST);  //Assumed that robot drop the coin from right side.
//         REP(i,0,abs(x_diff)){
//             move_to_next_node();
//         }
//         turn_left_90();
//         REP(i,0,abs(y_diff)){
//             move_to_next_node();
//         }
//     }

// }




//Assumed that robot drop the coin from right side.
void navigate_to_target_cell(int current_node_x,int current_node_y,int nearest_node_x,int nearest_node_y){
    int x_diff = nearest_node_x - current_node_x;
    int y_diff = nearest_node_y - current_node_y;
    int orientation = pose.orientation;

		if ( x_diff==0){
			if (y_diff>0){
				pose.turn_to(orientation,NORTH);
				REP(i,0,y_diff){
						move_to_next_node();					
				}
			}
			else if(y_diff<0){
				pose.turn_to(orientation,SOUTH);
				REP(i,0,abs(y_diff)){
						move_to_next_node();					
				}
			}
			else{

			}
		}

		else if( y_diff==0){
			if (x_diff>0){
				pose.turn_to(orientation,EAST);
				REP(i,0,x_diff){
						move_to_next_node();
				}
			}
			else if(x_diff<0){
				pose.turn_to(orientation,WEST);
				REP(i,0,abs(x_diff)){
						move_to_next_node();
				}
			}
			else{
				// pose.turn_to(pose.orientation);
			}
		}




    else if (x_diff>0 && y_diff>0){
					pose.turn_to(orientation,EAST);  //Assumed that robot drop the coin from right side.
					REP(i,0,x_diff){
							move_to_next_node();
					}

					turn_left_90();
					REP(i,0,y_diff){
							move_to_next_node();					
				}

    }

    else if (x_diff>0 && y_diff<0){

        pose.turn_to(orientation,SOUTH);  //Assumed that robot drop the coin from right side.
        REP(i,0,abs(y_diff)){
            move_to_next_node();
        }
				turn_left_90();
				REP(i,0,x_diff){
						move_to_next_node();					
        }
    }

    else if (x_diff<0 && y_diff>0){
        pose.turn_to(orientation,NORTH);  //Assumed that robot drop the coin from right side.
        REP(i,0,y_diff){
            move_to_next_node();
        }
        turn_left_90();
        REP(i,0,abs(x_diff)){
            move_to_next_node();
        }
    }
    else if (x_diff<0 && y_diff<0){
        pose.turn_to(orientation,WEST);  //Assumed that robot drop the coin from right side.
        REP(i,0,abs(x_diff)){
            move_to_next_node();
        }
        turn_left_90();
        REP(i,0,abs(y_diff)){
            move_to_next_node();
        }
    }

}

void go_to_ending_node(){
	int nearest_node_x=8,nearest_node_y=0;
	navigate_to_target_cell(get_x(pose.node_pose),get_y(pose.node_pose),nearest_node_x,nearest_node_y);
	pose.turn_to(pose.orientation,SOUTH);
}


#endif