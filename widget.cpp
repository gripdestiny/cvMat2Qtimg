#include "widget.h"
#include "ui_widget.h"
#include "cvmat2qimage.h"
#include "QDebug"
#include "QPixmap"
#include "QSize"
#include "QLabel"
#include "QFileDialog"
cv::Mat image;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString name=QFileDialog::getOpenFileName(this,tr("Opening"),"","Picture(*.jpg *.jpeg *.png);;All files(*)");

    image=cv::imread(name.toStdString());
    cv::cvtColor(image,image,CV_BGR2RGB);
}

void Widget::on_pushButton_2_clicked()
{
    label1=new QLabel();
    QImage im=cvMat2Qimage::mat2image(image);
    //qDebug()<<"done!!";
    label1->resize(QSize(im.width(),im.height()));

    label1->setPixmap(QPixmap::fromImage(im));
    label1->show();
}

void Widget::on_pushButton_3_clicked()
{
    label1->close();
    this->close();
}
