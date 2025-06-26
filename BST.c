#include<stdio.h>
#include<stdlib.h>

// Defining a structure of a node
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

// allies name
typedef struct Node tNode;

tNode* createNode(int val){
    tNode* newNode = NULL;
    newNode = (tNode*)malloc(sizeof(tNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// constructing Binary tree using BST rules
tNode* insert(tNode* root, int val){
    if(root == NULL){
        return createNode(val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    } else if(val > root->data){
        root->right = insert(root->right, val);
    }

    return root;
}

// inorder traversal
// left-> root-> right
void inOrder(tNode* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);

}

// finding min means traversing till the left most node or the left leaf node
int findMin(tNode* root){
    if(root == NULL){
        printf("Tree is empty\n");
        return -1;
    }

    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}

// to get the max element in the BST we need to traverse till the left most leaf of the tree
int findMax(tNode* root){
    if(root == NULL){
        printf("Tree is empty..\n");
        return -1;
    }

    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}




int main(){
    tNode* root = NULL;

    int vals[] = {50,30,70,20,40,60,80};
    int n = sizeof(vals)/sizeof(int);
    
    for(int i = 0; i < n; i++){
        root = insert(root, vals[i]);
    }

    printf("In-order traversal of the tree is: ");
    inOrder(root);
    printf("\n");

    int min = findMin(root);
    int max = findMax(root);

    printf("The min = %d and max = %d ", min , max);

    return 0;
}
