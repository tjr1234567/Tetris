#include <iostream>
#include "display.h"
#include "terminal.h"
/*
 *      0 1 2 3 4 5 6 7 8 9 A B C D E F
U+250x  ─ ━ │ ┃ ┄ ┅ ┆ ┇ ┈ ┉ ┊ ┋ ┌ ┍ ┎ ┏
U+251x  ┐ ┑ ┒ ┓ └ ┕ ┖ ┗ ┘ ┙ ┚ ┛ ├ ┝ ┞ ┟
U+252x  ┠ ┡ ┢ ┣ ┤ ┥ ┦ ┧ ┨ ┩ ┪ ┫ ┬ ┭ ┮ ┯
U+253x  ┰ ┱ ┲ ┳ ┴ ┵ ┶ ┷ ┸ ┹ ┺ ┻ ┼ ┽ ┾ ┿
U+254x  ╀ ╁ ╂ ╃ ╄ ╅ ╆ ╇ ╈ ╉ ╊ ╋ ╌ ╍ ╎ ╏
U+255x  ═ ║ ╒ ╓ ╔ ╕ ╖ ╗ ╘ ╙ ╚ ╛ ╜ ╝ ╞ ╟
U+256x  ╠ ╡ ╢ ╣ ╤ ╥ ╦ ╧ ╨ ╩ ╪ ╫ ╬ ╭ ╮ ╯
U+257x  ╰ ╱ ╲ ╳ ╴ ╵ ╶ ╷ ╸ ╹ ╺ ╻ ╼ ╽ ╾ ╿
*/
namespace dp
{
    inline int block2col(int block)
    {
        return 2 * block - 1;
    }
    void window(int top, int left, int width, int height, std::string title)
    {
        for (int r = 0; r < height; r++)
        {
            TermCtrl::move_to(top + r, block2col(left));
            for (int c = 0; c < width; c++)
            {
                if (r == 0)
                {
                    if (c == 0)
                    {
                        std::cout << " ┌";
                    }
                    else if (c == width - 1)
                    {
                        std::cout << "┐ ";
                    }
                    else
                    {
                        std::cout << "──";
                    }
                }
                else if (r == height - 1)
                {
                    if (c == 0)
                    {
                        std::cout << " └";
                    }
                    else if (c == width - 1)
                    {
                        std::cout << "┘ ";
                    }
                    else
                    {
                        std::cout << "──";
                    }
                }
                else
                {
                    if (c == 0)
                    {
                        std::cout << " │";
                    }
                    else if (c == width - 1)
                    {
                        std::cout << "│";
                    }
                    else
                    {
                        std::cout << "  ";
                    }
                }
            }
        }
        TermCtrl::move_to(top, block2col(left) + (width * 2 - title.length()) / 2);
        std::cout << title;
    }
}
