#include "dancerworkarea.h"
#include <QMessageBox>

DancerWorkArea::DancerWorkArea(QWidget *parent) :
    QWidget(parent)
{
    this->setAcceptDrops(true);
}

void DancerWorkArea::dragEnterEvent(QDragEnterEvent *event){
    const QMimeData *mimeData = event->mimeData();
    if(mimeData->hasFormat("application/x-dcomponent")){
        event->setDropAction((Qt::MoveAction));
        event->accept();
    }
    else event->ignore();
}

void DancerWorkArea::dragMoveEvent(QDragMoveEvent *event){
    const QMimeData *mimeData = event->mimeData();
    if(mimeData->hasFormat("application/x-dcomponent")){
        event->setDropAction((Qt::MoveAction));
        event->accept();
    }
    else event->ignore();
}

void DancerWorkArea::dropEvent(QDropEvent *event){
    const QMimeData *mimeData = event->mimeData();
    if(mimeData->hasFormat("application/x-dcomponent")){
        QString componentType;

        QByteArray itemData = mimeData->data("application/x-dcomponent");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        dataStream >> componentType;

        //remove this
        QMessageBox *mBox = new QMessageBox(this);
        QString message = "Attempting to add a ";
        message.append(componentType);
        mBox->setText(message);
        mBox->exec();
        //
    }
    else event->ignore();
}
