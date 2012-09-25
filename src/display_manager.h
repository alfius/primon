#include <QStringList>

class DisplayManager
{
  public:
    static QStringList listAvailableDisplays();
    static int setPrimaryDisplay(QString display);
};
