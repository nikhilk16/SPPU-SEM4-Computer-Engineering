#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


int sign(int x2,int x1){
    if(x2>x1)   return 1;
    else if(x2<x1)  return -1;
    else    return 0;
}

void MainWindow::on_pushButton_clicked()
{

        QImage image(300, 300, QImage::Format_RGB888);
            QRgb value;

        QString x_1=ui->textEdit->toPlainText();
        QString y_1=ui->textEdit_2->toPlainText();
        QString x_2=ui->textEdit_3->toPlainText();
        QString y_2=ui->textEdit_4->toPlainText();

        int x1=x_1.toInt();
        int y1=y_1.toInt();
        int x2=x_2.toInt();
        int y2=y_2.toInt();

        int dx=abs(x2-x1);
        int dy=abs(y2-y1);
        int s1=sign(x2,x1);
        int s2=sign(y2,y1);

        int interchange=0;

        if(dy>dx){
            int temp=dx;
            dx=dy;
            dy=temp;
            interchange=1;
        }
        else    interchange=0;

        int e=2*dy-dx;
        int x=x1;
        int y=y1;
        for(int i=1;i<=dx;i++){
            value=qRgb(0,255,0);
            image.setPixel(x,y,value);
            while(e>0){
                if(interchange==1)   x=x+s1;
                else    y=y+s2;
                e=e-2*dx;
            }
            if(interchange==1)  y=y+s2;
            else    x=x+s1;
            e=e+2*dy;
        }

        ui->label_5->setPixmap(QPixmap::fromImage(image));
        ui->label_5->show();
}