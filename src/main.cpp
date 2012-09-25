#include <QApplication>
#include "primon.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  Primon primon;
  primon.show();

  return app.exec();
}


