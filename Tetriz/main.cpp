#include <iostream>
#include <thread>
#include "terminal.h"
#include "utils.h"
using namespace std::chrono_literals;

void init()
{
    TermCtrl::hide_cursor();
}
void update()
{
    int row = 1, col = 0;
    while (true)
    {

        TermCtrl::clear();
        TermCtrl::move_to(0, 0);
        std::cout << "FPS:" << utils::fps();
        TermCtrl::move_to(row++ % 25, 10);
        TermCtrl::back_col(White);
        std::cout << "  ";
        TermCtrl::reset_col();
        std::cout << std::flush;
        std::this_thread::sleep_for(100ms); // about 10 frames per second
    }
}
void exit()
{
    TermCtrl::show_cursor();
    TermCtrl::reset_col();
}
int main()
{
    init();
    update();
    exit();
    return 0;
}