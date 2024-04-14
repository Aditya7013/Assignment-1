#include <iostream>

int findMaximum(int& num1, int& num2, int& num3) {
  int max = num1; 

  if (num2 > max) {
    max = num2;
  }

  if (num3 > max) {
    max = num3;
  }

  return max; 
}

int main() {
  int num1, num2, num3;


  std::cout << "Enter three integers: ";
  std::cin >> num1 >> num2 >> num3;

  
  int largestNumber = findMaximum(num1, num2, num3);

  
  std::cout << "Maximum number is: " << largestNumber << std::endl;

  return 0;
}