#ifndef backend_h
#define backend_h
#include "game.h"
int make_move(Game*, Pos, Pos);
int test_make_move(Game*, Pos, Pos);
int is_valid(Game*, Pos, Pos);
int is_check(Game*, Pos);
int is_vert_check(Game*, Pos);
int is_hor_check(Game*, Pos);
int is_diag_check(Game*, Pos);
int make_bishop_move(Game*, Pos, Pos);
int make_rook_move(Game*, Pos, Pos);
int make_knight_move(Game*, Pos, Pos);
int make_queen_move(Game*, Pos, Pos);
int make_pawn_move(Game*, Pos, Pos);
int make_king_move(Game*, Pos, Pos);
int is_horse(int h, int v);
#define WHITE_KING 2
#define WHITE_PAWN 1
#define BLACK_KING 8
#define BLACK_PAWN 7
#endif // backend_h
