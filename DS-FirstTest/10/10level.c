#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct bst
{
    int num;
    struct bst *parent;
    struct bst *right;
    struct bst *left;
} bst;
typedef struct que
{
    bst *ptr;
    struct que *next;
} que;
que *first = NULL, *last;
bst *insert(bst *root, int n)
{
    bst *new = malloc(sizeof(bst)), *ptr = root;
    new->num = n;
    new->right = NULL;
    new->left = NULL;
    if(root == NULL)
    {
        new->parent == NULL;
        return new;
    }
    while(1)
    {
        if(n > ptr->num && ptr->right != NULL)
            ptr = ptr->right;
        else if(n < ptr->num && ptr->left != NULL)
            ptr = ptr->left;
        else if(n > ptr->num && ptr->right == NULL)
        {
            ptr->right = new;
            new->parent = ptr;
            break;
        }
        else if(n < ptr->num && ptr->left == NULL)
        {
            ptr->left = new;
            new->parent = ptr;
            break;
        }
    }
    return root;
}
bst *Successor(bst *current)
{
    while (current->left != NULL)
        current = current->left;
    return current;
}
bst *delete(bst *root, int n)
{
    bst *ptr = root;
    while(ptr != NULL)
    {
        if(ptr->num == n)
            break;
        else if(n > ptr->num)
            ptr = ptr->right;
        else if(n < ptr->num)
            ptr = ptr->left;
    }
    bst *y = 0;      // �u���n�Q�R��������O���骺node
    bst *x = 0;      // �n�Q�R����node��"child"
    if (ptr->left == NULL || ptr->right == NULL)
        y = ptr;
    else
        y = Successor(ptr);
    if (y->left != NULL)
        x = y->left; // �Nx�]��y��child, �i��O���İO����,�]���i��ONULL
    else
        x = y->right;
    if (x != NULL)
        x->parent = y->parent;
    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    if (y != ptr)
        ptr->num = y->num;
    free(y);
    return root;
}
void que_push(bst *ptr)
{
    que *new = malloc(sizeof(que));
    new->ptr = ptr;
    new->next = NULL;
    if(first == NULL)
    {
        first = new;
        last = new;
        return;
    }
    last->next = new;
    last = new;
}
que *que_pop()
{
    que *ptr = first;
    first = first->next;
    return ptr->ptr;
}
int que_empty()
{
    return first == NULL ? 1 : 0;
}
void levelorder(bst *root)
{
    que_push(root);                         // ��root�@��level-order traversal���_�I�A���iqueue��
    while (!que_empty())                    // �Yqueue���O�Ū�, ����٦�node�S��visiting
    {
        bst *cur = que_pop();           // ���X���i�Jqueue��node
        printf(" %d", cur->num);   // �i��visiting
        if (cur->left != NULL)     // �Yleftchild�����, �N����iqueue
            que_push(cur->left);
        if (cur->right != NULL)    // �Yrightchild�����, �N����iqueue
            que_push(cur->right);
    }
    printf("\n");
}
int main()
{
    bst *root = NULL;
    char line[100010], *str;
    int n;
    freopen("10input.txt", "r", stdin);
    freopen("10output1.txt", "w", stdout);
    fgets(line, 100010, stdin);
    str = strtok(line, " \n");
    while(str != NULL)
    {
        n = atoi(str);
        root = insert(root, n);
        str = strtok(NULL, " \n");
    }
    while(fgets(line, 100010, stdin) != NULL)
    {
        if(strstr(line, "insert") != NULL)
        {
            n = atoi(line + 7);
            root = insert(root, n);
        }
        else if(strstr(line, "delete") != NULL)
        {
            n = atoi(line + 7);
            root = delete(root, n);
        }
    }
    levelorder(root);
    return 0;
}
