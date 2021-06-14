#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "digit_vertex.h"
#include "deck_tree.h"
#include "funcs.h"
#include <QMessageBox>
#include <QGraphicsScene>
#include <QDebug>
#include <vector>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scense = new QGraphicsScene(this);
    ui->graphicsView_2->setScene(scense);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::draw_tree() {}

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView_2->scale(zoom_size + 0.2, zoom_size + 0.2);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView_2->scale(zoom_size - 0.2, zoom_size - 0.2);
}

void MainWindow::preorder(node* p, int x1, int y1, int a)
{
  if(p != nullptr)
  {
    int value_tek = p->key;
    digit_vertex *digit = new digit_vertex(x1, y1, a, value_tek, 0);
    scense->addItem(digit);
    QString tek_text = std::to_string(value_tek).c_str();

    if (p->left) QGraphicsLineItem *line_left = scense->addLine(QLineF(x1, y1 + a, x1 - std::pow(2, heig_tree(p) - 1) * a, y1 + 2 * a));
    if (p->right) QGraphicsLineItem *line_right = scense->addLine(QLineF(x1 + a, y1 + a, x1 + a + std::pow(2, heig_tree(p) - 1) * a, y1 + 2 * a));

    preorder(p->left, x1 - a - std::pow(2, heig_tree(p) - 1) * a, y1 + 2 * a, a);
    preorder(p->right, x1 + a + std::pow(2, heig_tree(p) - 1) * a, y1 + 2 * a, a);
  }
}

int rand_diap(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void MainWindow::on_pushButton_3_clicked()
{
    int value_vertex = to_int(ui->lineEdit->text().toStdString());
    ui->lineEdit->clear();
    if (flag_avl || flag_rand) {
        if (flag_avl) root = insert(root, value_vertex);
        if (flag_rand) root = ins_splay(root, value_vertex);

        for (QGraphicsItem* it: scense->items()) {
              delete(it);
            }
        scense = new QGraphicsScene(this);
        ui->graphicsView_2->setScene(scense);
        preorder(root, 30, 30, 30);
    } else {
        ins_deck(value_vertex);
        for (QGraphicsItem* it: scense->items()) {
              delete(it);
            }
        scense = new QGraphicsScene(this);
        ui->graphicsView_2->setScene(scense);
        out(tree, 30, 30, 30);
    }
}

void MainWindow::delete_vertex() {
    scense = new QGraphicsScene(this);
    ui->graphicsView_2->setScene(scense);
    if (flag_avl or flag_rand) {
        if (root != nullptr) {
            preorder(root, 30, 30, 30);
        } else {
            for (QGraphicsItem* it: scense->items()) {
                  delete(it);
                }
            scense = new QGraphicsScene(this);
            ui->graphicsView_2->setScene(scense);
        }

    } else if (flag_deck) {
        out(tree, 30, 30, 30);
    }
}



void MainWindow::on_pushButton_4_clicked()
{
    int quantity = to_int(ui->lineEdit_n->text().toStdString());
    ui->lineEdit_n->clear();
    int left_val = 1;
    int right_cal = 1e5;
    ui->lineEdit_n->clear();
    if (flag_avl or flag_rand) {
        for (int i = 0; i < quantity; ++i) {
            int tek_vert = rand_diap(left_val, right_cal);
            while (find_avl(root, tek_vert)) {
                tek_vert = rand_diap(left_val, right_cal);
            }
            if (flag_avl) root = insert(root, tek_vert);
            if (flag_rand) root = ins_splay(root, tek_vert);

            for (QGraphicsItem* it: scense->items()) {
                  delete(it);
                }
            scense = new QGraphicsScene(this);
            ui->graphicsView_2->setScene(scense);
            preorder(root, 30, 30, 30);

        }
    } else if (flag_deck) {
        for (int i = 0; i < quantity; ++i) {
            int tek_vert = rand_diap(left_val, right_cal);
            while (find_deck(tree, tek_vert)) {
                tek_vert = rand_diap(left_val, right_cal);
            }
            if (flag_avl) root = insert(root, tek_vert);
            if (flag_deck) ins_deck(tek_vert);

            for (QGraphicsItem* it: scense->items()) {
                  delete(it);
            }
            scense = new QGraphicsScene(this);
            ui->graphicsView_2->setScene(scense);
            out(tree, 30, 30, 30);

        }
    }


}

void MainWindow::out(base* p, int x1, int y1, int a)
{
  if(p != nullptr)
  {
    int value_tek = p->key;
    digit_vertex *digit = new digit_vertex(x1, y1, a, value_tek, 0);
    scense->addItem(digit);
    QString tek_text = std::to_string(value_tek).c_str();
    if (p->left) QGraphicsLineItem *line_left = scense->addLine(QLineF(x1, y1 + a, x1 - std::pow(2, height_deck(p) - 1) * a, y1 + 2 * a));
    if (p->right) QGraphicsLineItem *line_right = scense->addLine(QLineF(x1 + a, y1 + a, x1 + a + std::pow(2, height_deck(p) - 1) * a, y1 + 2 * a));

    out(p->left, x1 - a - std::pow(2, height_deck(p) - 1) * a, y1 + 2 * a, a);
    out(p->right, x1 + a + std::pow(2, height_deck(p) - 1) * a, y1 + 2 * a, a);
  }
}

void MainWindow::on_pushButton_6_clicked() {
    ui->pushButton_6->setStyleSheet("* { background-color: rgb(60,255,40) }");
    ui->pushButton_7->setStyleSheet("* { background-color: rgb(255, 255, 255) }");
    ui->pushButton_8->setStyleSheet("* { background-color: rgb(255, 255, 255) }");
    flag_avl = true;
    flag_deck = false;
    flag_rand = false;
}

void MainWindow::on_pushButton_7_clicked() {
    ui->pushButton_7->setStyleSheet("* { background-color: rgb(60,255,40) }");
    ui->pushButton_6->setStyleSheet("* { background-color: rgb(255, 255, 255) }");
    ui->pushButton_8->setStyleSheet("* { background-color: rgb(255, 255, 255) }");
    flag_avl = false;
    flag_deck = true;
    flag_rand = false;
}

void MainWindow::on_pushButton_8_clicked() {
    ui->pushButton_8->setStyleSheet("* { background-color: rgb(60,255,40) }");
    ui->pushButton_6->setStyleSheet("* { background-color: rgb(255, 255, 255) }");
    ui->pushButton_7->setStyleSheet("* { background-color: rgb(255, 255, 255) }");
    flag_avl = false;
    flag_deck = false;
    flag_rand = true;

}

void MainWindow::on_pushButton_9_clicked() {

    if (flag_avl) {
        del_tree(root);
        root = nullptr;
    }
    if (flag_deck) {
        tre_del(tree);
    }
    for (QGraphicsItem* it: scense->items()) {
          delete(it);
    }
    scense = new QGraphicsScene(this);
    ui->graphicsView_2->setScene(scense);
}
