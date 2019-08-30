#ifndef ROLE_HPP
# define ROLE_HPP
#include "base.hpp"
#include "permissions.hpp"

typedef struct          sRole {
    int                 num;
    char                name[100];
    char                *description;
    p_list              *head;
}                       tRole;
typedef struct          role_list {
    tRole               *p;
    struct role_list    *next;
}                       r_list;
class Role {
    private:
        r_list          *del(r_list *list, int num);
        void            changeName(r_list *list, char *name, char *new_name);
        void            changeNum(r_list *list, int num, int new_num);
        r_list          *findRole(int num);
    public:
        r_list          *head;
        void            add();
        void            preChangeNum();
        void            preChangeName();
        void            find(p_list *list, int num);
        void            preDel();
        void            show();

        Role() {
            head = NULL;
        } 
};
#endif
