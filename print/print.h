#ifndef PRINT_H_
#define PRINT_H_

#include "../maze_def.h"
#include "../basics.h"

int cellArray[MAX_SIDE_CELLS][MAX_SIDE_CELLS];

void drop_coin_impl(int dropColor){
	cout << "Coin Dropped" << endl;
}

void get_test_maze(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  REP(j,0,MAX_SIDE_CELLS){
		REP(i,0,MAX_SIDE_CELLS){
      int tempCellColor;
      cin >> tempCellColor;
      cellArray[i][MAX_SIDE_CELLS-1-j]=tempCellColor;
    }
  }

	REP(j,0,MAX_SIDE_CELLS){
		REP(i,0,MAX_SIDE_CELLS){
      cout << cellArray[i][MAX_SIDE_CELLS-1-j] << " ";
    }
    cout << " "<< endl;
  }
  cout << " "<< endl;
}

void print_saved_cells(){
  REP(j,0,MAX_SIDE_CELLS){
		REP(i,0,MAX_SIDE_CELLS){
      cout << cells.color[i][MAX_SIDE_CELLS-1-j] << " ";
    }
    cout << " "<< endl;
  }
	cout << endl;
}

void print_color_indexes(){
	int x,y,z;
	cout << "red cells" << endl;
	REP(i,0,3){
				tie(x,y,z) = cells.redCells[i];
				cout << x << " " << y << " " << z << endl;		
	}
	cout << "green cells" << endl;
	REP(i,0,3){
        tie(x,y,z) = cells.greenCells[i];
				cout << x << " " << y << " " << z << endl;	
	}
	cout << "blue cells" << endl;
	REP(i,0,3){
				tie(x,y,z) = cells.blueCells[i];
				cout << x << " " << y << " " << z << endl;			
	}
	cout << endl;
}

void print_cell_values(){
	REP(j,0,MAX_SIDE_CELLS){
		REP(i,0,MAX_SIDE_CELLS){
      cout << cells.value[i][MAX_SIDE_CELLS-1-j] << " ";
    }
    cout << " "<< endl;
  }
	cout << endl;
}

void print_drop_order(){
	cout << "Dropping order: " << cells.droppingOrder[0] << " " << cells.droppingOrder[1] << " " << cells.droppingOrder[2] << endl;
}

void print_drop_indexes(){
	cout << "red index: " << cells.redDropIndex << " green index: " << cells.greenDropIndex << " blue index: " << cells.blueDropIndex << endl;
}

void print_node(){
  cout << "node x: " << get_x(pose.node_pose) << " node y: " << get_y(pose.node_pose) << endl;
}

void print_relative_cells(){
  int x,y;
  tie(x,y) = cells.right_cell();
  cout << "Right cell: " << x << " " << y << endl;
  tie(x,y) = cells.left_cell();
  cout << "Left cell: " << x << " " << y << endl << endl;
}

int get_left_color(){
  int left_x,left_y;
  tie(left_x,left_y) = cells.left_cell();
  return cellArray[left_x][left_y];
}

int get_right_color(){
  int right_x,right_y;
  tie(right_x,right_y) = cells.right_cell();
  return cellArray[right_x][right_y];
}

int get_center_color(){
  int left_x,left_y;
  tie(left_x,left_y) = cells.left_cell();
  int right_x,right_y;
  tie(right_x,right_y) = cells.right_cell();
  if (cellArray[right_x][right_y] != WHITE_COLOR){
    return cellArray[right_x][right_y];
  }
  else{
    return cellArray[left_x][left_y];
  }
}

int get_pillar_sum(){
		int tempPillarSum;
		cin >> tempPillarSum;
		return tempPillarSum;
}

#endif