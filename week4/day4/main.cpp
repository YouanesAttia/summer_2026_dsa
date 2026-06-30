#include <ncurses.h>

int main(int argc, char **argv)
{
    // Initializes the screen and sets up the memory
    initscr();

    int x, y;
    x = y = 10;
    // Moves the cursor to the specified location, move(y, x)
    move(y, x);

    // Prints a string to the window
    printw("Hello World!");

    // Refresh the screen to match whats in memory
    refresh();

    // Whats for suer input, returns int value of the key
    int c = getch();
    mvprintw(0, 0, "%d", c);
    refresh();
    getch();

    // Deallocate the memory and ends ncurses
    endwin();
}