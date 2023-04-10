#include <stdio.h>
#include <unistd.h>
#include "enumList.h"
#include "funcDeclaration.h"
#include "timeConversionFunc.c"

//TODO update startUnits and endUnits to ENUM values
int main() {
    
    //by default, the program converts 0 seconds into 0 minutes
    int usrInputMenuChoices[] = {1,2}; //0 is the starting units, 1 is the ending units
    float timeQuantity = 0.0;//How much time should be converted
    printf("Welcome to the Unit Converter!\n");
    int x = menu(usrInputMenuChoices, &timeQuantity);  //gets the units and quantity of time to convert from the user
    if (x == -1)
        printf("Error found in int menu()");
    //since we return the converted value through the function chain conversionFlowChart() >conversionToSmallerUnits/conversionToLargerUnits() > conversionFlowChart() we need to store the final value in the scope of the main function
    timeQuantity = conversionFlowChart(usrInputMenuChoices, timeQuantity);    //converts the time into the proper units
    
    //delete test function below when done
    //foo(&timeQuantity);
    //printf("Final amount%f", timeQuantity);
    return 0;
}
int foo(float *bar){
    *bar = (float)66.5000;
    printf("from foo %f", *bar);
}
/*  This function allows the user to select the starting and ending untis along with how much time should be converted.
*
*/
int menu(int userInputMenuChoices[], float *timeQuantity){
    printf("%f\n", *timeQuantity);
    for (int impatientComputer =0; impatientComputer < 20; impatientComputer++){
    printf("Pick your starting unit then ending units: \n1 seconds\n2 minutes \n3 hours \n4 days \n5 weeks\n6 exit\n");
    int x = scanf("%d %d", &userInputMenuChoices[0], &userInputMenuChoices[1]); //if successfully read, x=2
    
    
    if (userInputMenuChoices[0] ==6 || userInputMenuChoices[1] ==6){    //allows user to exit application
        printf("Ok we'll quit now\n");
        return -1;
    }
    printf("Now enter how much (non-negative) time we should covert: \n");
    float temp =0;
    int y = scanf("%f", &temp);         //takes user's input
    *timeQuantity = (float) temp;       //puts user's input into timeQuantity variable
                                        //Not 100% sure why we need this step.  Pointers are hard.
    printf("You entered %f.  timeQ %f\n\n", temp, *timeQuantity);
    if (userInputMenuChoices[0] <1 ||userInputMenuChoices[0] >6){
        printf("That's not a valid starting unit\n");
    }
    else if (userInputMenuChoices[1] <1 || userInputMenuChoices[1]>6){
        printf("That's not a valid ending unit\n");
    }
    if (*timeQuantity < 0){
        printf("You don't have a time visa. We will convert to positive time.\n");
        *timeQuantity = *timeQuantity * -1;   //automatically converts negative time to positive time.
    }

    //checks that user put in "proper" input 
    if (userInputMenuChoices[0] >=1 && userInputMenuChoices[0] <=6 && userInputMenuChoices[1] >=1 && userInputMenuChoices[1] <=6 && userInputMenuChoices[2]>=0)
        impatientComputer=21;
    }
    return 0;   //TODO does not pass arguments back to main function yet
}

/* The function will decide how to convert from the starting to ending units.
*   startUnits: the integer value represents which time units we start in
*   endUnits: the integer value represents which time units we want to convert to
*   unitQuantity: this is the amount of time (in startUnits) we are trying to convert.
*/
float conversionFlowChart(int usrInput[], float timeQuantity){
    float temp = timeQuantity;
    printf("timeQuantity %f\n", timeQuantity);
    //TODO error check that input cannot be misleading
    if (usrInput[0] < usrInput[1]){
        printf("We want to convert to larger units.\n");
        temp=convertToLargerUnits(usrInput, timeQuantity);
    } 
    else if( usrInput[0] == usrInput[1]){
        printf("We don't want to convert to at all!\n");
    }
    else {
        printf("alpha timeQuantity %f\n", timeQuantity);
        temp=convertToSmallerUnits(usrInput, timeQuantity);
    }
    return temp;
}

//takes large units and converts to a smaller one
float convertToSmallerUnits(int usrInput[], float timeQuantity){
    //printf("convertToSmallerUnits %f\n", timeQuantity);
    float temp = timeQuantity;

    if (usrInput[0] == week){
        temp = weekToDayConversion(temp);
        usrInput[0] = usrInput[0]-1;
        //printf("branch 5 %f\n", temp);
    }  
    if (usrInput[0] >= day && usrInput[0] > usrInput[1]){
        temp = dayToHourConversion(temp);
        usrInput[0] = usrInput[0]-1;
        //printf("branch 4 %f\n", temp);
    }
    if (usrInput[0] >=hour && usrInput[0] > usrInput[1]){
        temp = hourToMinConversion(temp);
        usrInput[0] = usrInput[0]-1;
        //printf("branch 3 %f\n", temp);
    }
    if (usrInput[0] >=minute && usrInput[0] > usrInput[1]){
        temp = minToSecConversion(temp);
        usrInput[0] = usrInput[0]-1;
        //printf("branch 2 %f\n", temp);
    }


  
    printf("The new amount of time is %f \n", temp);
    return temp;
}
//takes a small unit and converts it to a larger one
float convertToLargerUnits(int userInput[], float timeQuantity){
    float tempQuantity = timeQuantity;
    if (userInput[0] < minute && userInput[1] >= 2){
        tempQuantity = secToMinConversion(tempQuantity);
    }
    if (userInput[0] < hour && userInput[1] >=3){
        tempQuantity = minToHourConversion(tempQuantity);
    }
    if (userInput[0] < day && userInput[1] >=4){
        tempQuantity = hourToDayConversion(tempQuantity);
    }
    if (userInput[0] < week && userInput[1] >=5){
        tempQuantity = dayToWeekConversion(tempQuantity);
    }
    printf("You had %f %d and converted to %f %d", userInput[2], userInput[0], tempQuantity, userInput[1]);

    //For now, we'll trust that our functions in the if block above are working as intended.
    //changes userInput[2] to the new quantity of time
    return tempQuantity;
    }
