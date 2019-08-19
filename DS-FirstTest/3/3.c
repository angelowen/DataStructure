#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct link
{
    int num;
    struct link *next;
} link;
link *inverse(link *cur, int n)
{
    int i;
    link *ptr = cur->next, *tmp = ptr->next;
    cur->next = NULL;
    for (i = 0; i < n - 1; i++)
    {
        ptr->next = cur;
        cur = ptr;
        ptr = tmp;
        if (ptr == NULL)
            break;
        tmp = tmp->next;
    }
    return cur;
}
link *printdata(link *ptr)
{
    for (; ptr->next != NULL; ptr = ptr->next)
        printf("%d ", ptr->num);
    printf("%d\n", ptr->num);
    return ptr;
}
int main()
{
    freopen("3input.txt", "r", stdin);
    freopen("3output1.txt", "w", stdout);
    char line[10010], *str;
    int n = 1, i, option;
    link *first, *second, *third, *linklast, *pre, *ptr;
    first = malloc(sizeof(link));
    fgets(line, 10010, stdin);
    str = strtok(line, " \n");
    first->num = atoi(str);
    pre = first;
    str = strtok(NULL, " \n");
    while (str != NULL)
    {
        ptr = malloc(sizeof(link));
        ptr->num = atoi(str);
        pre->next = ptr;
        pre = ptr;
        str = strtok(NULL, " \n");
        n++;
    }
    pre->next = NULL;
    n /= 3;
    ptr = first;
    for (i = 0; i < n; i++)
        ptr = ptr->next;
    second = ptr;
    for (i = 0; i < n; i++)
        ptr = ptr->next;
    third = ptr;
    for (i = 0; i < n && ptr->next != NULL; i++)
        ptr = ptr->next;
    linklast = ptr;
    while (scanf("%d", &option) != EOF)
    {
        switch (option)
        {
        case 1:
            ptr = inverse(first, n);
            linklast->next = ptr;
            first = second;
            second = third;
            third = ptr;
            linklast = printdata(first);
            break;
        case 2:
            for (pre = first; pre->next != second; pre = pre->next);
            ptr = inverse(second, n);
            linklast->next = ptr;
            pre->next = third;
            second = third;
            third = ptr;
            linklast = printdata(first);
            break;
        case 3:
            for (pre = second; pre->next != third; pre = pre->next);
            ptr = inverse(third, n);
            pre->next = ptr;
            third = ptr;
            linklast = printdata(first);
            break;
        }
    }
    return 0;
}
