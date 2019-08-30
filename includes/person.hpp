#ifndef PERSON_HPP
# define PERSON_HPP
#include "base.hpp"
typedef struct          sPerson {
    char                name[100];
    r_list              *role;
    struct sPerson      *next;
    
}                       tPerson;
class Person {
    private:
        sPerson         *head;
    public:
        tPerson         *add(r_list *role);
        void            preDel();
    Person() {
        head = NULL;
    } 
};
#endif
