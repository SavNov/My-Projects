EMPTY = 0
WHITE_PAWN = 1
WHITE_KING = 2
WHITE_ROOK = 3
WHITE_BISHOP = 4
WHITE_KNIGHT = 5
WHITE_QUEEN = 6
BLACK_PAWN = 7
BLACK_KING = 8
BLACK_ROOK = 9
BLACK_BISHOP = 10
BLACK_KNIGHT = 11
BLACK_QUEEN = 12

class Board:
    turn = 0
    board[8][8] = {
    {BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP,BLACK_QUEEN,BLACK_KING,BLACK_BISHOP,BLACK_KNIGHT,BLACK_ROOK},
    {BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN},
    {WHITE_ROOK, WHITE_KNIGHT,WHITE_BISHOP ,WHITE_QUEEN ,WHITE_KING ,WHITE_BISHOP ,WHITE_KNIGHT ,WHITE_ROOK}
    } 


  int movetest(int initrow, initcol, finalrow, finalcol)    if board[initrow][initcol] == EMPTY:      return 0

    init = board[initrow][initcol]
    final = board[finalrow][finalcol]
    coldiff = (finalcol - initcol < 0) ? ((finalcol - initcol) * -1) : (finalcol - initcol)
    rowdiff = (finalrow - initrow < 0) ? ((finalrow - initrow) * -1) : (finalrow - initrow)
    switch (turn)      case 0:
        if final != 0 and final < 6:          return 0
        } # Confirms that player is either going to empty square or square with black piece
        if init > 6:          return 0
        } # Confirms that the piece belongs to white
        switch (init)          case WHITE_PAWN:
            if initrow == 1 and finalrow < 4 and finalrow != 0:              if final > 6 and (coldiff == 1):                return 1

              if final == 0 and coldiff == 0:                return 1

              return 0

            if initrow > 1 and rowdiff == 1 and finalrow != 0:              if final > 0:                return 0

              return 1

            break
          case WHITE_ROOK:
            if rowdiff > 0 and coldiff == 0:              for  (i = initrow; i < finalrow; i++)                if board[i][initcol] != 0:                  return 0



            if coldiff > 0 and rowdiff == 0:              for (i = initcol; i < finalcol; i++)                if board[initrow][i] != 0:                  return 0



            return 1
          default:
            return 0

        break
      case 1:
        if final > 6:          return 0

        if init < 7:          return 0

        switch (init)          case BLACK_PAWN:
            if initrow == 6 and finalrow > 3 and finalrow != 0:              if final > 0 and final < 7 and (coldiff == 1):                return 1

              if final == 0 and coldiff == 0:                return 1

              return 0

            if initrow < 6 and rowdiff == 1 and finalrow != 7:              if final > 0:                return 0

              return 1

            return 0





int main (void)  return 0

