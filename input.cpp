#include <iostream>
#include "components.h"
#include "input.h"
#include <vector>
#include "djikstra.h"

using namespace std;

static vector<node *> node_array;
static vector<train *> train_array;

// Build Train Track Here
static void train_sandbox() {
    node_array.push_back(new track(0, NULL, NULL, 3, NONE));
    node_array.push_back(new track(1, ((track*)node_array[0])->get_end(), NULL, 1, NONE));
    node_array.push_back(new track(2, ((track*)node_array[1])->get_end(), NULL, 2, NONE));
    node_array.push_back(new track(3, ((track*)node_array[2])->get_end(), NULL, 4, NONE));
    node_array.push_back(new track(4, ((track*)node_array[3])->get_end(), NULL, 10, NONE));
    node_array.push_back(new track(5, ((track*)node_array[4])->get_end(), NULL, 5, NONE));
    node_array.push_back(new junction(6, ((track*)node_array[5])->get_end(), NULL, NULL, LEFT));
    node_array.push_back(new track(7, ((junction *)node_array[6])->get_end_left(), NULL, 1, NONE));
    node_array.push_back(new track(8, ((junction *)node_array[6])->get_end_right(), NULL, 2, NONE));

    train_array.push_back(new train(1, ((track*)node_array[0]), MOVING, 7, FORWARD));
}

// @TODO: Junction, Stoplight control occurs here
// Fancy simulation logic here
void run_simulation() {
    train_sandbox();

    // @TODO: dynamically generate from train system
    int graph[V][V] = {{0, node_array[0]->get_length(), 0, 0, 0, 0, 0, 0, 0},
                       {node_array[0]->get_length(), 0, node_array[1]->get_length(), 0, 0, 0, 0, 0, 0},
                        {0, node_array[1]->get_length(), 0, node_array[2]->get_length(), 0, 0, 0, 0, 0},
                        {0, 0, node_array[2]->get_length(), 0, node_array[3]->get_length(), 0, 0, 0, 0},
                        {0, 0, 0, node_array[3]->get_length(), 0, node_array[4]->get_length(), 0, 0, 0},
                        {0, 0, 0, 0, node_array[4]->get_length(), 0, node_array[5]->get_length(), 0, 0},
                        {0, 0, 0, 0, 0, node_array[5]->get_length(), 0, node_array[7]->get_length(), node_array[8]->get_length()},
                        {0, 0, 0, 0, 0, 0, node_array[7]->get_length(), 0, node_array[6]->get_length()},
                        {0, 0, 0, 0, 0, 0, node_array[8]->get_length(), 0, node_array[6]->get_length()},
                    };
    
    for(int i = 0; i < train_array.size(); i++) {
        dijkstra(graph, train_array[i]->get_current_segment()->get_node_id());
        cout << endl << "Train " << train_array[i]->get_train_id() << " starting at " << train_array[i]->get_current_segment()->get_node_id() << endl;
        while(train_array[i]->get_current_segment()->get_node_id() != train_array[i]->get_destination_node_id()) {
            // @TODO: build infra to traverse min_path result
            train_array[i]->traverse_node();
        }
        cout << "Train " << train_array[i]->get_train_id() << " arrived at the destination!" << endl;
    }
}