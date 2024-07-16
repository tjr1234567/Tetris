#include <iostream>
#include <thread>
#include "terminal.h"
#include "utils.h"
#include "display.h"
using namespace std::chrono_literals;

void init()
{
    TermCtrl::clear();
    TermCtrl::hide_cursor();
    dp::window(1, 1, 9, 6, "HOLD");
    dp::window(1, 10, 12, 22, "TETRIZ");
    dp::window(1, 22, 8, 18, "NEXT");
    dp::window(7, 1, 9, 16, "status");
    dp::window(19, 22, 8, 4, "INFO");
}
void update()
{
    int row = 1, col = 0;
    while (true)
    {

        TermCtrl::move_to(14, 7);
        std::cout << "FPS:" << utils::fps();
        // TermCtrl::move_to(row++ % 25, 10);
        TermCtrl::move_to(5, 10);
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