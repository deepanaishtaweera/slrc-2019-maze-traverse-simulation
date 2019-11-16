#ifndef CELLS_H_
#define CELLS_H_

#include "maze_def.h"
#include "impl/colors.h"
#include "basics.h"

bool is_valid_cell(int x, int y) { 
  return  (0 <= x && x < MAX_SIDE_CELLS) && // Check if X coord is out of bounds
          (0 <= y && y < MAX_SIDE_CELLS);   // Check if Y coord is out of bounds}
}

struct Cells
{
    int color[MAX_SIDE_CELLS][MAX_SIDE_CELLS];
    int value[MAX_SIDE_CELLS][MAX_SIDE_CELLS];
		tuple <int,int,int> redCells[3],blueCells[3],greenCells[3];
		int droppingOrder[3];
		int redDropIndex;
    int blueDropIndex;
    int greenDropIndex;

    // ================================================= Getters

    pair<int,int> right_cell(){
        int orientation = pose.orientation;
        int x = get_x(pose.node_pose);
        int y = get_y(pose.node_pose);
        switch(orientation){
          case EAST:
            x-=1;
            y-=1;
            break;

          case WEST:
            x=x;
            y=y;
            break;

          case SOUTH:
            x-=1;
            y=y;
            break;

          default:
            x=x;
            y-=1;
            
            break;
        }
      if (is_valid_cell(x,y)){
        return make_pair(x,y);
      }
      else{
        return make_pair(-1,-1);
      }
    }

    pair <int,int> left_cell()
    {
        int orientation = pose.orientation;
        int x = get_x(pose.node_pose);
        int y = get_y(pose.node_pose);
        switch(orientation)
        {
          case EAST:
            x-=1;
            y=y;
            break;

          case WEST:
            x=x;
            y-=1;
            break;

          case SOUTH:
            x=x;
            y=y;
            break;

          default:
            x-=1;
            y-=1;
            break;
        }
      if (is_valid_cell(x,y)){
        return make_pair(x,y);
      }
      else{
        return make_pair(-1,-1);
      }
    }

    // ================================================= Setters
    void set_cell_colors(){ 
      int left_x,left_y,right_x,right_y;
      tie(left_x,left_y) = left_cell();
      tie(right_x,right_y) = right_cell();
      
      if(is_valid_cell(left_x,left_y) && leftCellColor!=WHITE_COLOR){
        color[left_x][left_y] = leftCellColor;
      }
      else if (is_valid_cell(right_x,right_y)&& rightCellColor!=WHITE_COLOR){
        color[right_x][right_y] = rightCellColor;
      }
    }

		void set_cell_val(){
			int lastFoundColor = WHITE_COLOR, cellVal = 0;
			int temp_y;
			REP(x,0,MAX_SIDE_CELLS){
				REP(y,0,MAX_SIDE_CELLS){
					if (x%2){
						temp_y = MAX_SIDE_CELLS - 1 - y;
					}
					else{
						temp_y = y;
					}
					// cout << x << " " << temp_y << endl;
					cellVal += lastFoundColor +1;
					value[x][temp_y] = cellVal;
					if (color[x][temp_y]!=WHITE_COLOR){
						lastFoundColor = color[x][temp_y];
					}
				}
			}
		}

		void set_color_indexes(){
			int numOfRedFound=0,numOfGreenFound=0,numOfBlueFound=0;
			int temp_y;
			REP(i,0,3){
				redCells[i] = make_tuple(0,0,1);
				greenCells[i] = make_tuple(0,0,1);
				blueCells[i] = make_tuple(0,0,1);
			}
			REP(x,0,MAX_SIDE_CELLS){
				REP(y,0,MAX_SIDE_CELLS){
					if (x%2){
						temp_y = MAX_SIDE_CELLS - 1 - y;
					}
					else{
						temp_y = y;
					}
					if (color[x][temp_y]==RED_COLOR){
						numOfRedFound+=1;
						if (numOfRedFound<=3){
							redCells[numOfRedFound-1] = make_tuple(x,temp_y,value[x][temp_y]);
						}
					}
					else if (color[x][temp_y]==GREEN_COLOR){
						numOfGreenFound+=1;
						if (numOfGreenFound<=3){
							greenCells[numOfGreenFound-1] = make_tuple(x,temp_y,value[x][temp_y]);
						}
					}
					else if (color[x][temp_y]==BLUE_COLOR){
						numOfBlueFound+=1;
						if (numOfBlueFound<=3){
							blueCells[numOfBlueFound-1] = make_tuple(x,temp_y,value[x][temp_y]);
						}
					}
				}
			}
		}

		void set_dropping_order()
    {
			int redCellsValSum=0,greenCellsValSum=0,blueCellsValSum=0;
			REP(i,0,3){
				int temp_x,temp_y,temp_val;
				tie(temp_x,temp_y,temp_val) = redCells[i];
				redCellsValSum+=pow(temp_val,3-i);
				tie(temp_x,temp_y,temp_val) = greenCells[i];
				greenCellsValSum+=pow(temp_val,3-i);
				tie(temp_x,temp_y,temp_val) = blueCells[i];
				blueCellsValSum+=pow(temp_val,3-i);
			}
			// cout << "red sum: " << redCellsValSum << " green sum: " << greenCellsValSum << " blue sum: " << blueCellsValSum << endl;


			if (redCellsValSum<greenCellsValSum){
					if (blueCellsValSum<redCellsValSum){
							droppingOrder[0] = BLUE_COLOR;
							droppingOrder[1] = RED_COLOR;
							droppingOrder[2] = GREEN_COLOR;
					}
					else{
							droppingOrder[0] = RED_COLOR;
							if (blueCellsValSum<greenCellsValSum){
								droppingOrder[1] = BLUE_COLOR;	
								droppingOrder[2] = GREEN_COLOR;
							}
							else{
								droppingOrder[1] = GREEN_COLOR;
								droppingOrder[2] = BLUE_COLOR;
							}
							
					}
			}
			else{
					if (blueCellsValSum<greenCellsValSum){
							droppingOrder[0] = BLUE_COLOR;
							droppingOrder[1] = GREEN_COLOR;
							droppingOrder[2] = RED_COLOR;
					}
					else{
							droppingOrder[0] = GREEN_COLOR;
							if (blueCellsValSum<redCellsValSum){
								droppingOrder[1] = BLUE_COLOR;	
								droppingOrder[2] = RED_COLOR;
							}
							else{
								droppingOrder[1] = RED_COLOR;
								droppingOrder[2] = BLUE_COLOR;
							}
					}
			}

		}
    void set_drop_indexes()
    {
      pillarSum =  get_pillar_sum();
			int blueFibDigit = blueArr[pillarSum -100];
      int greenFibDigit = greenArr[pillarSum -100];
	    // cout << pillarSum << endl;
      //redDropIndex
			if (100 <= pillarSum && pillarSum < 167){
        redDropIndex = 0;
      }
      else if (167 <= pillarSum && pillarSum < 233){
        redDropIndex = 1;
      }
      else {
        redDropIndex = 2;
      }

      //blueDropIndex
      if (0 <= blueFibDigit && blueFibDigit < 3){
				blueDropIndex = 0;
			}
			else if(3 <= blueFibDigit && blueFibDigit< 7){
				blueDropIndex = 1;
			}
			else
      {
				blueDropIndex = 2;
			}

      //greenDropIndex
      if (0 <= greenFibDigit && greenFibDigit < 3){
				greenDropIndex = 0;
			}
			else if(3 <= greenFibDigit && greenFibDigit< 7){
				greenDropIndex = 1;
			}
			else
      {
				greenDropIndex = 2;
			}
		}
};

#endif // FLOODFILL_POSE_H_