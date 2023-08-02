#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    spinner = new WaitingSpinnerWidget(ui->groupBoxWait);
    colorSpiner = QColor(81, 4, 71);
    spinner->setColor(colorSpiner);

    colorDialog = new QColorDialog(this);

    spinner->setRoundness(70.0);
    spinner->setMinimumTrailOpacity(15.0);
    spinner->setTrailFadePercentage(70.0);
    spinner->setNumberOfLines(12);
    spinner->setLineLength(10);
    spinner->setLineWidth(5);
    spinner->setInnerRadius(10);
    spinner->setRevolutionsPerSecond(1);
    spinner->setColor(QColor(81, 4, 71));



    connect(ui->pushButtonSTART, SIGNAL (clicked()), this, SLOT (clickedStart()));
    connect(ui->pushButtonSTOP, SIGNAL (clicked()), this, SLOT (clickedStop()));
    connect(ui->pushButtonCOLOR, SIGNAL (clicked()), this, SLOT (clickedColor()));


    connect(ui->doubleSpinBoxRoundness, SIGNAL (valueChanged(double)), this, SLOT (valueChangedRoundness(double)));
    connect(ui->doubleSpinBoxOpacity, SIGNAL (valueChanged(double)), this, SLOT (valueChangedOpacity(double)));
    connect(ui->doubleSpinBoxFadePerc, SIGNAL (valueChanged(double)), this, SLOT (valueChangedFadePerc(double)));

    connect(ui->spinBoxLines, SIGNAL (valueChanged(int)), this, SLOT (valueChangedLines(int)));
    connect(ui->spinBoxLinesLength, SIGNAL (valueChanged(int)), this, SLOT (valueChangedLinesLength(int)));
    connect(ui->spinBoxLineWidth, SIGNAL (valueChanged(int)), this, SLOT (valueChangedLineWidth(int)));
    connect(ui->spinBoxInnerRadius, SIGNAL (valueChanged(int)), this, SLOT (valueChangedInnerRadius(int)));
    connect(ui->spinBoxRevS, SIGNAL (valueChanged(int)), this, SLOT (valueChangedRevS(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::clickedColor()
{
    colorDialog->setCurrentColor(colorSpiner);
    colorDialog->exec();
    colorSpiner = colorDialog->selectedColor();
    spinner->setColor(colorSpiner);
}


void MainWindow::valueChangedRoundness(double set)
{
    spinner->setRoundness(set);
}

void MainWindow::valueChangedOpacity(double set)
{
    spinner->setMinimumTrailOpacity(set);
}

void MainWindow::valueChangedFadePerc(double set)
{
     spinner->setTrailFadePercentage(set);
}

void MainWindow::valueChangedLines(int set)
{
      spinner->setNumberOfLines(set);
}

void MainWindow::valueChangedLinesLength(int set)
{
    spinner->setLineLength(set);
}

void MainWindow::valueChangedLineWidth(int set)
{
    spinner->setLineWidth(set);
}

void MainWindow::valueChangedInnerRadius(int set)
{
    spinner->setInnerRadius(set);
}

void MainWindow::valueChangedRevS(int set)
{
    spinner->setRevolutionsPerSecond(set);
}
