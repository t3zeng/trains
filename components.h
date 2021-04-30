#pragma once

class track;
class connection;
class junction;
class node;

typedef enum {
    TRACK,
    JUNCTION
} node_type_t;

class node {
    protected:
        connection *start;
        connection *end;
        int length;
        int node_id;
        node_type_t type;
    public:
        connection *get_start();
        connection *get_end();
        int get_length();
        int get_node_id();
        node_type_t get_node_type();
};

typedef enum {
    NONE,
    RED,
    GREEN
} signal_state_t;

class track : public node {
    private:
        signal_state_t sig;
    public:
        track(int id, connection *s, connection *e, int l, signal_state_t ss);
        void set_signal(signal_state_t ss);
        signal_state_t get_signal();
};

class connection {
    protected:
        connection *partner;
        node *associated_node;
    public:
        connection(connection *p, node *n);
        connection *get_partner();
        node *get_node();
};

typedef enum {
    LEFT,
    RIGHT
} direction_t;

class junction : public node {
    private:
        connection *end_left;
        connection *end_right;
        direction_t dir;
    public:
        junction(int id, connection *s, connection *el, connection *er, direction_t d);
        void set_direction(direction_t d);
        direction_t get_direction();
        connection *get_end_left();
        connection *get_end_right();
};

class reverse_junction : public node {
    private:
        connection *start_left;
        connection *start_right;
        direction_t dir;
    public:
        reverse_junction(int id, connection *sl, connection *sr, connection *e, direction_t d);
        void set_direction(direction_t d);
        direction_t get_direction();
        connection *get_start_left();
        connection *get_start_right();
};

typedef enum {
    STOPPED,
    MOVING
} train_state_t;

typedef enum {
    BACKWARD,
    FORWARD
} train_dir_t;

class train {
    private:
        int train_id;
        train_state_t train_state;
        node *current_segment;
        int destination_node_id;
        train_dir_t train_dir;
        int segment_idx;
    public:
        train(int id, node *current, train_state_t state, int dest_id, train_dir_t td);
        int traverse_node();
        node *get_current_segment();
        void set_destination_node_id(int dest_id);
        int get_destination_node_id();
        void set_train_state(train_state_t state);
        train_state_t get_train_state();
        void set_train_dir(train_dir_t dir);
        train_dir_t get_train_dir();
        int get_train_id();
};