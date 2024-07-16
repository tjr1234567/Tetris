// Terminal Control
namespace TermCtrl
{
    void move_to(int row, int col); // move the cursor
    void fore_col(int id);          // set foreground color
    void back_col(int id);          // set background color
    void clear();                   // clear the screen
    void reset_col();               // reset the color
}