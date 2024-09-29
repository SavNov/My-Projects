#ifndef game_h
#define game_h

typedef struct Game {
  int board[8][8];
  void (*make_move)(struct Game *ptr_Game);
  int move;
  int player;
} Game;
typedef struct Pos {
  int row;
  int col;
} Pos;
#endif // !game.h
