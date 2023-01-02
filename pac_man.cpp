//Making pac man game
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>
// #include "emoji.h"

using namespace std;
// using namespace emojicpp;

void display(string array[9][16], int);

void moveEnemy (string, string, string, string);

#define row 9
#define column 16
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27

const string character =  "sheikh" /* emojize(":mouse2:") */;
const string food = "33";
const string enemy1 = "GREEN";
const string enemy2 = "RED";
const string enemy3 = "BLUE";
const string enemy4 = "PINK";

int main()
{
    int userInput = 1, score = 0, current_row = 1, current_column = 1;
    string rules;
    cout << "******WELCOME TO PAC MAN GAME******";

    //Reading from a file
    ifstream read_file;
    read_file.open("manual.txt");

    if(read_file.fail())
    {
        cout << endl << "Conldn't open the required file\nmake sure you have \"manual.txt\" in your current directory.";
        exit (1);
    }

    while (!read_file.eof())
    {
        getline (read_file, rules, '\n');
        cout << endl << rules << endl;
    }

    string grid [row][column]={{"42", "42", "42", "42", "42", "42", "42", "42", "42", "42", "42", "42", "42", "42", "42", "42"},
                            {"42", character,  "0",  "0", "-1",  food,  "0",  "0", "-1",  "0", "-1",  enemy3,  "0",  "0",  "0", "42"},
                            {"42", "-1", "-1",  "0", "-1", "-1", "-1",  "0", "-1",  food, "-1",  "0", "-1", "-1", "-1", "42"},
                            {"42", "-1", "-1",  food, "-1", "-1", "-1",  enemy2, "-1",  "0", "-1",  "0", "-1", "-1", "-1", "42"},
                            {"42",  "0",  "0",  "0",  "0",  "0", "-1",  "0",  "0",  "0", "-1",  "0",  "0",  "0",  food, "42"},
                            {"42",  "0", "-1", "-1", "-1",  food, "-1",  "0", "-1",  "0", "-1",  "0", "-1", "-1",  "0", "42"},
                            {"42",  "0", "-1", "-1", "-1",  food, "-1",  "0", "-1",  "0", "-1",  "0", "-1", "-1",  "0", "42"},
                            {"42",  enemy1, "-1", food,  "0",  "0",  "0",  "0", "-1",  "0",  "0",  "0", "-1", "-1",  enemy4, "42"},
                            {"42", "42", "42", "42", "42", "42", "42", "42", "42", "42", "42", "42", "42", "42", "42", "42"}};

    while(1)
    {
        if (userInput != 0)
            display(grid, score);

        if (score == 140)
        {
            system("cls");
            cout << "*****HURRAY! YOU WON*****";
            return 0;
        }

        switch (userInput = _getch())
            {
            case KEY_UP:
                if (grid[current_row - 1][current_column] == "0")
                {
                    grid[current_row - 1][current_column] = character;
                    grid[current_row][current_column] = "0";
                    current_row--;
                    
                }
                else if (grid[current_row - 1][current_column] == food)
                {
                    grid[current_row - 1][current_column] = character;
                    grid[current_row][current_column] = "0";
                    current_row--;
                    score += 20;
                }
                else if (grid[current_row - 1][current_column] == enemy)
                {
                    moveEnemy();
                }
                
                else if (grid[current_row - 1][current_column] == "42")
                {
                    system("cls");
                    grid[current_row - 1][current_column] = "XXXX";
                    grid[current_row][current_column] = "0";
                    display(grid, score);
                    cout << "\nYour character is dead";
                    exit (1);
                }
                break;

            case KEY_DOWN:
                if (grid[current_row + 1][current_column] == "0")
                {
                    grid[current_row + 1][current_column] = character;
                    grid[current_row][current_column] = "0";
                    current_row++;
                }
                else if (grid[current_row + 1][current_column] == food)
                {
                    grid[current_row + 1][current_column] = character;
                    grid[current_row][current_column] = "0";
                    current_row++;
                    score += 20;
                }
                else if (grid[current_row + 1][current_column] == "42")
                {
                    system("cls");
                    grid[current_row + 1][current_column] = "XXXX";
                    grid[current_row][current_column] = "0";
                    display(grid, score);
                    cout << "\nYour character is dead";
                    exit (1);
                }
                break;
            
            case KEY_LEFT:
                if (grid[current_row][current_column - 1] == "0")
                {
                    grid[current_row][current_column - 1] = character;
                    grid[current_row][current_column] = "0";
                    current_column--;
                }
                else if (grid[current_row][current_column - 1] == food)
                {
                    grid[current_row][current_column - 1] = character;
                    grid[current_row][current_column] = "0";
                    current_column--;
                    score += 20;
                }
                else if (grid[current_row][current_column - 1] == "42")
                {
                    system("cls");
                    grid[current_row][current_column - 1] = "XXXX";
                    grid[current_row][current_column] = "0";
                    display(grid, score);
                    cout << "\nYour character is dead";
                    exit (1);
                }
                break;

            case KEY_RIGHT:
                if (grid[current_row][current_column + 1] == "0")
                {
                    grid[current_row][current_column + 1] = character;
                    grid[current_row][current_column] = "0";
                    current_column++;
                }
                else if (grid[current_row][current_column + 1] == food)
                {
                    system("cls");
                    grid[current_row][current_column + 1] = character;
                    grid[current_row][current_column] = "0";
                    current_column++;
                    score += 20;
                }
                else if (grid[current_row][current_column + 1] == "42")
                {
                    system("cls");
                    grid[current_row][current_column + 1] = "XXXX";
                    grid[current_row][current_column] = "0";
                    display(grid, score);
                    cout << "\nYour character is dead";
                    exit (1);
                }
                break;

            case ESC:
                exit(0);
                break;

            default:
                userInput = 0;
                break;
            }

        if (userInput == 0)
            continue;

        system("cls");
    }

    return 0;
}

void display(string array[9][16], int score)
{
    cout << endl << "Score: " << score;
    for (int i = 0; i < row; i++)
    {
        cout << endl << endl;
        for (int j = 0; j < column; j++)
        {
            cout << setw(8) << array[i][j];
        }
    }
}