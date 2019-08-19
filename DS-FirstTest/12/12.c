#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 100
typedef struct aa
{
    int n;
    struct aa *next;
} node;

node *row[MAXNUM];
int passed[MAXNUM] = {0};
int printed[MAXNUM] = {0};
int arr[MAXNUM], cnt = 0;

int print(int i)
{
    node *cur;
    if (row[i] != NULL && passed[i] == 0)
    {
        cur = row[i];
        if (!printed[i])
        {
            // printf("%d ", i);
            arr[cnt] = i;
            cnt++;
        }
        printed[i] = 1;
        passed[i] = 1;
        while (cur)
        {
            if (!printed[cur->n])
            {
                printed[cur->n] = 1;
                // printf("%d ", cur->n);
                arr[cnt] = cur->n;
                cnt++;
            }

            print(cur->n);
            cur = cur->next;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
void link(int num1, int num2)
{
    node *tmp, *cur;
    tmp = malloc(sizeof(node));
    tmp->next = NULL;
    tmp->n = num2;
    if (row[num1] == NULL)
    {
        row[num1] = tmp;
    }
    else
    {
        cur = row[num1];
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = tmp;
    }
}
void sort(int cnt)
{
    int i, j, tmp;
    for (i = 0; i < cnt - 1; i++)
    {
        for (j = i; j < cnt; j++)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for (i = 0; i < cnt; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int i, j, num2, num1;

    node *tmp, *cur;
    while (scanf("%d %d ", &num1, &num2) != EOF)
    {
        link(num1, num2);
        link(num2, num1);
    }
    for (i = 0; i < MAXNUM; i++)
    {
        if (print(i))
        {
            sort(cnt);
            printf("\n");
        }
        cnt = 0;
    }

    return 0;
}
