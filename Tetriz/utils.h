#pragma once
#include <string>
namespace utils
{
    int fps();
    std::string utf32_2_utf8(std::u32string str);
    inline int b2c(int block)
    {
        return 2 * block - 1;
    }
}