#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <fstream>
#include <limits>
#include <windows.h>
#include <string>                  //Libraries                                          

using namespace std;                //Command for the compiler so that you don't have to add "std:" before each command                    

int main ()            //Start of the program 
{
    while (true)                //A loop that allows you to return to the menu after the operation is completed 
    {           
        int Menunumber;
        cout << "Simple number guessing game"<<endl;
        cout << "Select mode:" <<endl;      
        cout << "1.Play (3-digit numbers)" <<endl;
        cout << "2.Play hard mode (6-digit numbers)" <<endl;
        cout << "3.Leader board" <<endl;
        cout << "4.Exit" <<endl;
        cout << "Choose option 1, 2, 3 or 4: ";            
        cin >> Menunumber;
        switch (Menunumber)           //Main menu
        {
            case 1:             //3 digit guessing game
            {
            cout <<"Instruction:"<<endl; 
            cout << "The program will generate a random 3-digit number. The player's task is to guess this number by entering the numbers in the terminal. The correct number guessed will be displayed in green and the incorrect number will be displayed in red."<<endl;
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            random_device rd;       // Used to obtain the seed for the random number generator
            mt19937 gen(rd());      // Standard random number generator mersenne_twister_engine
            uniform_int_distribution<> distrib(100, 999);       // Generuje liczby losowe w zakresie [100, 999]

            int drawn_number = distrib(gen);
            string drawn_number_digit = to_string(drawn_number);
            string attempt;
            int answer = 0;

            do               //A loop that waits for the player to guess the name
            {
            
                cout << "Enter a three-digit number: ";
                cin >> attempt;
                cout << answer + 1 << ": ";

                if (attempt.length() != 3 || !all_of(attempt.begin(), attempt.end(), ::isdigit)) {
                cout << "Invalid input. Please enter a three-digit number." << endl;
                continue;
                }

                if (drawn_number_digit[0] == attempt[0]){
                SetConsoleTextAttribute(hConsole, 2);
                cout << attempt[0];
                SetConsoleTextAttribute(hConsole, 7);}
                else{
                SetConsoleTextAttribute(hConsole, 4);
                cout << attempt[0];
                SetConsoleTextAttribute(hConsole, 7);}

                if (drawn_number_digit[1] == attempt[1]){
                SetConsoleTextAttribute(hConsole, 2);
                cout << attempt[1];
                SetConsoleTextAttribute(hConsole, 7);}
                else{
                SetConsoleTextAttribute(hConsole, 4);
                cout << attempt[1];
                SetConsoleTextAttribute(hConsole, 7);}

                if (drawn_number_digit[2] == attempt[2]){
                SetConsoleTextAttribute(hConsole, 2);
                cout << attempt[2];
                SetConsoleTextAttribute(hConsole, 7);}
                else{
                SetConsoleTextAttribute(hConsole, 4);
                cout << attempt[2];
                SetConsoleTextAttribute(hConsole, 7);}

                cout << endl;

            answer++;              //The program checks whether the user enters the correct numbers and counts the number of attempts

            }
            while (drawn_number_digit != attempt);

                cout << "Congratulations! You guessed the number!" <<endl;               //Congratulations

                string name;            
                do
                {
                    cout << "Enter a name (exactly 5 characters); ";
                    cin >> name;
                }
                while (name.length() != 5);          
            
                ofstream Leader_board("Leader_board.txt", ios::app);
                Leader_board << "Name: " << name << " number of tries: " << answer << " Mode: 3-digits"<<endl;
                Leader_board.close();              //The program asks you to enter a username that has exactly 5 letters and numbers, and then saves it in the leader_board file
                
            system("pause");
            break;   
            }
            case 2:
            {
            cout <<"Instruction:"<<endl; 
            cout << "The program will generate a random 6-digit number. The player's task is to guess this number by entering the numbers in the terminal. The correct number guessed will be displayed in green and the incorrect number will be displayed in red."<<endl;
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> distrib(100000, 999999);
            int drawn_number = distrib(gen);
            string drawn_number_digit = to_string(drawn_number);
            string attempt;
            int answer = 0;
            
            do               //A loop that waits for the player to guess the name
            {
            
                cout << "Enter a six-digit number: ";
                cin >> attempt;
                cout << answer + 1 << ": ";

                if (attempt.length() != 6 || !all_of(attempt.begin(), attempt.end(), ::isdigit)) {
                cout << "Invalid input. Please enter a three-digit number." << endl;
                continue;
                }
                if (drawn_number_digit[0] == attempt[0]){
                SetConsoleTextAttribute(hConsole, 2);
                cout << attempt[0];
                SetConsoleTextAttribute(hConsole, 7);}
                else{
                SetConsoleTextAttribute(hConsole, 4);
                cout << attempt[0];
                SetConsoleTextAttribute(hConsole, 7);}

                if (drawn_number_digit[1] == attempt[1]){
                SetConsoleTextAttribute(hConsole, 2);
                cout << attempt[1];
                SetConsoleTextAttribute(hConsole, 7);}
                else{
                SetConsoleTextAttribute(hConsole, 4);
                cout << attempt[1];
                SetConsoleTextAttribute(hConsole, 7);}

                if (drawn_number_digit[2] == attempt[2]){
                SetConsoleTextAttribute(hConsole, 2);
                cout << attempt[2];
                SetConsoleTextAttribute(hConsole, 7);}
                else{
                SetConsoleTextAttribute(hConsole, 4);
                cout << attempt[2];
                SetConsoleTextAttribute(hConsole, 7);}

                if (drawn_number_digit[3] == attempt[3]){
                SetConsoleTextAttribute(hConsole, 2);
                cout << attempt[3];
                SetConsoleTextAttribute(hConsole, 7);}
                else{
                SetConsoleTextAttribute(hConsole, 4);
                cout << attempt[3];
                SetConsoleTextAttribute(hConsole, 7);}

                if (drawn_number_digit[4] == attempt[4]){
                SetConsoleTextAttribute(hConsole, 2);
                cout << attempt[4];
                SetConsoleTextAttribute(hConsole, 7);}
                else{
                SetConsoleTextAttribute(hConsole, 4);
                cout << attempt[4];
                SetConsoleTextAttribute(hConsole, 7);}

                if (drawn_number_digit[5] == attempt[5]){
                SetConsoleTextAttribute(hConsole, 2);
                cout << attempt[5];
                SetConsoleTextAttribute(hConsole, 7);}
                else{
                SetConsoleTextAttribute(hConsole, 4);
                cout << attempt[5];
                SetConsoleTextAttribute(hConsole, 7);}

                cout << endl;

                

            answer++;              //The program checks whether the user enters the correct numbers and counts the number of attempts

            }
            while (drawn_number_digit != attempt);

                cout << "Congratulations! You guessed the number!" <<endl;               //Congratulations

                string name;            
                do
                {
                    cout << "Enter a name (exactly 5 characters); ";
                    cin >> name;
                }
                while (name.length() != 5);          
            
                ofstream Leader_board("Leader_board.txt", ios::app);
                Leader_board << "Name: " << name << " number of tries: " << answer << " Mode: 6-digits"<<endl;
                Leader_board.close();              //The program asks you to enter a username that has exactly 5 letters and numbers, and then saves it in the leader_board file
                
            system("pause");
            break;   
            }
            case 3:
            {
                ifstream Leader_board("Leader_board.txt");
                if (!Leader_board) 
                {
                    cout << "File leader_board is empty or does not exist" << endl;
                }
                else
                {
                string line;
                bool isEmpty = true;
                while (getline(Leader_board, line))
                {
                    if (!line.empty())
                    {
                        cout << line << endl;
                        isEmpty = false;
                    }
                }
                if (isEmpty) 
                {
                    cout << "File leader_board is empty or does not exist" << endl;         //The program displays the contents of the file leader_board if it exists, if the file does not exist or is empty it displays File leader_board is empty or does not exist
                }
                }
            system("pause");
            break;
            }
            
            case 4:
            {
                exit(0);         //Turning off the program
            break;
            }

            default:
            {
            if (cin.fail() || Menunumber < 1 || Menunumber > 4) {
            cin.clear();        //Clear error status
            cin.ignore(numeric_limits<streamsize>::max(), '\n');        //Skip invalid characters
            cout << "Wrong input" << endl;
            system("pause");
            system("cls");
            continue;
            }
            }

        }
    system("cls");
    }
return 0;
}
