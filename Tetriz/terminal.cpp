#include "terminal.h"
#include <iostream>
#define CSI "\033["
void TermCtrl::move_to(int row, int col)
{
    std::cout << CSI << row << ";" << col << "H";
}
void TermCtrl::fore_col(int id)
{
    std::cout << CSI << "38;5;" << id << "m";
}
void TermCtrl::back_col(int id)
{
    std::cout << CSI << "48;5;" << id << "m";
}
void TermCtrl::clear()
{
    std::cout << CSI << "2J";
}
void TermCtrl::reset_col()
{
    std::cout << CSI << "0m";
}