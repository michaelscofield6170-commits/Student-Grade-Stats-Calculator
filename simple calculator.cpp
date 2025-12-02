#include <iostream>
#include <string>
using namespace std;



int main () {

    float num1 , num2 ;
    char op ;
    cout << "enter first number: " ;
    cin >> num1 ;
    cout << "enter the operator: " ;
    cin >> op ;
    cout << "enter second number: " ;
    cin >> num2 ;

    switch (op) {
        case '+' : cout << num1 + num2 ; break ;
        case '-' : cout << num1 - num2 ; break ;
        case '*' : cout << num1 * num2 ; break ;
        case '/' :
        if (num2 != 0) {
            cout << num1 / num2 ;
        } else {
            cout << "error : division by zero" ;
        }
        default : cout << "error : invalid operator" ; break ;
    }




}