#include <stdio.h>

void draw(int board[]) {
  char c;
  for(int i = 0;i< 9;i++) {
    switch (board[i]) {
      case 0:
        printf(" %d ",i);
        break;
      case 1:
        printf(" x ");
        break;
      case -1:
        printf(" o ");
        break;
    }
    if ((i+1) % 3 == 0) printf("\n---|---|---\n");
    else printf("|");
  }
}

int checkTriplets(int board[],int a, int b,int c) {
  return
    board[a] == board[b] && board[b] == board[c] && 
    board[a] == board[c] && board[a] != 0;
}

int includes(int arr[],int x) {
  for(int i = 0;i<9;i++) {
    if (arr[i] == x) return 1;
  }
  return 0;
}

int game(int board[]) {
  if (checkTriplets(board, 0, 4, 8)) return board[0];
  if (checkTriplets(board, 2, 4, 6)) return board[2];

  int n = 0;
  for (n = 0; n < 3; n++)
    if (checkTriplets(board, n, n + 3, n + 6)) return board[n];
  for (n = 0; n < 9; n = n + 3)
    if (checkTriplets(board, n, n + 1, n + 2)) return board[n];
  return includes(board,0) ? 0.5 : 0;
}

int main() {
  int board[] = {0,0,0, 0,0,0, 0,0,0};
  draw(board);
  int i,event,turn = 1;
  while(1) {
    printf("%c turn> ", turn > 0 ? 'x': 'o');
    scanf("%d",&i);
    if (i > 8 || board[i] != 0) {
      printf("invalid input.\n");
      continue;
    };

    board[i] = turn;
    event = game(board);
    if (event) {
      draw(board);
      if (event == 0.5) printf("draw\n");
      else printf("%c wins!\n", event > 0 ? 'x': 'o');
      break;
    }
    draw(board);
    turn *= -1;
  }
  return 0;
}
