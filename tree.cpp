//Cpp file for Binary Search Tree
#include <iostream>
#include "tree.h"

using namespace std;

Tree::Tree(){
  head = NULL;
}
/*
Tree::~Tree(){
  destroy();
}
*/
void Tree::destroy(Node* root){
  //have to make sure there is actually something in this node or else we would be deleting nothing
  if(root != NULL){
    destroy(root->lchild);
    destroy(root->rchild);
    delete root;
  }
}
void Tree::insert(int key, Node* root){
  if(key < root->value){
    if(root->lchild != NULL){
      insert(key, root->lchild);
    }
    else{
      root->lchild = new Node;
      root->lchild->value = key;
      root->lchild->lchild = NULL;
      root->lchild->rchild = NULL;
    }
  }
  else if(key >= root->value){
    if(root->rchild != NULL){
      insert(key, root->rchild);
    }
    else{
      root->rchild = new Node;
      root->rchild->value = key;
      root->rchild->lchild = NULL;
      root->rchild->rchild = NULL;
    }
  }
}
Node* Tree::search(int key, Node* root){
  if(root != NULL){
    if(key == root->value){
      return root;
    }
    //repeats process based on roots value
    if(key < root->value){
      return search(key, root->lchild);
    }
    else{
      return search(key, root->rchild);
    }
  }
}
void Tree::insert(int key){
  if(head != NULL){
    insert(key, head);
  }
  else{
    head = new Node;
    head->value = key;
    head->lchild = NULL;
    head->rchild = NULL;
  }
}
Node* Tree::search(int key){
  return search(key, head);
}
void Tree::destroy(){
  destroy(head);
}
