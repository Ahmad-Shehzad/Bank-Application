 #include <iostream> 
 using namespace std;  

int main(){
    char opt;

    cout << "\n-----------Main Menu-----------\n\n";
    cout << "A. Existing Customer\n";
    cout << "B. New Customer\n\n";
    cout << "Please enter an option.\n";

    cin >> opt;

    if (opt=='A'){
        cout << "You have chosen option A";
    }
    else if (opt=='B'){
        cout << "You have chosen option B";
    }
    else{
        cout<<"\nPlease enter a valid choice, A or B.\n";
        main();
    }
}