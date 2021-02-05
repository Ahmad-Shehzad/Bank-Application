#include <iostream>
#include <cmath>
using namespace std;

class BankAccount{

    private: double balances [10];
    private: int id;
    private: int size = 0;
    private: string accounts[10];
    private: long long passwords[10];

    public: int addAccount(string name, string pass){
        id = size;
        size++;

        accounts[id] = name;
        passwords[id] = hash(pass);
        balances[id] = 0;

        return id;
    }

    public: bool login(int id, string pass){

        if (passwords[id]==hash(pass)){
            cout << "\n-------Login Successful-------\n";
            return true;
        }
        else{
            cout << "Incorrect Login Details. Please Try Again.";
            return false;
        }
    }

    private: long long hash(string input){

        int n = input.length();
        long long output = 0;
        int temp;

        for (int i=0; i<n; i++){
            temp = input.at(i);
            output += temp*pow(10.0, (float) (n-i-1) );
        }

        output %= 1379879;
        return output;

    }

    public: void deposit(int id, double amount) {
         
         if (amount<=0){
             cout << "Please enter a valid amount.";
         }
         else{
             balances[id] += amount;
         }
    }

    public: void withdraw(int id, int amount){

        if(amount<0){
            cout << "Please enter a valid amount";
        }
        else{
            balances[id]-=amount;
        }

    }

    public: void getBalance(int id) {
        cout << "\n\nYour balance is " << balances[id] << endl;
    }
};

class Menus{
   
    private: BankAccount bank;

    private: void returnMenu(int id){
        char opt;

        cout << "Would you like to exit? (Y/N)";

        cin >> opt;

        if (opt=='Y'){
            MainMenu();
        }
        else{
            bankingMenu(id);
        }

    }

    private: void bankingMenu(int id){

        cout << "\n-------Please Choose an Option-------\n\n";
        cout << "A. View Balance\n";
        cout << "B. Deposit Money\n";
        cout << "C. Withdraw Money\n";
        cout << "D. Return to Main Menu\n\n";

        char opt;

        cin >> opt;

        switch (opt){
            
            case 'A':
                bank.getBalance(id);
                returnMenu(id);
                break;
            
            case 'B':
                double amount;
                cout << "\nPlease enter the amount you wish to deposit.\n";
                cin >> amount;
                bank.deposit(id, amount);
                returnMenu(id);
                break;
            
            case 'C':
                double amount2;
                cout << "\nPlease enter the amount you wish to withdraw.\n";
                cin >> amount2;
                bank.withdraw(id, amount2);
                returnMenu(id);
                break;
            
            case 'D':
                MainMenu();
                break;
        }
    }


    private: void newAccountMenu(){
        
        string accountName;
        string password;

        cout << "\nPlease enter a Account Name:\n";
        cin >> accountName;

        cout << "\nPlease enter a password:\n";
        cin >> password;
        int id = bank.addAccount(accountName, password);
        cout << "\n-------Your Account ID: " << id << "-------\n\n";
        bankingMenu(id);
    }

    private: void existingAccountMenu(){

        int username;
        string password;

        cout << "\nPlease Enter Your Login Details:\n\n";
        cout << "ID:\n";
        cin >> username;

        cout << "\nPassword:\n";
        cin >> password;

        if (bank.login(username, password)){
            bankingMenu(username);
        }
        else{
            MainMenu();
        }
    }

    public: void MainMenu(){
    

        char opt;

        cout << "\n-----------Main Menu-----------\n\n";
        cout << "A. Existing Customer\n";
        cout << "B. New Customer\n";
        cout << "C. Exit\n\n";
        cout << "Please enter an option.\n";

        cin >> opt;

        if (opt=='A'){
            existingAccountMenu();
        }
        else if (opt=='B'){
            newAccountMenu();
        }
        else if (opt=='C'){
            cout<<"\nThank you for using our services.\n\n";
        }
        else{
            cout<<"\nPlease enter a valid choice, A or B.\n";
            MainMenu();
        }
    }
};



int main(){
    Menus menu;
    menu.MainMenu();
}

