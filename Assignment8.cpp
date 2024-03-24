#include <iostream>
using namespace std;

class SeriesSum {
public:
  int calculateSum(int n) {
    int series_sum = 0;
    for (int i = 1; i <= n; ++i) {
      series_sum += i * (i + 1) / 2;
    }
    return series_sum;
  }
};

int main() {
  int n;
  SeriesSum sumCalculator; 

  cout << "Enter a positive integer: ";
  cin >> n;

  if (n <= 0) {
    cout << "Error: Please enter a positive integer." << endl;
    return 1;
  }

  int result = sumCalculator.calculateSum(n);
  cout << "The sum of the series for n = " << n << " is: " << result << endl;

  return 0;
}