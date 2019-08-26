#ifndef BASE_H
# define BASE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sPermission {
    int num;
    char name[100];
    char *description;
} tPermission;

typedef struct sRole {
    int num;
    char name[100];
    char *description;
    tPermission *head;
} tRole;
#endif
