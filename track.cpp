#include "components.h"
#include <cstddef>

using namespace std;

// start - points to what connection the starting connection points to
// end - points to what connection the ending connection points to
track::track(int id, connection *s, connection *e, int l, signal_state_t ss) {
    start = new connection(s, this);
    end = new connection(e, this);
    length = l;
    sig = ss;
    has_train = false;
    node_id = id;
}

void track::set_signal(signal_state_t ss) {
    sig = ss;
}

signal_state_t track::get_signal() {
    return sig;
}