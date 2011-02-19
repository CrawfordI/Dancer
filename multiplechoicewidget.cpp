#include "multiplechoicewidget.h"
#include <QMenu>
#include <QPoint>
#include <QAction>

#define MIN_CHOICES 2

MultipleChoiceWidget::MultipleChoiceWidget(QWidget * parent) : QWidget(parent)
{
  questions = new QList<QRadioButton *>;
  box = new QButtonGroup;
  gridLayoutButtonGroup = new QGridLayout(this);
  randomizeAnswers = false;
  for (int i = 0; i < MIN_CHOICES; i++)
  {
    if(!randomizeAnswers) {
        addButton();
    } else {
        //TODO: RANDOMIZE
    }
  }

  box->setExclusive(true);


}

void MultipleChoiceWidget::mousePressEvent(QMouseEvent *event) {
    //if (event->buttons() & Qt::LeftButton) {
       // dragPosition = event->globalPos() - frameGeometry().topLeft();
         //    event->accept();
         //}
    if (event->buttons() & Qt::RightButton) {
            menuPopup(event->pos());
            event->accept();
    }
}

void MultipleChoiceWidget::menuPopup(const QPoint & point) {
    QPoint global = this->mapToGlobal(point);
    QMenu* pPopup = new QMenu(this);
    QAction* pAction1 = new QAction("Add Button", this);
    QAction* pAction2 = new QAction("Retund?", this);
    pPopup ->addAction(pAction1);
    pPopup ->addAction(pAction2);
    connect(pAction1, SIGNAL(triggered()), this, SLOT(addButton()));
    QAction* pItem = pPopup->exec(global);
}

void MultipleChoiceWidget::addButton() {
    QRadioButton * button = new QRadioButton(tr("Insert Text: New"), this);
    questions->append(button);
    box->addButton(button);
    gridLayoutButtonGroup->addWidget(button);
    if (button->width() > this->width())
       this->resize(this->width(),questions->size()*button->height());
    this->update();
}

MultipleChoiceWidget::~MultipleChoiceWidget() {
    delete questions;
    delete box;
}
