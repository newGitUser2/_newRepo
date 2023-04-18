#include <iostream>
#include "list.hpp"

int main(){
	List l1;
        l1.push_back(47);
        l1.push_back(13);
        l1.push_back(8);
        l1.push_back(31);
	l1.print();
	std::cout << l1.pop_back() << '\n';
	l1.set_size(6);
	std::cout << "Size is " << l1.get_size() << '\n';
	l1.insert(27, 1);
	l1.print();
	std::cout << "Size is " << l1.get_size() << '\n';
	l1.remove_by_value(13);
	std::cout << "Data of the last element: " << l1.pop_back() << '\n';

        return 0;
}
