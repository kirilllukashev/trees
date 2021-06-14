#ifndef FUNCS_H
#define FUNCS_H

#include "mainwindow.h"



extern double zoom_size;
extern node* root;
extern bool flag_deck;
extern bool flag_avl;
extern bool flag_rand;
extern bool flag;
int height(node* p);
int checkheig(node* p);
void fixheight(node* p);
node* rotateright(node* p);
node* rotateleft(node* q);
node* balance(node* p);
node* insert(node* p, int k);
node* findmin(node* p);
node* removemin(node* p);
node* remove(node* p, int k);
void del_tree(node* q);
bool find_avl(node* q, int key);
node* splay(node *root, int key);
void ins_Tree(node* q, int key);
node* ins_splay(node* q, int key);
int64_t to_int(std::string str_numb);
node* Merge(node* q1, node* q2);
node* del_splay(node* q, int key);
int heig_tree(node* p);

#endif // FUNCS_H
