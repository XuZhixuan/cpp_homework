#include <iostream>

int main()
{
	int input;
	std::cin >> input;
  
  	int c50 = input / 50;
  	input = input % 50;
  
  	int c20 = input / 20;
   	input = input % 20;
  
  	int c10 = input / 10;
   	input = input % 10;
  
  	int c5 = input / 5;
  	input = input % 5;
  
  	std::cout << c50 << std::endl;
    	std::cout << c20 << std::endl;
    	std::cout << c10 << std::endl;
    	std::cout << c5 << std::endl;
    	std::cout << input << std::endl;
	
  	return 0;
}
