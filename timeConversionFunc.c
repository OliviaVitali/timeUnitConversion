/*  We use these functions to convert time in units to time in another units
*   These functions can be chained, thus we don't need 5! functions to convert all units
*   to any other time units (ie days to minutes can go through several functions and 
*   doesn't need its own function)
*/
//function to convert seconds to minutes
float secToMinConversion(float seconds){
    float minutes =seconds/60;
    
    if (minutes <0)     //prevents time travel error.  Cannot have negative time.
        minutes = minutes *-1;
    
    return minutes;
}

//function to convert minutes to seconds

float minToSecConversion(float minutes){
    float seconds = minutes*60;

    if (seconds <0)     //prevents time travel error.  Cannot have negative time.
        seconds = seconds * -1;

    return seconds;
}

//function to convert minutes into hours
float minToHourConversion(float minutes){
    float hours = minutes /60;

    if (hours <0)
        hours = hours * -1;
    return hours;
}

float hourToMinConversion(float hours){
    float min=hours *60;
    if ( hours < 0){
        min = hours /  60 * (-1);
    }
    return min;
}
float hourToDayConversion(float hours){
    float day = hours/24;
    if (day < 0){
        day = day *-1;
    }
    return day;
}
float dayToHourConversion(float days){
        float hours = days*24;
    if ( hours < 0){
        hours = hours *-1;
    }
    return hours;
}
float dayToWeekConversion(float days){
        float week = days / 7;
    if ( week < 0){
        week = week *-1;
    }
    return week;
}
float weekToDayConversion(float week){
    float days = week * 7;
    if ( days< 0){
        days = days *-1;
    }
    return days;
}