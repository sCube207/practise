#include "../includes/role.hpp"
#include "../includes/permissions.hpp"
#include "../includes/base.hpp"

void    Role::add() {
    r_list      *list;
    tRole       *p;
    char        desc[1000];

    list = (r_list *)malloc(sizeof(r_list));
    p = (tRole *)malloc(sizeof(tRole));
    if (p != NULL && list != NULL) {
        printf("Enter the role number\n"); 
        scanf("%d", &p->num);
        printf("Enter the role name\n");
        scanf("%s", p->name);
        printf("Enter the role description\n");
        scanf("%s", desc);
        p->description = strdup(desc);
        p->head = NULL;
        list->p = p;
        list->next = NULL;
        head = list;
    }
}

void   Role::show() { 
    r_list      *list;
    p_list      *perm;

    list = head;
    perm = list->p->head;
    while (list != NULL) {
        printf("------------------------------------------------------------\n");
        printf("Number of role - %d\n", list->p->num);
        printf("Name of the role - %s\n", list->p->name);
        printf("Description of the role - %s\n", list->p->description);
        printf("Permissions of the role:\n");
        while (perm != NULL) {
            printf("%d - %s\n", perm->p->num, perm->p->name);
            perm = perm->next;
        }
        printf("------------------------------------------------------------\n");
        list = list->next;
    }
}

void    Role::preChangeName() {  
    char    name[100];
    char    new_name[100];

    printf("Enter the role name to change\n");
    scanf("%s", name);
    printf("Enter the role new name\n");
    scanf("%s", new_name);
    changeName(head, name, new_name);
}

void    Role::changeName(r_list *list, char *name, char *new_name) {
    if (list != NULL) {
        if (strcmp(name, list->p->name) == 0) {
            strcpy(list->p->name, new_name);
            return;
        }
        else
            changeName(list->next, name, new_name);
    }
    return;
}

void    Role::preChangeNum() {  
    int     num;
    int     new_num;

    printf("Enter the role num to change\n");
    scanf("%d", &num);
    printf("Enter the role new num\n");
    scanf("%d", &new_num);
    changeNum(head, num, new_num);
}

void    Role::changeNum(r_list *list, int num, int new_num) {
    if (list != NULL) {
        if (num == list->p->num)
            list->p->num = new_num;
            return;
        }
        else
            changeNum(list->next, num, new_num);
}

void    Role::preDel() {
    int     num;

    printf("Enter the role num to delete\n");
    scanf("%d", &num);
    head = del(head, num);
}

r_list *Role::del(r_list *list, int num) {
    r_list *p = NULL;

    if (list != NULL) {
        if (num == list->p->num) {
            p = list->next;
            free(list);
            return p;
        }
        list->next = del(list->next, num);
        return list;
    }
    return NULL;
}

r_list  *Role::findRole(int num) { 
    r_list *list;

    list = head;
    while (list != NULL) {
        if (num == list->p->num)
            return list;
        else
            list = list->next;
    }
    return NULL;
}








