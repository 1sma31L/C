#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BstNode
{
  int data;
  struct BstNode *right;
  struct BstNode *left;
};

// Create a new node in the binary seach tree
struct BstNode *GetNewNode(int data)
{
  struct BstNode *newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
};

// Insert a new node in the binary seach tree
struct BstNode *insert(struct BstNode *root, int data)
{
  if (root == NULL)
  {
    root = GetNewNode(data);
  }
  else if (data <= root->data)
  {
    root->left = insert(root->left, data);
  }
  else
  {
    root->right = insert(root->right, data);
  }
  return root;
};

// Search in the binary seach tree
bool search(struct BstNode *root, int data)
{
  if (root == NULL)
    return false;
  else if (root->data == data)
    return true;
  else if (data <= root->data)
    return search(root->left, data);
  else
    return search(root->right, data);
}

// Find minimum value in the binary search tree
int findMin(struct BstNode *root)
{
  if (root == NULL)
  {
    return -1;
  }
  else if (root->left == NULL)
  {
    return root->data;
  }
  else
  {
    return findMin(root->left);
  }
}

// Find maximum value in the binary search tree
int findMax(struct BstNode *root)
{
  if (root == NULL)
  {
    return -1;
  }
  else if (root->right == NULL)
  {
    return root->data;
  }
  else
  {
    return findMax(root->right);
  }
}

// Find height of the binary search tree
int findHeight(struct BstNode *root)
{
  if (root == NULL)
    return -1;

  int lefth = findHeight(root->left);
  int righth = findHeight(root->right);

  return (lefth > righth ? lefth : righth) + 1;
}

int main()
{
  int searchVal;
  struct BstNode *root = NULL;
  root = insert(root, 15);
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 25);
  root = insert(root, 30);
  root = insert(root, 21);
  root = insert(root, 8);
  root = insert(root, 7);
  root = insert(root, 6);
  root = insert(root, 6);
  root = insert(root, 6);
  printf("The max value is : %d\n", findMax(root));
  printf("The min value is : %d\n", findMin(root));
  printf("The the height is : %d\n", findHeight(root));
  return 0;
}