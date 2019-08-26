#include "../includes/base.hpp"
#include "../includes/permissions.hpp"


int     main(int argc, char *argv[]) { 
    Permission p;

    p.add();
    p.add();
    p.add();
    p.preDel();
    p.preChangeNum();
    p.preChangeName();
    p.show();
}
