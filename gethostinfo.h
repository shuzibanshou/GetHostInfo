#ifndef GETHOSTINFO_H
#define GETHOSTINFO_H

#include <QDialog>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QDebug>

namespace Ui {
class GetHostInfo;
}

class GetHostInfo : public QDialog
{
    Q_OBJECT

public:
    explicit GetHostInfo(QWidget *parent = 0);
    ~GetHostInfo();

private slots:
    //点击查询主机信息槽函数
    void on_getHostInfo_clicked();
    //点击反查域名ip槽函数
    void on_getDomainInfo_clicked();
    //反查域名ip的异步槽函数
    void async_lookupHost(QHostInfo);
    //获取网卡信息
    void on_getNetwork1_clicked();
    //点击查询主机信息槽函数-会显示环回地址
    void on_getNetwork2_clicked();

private:
    Ui::GetHostInfo *ui;
    //将协议枚举值映射成字符串
    QString showProtocolName(QAbstractSocket::NetworkLayerProtocol);
};

#endif // GETHOSTINFO_H
