#include "primon.h"
#include <stdio.h>
#include "display_manager.h"

Primon::Primon()
{
  QGroupBox *groupBox = createAndPopulateGroupBox();
  QFrame *buttons = createButtons();

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(groupBox);
  layout->addWidget(buttons);

  setLayout(layout);

  setWindowTitle(tr("Primon"));
}

void Primon::setPrimaryDisplay()
{
  for (int i = 0; i < radioButtons.size(); i++)
  {
    if (radioButtons.at(i)->isChecked())
    {
      QString display = radioButtons.at(i)->text();
      DisplayManager::setPrimaryDisplay(display);
    }
  }
}

QGroupBox* Primon::createAndPopulateGroupBox()
{
  QGroupBox *groupBox = new QGroupBox(tr("Displays"));
  QVBoxLayout *groupBoxLayout = new QVBoxLayout();
  QStringList displays = DisplayManager::listAvailableDisplays();
  for (int i = 0; i < displays.size(); i++)
  {
    QRadioButton *radio = new QRadioButton(displays.at(i));
    radioButtons << radio;
    groupBoxLayout->addWidget(radio);
  }
  groupBoxLayout->addStretch(1);
  groupBox->setLayout(groupBoxLayout);

  return groupBox;
}

QFrame* Primon::createButtons()
{
  QFrame *frame = new QFrame();

  QPushButton *setPrimaryDisplayButton = new QPushButton(tr("Set as primary"));
  QPushButton *quitButton = new QPushButton(tr("Quit"));

  QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
  QObject::connect(setPrimaryDisplayButton, SIGNAL(clicked()), SLOT(setPrimaryDisplay()));

  QHBoxLayout *layout = new QHBoxLayout();
  layout->addWidget(setPrimaryDisplayButton);
  layout->addWidget(quitButton);
  frame->setLayout(layout);

  return frame;
}
