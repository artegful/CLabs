#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
typedef struct tnode
{
    char letter;
    int count;
    struct tnode *left;
    struct tnode *right;
} Tree;

Tree *AddTree(Tree *p, char w);
void TreePrint(Tree *p);
void FreeMem(Tree *tree);
int Max(int a, int b);
int Depth(Tree *ptr, int depCount);

int main()
{
    Tree *root;
    char letter;
    root = NULL;
    do
    {
        letter = getchar();
        if (isalpha(letter))
        {
            root = AddTree(root, letter);
        }
    } while (letter != EOF && letter != '\n');
    TreePrint(root);
    printf("\nDepth = %d\n", Depth(root, 0));
    FreeMem(root);
    return 0;
}

Tree *AddTree(Tree *p, char w)
{
    int cond;
    if (p == NULL)
    {
        p = (Tree *)malloc(sizeof(Tree));
        p->letter = w;
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if (w == p->letter)
    {
        p->count++;
    }
    else if (w < p->letter)
    {
        p->left = AddTree(p->left, w);
    }
    else
    {
        p->right = AddTree(p->right, w);
    }
    return p;
}

void TreePrint(Tree *p)
{
    if (p != NULL)
    {
        TreePrint(p->left);
        printf("%d %c\n", p->count, p->letter);
        TreePrint(p->right);
    }
}

void FreeMem(Tree *tree)
{
    if (tree != NULL)
    {
        FreeMem(tree->left);
        FreeMem(tree->right);
        free(tree);
    }
}

int Max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int Depth(Tree *ptr, int depCount)                             
{
        if(ptr == NULL)
              return depCount;
 
        return Max(Depth(ptr -> left, depCount+1), Depth(ptr -> right, depCount+1));
}

