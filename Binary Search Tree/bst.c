#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief The structure of a binary search tree node
 */
struct BstNode
{
  int data;
  struct BstNode *right;
  struct BstNode *left;
};

/**
 * @brief Create a new node
 * @param data: The value of the node
 * @return The new node
 */
struct BstNode *GetNewNode(int data)
{
  struct BstNode *newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
};

/**
 * @brief Insert a value in the binary search tree
 * @param root: The root of the binary search tree
 * @param data: The value to insert
 * @return The root of the binary search tree
 */
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

/**
 * @brief Search a value in the binary search tree
 * @param root: The root of the binary search tree
 * @param data: The value to search
 * @return True if the value is found, false otherwise
 */
bool search(struct BstNode *root, int data)
{
  if (root == NULL)
    return false;
  else
  {
    if (root->data == data)
      return true;
    else
    {
      if (data <= root->data)
        return search(root->left, data);
      else
        return search(root->right, data);
    }
  }
}

/**
 * @brief Find minimum value in the binary search tree
 * @param root: The root of the binary search tree
 * @return The minimum value
 */
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

/**
 * @brief Find maximum value in the binary search tree
 * @param root: The root of the binary search tree
 * @return The maximum value
 */
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

/**
 * @brief Find the height of the binary search tree
 * @param root: The root of the binary search tree
 * @return The height of the binary search tree
 */
int findHeight(struct BstNode *root)
{
  if (root == NULL)
    return -1;

  int lefth = findHeight(root->left);
  int righth = findHeight(root->right);

  return (lefth > righth ? lefth : righth) + 1;
}

/**
 * @brief Inorder traversal of the binary search tree
 * @param root: The root of the binary search tree
 */
void inorderTraversal(struct BstNode *root)
{
  if (root == NULL)
    return;

  inorderTraversal(root->left);
  printf("%d ", root->data);
  inorderTraversal(root->right);
}

/**
 * @brief Preorder traversal of the binary search tree
 * @param root: The root of the binary search tree
 */
void preorderTraversal(struct BstNode *root)
{
  if (root == NULL)
    return;

  printf("%d ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

/**
 * @brief Postorder traversal of the binary search tree
 * @param root: The root of the binary search tree
 */
void postorderTraversal(struct BstNode *root)
{
  if (root == NULL)
    return;

  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ", root->data);
}

/**
 * @brief Main function
 */
int main()
{
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
  printf("The height is : %d\n", findHeight(root));

  printf("Inorder Traversal: ");
  inorderTraversal(root);
  printf("\n");

  printf("Preorder Traversal: ");
  preorderTraversal(root);
  printf("\n");

  printf("Postorder Traversal: ");
  postorderTraversal(root);
  printf("\n");

  return 0;
}
