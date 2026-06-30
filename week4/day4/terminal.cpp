#include <ncurses.h>
#include <cstring>

int main(int argc, char **argv)
{
    initscr();
    noecho();
    cbreak();

    int y, x, yBeg, xBeg, yMax, xMax;
    getyx(stdscr, y, x);
    getbegyx(stdscr, yBeg, xBeg);
    getmaxyx(stdscr, yMax, xMax);

    mvprintw(yMax / 2, xMax / 2, "Hello");

    getch();
    endwin();

    return 0;
}