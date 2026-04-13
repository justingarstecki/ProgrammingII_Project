#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>

#include "ExpressionParser.h"
#include "HistoryManager.h"
#include "AdvancedCalculator.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void numberClicked();
    void operatorClicked();
    void calculateClicked();
    void clearClicked();
    void clearHistoryClicked();
    void sinClicked();
    void cosClicked();
    void logClicked();
    void sqrtClicked();

private:
    QLineEdit *input;
    QLabel *result;
    QListWidget *historyBox;

    ExpressionParser parser;
    HistoryManager history;
    AdvancedCalculator advCalc;
};

#endif
