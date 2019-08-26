#include "../includes/roles.hpp"
#include "../includes/base.hpp"

void    Role::add() {
    r_list      *list;
    tRole       *p;
    char        *desc[1000];

    list = (r_list *)malloc(sizeof(r_list));
    p = (tRole *)malloc(sizeof(tRole));
    if (p == NULL || list == NULL) {
        printf("Enter the role number\n"); 
        scanf("%d", p->num);
        printf("Enter the role name\n");
        scanf("%s", name);
        printf("Enter the role description\n");
        scanf("%s", desc);
        p->description = strdup(desc);
        p->head = NULL;
        list->p = p;
        list->next = NULL;
        head = list;
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
            changeName(head, name, new_name);
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
            changeNum(head, num, new_num);
    }
    return;
}
