#define PIECES_H
#define EMPTY 0
#define WHITE_PAWN 1
#define WHITE_KING 2
#define WHITE_ROOK 3
#define WHITE_BISHOP 4
#define WHITE_KNIGHT 5
#define WHITE_QUEEN 6
#define BLACK_PAWN 7
#define BLACK_KING 8
#define BLACK_ROOK 9
#define BLACK_BISHOP 10
#define BLACK_KNIGHT 11
#define BLACK_QUEEN 12

class Board {
  private:
    int turn = 0;
  public:
    int board[8][8] = {
    {BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP,BLACK_QUEEN,BLACK_KING,BLACK_BISHOP,BLACK_KNIGHT,BLACK_ROOK},
    {BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN},
    {WHITE_ROOK, WHITE_KNIGHT,WHITE_BISHOP ,WHITE_QUEEN ,WHITE_KING ,WHITE_BISHOP ,WHITE_KNIGHT ,WHITE_ROOK}
  };

  int movetest(int initrow, int initcol, int finalrow, int finalcol) {
    if (board[initrow][initcol] == EMPTY) {
      return 0;
    }
    int init = board[initrow][initcol];
    int final = board[finalrow][finalcol];
    int coldiff = (finalcol - initcol < 0) ? ((finalcol - initcol) * -1) : (finalcol - initcol);
    int rowdiff = (finalrow - initrow < 0) ? ((finalrow - initrow) * -1) : (finalrow - initrow);
    switch (turn) {
      case 0:
        if (final != 0 && final < 6) {
          return 0;
        } // Confirms that player is either going to empty square or square with black piece
        if (init > 6) {
          return 0;
        } // Confirms that the piece belongs to white
        switch (init) {
          case WHITE_PAWN:
            if (initrow == 1 && finalrow < 4 && finalrow != 0) {
              if (final > 6 && (coldiff == 1)) {
                return 1;
              }
              if (final == 0 && coldiff == 0) {
                return 1;
              }
              return 0;
            }
            if (initrow > 1 && rowdiff == 1 && finalrow != 0) {
              if (final > 0) {
                return 0;
              }
              return 1;
            }
            break;
          case WHITE_ROOK:
            if (rowdiff > 0 && coldiff == 0) {
              for  (int i = initrow; i < finalrow; i++) {
                if (board[i][initcol] != 0) {
                  return 0;
                }
              }
            }
            if (coldiff > 0 && rowdiff == 0) {
              for (int i = initcol; i < finalcol; i++) {
                if (board[initrow][i] != 0) {
                  return 0;
                }
              }
            }
            return 1;
          default:
            return 0;
        }
        break;
      case 1:
        if (final > 6) {
          return 0;
        }
        if (init < 7) {
          return 0;
        }
        switch (init) {
          case BLACK_PAWN:
            if (initrow == 6 && finalrow > 3 && finalrow != 0) {
              if (final > 0 && final < 7 && (coldiff == 1)) {
                return 1;
              }
              if (final == 0 && coldiff == 0) {
                return 1;
              }
              return 0;
            }
            if (initrow < 6 && rowdiff == 1 && finalrow != 7) {
              if (final > 0) {
                return 0;
              }
              return 1;
            }
            return 0;
        }
    }
  }
};

int main (void) {
  return 0;
}
