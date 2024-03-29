#include <iostream>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {  //it checks if the user put the right arguments in the command line
        std::cerr << "Incorrect usage. To create a directory, one name is required:" <<std::endl << argv[0] << " <directory_name>\n";  //
        return 1;
    }
    const char* directory_name = argv[1];      //tt gets the name after the ./mkdir
    if (mkdir(directory_name, 0777) != 0) {   //it creates a directory with the name and with full permissions. if it fails an error is created.
        std::cerr << "You were not able to create a directory. Try again.\n";
        return 1;
    }
    std::cout << "The directory |" << directory_name << "| was created with success.";
    return 0;
}
