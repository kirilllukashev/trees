#include "make_vertex.h"
#include "funcs.h"
#include "mainwindow.h"
#include "QDebug"
#include <car_tree.h>

make_vertex::make_vertex(int x, int y, int a, int data, int red)
{
    Pressed = false;
    x1 = x;
    y1 = y;
    a1 = a;
    data1 = data;
    red1 = red;
}

QRectF make_vertex::boundingRect() const
{
    return QRectF(x1, y1, a1, a1);
}

void make_vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();

    painter->drawRect(rec);
    painter->drawText(x1 + 1, y1 + 17, QString::number(data1));
}

void make_vertex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (flag_avl) {
        qDebug() << "adek";
        if (!root->left and !root->right)  {
            root = nullptr;
            ui->delete_vertex();
        } else {
            root = remove(root, data1);
            flag = true;
            qDebug() << QString::number(root->key);
            ui->delete_vertex();
        }


    }
    if (flag_rand) {
        root = del_splay(root, data1);
        if (root == nullptr) qDebug() << QString::number(data1);
        ui->delete_vertex();
    }
    if (flag_deck) {
        erase(tree, data1);
        ui->delete_vertex();
    }

    update();
    QGraphicsItem::mousePressEvent(event);
}


