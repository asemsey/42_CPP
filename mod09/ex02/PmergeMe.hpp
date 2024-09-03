#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <iostream>

int	ft_error(const std::string &err);

std::vector<std::string>	ft_split(const std::string &str, char c);
std::vector<int>			to_int_vec(std::vector<std::string> vec);
std::deque<int>				to_int_deq(std::vector<std::string> vec);
std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);
std::ostream& operator<<(std::ostream& os, const std::deque<int>& deq);

std::vector<int>			mergeSort_vec(std::vector<int> nums);
std::deque<int>				mergeSort_deq(std::deque<int> nums);

#endif