#include <dirent.h>
#include <iostream>
#include <fstream>

void read_directory(const std::string& name)
{
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        std::string filename = dp->d_name;
        std::ifstream file(filename);
        if (file.is_open()) {
            // do something with the file
            std::cout << "Opened file: " << filename << std::endl;
            file.close();
        }
    }
    closedir(dirp);
}

int main()
{
    read_directory("."); // current directory
    return 0;
}
