#include "CamWidget.h"

#include <QVBoxLayout>
#include <QMessageBox>

CamWidget::CamWidget(QWidget *parent)
    :QWidget{parent}
{
        startCapture();

       // create a label to display camera stream
        m_label = new QLabel(this);
        m_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        m_label->setAlignment(Qt::AlignCenter);
        
        // create a layout to position the label and button
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(m_label);

        // create a button to capture images
        QPushButton *button = new QPushButton("Chxk", this);
        //connect(button, &QPushButton::clicked, this, &CameraWidget::captureImage);
        layout->addWidget(button);
}

CamWidget::~CamWidget()
{
    m_cap.release(); // release the camera
}


void CamWidget::startCapture()
{
    m_cap.open(0); // open the default camera
    if (!m_cap.isOpened()) // check if we succeeded
    {
        QMessageBox::warning(this, "Error", "Failed to open camera.");
        return;
    }

    m_timerId = startTimer(30); // start timer to capture frames
}


void CamWidget::timerEvent(QTimerEvent *event) 
{
    if (event->timerId() == m_timerId)
    {
        cv::Mat frame;
        m_cap >> frame; // get a new frame from camera

        QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
        m_label->setPixmap(QPixmap::fromImage(image.rgbSwapped())); // display the frame in label
    }
} 



