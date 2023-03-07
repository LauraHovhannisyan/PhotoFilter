#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimerEvent>
#include <QResizeEvent>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>


class CamWidget:public QWidget
{
    Q_OBJECT
public:
    explicit CamWidget(QWidget *parent=nullptr);
    ~CamWidget();

    QLabel *m_label;
    cv::VideoCapture m_cap;
    int m_timerId;
    bool isActive=true;

    void timerEvent(QTimerEvent* event);

private:
    void startCapture();
    void captureImage();
};
#endif