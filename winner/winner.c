#include <stdio.h>
#include "../common.h"
#include "winner.h"

char checkWinner(Board* board) {
  int win;

  for (int i = 0; i < (*board).size; i++) {
    // check rows
    win = 1;
    for (int j = 1; j < (*board).size; j++) {
      if ((*board).board[i][j] != (*board).board[i][j - 1]) {
        win = 0;
        break;
      }
    }

    if (win && (*board).board[i][0] != ' ') return (*board).board[i][0];

    // check columns
    for (int j = 1; j < (*board).size; j++) {
      if ((*board).board[j][i] != (*board).board[j-1][i]) {
        win = 0;
        break;
      }
    }
  
    if (win && (*board).board[0][i] != ' ') return (*board).board[0][i];
  }

  // check diagonals
  win = 1;
  for (int i = 1; i < (*board).size; i++) {
    if ((*board).board[i][i] != (*board).board[i-1][i-1]) {
      win = 0;
      break;
    }
  }

  if (win && (*board).board[0][0] != ' ') return (*board).board[0][0];

  win = 1;
  for (int i = 1; i < (*board).size; i++) {
    if ((*board).board[i][(*board).size-i-1] != (*board).board[i-1][(*board).size-i]) {
      win = 0;
      break;
    }
  }

  if (win && (*board).board[0][(*board).size-1] != ' ') return (*board).board[0][(*board).size-1];

  return ' ';
};

void printWinner(char winner) {
  if (winner == PLAYER) {
    printf("You win!\n");
  } else if (winner == COMPUTER) {
    printf("Computer wins!\n");
  } else {
    printf("It's a tie!\n");
  }
};