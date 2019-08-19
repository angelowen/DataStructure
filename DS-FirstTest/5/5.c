#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct link {
  char mar[100];
  char date[100];
  int good;
  char place[100];
} node;
int main(int argc, char const *argv[]) {
  node market[100];
  int n, i, j, all = 0, len, max = 0, tai = 0, w = 0;
  char *token;
  char a[1000], max_mar[100], taichung[100][100], wed[100][100];
  freopen("5.txt", "r", stdin);
  while (fgets(a, 1000, stdin) != NULL) {
    a[strlen(a) - 1] = '\0';
    token = strtok(a, ",");
    strcpy(market[all].mar, token);

    token = strtok(NULL, ",");
    strcpy(market[all].date, token);
    token = strtok(NULL, ",");
    market[all].good = atoi(token);
    token = strtok(NULL, ",");
    strcpy(market[all].place, token);
//    printf("%s %s %d %s\n", market[all].mar, market[all].date, market[all].good,
//           market[all].place);
    all++;
  }
  for (i = 0; i < all; i++) {
    if (market[i].good > max) {
      max = market[i].good;
      strcpy(max_mar, market[i].mar);
    }
    if (strcmp("台中市", market[i].place) == 0) {
      strcpy(taichung[tai], market[i].mar);
      tai++;
    }
    if (strstr(market[i].date, "3") != NULL) {
      strcpy(wed[w], market[i].mar);
      w++;
    }
  }
//  printf("%d %d\n", tai, w);
  printf("評價最高的夜市：%s\n", max_mar);
  printf("星期三有開的夜市：");
  for (i = 0; i < w; i++) {
    printf("%s ", wed[i]);
  }
  printf("\n");
  printf("台中的夜市：");
  for (i = 0; i < tai; i++) {
    printf("%s ", taichung[i]);
  }
  printf("\n");

  return 0;
}
