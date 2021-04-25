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

int node::get_node_id() {
    return node_id;
}

node_type_t node::get_node_type() {
    return type;
}