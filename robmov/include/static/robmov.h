#ifndef ROBMOV_H
#define ROBMOV_H

 
struct Robot {
    char *name;
};

int move(struct Robot * r);
int stop(struct Robot * r);




#endif /* ROBMOV_H */