#include <iostream>

class ArrayComparator {
private:
  
  int* array1;
  int* array2;
  int size; 
public:
  ArrayComparator(int arr1[], int arr2[], int arraySize) {
    if (arraySize <= 0) {
      std::cerr << "Error: Array size must be positive." << std::endl;
      return;
    }

    size = arraySize;


    array1 = new int[size];
    array2 = new int[size];

 
    for (int i = 0; i < size; i++) {
      array1[i] = arr1[i];
    }

   
    for (int i = 0; i < size; i++) {
      array2[i] = arr2[i];
    }
  }

 
  ~ArrayComparator() {
    delete[] array1;
    delete[] array2;
  }


  int findHigherSumArray() {
    int sum1 = 0;
    int sum2 = 0;

    // Calculate sum of elements in array1
    for (int i = 0; i < size; i++) {
      sum1 += array1[i];
    }

    // Calculate sum of elements in array2
    for (int i = 0; i < size; i++) {
      sum2 += array2[i];
    }

    // Compare sums and return the index of the array with higher sum
    if (sum1 > sum2) {
      return 1; // Array 1 has higher sum
    } else if (sum2 > sum1) {
      return 2; // Array 2 has higher sum
    } else {
      return 0; // Both arrays have equal sum
    }
  }
};

int main() {
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {10, 20, 30, 40, 50};
  int arraySize = sizeof(arr1) / sizeof(arr1[0]); 

  ArrayComparator arrayComp(arr1, arr2, arraySize);

  int result = arrayComp.findHigherSumArray();

  if (result == 1) {
    std::cout << "Array 1 has a higher sum of elements." << std::endl;
  } else if (result == 2) {
    std::cout << "Array 2 has a higher sum of elements." << std::endl;
  } else {
    std::cout << "Both arrays have the same sum of elements." << std::endl;
  }

  return 0;
}