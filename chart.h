#ifndef CHART_H
#define CHART_H

#include <QWidget>

class QPaintEvent;

class Chart : public QWidget
{
Q_OBJECT

public:

  Chart(QWidget *parent=0);

protected:

  virtual void paintEvent(QPaintEvent*);

private:

};

#endif // CHART_H
