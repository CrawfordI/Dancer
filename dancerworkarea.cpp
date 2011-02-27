#include "dancerworkarea.h"
#include "multiplechoicewidget.h"
#include <QMenu>
#include <QMessageBox>

DancerWorkArea::DancerWorkArea(QWidget *parent) :
    QWidget(parent)
{
    this->setAcceptDrops(true);
    numChildren=0;
}

void DancerWorkArea::dragEnterEvent(QDragEnterEvent *event){
   /* const QMimeData *mimeData = event->mimeData();
    if(mimeData->hasFormat("application/x-dcomponent")){
        event->setDropAction((Qt::MoveAction));
        event->accept();
    }
    else event->ignore();*/
    event->acceptProposedAction();
}

void DancerWorkArea::dragMoveEvent(QDragMoveEvent *event){
    /*const QMimeData *mimeData = event->mimeData();
    if(mimeData->hasFormat("application/x-dcomponent")){
        event->setDropAction((Qt::MoveAction));
        event->accept();
    }
    else event->ignore();*/
    event->acceptProposedAction();
}

void DancerWorkArea::dropEvent(QDropEvent *event){
    const QMimeData *mimeData = event->mimeData();
    if(mimeData->hasFormat("application/x-dcomponent")){
        QString componentType;
        QByteArray itemData = mimeData->data("application/x-dcomponent");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        dataStream >> componentType;

        if(componentType == "Multiple Choice"){
           MultipleChoiceWidget *temp = new MultipleChoiceWidget(this, numChildren);
           temp->setGeometry( *(new QRect(event->pos(),temp->size())));
           temp->show();
           connect(temp,SIGNAL(selectedWidget(int)), this, SLOT(receiveSelectedWidget(int)));
           numChildren++;
        }
    }
    else if (mimeData->hasFormat("application/x-dwidget")) {
        emit moveWidgetRequest(event->pos(),mimeData->text());
    }
    else event->ignore();
}

void DancerWorkArea::mousePressEvent(QMouseEvent *event){
    /*
    QPoint pos = event->pos();
    QWidget *target = this->childAt(pos);
    if(!target)
        return;
    */
 }

void DancerWorkArea::receiveSelectedWidget(int id) {
    QMimeData* mimeData = new QMimeData;
    mimeData->setText(QString::number(id));
    mimeData->setData("application/x-dwidget", "Movement");
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    //drag->exec();
    drag->exec(Qt::MoveAction,Qt::MoveAction);
}
