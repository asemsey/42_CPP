#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <iostream>
# include <fstream>

void	replace(const char *filename, std::string s1, std::string s2);
std::string	strReplace(std::string str, std::string s1, std::string s2);

#endif