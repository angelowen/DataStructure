#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct t
{
    int num;
    struct t *l;
    struct t *r;
} tree;
typedef struct que
{
   tree *ptr;
    struct que *next;
} que;
que *first = NULL, *last;

int all=0,bomb=0;
int rec[2000]= {0};

void que_push(tree *ptr)
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
tree *que_pop()
{
    que *ptr = first;
    first = first->next;
    return ptr->ptr;
}
int que_empty()
{
    return first == NULL ? 1 : 0;
}
void levelorder(tree  *root)
{
    //tree *cur;
    que_push(root);                         // ��root�@��level-order traversal���_�I�A���iqueue��
    while (!que_empty())                    // �Yqueue���O�Ū�, ����٦�node�S��visiting
    {

         tree *cur= que_pop();           // ���X���i�Jqueue��node

        printf(" %d", cur->num);   // �i��visiting
        if (cur->l != NULL)     // �Yleftchild�����, �N����iqueue
            que_push(cur->l);
        if (cur->r != NULL)    // �Yrightchild�����, �N����iqueue
            que_push(cur->r);
    }
    printf("\n");
}


tree * insert(tree *root,int com,int n)
{
    tree *tmp,*t1,*pre;
    //int n;
    if(com==1){
        // printf("Enter a number:\n");
        // scanf("%d",&n);
        if(rec[n]==1)
        {
            printf("Error.Number %d exists\n",n);
            return root;
        }
        else
        {
            rec[n]=1;
        }
    }

    tmp=malloc(sizeof(tree));
    tmp->num=n;
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
            if(n>t1->num)
            {
                t1=t1->r;
            }
            else
            {
                t1=t1->l;
            }
        }
        if(n>pre->num)
        {
            pre->r=tmp;
        }
        else
        {
            pre->l=tmp;
        }
    }
    all++;
    if(com==1){
        printf("Number %d is inserted\n",n);
    }

    return root;
}
void inorder(tree *cur)
{
    if (cur)                            // if current != NULL
    {

        inorder(cur->l);       // L
        printf("%d ",cur->num); // V
        inorder(cur->r);      // R
    }
}

tree *search(int n,tree **parent,tree *root)
{
    tree *current = root;               // �Ncurent���Vroot�@��traversal�_�I
    while (current != NULL )    // ��ر��p���X�j��G
    {

        if(n==current->num)
        {
//            printf("parent=%d\n",parent->num);
            return current;
        }                                               // 1.�S��� 2.�����
        else if (n < current->num)
        {
            *parent=current;
            current = current->l; // �V����
        }
        else
        {
            *parent=current;
            current = current->r;  // �V�k��
        }
    }

    return NULL;
}
tree *min(tree *st)
{
    tree *pre;
    while (st != NULL)
    {
        pre = st;
        st = st->l;
    }
    return pre;
}
tree *delete (int n,tree *root)    // �n�R���㦳KEY��node
{
    int  val;
    tree *pre, *child,*cur, *tmp, *parent,*del;
    del = search(n, &parent,root);
    if(del==NULL)
    {
        printf("Number not found\n");
        return root;
    }
    if (del->l == NULL && del->r == NULL)
    {

        if (del != root)
        {
            if (parent->l == del)
            {
                parent->l = NULL;
            }
            else
            {
                parent->r = NULL;
            }
        }
    }
    else if (del->l && del->r)
    {
        tmp = min(del->r);
        val = tmp->num;
        root=delete (val,root);
        del->num = val;
    }
    else
    {
        if (del->l != NULL)
        {
            child = del->l;
        }
        else
        {
            child = del->r;
        }
        if (del != root)
        {
            if (del == parent->l)
            {
                parent->l = child;
            }
            else
            {
                parent->r = child;
            }
        }
        else
        {
            root = child;
        }
    }
    return root;
}
tree *preorder(tree *cur,tree *root){
    if (cur)
    {
        if(((cur->num)/10)==bomb || ((cur->num)%10)==bomb){
                printf("Number %d is deleted.\n",cur->num);
                root=delete(cur->num,root);

            }
        root=preorder(cur->l,root);       // L
        root=preorder(cur->r,root);      // R
    }

        return root;
}
void bst()
{
    char c;//command
    int n,j,enter;
    tree *root,*pre,*cur,*tmp,*parent;

    while(1)
    {
        printf("(I)nsert\n");
        printf("(D)elete\n");
        printf("(S)earch\n");
        printf("(P)rint infix & level order\n");
        printf("(R)eturn\n");
        scanf("%d",&enter);
        scanf("%c",&c);
        if(c=='r'||c=='R')
        {
            return ;
        }
        if(c=='i')
        {
             printf("Enter a number:\n");
             scanf("%d",&n);
            root=insert(root,1,n);
        }
        else if(c=='p')
        {
            printf("The tree in infix order: ");
            inorder(root);
            printf("\n");
            printf("The tree in level ordeer: ");
            levelorder(root);
             printf("\n");
        }
        else if(c=='d')
        {
            printf("Enter a number:\n");
            scanf("%d", &n);
            if (rec[n] == 0)
            {
                printf("Number not found\n");
                continue;
            }
            else
            {
                rec[n] = 0;
                all--;
            }
            root=delete(n,root);
            printf("Number %d is deleted\n",n);
        }
        else if(c=='s')
        {

            printf("Enter the element to search:\n");
            scanf("%d",&n);
            cur=search(n,&parent,root);
            if(cur==NULL)
            {
                printf("Sorry! Number not found\n");
            }
            else
            {
                printf("Bingo! Number is found\n");
            }
        }

    }

}
tree *load(tree *root){
    char file[100];
    int n;
    FILE *fp;
    printf("Please input the map file: ");
    scanf("%s",file);
    fp=fopen(file,"r");
    all=0;
    while(fscanf(fp, "%d",&n)!=EOF){
        root=insert(root,2,n);
        //printf("%d %d\n",root->num,n);
    }
    fclose(fp);
    return root;
}
int find(int n,int arr[],tree *root){
    int cnt=0;
    tree *current = root;               // �Ncurent���Vroot�@��traversal�_�I
    while (current)    // ��ر��p���X�j��G
    {

        if(n==current->num)
        {
            arr[cnt++]=current->num;
            return cnt;
        }                                               // 1.�S��� 2.�����
        else if (n < current->num)
        {
            arr[cnt++]=current->num;
            current = current->l; // �V����
        }
        else
        {
            arr[cnt++]=current->num;
            current = current->r;  // �V�k��
        }
    }

    return -1;
}
void game(){
    int key,tr,arr1[1000],arr2[1000],cnt1=0,cnt2=0,i,j,s;
    tree *root;
    root=load(root);

    printf("please input the key location:");
    scanf("%d",&key);
    printf("please input the treasure location:");
    scanf("%d",&tr);
    printf("please input the bomb number(0~9):");
    scanf("%d",&bomb);

    root=preorder(root,root);//include delete
    // inorder(root);
    printf("Adventurer successfully found the treasure.\n");
    printf("Shortest path to found the treasure:\n");
    cnt1=find(key,arr1,root);
    cnt2=find(tr,arr2,root);
    if(cnt1>cnt2){
        s=cnt2;
    }
    else{
        s=cnt1;
    }
    for(i=0;i<s;i++){
        if(arr1[i]!=arr2[i]){
            break;
        }
    }
    for(j=0;j<cnt1;j++){
        printf("%d->",arr1[j]);
    }
    for(j=cnt1-2;j>=i-1;j--){
        printf("%d->",arr1[j]);
    }
    for(j=i;j<cnt2-1;j++){
        printf("%d->",arr2[j]);
    }
    printf("%d\n",arr2[cnt2-1]);

}
int main()
{
    int com;
    while(1)
    {
        printf("(1)Binary search tree\n");
        printf("(2)Treasure hunter\n");
        printf("(3)Exit\n");
        scanf("%d",&com);
        if(com==3)
        {
            return 0;
        }
        if(com==1)
        {
            bst();
        }
        else if(com==2)
        {
            game();
        }
    }
    return 0;
}
