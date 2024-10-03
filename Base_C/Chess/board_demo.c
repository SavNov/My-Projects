#include <ncurses.h>
#include <unistd.h>
#define LEFT_EDGE 10
#define TOP_EDGE 10
#define ENTER 10
char map(int key) {
  if (key == 0) {
    return ' ';
  } else if (key == 1) {
    return 'X';
  } else if (key == 2) {
    return 'O';
  } else {
    return '\0';
  }
}
struct Pos {
  int row;
  int col;
};
void show_board(struct Pos pos1) {
  noecho();
  cbreak();
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  int board[8][8] = {
    {1,2,1,2,1,2,1,2},
    {1,2,1,2,1,2,1,2},
    {1,2,1,2,1,2,1,2},
    {1,2,1,2,1,2,1,2},
    {1,2,1,2,1,2,1,2},
    {1,2,1,2,1,2,1,2},
    {1,2,1,2,1,2,1,2},
    {1,2,1,2,1,2,1,2},
  };
  for (int i = 0; i < 8; i++) {
    move(TOP_EDGE+0, LEFT_EDGE+i);
    for (int j = 0; j < 8; j++) {
      move(TOP_EDGE+j, LEFT_EDGE+i*2);
      if (i == pos1.col && j == pos1.row) {
        attron(COLOR_PAIR(1));
        printw("%c", map(board[j][i]));
        attroff(1);
      } else {
        attron(COLOR_PAIR(2));
        printw("%c", map(board[j][i]));
        attroff(COLOR_PAIR(2));
      }
    }
  }
}
int main (void) {
  initscr();
  struct Pos start_pos;
  start_pos.col = 0;
  start_pos.row = 0;
  show_board(start_pos);
  int key = getch();
  while (key != ENTER) {
    switch (key) {
      case 'j': 
        if (start_pos.row < 7) {start_pos.row++;}
        break;
      case 'k':
        if (start_pos.row > 0) {start_pos.row--;}
        break;
      case 'h':
        if (start_pos.col > 0) {start_pos.col--;}
        break;
      case 'l':
        if (start_pos.col < 7) {start_pos.col++;}
        break;
      default: 
        move(20,20);
        printw("Please use hjkl to navigate. If you'd like to quit, press <CR> (Enter).");
        refresh();
        move(0,0);
    }
    show_board(start_pos);
    refresh();
    key = getch();
    clear();
    refresh();
  }
  move(0,0);
  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  refresh();
  for (int x = 5; x > 0; x--) {
    clear();
    attron(COLOR_PAIR(2));
    printw("Quitting...");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(1));
    printw("%is", x);
    attroff(COLOR_PAIR(1));
    refresh();
    sleep(1);
  }
  endwin();
  return 0;
}
