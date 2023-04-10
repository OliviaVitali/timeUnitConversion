//declaration of functions seperated into header file for readability
float secToMinConversion(float seconds);    //done
float minToSecConversion(float minutes);    //done
float minToHourConversion(float minutes);   //done
float hourToMinConversion(float hours);
float hourToDayConversion(float hours);
float dayToHourConversion(float days);
float dayToWeekConversion(float days);
float weekToDayConversion(float days);
int menu(int userInputMenuChoices[], float *timeQuantity);
float conversionFlowChart(int userInputs[], float timeQuantity);
float convertToLargerUnits(int userInputs[], float timeQuantity);
float convertToSmallerUnits(int userInput[], float timeQuantity);
int foo(float *bar);