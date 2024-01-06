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
 
void savetofile(const string& name, int answer, string mode)
{
    ofstream Leader_board("Leader_board.txt", ios::app);
    Leader_board << "Name: " << name << " number of tries: " << answer << " Mode: "<< mode << endl;
    Leader_board.close();           //Saving to file
}

string generatenumber(int a, int b)
{
    random_device rd;           // Used to obtain the seed for the random number generator
    mt19937 gen(rd());          // Standard random number generator mersenne_twister_engine
    uniform_int_distribution<> distrib(a, b);           // Generates a number in between a and b
    int drawn_number = distrib(gen);
    return to_string(drawn_number);         
}

    void checkattempt(const string& attempt, const string& drawn_number_digit) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < attempt.length(); i++) {
        if (drawn_number_digit[i] == attempt[i]) {
            SetConsoleTextAttribute(hConsole, 2);
            cout << attempt[i];
        } else {
            SetConsoleTextAttribute(hConsole, 4);
            cout << attempt[i];
        }
        SetConsoleTextAttribute(hConsole, 7);
    }           //checking the data entered by the player

    cout << endl;
}

int main ()            //Start of the program 
{
    while (true)                //A loop that allows you to return to the menu after the operation is completed 
    {           
        int Menunumber;

        cout << "Simple number guessing game"<<endl;
        cout << "Select mode:" <<endl;      
        cout << "1.Play (3-digit numbers)" <<endl;
        cout << "2.Play difficult mode (6-digit numbers)" <<endl;
        cout << "3.Play even more difficult mode (9-digit numbers)" <<endl;
        cout << "4.Leader board" <<endl;
        cout << "5.Exit" <<endl;
        cout << "Choose option 1, 2, 3, 4 or 5: ";

        cin >> Menunumber;
        switch (Menunumber)           //Main menu
        {
            case 1:             //3 digit guessing game
            {
            cout <<"Instruction:"<<endl; 
            cout << "The program will generate a random 3-digit number. The player's task is to guess this number by entering the numbers in the terminal. The correct number guessed will be displayed in green and the incorrect number will be displayed in red."<<endl;
            
            string mode = "3-digits";
            
            int a = 100;
            int b = 999;

            generatenumber(a,b);

            string drawn_number_digit = generatenumber(a,b);
            string attempt;
            
            int answer = 0;

            bool returntomenu = false;
            
            do               //A loop that waits for the player to guess the name
            {
                cout << "Enter a three-digit number or menu to return to menu: ";
                cin >> attempt;
                cout << answer + 1 << ": ";
                
                if (attempt =="menu")
                {
                returntomenu = true;

                break;
                }
                
                if (attempt.length() != 3 || !all_of(attempt.begin(), attempt.end(), ::isdigit)) 
                {
                cout << "Invalid input. Please enter a three-digit number." << endl;
                
                continue;
                }
                
                checkattempt(attempt, drawn_number_digit);
                
                answer++;              //The program checks whether the user enters the correct numbers and counts the number of attempts

            }
            while (drawn_number_digit != attempt  && !returntomenu);

            if (!returntomenu)
            {
                cout << "Congratulations! You guessed the number!" <<endl;               //Congratulations

                string name; 

                    do
                    {
                        cout << "Enter a name (exactly 5 characters); ";
                        cin >> name;
                    }
                    while (name.length() != 5);          
                    
                    savetofile(name, answer, mode);
            }
            system("pause");
            break;   
            }

            case 2:
            {
            cout <<"Instruction:"<<endl; 
            cout << "The program will generate a random 6-digit number. The player's task is to guess this number by entering the numbers in the terminal. The correct number guessed will be displayed in green and the incorrect number will be displayed in red."<<endl;
            
            string mode = "6-digits";

            int a = 100000;
            int b = 999999;

            generatenumber(a,b);

            string drawn_number_digit = generatenumber(a,b);
            string attempt;
            
            int answer = 0;
            
            bool returntomenu = false;
            
            do               //A loop that waits for the player to guess the name
            {
                cout << "Enter a six-digit number or menu to return to menu: ";
                cin >> attempt;
                cout << answer + 1 << ": ";
                
                if (attempt =="menu")
                {
                
                returntomenu = true;
                
                break;
                }
                
                if (attempt.length() != 6 || !all_of(attempt.begin(), attempt.end(), ::isdigit)) 
                {
                
                cout << "Invalid input. Please enter a three-digit number." << endl;
                
                continue;
                }
                
                checkattempt(attempt, drawn_number_digit);

                answer++;              //The program checks whether the user enters the correct numbers and counts the number of attempts

            }
            while (drawn_number_digit != attempt);
            
            if (!returntomenu)
            {
                cout << "Congratulations! You guessed the number!" <<endl;               //Congratulations

                string name;            
                
                    do
                    {
                        cout << "Enter a name (exactly 5 characters); ";
                        cin >> name;
                    }
                    while (name.length() != 5);          
                    
                    savetofile(name, answer, mode);
            }
            system("pause");
            break;   
            }
            case 3:
            {
            cout <<"Instruction:"<<endl; 
            cout << "The program will generate a random 9-digit number. The player's task is to guess this number by entering the numbers in the terminal. The correct number guessed will be displayed in green and the incorrect number will be displayed in red."<<endl;
            string mode = "9-digits";

            int a = 100000000;
            int b = 999999999;

            generatenumber(a,b);

            string drawn_number_digit = generatenumber(a,b);
            string attempt;
            
            int answer = 0;
            
            bool returntomenu = false;
            
            do               //A loop that waits for the player to guess the name
            {
                cout << "Enter a nine-digit number or menu to return to menu: ";
                cin >> attempt;
                cout << answer + 1 << ": ";
                
                if (attempt =="menu")
                {
                
                returntomenu = true;
                
                break;
                }
                
                if (attempt.length() != 9 || !all_of(attempt.begin(), attempt.end(), ::isdigit)) 
                {
                
                cout << "Invalid input. Please enter a three-digit number." << endl;
                
                continue;
                }
                
                checkattempt(attempt, drawn_number_digit);

                answer++;              //The program checks whether the user enters the correct numbers and counts the number of attempts

            }
            while (drawn_number_digit != attempt);
            
            if (!returntomenu)
            {
                cout << "Congratulations! You guessed the number!" <<endl;               //Congratulations

                string name;            
                
                    do
                    {
                        cout << "Enter a name (exactly 5 characters); ";
                        cin >> name;
                    }
                    while (name.length() != 5);          
                    
                    savetofile(name, answer, mode);
            }
            system("pause");
            break;   
            }
            case 4:
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
            
            case 5:
            {
                exit(0);         //Turning off the program
            break;
            }

            default:
            {
                if (cin.fail() || Menunumber < 1 || Menunumber > 5) 
                {
                
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

