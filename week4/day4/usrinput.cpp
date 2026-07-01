#include <ncurses.h>
#include <cstring>
using namespace std;

int main(int argc, char **argv)
{
    initscr();
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *win = newwin(3, xMax - 12, yMax - 5, 5);
    box(win, 0, 0);
    refresh();
    wrefresh(win);

    int c = wgetch(win);
    if (c == 'j')
    {
        mcwprintw(win, 1, 1, "You pressed j!");
        wrefresh(win);
    }

    getch();
    endwin();

    return 0;
}