#include "components.h"
#include <cstddef>

connection::connection(connection *p, track *t, junction *j) {
    // connects to partner connection
    partner = p;

    // if partner is not NULL, attach partner to this connection
    if (partner != NULL) {
        partner->partner = this;
    }

    // ties connection to a track
    associated_track = t;

    // ties connection to a junction
    associated_junction = j;
}

connection *connection::get_partner() {
    return partner;
}

track *connection::get_track() {
    return associated_track;
}

junction *connection::get_junction() {
    return associated_junction;
}