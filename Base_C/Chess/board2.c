#include <stdio.h>
#include <stdlib.h>

typedef struct Game {
  int board[8][8];
  void (*make_move)(struct Game *ptr_Game);
} Game;

int main(int argc, char **argv) {
  if (argc > 1) {
    for (int i = 0; i < argc; i++) {
      printf("%s ", argv[i]);
    }
  }
  return 0;
}
