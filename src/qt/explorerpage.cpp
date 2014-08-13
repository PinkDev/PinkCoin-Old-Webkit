#include "explorerpage.h"
#include "ui_explorerpage.h"

#include <QUrl>
#include <QSsl>
#include <QWidget>
#include <QtWebKitWidgets/QWebView>
#include <QFile>
#include <QtWebKit>
#include <QWebFrame>

ExplorerPage::ExplorerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExplorerPage)
{
    ui->setupUi(this);
    // QWebView *view = new QWebView(ui->xView);
    ui->xView->load(QUrl("http://chainz.cryptoid.info/pc/"));
    QEventLoop loop;
    connect(ui->xView,SIGNAL(loadFinished(bool)),&loop,SLOT(quit()));
    loop.exec();
    QWebFrame *frame = ui->xView->page()->mainFrame();
    QWebElement document = frame->documentElement();
    QWebElement element = document.findFirst("body");
    element.setAttribute("style", "background-color: #302F2F;color: #dd37b6;");
    element = document.findFirst(".navbar");
    element.setAttribute("style", "display: none;");
    //QWebElementCollection elements = document.findAll("a");
    //foreach(QWebElement item,elements){
    //    item.setAttribute("style", "color: #dd37b6;");
    //}
    QWebElementCollection elements = document.findAll("iframe");
    foreach(QWebElement item,elements){
        item.setAttribute("style", "display: none;");
    }
}

ExplorerPage::~ExplorerPage()
{
    delete ui;
}

void ExplorerPage::setModel(WalletModel *model)
{
    this->model = model;
}
