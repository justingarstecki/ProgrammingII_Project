# ProgrammingII_Project
## UML Diagram


classDiagram
    class Calculator {
        -double currentResult
        +Calculator()
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
        +void parseExpression()
        +double evaluateExpression()
    }

    class HistoryManager {
        -vector~string~ historyList
        +void addRecord(string record)
        +void displayHistory()
        +void saveToFile()
        +void loadFromFile()
    }

    class UserInterface {
        +void displayMenu()
        +string getInput()
        +void showResult(double result)
    }

    AdvancedCalculator --|> Calculator
    ExpressionParser --> Calculator : uses
    UserInterface --> Calculator : interacts
    UserInterface --> AdvancedCalculator : interacts
    UserInterface --> ExpressionParser : interacts
    UserInterface --> HistoryManager : interacts
