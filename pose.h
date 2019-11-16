#ifndef POSE_H_
#define POSE_H_

#include "maze_def.h"

int get_node_pose(int x, int y) { return x * MAX_SIDE_NODES + y; }

int get_x(int node_pose) { return node_pose / MAX_SIDE_NODES; }

int get_y(int node_pose) { return node_pose % MAX_SIDE_NODES; }

struct Pose
{
    int node_pose = 0;    // This is x*MAX_SIDE_NODES + y
    int orientation = NORTH; // This is number between 0 and 3 (Facing direction)

    // ================================================= Getters

    int clockwise_direction()
    {
        return (orientation + 1) % 4;
    }

    int counter_clockwise_direction()
    {
        return (orientation != 0) ? orientation - 1 : 3;
    }

    // Get node_pose of the tile in the direction (relative to robot pose)
    int node_pose_of_relative_node(int dir)
    {
        // First extract X, Y coordinates
        int x = get_x(node_pose);
        int y = get_y(node_pose);

        // Then change them
        switch (dir)
        {
        case EAST:
            x += 1;
            break;
        case WEST:
            x -= 1;
            break;
        case SOUTH:
            y -= 1;
            break;
        default: // NORTH
            y += 1;
            break;
        }

        // Convert them back
        return get_node_pose(x, y);
    }

    // ================================================= Setters

    void turn_clockwise()
    {
        orientation = clockwise_direction();
    }

    void turn_counter_clockwise()
    {
        orientation = counter_clockwise_direction();
    }

    void go_to_node_in_front()
    {
        node_pose = node_pose_of_relative_node(orientation);
    }


		    //This function is for turning to the required direction.
    void turn_to(int dir,int required_dir)
    {   
        int diff = required_dir-dir;
        switch (diff)
        {
        case 3:
            turn_counter_clockwise();
            break;
				case -3:
						turn_clockwise();
						break;
        case 2:
            turn_clockwise();
            turn_clockwise();
            break;
				case -2:
						turn_clockwise();
						turn_clockwise();
						break;
        case 1:
            turn_clockwise();
            break;
				case -1:
						turn_counter_clockwise();
						break;
        default: 
            break;
        }
    }

  
};

#endif // FLOODFILL_POSE_H_