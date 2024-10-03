#include <stdio.h>
#include "game.h"
#include "frontend.h"

Game* init_game(void) {
  Game game;
  game.move = 0;
  game.player = 0;
  Game* ptr_game = &game;
  return ptr_game;
}
int main(int argc, char **argv) {
  if (argc > 1) {
    for (int i = 0; i < argc; i++) {
      printf("%s ", argv[i]);
    }
  }
  Game* game = init_game();
  nav_board(game);
  return 0;
}
