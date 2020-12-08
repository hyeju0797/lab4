#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class QTcpSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void readyRead(); //서버로부터 메시지가 온 경우
    void connected(); //서버에게 연결되었다고 알림
    void on_connectButton_clicked(); //연결 버튼 클릭
    void on_sendButton_clicked(); //채팅 메세지 전송 버튼을 클릭
    void on_messageLineEdit_returnPressed();

private:
    Ui::Widget *ui;
    QTcpSocket* socket;
    time_t ct;
    struct tm tm;
    char strTime[50];
};
#endif // WIDGET_H


