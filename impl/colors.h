#ifndef COLORS_H_
#define COLORS_H_

#include "../basics.h"
#include "../maze_def.h"

int leftLineColor,rightLineColor,centerLineColor,leftCellColor = WHITE_COLOR,rightCellColor = WHITE_COLOR;

void update_colors()
{
  leftCellColor = WHITE_COLOR;
  rightCellColor = WHITE_COLOR;
  leftLineColor = get_left_color();
  rightLineColor = get_right_color();
  centerLineColor = get_center_color();

  if(leftLineColor == centerLineColor && leftLineColor != WHITE_COLOR){
    leftCellColor = leftLineColor;
  }
  else if (rightLineColor == centerLineColor && rightLineColor != WHITE_COLOR){
    rightCellColor = rightLineColor;
  }
}

#endif