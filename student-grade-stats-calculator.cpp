#include <iostream>
#include <string>
using namespace std;



int main () {
int n ;
cout << "enter number of subjects : " ;
cin >> n ;

if ( n <= 0 ) {
    cout << "invalid number , please enter a positive number " << endl ;
    return 0 ;
}

int grade ;
int total = 0 ;
int maxgrade = -1 ;
int mingrade = 101 ;


// loop to get grades
for ( int i = 0 ; i < n ; i++) {
    cout << "enter grade for subject " << i << " : " ;
    cin >> grade ;

    // validate grade 
if ( grade < 0 || grade > 100 ) {
    cout << "invalid grade , please enter a grade between 0 and 100 " << endl ;
    i-- ; //decrement i to repeat this iteration
    continue;
}
total += grade ;
if (grade > maxgrade) maxgrade = grade ;
if (grade < mingrade) mingrade = grade ;

}
float average = (float) total / n ;

//determine letter grade 
char lettergrade ;
if (average >= 90) lettergrade = 'A' ;
else if ( average >= 80) lettergrade = 'B' ;
else if ( average >= 70) lettergrade = 'C' ;
else if (average >= 60) lettergrade = 'D' ;
else lettergrade = 'F' ;

// output results
cout << "\n======RESULTS======\n" ;
cout << "total grades : " << total << endl ;
cout << "average grade : " << average << endl ;
cout << "highest grade : " << maxgrade << endl ;
cout << "lowest grade : " << mingrade << endl ;
cout << "letter grade : " ;

switch (lettergrade){
    case 'A' : cout << "excellent (A) " << endl ; break ;
    case 'B' : cout << "good (B) " << endl ; break;
    case 'C' : cout << "good (C) " << endl ; break;
    case 'D' : cout << "pass (D) " << endl ; break ;
    case 'F' : cout << "fail (F) " << endl ; break ;
    default : cout << "invalid letter grade " << endl ; break ;
}
cout << endl ;

// Do-While Example: ask user if they want to exit
char exitchoice ;
do {
    cout << "\n do you want to exit ? (y/n) : " ;
    cin >> exitchoice ;

}while ( exitchoice != 'y' && exitchoice != 'n' ) ;




}
