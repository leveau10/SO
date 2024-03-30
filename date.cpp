#include <iostream>
#include <iomanip>
#include <ctime>

int main() {
	//the time_t is the timestamp since 00:00 1/1/1970 and curr_time represents the seconds passed by since then.
    time_t curr_time; 
	time(&curr_time);  

	tm *tm_struct = localtime(&curr_time); //puts the in a class to make the formatation easier.

    const char* weekDay[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int day = tm_struct->tm_wday;  //get the day of the week
    const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int month = tm_struct->tm_mon;  //get the month

    std::cout << "Current day and time: " << std::endl;
    std::cout << weekDay[day] << ' ';   // day of the week
    std::cout << tm_struct->tm_mday << ' '; //month day
    std::cout << months[month] << ' ';     // month
    std::cout << tm_struct->tm_year + 1900 << ' ';        // year
    std::cout << std::setw(2) << std::setfill('0') << tm_struct->tm_hour << ':';   // hour
    std::cout << std::setw(2) << std::setfill('0') << tm_struct->tm_min << ':';    // minutes
    std::cout << std::setw(2) << std::setfill('0') << tm_struct->tm_sec <<  ' ';   // seconds
    std::cout << tm_struct->tm_zone << std::endl;
    
	return 0;
}
