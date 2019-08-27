#ifndef PERMITIONS_HPP
# define PERMITIONS_HPP
#include "base.hpp"

typedef struct          sPermission {
    int                 num;
    char                name[100];
    char                *description; 
}                       tPermission;
typedef struct          per_list {
    tPermission         *p;
    struct per_list     *next;
}                       p_list;
class Permission {
    private:
        p_list          *head;
        p_list          *del(p_list *list, int num);
        void            changeName(p_list *list, char *name, char *new_name);
        void            changeNum(p_list *list, int num, int new_num);
        p_list          *findPermission(int num);
    public:
        void            add();
        void            preChangeNum();
        void            preChangeName();
        void            preDel();
        void            show();

        Permission() {
            head = NULL;
        } 
};
#endif
