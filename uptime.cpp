#include <iostream>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;  //struct that to store information from the system
    if (sysinfo(&info) != 0) {   //it gets the information from the system and puts in the struct
        std::cerr << "Failed to get system info\n";
        return 1;
    }
    //the info struct has a property uptime that shows the time in seconds
    //it makes the math to show in a nice format

    int day = info.uptime/86400;
    int hour = info.uptime/3600;
    int minute = (info.uptime%3600)/60;
    int secs = ((info.uptime%3600)%60);

    std::cout << "The system is up for: \n";
    std::cout << day << " days, ";
    std::cout << hour << " hours, ";
    std::cout << minute << " minutes and ";
    std::cout << secs << " seconds.\n";
    return 0;
}
