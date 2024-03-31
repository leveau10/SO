# System call implementation
This repository contains the study and implementation of some linux system calls.

Some implementations may be not exactly as those used on the linux shell, but provides important informations.

## Install requirements
- Clone the repository.
- A C++ compiler is required to run compile the programs. [GCC](https://gcc.gnu.org/) is recommmended.

## System calls
- [date](/date.cpp)<br>
    The ```date``` shows the current day and time. The informations provided are the day of the week, day, month, year, time and the UTC timezone.
- [uptime](/uptime.cpp)<br>
    The ```uptime``` shows for how long the system is up.
- [mkdir](/mkdir.cpp)<br>
    The ```mkdir``` creates a new directory with full access[read, write, execute]. 
    Only one argument is accepted which is the name of the directory.
- [rmdir](/rmdir.cpp)<br>
    The ```rmdir``` removes a directory if it is empty and an error occurs if the directory is not empty or it doesn't exist.
    Only one argument is accepted which is the name of the directory.
- [chmod](/chmod.cpp)<br>
    The ```chmod``` changes the permissions of a file or directory.
    Two arguments are accepted which are the name of the file/directory and an octal that represents the permissions of the owner, group owner and other.
    |Permissions|<center>Description<center>|Digit|
    |:---:|---|:---:|
    |rwx|Read, Write, Execute|7|
    |rw-|Read, Write |6|
    |r-x|Read, Execute|5|
    |r--|Read-only|4|
    | x-|Write, Execute|3|
    |w--|Write-only|2|
    |--x|Execute-only|1|
    |---|No permissions |0|
    
    For example, if you want to change the <b>owner</b> to have full permissions, the <b>group owner</b> to read and execute, and the <b>others</b> to execute-only: ```./chmod <filename> 0751```