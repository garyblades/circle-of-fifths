// This class draws a circle of fifths chart

#include "chart.h"

#include <math.h>

#include <QPainter>

#define SIZE   570
#define MARGIN  23

// Initialize the instance

Chart::Chart(QWidget *parent) : QWidget(parent)
{
  setWindowTitle("Circle of Fifths");
  setGeometry(300,300, SIZE,SIZE);
}

void Chart::paintEvent(QPaintEvent*)
{
  QPainter painter(this);

  int W = width();
  int H = height();

  int x0 = W / 2;
  int y0 = H / 2;

  int w = W - 2*MARGIN;
  int h = H - 2*MARGIN;

  int r2 = w/2;
  if (h < w) r2 = h/2;

  int r1 = r2 - 100;

  painter.drawEllipse(QPoint(x0,y0), r1, r1);
  painter.drawEllipse(QPoint(x0,y0), r2, r2);

  float delta = 360 / 12;
  float theta = delta / 2;

  #define DEG2RAD (3.14159 / 180.)

  for (int i=0; i<12; i++)
  {
    int x1 = x0 + r1 * cos(DEG2RAD*theta);
    int y1 = y0 + r1 * sin(DEG2RAD*theta);
    int x2 = x0 + r2 * cos(DEG2RAD*theta);
    int y2 = y0 + r2 * sin(DEG2RAD*theta);
    painter.drawLine(x1,y1, x2,y2);
    theta += delta;
  }

}
