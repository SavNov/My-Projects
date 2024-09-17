#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void) {
  srand(time(NULL));

  int num = rand() % 200 + 1;
  int guess;
  int * userguess = &guess;
  scanf("%i", userguess);
  while (num != guess) {
    if (num < guess) {
      printf("Your guess, %i, was too high!\n", guess);
      scanf("%i", userguess);
    }
    else {
      printf("Your guess, %i, was too low!\n", guess);
      scanf("%i", userguess);
    }
  }
  printf("Your guess, %i, was correct!", guess);
}
