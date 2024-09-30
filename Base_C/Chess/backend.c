#include "backend.h"
#include "game.h"
#define VERT 1 
#define HOR 0
#define DIA 2 
#define L_SHAPE 3
#define is ==
#define and &&
int abs(int a) {
  if (a < 0) {
    a *= -1;
  } else {
    return a;
  }
}
int is_horse(int h, int v) {
  int abs_h = abs(h);
  int abs_v = abs(v);
  if (abs_h is 2 && abs_v is 1) {
    return 1;
  } else if (abs_h is 1 && abs_v is 2) {
    return 1;
  } else {
    return 0;
  }
}
int test_make_move(Game* ptr_Game, Pos pos1, Pos pos2) {
  int v = pos2.col-pos1.col;
  int h = pos2.row-pos1.row;
  int move_type;
  if (v == h) {
    move_type = DIA; 
  } else if (v != 0 && h == 0) {
    move_type = VERT;
  } else if (v == 0 && h != 0) {
    move_type = HOR;
  } else if (is_horse(h,v) == 1) {
    move_type = L_SHAPE;
  } 
}
int make_move(Game* ptr_Game, Pos pos1, Pos pos2) {
  Game* game_copy = ptr_Game;
  /*Where the hell is the king?
   */
  Pos king_pos;
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if (ptr_Game->board[row][col] == WHITE_KING && ptr_Game->player == 0) {
        king_pos.col = col;
        king_pos.row = row;
      }
      else if (ptr_Game->board[row][col] == BLACK_KING && ptr_Game->player == 1) {
        king_pos.col = col;
        king_pos.row = row;
      }
    }
  }
  /*Ah. There's the king.*/

  test_make_move(game_copy, pos1, pos2);

  if (is_check(game_copy, king_pos)) {
    return 2; 
  } else {
    return 0;
  }
}
