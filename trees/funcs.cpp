#include "funcs.h"
#include "mainwindow.h"
#include <iostream>
#include <cmath>
#include <algorithm>


double zoom_size = 1.0;
bool flag = false;

node* root = nullptr;


bool flag_deck = false;
bool flag_avl = false;
bool flag_rand = false;
int height(node* p)
{
  return p?p->height:0;
}

int checkheig(node* p)
{
  return height(p->right)-height(p->left);
}

int heig_tree(node* p) {
    if (p == nullptr) {
        return 0;
    }
    return 1 + std::max(heig_tree(p->left), heig_tree(p->right));
}

void fixheight(node* p)
{
  int hl = height(p->left);
  int hr = height(p->right);
  p->height = (hl>hr?hl:hr)+1;
}

node* rotateright(node* p) // правый поворот вокруг p
{
  node* q = p->left;
  p->left = q->right;
  q->right = p;
  fixheight(p);
  fixheight(q);
  return q;
}

node* rotateleft(node* q) // левый поворот вокруг q
{
  node* p = q->right;
  q->right = p->left;
  p->left = q;
  fixheight(q);
  fixheight(p);
  return p;
}

node* balance(node* p) // балансировка узла p
{
  fixheight(p);
  if (checkheig(p) == 2)
  {
    if (checkheig(p->right) < 0)
      p->right = rotateright(p->right);
    return rotateleft(p);
  }
  if(checkheig(p) == -2)
  {
    if(checkheig(p->left) > 0)
      p->left = rotateleft(p->left);
    return rotateright(p);
  }
  return p;
}

node* insert(node* p, int k)
{
  if (!p) return new node(k);
  if(k < p->key)
    p->left = insert(p->left,k);
  else
    p->right = insert(p->right,k);
  return balance(p);
}

node* findmin(node* p)
{
  return p->left?findmin(p->left):p;
}

node* removemin(node* p)
{
  if(p->left == nullptr)
    return p->right;
  p->left = removemin(p->left);
  return balance(p);
}

node* remove(node* p, int k)
{
  if(!p) return nullptr;
  if( k < p->key )
    p->left = remove(p->left,k);
  else if( k > p->key )
    p->right = remove(p->right,k);
  else //  k == p->key
  {
    node* q = p->left;
    node* r = p->right;
    delete p;
    if(!r) return q;
    node* min = findmin(r);
    min->right = removemin(r);
    min->left = q;
    return balance(min);
  }
  return balance(p);
}



int64_t to_int(std::string str_numb) {
  int64_t number = 0;
  int64_t strlength = str_numb.size();
  for (int i = 0; i < strlength; ++i) {
    number += (str_numb[i] - '0') * std::pow(10, strlength - i - 1);
  }
  return number;
}

void del_tree(node* q) {
    if (q != nullptr) {
        del_tree(q->left);
        del_tree(q->right);
        delete q;
        qDebug() << "check";
    }
}

bool find_avl(node* q, int key) {
    if (q == nullptr) return false;
    if (q->key == key) return true;
    return find_avl(q->right, key) or find_avl(q->left, key);
}







node *splay(node *root, int key)
{
  if (root == nullptr or root->key == key)
    return root;

  if (root->key > key)
  {
    if (root->left == nullptr) return root;

    // Zig-Zig левый
    if (root->left->key > key)
    {
      root->left->left = splay(root->left->left, key);
      root = rotateright(root);
    }
    else if (root->left->key < key) // Zig-Zag
    {
      root->left->right = splay(root->left->right, key);

      if (root->left->right != nullptr)
        root->left = rotateleft(root->left);
    }
    return (root->left == nullptr)? root: rotateright(root);
  }
  else
  {
    if (root->right == nullptr) return root;
    // zig-zag правый
    if (root->right->key > key)
    {
      root->right->left = splay(root->right->left, key);

      if (root->right->left != nullptr)
        root->right = rotateright(root->right);
    }
    else if (root->right->key < key)// zig-zig правый
    {
      root->right->right = splay(root->right->right, key);
      root = rotateleft(root);
    }
    return (root->right == nullptr)? root: rotateleft(root);
  }
}

node* Merge(node* q1, node* q2) {
  node* max = q1;
  if (max == nullptr) return q2;
  while (max->right != nullptr) {
    max = max->right;
  }
  node* curr = splay(q1, max->key);
  //out(curr);
  curr->right = q2;
  return curr;
}

void ins_Tree(node* q, int key) {
  if (q->key > key) {
    if (q->left == nullptr) {

      q->left = new node(key);
      q->left->left = nullptr;
      q->left->right = nullptr;
      return;
    }
    ins_Tree(q->left, key);
  } else {
    if (q->right == nullptr) {
       q->right = new node(key);
       q->right->left = nullptr;
       q->right->right = nullptr;
      return;
    }
    ins_Tree(q->right, key);
  }
}

node* ins_splay(node* q, int key) {
  if (q == nullptr) {
      q = new node(key);
      return q;
  }
  ins_Tree(q, key);
  return splay(q, key);
}

node* del_splay(node* q, int key) {
    node* tek = splay(q, key);
    return Merge(tek->left, tek->right);
}


