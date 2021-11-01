#include "../include/proc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int find_index(struct Proc *procs, int count, char * package_id){
    for (int i = 0; i < count; ++i)
    {
        Proc proc = procs[i];
        int result;
        result = strcmp(proc.package_id, package_id);
        if (result == 0){
            return i;
        }

    }
    return -1;
}