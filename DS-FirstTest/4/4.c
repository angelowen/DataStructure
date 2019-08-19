#include <stdio.h>  //DONE
#include <stdlib.h>
#include <string.h>
typedef struct link {
  int num;
  struct link *r;
  struct link *l;
} node;
int all = 0;
int main(int argc, char const *argv[]) {
  char a[100];
  int i, j, n;
  node *first, *tmp, *pre;
  freopen("4input.txt","r",stdin);
  while (scanf("%s", a) != EOF) {
    if (strcmp(a, "Push") == 0) {
      scanf("%d", &n);
      tmp = malloc(sizeof(node));
      tmp->num = n;
      tmp->r = NULL;
      if (all == 0) {
        first = tmp;
        first->l = NULL;
      } else {
        pre->r = tmp;
        tmp->l = pre;
      }
      all++;
      pre = tmp;
    } else {
      tmp->l->r = NULL;
      tmp = tmp->l;
      pre = tmp;
      all--;
    }
  }
  printf("%d\n", all);
  while (first) {
    printf("%d ", first->num);
    first = first->r;
  }
  printf("\n");
  return 0;
}
