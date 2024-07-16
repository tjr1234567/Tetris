#include "utils.h"
#include <chrono>
using namespace std::chrono_literals;
int utils::fps()
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