#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int found(int f[], int size, int value)
{
    int found = 0;
    for(int i = 0; i < size; i++)
    {
        if(f[i] == value)
        {
            found = 1;
            break;
        }
    }
    if(found == 0)
        return -1;
    else
        return 1;
}

int uniqueRand(int a[], int size)
{
    while(1)
    {
        int found = 0;
        for(int i = 0; i < size; i++)
        {
            a[i] = (rand() % 9) + 1;
        }
        for(int i = 0; i < size - 1; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                if(a[i] == a[j])
                {
                    found = 1;
                    break;
                }
            }
        }
        if(found == 1)
            continue;
        else if(found == 0)
            break;
    }
    return 0;
}

int main()
{
    srand(time(NULL));
    int p[100];
    int ct = 1;
    int i = 0;
    do
    {
        printf("***************\n");
        printf("Welcome to MasterMind Game\n");
        printf("Best of luck\n");
        printf("***************\n");
        int f, e;
        while(1)
        {
            printf("Enter the number of guesses (1 to 20): ");
            scanf("%d", &f);
            if(f < 1 || f > 20)
            {
                printf("\nIncorrect number of guesses!!!\n");
                continue;
            }
            else
            {
                break;
            }
        }
        printf("You will have %d chances to guess the code\n", f);
        int choice = 0;
        while(choice < 1 || choice > 3)
        {
            printf("\nEnter the code of hidden digits (1 to 3 digits number): ");
            scanf("%d", &choice);
            if(choice < 1 || choice > 3)
                printf("\nIncorrect number of digits!!\n");
        }
        int a[3];
        int z = uniqueRand(a, choice);
        printf("The code has been set.\n");
        
        do
        {
            printf ("\nYou have %d remaining chances\n", f);
            printf ("Guess %d numbers : \n", choice);
            for(int i = 0; i < choice; i++)
            {
                scanf ("%1d",&p[i]);
            }
            int cnp = 0, cn = 0, fo = 0, num[3], j = 0;
            for(int i = 0; i < choice; i++)
            {
                if(a[i] == p[i])
                {
                    num[j++] = a[i];
                    cnp++;
                }
                else
                {
                    int x = found(a, choice, p[i]);
                    if(x ==-1)
                    {
                    continue;
                    }
                    else if(x == 1)
                {
                cn++;
                }
            }
        }
            printf("\nNumber of correct guesses at correct position = %d\n", cnp);
            printf("Number of correct guesses at wrong position = %d\n", cn);
            if(cnp == choice){
                printf("\nCongratulations, you have won the game!!!\n");
                break;
                
            }
            else
            {
                printf("\nIncorrect guess. Try again!!!\n");
                f--;
                ct++;
                
            }
            
        }
        while(f != 0);
        if(f == 0)
        {
            printf("\nSorry, you have lost the game!!!\n");
            
        }
            
            printf("\nDo you want to play again? Press 1 for YES and 0 for NO: ");
            
            int playAgain;
            scanf("%d",&playAgain);
            if(playAgain == 0)
            {
                break;
            }
            ct = 1;
            i++;
        
    }
    while(i < 100);
    printf("\nThank you for playing MasterMind Game!!!\n");
    return 0;
    
}
