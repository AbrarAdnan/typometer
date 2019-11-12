#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

void sorting_function(struct structure list[80], int s); int main();void main_menu();void two_player_mode();


struct structure{
    char name[20];
    float score;
};
fstream file;
structure toplist;
structure backup[10];
structure input;

static const char alphanum[] =
"0123456789"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char character()
{

    return alphanum[rand() % stringLength];
}

int input_score(float score)
{
    input.score=score;
    cin.ignore();
    cout<<"\nEnter your name :";
    cin.getline(input.name,10);
    file.open("Highscore.txt",ios::app);
    file.write((char*)&input,sizeof(input));
    file.close();
}

int show_data()
{
    int i=0;
    file.open("Highscore.txt",ios::in);
    file.read((char*)&toplist,sizeof(toplist));
    while(file.eof()==0)
    {
        backup[i]=toplist;
        file.read((char*)&toplist,sizeof(toplist));
        i++;
    }
    file.close();
    sorting_function(backup,i);
    cout<<"\nPress any key to go to the main menu";
    getch();
    main_menu();
}

void sorting_function(structure backup[], int s)
{
    int i, j;
    struct structure temp;

    for (i=0;i<s;i++)
    {
        for (j=i+1;j<s;j++)
        {
            if (backup[j].score>backup[i].score)
            {
                temp = backup[j];
                backup[j] = backup[i];
                backup[i] = temp;
            }
        }
    }
    cout<<"\n\nThe high score is :\n\n"<<endl;
    cout<<"Rank......score.........................name"<<endl;
    for(i=0;i<10;i++)
    {
        cout.width(2);
        cout<<i+1;
        cout.width(0);
        cout<<"        "<<backup[i].score<<" characters/second    ";
        cout<<backup[i].name<<endl;
        file.open("Highscore.txt",ios::trunc);
        file.read((char*)&toplist,sizeof(toplist));
        file.close();
    }
}
void checking_score(double score)
{
        int i=0;
        file.open("Highscore.txt",ios::in);
        file.read((char*)&toplist,sizeof(toplist));
        while(file.eof()==0)
        {
            backup[i]=toplist;
            file.read((char*)&toplist,sizeof(toplist));
            i++;
        }
    file.close();
    if(backup[i].score<score)
    {
        cout<<"\nCongratulations !"<<endl;
        cout<<"Your score was enough for a place in the high score"<<endl;
        printf("Your score = %.3f characters/second \n",score);
        input_score(score);
        show_data();
    }
    else
    {
        cout<<"\nSorry! Your score was not enough for a place in the high score";
        cout<<"Your score was "<<score<<" characters/second \n";
    }
}
void about_us()
{
    system("Cls");
    cout<<"\n\tTYPOMETER\n\tDeveloped and created by:\n\n\tAbrar Faiaz Adnan Dept. of ICE 3rd Batch"<<endl;
    cout<<"\n\tSpecial thanks to:\n\tShamim Sir, Niloy bhai, Sakib bhai and Arafat bhai";
    cout<<endl<<"\n\tPress any key to return to the main menu :";
    getch();
    main_menu();
}
void game()
{
    system("Cls");
    printf("\t\tRules of the game\n");
    printf("\n=>You'll be given 3 sets of 5 random alphabets and numbers.\n=>You'll have to enter them exactly as they appear.\n");
    printf("=>If you make a single mistake the game will stop.\n");
    printf("=>The number of characters you enter per second will be your score.\n=>The  higher the score the better\n");
    printf("\n\n\n\tPress any key to start the game. Good Luck!\n");
    getch();
    system("Cls");
    int a;
    for (a=0;a<=100;a++)
    {
        printf("\n\n\n\n\n\n\n\n\t\t\t%d percent completed",a,037);
        system("cls");
    }
        int i,j,random,correct=1;
        char question[6],answer[6];
        double start_time=0,end_time=0;
        double elapsed_time=0,total=0;
        char decision;
        start_time=clock();
        srand(time(NULL));
        for(i=0;i<3;i++)
        {
            for(j=0;j<5;j++)
            {
                question[j]=character();
            }
            cout<<"Question:    "<<question;
            cout<<"\nYour Answer: ";
            cin>>answer;
            correct=strcmp(question,answer);
            if(correct!=0)
            {
                printf("Wrong input. You lost.\nPress Y to restart the game or any other key to return to main menu ");
                cin>>decision;
            if(decision=='Y'||decision=='y')
                {
                    game();
                }
                else
                {
                    main_menu();
                }
            }
        }
        end_time=clock();
        total=end_time-start_time;
        elapsed_time=total/CLOCKS_PER_SEC;
        float score=15/elapsed_time;
        checking_score(score);
        cout<<"\nPress any key to go to the main menu";
    getch();
    main_menu();
}
void two_player_mode()
{
    float typing_speed_1,typing_speed_2;
    system("Cls");
    printf("\t\tRules of the game\n");
    printf("\n=>You'll be given 3 sets of 5 random alphabets and numbers.\n=>You'll have to enter them exactly as they appear.\n");
    printf("=>If you make a single mistake the game will stop.\n");
    printf("=>The number of characters you enter per second will be your score.\nThe higher the better");
    string player_one,player_two;
    cout<<"Player one enter your name :";
    cin>>player_one;
    cout<<"Player two enter your name :";
    cin>>player_two;
    printf("\n\n\n\tPress any key to start the game. Good Luck ");
    cout<<player_one<<"!\n";
    getch();
    system("Cls");
    int a;
    for (a=0;a<=100;a++)
    {
        printf("\n\n\n\n\n\n\n\n\t\t\t\tLOADING\n\t\t\t\t-------");
        printf("\n\t\t\t %d percent completed",a,037);
        system("cls");
    }
        int i,j,random,correct=1;
        char question[6],answer[6];
        double start_time=0,end_time=0;
        double elapsed_time_1=0,total=0;
        char decision;
        start_time=clock();
        srand(time(NULL));
        for(i=0;i<3;i++)
        {
            for(j=0;j<5;j++)
            {
                question[j]=character();
            }
            cout<<"Question:    "<<question;
            cout<<"\nYour Answer: ";
            cin>>answer;
            correct=strcmp(question,answer);
            if(correct!=0)
            {
                printf("\nWrong input. You lost.\nPress Y to restart the two player mode\nor any other key to return to main menu ");
                cin>>decision;
            if(decision=='Y'||decision=='y')
                {
                    two_player_mode();
                }
                else
                {
                    main_menu();
                }
            }
        }
        end_time=clock();
        total=end_time-start_time;
        elapsed_time_1=total/CLOCKS_PER_SEC;
        typing_speed_1=15/elapsed_time_1;
        printf("\nTyping speed of player one = %.3f character/second \n",typing_speed_1);
        printf("\n\n\n\tPress any key to start the game. Good Luck ");
        cout<<player_two<<"!\n";
        getch();
        system("Cls");
        for (a=0;a<=100;a++)
    {
        printf("\n\n\n\n\n\n\n\n\t\t\t\tLOADING\n\t\t\t\t-------");
        printf("\n\t\t\t %d percent completed",a,037);
        system("cls");
    }
        correct=1;
        start_time=0,end_time=0;
        double elapsed_time_2=0;
        total=0;
        start_time=clock();
        srand(time(NULL));
        for(i=0;i<3;i++)
        {
            for(j=0;j<5;j++)
            {
                question[j]=character();
            }
            cout<<"Question:    "<<question;
            cout<<"\nYour Answer: ";
            cin>>answer;
            correct=strcmp(question,answer);
            if(correct!=0)
            {
                printf("\nWrong input. You lost.\nPress Y to restart the two player mode\nor any other key to return to main menu ");
                cin>>decision;
            if(decision=='Y'||decision=='y')
                {
                    two_player_mode();
                }
                else
                {
                    main_menu();
                }
            }
        }
        end_time=clock();
        total=end_time-start_time;
        elapsed_time_2=total/CLOCKS_PER_SEC;
        typing_speed_2=15/elapsed_time_2;
        cout<<"\nTyping speed of "<<player_one;
        printf(" = %.3f character/second \n",typing_speed_1);
        cout<<"\nTyping speed of "<<player_two;
        printf(" = %.3f character/second \n",typing_speed_2);
        if(typing_speed_1<typing_speed_2)
        {
            cout<<"\nCongratulations "<<player_two<<"! You've won";
        }
        else if(typing_speed_1>typing_speed_2)
        {
            cout<<"\nCongratulations "<<player_two<<" You've won";
        }
        else
        {
            cout<<"\nBoth players scored the same. This is a one in a million event!! :o";
        }
        cout<<"\n\nPress y to start the two player mode again or any other key for main menu ";
        cin>>decision;
        if(decision=='Y'||decision=='y')
                {
                    two_player_mode();
                }
                else
                {
                    main_menu();
                }
}

void main_menu()
{
    system("Cls");
    printf("\n\n\n\n\t\t\tMain Menu\n\t\t\t~~~~~~~~~\n\n");
        printf("\t\tPress '1' to play new game\n");
        printf("\t\tPress '2' to enter 2 player mode\n");
        printf("\t\tPress '3' to see the high score\n");
        printf("\t\tPress '4' to see the info about the game \n");
        printf("\t\tPress any other key to exit the game\n");
        int s;
        cout<<"\n\t\tEnter your choice : ";
        cin>>s;
        system("Cls");
        switch(s)
        {
            case 1: game();
            break;
            case 3: show_data();
            break;
            case 4: about_us();
            break;
            case 2: two_player_mode();
            break;
            default:
            break;
        }
}
main()
{
        system("Cls");
        printf("\n\n\t\tWelcome to Typometer\n\t\t\t-Programmed by BitCoders\n\n\n\t\tPress any key to continue");
        getch();
        system("Cls");
        main_menu();
}





