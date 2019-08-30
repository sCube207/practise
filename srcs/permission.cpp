#include "../includes/permissions.hpp"
#include "../includes/base.hpp"

void  Permission::add() { 
    tPermission *p;
    p_list      *list;
    char        desc[1000]; // array to read description and malloc memorry

    list = (p_list *)malloc(sizeof(p_list));
    p = (tPermission *)malloc(sizeof(tPermission));
    if (p != NULL) {
        printf("Enter the number of permission\n");
        scanf("%d", &p->num);
        printf("Enter the name of the permission\n");
        scanf("%s", p->name);
        printf("Enter the description of the permission\n");
        scanf("%s", desc);
        p->description = strdup(desc);
        list->p = p;
        list->next = head;
        head = list;
    }
}

void    Permission::show() {  
    p_list      *list;
    
    list = head;
    while (list != NULL) {
        printf("------------------------------------------------------------\n");
        printf("Number of permission - %d\n", list->p->num);
        printf("Name of the permission - %s\n", list->p->name);
        printf("Description of the permission - %s\n", list->p->description);
        printf("------------------------------------------------------------\n");
        list = list->next;
    }
}

void    Permission::preDel() {
    int     d;

    printf("Enter the number of permission to delete\n");
    scanf("%d", &d);

    head = del(head, d);
}

p_list    *Permission::del(p_list *list, int num) {
    p_list *p = NULL;

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

void    Permission::preChangeNum() {
    int    num;
    int     new_num;
    p_list *list;

    printf("Enter the number of permission to change\n");
    scanf("%d", &num);
    printf("Enter the new number of permission\n");
    scanf("%d", &new_num);

    changeNum(head, num, new_num);
}

void    Permission::changeNum(p_list *list, int num, int new_num) {
    if (list != NULL) {
        if (num == list->p->num) {
            list->p->num = new_num;
            return;
        }
        else
            changeNum(list->next, num, new_num);
    }
}


void    Permission::preChangeName() {
    char    name[100];
    char     new_name[100];
    p_list *list;

    printf("Enter the name of permission to change\n");
    scanf("%s", name);
    printf("Enter the new name of permission\n");
    scanf("%s", new_name);

    changeName(head, name, new_name);
}

void    Permission::changeName(p_list *list, char *name, char *new_name) {
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

p_list *Permission::findPermission(int num) {
    p_list *list;

    list = head;
    while (list != NULL) {
        if (list->p->num == num)
            return list;
        list = list->next;
    }
    return NULL;
}





