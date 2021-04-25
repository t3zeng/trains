#include "components.h"
#include <cstddef>

train::train(int id, node *current, train_state_t state, int dest_id) {
    train_id = id;
    current_segment = current;
    train_state = state;
    destination_node_id = dest_id;
}

// returns the id of node after traversal
int train::traverse_node() {
    // don't go anywhere if train is stopped
    if(train_state == STOPPED) {
        return current_segment->get_node_id();
    }
    // if there is no connected node then we're at a terminator
    if(current_segment->get_end()->get_partner() == NULL) {
        train_state = STOPPED;
        return current_segment->get_node_id();
    }

    current_segment = current_segment->get_end()->get_partner()->get_node();
    return current_segment->get_node_id();
}

node *train::get_current_segment() {
    return current_segment;
}

int train::get_destination_node_id() {
    return destination_node_id;
}