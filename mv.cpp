#include <iostream>
#include <cstdlib> // For std::rename()

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Incorrect usage. To rename or move a file, two arguments are required:\n" << argv[0] << " <source> <destination>\n";
        return 1;
    }

    const char* source = argv[1];  //it gets the source 
    const char* destination = argv[2];  //it is gets the destination file

    if (rename(source, destination) != 0) {    //it renames, moves or do both with the source to the destination an error is thrown if something wrong happens
        std::cerr << "Error moving file " << source << " to " << destination << std::endl;
        return 1;
    }

    std::cout << "File " << source << " moved to " << destination << " successfully.\n";
    return 0;
}
