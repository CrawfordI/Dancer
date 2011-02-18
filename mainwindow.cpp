#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dancerlist.h"
#include "dancerworkarea.h"

#include <QRect>
#include <QTreeWidget>
#include <QLayout>

#define SIDEBARW 150

DancerWorkArea *workArea;
DancerList *list;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

    workArea = new DancerWorkArea(this);
    list = new DancerList(this);

    resizeDancer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeDancer(){

    list->setGeometry(*(new QRect(0,ui->menuBar->height(),SIDEBARW,height())));
    workArea->setGeometry(*(new QRect(SIDEBARW,ui->menuBar->height(),width()-SIDEBARW,height())));
}

void MainWindow::resizeEvent(QResizeEvent *event){
    resizeDancer();
}
