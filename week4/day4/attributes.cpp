#include <ncurses.h>
using namespace std;

int main(int argc, char **argv)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    start_color();

    if (!has_colors())
    {
        printw("Terminal doesn't support color");
        getch();
        return -1;
    }
    start_color();

    /*
     * COLOR_PAIR(n)
     * COLOR_BLACK    0
     * COLOR_RED      1
     * COLOR_GREEN    2
     * COLOR_YELLOW   3
     * COLOR_BLUE     4
     * COLOR_MAGENTA  5
     * COLOR_CYAN     6
     * COLOR_WHITE    7
     */

    // init_pair(pair_number, foreground, background);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);

    if (can_change_color())
    {
        printw("can change color");
        // init_color(color, red, green, blue);
        init_color(COLOR_RED, 1000, 0, 0);
    }

    /*
     * A_NORMAL
     * A_STANDOUT
     * A_REVERSE
     * A_BLINK
     * A_DIM
     * A_BOLD
     * A_PROTECT
     * A_INVIS
     * A_ALTCHARSET
     * A_CHARTEXT
     */

    attron(COLOR_PAIR(1));
    printw("Red text");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(3));
    printw("White on blue");
    attroff(COLOR_PAIR(3));

    getch();
    endwin();
}