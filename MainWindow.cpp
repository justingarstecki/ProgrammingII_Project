#include "MainWindow.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QString>
#include <exception>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Calculator");
    resize(400, 500);

    inputBox = new QLineEdit();
    inputBox->setPlaceholderText("Enter expression like 2 + 3");

    resultLabel = new QLabel("Result: ");
    historyList = new QListWidget();

    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addWidget(inputBox);
    mainLayout->addWidget(resultLabel);

    QGridLayout *grid = new QGridLayout();

    QPushButton *b7 = new QPushButton("7");
    QPushButton *b8 = new QPushButton("8");
    QPushButton *b9 = new QPushButton("9");
    QPushButton *bDiv = new QPushButton("/");

    QPushButton *b4 = new QPushButton("4");
    QPushButton *b5 = new QPushButton("5");
    QPushButton *b6 = new QPushButton("6");
    QPushButton *bMul = new QPushButton("*");

    QPushButton *b1 = new QPushButton("1");
    QPushButton *b2 = new QPushButton("2");
    QPushButton *b3 = new QPushButton("3");
    QPushButton *bSub = new QPushButton("-");

    QPushButton *b0 = new QPushButton("0");
    QPushButton *bDot = new QPushButton(".");
    QPushButton *bClear = new QPushButton("C");
    QPushButton *bAdd = new QPushButton("+");

    grid->addWidget(b7, 0, 0);
    grid->addWidget(b8, 0, 1);
    grid->addWidget(b9, 0, 2);
    grid->addWidget(bDiv, 0, 3);

    grid->addWidget(b4, 1, 0);
    grid->addWidget(b5, 1, 1);
    grid->addWidget(b6, 1, 2);
    grid->addWidget(bMul, 1, 3);

    grid->addWidget(b1, 2, 0);
    grid->addWidget(b2, 2, 1);
    grid->addWidget(b3, 2, 2);
    grid->addWidget(bSub, 2, 3);

    grid->addWidget(b0, 3, 0);
    grid->addWidget(bDot, 3, 1);
    grid->addWidget(bClear, 3, 2);
    grid->addWidget(bAdd, 3, 3);

    mainLayout->addLayout(grid);

    connect(b0, &QPushButton::clicked, this, &MainWindow::buttonClicked);
    connect(b1, &QPushButton::clicked, this, &MainWindow::buttonClicked);
    connect(b2, &QPushButton::clicked, this, &MainWindow::buttonClicked);
    connect(b3, &QPushButton::clicked, this, &MainWindow::buttonClicked);
    connect(b4, &QPushButton::clicked, this, &MainWindow::buttonClicked);
    connect(b5, &QPushButton::clicked, this, &MainWindow::buttonClicked);
    connect(b6, &QPushButton::clicked, this, &MainWindow::buttonClicked);
    connect(b7, &QPushButton::clicked, this, &MainWindow::buttonClicked);
    connect(b8, &QPushButton::clicked, this, &MainWindow::buttonClicked);
    connect(b9, &QPushButton::clicked, this, &MainWindow::buttonClicked);
    connect(bDot, &QPushButton::clicked, this, &MainWindow::buttonClicked);

    connect(bAdd, &QPushButton::clicked, this, &MainWindow::operatorClicked);
    connect(bSub, &QPushButton::clicked, this, &MainWindow::operatorClicked);
    connect(bMul, &QPushButton::clicked, this, &MainWindow::operatorClicked);
    connect(bDiv, &QPushButton::clicked, this, &MainWindow::operatorClicked);

    connect(bClear, &QPushButton::clicked, this, &MainWindow::clearInput);

    QHBoxLayout *row = new QHBoxLayout();

    QPushButton *equalButton = new QPushButton("Calculate");
    QPushButton *sinButton = new QPushButton("sin");
    QPushButton *cosButton = new QPushButton("cos");
    QPushButton *logButton = new QPushButton("log");
    QPushButton *sqrtButton = new QPushButton("sqrt");

    row->addWidget(equalButton);
    row->addWidget(sinButton);
    row->addWidget(cosButton);
    row->addWidget(logButton);
    row->addWidget(sqrtButton);

    connect(equalButton, &QPushButton::clicked, this, &MainWindow::calculate);
    connect(sinButton, &QPushButton::clicked, this, &MainWindow::doSin);
    connect(cosButton, &QPushButton::clicked, this, &MainWindow::doCos);
    connect(logButton, &QPushButton::clicked, this, &MainWindow::doLog);
    connect(sqrtButton, &QPushButton::clicked, this, &MainWindow::doSqrt);

    mainLayout->addLayout(row);

    mainLayout->addWidget(historyList);

    QPushButton *clearHistoryButton = new QPushButton("Clear History");
    connect(clearHistoryButton, &QPushButton::clicked, this, &MainWindow::clearHistory);
    mainLayout->addWidget(clearHistoryButton);

    setLayout(mainLayout);
}

void MainWindow::buttonClicked()
{
    QPushButton *button = (QPushButton*)sender();
    inputBox->setText(inputBox->text() + button->text());
}

void MainWindow::operatorClicked()
{
    QPushButton *button = (QPushButton*)sender();
    inputBox->setText(inputBox->text() + " " + button->text() + " ");
}

void MainWindow::calculate()
{
    try
    {
        parser.setExpression(inputBox->text().toStdString());
        double answer = parser.evaluateExpression();

        QString resultText = QString::number(answer);
        resultLabel->setText("Result: " + resultText);

        QString historyText = inputBox->text() + " = " + resultText;
        history.addEntry(historyText.toStdString());
        historyList->addItem(historyText);
    }
    catch (const std::exception &e)
    {
        resultLabel->setText(QString("Error: ") + e.what());
    }
}

void MainWindow::clearInput()
{
    inputBox->clear();
    resultLabel->setText("Result: ");
}

void MainWindow::clearHistory()
{
    history.clearHistory();
    historyList->clear();
}

void MainWindow::doSin()
{
    bool ok;
    double num = inputBox->text().toDouble(&ok);

    if (ok)
    {
        double answer = calc.sine(num);
        QString resultText = QString::number(answer);
        resultLabel->setText("Result: " + resultText);

        QString historyText = "sin(" + QString::number(num) + ") = " + resultText;
        history.addEntry(historyText.toStdString());
        historyList->addItem(historyText);
    }
    else
    {
        resultLabel->setText("Error: invalid input");
    }
}

void MainWindow::doCos()
{
    bool ok;
    double num = inputBox->text().toDouble(&ok);

    if (ok)
    {
        double answer = calc.cosine(num);
        QString resultText = QString::number(answer);
        resultLabel->setText("Result: " + resultText);

        QString historyText = "cos(" + QString::number(num) + ") = " + resultText;
        history.addEntry(historyText.toStdString());
        historyList->addItem(historyText);
    }
    else
    {
        resultLabel->setText("Error: invalid input");
    }
}

void MainWindow::doLog()
{
    bool ok;
    double num = inputBox->text().toDouble(&ok);

    if (ok)
    {
        try
        {
            double answer = calc.logarithm(num);
            QString resultText = QString::number(answer);
            resultLabel->setText("Result: " + resultText);

            QString historyText = "log(" + QString::number(num) + ") = " + resultText;
            history.addEntry(historyText.toStdString());
            historyList->addItem(historyText);
        }
        catch (const std::exception &e)
        {
            resultLabel->setText(QString("Error: ") + e.what());
        }
    }
    else
    {
        resultLabel->setText("Error: invalid input");
    }
}

void MainWindow::doSqrt()
{
    bool ok;
    double num = inputBox->text().toDouble(&ok);

    if (ok)
    {
        try
        {
            double answer = calc.squareRoot(num);
            QString resultText = QString::number(answer);
            resultLabel->setText("Result: " + resultText);

            QString historyText = "sqrt(" + QString::number(num) + ") = " + resultText;
            history.addEntry(historyText.toStdString());
            historyList->addItem(historyText);
        }
        catch (const std::exception &e)
        {
            resultLabel->setText(QString("Error: ") + e.what());
        }
    }
    else
    {
        resultLabel->setText("Error: invalid input");
    }
}
