#pragma once

#include <QWidget>
namespace Ui { class LongLatLabel; };

class AbstractMapHandle;

class LongLatLabel : public QWidget
{
	Q_OBJECT

public:
	LongLatLabel(AbstractMapHandle *mapHandle, QWidget *parent = nullptr);
	~LongLatLabel();

	void set(qreal longitude, qreal latitude);

protected:
	virtual bool eventFilter(QObject *, QEvent *);

private:
	Ui::LongLatLabel	*	ui			= nullptr;
	AbstractMapHandle	*	m_mapHandle = nullptr;
};
