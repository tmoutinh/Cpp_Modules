# include <iostream>
# include <fstream>

std::string ReadContents(std::string filename)
{
    
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Incorrect syntax !" << std::endl;
        std::cout << "Syntax:: <filename> <target string> <subsitute string>" << std::endl;
        return (-1);
    }
    std::string input;
    std::string OldString;
    std::string NewString;
    std::string output;

    OldString = argv[2];
    NewString = argv[3];
    input = ReadContents(argv[1]);
    return(0);
}