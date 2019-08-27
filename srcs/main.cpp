#include "../includes/permissions.hpp"
#include "../includes/base.hpp"
#include "../includes/role.hpp"


int     main(int argc, char *argv[]) { 
    Permission  p;
    Role        r;
/*
    p.add();
    p.add();
    p.add();
    p.preDel();
    p.preChangeNum();
    p.preChangeName();
    p.show();
*/
    r.add();
    r.add();
    r.add();
    r.preDel();
    r.preChangeNum();
    r.preChangeName();
    r.show();

}
