#include "../includes/base.hpp"
#include "../includes/role.hpp"
#include "../includes/permissions.hpp"
#include "../includes/person.hpp"

tPerson    *Person::add(r_list *role) {
    tPerson *p;
    int     num;

    p = (tPerson *)malloc(sizeof(tPerson));
    role = NULL;
    if (p != NULL) {
        printf("Enter person name\n");
        scanf("%s", p->name);
        printf("Enter person role number\n");
        scanf("%d", &num);
        p->role = role;
        while (p->role != NULL) {
            if (p->role->p->num == num)
                break;
            p->role = p->role->next;
        }
    }
    return p;
}
