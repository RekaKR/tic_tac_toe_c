#include <stdio.h>
#include <stdlib.h>
#include "../common.h"
#include "../winner/winner.h"
#include "../board/board.h"
#include "moves.h"

void playerMove(Board* board) {
  int x, y;
  
  do {
    printf("Enter row #(1-%d): ", (*board).size);
    scanf("%d", &x);
    x--;

    printf("Enter column #(1-%d): ", (*board).size);
    scanf("%d", &y);
    y--;

    if ((*board).board[x][y] != ' ') {
      printf("Invalid move.\n");
    } else {
      (*board).board[x][y] = PLAYER;
      break;
    }
  } while ((*board).board[x][y] != ' ');
};

void computerMove(Board* board) {
  int x, y;

  if (checkFreeSpaces(board) > 0) {
    do {
      x = rand() % (*board).size;
      y = rand() % (*board).size;
    } while ((*board).board[x][y] != ' ');

    (*board).board[x][y] = COMPUTER;
  } else {
    printWinner(' ');
  }
};