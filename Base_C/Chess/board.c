#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
typedef uint64_t Bitboard; // Represents entire chess board.
#define A1 0
#define A2 1
#define A3 2
#define A4 3
#define A5 4
#define A6 5
#define A7 6
#define A8 7
#define B1 8
#define B2 9
#define B3 10
#define B4 11
#define B5 12
#define B6 13
#define B7 14
#define B8 15
#define C1 16
#define C2 17
#define C3 18
#define C4 19
#define C5 20
#define C6 21
#define C7 22
#define C8 23
#define D1 24
#define D2 25
#define D3 26
#define D4 27
#define D5 28
#define D6 29
#define D7 30
#define D8 31
#define E1 32
#define E2 33
#define E3 34
#define E4 35
#define E5 36
#define E6 37
#define E7 38
#define E8 39
#define F1 40
#define F2 41
#define F3 42
#define F4 43
#define F5 44
#define F6 45
#define F7 46
#define F8 47
#define G1 48
#define G2 49
#define G3 50
#define G4 51
#define G5 52
#define G6 53
#define G7 54
#define G8 55
#define H1 56
#define H2 57
#define H3 58
#define H4 59
#define H5 60
#define H6 61
#define H7 62
#define H8 63

void print_binary(int n) {
  int i;
  for (i = 7; i >= 0; --i) {
    printf("%d", (n >> i & 1));
  }
  printf(" \n");
}
Bitboard empty_board = 1;
int main(void) {
  Bitboard empty = 0;
  Bitboard *ptr_empty = &empty;
}

