#include "frontend.h"
#include "backend.h"
#include "pieces.h"
#include <ncurses.h>
char map (int a) {
  switch (a) {
    case EMPTY:
    return ' ';
    case WHITE_PAWN:
    return 'p';
    case WHITE_KING:
    return 'k';
    case WHITE_ROOK:
    return 'r';
    case WHITE_BISHOP:
    return 'b';
    case WHITE_KNIGHT:
    return 'n';
    case WHITE_QUEEN:
    return 'q';
    case BLACK_PAWN:
    return 'P';
    case BLACK_KING:
    return 'K';
    case BLACK_ROOK:
    return 'R';
    case BLACK_BISHOP:
    return 'B';
    case BLACK_KNIGHT:
    return 'N';
    case BLACK_QUEEN:
    return 'Q';
    default:
    return 'X';
  }
}
void display_board(Game* ptr_Game, Pos starting_pos, Pos ending_pos, Pos player_pos) {
  initscr();
  #define TOP 10
  #define LEFT 10

  init_pair(0, COLOR_BLUE, COLOR_BLACK);
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      move(TOP+row, LEFT+col*2);
      if (starting_pos.col == col && starting_pos.row == row) {
        attron(COLOR_PAIR(1));
        printw("%c", map(ptr_Game->board[row][col]));
        attroff(COLOR_PAIR(1));
      } else if (ending_pos.col == col && ending_pos.row == row) {
        attron(COLOR_PAIR(2));
        printw("%c", map(ptr_Game->board[row][col]));
        attroff(COLOR_PAIR(2));
      } else if (player_pos.col == col && player_pos.row == row) {
        attron(COLOR_PAIR(0));
        printw("%c", map(ptr_Game->board[row][col]));
        attroff(COLOR_PAIR(0));
      } else {
        printw("%c", map(ptr_Game->board[row][col]));
      }
    }
  }
  endwin();
}
void nav_board(Game* ptr_Game) {
  Pos player_pos;
  Pos ending_pos;
  ending_pos.row = -1;
  ending_pos.col = -1;
  Pos starting_pos;
  starting_pos.row = -1;
  starting_pos.col = -1;
  /*Off to implement checkmate before I forget.
   */
  /*Realized I have no idea how that is going to work.*/
  int key = getch();
  while (key != ENTER) {
    switch (key) {
      case 'j': 
        player_pos.row = player_pos.row++;
        break;
      case 'k':
        player_pos.row = player_pos.row--;
        break;
      case 'h':
        player_pos.col = player_pos.col--;
        break;
      case 'l':
        player_pos.col = player_pos.col++;
        break;
      default:
        move(12,12);
        printw("Please use hjkl to move.");
        move(0,0);
        break;
    }
    display_board(ptr_Game, starting_pos, ending_pos, player_pos);
  }

  key = getch();
  while (key != ENTER) {
    switch (key) {
      case 'j': 
        player_pos.row = player_pos.row++;
        break;
      case 'k':
        player_pos.row = player_pos.row--;
        break;
      case 'h':
        player_pos.col = player_pos.col--;
        break;
      case 'l':
        player_pos.col = player_pos.col++;
        break;
      default:
        move(12,12);
        printw("Please use hjkl to move.");
        move(0,0);
        break;
    }
    display_board(ptr_Game, starting_pos, ending_pos, player_pos);
  } 
  ending_pos = player_pos;
  while (key != ENTER) {
    switch (key) {
      case 'j': 
        player_pos.row = player_pos.row++;
        break;
      case 'k':
        player_pos.row = player_pos.row--;
        break;
      case 'h':
        player_pos.col = player_pos.col--;
        break;
      case 'l':
        player_pos.col = player_pos.col++;
        break;
      default:
        move(12,12);
        printw("Please use hjkl to move.");
        move(0,0);
        break;
    }
    display_board(ptr_Game, starting_pos, ending_pos, player_pos);
  } 
  endwin();
}  
