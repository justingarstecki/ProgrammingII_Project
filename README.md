# ProgrammingII_Project
--------------------------------------------------------
---------------------------------------------------------
- currentResult : double
 + Calculator()                                  
 + add(a: double, b: double) : double             
 + subtract(a: double, b: double) : double        
 + multiply(a: double, b: double) : double        
 + divide(a: double, b: double) : double
                  ^
                  |
           AdvancedCalculator
      + sine(value: double) : double
  + cosine(value: double) : double
  + logarithm(value: double) : double
   +  + squareRoot(value: double) : double
------------------------------------------------------
----------------------------------------------------

                 ExpressionParser 
               - expression : string 
+ parseExpression() : void
+ evaluateExpression() : double
                  |
                  v
              Calculator    
--------------------------------------------------------
-----------------------------------------------------
                      HistoryManager 
               - historyList : vector<string>   
               + addRecord(record: string) : void     
 + displayHistory() : void
 + saveToFile() : void
 + loadFromFile() : void

--------------------------------------------------------
--------------------------------------------------------
                     UserInterface   

 + displayMenu() : void  
 + getInput() : string 
 + showResult(result: double) : void

                          |
                          | interacts with
                          v
  
  Calculator / AdvancedCalculator / Parser /      
  HistoryManager 
  ----------------------------------------------------
  ---------------------------------------------------
  
Relationships:
- AdvancedCalculator inherits from Calculator
- ExpressionParser uses Calculator to evaluate expressions
- HistoryManager stores previous calculations
- UserInterface interacts with all major classes

   



              
                  
                 
