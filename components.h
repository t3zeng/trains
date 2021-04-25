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
    public:
        connection *get_start();
        connection *get_end();
        int get_length();
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
        track(connection *s, connection *e, int l, signal_state_t ss);
};

class connection {
    protected:
        connection *partner;
        track *associated_track;
        junction *associated_junction;
    public:
        connection(connection *p, track *t, junction *j);
        connection *get_partner();
        track *get_track();
        junction *get_junction();
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
        junction(connection *s, connection *el, connection *er, direction_t d);
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
        train_state_t state;
    public:
        train(int id);
};