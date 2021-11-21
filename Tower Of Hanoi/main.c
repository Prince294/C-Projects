#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int peg_A_Disk[50], peg_B_Disk[50] = {0}, peg_C_Disk[50] = {0};
int Peg_A, Peg_B = 0, Peg_C = 0;
int Disk, turn = 0;

void movement(char Source, char Destination)
{
    delay(25000);
    // getch();
    int Disk_no;
    if (Source == 'A')
    {
        Disk_no = peg_A_Disk[Peg_A];
        if (Destination == 'B')
        {
            ++Peg_B;
            peg_B_Disk[Peg_B] = Disk_no;
            diskMove(2, Disk_no, 1);
        }
        else if (Destination == 'C')
        {
            ++Peg_C;
            peg_C_Disk[Peg_C] = Disk_no;
            diskMove(3, Disk_no, 1);
        }
        --Peg_A;
        removeDisk(Disk_no, 1, 'A');
    }
    else if (Source == 'B')
    {
        Disk_no = peg_B_Disk[Peg_B];
        if (Destination == 'A')
        {
            ++Peg_A;
            peg_A_Disk[Peg_A] = Disk_no;
            diskMove(1, Disk_no, 2);
        }
        else if (Destination == 'C')
        {
            ++Peg_C;
            peg_C_Disk[Peg_C] = Disk_no;
            diskMove(3, Disk_no, 2);
        }
        --Peg_B;
        removeDisk(Disk_no, 2, 'B');
    }
    else if (Source == 'C')
    {
        Disk_no = peg_C_Disk[Peg_C];
        if (Destination == 'A')
        {
            ++Peg_A;
            peg_A_Disk[Peg_A] = Disk_no;
            diskMove(1, Disk_no, 3);
        }
        else if (Destination == 'B')
        {
            ++Peg_B;
            peg_B_Disk[Peg_B] = Disk_no;
            diskMove(2, Disk_no, 3);
        }
        --Peg_C;
        removeDisk(Disk_no, 3, 'C');
    }
    // gotoxy(0, 40);
    // printf("%d=%d, %d=%d, %d=%d", Peg_A, peg_A_Disk[Peg_A], Peg_B, peg_B_Disk[Peg_B], Peg_C, peg_C_Disk[Peg_C]);
}

//Functions for designing purpose
void tower(int Disk)
{
    int X, Y;
    for (int i = 0; i < (Disk * 2) + 2; i++)
    {
        X = 30, Y = i + 10;
        for (int j = 0; j < 3; j++)
        {
            gotoxy(X, Y);
            printf("*");
            X = X + 32;
        }
    }
}

void diskMove(int peg, int disk_no, int fromDisk)
{
    int X = (30 + (32 * (peg - 1))) - (disk_no / 2), Y = (Disk * 2) + 11;
    int X1 = (30 + (32 * (fromDisk - 1)) - (disk_no / 2)), Y1 = Y;

    if (peg == 3)
    {
        Y -= Peg_C * 2 - 2;
        if (fromDisk == 1)
        {
            Y1 -= Peg_A * 2 - 2;
            while (Y1 > 5)
            {
                gotoxy(X1, --Y1);
                delay(4000);
                for (int i = 1; i <= peg_A_Disk[Peg_A]; i++)
                {
                    printf("*");
                }
                gotoxy(X1, Y1 + 1);
                for (int i = 1; i <= peg_A_Disk[Peg_A]; i++)
                {
                    if (i == ((peg_A_Disk[Peg_A] / 2) + 1) && (Y1 + 1 >= 10))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
            while (X1 < X)
            {
                gotoxy(X1++, Y1);
                delay(2000);
                for (int i = 0; i <= peg_A_Disk[Peg_A]; i++)
                {
                    printf("*");
                }
                gotoxy(X1 - 1, Y1);
                printf(" ");
            }
            while (Y1 < Y)
            {
                gotoxy(X1, ++Y1);
                delay(4000);
                for (int i = 1; i <= peg_A_Disk[Peg_A]; i++)
                {
                    printf("*");
                }
                gotoxy(X1, Y1 - 1);
                for (int i = 1; i <= peg_A_Disk[Peg_A]; i++)
                {
                    if (i == ((peg_A_Disk[Peg_A] / 2) + 1) && (Y1 + 1 >= 12))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
        }
        else if (fromDisk == 2)
        {
            Y1 -= Peg_B * 2 - 2;
            while (Y1 > 5)
            {
                gotoxy(X1, --Y1);
                delay(4000);
                for (int i = 1; i <= peg_B_Disk[Peg_B]; i++)
                {
                    printf("*");
                }
                gotoxy(X1, Y1 + 1);
                for (int i = 1; i <= peg_B_Disk[Peg_B]; i++)
                {
                    if (i == ((peg_B_Disk[Peg_B] / 2) + 1) && (Y1 + 1 >= 10))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
            while (X1 < X)
            {
                gotoxy(X1++, Y1);
                delay(2000);
                for (int i = 0; i <= peg_B_Disk[Peg_B]; i++)
                {
                    printf("*");
                }
                gotoxy(X1 - 1, Y1);
                printf(" ");
            }
            while (Y1 < Y)
            {
                gotoxy(X1, ++Y1);
                delay(4000);
                for (int i = 1; i <= peg_B_Disk[Peg_B]; i++)
                {
                    printf("*");
                }
                gotoxy(X1, Y1 - 1);
                for (int i = 1; i <= peg_B_Disk[Peg_B]; i++)
                {
                    if (i == ((peg_B_Disk[Peg_B] / 2) + 1) && (Y1 + 1 >= 12))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
        }
    }

    if (peg == 2)
    {
        Y -= Peg_B * 2 - 2;
        if (fromDisk == 1)
        {
            Y1 -= Peg_A * 2 - 2;
            while (Y1 > 5)
            {
                gotoxy(X1, --Y1);
                delay(4000);
                for (int i = 1; i <= peg_A_Disk[Peg_A]; i++)
                {
                    printf("*");
                }
                gotoxy(X1, Y1 + 1);
                for (int i = 1; i <= peg_A_Disk[Peg_A]; i++)
                {
                    if (i == ((peg_A_Disk[Peg_A] / 2) + 1) && (Y1 + 1 >= 10))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
            while (X1 < X)
            {
                gotoxy(X1++, Y1);
                delay(2000);
                for (int i = 0; i <= peg_A_Disk[Peg_A]; i++)
                {
                    printf("*");
                }
                gotoxy(X1 - 1, Y1);
                printf(" ");
            }
            while (Y1 < Y)
            {
                gotoxy(X1, ++Y1);
                delay(4000);
                for (int i = 1; i <= peg_A_Disk[Peg_A]; i++)
                {
                    printf("*");
                }
                gotoxy(X1, Y1 - 1);
                for (int i = 1; i <= peg_A_Disk[Peg_A]; i++)
                {
                    if (i == ((peg_A_Disk[Peg_A] / 2) + 1) && (Y1 + 1 >= 12))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
        }
        else if (fromDisk == 3)
        {
            Y1 -= Peg_C * 2 - 2;
            while (Y1 > 5)
            {
                gotoxy(X1, --Y1);
                delay(4000);
                for (int i = 1; i <= peg_C_Disk[Peg_C]; i++)
                {
                    printf("*");
                }
                gotoxy(X1, Y1 + 1);
                for (int i = 1; i <= peg_C_Disk[Peg_C]; i++)
                {
                    if (i == ((peg_C_Disk[Peg_C] / 2) + 1) && (Y1 + 1 >= 10))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
            while (X1 > X)
            {
                gotoxy(X1--, Y1);
                delay(3000);
                for (int i = 1; i <= peg_C_Disk[Peg_C]; i++)
                {
                    printf("*");
                }
                gotoxy(X1 + peg_C_Disk[Peg_C], Y1);
                printf(" ");
            }
            while (Y1 < Y)
            {
                gotoxy(X1, ++Y1);
                delay(4000);
                for (int i = 1; i <= peg_C_Disk[Peg_C]; i++)
                {
                    printf("*");
                }
                gotoxy(X1, Y1 - 1);
                for (int i = 1; i <= peg_C_Disk[Peg_C]; i++)
                {
                    if (i == ((peg_C_Disk[Peg_C] / 2) + 1) && (Y1 + 1 >= 12))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
        }
    }

    if (peg == 1)
    {
        Y -= Peg_A * 2 - 2;
        if (fromDisk == 2)
        {
            Y1 -= Peg_B * 2 - 2;
            while (Y1 > 5)
            {
                gotoxy(X1, --Y1);
                delay(4000);
                for (int i = 1; i <= peg_B_Disk[Peg_B]; i++)
                {
                    printf("*");
                }
                gotoxy(X1, Y1 + 1);
                for (int i = 1; i <= peg_B_Disk[Peg_B]; i++)
                {
                    if (i == ((peg_B_Disk[Peg_B] / 2) + 1) && (Y1 + 1 >= 10))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
            while (X1 > X)
            {
                gotoxy(X1--, Y1);
                delay(3000);
                for (int i = 1; i <= peg_B_Disk[Peg_B]; i++)
                {
                    printf("*");
                }
                gotoxy(X1 + peg_B_Disk[Peg_B], Y1);
                printf(" ");
            }
            while (Y1 < Y)
            {
                gotoxy(X1, ++Y1);
                delay(4000);
                for (int i = 1; i <= peg_B_Disk[Peg_B]; i++)
                {
                    printf("*");
                }
                gotoxy(X1, Y1 - 1);
                for (int i = 1; i <= peg_B_Disk[Peg_B]; i++)
                {
                    if (i == ((peg_B_Disk[Peg_B] / 2) + 1) && (Y1 + 1 >= 12))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
        }
        else if (fromDisk == 3)
        {
            Y1 -= Peg_C * 2 - 2;
            while (Y1 > 5)
            {
                gotoxy(X1, --Y1);
                delay(4000);
                for (int i = 1; i <= peg_C_Disk[Peg_C]; i++)
                {
                    printf("*");
                }
                gotoxy(X1, Y1 + 1);
                for (int i = 1; i <= peg_C_Disk[Peg_C]; i++)
                {
                    if (i == ((peg_C_Disk[Peg_C] / 2) + 1) && (Y1 + 1 >= 10))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
            while (X1 > X)
            {
                gotoxy(X1--, Y1);
                delay(2000);
                for (int i = 1; i <= peg_C_Disk[Peg_C]; i++)
                {
                    printf("*");
                }
                gotoxy(X1 + peg_C_Disk[Peg_C], Y1);
                printf(" ");
            }
            while (Y1 < Y)
            {
                gotoxy(X1, ++Y1);
                delay(4000);
                for (int i = 1; i <= peg_C_Disk[Peg_C]; i++)
                {
                    printf("*");
                }
                gotoxy(X1, Y1 - 1);
                for (int i = 1; i <= peg_C_Disk[Peg_C]; i++)
                {
                    if (i == ((peg_C_Disk[Peg_C] / 2) + 1) && (Y1 + 1 >= 12))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
        }
    }
}

void removeDisk(int Disk_no, int peg_no, char peg)
{
    int X = (30 + (32 * (peg_no - 1))) - Disk_no / 2, Y;
    if (peg == 'A')
    {
        if (Peg_A == 0)
        {
            Y = ((Disk * 2) + 11) - ((Peg_A)*2);
        }
        else
        {
            Y = ((Disk * 2) + 11) - ((Peg_A)*2);
        }
    }
    else if (peg == 'B')
    {
        Y = ((Disk * 2) + 11) - (Peg_B * 2);
    }
    else
    {
        Y = ((Disk * 2) + 11) - (Peg_C * 2);
    }
    gotoxy(X, Y);
    for (int i = 1; i <= Disk_no; i++)
    {
        if (i == ((Disk_no / 2) + 1))
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
    }
}

void disk(int n)
{
    int X = 30 - (2 * n), Y = (n * 2) + 11;
    n *= 2;
    for (int i = n / 2; i >= 1; i--)
    {
        gotoxy(X, Y);
        for (int j = (i * 4) + 1; j > 0; j--)
        {
            printf("*");
        }
        Y -= 2, X += 2;
    }
}

void TOH(int n, char A, char B, char C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        gotoxy(0, 30);
        // printf("%c to %c\n", A, C);
        movement(A, C);
        TOH(n - 1, B, A, C);
    }
}

void delay(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
        }
    }
}

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

void main()
{
    system("cls");
    printf("Enter the Number of Disk\n");
    scanf("%d", &Disk);
    int b = 0;
    for (int i = Disk; i > 0; i--)
    {
        peg_A_Disk[i] = 5 + (4 * b);
        b++;
    }
    Peg_A = Disk;

    tower(Disk);
    disk(Disk);

    gotoxy(0, 30);
    TOH(Disk, 'A', 'B', 'C');
    getch();
}