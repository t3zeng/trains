#include <iostream>
#include "components.h"

using namespace std;

// track traversal demo using junctions and going backwards
void track_traversal_demo() {
    track *t1 = new track(NULL, NULL, 1, NONE);
    track *t2 = new track(t1->get_end(), NULL, 2, NONE);
    track *t3 = new track(t2->get_end(), NULL, 3, NONE);
    junction *j1 = new junction(t3->get_end(), NULL, NULL, LEFT);
    track *t4 = new track(j1->get_end_left(), NULL, 4, NONE);
    track *t5 = new track(j1->get_end_right(), NULL, 5, NONE);

    node *alias = t1;
    while(alias->get_end()->get_partner() != NULL) {
        cout << alias->get_length() << endl;
        alias = alias->get_end()->get_partner()->get_track();
    }
    cout << alias->get_length() << endl;
    while(alias->get_start()->get_partner() != NULL) {
        cout << alias->get_length() << endl;
        alias = alias->get_start()->get_partner()->get_track();
    }
    cout << alias->get_length() << endl;
}

int main() {
    track_traversal_demo();

    return 0;
}