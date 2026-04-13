#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

#include "ExpressionParser.h"
#include "HistoryManager.h"
#include "AdvancedCalculator.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void appendText();
    void appendOperator();
    void calculateResult();
    void clearExpression();
    void clearHistory();
    void applySine();
    void applyCosine();
    void applyLog();
    void applySqrt();

private:
    QLineEdit *expressionInput;
    QLabel *resultLabel;
    QListWidget *historyList;

    ExpressionParser parser;
    HistoryManager historyManager;
    AdvancedCalculator advancedCalc;

    void updateHistoryDisplay();
    void addHistoryEntry(const QString& entry);
};

#endif
