#include "utils.h"
#include "define.h"
namespace utils
{
    int fps()
    {
        static auto start = std::chrono::steady_clock::now();
        auto end = start;
        static int FrameCount = 0;
        static int fps = 0;
        end = std::chrono::steady_clock::now();
        FrameCount++;
        if (end - start > 1s)
        {
            fps = FrameCount;
            FrameCount = 0;
            start = end;
        }
        return fps;
    }
    std::string utf32_2_utf8(std::u32string str)
    {
        static std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
        return convert.to_bytes(str);
    }
}
