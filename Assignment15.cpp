#include <iostream>

class DynamicArray {
private:
  int* arr;

  int size;
  
  int capacity;

public:
  
  DynamicArray(int initialSize) : size(0), capacity(initialSize) {

    arr = new int[capacity];
  }


  ~DynamicArray() {
    delete[] arr;
  }

  // Function to add an element to the dynamic array
  void add(int value) {
    // Check if the array is full (size == capacity)
    if (size == capacity) {
      // Need to resize the array to accommodate more elements
      // Allocate a new temporary array with double the capacity
      int* temp = new int[2 * capacity];

      // Copy the existing elements from the old array to the new one
      for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
      }

      // Deallocate memory of the old array (avoid memory leaks)
      delete[] arr;

      // Update the internal pointers to point to the new array
      arr = temp;

      // Update the capacity to reflect the new size
      capacity *= 2;
    }

    // Add the new element to the end of the array
    arr[size++] = value;
  }

  // Function to display elements of the dynamic array
  void display() {
    std::cout << "Dynamic Array elements: ";
    for (int i = 0; i < size; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }
};

int main() {
  // Create a dynamic array with initial size 5
  DynamicArray dynArray(5);

  // Add elements to the dynamic array
  dynArray.add(10);
  dynArray.add(20);
  dynArray.add(30);
  dynArray.add(40);
  dynArray.add(50);

  // Display elements of the dynamic array
  dynArray.display();

  // Add more elements to test dynamic resizing
  dynArray.add(60);
  dynArray.add(70);
  dynArray.add(80);

  // Display elements of the dynamic array after resizing
  dynArray.display();

  return 0;
}