#include <stdio.h>
#include <stdlib.h>

void hanoi(int, char, char, char);

int time = 0;

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%d\n",(1<<n)-1);
    hanoi(n, 'A', 'B', 'C');

}

void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        printf("Move sheet from %c to %c\n", A, C);
    }
    else
    {
        hanoi(n - 1, A, C, B);
        printf("Move sheet from %c to %c\n", A, C);
        hanoi(n - 1, B, A, C);
    }
}
