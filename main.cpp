#include <iostream>
#include "components.h"

using namespace std;

// track traversal demo using junctions
void track_traversal_demo() {
    track *t1 = new track(1, NULL, NULL, 1, NONE);
    track *t2 = new track(2, t1->get_end(), NULL, 2, NONE);
    track *t3 = new track(3, t2->get_end(), NULL, 3, NONE);
    junction *j1 = new junction(4, t3->get_end(), NULL, NULL, LEFT);
    track *t4 = new track(5, j1->get_end_left(), NULL, 4, NONE);
    track *t5 = new track(6, j1->get_end_right(), NULL, 5, NONE);

    node *alias = t1;
    while(alias->get_end()->get_partner() != NULL) {
        cout << alias->get_node_id() << endl;
        alias = alias->get_end()->get_partner()->get_node();
    }
    cout << alias->get_node_id() << endl;
    while(alias->get_start()->get_partner() != NULL) {
        cout << alias->get_node_id() << endl;
        alias = alias->get_start()->get_partner()->get_node();
    }
    cout << alias->get_node_id() << endl;

    j1->set_direction(RIGHT);

    while(alias->get_end()->get_partner() != NULL) {
        cout << alias->get_node_id() << endl;
        alias = alias->get_end()->get_partner()->get_node();
    }
    cout << alias->get_node_id() << endl;
    while(alias->get_start()->get_partner() != NULL) {
        cout << alias->get_node_id() << endl;
        alias = alias->get_start()->get_partner()->get_node();
    }
    cout << alias->get_node_id() << endl;
}

// train traversal demo
void train_traversal_demo() {
    track *t1 = new track(1, NULL, NULL, 1, NONE);
    track *t2 = new track(2, t1->get_end(), NULL, 2, NONE);
    track *t3 = new track(3, t2->get_end(), NULL, 3, NONE);
    junction *j1 = new junction(4, t3->get_end(), NULL, NULL, LEFT);
    track *t4 = new track(5, j1->get_end_left(), NULL, 4, NONE);
    track *t5 = new track(6, j1->get_end_right(), NULL, 5, NONE);
    train *my_train = new train(1, t1, MOVING, 5);

    cout << my_train->get_current_segment()->get_node_id() << endl;
    while(my_train->get_current_segment()->get_node_id() != my_train->get_destination_node_id()) {
        cout << my_train->traverse_node() << endl;
    }
}

int main() {
    // track_traversal_demo();
    // train_traversal_demo();

    return 0;
}