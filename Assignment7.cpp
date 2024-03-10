#include <iostream>
#include <cstring>

using namespace std;

class sample {
public:
    char *name;

    sample() : name(nullptr) {}  // Initialize name to nullptr

    sample(char *str, int length) {
        name = new char[length + 1];
        strcpy(name, str);
    }

    // Destructor to deallocate memory
    ~sample() {
        delete[] name;
    }

    // Copy constructor for proper copying of objects
    sample(const sample& other) {
        name = new char[strlen(other.name) + 1];  // Allocate new memory for the copy
        strcpy(name, other.name);
    }
};

int main() {
    sample user1((char *)"chitkara", 8);
    sample user2 = user1;  // Copy constructor now creates a deep copy
    strcpy(user2.name, "dummy");
    cout << user2.name << user1.name << endl;  // Output: dummychitkara
    return 0;
}
