#ifndef MULTIPLECHOICEWIDGET_H
#define MULTIPLECHOICEWIDGET_H

#include <QRadioButton>
#include <QButtonGroup>
#include <QList>
#include <QWidget>
#include <QGridLayout>
#include <QMouseEvent>

class MultipleChoiceWidget : public QWidget
{
    Q_OBJECT

public:
     MultipleChoiceWidget(QWidget *parent = 0);
    ~MultipleChoiceWidget();

protected:
    void mousePressEvent(QMouseEvent *event);
    void menuPopup(const QPoint & point);

//signals:
//    void currentButtonsChanged(MultipleChoiceWidget mcw);

private:
    QList<QRadioButton *> * questions;
    QButtonGroup * box;
    QGridLayout  * gridLayoutButtonGroup;
    int answer;
    bool randomizeAnswers;


private slots:
    void addButton();
//    void removeButton();
};

#endif // MULTIPLECHOICEWIDGET_H
