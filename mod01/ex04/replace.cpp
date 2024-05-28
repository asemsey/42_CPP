#include "include/replace.hpp"

// ofstream: Stream class to write on files
// ifstream: Stream class to read from files
// fstream: Stream class to both read and write from/to file

// uses find, erase and insert
std::string	strReplace(std::string str, std::string s1, std::string s2)
{
	std::size_t	found;

	while (1) {
		found = str.find(s1);
		if (found == std::string::npos)
			return (str);
		str.erase(found, s1.length());
		str.insert(found, s2);
	}
}

void	replace(const char *filename, std::string s1, std::string s2)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		newfile;
	std::string		line;

	infile.open(filename);
	if (!infile.is_open()) {
		std::cout << "Error: File not found\n";
		return ;
	}
	
	newfile = std::string(filename) + ".replace";
	outfile.open(newfile.c_str());
	while (1) {
		if (getline(infile, line)) {
			outfile << strReplace(line, s1, s2) << std::endl;
		}
		else
			break ;
	}
	infile.close();
	outfile.close();
}
