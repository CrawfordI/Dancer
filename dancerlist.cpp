#include "dancerlist.h"

#include <QPoint>
#include <QMimeData>

DancerList::DancerList(QWidget *parent) :
    QListWidget(parent)
{    
    QListWidgetItem *multiChoice = new QListWidgetItem("Multiple Choice", this);
}

void DancerList::mousePressEvent(QMouseEvent *event){
    QPoint pos = event->pos();
    QListWidgetItem *target = this->itemAt(pos);
    if(!target)
        return;
    QMimeData *mimeData = new QMimeData;
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    const QString dataString= target->text();
    dataStream << dataString;

    mimeData->setData("application/x-dcomponent",itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);

    drag->exec(Qt::MoveAction,Qt::MoveAction);
 }
