#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
//function prototypes

struct player
{
    char name[40];
    int score;
}p[2];
char square[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
int checkwin();
void board(struct player []);
void hgame(char [],int,struct player []);
int ttt(struct player []);
int hangman(struct player p[]);
int score_card();

/*void display_score(struct player p[])
{
    cout<<p[0].name<<"\t\t - \t\t"<<p[0].score<<endl;
    cout<<p[1].name<<"\t\t - \t\t"<<p[1].score<<endl;
}*/
void delay(int a)
{
    long i=0;
    while(i<(a*320000000))
        i++;
}


int main()
{
    int a,h,t;
    system("cls");
    printf("Enter your name Player 1 : ");
    gets(p[0].name);
    printf("Enter your name Player 2 : ");
    gets(p[1].name);
    //p[0].score = 0;
    //p[1].score = 1;
    system("cls");
    printf("\t\t\t\t\t      Welcome to the Arena");
    delay(2);
    printf("\n\n\t\t\t\t\t %s \a ",p[0].name);
    delay(2);
    printf("\tVS");
    delay(2);
    printf("\t %s \a",p[1].name);
    delay(2);
    printf("\n\n\n\t\t\t\t\t LET'S GO!!!!!!!!!!!");
    delay(3);
    menu:
    system("cls");
    printf("\t\t\t\t\t Main Menu\n");
    printf("1) Tic - Tac - Toe \n");
    printf("2) Hangman\n");
    printf("3) Score card\n");
    printf("4) Exit\n");
    printf("Enter a choice : ");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
            t=ttt(p);
        break;
        case 2: h=hangman(p);
        break;
        case 3: score_card();
        break;
        case 4:
            score_card();
            delay(2);
            return 0;
        break;
        default : printf("Wrong choice entered!!!\n\t TRY AGAIN \a");
        delay(2);
        goto menu;
        break;
    }
    if(h==1 || t==1)
        goto menu;
    return 0;
}

/****
Function to tell whether to continue playing Hangman or not
****/

int hangman(struct player p[2])
{

    char word[30],ch;
    int i;
    do
    {
        for(i=0;i<2;i++)
        {
            system("cls");
            printf("\n\t\t\t\t\t HANGMAN \n\n");
            printf("\t\t\t\t\t Round %d\n\n",i+1);
            printf(" %s, please enter a word (upto 30 letters) : ",p[i].name);
            scanf("%s",word);
            //gets(word);
            system("cls");

            if(i==1)
                hgame(word,0,p);
            else
                hgame(word,1,p);
        }
        printf("\n\n Do you want to continue with this game(Y for yes / N for no) : ");
        scanf(" %c",&ch);
    }while(ch=='y' || ch=='Y');
    printf("Do you want to return to The main menu ?(Y for yes / N for no) : ");
    scanf(" %c",&ch);
    if (ch=='y' || ch=='Y')
        return 1;
    else
    {
        score_card();
        return 0;
    }
}

/****
Function to play Hangman
****/

void hgame(char answer[],int x,struct player p[2])
{
    int lives = 5,count,i;
    char letter,guess[strlen(answer)];
    system("cls");
        printf("\n\t\t\t\t\t HANGMAN \n\n");
        if(x==1)
            printf("\t\t\t\t\t Round %d\n",1);
        else
            printf("\t\t\t\t\t Round %d\n",2);
    printf("Press Enter if you are ready %s",p[x].name);
    getch();
    //delay(2);
    printf("\t\t\nThere are 5 lives with you %s \n\t\t ALL THE BEST !!!!!!!",p[x].name);
    delay(5);
    for(i=0;i<strlen(answer);i++)
    {
        if(answer[i]=='A'||answer[i]=='E'||answer[i]=='I'||answer[i]=='O'||answer[i]=='U'||answer[i]=='a'||answer[i]=='e'||answer[i]=='i'||answer[i]=='o'||answer[i]=='u')
            guess[i]=answer[i];
        else
            guess[i]='_';
    }
    guess[i]='\0';
    while (lives > 0 && strcmp(answer,guess)!=0)
    {
        system("cls");
        printf("\n\t\t\t\t\t HANGMAN \n\n");
        if(x)
            printf("\t\t\t\t\t Round %d\n",1);
        else
            printf("\t\t\t\t\t Round %d\n",2);
        printf("\t\t\t\t\t\t\t\t\t\t\t Lives left : ");
        for(i=0;i<lives;i++)
            printf("*");
        printf("\n");
        for(i=0;i<strlen(guess);i++)
            printf(" %c",guess[i]);

        printf("\n\n %s ,enter a character you think that might be present in the word ? : ",p[x].name);
        scanf(" %c",&letter);
        count = 0;
        for(i=0;i<strlen(answer);i++)
        {
            if (letter == answer[i])
            {
                guess[i]= letter;
                count++;
            }
        }
        if(count)
        {
            printf("Keep Going\n");
            delay(2);
        }
        else
        {
            printf("Sorry, the word doesn't contain %c \n",letter);
            delay(2);
            lives--;
        }
    }
    if (strcmp(answer,guess)==0)
    {
        system("cls");
        printf("\n\t\t\t\t\t HANGMAN \n\n");
        if(x)
            printf("\t\t\t\t\t Round %d\n",1);
        else
            printf("\t\t\t\t\t Round %d\n",2);
        printf("\t\t\t\t\t\t\t\t\t\t Lives left : ");
        for(i=0;i<lives;i++)
            printf("*");
        printf("\n");
        for(i=0;guess[i]!='\0';i++)
            printf(" %c",guess[i]);

    }
    if (lives==0)
    {
        system("cls");
        printf("\n\t\t\t\t\t HANGMAN \n\n");
        if(x)
            printf("\t\t\t\t\t Round %d\n",2);
        else
            printf("\t\t\t\t\t Round %d\n",1);
        printf("\t\t\t\t\t\t\t\t\t\t No Lives left \n");
        for(i=0;guess[i]!='\0';i++)
            printf(" %c",guess[i]);
        printf("\n\n The correct word was %s",answer);
        printf("\nSorry %s,you were not able to guess the word correctly \n Better luck next time :( ",p[x].name);
    }
    else
    {
        printf("\nCongrats %s, You won this round :) ",p[x].name);
        //p[x].score++;
    }
    delay(4);
}

/****
Function to play Tic - Tac -toe
         and tell whether to continue or not
****/

int ttt(struct player p[2])
{
    int player = 1, i,j, choice,count;
    char mark,ch;
    do
    {
        for(int a=0;a<10;a++)
            square[a]=' ';
        player =1;
        do
        {
            count=0;
            board(p);
            player = (player % 2) ? 1 : 2;

            printf(" %s, enter a number:  ", p[player-1].name);
            scanf("%d", &choice);

            mark = (player == 1) ? 'X' : 'O';

            for(j=1;j<10;j++)
            {
                if(choice>=1 && choice<=9 && square[choice]==' ')
                {
                    square[choice] = mark;
                    count++;
                }
            }
            if (count==0)
            {
                printf("Invalid Move!!");
                player--;
                delay(2);
            }
            i = checkwin();

            player++;
        }while (i ==  - 1);

        board(p);

        if (i == 1)
        {
            printf("Bravo, \a %s, you have won this match", p[player-2].name);
            //p[player-2].score++;
        }
        else
            printf("\a Game draw");

        printf("\n\n Do you want to continue with this game(Y for yes / N for no) : ");
        scanf(" %c",&ch);
    }while(ch=='y' || ch=='Y');

    printf("Do you want to return to The main menu ?(Y for yes / N for no) : ");
    scanf(" %c",&ch);
    if (ch=='y' || ch=='Y')
        return 1;
    else
    {
        score_card();
        return 0;
    }
}

/*****

FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT

*****/
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3] && square[1]!=' ')
        return 1;

    else if (square[4] == square[5] && square[5] == square[6] && square[4]!=' ')
        return 1;

    else if (square[7] == square[8] && square[8] == square[9] && square[7]!=' ')
        return 1;

    else if (square[1] == square[4] && square[4] == square[7] && square[1]!=' ')
        return 1;

    else if (square[2] == square[5] && square[5] == square[8] && square[2]!=' ')
        return 1;

    else if (square[3] == square[6] && square[6] == square[9] && square[3]!=' ')
        return 1;

    else if (square[1] == square[5] && square[5] == square[9] && square[1]!=' ')
        return 1;

    else if (square[3] == square[5] && square[5] == square[7] && square[3]!=' ')
        return 1;

    else if (square[1] != ' ' && square[2] != ' ' && square[3] != ' ' &&
        square[4] != ' ' && square[5] != ' ' && square[6] != ' ' && square[7]
        != ' ' && square[8] != ' ' && square[9] != ' ')

        return 0;
    else
        return  - 1;
}


/****
Function to draw Tic - Tac - Toe Board
****/
void board(struct player p[2])
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("%s(X)  -  %s (O)\n\n\n",p[0].name,p[1].name);


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

int score_card()
{
    return 0;
}
