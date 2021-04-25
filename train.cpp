#include "components.h"

train::train(int id, node *current, train_state_t state, int dest_id) {
    train_id = id;
    current_segment = current;
    train_state = state;
    destination_node_id = dest_id;
}