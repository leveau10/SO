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