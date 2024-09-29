#include <stdio.h>
#include "backend.h"
#include "game.h"
#include <stdlib.h>

void make_move(Game *ptr_Game, Pos pos1, Pos pos2) {
  Game game_copy = *ptr_Game;
  /* Assuming that move is valid, logic will need to be implemented later.
    Will verify that move does not put player's king into check.
    King's check function, or rather the legal move function it will call, instead of simply checking which piece is on the initial square, will need to be notified of the piece, the initial position, and the final position. Instead of making the move, it'll need to simply report whether the move is legal or not. 
    It will iterate over every piece type, seeing if it could capture a select piece from its position. If there's nothing there, then it won't count as a check. If there is something there, checking if the piece is of the same type as the king is claiming to be, if it can be captured then the king will be considered in check.
   */
  game_copy.test_make_move(&game_copy, pos1, pos2);
}

int main(int argc, char **argv) {
  if (argc > 1) {
    for (int i = 0; i < argc; i++) {
      printf("%s ", argv[i]);
    }
  }
  return 0;
}
