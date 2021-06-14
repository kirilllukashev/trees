//#ifndef MAKE_VERTEX_H
//#define MAKE_VERTEX_H


class make_vertex
{
public:
    make_vertex();
};

//#endif // MAKE_VERTEX_H
//#ifndef MAKE_VERTEX_H
#define MAKE_VERTEX_H
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"


class MAKE_VERTEX : public QGraphicsItem
{
public:
    MAKE_VERTEX(int x, int y, int a, int data, int red);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int x1, y1, red1, data1, a1;
    Ui::MainWindow *ui1;
    bool Pressed;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private slots:

};

//#endif // DIGIT_VERTEX_H
