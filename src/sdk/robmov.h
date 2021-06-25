#ifndef ROBMOV_H
#define ROBMOV_H

struct Robot {
    char *name;
};

int move_forward(struct Robot * r);
int move_backward(struct Robot * r);
int move_right(struct Robot * r);
int move_letf(struct Robot * r);
int rotate_right(struct Robot * r);
int rotate_left(struct Robot * r);
int stop(struct Robot * r);

#endif /* ROBMOV_H */