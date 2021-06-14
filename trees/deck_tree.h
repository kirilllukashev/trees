#ifndef DECK_TREE_H
#define DECK_TREE_H
#include "mainwindow.h"

extern base* tree;

base* merge(base* qo, base* b);
std::pair<base*, base*> split(base* tek, int count);
void ins_deck(int k);
int height_deck(base* p);
base* erase (base* & t, int key);
void tre_del(base* q);
bool find_deck(base* q, int key);
#endif // DECK_TREE_H
