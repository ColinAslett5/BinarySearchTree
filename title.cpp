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
Node* delt(Node* root, int x);
int main(){
  cout << "Welcome to Binary Search Tree, Enter a list of numbers" << endl;
  char input[200];
  cin.getline(input,200);
  seperate(input);
  bool kg = true;
  while(kg == true){
    char i;
    cout << "1 = print tree, 2 = add a number, 3 = delete a number, 4 = quit" << endl;
    cin >> i;
    //printing out the tree
    if(i == '1'){
      int dif = 0;
      print(head,dif);
    }
    //adding a number
    if(i == '2'){
      int numb;
      cout << "Enter a number: ";
      cin >> numb;
      cout << endl;
      add(numb);
    }
    //deleting a part of the tree
    if(i == '3'){
      int numx;
      cout << "Enter a number: ";
      cin >> numx;
      cout << endl;
      delt(head,numx);
    }//quitting
    if(i == '4'){
      kg = false;
    }
  }
  return 0;
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
  int i = 3;
  dif += i;
  print(root->rchild,dif);
  for(int x = i;x < dif;x++){
    printf(" ");
  }
  printf("%d\n",root->value);
  print(root->lchild,dif);
}
Node* delt(Node* root, int x){
  if(root == NULL){
    return root;
  }
  else if(x < root->value){
    root->lchild = delt(root->lchild,x);
  }
  else if(x > root->value){
    root->rchild = delt(root->rchild,x);
  }
  else{
    //if the root value has no children
    if(root->lchild == NULL && root->rchild == NULL){
      delete root;
      root = NULL;
    }
    //if the root value has no left child
    else if(root->lchild == NULL){
      Node* current = root;
      root = root->rchild;
      delete current;
    }
    //if the root value has no right child
    else if(root->rchild == NULL){
      Node* current = root;
      root = root->lchild;
      delete current;
    }
    //smallest node possible
    else{
      Node* current = root->rchild;
      while(current->lchild != NULL){
	current = current->lchild;
      }
      root->value = current->value;
      root->rchild = delt(root->rchild,current->value);
    }
  }
  return root;
}
