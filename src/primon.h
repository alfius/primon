#include <QtGui>

class Primon : public QWidget
{
  Q_OBJECT

public:
  Primon();

private slots:
  void setPrimaryDisplay();

private:
  QList<QRadioButton*> radioButtons;

  QGroupBox* createAndPopulateGroupBox();
  QFrame* createButtons();
};
