//Making pac man game
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>
// #include "emoji.h"

using namespace std;
// using namespace emojicpp;

void display(string array[9][16], int);

void moveEnemy (string array[][16], string, string, string, string, int,int ,int ,int ,int ,int ,int, int, int, int);

void scan(string array[9][16], int &,int &,int &,int &,int &, int &, int &, int &, int &, int &);

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
    int userInput = 1, score = 0, current_row_character = 1, current_column_character = 1, current_column_enemy1, current_row_enemy1, current_row_enemy2, current_column_enemy2, current_row_enemy3, current_column_enemy3, current_row_enemy4, current_column_enemy4;
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

    scan (grid, current_row_character, current_column_character, current_row_enemy1, current_column_enemy1, current_row_enemy2, current_column_enemy2, current_row_enemy3, current_column_enemy3, current_row_enemy4, current_column_enemy4);

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
                if (grid[current_row_character- 1][current_column_character] == "0")
                {
                    grid[current_row_character- 1][current_column_character] = character;
                    grid[current_row_character][current_column_character] = "0";
                    current_row_character--;
                    moveEnemy(grid, enemy1, enemy2, enemy3, enemy4, current_row_character, current_column_character, current_row_enemy1, current_column_enemy1, current_row_enemy2, current_column_enemy2, current_row_enemy3, current_column_enemy3, current_row_enemy4, current_column_enemy4);
                }
                else if (grid[current_row_character- 1][current_column_character] == food)
                {
                    grid[current_row_character- 1][current_column_character] = character;
                    grid[current_row_character][current_column_character] = "0";
                    current_row_character--;
                    score += 20;
                    moveEnemy(grid, enemy1, enemy2, enemy3, enemy4, current_row_character, current_column_character, current_row_enemy1, current_column_enemy1, current_row_enemy2, current_column_enemy2, current_row_enemy3, current_column_enemy3, current_row_enemy4, current_column_enemy4);
                }
                else if ((grid[current_row_character - 1][current_column_character] == enemy1) || (grid[current_row_character - 1][current_column_character] == enemy2) || (grid[current_row_character - 1][current_column_character] == enemy3) || (grid[current_row_character - 1][current_column_character] == enemy4))
                {
                    cout << "\nYou lost";
                    return 0;
                }
                /*
                else if (grid[current_row_character- 1][current_column_character] == "42")
                {
                    system("cls");
                    grid[current_row_character- 1][current_column_character] = "XXXX";
                    grid[current_row_character][current_column_character] = "0";
                    display(grid, score);
                    cout << "\nYour character is dead";
                    exit (1);
                }
                */
                break;

            case KEY_DOWN:
                if (grid[current_row_character+ 1][current_column_character] == "0")
                {
                    grid[current_row_character+ 1][current_column_character] = character;
                    grid[current_row_character][current_column_character] = "0";
                    current_row_character++;
                }
                else if (grid[current_row_character+ 1][current_column_character] == food)
                {
                    grid[current_row_character+ 1][current_column_character] = character;
                    grid[current_row_character][current_column_character] = "0";
                    current_row_character++;
                    score += 20;
                }
                else if ((grid[current_row_character + 1][current_column_character] == enemy1) || (grid[current_row_character + 1][current_column_character] == enemy2) || (grid[current_row_character + 1][current_column_character] == enemy3) || (grid[current_row_character + 1][current_column_character] == enemy4))
                {
                    cout << "\nYou lost";
                    return 0;
                }
                /*
                else if (grid[current_row_character+ 1][current_column_character] == "42")
                {
                    system("cls");
                    grid[current_row_character+ 1][current_column_character] = "XXXX";
                    grid[current_row_character][current_column_character] = "0";
                    display(grid, score);
                    cout << "\nYour character is dead";
                    exit (1);
                }
                */
                break;
            
            case KEY_LEFT:
                if (grid[current_row_character][current_column_character - 1] == "0")
                {
                    grid[current_row_character][current_column_character - 1] = character;
                    grid[current_row_character][current_column_character] = "0";
                    current_column_character--;
                }
                else if (grid[current_row_character][current_column_character - 1] == food)
                {
                    grid[current_row_character][current_column_character - 1] = character;
                    grid[current_row_character][current_column_character] = "0";
                    current_column_character--;
                    score += 20;
                }
                else if ((grid[current_row_character][current_column_character - 1] == enemy1) || (grid[current_row_character][current_column_character - 1] == enemy2) || (grid[current_row_character][current_column_character - 1] == enemy3) || (grid[current_row_character][current_column_character - 1] == enemy4))
                {
                    cout << "\nYou lost";
                    return 0;
                }
                /*
                else if (grid[current_row_character][current_column_character - 1] == "42")
                {
                    system("cls");
                    grid[current_row_character][current_column_character - 1] = "XXXX";
                    grid[current_row_character][current_column_character] = "0";
                    display(grid, score);
                    cout << "\nYour character is dead";
                    exit (1);
                }
                */
                break;

            case KEY_RIGHT:
                if (grid[current_row_character][current_column_character + 1] == "0")
                {
                    grid[current_row_character][current_column_character + 1] = character;
                    grid[current_row_character][current_column_character] = "0";
                    current_column_character++;
                }
                else if (grid[current_row_character][current_column_character + 1] == food)
                {
                    system("cls");
                    grid[current_row_character][current_column_character + 1] = character;
                    grid[current_row_character][current_column_character] = "0";
                    current_column_character++;
                    score += 20;
                }
                else if ((grid[current_row_character][current_column_character + 1] == enemy1) || (grid[current_row_character][current_column_character + 1] == enemy2) || (grid[current_row_character][current_column_character + 1] == enemy3) || (grid[current_row_character][current_column_character + 1] == enemy4))
                {
                    cout << "\nYou lost";
                    return 0;
                }
                /*
                else if (grid[current_row_character][current_column_character + 1] == "42")
                {
                    system("cls");
                    grid[current_row_character][current_column_character + 1] = "XXXX";
                    grid[current_row_character][current_column_character] = "0";
                    display(grid, score);
                    cout << "\nYour character is dead";
                    exit (1);
                }*/
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

void moveEnemy (string array[9][16], string a, string b, string c, string d, int current_row_character, int current_column_character, int current_row_enemy1,int current_column_enemy1,int current_row_enemy2,int current_column_enemy2,int current_row_enemy3,int current_column_enemy3,int current_row_enemy4, int current_column_enemy4)
{
    int movement;
    while (1) // enemy 1
    {
        movement = rand () % 4 + 1;
        if (movement == 1)  //up
        {
            if (array[current_row_enemy1 - 1][current_column_enemy1] == "0")
            {
                array[current_row_enemy1 - 1][current_column_enemy1] = enemy1;
                array[current_row_enemy1][current_column_enemy1] = "0";
                current_row_enemy1--;
            }
            else if (array[current_row_enemy1 - 1][current_column_enemy1] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy1 - 1][current_column_enemy1] == food)
            {
                if (array[current_row_enemy1 - 2][current_column_enemy1] == "0")
                {
                    array[current_row_enemy1 - 2][current_column_enemy1] = enemy1;
                    array[current_row_enemy1][current_column_enemy1] == "0";
                    current_row_enemy1 -= 2;
                }
                else if (array[current_row_enemy1 - 2][current_column_enemy1] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }


        else if (movement == 2)  //down
        {
            if (array[current_row_enemy1 + 1][current_column_enemy1] == "0")
            {
                array[current_row_enemy1 + 1][current_column_enemy1] = enemy1;
                array[current_row_enemy1][current_column_enemy1] = "0";
                current_row_enemy1++;
            }
            else if (array[current_row_enemy1 + 1][current_column_enemy1] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy1 + 1][current_column_enemy1] == food)
            {
                if (array[current_row_enemy1 + 2][current_column_enemy1] == "0")
                {
                    array[current_row_enemy1 + 2][current_column_enemy1] = enemy1;
                    array[current_row_enemy1][current_column_enemy1] == "0";
                    current_row_enemy1 += 2;
                }
                else if (array[current_row_enemy1 + 2][current_column_enemy1] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }
        else if (movement == 3)  //left
        {
            if (array[current_row_enemy1][current_column_enemy1 - 1] == "0")
            {
                array[current_row_enemy1][current_column_enemy1 - 1] = enemy1;
                array[current_row_enemy1][current_column_enemy1] = "0";
                current_column_enemy1--;
            }
            else if (array[current_row_enemy1][current_column_enemy1 - 1] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy1][current_column_enemy1 - 1] == food)
            {
                if (array[current_row_enemy1][current_column_enemy1 - 2] == "0")
                {
                    array[current_row_enemy1][current_column_enemy1 - 2] = enemy1;
                    array[current_row_enemy1][current_column_enemy1] == "0";
                    current_column_enemy1 -= 2;
                }
                else if (array[current_row_enemy1][current_column_enemy1 - 2] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }
        else if (movement == 4)  //right
        {
            if (array[current_row_enemy1][current_column_enemy1 + 1] == "0")
            {
                array[current_row_enemy1][current_column_enemy1 + 1] = enemy1;
                array[current_row_enemy1][current_column_enemy1] = "0";
                current_column_enemy1++;
            }
            else if (array[current_row_enemy1][current_column_enemy1 + 1] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy1][current_column_enemy1 + 1] == food)
            {
                if (array[current_row_enemy1][current_column_enemy1 + 2] == "0")
                {
                    array[current_row_enemy1][current_column_enemy1 + 2] = enemy1;
                    array[current_row_enemy1][current_column_enemy1] == "0";
                    current_column_enemy1 += 2;
                }
                else if (array[current_row_enemy1][current_column_enemy1 + 2] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }
        else
        {
            cout << "\nError: 294";
        }

        break;
    }

    while (1) //enemy 2
    {
        movement = rand () % 4 + 1;
        if (movement == 1)  //up
        {
            if (array[current_row_enemy2 - 1][current_column_enemy2] == "0")
            {
                array[current_row_enemy2 - 1][current_column_enemy2] = enemy1;
                array[current_row_enemy2][current_column_enemy2] = "0";
                current_row_enemy2--;
            }
            else if (array[current_row_enemy2 - 1][current_column_enemy2] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy2 - 1][current_column_enemy2] == food)
            {
                if (array[current_row_enemy2 - 2][current_column_enemy2] == "0")
                {
                    array[current_row_enemy2 - 2][current_column_enemy2] = enemy1;
                    array[current_row_enemy2][current_column_enemy2] == "0";
                    current_row_enemy2 -= 2;
                }
                else if (array[current_row_enemy2 - 2][current_column_enemy2] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }


        else if (movement == 2)  //down
        {
            if (array[current_row_enemy2 + 1][current_column_enemy2] == "0")
            {
                array[current_row_enemy2 + 1][current_column_enemy2] = enemy1;
                array[current_row_enemy2][current_column_enemy2] = "0";
                current_row_enemy2++;
            }
            else if (array[current_row_enemy2 + 1][current_column_enemy2] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy2 + 1][current_column_enemy2] == food)
            {
                if (array[current_row_enemy2 + 2][current_column_enemy2] == "0")
                {
                    array[current_row_enemy2 + 2][current_column_enemy2] = enemy1;
                    array[current_row_enemy2][current_column_enemy2] == "0";
                    current_row_enemy2 += 2;
                }
                else if (array[current_row_enemy2 + 2][current_column_enemy2] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }
        else if (movement == 3)  //left
        {
            if (array[current_row_enemy2][current_column_enemy2 - 1] == "0")
            {
                array[current_row_enemy2][current_column_enemy2 - 1] = enemy1;
                array[current_row_enemy2][current_column_enemy2] = "0";
                current_column_enemy2--;
            }
            else if (array[current_row_enemy2][current_column_enemy2 - 1] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy2][current_column_enemy2 - 1] == food)
            {
                if (array[current_row_enemy2][current_column_enemy2 - 2] == "0")
                {
                    array[current_row_enemy2][current_column_enemy2 - 2] = enemy1;
                    array[current_row_enemy2][current_column_enemy2] == "0";
                    current_column_enemy2 -= 2;
                }
                else if (array[current_row_enemy2][current_column_enemy2 - 2] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }
        else if (movement == 4)  //right
        {
            if (array[current_row_enemy2][current_column_enemy2 + 1] == "0")
            {
                array[current_row_enemy2][current_column_enemy2 + 1] = enemy1;
                array[current_row_enemy2][current_column_enemy2] = "0";
                current_column_enemy2++;
            }
            else if (array[current_row_enemy2][current_column_enemy2 + 1] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy2][current_column_enemy2 + 1] == food)
            {
                if (array[current_row_enemy2][current_column_enemy2 + 2] == "0")
                {
                    array[current_row_enemy2][current_column_enemy2 + 2] = enemy1;
                    array[current_row_enemy2][current_column_enemy2] == "0";
                    current_column_enemy2 += 2;
                }
                else if (array[current_row_enemy2][current_column_enemy2 + 2] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }
        else
        {
            cout << "\nError: 294";
        }

        break;
    }

    while (1) //enemy 3
    {
        movement = rand () % 4 + 1;
        if (movement == 1)  //up
        {
            if (array[current_row_enemy3 - 1][current_column_enemy3] == "0")
            {
                array[current_row_enemy3 - 1][current_column_enemy3] = enemy1;
                array[current_row_enemy3][current_column_enemy3] = "0";
                current_row_enemy3--;
            }
            else if (array[current_row_enemy3 - 1][current_column_enemy3] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy3 - 1][current_column_enemy3] == food)
            {
                if (array[current_row_enemy3 - 2][current_column_enemy3] == "0")
                {
                    array[current_row_enemy3 - 2][current_column_enemy3] = enemy1;
                    array[current_row_enemy3][current_column_enemy3] == "0";
                    current_row_enemy3 -= 2;
                }
                else if (array[current_row_enemy3 - 2][current_column_enemy3] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }


        else if (movement == 2)  //down
        {
            if (array[current_row_enemy3 + 1][current_column_enemy3] == "0")
            {
                array[current_row_enemy3 + 1][current_column_enemy3] = enemy1;
                array[current_row_enemy3][current_column_enemy3] = "0";
                current_row_enemy3++;
            }
            else if (array[current_row_enemy3 + 1][current_column_enemy3] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy3 + 1][current_column_enemy3] == food)
            {
                if (array[current_row_enemy3 + 2][current_column_enemy3] == "0")
                {
                    array[current_row_enemy3 + 2][current_column_enemy3] = enemy1;
                    array[current_row_enemy3][current_column_enemy3] == "0";
                    current_row_enemy3 += 2;
                }
                else if (array[current_row_enemy3 + 2][current_column_enemy3] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }
        else if (movement == 3)  //left
        {
            if (array[current_row_enemy3][current_column_enemy3 - 1] == "0")
            {
                array[current_row_enemy3][current_column_enemy3 - 1] = enemy1;
                array[current_row_enemy3][current_column_enemy3] = "0";
                current_column_enemy3--;
            }
            else if (array[current_row_enemy3][current_column_enemy3 - 1] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy3][current_column_enemy3 - 1] == food)
            {
                if (array[current_row_enemy3][current_column_enemy3 - 2] == "0")
                {
                    array[current_row_enemy3][current_column_enemy3 - 2] = enemy1;
                    array[current_row_enemy3][current_column_enemy3] == "0";
                    current_column_enemy3 -= 2;
                }
                else if (array[current_row_enemy3][current_column_enemy3 - 2] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }
        else if (movement == 4)  //right
        {
            if (array[current_row_enemy3][current_column_enemy3 + 1] == "0")
            {
                array[current_row_enemy3][current_column_enemy3 + 1] = enemy1;
                array[current_row_enemy3][current_column_enemy3] = "0";
                current_column_enemy3++;
            }
            else if (array[current_row_enemy3][current_column_enemy3 + 1] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy3][current_column_enemy3 + 1] == food)
            {
                if (array[current_row_enemy3][current_column_enemy3 + 2] == "0")
                {
                    array[current_row_enemy3][current_column_enemy3 + 2] = enemy1;
                    array[current_row_enemy3][current_column_enemy3] == "0";
                    current_column_enemy3 += 2;
                }
                else if (array[current_row_enemy3][current_column_enemy3 + 2] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }
        else
        {
            cout << "\nError: 618";
        }

        break;
    }

    while (1)  //enemy 4
    {
        movement = rand () % 4 + 1;
        if (movement == 1)  //up
        {
            if (array[current_row_enemy4 - 1][current_column_enemy4] == "0")
            {
                array[current_row_enemy4 - 1][current_column_enemy4] = enemy1;
                array[current_row_enemy4][current_column_enemy4] = "0";
                current_row_enemy4--;
            }
            else if (array[current_row_enemy4 - 1][current_column_enemy4] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy4 - 1][current_column_enemy4] == food)
            {
                if (array[current_row_enemy4 - 2][current_column_enemy4] == "0")
                {
                    array[current_row_enemy4 - 2][current_column_enemy4] = enemy1;
                    array[current_row_enemy4][current_column_enemy4] == "0";
                    current_row_enemy4 -= 2;
                }
                else if (array[current_row_enemy4 - 2][current_column_enemy4] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }


        else if (movement == 2)  //down
        {
            if (array[current_row_enemy4 + 1][current_column_enemy4] == "0")
            {
                array[current_row_enemy4 + 1][current_column_enemy4] = enemy1;
                array[current_row_enemy4][current_column_enemy4] = "0";
                current_row_enemy4++;
            }
            else if (array[current_row_enemy4 + 1][current_column_enemy4] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy4 + 1][current_column_enemy4] == food)
            {
                if (array[current_row_enemy4 + 2][current_column_enemy4] == "0")
                {
                    array[current_row_enemy4 + 2][current_column_enemy4] = enemy1;
                    array[current_row_enemy4][current_column_enemy4] == "0";
                    current_row_enemy4 += 2;
                }
                else if (array[current_row_enemy4 + 2][current_column_enemy4] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }
        else if (movement == 3)  //left
        {
            if (array[current_row_enemy4][current_column_enemy4 - 1] == "0")
            {
                array[current_row_enemy4][current_column_enemy4 - 1] = enemy1;
                array[current_row_enemy4][current_column_enemy4] = "0";
                current_column_enemy4--;
            }
            else if (array[current_row_enemy4][current_column_enemy4 - 1] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy4][current_column_enemy4 - 1] == food)
            {
                if (array[current_row_enemy4][current_column_enemy4 - 2] == "0")
                {
                    array[current_row_enemy4][current_column_enemy4 - 2] = enemy1;
                    array[current_row_enemy4][current_column_enemy4] == "0";
                    current_column_enemy4 -= 2;
                }
                else if (array[current_row_enemy4][current_column_enemy4 - 2] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }
        else if (movement == 4)  //right
        {
            if (array[current_row_enemy4][current_column_enemy4 + 1] == "0")
            {
                array[current_row_enemy4][current_column_enemy4 + 1] = enemy1;
                array[current_row_enemy4][current_column_enemy4] = "0";
                current_column_enemy4++;
            }
            else if (array[current_row_enemy4][current_column_enemy4 + 1] == character)
            {
                cout << "\nYou lost!";
                exit (0);
            }
            else if (array[current_row_enemy4][current_column_enemy4 + 1] == food)
            {
                if (array[current_row_enemy4][current_column_enemy4 + 2] == "0")
                {
                    array[current_row_enemy4][current_column_enemy4 + 2] = enemy1;
                    array[current_row_enemy4][current_column_enemy4] == "0";
                    current_column_enemy4 += 2;
                }
                else if (array[current_row_enemy4][current_column_enemy4 + 2] == character)
                {
                    cout << "\nYou lost!";
                    exit (0);
                }
            }
            else
                continue;
        }
        else
        {
            cout << "\nError: 751";
        }

        break;
    }
}

void scan (string array[][16],int &current_row_character, int &current_column_character, int &current_row_enemy1,int &current_column_enemy1,int &current_row_enemy2,int &current_column_enemy2,int &current_row_enemy3,int &current_column_enemy3,int &current_row_enemy4, int &current_column_enemy4)
{
    //character
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; i < 16; j++)
        {
            if (array[i][j] == character)
            {
                current_row_character = i;
                current_column_character = j;
            }
        }
    }
    
    //enemy 1
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; i < 16; j++)
        {
            if (array[i][j] == enemy1)
            {
                current_row_enemy1 = i;
                current_column_enemy1 = j;
            }
        }
    }

    //enemy 2
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; i < 16; j++)
        {
            if (array[i][j] == enemy2)
            {
                current_row_enemy2 = i;
                current_column_enemy2= j;
            }
        }
    }

    //enemy 3
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; i < 16; j++)
        {
            if (array[i][j] == enemy3)
            {
                current_row_enemy3 = i;
                current_column_enemy3= j;
            }
        }
    }

    //enemy 4
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; i < 16; j++)
        {
            if (array[i][j] == enemy4)
            {
                current_row_enemy4 = i;
                current_column_enemy4= j;
            }
        }
    }
}