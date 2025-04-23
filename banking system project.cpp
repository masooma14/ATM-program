#include <iostream>
using namespace std;

// Base class
class Account {
protected:
  double balance;
public:
  double amount;
  Account(double initialBalance) {
    balance = initialBalance;
  }

  // Method to deposit money
  void deposit() {
    cout << "Enter the amount you want to deposit :" << endl;
    cin >> amount;
    balance += amount;
  }
  // Method to get the current balance
  double getBalance() const {
    cout << "Your current balance = " << balance << endl;
    return balance;
  }
};

class SavingsAccount : public Account {
public:
  // Constructor for SavingsAccount that calls the base class constructor
  SavingsAccount(double initialBalance) : Account(initialBalance) {}

  bool withdraw(int a) {
    cout << "Enter the amount you want to withdraw :";
    cin >> amount;

    if (amount <= 10000 && amount <= balance) {  
      balance -= amount;
      return true;
    } else {
      if (amount > 10000) {
        cout << "You can't withdraw amount more than 10k from savings account!" << endl;
      } else {
        cout << "Insufficient funds!" << endl;
      }
      return false;
    }
  }
  
};
// Derived class for CurrentAccount
class CurrentAccount : public Account {
public:
  // Constructor for CurrentAccount that calls the base class constructor
  CurrentAccount(double initialBalance) : Account(initialBalance) {}
    bool withdraw(int a) {
    cout << "Enter the amount you want to withdraw :";
    cin >> a;

    if (a <= balance) {
      balance -= a;
      return true;
    } else {
        
      return false;
    }}
  
};
int main() {
  char temp;
  int select, amount;
  cout << "*Select account type*" << endl;
  cout << "Press C for current and S for savings account:" << endl;
  cin >> temp;

  if (temp != 'c' && temp != 's') {
    cout << "Invalid account type selection. Please enter 'c' or 's'." << endl;
  } else {
    CurrentAccount myAccount(100000); // Create a myAccount object

    if (temp == 'c') {
      do {
        cout << "\nChoose options from the following by pressing sr. number:" << endl;
        cout << "1. Deposit cash \n2. Balance Inquiry\n3. Withdraw cash " << endl;
        cin >> select;

        switch (select) {
          case 1:
            myAccount.deposit();
            break;
          case 2:
            myAccount.getBalance();
            break;
          case 3:
            if (myAccount.withdraw(amount)) {
              cout << "Withdrawal successful!" << endl;
            } else {
              cout << "Insufficient funds!" << endl;
            }
            break;
          default:
            cout << "Program about to terminate!" << endl;
            break;
        }
        cout<<"\nnote: Press 4 if you want to terminate the program" << endl;
      } while (select != 4); // Exit loop when user selects 4 (not implemented yet)
    } 
    }
     //For savings account
  SavingsAccount myAcc(100000);
  if (temp == 's')
   {
      do 
	  {
        cout << "\nChoose options from the following by pressing sr. number:" << endl;
        cout << "1. Deposit cash \n2. Balance Inquiry\n3. Withdraw cash " << endl;
        cin >> select;
		
        switch (select) 
		{
          case 1:
            myAcc.deposit();
            break;
          case 2:
            myAcc.getBalance();
            break;
          case 3:
          	myAcc.withdraw(amount);
          
            break;
          default:
            cout << "Program about to terminate!" << endl;
            
        }
        cout<<"\nnote: Press 4 if you want to terminate the program" << endl;
      } 
	  while (select != 4);
}
return 0;
}  

