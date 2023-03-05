/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

// #include <QApplication>

// #include "calculator.h"

// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);
//     Calculator calc;
//     calc.show();
//     return app.exec();
// }


#include <opencv2/opencv.hpp>
#include <QtWidgets>

using namespace cv;

// camera widget class
class CameraWidget : public QWidget
{
public:
    CameraWidget(QWidget *parent = nullptr) : QWidget(parent)
    {
        // create a label to display camera stream
        m_label = new QLabel(this);
        m_label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

        // create a layout to position the label and button
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(m_label);

        // create a button to capture images
        QPushButton *button = new QPushButton("Capture", this);
        connect(button, &QPushButton::clicked, this, &CameraWidget::captureImage);
        layout->addWidget(button);
    }

    ~CameraWidget()
    {
        m_cap.release(); // release the camera
    }

    void startCapture()
    {
        m_cap.open(0); // open the default camera
        if (!m_cap.isOpened()) // check if we succeeded
        {
            QMessageBox::warning(this, "Error", "Failed to open camera.");
            return;
        }

        m_timerId = startTimer(30); // start timer to capture frames
    }

    void stopCapture()
    {
        killTimer(m_timerId); // stop timer
        m_cap.release(); // release the camera
    }

protected:
    void timerEvent(QTimerEvent *event) override
    {
        if (event->timerId() == m_timerId)
        {
            Mat frame;
            m_cap >> frame; // get a new frame from camera

            QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
            m_label->setPixmap(QPixmap::fromImage(image.rgbSwapped())); // display the frame in label
        }
    }

    void captureImage()
    {
        Mat frame;
        m_cap >> frame; // get a new frame from camera

        QString fileName = QFileDialog::getSaveFileName(this, "Save Image", ".", "Images (*.png *.jpg *.bmp)");
        if (!fileName.isEmpty())
        {
            imwrite(fileName.toStdString(), frame); // save the image
            QMessageBox::information(this, "Success", "Image saved!");
        }
    }

private:
    QLabel *m_label;
    VideoCapture m_cap;
    int m_timerId;
};

// main function
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // create main window
    QWidget *mainWindow = new QWidget;
    mainWindow->setWindowTitle("Camera Widget");

    // create camera widget
    CameraWidget *cameraWidget = new CameraWidget(mainWindow);
    cameraWidget->startCapture();

    // create layout to position camera widget
    QVBoxLayout *layout = new QVBoxLayout(mainWindow);
    layout->addWidget(cameraWidget);

    mainWindow->show();
    return app.exec();
}
