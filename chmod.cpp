#include <iostream>
#include <cstring>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    if (argc != 3) { //it checks if the 2 required arguments are present
        std::cerr << "Incorrect usage.\nTwo arguments are required: a filename and the permissions in Octal.\n" << argv[0] << " <filename> <permissions>\n";
        return 1;
    }

    const char* filename = argv[1];    //gets the filename
    const char* permissions_str = argv[2];    //gets the permission
    mode_t permissions;
    
    if (sscanf(permissions_str, "%o", &permissions) != 1) {   //it converts the given permission to an octal integer
        std::cerr << "Invalid permissions format.\n";
        return 1;
    }

    if (chmod(filename, permissions) != 0) {
        std::cerr << "Error changing file permissions.\n" ;  //it changes the file permissions
        return 1;
    }

    std::cout << "Permissions changed successfully.\n";
    return 0;
}
