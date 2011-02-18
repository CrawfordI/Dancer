#include "multiplechoicewidget.h"
#include <QMenu>
#include <QPoint>
#include <QAction>

MultipleChoiceWidget::MultipleChoiceWidget(QWidget * parent) : QWidget(parent)
{
  QRadioButton * b1 = new QRadioButton(tr("Insert Text1"), this);
  QRadioButton * b2 = new QRadioButton(tr("Insert Text2"), this);
  QRadioButton * b3 = new QRadioButton(tr("Insert Text3"), this);

  questions = new QList<QRadioButton *>;
  box = new QButtonGroup;
  gridLayoutButtonGroup = new QGridLayout(this);
  randomizeAnswers = false;

  questions->append(b1);
  questions->append(b2);
  questions->append(b3);

  for (int i = 0; i < questions->size(); i++)
  {
    if(!randomizeAnswers) {
        box->addButton(questions->at(i));
    } else {
        //TODO: RANDOMIZE
    }
    gridLayoutButtonGroup->addWidget(questions->at(i));
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
    this->resize(130,150); //do a correct resize based on items...
    this->update();
}

MultipleChoiceWidget::~MultipleChoiceWidget() {
    delete questions;
    delete box;
}
