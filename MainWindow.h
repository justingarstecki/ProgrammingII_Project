#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>

#include "ExpressionParser.h"
#include "HistoryManager.h"
#include "AdvancedCalculator.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void buttonClicked();
    void operatorClicked();
    void calculate();
    void clearInput();
    void clearHistory();
    void doSin();
    void doCos();
    void doLog();
    void doSqrt();

private:
    QLineEdit *inputBox;
    QLabel *resultLabel;
    QListWidget *historyList;

    ExpressionParser parser;
    HistoryManager history;
    AdvancedCalculator calc;
};

#endif
