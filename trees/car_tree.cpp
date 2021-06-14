#include "car_tree.h"
#include "mainwindow.h"


base * tree = nullptr;

base* merge(base* qo, base* b) {
  if (qo == nullptr) {
    return b;
  } else if (b == nullptr) {
    return qo;
  } else if (qo->prior > b->prior) {
    qo->right = merge(qo->right, b);
    return qo;
  } else {
    b->left = merge(qo, b->left);
    return b;
  }
}


std::pair<base*, base*> split(base* tek, int count) {
  std::pair<base*, base*> oneee;
  if (tek == nullptr) {
    oneee.first = nullptr;
    oneee.second = nullptr;
    return oneee;
  } else if (count > tek->key) {
    std::pair<base*, base*> help = split(tek->right, count);
    tek->right = help.first;
    oneee.first = tek;
    oneee.second = help.second;
    return oneee;
  } else {
    std::pair<base*, base*> twooo = split(tek->left, count);
    tek->left = twooo.second;
    oneee.first = twooo.first;
    oneee.second = tek;
    return oneee;
  }
}


void ins_deck(int k) {
  base * p = new base;
  p->left = p->right = nullptr;
  p->key = k;
  p->prior = rand();
  std::pair<base*, base*> spl = split(tree, k);
  spl.first = merge(spl.first, p);
  tree = merge(spl.first, spl.second);
}

int height_deck(base* p) {
    if (!p) return -1;
    return 1 + std::max(height_deck(p->left), height_deck(p->right));
}

base* erase (base* & t, int key) {
  if (t->key == key) {
      //if (!t->left and !t->right)
    t  = merge(t->left, t->right);
  } else {
    erase(key < t->key ? t->left : t->right, key);
  }
}

void tre_del(base* q) {
    if (q != nullptr) {
        tre_del(q->left);
        tre_del(q->right);
        delete q;
    }
}

bool find_deck(base* q, int key) {
    if (q == nullptr) return false;
    if (q->key == key) return true;
    return find_deck(q->right, key) or find_deck(q->left, key);
}

