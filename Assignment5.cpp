#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class User {
private:
    string name;
    int birth_year;
    int birth_month;
    int birth_day;
    double salary;

public:
    User(const string& name, int year, int month, int day, double salary) {
        if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
            throw invalid_argument("Invalid birth date!");
        }
        this->name = name;
        birth_year = year;
        birth_month = month;
        birth_day = day;
        this->salary = salary;
    }

    int operator==(const User& other) const {
        int age1 = calculateAge();
        int age2 = other.calculateAge();
        if (age1 > age2)
            return 1;  // User1 is elder
        else if (age1 == age2)
            return 0;  // Both are equal
        else
            return -1; // User1 is younger
    }

    double operator+(double increment) const {
        return salary * (1 + increment / 100.0);
    }

    int calculateAge() const {
        time_t now = time(0);
        tm* current_time = localtime(&now);
        int current_year = current_time->tm_year + 1900;
        int current_month = current_time->tm_mon + 1;
        int current_day = current_time->tm_mday;

        int age = current_year - birth_year;
        if (current_month < birth_month || (current_month == birth_month && current_day < birth_day)) {
            age--;
        }
        return age;
    }

    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << calculateAge() << endl;
        cout << "Salary: $" << salary << endl;
    }

    string getName() const {
        return name;
    }
};

int main() {
    try {
        User user1("Aditya", 1990, 5, 15, 80000.0);
        User user2("Ankit", 1995, 10, 20, 75000.0);

    
        int result = user1 == user2;

        if (result == 1) {
            cout << user1.getName() << " is elder." << endl;
        } else if (result == 0) {
            cout << user1.getName() << " and " << user2.getName() << " are of the same age." << endl;
        } else {
            cout << user2.getName() << " is elder." << endl;
        }

        double average_sal = (user1 + 5.0) + (user2 + 10.0); 
        average_sal /= 2.0;
        cout << "Average Salary: $" << average_sal << endl;

        user1.displayDetails();
        user2.displayDetails();
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
