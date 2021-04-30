#include <iostream>
#include "components.h"
#include "input.h"
#include <vector>

using namespace std;

static vector<node *> node_array;
static vector<train *> train_array;

// Build Train Track Here
static void train_sandbox() {
    node_array.push_back(new track(1, NULL, NULL, 3, NONE));
    node_array.push_back(new track(2, node_array[0]->get_end(), NULL, 1, NONE));
    node_array.push_back(new track(3, node_array[1]->get_end(), NULL, 2, NONE));
    node_array.push_back(new track(4, node_array[2]->get_end(), NULL, 4, NONE));
    node_array.push_back(new track(5, node_array[3]->get_end(), NULL, 10, NONE));
    node_array.push_back(new track(6, node_array[4]->get_end(), NULL, 5, NONE));

    train_array.push_back(new train(1, node_array[0], MOVING, 6, FORWARD));
}

// @TODO: Junction, Stoplight control occurs here
// Fancy simulation logic here
void run_simulation() {
    train_sandbox();
    
    for(int i = 0; i < train_array.size(); i++) {
        cout << "Train " << train_array[i]->get_train_id() << " starting at " << train_array[i]->get_current_segment()->get_node_id() << endl;
        while(train_array[i]->get_current_segment()->get_node_id() != train_array[i]->get_destination_node_id()) {
            train_array[i]->traverse_node();
        }
        cout << "Train " << train_array[i]->get_train_id() << " arrived at the destination!" << endl;
    }
}