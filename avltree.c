#include "avltree.h"
#include <stdio.h>
#include <stdlib.h>

struct AvlNode{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

// Function prototypes


AvlTree MakeEmpty(AvlTree T){
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}


void PrintTree(AvlTree T) {
    static int depth = 0;
    if (T != NULL) {
        depth += 1;
        PrintTree(T->Right);  // Print right subtree first (switched from left)
        
        for (int i = 1; i < depth; i++)
            printf("      ");  // Space for indentation
        printf("%d ----\n", T->Element);
        
        PrintTree(T->Left);   // Print left subtree last (switched from right)
        depth -= 1;
    }
}


static int Max(int a, int b) {
    return a > b ? a : b;
}

int height(AvlTree T)
{
    if(T==NULL)
    {
        return -1;
    }
    return T->Height;
}



Position Find(ElementType X,AvlTree T)
{
    if(T==NULL)
    {
        return NULL;
    }
    if(X<T->Element)  //to the left
    {
        T=Find(X,T->Left);
    }

    if(X>T->Element)  //to the right
    {
        T=Find(X,T->Right);
    }


    //find
    return T;    

}




AvlTree GenerateTestTree() {
    AvlTree T = NULL;
    // Manually create a balanced AVL tree with known structure
    T = malloc(sizeof(struct AvlNode));
    T->Element = 50;
    T->Height = 4;  // 增加高度
    
    // Left subtree
    T->Left = malloc(sizeof(struct AvlNode));
    T->Left->Element = 30;
    T->Left->Height = 3;
    
    T->Left->Left = malloc(sizeof(struct AvlNode));
    T->Left->Left->Element = 20;
    T->Left->Left->Height = 2;
    
    // 添加新的子节点
    T->Left->Left->Left = malloc(sizeof(struct AvlNode));
    T->Left->Left->Left->Element = 10;
    T->Left->Left->Left->Height = 1;
    T->Left->Left->Left->Left = T->Left->Left->Left->Right = NULL;

    T->Left->Left->Right = malloc(sizeof(struct AvlNode));
    T->Left->Left->Right->Element = 25;
    T->Left->Left->Right->Height = 1;
    T->Left->Left->Right->Left = T->Left->Left->Right->Right = NULL;
    
    T->Left->Right = malloc(sizeof(struct AvlNode));
    T->Left->Right->Element = 40;
    T->Left->Right->Height = 2;
    
    // 添加新的子节点
    T->Left->Right->Left = malloc(sizeof(struct AvlNode));
    T->Left->Right->Left->Element = 35;
    T->Left->Right->Left->Height = 1;
    T->Left->Right->Left->Left = T->Left->Right->Left->Right = NULL;

    T->Left->Right->Right = malloc(sizeof(struct AvlNode));
    T->Left->Right->Right->Element = 45;
    T->Left->Right->Right->Height = 1;
    T->Left->Right->Right->Left = T->Left->Right->Right->Right = NULL;
    
    // Right subtree
    T->Right = malloc(sizeof(struct AvlNode));
    T->Right->Element = 70;
    T->Right->Height = 3;
    
    T->Right->Left = malloc(sizeof(struct AvlNode));
    T->Right->Left->Element = 60;
    T->Right->Left->Height = 2;
    
    // 添加新的子节点
    T->Right->Left->Left = malloc(sizeof(struct AvlNode));
    T->Right->Left->Left->Element = 55;
    T->Right->Left->Left->Height = 1;
    T->Right->Left->Left->Left = T->Right->Left->Left->Right = NULL;

    T->Right->Left->Right = malloc(sizeof(struct AvlNode));
    T->Right->Left->Right->Element = 65;
    T->Right->Left->Right->Height = 1;
    T->Right->Left->Right->Left = T->Right->Left->Right->Right = NULL;
    
    T->Right->Right = malloc(sizeof(struct AvlNode));
    T->Right->Right->Element = 80;
    T->Right->Right->Height = 2;
    
    // 添加新的子节点
    T->Right->Right->Left = malloc(sizeof(struct AvlNode));
    T->Right->Right->Left->Element = 75;
    T->Right->Right->Left->Height = 1;
    T->Right->Right->Left->Left = T->Right->Right->Left->Right = NULL;

    T->Right->Right->Right = malloc(sizeof(struct AvlNode));
    T->Right->Right->Right->Element = 90;
    T->Right->Right->Right->Height = 1;
    T->Right->Right->Right->Left = T->Right->Right->Right->Right = NULL;
    
    return T;
}


// 修改 Insert 函数中更新高度的部分
AvlTree Insert(ElementType X, AvlTree T)
{
    if(T==NULL)
    {
            AvlTree tempt=malloc(sizeof(struct AvlNode));
            tempt->Element=X;
            tempt->Height=0;
            tempt->Left=NULL;
            tempt->Right=NULL;
            T=tempt;
    }
    if(X<T->Element)
    {
        
        T->Left=Insert(X,T->Left);
        
        if (height(T->Left)-height(T->Right)==2)
        {
            /* code */
            if(X<T->Left->Element)
                T=SingleRotateWithLeft(T);
            else
                T=DoubleRotateWithLeft(T);
        }
        
        
        
    }

    if(X>T->Element)
    {
        
        
            T->Right=Insert(X,T->Right);
        
        if (height(T->Right)-height(T->Left)==2)
        {
            if(X>T->Right->Element)
                T=SingleRotateWithRight(T);
            else
                T=DoubleRotateWithRight(T);
        }
    }

    T->Height = Max( height(T->Left), height(T->Right) ) + 1;
    return T;
    
}

// 修改后的 SingleRotateWithLeft 函数
AvlTree SingleRotateWithLeft( Position K2 )
{
    AvlTree k1 = K2->Left;
    K2->Left = k1->Right;
    k1->Right = K2;

    K2->Height = Max( height(K2->Left), height(K2->Right) ) + 1;
    k1->Height = Max( height(k1->Left), height(K2) ) + 1;
    return k1;
}

// 修改后的 SingleRotateWithRight 函数
AvlTree SingleRotateWithRight( Position K1 )
{
    AvlTree k2 = K1->Right;
    K1->Right = k2->Left;
    k2->Left = K1;

    K1->Height = Max( height(K1->Left), height(K1->Right) ) + 1;
    k2->Height = Max( height(k2->Right), height(K1) ) + 1;
    return k2;
}

AvlTree DoubleRotateWithLeft( Position K3)
{
    Position K1=K3->Left;
    Position K2=K1->Right;
    K3->Left=SingleRotateWithRight(K1);
    return SingleRotateWithLeft(K3);
}

AvlTree DoubleRotateWithRight(Position K1) 
{
    Position K3 = K1->Right;
    Position K2 = K3->Left;
    K1->Right = SingleRotateWithLeft(K3);
    return SingleRotateWithRight(K1);
}













int main(void)
{
    AvlTree temp1;
    int mode;
    AvlTree T=GenerateTestTree();
    PrintTree(T);
    while (printf("please in select you mode"),scanf("%d",&mode),mode!=0)
    {
        /* code */
        for(int i=0;i<5;i++)
        {
            printf("\n");
        }
        switch (mode)
        {
        case 0:  goto end;
        
        case 1:    //insert
            /* code */
            int InsertElement;
            printf("please input your insert num");
            scanf("%d",&InsertElement);
            Insert(InsertElement,T);
            break;

        case 2:    //make empty
            MakeEmpty(T);
            printf("ok,the tree is empty already");
            break;
        
        case 3 :    //find
            int FindElement;
            printf("please input the num you want to find");
            scanf("%d",&FindElement);
            temp1=Find(FindElement,T);
            printf("the address the num you find is %X",temp1);
            break;
        }
        printf("\n");
        PrintTree(T);
    }
end:
}