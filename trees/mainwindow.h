#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsPolygonItem>
#include <string>
#include <QString>
#include <cmath>
#include <algorithm>
#include "make_vertex.h"
#include <cstdlib>
#include <ctime>
#include <utility>

struct node
{
    int key;
    int height;
    node* left;
    node* right;
    node(int k) { key = k; left = right = 0; height = 1;}
};

struct base {
    int key, prior;
    base* left;
    base* right;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void delete_vertex();

    void preorder(node *p, int x1, int y1, int a);

    void out(base* p, int x1, int y1, int a);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void draw_tree();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scense;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsLineItem *line;

};
extern MainWindow *ui;
#endif // MAINWINDOW_H
