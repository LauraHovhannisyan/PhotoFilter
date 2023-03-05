// #include <opencv2/opencv.hpp>
// #include <QtWidgets>
// using namespace cv;

// // camera widget class
// class CameraWidget : public QWidget
// {
// public:
//     CameraWidget(QWidget *parent = nullptr) : QWidget(parent)
//     {
//         // create a label to display camera stream
//         m_label = new QLabel(this);
//         m_label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

//         // create a layout to position the label and button
//         QVBoxLayout *layout = new QVBoxLayout(this);
//         layout->addWidget(m_label);

//         // create a button to capture images
//         QPushButton *button = new QPushButton("Capture", this);
//         connect(button, &QPushButton::clicked, this, &CameraWidget::captureImage);
//         layout->addWidget(button);
//     }

//     ~CameraWidget()
//     {
//         m_cap.release(); // release the camera
//     }

//     void startCapture()
//     {
//         m_cap.open(0); // open the default camera
//         if (!m_cap.isOpened()) // check if we succeeded
//         {
//             QMessageBox::warning(this, "Error", "Failed to open camera.");
//             return;
//         }

//         m_timerId = startTimer(30); // start timer to capture frames
//     }

//     void stopCapture()
//     {
//         killTimer(m_timerId); // stop timer
//         m_cap.release(); // release the camera
//     }

// protected:
//     void timerEvent(QTimerEvent *event) override
//     {
//         if (event->timerId() == m_timerId)
//         {
//             Mat frame;
//             m_cap >> frame; // get a new frame from camera

//             QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
//             m_label->setPixmap(QPixmap::fromImage(image.rgbSwapped())); // display the frame in label
//         }
//     }

//     void captureImage()
//     {
//         Mat frame;
//         m_cap >> frame; // get a new frame from camera

//         QString fileName = QFileDialog::getSaveFileName(this, "Save Image", ".", "Images (*.png *.jpg *.bmp)");
//         if (!fileName.isEmpty())
//         {
//             imwrite(fileName.toStdString(), frame); // save the image
//             QMessageBox::information(this, "Success", "Image saved!");
//         }
//     }

// private:
//     QLabel *m_label;
//     VideoCapture m_cap;
//     int m_timerId;
// };

// // main function
// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);

//     // create main window
//     QWidget *mainWindow = new QWidget;
//     mainWindow->setWindowTitle("Camera Widget");

//     // create camera widget
//     CameraWidget *cameraWidget = new CameraWidget(mainWindow);
//     cameraWidget->startCapture();

//     // create layout to position camera widget
//     QVBoxLayout *layout = new QVBoxLayout(mainWindow);
//     layout->addWidget(cameraWidget);

//     mainWindow->show();
//     return app.exec();
// }

#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    MainWindow w;
    w.show();
    return a.exec();
}
