#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    std::srand(std::time(nullptr));
    secret_number = std::rand() % 10 + 1;
    qDebug() << "Secret Number Generated: " << QString::number(secret_number);

    ui->startOverButton->setDisabled(true);
    ui->messageLabel->setText("");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_guessButton_clicked()
{
    guess_number = ui->numberSpinBox->value();
    qDebug() << "User Gussed: " << QString::number(guess_number);

    if(guess_number > secret_number) {
        ui->messageLabel->setText("Your Guess Is Too High!");
    } else if (guess_number < secret_number) {
        ui->messageLabel->setText("Your Guess Is Too Low!");
    } else {
        ui->messageLabel->setText("You Guessesd the number!");
        ui->startOverButton->setDisabled(false);
    }
}


void Widget::on_startOverButton_clicked()
{
    qDebug() << "Start Over Button Clicked";
    ui->messageLabel->setText("");
    secret_number = std::rand() % 10 + 1;
    qDebug() << "Secret Number Generated: " << QString::number(secret_number);
    ui->numberSpinBox->setValue(0);

}

