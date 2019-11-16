#ifndef GRID_H_
#define GRID_H_

#include "../maze_def.h"
#include "print.h"

void print_grid(int pos_x,int pos_y, int orientation){

  int userRows= 8,userColumns=8;
  int arr[64];

  for (int k=1;k<=64;k++){
	
    arr[k-1]=k;
  }

  cout<<endl;
  cout<<" ";
  int i=0,j;
  int row=8, col;
  for(j = 0; j <= 4*userColumns; j++){
    if(j%4==2){
        cout<<i++;
    }
    else cout<<" ";
  }
  cout<<endl;

  for(i = 0; i <= 2*(userRows) ;i++){ 
    // if (i>2*userRows){

    // }
    if(i%2!=0){
      row = 7-(i/2);
      cout<< " ";
      
    }
    for(j = 0; j <= 2*userColumns; j++){
      int col = j/2;
      if(i%2==0)
      {
        if(j==0){
            cout<<" ";
        }
        if(j%2==0){
          // node position of the robot
          if ((row==pos_y) && (col==pos_x)){
            if (orientation==NORTH){
              cout << "^";
            }
            else if (orientation==SOUTH){
              cout << "V";
            }
            else if (orientation==EAST){
              cout << ">";
            }
            else{
              cout << "<";
            }
            
          }
          else
            cout<<" ";
        }    
        else cout<<"---";
      }
      else{
        if(j%2==0)
            cout<<"|";
        else {
          //square(*) position
          // if ((row==pos_x) && (col==pos_y)){
          //   cout << cells.color[row][col];
          // }
          // else{
          //   cout<<"   ";
          // }

          cout << " " << cells.color[col][row] <<" ";
          
        }
      }
    }

    if(i%2!=0)
      cout<<"  "<<7-(i/2);
    cout<<endl;

  }
}

#endif
