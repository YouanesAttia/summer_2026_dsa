#include <ncurses.h>
using namespace std;

int main(int argc, char **argv)
{
    initscr();

    int height, width, start_y, start_x;
    height = 10;
    width = 20;
    start_x = start_y = 10;
    WINDOW *win = newwin(height, width, start_y, start_x);
    refresh();

    box(win, 0, 0);
    mvwprintw(win, 1, 1, "This is my box");
    wrefresh(win);

    getch();
    endwin();
}