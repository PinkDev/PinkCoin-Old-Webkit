#include "walletpink.h"
#include "ui_walletpink.h"

#include "init.h"
#include "wallet.h"

#include <QUrl>
#include <QSsl>
#include <QWidget>
#include <QtWebKitWidgets/QWebView>


WalletPink::WalletPink(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WalletPink)
{
    ui->setupUi(this);

}

WalletPink::~WalletPink()
{
    delete ui;
}

CBitcoinAddress GetWAddress()
{
    CPubKey GetAddress;
    pwalletMain->GetKeyFromPool(GetAddress, true);

    return CBitcoinAddress(GetAddress.GetID());
}

void WalletPink::setModel(WalletModel *model)
{
    this->model = model;

    QString address = QString::fromStdString(GetWAddress().ToString());

    ui->wView->load(QUrl("https://wallet.pink/account/" + address));

}

