#include <ncurses.h>
using namespace std;

int main(int argc, char **argv)
{
    initscr();
    // cbreak(); //ctrl + c will exit you out
    // raw(); //doesn't exit you but prints the char
    // noeche(); //similar to raw but it doesn't print
    int height, width, start_y, start_x;
    height = 10;
    width = 20;
    start_x = start_y = 10;
    WINDOW *win = newwin(height, width, start_y, start_x);
    refresh();

    char c = 'g';
    box(win, (int)c, 104);
    // wborder(win, left, right, top, bottom, tlc, trc, blc, brc)
    mvwprintw(win, 1, 1, "This is my box");
    wrefresh(win);

    getch();
    getch();
    endwin();
}