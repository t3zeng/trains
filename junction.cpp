#include "components.h"
#include <cstddef>
#include <iostream>

using namespace std;

junction::junction(int id, connection *s, connection *el, connection *er, direction_t d) {
    start = new connection(s, this);
    end_left = new connection(el, this);
    end_right = new connection(er, this);
    dir = d;
    if(dir == RIGHT) end = end_right;
    else if(dir == LEFT) end = end_left;
    length = 0;
    node_id = id;
}

void junction::set_direction(direction_t d) {
    dir = d;
    if(dir == LEFT) {
        end = end_left;
    }
    else if(dir == RIGHT) {
        end = end_right;
    }
    else {
        cout << "ERROR: INVALID JUNCTION DIRECTION" << endl;
    }
}

direction_t junction::get_direction() {
    return dir;
}

connection *junction::get_end_left() {
    return end_left;
}

connection *junction::get_end_right() {
    return end_right;
}

reverse_junction::reverse_junction(int id, connection *sl, connection *sr, connection *e, direction_t d) {
    start_left = new connection(sl, this);
    start_right = new connection(sr, this);
    end = new connection(e, this);
    dir = d;
    if(dir == RIGHT) start = start_right;
    else if(dir == LEFT) start = start_left;
    length = 0;
    node_id = id;
}

void reverse_junction::set_direction(direction_t d) {
    dir = d;
    if(dir == LEFT) {
        start = start_left;
    }
    else if(dir == RIGHT) {
        start = start_right;
    }
    else {
        cout << "ERROR: INVALID JUNCTION DIRECTION" << endl;
    }
}

direction_t reverse_junction::get_direction() {
    return dir;
}

connection *reverse_junction::get_start_left() {
    return start_left;
}

connection *reverse_junction::get_start_right() {
    return start_right;
}