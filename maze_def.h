#ifndef MAZE_DEF_H_
#define MAZE_DEF_H_

#define REP(i, a, b) for (int i = a; i < b; i++)
#define REP_N(i, a, b) for (int i = a; i > b; i--)

#include <iostream>
#include <stdio.h>
#include <utility>
#include <tuple>
#include<cmath>
using namespace std;

#define GO_FORWARD 0
#define TURN_RIGHT 1
#define TRUN_LEFT 2

#define MAX_SIDE_NODES 9
#define MAX_SIDE_CELLS 8

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// color defs
#define WHITE_COLOR 0
#define RED_COLOR 1
#define GREEN_COLOR 2
#define BLUE_COLOR 3

//indicating line values
#define LINE1_VALUE = 10
#define LINE2_VALUE = 20
#define LINE3_VALUE = 30
#define LINE4_VALUE = 40

//pillar position values
#define LEFT_VALUE = 1
#define RIGHT_VALUE = 2
#define LEFT_AND_RIGHT_VALUE = 3

#endif