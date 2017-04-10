//Binary Search Tree header file
#include <iostream>
#pragma once
struct Node{
  int value;
  Node* lchild;
  Node* rchild;
};
class Tree{
 public:
  Tree();
  ~Tree();
  void insert(int key);//adding to the tree
  Node* search(int key);//going through the tree
  void destroy();//destroying a particular part of the tree
 private:
  void destroy(Node* root);
  void insert(int key, Node* root);
  Node* search(int key, Node* root);
  Node* head;
};
