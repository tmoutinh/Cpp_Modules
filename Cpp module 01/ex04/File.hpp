#ifndef FILE_HPP
# define FILE_HPP
# include <iostream>
# include <fstream>

class filename{
    public:
        filename(std::string file, std::string type);
        ~filename();
        char    *get_content();
        void    *write_content();
    private:
        char *_content;
        std::ifstream _input;
        std::ofstream _output;
};

#endif