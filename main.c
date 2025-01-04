#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "common.h"
#include "./moves/moves.h"
#include "./board/board.h"
#include "./winner/winner.h"

void startGame(Board* board) {
  char winner = ' ';
  char response;

  do {
    winner = ' ';
    response = ' ';

    resetBoard(board);

    while (winner == ' ' && checkFreeSpaces(board) != 0) {
      printBoard(board);
      playerMove(board);

      winner = checkWinner(board);

      if (winner != ' ' || checkFreeSpaces(board) == 0) {
        break;
      }

      computerMove(board);
      winner = checkWinner(board);

      if (winner != ' ' || checkFreeSpaces(board) == 0) {
        break;
      }
    }

    printBoard(board);
    printWinner(winner);

    printf("Would you like to play again? (Y/N): ");
    scanf(" %c", &response);
    response = toupper(response);
  } while (response == 'Y');
}

int main() {
  srand(time(0));
  
  Board board;
  
  initializeBoard(&board);
  startGame(&board);

  for (int i = 0; i < board.size; i++) {
    free(board.board[i]);
  }

  free(board.board);

  printf("Thanks for playing!\n");

  return 0;
}