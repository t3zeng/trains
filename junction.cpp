#include "components.h"
#include <cstddef>
#include <iostream>

using namespace std;

junction::junction(connection *s, connection *el, connection *er, direction_t d) {
    start = new connection(s, this);
    end_left = new connection(el, this);
    end_right = new connection(er, this);
    end = end_left;
    dir = d;
    length = 0;
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