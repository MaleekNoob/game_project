void scan(string array[][16],int &current_row_character, int &current_column_character, int &current_row_enemy1,int &current_column_enemy1,int &current_row_enemy2,int &current_column_enemy2,int &current_row_enemy3,int &current_column_enemy3,int &current_row_enemy4, int &current_column_enemy4)
{
    //character
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 16; j++)
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
        for (int j = 0; j < 16; j++)
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
        for (int j = 0; j < 16; j++)
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
        for (int j = 0; j < 16; j++)
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
        for (int j = 0; j < 16; j++)
        {
            if (array[i][j] == enemy4)
            {
                current_row_enemy4 = i;
                current_column_enemy4= j;
            }
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
