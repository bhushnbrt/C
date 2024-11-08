// Structure of Binary Trees

struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

/*
          1
        /   \
       2     3
      / \   / \
     4   5 6   7

*/

// PreOrder Traversal

void PreOrder(struct BinaryTreeNode *root)
{
    if(root)
    {
        printf("%d", root->data)
        PreOrder(root->left)
        PreOrder(root->right)
    }
}


// Inorder Traversal

void InOrder(struct BinaryTreeNode *root)
{
    if(root)
    {
        InOrder(root->left);
        printf("d", root->data)
        InOrder(root->right);
    }
}


// PostOrder Traversal

void PostOrder(struct BinaryTreeNode *root)
{
    if(root)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d", root->data)
    }
}


// Level Order Traversal
void LevelOrder(struct BinaryTreeNode *root)
{
    struct BinaryTreeNode *temp;
    struct Queue *Q=CreateQueue();
    if(!root)
        return;
    EnQueue(Q,root);
    while(!IsEmptyQueue(Q))
    {
        temp=DeQueue(Q);
        // Process current node
        printf("%d", temp->data);
        if(temp->data)
            EnQueue(Q, temp->left);
        if(temp->right)
            EnQueue(Q, temp->right);
    }
    DeleteQueue(Q);
}
