classDiagram
    class Calculator {
        +double add(double a, double b)
        +double subtract(double a, double b)
        +double multiply(double a, double b)
        +double divide(double a, double b)
    }

    class AdvancedCalculator {
        +double sine(double value)
        +double cosine(double value)
        +double logarithm(double value)
        +double squareRoot(double value)
    }

    class ExpressionParser {
        -string expression
        +void setExpression(string expr)
        +double evaluateExpression()
    }

    class HistoryManager {
        -vector~string~ historyList
        +void addEntry(string entry)
        +vector~string~ getHistory()
        +void clearHistory()
    }

    class MainWindow {
        -QLineEdit inputBox
        -QLabel resultLabel
        -QListWidget historyList
        +buttonClicked()
        +operatorClicked()
        +calculate()
        +clearInput()
        +clearHistory()
        +doSin()
        +doCos()
        +doLog()
        +doSqrt()
    }

    AdvancedCalculator --|> Calculator
    ExpressionParser --> AdvancedCalculator : uses
    MainWindow --> ExpressionParser : uses
    MainWindow --> AdvancedCalculator : uses
    MainWindow --> HistoryManager : uses
