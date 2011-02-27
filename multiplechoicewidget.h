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
     MultipleChoiceWidget(QWidget *parent = 0, int id = 0);
    ~MultipleChoiceWidget();

protected:
    void mousePressEvent(QMouseEvent *event);
    void menuPopup(const QPoint & point);

signals:
    void selectedWidget(int);

private:
    QList<QRadioButton *> * questions;
    QButtonGroup * box;
    QGridLayout  * gridLayoutButtonGroup;
    int id;
    int answer;
    bool randomizeAnswers;
    void correctButtonSize(QRadioButton *button);

private slots:
    void addButton();
  //void removeButton();
    void moveWidget(const QPoint & point, int id);
};

#endif // MULTIPLECHOICEWIDGET_H
