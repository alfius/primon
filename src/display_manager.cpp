#include "display_manager.h"
#include <stdio.h>

QStringList DisplayManager::listAvailableDisplays()
{
  QStringList result;

  char* command = "xrandr --prop | grep '[^dis]connected' | cut --delimiter=' ' -f1";
  char line[256];
  FILE* fp = popen(command, "r");
  while (fgets(line, 256, fp) != NULL)
  {
    QString qLine = line;
    qLine.remove('\n');
    result << qLine;
  }

  pclose(fp);

  return result;
}

int DisplayManager::setPrimaryDisplay(QString display)
{
  return system("xrandr --output " + display.toLocal8Bit() + " --primary");
}
