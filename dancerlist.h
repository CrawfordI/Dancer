#ifndef DANCERLIST_H
#define DANCERLIST_H

#include <QListWidget>
#include <QMouseEvent>

class DancerList : public QListWidget
{
    Q_OBJECT
public:
    explicit DancerList(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:

};

#endif // DANCERLIST_H
