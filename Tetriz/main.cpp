#include <iostream>
#include <thread>
#include "terminal.h"
using namespace std::chrono_literals;
int main()
{
    int row = 1, col = 0;

    TermCtrl::hide_cursor();
    while (true)
    {
        TermCtrl::clear();
        TermCtrl::move_to(row++, 10);
        TermCtrl::back_col(White);
        std::cout << "  ";
        TermCtrl::reset_col();
        std::cout << std::flush;
        std::this_thread::sleep_for(1s);
    }
    return 0;
}