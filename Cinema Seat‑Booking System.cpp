#include <iostream>
using namespace std;

// constants for seat layout
const int ROWS = 5 ;
const int COLS = 4 ;

// 2D array to represent the seating arrangement
// 0 = available, 1 = booked
int seats[ROWS][COLS] = {0} ;

//shows the full seating arrangement

void showseats() {
    cout << "\n ======= seat layout (0 = available , 1 = booked)====== \n" ;
    for (int i = 0 ; i < ROWS ; i++) {
        for (int j = 0 ; j < COLS ; j++) {
            cout << seats[i][j] << " " ;
        }
        cout << endl ;
    }
}

//books a single seat if available

void booksingleseat() {
    int r, c ;
    cout << "enter row and column to book a seat (0-based) :" ;
    cin >> r >> c ;
    if ( r >= 0 && r < ROWS && c >= 0 && c < COLS && seats[r][c] == 0) {
        seats[r][c] = 1 ;
        cout << "seat booked successfully \n" ;
    } else {
        cout << "invalid seat selection or seat already booked \n" ;
    }
}

// Books a group of adjacent seats in a row
void bookgroupseats() {
    int row , startCol , count ;
    cout << "enter row , starting column and number of seats to book (0-based) : " ;
    cin >> row >> startCol >> count ;
    if (row >= 0 && row < ROWS && startCol >= 0 && startCol + count <= COLS) {
        bool canbook = true ;

        //check all seats in block are available
        for ( int i = 0 ; i < count ; i++) {
            if (seats[row][startCol + i] == 1) {
                canbook = false ;
                break ;
            }
        }
       // book of all are free
       if (canbook) {
        for ( int i = 0 ; i < count ; i++) {
            seats[row][startCol + i ] = 1 ; 
        }
        cout << "seats booked successfully \n" ;
       } else {
        cout << "one or more seats in the block are already booked \n" ;
       }
    } else {
        cout << "invalid seat selection \n" ;
    }
}

// Cancels a booking if seat is valid and currently booked
void cancelseat() {
    int r,c ;
    cout << "enter row and column to cancel booking (0-based): " ;
    cin >> r >> c ;
    if ( r >= 0 && r < ROWS && c >= 0 && c < COLS && seats[r][c] == 1) {
        seats[r][c] = 0 ;
        cout << "booking cancelled successfully \n" ;
    } else {
        cout << "invalid seat selection or seat not booked \n" ;
    }
}

void displayAvailableseats() {
    cout << "\n ======= available seats ======= \n" ;
    bool found = false ;
    for (int i = 0 ; i < ROWS ; i++) {
        for (int j = 0 ; j < COLS ; j++) {
            if (seats[i][j] == 0) {
                cout << "seat (" << i << ", " << j << ") is available \n" ;
                found = true ;
            }
        }
    }
}



int main() {
    int choice ;
    while(true) {
        cout << "\n======== seat booking system ========\n" ;
        cout << "1.show seats \n" ;
        cout << "2.book single seat \n" ;
        cout << "3.book group seats \n" ;
        cout << "4.cancel seat booking \n" ;
        cout << "5.display available seats only \n" ;
        cout << "6.exit \n" ;
        cout << "enter your choice (1-6): " ;
        cin >> choice ;
        switch (choice) {
            case 1: showseats(); break;
            case 2: booksingleseat(); break;
            case 3: bookgroupseats(); break;
            case 4: cancelseat(); break;
            case 5: displayAvailableseats(); break;
            case 6:
                cout << "Exiting system. Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;

        }
      
