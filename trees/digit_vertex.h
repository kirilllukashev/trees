#ifndef DIGIT_VERTEX_H
#define DIGIT_VERTEX_H
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"


class digit_vertex : public QGraphicsItem
{
public:
    digit_vertex(int x, int y, int a, int data, int red);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int x1, y1, red1, data1, a1;
    Ui::MainWindow *ui1;
    bool Pressed;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private slots:

    void on_pushButton_5_clicked();
};

#endif // DIGIT_VERTEX_H
