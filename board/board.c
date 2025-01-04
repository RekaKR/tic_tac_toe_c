#include <stdio.h>
#include <stdlib.h>
#include "../common.h"
#include "board.h"
#include "../moves/moves.h"

void initializeBoard(Board* board) {
  do {
    printf("Enter board size (e.g., 3 for 3x3, 4 for 4x4; min 3): ");
    scanf("%d", &(*board).size);

    if ((*board).size < 3) {
      printf("Invalid size. Please enter a size of at least 3.\n");
    }
  } while ((*board).size < 3);

  (*board).board = (char**)malloc((*board).size * sizeof(char *));
  for (int i = 0; i < (*board).size; i++) {
    (*board).board[i] = (char*)malloc((*board).size * sizeof(char));
  }
}

void resetBoard(Board* board) {
  for (int i = 0; i < (*board).size; i++) {
    for (int j = 0; j < (*board).size; j++) {
      (*board).board[i][j] = ' ';
    }
  }
}

void printBoard(Board* board) {
  for (int i = 0; i < (*board).size; i++) {
    printf("\n");
    
    for (int j = 0; j < (*board).size; j++) {
      printf("|  %c", (*board).board[i][j]);
    }

    printf("|\n");

    for (int j = 0; j < (*board).size; j++) {
      printf("-----");
    }
  }

  printf("\n");
};

int checkFreeSpaces(Board* board) {
  int freeSpaces = (*board).size * (*board).size;

  for (int i = 0; i < (*board).size; i++) {
    for (int j = 0; j < (*board).size; j++) {
      if ((*board).board[i][j] != ' ') {
        freeSpaces--;
      }
    }
  }

  return freeSpaces;
};