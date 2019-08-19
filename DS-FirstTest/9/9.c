#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct t
{
    int val;
    struct t *l;
    struct t *r;
} tree;
void preorder(tree *cur)
{
    if (cur)                            // if current != NULL
    {
        printf("%d ",cur->val);   // V
        preorder(cur->l);       // L
        preorder(cur->r);      // R
    }
}
void inorder(tree *cur)
{
    if (cur)                            // if current != NULL
    {

        inorder(cur->l);       // L
        printf("%d ",cur->val);   // V
        inorder(cur->r);      // R
    }
}
void postorder(tree *cur)
{
    if (cur)                            // if current != NULL
    {

        postorder(cur->l);       // L
        postorder(cur->r);      // R
        printf("%d ",cur->val);   // V
    }
}
int main()
{
    int n,all=0;
    tree *tmp,*root,*t1,*pre;
    freopen("9input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        tmp=malloc(sizeof(tree));
        tmp->val=n;
        tmp->l=NULL;
        tmp->r=NULL;
        if(all==0)
        {

            root =tmp;
        }
        else
        {
            t1=root;
            while(t1!=NULL)
            {
                pre=t1;
                if(n>t1->val)
                {
                    t1=t1->r;
                }
                else
                {
                    t1=t1->l;
                }
                //////
            }
            if(n>pre->val)
            {
                pre->r=tmp;
            }
            else
            {
                pre->l=tmp;
            }
        }
        all++;
    }

    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    return 0;
}
