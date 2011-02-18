#include "dancerworkarea.h"
#include "multiplechoicewidget.h"

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
        QPoint pos = event->pos();
        QByteArray itemData = mimeData->data("application/x-dcomponent");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        dataStream >> componentType;

        //remove this

        //
        if(componentType == "Multiple Choice"){
           MultipleChoiceWidget *temp = new MultipleChoiceWidget(this);
           temp->setGeometry(*(new QRect(pos.x(),pos.y(),400,100)));
           temp->show();
        }

    }
    else event->ignore();
}
