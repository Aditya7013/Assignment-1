#include <iostream>
#include <functional> 

using namespace std;

class Sample {
public:
   int Compute(function<int(int)> func, int n) {
       return func(n);
   }

   int findFactorial(int n) {
       if (n < 0) {
           cerr << "Error: Factorial is not defined for negative numbers." << endl;
           return -1;
       }
       int fact = 1;
       for (int i = 1; i <= n; i++) {
           fact *= i;
       }
       return fact;
   }

   int findSquare(int n) {
       return n * n;
   }

   int findCube(int n) {
       return n * n * n;
   }
};

int main(int argc, char* argv[]) {
   if (argc < 2) {
       cerr << "Error: Please provide a value for N." << endl;
       return 1;
   }

   Sample obj;
   int n = stoi(argv[1]); 
   
   function<int(int)> func; 

   if (argc >= 3) {
       string option = argv[2];
       if (option == "square") {
           func = [&obj](int n) { return obj.findSquare(n); }; 
       } else if (option == "cube") {
           func = [&obj](int n) { return obj.findCube(n); }; 
       } else if (option != "factorial") { 
           cerr << "Error: Invalid operation specified." << endl;
           return 1;
       }
   }

   if (!func) {
       func = [&obj](int n) { return obj.findFactorial(n); };
   }

   int result = obj.Compute(func, n);
   cout << "Result: " << result << endl;

   return 0;
}
