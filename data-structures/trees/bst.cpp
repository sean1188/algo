#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * Implementation of a node-based Binary Search Tree.
 * Binary search trees allow fast lookup and min max.
 * Creates the following tree
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80
*/

struct Node {
  int key;
  struct Node *left, *right;
};

// Create new node
Node *newNode(int i) {
  struct Node *foo = (struct Node *)malloc(sizeof(struct Node));
  foo->key = i;
  foo->left = NULL;
  foo->right = NULL;
  return foo;
};

// Inorder traversal
void inorder(Node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d \n", root->key);
    inorder(root->right);
  }
}

// Create new node
Node *insert(Node *node, int key) {
  // Create new node
  if (node == NULL)
    return newNode(key);

  // Recur
  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);

  return node;
}

// Find the min
Node *minValueNode(Node *node) {
  Node *current = node;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current;
}

// Delete a node
Node *deleteNode(Node *root, int key) {
  if (root == nullptr)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // One child or no child
    if (root->left == nullptr) {
      Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == nullptr) {
      Node *temp = root->left;
      free(root);
      return temp;
    }
    // Multiple children
    Node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }

  return root;
}

int main() {
  Node *tree = NULL;
  tree = insert(tree, 10);
  insert(tree, 20);
  insert(tree, 30);
  insert(tree, 40);
  insert(tree, 50);
  insert(tree, 60);
  insert(tree, 25);
  insert(tree, 23);
  insert(tree, 61);

  inorder(tree);

  printf("\nDeleting 30...\n");
  tree = deleteNode(tree, 30);
  inorder(tree);

  printf("\nDeleting 50...\n");
  tree = deleteNode(tree, 50);
  inorder(tree);

  return 0;
};
