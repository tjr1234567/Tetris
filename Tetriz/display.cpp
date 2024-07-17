#include <iostream>
#include "display.h"
#include "terminal.h"
#include "utils.h"
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
    const std::u32string style1 = U" ┌┐└┘│─";
    const std::u32string style2 = U" ╔╗╚╝║═";
    const std::u32string style3 = U" ┏┓┗┛┃━";
    const std::u32string style4 = U" ╭╮╰╯┆╌";
    const std::u32string current_style = style4;

    void window(int top, int left, int width, int height, std::string title)
    {
        for (int r = 0; r < height; r++)
        {
            TermCtrl::move_to(top + r, utils::b2c(left));
            for (int c = 0; c < width; c++)
            {
                if (r == 0)
                {
                    if (c == 0)
                    {
                        std::cout << utils::utf32_2_utf8({current_style[0], current_style[1]}); //" ┌";
                    }
                    else if (c == width - 1)
                    {
                        std::cout << utils::utf32_2_utf8({current_style[2], current_style[0]}); //"┐ ";
                    }
                    else
                    {
                        std::cout << utils::utf32_2_utf8({current_style[6], current_style[6]}); //"──";
                    }
                }
                else if (r == height - 1)
                {
                    if (c == 0)
                    {
                        std::cout << utils::utf32_2_utf8({current_style[0], current_style[3]}); //" └";
                    }
                    else if (c == width - 1)
                    {
                        std::cout << utils::utf32_2_utf8({current_style[4], current_style[0]}); //"┘ ";
                    }
                    else
                    {
                        std::cout << utils::utf32_2_utf8({current_style[6], current_style[6]}); //"──";
                    }
                }
                else
                {
                    if (c == 0)
                    {
                        std::cout << utils::utf32_2_utf8({current_style[0], current_style[5]}); //" │";
                    }
                    else if (c == width - 1)
                    {
                        std::cout << utils::utf32_2_utf8({current_style[5], current_style[0]}); //"│";
                    }
                    else
                    {
                        std::cout << utils::utf32_2_utf8({current_style[0], current_style[0]}); //"  ";
                    }
                }
            }
        }
        TermCtrl::move_to(top, utils::b2c(left) + (width * 2 - title.length()) / 2);
        std::cout << title;
    }
}
