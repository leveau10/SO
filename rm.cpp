#include <iostream>
#include <cstdio>

int main(int argc, char* argv[]) {
    if (argc != 2) {   //it checks if the user put the right arguments in the command line
        std::cerr << "Incorrect usage. To remove a file, a name is required: " << argv[0] << " <filename>\n"; // 
        return 1;
    }

    const char* filename = argv[1]; //it gets the filename
    
    if (remove(filename) != 0) {  //it removes the file and an error is thrown if fails.
        std::cerr << "Error removing file: " << filename << '\n';
        return 1;
    }

    std::cout << "File " << filename << " removed successfully.\n";
    return 0;
}
