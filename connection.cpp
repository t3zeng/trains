#include "components.h"
#include <cstddef>

connection::connection(connection *p, node *n) {
    // connects to partner connection
    partner = p;

    // if partner is not NULL, attach partner to this connection
    if (partner != NULL) {
        partner->partner = this;
    }

    // ties connection to a node (track/junction)
    associated_node = n;
}

connection *connection::get_partner() {
    return partner;
}

node *connection::get_node() {
    return associated_node;
}