#pragma once

class track;
class connection;
class junction;
class node;

class node {
    protected:
        connection *start;
        connection *end;
        int length;
        int node_id;
    public:
        connection *get_start();
        connection *get_end();
        int get_length();
        int get_node_id();
};

typedef enum {
    NONE,
    RED,
    GREEN
} signal_state_t;

class track : public node {
    private:
        signal_state_t sig;
        bool has_train;
    public:
        track(int id, connection *s, connection *e, int l, signal_state_t ss);
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

typedef enum {
    STOPPED,
    MOVING
} train_state_t;

class train {
    private:
        int train_id;
        train_state_t train_state;
        node *current_segment;
        int destination_node_id;
    public:
        train(int id, node *current, train_state_t state, int dest_id);
        int traverse_node();
        node *get_current_segment();
        int get_destination_node_id();
        void set_train_state(train_state_t state);
        train_state_t get_train_state();
};