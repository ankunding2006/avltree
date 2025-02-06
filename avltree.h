        typedef int ElementType;

/* START: fig4_35.txt */
        #ifndef _AvlTree_H
        #define _AvlTree_H

        struct AvlNode;
        typedef struct AvlNode *Position;
        typedef struct AvlNode *AvlTree;

        AvlTree MakeEmpty( AvlTree T );
        Position Find( ElementType X, AvlTree T );
        Position FindMin( AvlTree T );
        Position FindMax( AvlTree T );
        AvlTree Insert( ElementType X, AvlTree T );
        AvlTree Delete( ElementType X, AvlTree T );
        ElementType Retrieve( Position P );
        AvlTree SingleRotateWithLeft(Position K2);
        AvlTree SingleRotateWithRight(Position K1);
        AvlTree DoubleRotateWithLeft(Position K3);
        AvlTree DoubleRotateWithRight(Position K1);

        #endif  /* _AvlTree_H */
/* END */
