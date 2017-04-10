//Main file for Binary Search Tree
#include <iostream>
#include <sstream>
#include <stdio.h>
using namespace std;
struct Node{
  int value;
  Node* lchild;
  Node* rchild;
};
Node* head = NULL;
void add(int key);
void add(int key, Node* root);
void seperate(char* input);
Node* search(int key);
Node* search(int key, Node* root);
void print(Node* root, int dif);
int main(){
  cout << "Welcome to Binary Search Tree, Enter a list of numbers" << endl;
  char input[200];
  cin.getline(input,200);
  seperate(input);
  int dif = 0;
  print(head,dif);
}
void seperate(char* input){
  int index = 0;
  while(input[index]){
    if(isdigit(input[index])){
      int i = input[index] - '0';
      while(isdigit(input[++index])){
	i = 10*i + (input[index] - '0');
      }
      add(i);
    }
    else{
      index++;
    }
  }
}
void add(int key){
  if(head != NULL){
    add(key, head);
  }
  else{
    head = new Node;
    head->value = key;
    head->lchild = NULL;
    head->rchild = NULL;
  }
}
void add(int key, Node* root){
  if(key < root->value){
    if(root->lchild != NULL){
      add(key,root->lchild);
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
      add(key,root->rchild);
    }
    else{
      root->rchild = new Node;
      root->rchild->value = key;
      root->rchild->lchild = NULL;
      root->rchild->rchild = NULL;
    }
  }
}
Node* search(int key, Node* root){
  if(root != NULL){
    if(key == root->value){
      return root;
    }
    if(key < root->value){
      return search(key,root->lchild);
    }
    else{
      return search(key,root->rchild);
    }
  }
  else{
    return NULL;
  }
}
Node* search(int key){
  return search(key, head);
}
void print(Node* root, int dif){
  if(root == NULL){
    return;
  }
  int i = 2;
  dif += i;
  print(root->rchild,dif);
  for(int x = i;x < dif;x++){
    printf(" ");
  }
  printf("%d\n",root->value);
  print(root->lchild,dif);
}
