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

signals:

public slots:

};

#endif // DANCERWORKAREA_H
