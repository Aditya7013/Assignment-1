#include <iostream>

class Computation {
public:
  int compute(int a, int b) {
    return a + b;
  }

  double compute(int a, float b) {
    return a + b;
  }

  double compute(int a, double b) {
    return a + b;
  }

  int compute(char a, char b) {
    return (int)a + (int)b;
  }

  int compute(char a, int b) {
    return (int)a + b;
  }

  int compute() {
    return 0;
  }
};

int main() {
  Computation myComputation;

  int intResult = myComputation.compute(5, 3);
  double floatResult = myComputation.compute(2, 4.5f);
  double doubleResult = myComputation.compute(10, 3.14159);
  int asciiResult = myComputation.compute('A', 'B');
  int charIntResult = myComputation.compute('Z', 10);
  int defaultResult = myComputation.compute();

  std::cout << "Integer addition: " << intResult << std::endl;
  std::cout << "Integer-float addition: " << floatResult << std::endl;
  std::cout << "Integer-double addition: " << doubleResult << std::endl;
  std::cout << "Character ASCII addition: " << asciiResult << std::endl;
  std::cout << "Character-integer addition: " << charIntResult << std::endl;
  std::cout << "Default addition: " << defaultResult << std::endl;

  return 0;
}
