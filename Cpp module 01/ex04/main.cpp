# include <fstream>
# include <cstdlib>
# include <iostream>

std::string ReadContents(char *filename)
{
    std::ifstream	input;
    std::string		content;
	std::string		temp;

	input.open(filename, std::ios::in);
    if (!input.is_open())
    {
        std::cout << "sed: No such file or unable to open : ";
		std::cout << filename << std::endl;
        exit(-2);
    }
    while (1)
	{
		getline(input, temp);
		content += temp;
		if (input.eof())
			break ;
		content += '\n';
	}
    input.close();
    return (content);
}

std::string	replace(std::string input, std::string OldString, std::string NewString)
{
	size_t	new_pos;
	size_t	old_pos;
	std::string	output;

	new_pos = 0;
	old_pos = 0;
	if (OldString == "")
	{
		std::cout << "./sed : Passed Null as the <target string>" << std::endl;
		exit(-3);
	}
	while (1)
	{
		new_pos = input.find(OldString, old_pos);
		output += input.substr(old_pos, (new_pos - old_pos));
		if (new_pos == std::string::npos)
			break;
		output += NewString;
		old_pos = new_pos + OldString.length();
	}
	return (output);
}

void	WriteFile(std::string filename, std::string output)
{
	std::ofstream file;
	std::string		o_filename;

	o_filename = filename + ".rename";
	file.open(o_filename.c_str(), std::ios::out);
	if (!file.is_open())
    {
        std::cout << "sed: unable to create : ";
		std::cout << o_filename << std::endl;
        exit(-2);
    }
	file << output;
	file.close();
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "sed: Incorrect syntax" << std::endl;
        std::cout << "Syntax:: ./sed <filename> <target string> <subsitute string>" << std::endl;
        return (-1);
    }
    std::string input;
    std::string OldString;
    std::string NewString;
    std::string output;

    OldString = argv[2];
    NewString = argv[3];
    input = ReadContents(argv[1]);
	output = replace(input, OldString, NewString);
	WriteFile(argv[1], output);
	std::cout << input <<std::endl;
    
    return(0);
}