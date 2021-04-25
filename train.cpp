#include "components.h"
#include <cstddef>
#include <iostream>

using namespace std;

train::train(int id, node *current, train_state_t state, int dest_id, train_dir_t td) {
    train_id = id;
    current_segment = current;
    train_state = state;
    destination_node_id = dest_id;
    train_dir = td;
}

// returns the id of node after traversal
int train::traverse_node() {
    // don't go anywhere if train is stopped
    if(train_state == STOPPED) {
        cout << "Train " << train_id << " is stopped at " << current_segment->get_node_id() << endl;
        return current_segment->get_node_id();
    }
    // if there is no connected node then we're at a terminator
    if((train_dir == FORWARD && current_segment->get_end()->get_partner() == NULL) ||
        (train_dir == BACKWARD && current_segment->get_start()->get_partner() == NULL)) {
        cout << "Train " << train_id << " stopped as it has reached a terminator at " << current_segment->get_node_id() << endl;
        train_state = STOPPED;
        return current_segment->get_node_id();
    }
    // if the train is at a junction not configured to the train's segment, train is stopped
    if(current_segment->get_node_type() == JUNCTION) {
        // TODO: HANDLE JUNCTION LOGIC
        // train_state = STOPPED;
        // return current_segment->get_node_id();
    }

    if(train_dir == FORWARD) current_segment = current_segment->get_end()->get_partner()->get_node();
    else if(train_dir == BACKWARD) current_segment = current_segment->get_start()->get_partner()->get_node();

    cout << "Train " << train_id << " traversed to " << current_segment->get_node_id() << endl;

    return current_segment->get_node_id();
}

node *train::get_current_segment() {
    return current_segment;
}

void train::set_destination_node_id(int dest_id) {
    cout << "Setting train " << train_id << " destination to " << dest_id << endl;
    destination_node_id = dest_id;
}

int train::get_destination_node_id() {
    return destination_node_id;
}

void train::set_train_state(train_state_t state) {
    train_state = state;
}

train_state_t train::get_train_state() {
    return train_state;
}

void train::set_train_dir(train_dir_t dir) {
    dir == BACKWARD ? cout << "Setting train " << train_id << " to BACKWARD" << endl:cout << "Setting train " << train_id << " to FORWARD" << endl;

    train_dir = dir;
}

train_dir_t train::get_train_dir() {
    return train_dir;
}