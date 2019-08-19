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
    bst *y = 0;      // 真正要被刪除並釋放記憶體的node
    bst *x = 0;      // 要被刪除的node的"child"
    if (ptr->left == NULL || ptr->right == NULL)
        y = ptr;
    else
        y = Successor(ptr);
    if (y->left != NULL)
        x = y->left; // 將x設成y的child, 可能是有效記憶體,也有可能是NULL
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
    que_push(root);                         // 把root作為level-order traversal之起點，推進queue中
    while (!que_empty())                    // 若queue不是空的, 表示還有node沒有visiting
    {
        bst *cur = que_pop();           // 取出先進入queue的node
        printf(" %d", cur->num);   // 進行visiting
        if (cur->left != NULL)     // 若leftchild有資料, 將其推進queue
            que_push(cur->left);
        if (cur->right != NULL)    // 若rightchild有資料, 將其推進queue
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
