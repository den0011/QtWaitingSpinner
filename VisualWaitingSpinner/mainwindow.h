#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include "../waitingspinnerwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    WaitingSpinnerWidget * spinner;
    QColor colorSpiner;
    QColorDialog *colorDialog;

private slots:
    void clickedStart() {spinner->start();}
    void clickedStop() {spinner->stop();}
    void clickedColor();

    void valueChangedRoundness(double);
    void valueChangedOpacity(double);
    void valueChangedFadePerc(double);

    void valueChangedLines(int);
    void valueChangedLinesLength(int);
    void valueChangedLineWidth(int);
    void valueChangedInnerRadius(int);
    void valueChangedRevS(int);



};

#endif // MAINWINDOW_H
