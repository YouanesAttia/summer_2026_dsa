#include <ncurses.h>

int main(int argc, char **argv)
{
    // Initializes the screen and sets up the memory
    initscr();

    // Prints a string to the window
    printw("Hello World!");

    // Refresh the screen to match whats in memory
    refresh();

    // Whats for suer input, returns int value of the key
    int c = getch();
    printw("%d", c);
    refresh();
    getch();

    // Deallocate the memory and ends ncurses
    endwin();
}