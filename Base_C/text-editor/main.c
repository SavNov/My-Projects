#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

void end(void) {
  clrtobot();
  sleep(1);
  endwin();
}
int main(void) {
  initscr();

  move(5, 10);
  printw("Welcome to my text editor!\n");
  refresh();
  sleep(3);

  move(10, 10);
  printw("This was written in Ncurses!\n");
  refresh();

  move(0,0);
  printw("Press q to exit: Pressing anything else will begin the program.");
  refresh();
  char user = getch();
  if (user == 'q') {
    end();
    return 0;
  }
  getch();
  endwin();

  return 0;
}
