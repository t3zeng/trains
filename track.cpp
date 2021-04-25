#include "components.h"
#include <cstddef>

using namespace std;

// start - points to what connection the starting connection points to
// end - points to what connection the ending connection points to
track::track(connection *s, connection *e, int l, signal_state_t ss) {
    start = new connection(s, this, NULL);
    end = new connection(e, this, NULL);
    length = l;
    sig = ss;
    has_train = false;
}