#include "CamWidget.h"

#include <QVBoxLayout>
#include <QMessageBox>
#include <QPixmap>

 
void detectEyes(cv::Mat &image){
    std::vector<cv::Rect> eyes;
    cv::CascadeClassifier eye_cascade("C://Users//hovha//ACA//PhotoFilter//haarcascade_eye.xml");
    eye_cascade.detectMultiScale(image, eyes, 1.1, 5);
    if(eyes.size() < 2){
        return;
    }
    cv::Mat eye1, eye2;

        for(int i = eyes[0].y + eyes[0].height/2 - eyes[0].height/6; i <= eyes[0].y + eyes[0].height/2 + eyes[0].height/6; i++){
            for(int j = eyes[0].x + eyes[0].width/2 - eyes[0].width/6; j <= eyes[0].x + eyes[0].width/2 + eyes[0].width/6; j++){
            image.at<cv::Vec3b>(i, j)[0] /= 3;
            // image.at<Vec3b>(i, j)[1] /= 3;
            }
    }
        for(int i = eyes[1].y + eyes[1].height/2 - eyes[1].height/6; i <= eyes[1].y + eyes[1].height/2 + eyes[1].height/6; i++){
            for(int j = eyes[1].x + eyes[1].width/2 - eyes[1].width/6; j <= eyes[1].x + eyes[1].width/2 + eyes[1].width/6; j++){
                image.at<cv::Vec3b>(i, j)[0] /= 3;
                // image.at<Vec3b>(i, j)[1] /= 3;
            }
    }
}






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
        connect(button, &QPushButton::clicked, this, &CamWidget::captureImage);
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

void CamWidget::captureImage()
{
    QPixmap black_pixmap(m_label->size());
    black_pixmap.fill(QColor("black"));
    m_label->setPixmap(black_pixmap);
    isActive=false;
}

void CamWidget::timerEvent(QTimerEvent *event) 
{
    if (event->timerId() == m_timerId)
    {
        cv::Mat frame;
        m_cap >> frame; // get a new frame from camera
        detectEyes(frame);
        QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
        m_label->setPixmap(QPixmap::fromImage(image.rgbSwapped())); // display the frame in label
    }
    if(!isActive)
        killTimer(m_timerId); 
} 



