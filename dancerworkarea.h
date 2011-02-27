#ifndef DANCERWORKAREA_H
#define DANCERWORKAREA_H

#include <QWidget>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>

class DancerWorkArea : public QWidget
{
    Q_OBJECT
public:
    explicit DancerWorkArea(QWidget *parent = 0);

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void moveWidgetRequest(const QPoint &, int);

private:
    int numChildren;

private slots:
    void receiveSelectedWidget(int id);
};

#endif // DANCERWORKAREA_H
