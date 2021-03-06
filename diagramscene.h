﻿#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QObject>
#include "rectitem.h"
#include "lineitem.h"
#include "textitem.h"
#include "mainwindow.h"
#include "ellipseitem.h"
#include "pixitem.h"
#include "arrowitem.h"

//#include "mysql.h"

#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
class QGraphicsPolygonItem;
class QGraphicsScene;
class QGraphicsSceneMouseEvent;
class QPaintEvent;
class QPointF;
class QWidget;
QT_END_NAMESPACE



class DiagramScene : public QGraphicsScene
{
    Q_OBJECT

public:
    enum Mode { InsertCircleItem , InsertRectItem , InsertLineItem , InsertTextItem, InsertPixItem, InsertArrowItem, MoveItem};
    DiagramScene(QObject *parent = 0);

    //QList<PixItem*> myPixList;
    QMap<QString,PixItem*> myPixMap;

    void setMode(Mode mode );
    void setStartPoint(QPointF point);
    void setItemColor(const QColor &color);
    void setLineColor(const QColor &color);
    void setLineWidth(const int width);
    void setTextColor(const QColor &color);
    void setFont(const QFont &font);
    QFont font() const
        { return myTextFont; }
    GroupItem *myCreatItemGroup(const QList<QGraphicsItem *> &items);
    void myDestroyItemGroup(GroupItem *group);

public:
    int arrowType;
    double numDegrees;
    void wheelEvent(QGraphicsSceneWheelEvent *event);

public slots:
    void cut();
    void copy();
    void paste();


    bool writeFile(QFile &file);
    bool readFile(QFile &file);
    void editorLostFocus(TextItem *item);
signals:
    void itemSelected(QGraphicsItem *item);
    void wheelChanged(double num);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
    bool isItemChange(int type);

    QColor myItemColor;
    QColor myLineColor;
    int myLineWidth;
    EllipseItem *circle;
    RectItem *Rect;
    LineItem *line;
    TextItem *textItem;

    PixItem *pixItem;
    QPixmap *pixmap;
    ArrowItem *arrow;

    QPointF startPoint;
    Mode myMode;
    QColor myTextColor;
    QFont myTextFont;

    QString code;
    QString name;

    QPen myPen;
//signals:
    //void itemMoved(DiagramItem *movedItem,const QPointF &movedFromPosition);

};
#endif // DIAGRAMSCENE_H
