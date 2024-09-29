#ifndef backend_h
#define backend_h
#include "game.h"
void make_move(Game*, Pos, Pos);
void test_make_move(Game*, Pos, Pos);
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
#endif // backend_h
