#include "components.h"

int node::get_length() {
    return length;
}

connection * node::get_start() {
    return start;
}

connection * node::get_end() {
    return end;
}