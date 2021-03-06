#include "BaiduMapView.h"
#include <QtWebChannel>
#include <QtWebEngineWidgets>

BaiduMapView::BaiduMapView(QWidget *parent)
	: QWebEngineView(parent)
{
	QWebChannel *channel = new QWebChannel(this);
	channel->registerObject("bridge", this);
	this->page()->setWebChannel(channel);
	this->settings()->setDefaultTextEncoding("UTF-8");

	QString strMapPath = "http://127.0.0.1/";
	strMapPath += "baidumap/main.html";
	QUrl url(strMapPath);
	this->page()->load(url);
	this->triggerPageAction(QWebEnginePage::Reload, true);

	this->setMouseTracking(true);
}

BaiduMapView::~BaiduMapView()
{
	this->page()->webChannel()->deregisterObject(this);

}

void BaiduMapView::mouseMoved(qreal longitude, qreal latitude)
{
	emit signalMouseMoved(longitude, latitude);
}

