#include <ncurses.h>

int main (void) {
  int board[3][3] = {
    {1,0,1},
    {0,0,0},
    {0,0,0},
  };
  initscr();
  int key = getch();
  printw("%i", key);
  getch();
  endwin();
  return 0;
}
