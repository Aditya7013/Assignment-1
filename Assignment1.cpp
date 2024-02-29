#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
  string userId;
  string password;
  double balance;

public:
  BankAccount(string _userId, string _password) : userId(_userId), password(_password), balance(0) {}

  bool login(string _userId, string _password) {
    return userId == _userId && password == _password;
  }

  void deposit(double amount) {
    balance += amount;
    cout << "Amount deposited: $" << amount << endl;
  }

  void withdraw(double amount) {
    if (amount > balance) {
      cout << "Insufficient balance." << endl;
    } else {
      balance -= amount;
      cout << "Amount withdrawn: $" << amount << endl;
    }
  }

  void requestBalance() {
    cout << "Your balance is $" << balance << endl;
  }
};

int main() {
  char choice;
  BankAccount *account = nullptr;

  cout << "Hi! Welcome to Mr. Aditya’s ATM Machine!" << endl;

  do {
    cout << "Please select an option from the menu below:" << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
    cin >> choice;

    switch(choice) {
      case 'c': {
        string userId, password;
        cout << "Please enter your user name: ";
        cin >> userId;
        cout << "Please enter your password: ";
        cin >> password;
        account = new BankAccount(userId, password);
        cout << "Thank You! Your account has been created!" << endl;
        break;
      }
      case 'l': {
        string userId, password;
        cout << "Please enter your user id: ";
        cin >> userId;
        cout << "Please enter your password: ";
        cin >> password;
        if (account != nullptr && account->login(userId, password)) {
          cout << "Access Granted!" << endl;
          char option;
          do {
            cout << "d -> Deposit Money" << endl;
            cout << "w -> Withdraw Money" << endl;
            cout << "r -> Request Balance" << endl;
            cout << "q -> Quit" << endl;
            cout << "> ";
            cin >> option;

            switch(option) {
              case 'd': {
                double amount;
                cout << "Amount of deposit: $";
                cin >> amount;
                account->deposit(amount);
                break;
              }
              case 'w': {
                double amount;
                cout << "Amount of withdrawal: $";
                cin >> amount;
                account->withdraw(amount);
                break;
              }
              case 'r':
                account->requestBalance();
                break;
              case 'q':
                cout << "Thanks for stopping by!" << endl;
                break;
              default:
                cout << "Invalid option!" << endl;
            }
          } while(option != 'q');
        } else {
          cout << "******** LOGIN FAILED! ********" << endl;
        }
        break;
      }
      case 'q':
        cout << "Thanks for stopping by!" << endl;
        break;
      default:
        cout << "Invalid option!" << endl;
    }
  } while(choice != 'q');

  delete account;
  return 0;
}