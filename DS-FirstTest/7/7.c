#include <ctype.h>//https://goo.gl/D9krii
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int i, j, all = 0, n = 0;
  char stack[100][100], c, a[2000];
  freopen("7input.txt","r",stdin);
  fgets(a, 2000, stdin);
  for (i = strlen(a) - 1; i >= 0; i--) {
    if (isalpha(a[i])) {
      stack[all][0] = a[i];
      stack[all][1] = '\0';
      all++;
    } else if (a[i] == ' ') {
      continue;
    } else {
      strcat(stack[all - 1], stack[all - 2]);
      stack[all - 1][strlen(stack[all - 1])] = a[i];
      strcpy(stack[all - 2], stack[all - 1]);
      all--;
    }
  }
  printf("%s\n", stack[0]);
  for (i = 0; i < strlen(stack[0]); i++) {
    if (isalpha(stack[0][i])) {
      n++;
    } else
      n--;
    printf("%d ", n);
  }
  printf("\n");
  return 0;
}

