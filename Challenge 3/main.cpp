#include <iostream>
#include "fonction.h"

bool test() {
	return 	fonction(0b0) == 0 && \
		fonction(0b1) == 1;

}
int main()
{
	if (test()) {
		std::cout << "Succes" << std::endl;
		return 0;
	} else {
		std::cout << "Nope" << std::endl;
		return -1;
	}
}
