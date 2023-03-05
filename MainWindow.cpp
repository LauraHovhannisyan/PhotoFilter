#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    setWindowTitle("Photo Filter");
    resize(500,500);
    camWidget=new CamWidget;
    setCentralWidget(camWidget);
}

MainWindow::~MainWindow()
{
}