#include <iostream>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {  //it checks if the number of args is correct. only one argument is accepted(name of the directory)
        std::cerr << "Incorrect usage. To remove a directory, a name is required: " << argv[0] << " <directory_name>\n";   
        return 1;
    }

    const char* directory_name = argv[1];   //it gets the name after the ./rmdir
    if (rmdir(directory_name) != 0) {    //it tries to remove the directory with the name given by the user. if the directory doesn't exist or the directory isn't empty
        std::cerr << "Error removing directory.\n";
        return 1;
    }

    std::cout << "Directory removed successfully.\n";
    return 0;
}