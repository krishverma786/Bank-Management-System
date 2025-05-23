#include <iostream>
#include <string>
using namespace std;

class BankAccount {           //created a class
private:
    string accountNumber;
    string name;
    string mobile;
    int pin;
    int balance;

public:
    BankAccount() {
        balance = 0;
    }

    void open_account(string accName, string accMobile, int accPin, string accNumber) {        
        name = accName;
        mobile = accMobile;
        pin = accPin;
        accountNumber = accNumber;
        balance = 0;

        cout << "✅ Account created successfully for " << name << "!" << endl;
        cout << "Your account number is: " << accountNumber << endl;
    }
    
    void withdraw(string enteredAccNumber, int amount) {
        if (enteredAccNumber == accountNumber) {
            balance -= amount;
            cout <<"✅ INR"<<amount<<" withdrawn succesfully!"<<endl;
            cout << "💰 Current Balance: INR " << balance << endl;
        } else {
            cout << "❌ Invalid account number. Deposit failed." << endl;
        }
    }

    void deposit(string enteredAccNumber, int amount) {
        if (enteredAccNumber == accountNumber) {
            balance += amount;
            cout << "✅ INR " << amount << " deposited successfully!" << endl;
            cout << "💰 Current Balance: INR " << balance << endl;
        } else {
            cout << "❌ Invalid account number. Deposit failed." << endl;
        }
    }

    void show_details(string enteredAccNumber) {
        if (enteredAccNumber == accountNumber) {
            cout << "📄 Account Details:" << endl;
            cout << "Name: " << name << endl;
            cout << "Mobile: " << mobile << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: INR " << balance << endl;
        } else {
            cout << "❌ Account not found!" << endl;
        }
    }
};

int main() {
    int choice;
    BankAccount userAccount;      //Think of the class as a blueprint (like a design for a car), and userAccount as a real car made from that blueprint.Without creating an object (userAccount), the blueprint (class) can't do anything. It just describes what a bank account can do

    cout << "🏦 Welcome to Krish Bank!" << endl;

    do {
        cout << "\n🔘 Menu:\n";
        cout << "1. Open an account\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Deposit Money\n";
        cout << "4. Show account details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, mobile, accNumber;   //as number is big and name has more than 2 character, so we use string
                int pin;
                cout << "Enter name: ";
                cin >> name;

                cout << "Enter mobile number: ";
                cin >> mobile;

                cout << "Enter pin: ";
                cin >> pin;

                cout << "Set account number: ";
                cin >> accNumber;

                userAccount.open_account(name, mobile, pin, accNumber);       //called function
                break;
            }
            case 2: {
                string accNumber;
                int amount;
                cout<<"Enter account number: ";
                cin>>accNumber;
                cout<<"Enter amount to withdraw: ";
                cin>>amount;
              userAccount.withdraw(accNumber,amount);
            }

            case 3: {
                string accNumber;
                int amount;

                cout << "Enter account number: ";
                cin >> accNumber;

                cout << "Enter amount to deposit: ";
                cin >> amount;

                userAccount.deposit(accNumber, amount);
                break;
            }

            case 4: {
                string accNumber;
                cout << "Enter account number: ";
                cin >> accNumber;
                userAccount.show_details(accNumber);
                break;
            }

            case 5:
                cout << "👋 Thank you for banking with Krish Bank!" << endl;
                break;

            default:
                cout << "❌ Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
