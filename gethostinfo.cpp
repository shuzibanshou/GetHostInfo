#include "gethostinfo.h"
#include "ui_gethostinfo.h"

GetHostInfo::GetHostInfo(QWidget *parent) :QDialog(parent),ui(new Ui::GetHostInfo)
{
    ui->setupUi(this);
}

GetHostInfo::~GetHostInfo()
{
    delete ui;
}

void GetHostInfo::on_getHostInfo_clicked()
{
    //清空内容
    ui->content->clear();
    //获取主机名
    QString hostname = QHostInfo::localHostName();
    ui->content->append("本地主机名为:"+hostname);
    //获取主机信息
    QHostInfo qHostInfo = QHostInfo::fromName(hostname);
    //取出地址信息
    QList<QHostAddress> addrList = qHostInfo.addresses();
    if(addrList.isEmpty()){
        //没有获取到任何地址信息 直接返回
        return;
    } else {
        int addrListLength = addrList.size();
        if(ui->showIPv4->isChecked()){
            for(int i = 0; i < addrListLength; i++){
                if(addrList[i].protocol() == QAbstractSocket::IPv4Protocol){
                    //qDebug("QAbstractSocket::IPv4Protocol");
                    ui->content->append("IP地址:"+addrList[i].toString()+"\t协议为:"+showProtocolName(addrList[i].protocol()));
                }
            }
        } else {
            for(int i = 0; i < addrListLength; i++){
                ui->content->append("IP地址:"+addrList[i].toString()+"\t协议为:"+showProtocolName(addrList[i].protocol()));
            }
        }

    }
}

QString GetHostInfo::showProtocolName(QAbstractSocket::NetworkLayerProtocol protocol)
{
    switch(protocol){
        case QAbstractSocket::IPv4Protocol:
            return "IPv4";
        case QAbstractSocket::IPv6Protocol:
            return "IPv6";
        case QAbstractSocket::AnyIPProtocol:
            return "AnyIP";
        case QAbstractSocket::UnknownNetworkLayerProtocol:
            return "UnknownNetwork";
        default:
            return "UnknownNetwork";
    }
}


void GetHostInfo::on_getDomainInfo_clicked()
{
    //清空内容
    ui->content->clear();
    QString domain = ui->domain->text();
    ui->content->append("正在查询的域名:"+domain);
    QHostInfo::lookupHost(domain,this,SLOT(async_lookupHost(QHostInfo)));
}

void GetHostInfo::async_lookupHost(QHostInfo host)
{
    QList<QHostAddress> addrList = host.addresses();
    if(addrList.isEmpty()){
        //没有获取到任何地址信息 直接返回
        return;
    } else {
        int addrListLength = addrList.size();
        if(ui->showIPv4->isChecked()){
            for(int i = 0; i < addrListLength; i++){
                if(addrList[i].protocol() == QAbstractSocket::IPv4Protocol){
                    //qDebug("QAbstractSocket::IPv4Protocol");
                    ui->content->append("IP地址:"+addrList[i].toString()+"\t协议为:"+showProtocolName(addrList[i].protocol()));
                }
            }
        } else {
            for(int i = 0; i < addrListLength; i++){
                ui->content->append("IP地址:"+addrList[i].toString()+"\t协议为:"+showProtocolName(addrList[i].protocol()));
            }
        }
    }
}

void GetHostInfo::on_getNetwork1_clicked()
{
    //清空内容
    ui->content->clear();
    QList<QNetworkInterface> interfaceList = QNetworkInterface::allInterfaces();
    foreach(auto interface,interfaceList){
        if(interface.isValid()){
            ui->content->append("设备名称:"+interface.humanReadableName()+"\tMAC地址:"+interface.hardwareAddress());
            QList<QNetworkAddressEntry> entriesList = interface.addressEntries();
            for(int i = 0; i < entriesList.size(); i++ ){
                ui->content->append("IP地址:"+entriesList[i].ip().toString());
                ui->content->append("子网掩码:"+entriesList[i].netmask().toString()+"\t广播地址:"+entriesList[i].broadcast().toString());
                ui->content->append("");
            }
        }
        ui->content->append("------------------------------------------------------------");
    }
}

void GetHostInfo::on_getNetwork2_clicked()
{
    //清空内容
    ui->content->clear();
    QList<QHostAddress> addrList = QNetworkInterface::allAddresses();
    if(addrList.isEmpty()){
        //没有获取到任何地址信息 直接返回
        return;
    } else {
        int addrListLength = addrList.size();
        if(ui->showIPv4->isChecked()){
            for(int i = 0; i < addrListLength; i++){
                if(addrList[i].protocol() == QAbstractSocket::IPv4Protocol){
                    //qDebug("QAbstractSocket::IPv4Protocol");
                    ui->content->append("IP地址:"+addrList[i].toString()+"\t协议为:"+showProtocolName(addrList[i].protocol()));
                }
            }
        } else {
            for(int i = 0; i < addrListLength; i++){
                ui->content->append("IP地址:"+addrList[i].toString()+"\t协议为:"+showProtocolName(addrList[i].protocol()));
            }
        }
    }
}
