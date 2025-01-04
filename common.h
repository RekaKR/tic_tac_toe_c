#ifndef COMMON_H
#define COMMON_H

#define PLAYER 'X'
#define COMPUTER 'O'

typedef struct Board {
  int size;
  char** board;
} Board;

#endif