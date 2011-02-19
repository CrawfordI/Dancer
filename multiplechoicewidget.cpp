#include "multiplechoicewidget.h"
#include <QMenu>
#include <QPoint>
#include <QAction>

using namespace std;

#define MIN_CHOICES 2

MultipleChoiceWidget::MultipleChoiceWidget(QWidget * parent) : QWidget(parent)
{
  questions = new QList<QRadioButton *>;
  box = new QButtonGroup;
  gridLayoutButtonGroup = new QGridLayout(this);
  gridLayoutButtonGroup->setMargin(0);
  randomizeAnswers = false;
    this->resize(0,0);
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
    //QAction* pItem = pPopup->exec(global);
    pPopup->exec(global);
}

void MultipleChoiceWidget::addButton() {
    QSize newSize = this->size();
    QRadioButton * button = new QRadioButton(tr("Insert Text: New"), this);
    correctButtonSize(button);
    questions->append(button);
    box->addButton(button);
    gridLayoutButtonGroup->addWidget(button);
    if (button->width() > this->width())
        newSize.setWidth(button->width());
    newSize.setHeight(questions->size() * button->height());
    this->resize(newSize);
    button->show();
    this->update();
}

void MultipleChoiceWidget::correctButtonSize(QRadioButton *button){
    QFontMetrics metric(button->font());
    QSize *newButtonSize = new QSize();
    newButtonSize->setWidth(
            metric.width(button->text(),button->text().length()) +
            25 //not the measured value, Qt is retarded...
            );
    newButtonSize->setHeight(max(metric.height(), 13));
    button->resize(*newButtonSize);
}

MultipleChoiceWidget::~MultipleChoiceWidget() {
    delete questions;
    delete box;
}
