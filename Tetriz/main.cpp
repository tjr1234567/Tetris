#include <iostream>
#include "terminal.h"
int main()
{
    TermCtrl::move_to(5, 10);
    TermCtrl::fore_col(214);
    std::cout << "Hello world" << std::endl;
    TermCtrl::move_to(10, 1);
    return 0;
}