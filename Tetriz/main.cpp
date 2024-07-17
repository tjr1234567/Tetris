#include "define.h"
#include "terminal.h"
#include "utils.h"
#include "display.h"
#include "control.h"
#include "game.h"

void init()
{
    TermCtrl::hide_cursor();
    gm::start_listener();
    gm::init();
}
void update()
{
    int row = 1, col = 0;
    while (gm::running) // check the quit signal
    {
        TermCtrl::clear();
        dp::window(1, 1, 9, 6, "HOLD");
        dp::window(1, 10, 12, 22, "TETRIZ");
        dp::window(1, 22, 8, 18, "NEXT");
        dp::window(7, 1, 9, 16, "status");
        dp::window(19, 22, 8, 4, "INFO");

        TermCtrl::move_to(14, 7);
        std::cout << "FPS:" << utils::fps();
        TermCtrl::move_to(gm::row, utils::b2c(gm::col)); // implement the block falling
        TermCtrl::back_col(White);                       // set the color of block
        std::cout << "  ";                               // print the block
        TermCtrl::reset_col();                           // reset the background color

        std::cout << std::flush;
        std::this_thread::sleep_for(100ms); // about 10 frames per second
    }
}
void exit()
{
    TermCtrl::show_cursor();
    TermCtrl::reset_col();
    TermCtrl::clear();
    TermCtrl::move_to(1, 1);
    TermCtrl::fore_col(Red);
    std::cout << "SCORE is " << "number" << std::endl
              << "BYE" << std::endl;
}
int main()
{
    init();
    update();
    exit();
    return 0;
}