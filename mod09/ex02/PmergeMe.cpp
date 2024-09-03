#include "PmergeMe.hpp"

int	ft_error(const std::string &err) {
	std::cerr << "Error: " << err << std::endl;
	return 1;
}

std::vector<std::string> ft_split(const std::string &str, char c) {
	std::vector<std::string>	vec;
	std::stringstream		ss(str);
	std::string				word;

	while (std::getline(ss, word, c)) {
		if (!word.empty())
			vec.push_back(word);
	}
	return vec;
}

std::vector<int> to_int_vec(std::vector<std::string> vec) {
	int						tmp = 0;
	std::string::size_type	rest;
	std::vector<int>		ints;

	for (std::vector<std::string>::iterator i = vec.begin(); i != vec.end(); i++) {
		try {
			tmp = std::stoi(*i, &rest);
		} catch (std::exception &e) {
			ints.clear();
			return ints;
		}
		if (rest != (*i).length() || tmp < 0) {
			ints.clear();
			return ints;
		}
		ints.push_back(tmp);
	}
	return ints;
}

std::deque<int> to_int_deq(std::vector<std::string> vec) {
	int						tmp = 0;
	std::string::size_type	rest;
	std::deque<int>		ints;

	for (std::vector<std::string>::iterator i = vec.begin(); i != vec.end(); i++) {
		try {
			tmp = std::stoi(*i, &rest);
		} catch (std::exception &e) {
			ints.clear();
			return ints;
		}
		if (rest != (*i).length()) {
			ints.clear();
			return ints;
		}
		ints.push_back(tmp);
	}
	return ints;
}

// container one: vector -----------------------------------------------
// ---->	good for fast random access, contiguous memory but iterators
// 			can invalidate after changes

std::vector<int>	merge_vec(std::vector<int>& left, std::vector<int>& right) {
	std::vector<int> nums;
	nums.reserve(left.size() + right.size());

	std::vector<int>::iterator l = left.begin();
	std::vector<int>::iterator r = right.begin();

	while (l != left.end() && r != right.end()) {
		if (*l < *r) {
			nums.push_back(*l);
			l++;
		} else {
			nums.push_back(*r);
			r++;
		}
	}
	nums.insert(nums.end(), l, left.end());
	nums.insert(nums.end(), r, right.end());
	return nums;
}

std::vector<int>	mergeSort_vec(std::vector<int> nums) {
	if (nums.size() <= 1)
		return nums;
	int middle = nums.size()/2;
	std::vector<int> left(nums.begin(), nums.begin() + middle);
	std::vector<int> right(nums.begin() + middle, nums.end());
	
	left = mergeSort_vec(left);
	right = mergeSort_vec(right);
	return merge_vec(left, right);;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		os << vec[i];
		if (i != vec.size() - 1)
			os << " ";
	}
	return os;
}

// container two: deque ------------------------------------------------
// ---->	slower random access, good for insertions at the ends

std::deque<int>	merge_deq(std::deque<int>& left, std::deque<int>& right) {
	std::deque<int> nums;

	while (!left.empty() && !right.empty()) {
		if (left.front() < right.front()) {
			nums.push_back(left.front());
			left.pop_front();
		} else {
			nums.push_back(right.front());
			right.pop_front();
		}
	}
	nums.insert(nums.end(), left.begin(), left.end());
	nums.insert(nums.end(), right.begin(), right.end());
	return nums;
}

std::deque<int>	mergeSort_deq(std::deque<int> nums) {
	if (nums.size() <= 1)
		return nums;
	int middle = nums.size()/2;
	std::deque<int> left(nums.begin(), nums.begin() + middle);
	std::deque<int> right(nums.begin() + middle, nums.end());
	
	left = mergeSort_deq(left);
	right = mergeSort_deq(right);
	return merge_deq(left, right);
}

std::ostream& operator<<(std::ostream& os, const std::deque<int>& deq) {
	for (size_t i = 0; i < deq.size(); ++i) {
		os << deq[i];
		if (i != deq.size() - 1)
			os << " ";
	}
	return os;
}