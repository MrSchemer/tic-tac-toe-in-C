#include <stdio.h>

void ShowBoard(char x[], char o[])
{
    char one = (x[0] == 'X') ? 'X' : (o[0] == 'O') ? 'O'
                                                   : '1';
    char two = (x[1] == 'X') ? 'X' : (o[1] == 'O') ? 'O'
                                                   : '2';
    char three = (x[2] == 'X') ? 'X' : (o[2] == 'O') ? 'O'
                                                     : '3';
    char four = (x[3] == 'X') ? 'X' : (o[3] == 'O') ? 'O'
                                                    : '4';
    char five = (x[4] == 'X') ? 'X' : (o[4] == 'O') ? 'O'
                                                    : '5';
    char six = (x[5] == 'X') ? 'X' : (o[5] == 'O') ? 'O'
                                                   : '6';
    char seven = (x[6] == 'X') ? 'X' : (o[6] == 'O') ? 'O'
                                                     : '7';
    char eight = (x[7] == 'X') ? 'X' : (o[7] == 'O') ? 'O'
                                                     : '8';
    char nine = (x[8] == 'X') ? 'X' : (o[8] == 'O') ? 'O'
                                                    : '9';

    printf(" %c | %c | %c \n", one, two, three);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", four, five, six);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", seven, eight, nine);
}
int checkWin(char x[], char o[])
{
    int wins[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};

    for (int i = 0; i < 8; i++)
    {
        int X = 0;
        int O = 0;

        for (int j = 0; j < 3; j++)
        {
            if (x[wins[i][j]] == 'X')
            {
                X++;
            }
            else if (o[wins[i][j]] == 'O')
            {
                O++;
            }
        }

        if (X == 3)
        {
            printf("X wins\n");
            return 1;
        }

        if (O == 3)
        {
            printf("O wins\n");
            return 0;
        }
    }

    return -1;
}

int main()
{
    int turn = 1, entered;
    char xstatus[9] = {'0', '0', '0', '0', '0', '0', '0', '0', '0'}, ostatus[9] = {'0', '0', '0', '0', '0', '0', '0', '0', '0'};
    while (1 == 1)
    {
        ShowBoard(xstatus, ostatus);
        if (turn == 1)
        {
            printf("\nX's turn\nEnter Position of 'X':");
            scanf("%d", &entered);
            if (entered > 9 || xstatus[entered - 1] != '0' || ostatus[entered - 1] != '0')
            {

                printf("enter in range and remaining options");
                continue;
            }

            xstatus[entered - 1] = 'X';
        }
        else
        {
            printf("O's turn\nEnter Position of 'O':");
            scanf("%d", &entered);
            if (entered > 9 || (xstatus[entered - 1] != '0' || ostatus[entered - 1] != '0'))
            {

                printf("enter in range and remaining options\n");
                continue;
            }
            ostatus[entered - 1] = 'O';
        }
        int result = checkWin(xstatus, ostatus);
        if (result == 1)
        {
            printf("!!!!!!!!!!!!!!!!!!!!X win!!!!!!!!!!!!!!!!!!");
            break;
        }
        else if (result == 0)
        {
            printf("!!!!!!!!!!!!!!!!!!!!O win!!!!!!!!!!!!!!!!!!");
            break;
        }
        // check if board is complete or not
        int countxo = 0;
        for (int i = 0; i < 9; i++)
        {
            if (xstatus[i] != '0')
            {
                countxo += 1;
            }
            else if (ostatus[i] != '0')
            {
                countxo += 1;
            }
        }
        if (countxo == 9)
        {
            ShowBoard(xstatus, ostatus);
            break;
        }

        turn = 1 - turn;
    }

    return 0;
}  