#include <iostream>
#include <iomanip>
#include <ctime>

int main() {
	//the time_t is the timestamp since 00:00 1/1/1970 and curr_time represents the seconds passed by since then.
    time_t curr_time; 
	time(&curr_time);  

	tm *tm_struct = localtime(&curr_time); //puts the in a class to make the formatation easier.

    std::cout << "Current day and time: " << std::endl;
    std::cout << tm_struct->tm_year + 1900  << '-';   // year
    std::cout << tm_struct->tm_mon  + 1 << '-';     // month
    std::cout << tm_struct->tm_mday << ' ';        // day
    std::cout << std::setw(2) << std::setfill('0') << tm_struct->tm_hour << ':';         // hour
    std::cout << std::setw(2) << std::setfill('0') << tm_struct->tm_min << ':';         // minutes
    std::cout << std::setw(2) << std::setfill('0') << tm_struct->tm_sec << std::endl;   // seconds

	return 0;
}
