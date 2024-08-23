#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	{//subject
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "top " << mstack.top() << std::endl;
		mstack.pop();//17

		std::cout << "size " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		// -----------------------------------------------
		std::stack<int> s(mstack);
		it = std::find(mstack.begin(), mstack.end(), 0);
		if (it != mstack.end())
			std::cout << "found number at: "
				<< std::distance(it, mstack.end()) << std::endl;
	}
	// std::cout << "output should be identical:\n";
	// {//replace Mutant with std::list
	// 	std::list<int> lstack;

	// 	lstack.push_back(5);
	// 	lstack.push_back(17);

	// 	std::cout << "top " << lstack.back() << std::endl;
	// 	lstack.pop_back();

	// 	std::cout << "size " << lstack.size() << std::endl;

	// 	lstack.push_back(3);
	// 	lstack.push_back(5);
	// 	lstack.push_back(737);
	// 	lstack.push_back(0);

	// 	std::list<int>::iterator iit = lstack.begin();
	// 	std::list<int>::iterator iite = lstack.end();
	// 	++iit;
	// 	--iit;
	// 	while (iit != iite)
	// 	{
	// 		std::cout << *iit << std::endl;
	// 		++iit;
	// 	}
	// }
	return 0;
}