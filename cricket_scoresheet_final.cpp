#include<dos.h>
#include<windows.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<fstream>
using namespace std;
static int mn=10;
fstream myfile;
string line,batting_team,balling_team;
int BALLS,innings=1,target,i,b;                                     //static variable
template<class x> void MyTeam(x o);
string batter[30], batter_next[30];
int visited[20], visited_next[30];
int flag,flag1;
pair<int,int> batter_info[20], batter_next_info[20];//first = run, second = ball played
int st, nst;
template<class z> void Score_board(z &t);
int extra_choice(string);
COORD coord= {0,0}; // this is global variable
void gotoxy(int x,int y)//change Cursor Location
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void bat_display()
{

    system("cls");
    /*for(int i = 0; i <=15; i++){
        visited[i] = 0;
        batter_info[i].first = 0;
        batter_info[i].second = 0;
    }*/



    for(int i = 1; i <= 11; i++)
    {
        if(visited[i] == 0)
            cout << i << ". " << batter[i] << endl;
    }

    if(flag == 0)
    {
        cout << "Choose 2 Batsman : " << endl;
        flag++;
        cout << "Choose Strike Batter : " << endl;
        cin >> st;
        cout << "Choose Non-Strike Batter : " << endl;
        cin >> nst;

        visited[st] = 1;
        visited[nst] = 1;


    }
    else
    {
        cout << "Choose next Batter : " << endl;
        cin >> st;
        visited[st] = 1;


    }

    system("cls");

}
void bat_display_next()
{

    system("cls");
    /*for(int i = 0; i <=15; i++){
        visited[i] = 0;
        batter_info[i].first = 0;
        batter_info[i].second = 0;
    }*/



    for(int i = 1; i <= 11; i++)
    {
        if(visited_next[i] == 0)
            cout << i << ". " << batter_next[i] << endl;
    }

    if(flag1 == 0)
    {
        cout << "Choose 2 Batsman : " << endl;
        flag1++;
        cout << "Choose Strike Batter : " << endl;
        cin >> st;
        cout << "Choose Non-Strike Batter : " << endl;
        cin >> nst;

        visited_next[st] = 1;
        visited_next[nst] = 1;


    }
    else
    {
        cout << "Choose next Batter : " << endl;
        cin >> st;
        visited_next[st] = 1;


    }

    system("cls");

}

void second_innings_batter_info()
{
    if(balling_team=="Bangladesh")
    {
        myfile.open("bd.txt");
        int i=1;
        while(getline(myfile,line))
        {
            gotoxy(22,b++);

            batter_next[i] = line;
            //cout<<i<<". "<<batter[i]<<endl;
            i++;
        }
        myfile.close();
        bat_display_next();

    }
    if(balling_team=="India")
    {
        myfile.open("ind.txt");
        int i=1;
        while(getline(myfile,line))
        {
            gotoxy(22,b++);
            batter_next[i] =line;
            //cout<<i<<". "<<line<<endl;
            i++;
        }
        myfile.close();
        bat_display_next();

    }
    if(balling_team=="Pakistan")
    {
        myfile.open("pakistan.txt");
        int i=1;
        while(getline(myfile,line))
        {
            gotoxy(22,b++);
            batter_next[i] = line;
            //cout<<i<<". "<<line<<endl;
            i++;
        }
        myfile.close();
        bat_display_next();

    }
    if(balling_team=="England")
    {
        myfile.open("england.txt");
        int i=1;
        while(getline(myfile,line))
        {
            gotoxy(22,b++);
            batter_next[i] = line;
            //cout<<i<<". "<<line<<endl;
            i++;
        }
        myfile.close();
        bat_display_next();

    }
    if(balling_team=="Australia")
    {
        myfile.open("australia.txt");
        int i=1;
        while(getline(myfile,line))
        {
            gotoxy(22,b++);
            batter_next[i] = line;
            //cout<<i<<". "<<line<<endl;
            i++;
        }
        myfile.close();
        bat_display_next();

    }
    if(balling_team=="New Zealand")
    {
        myfile.open("newzland.txt");
        int i=1;
        while(getline(myfile,line))
        {
            gotoxy(22,b++);
            batter_next[i] = line;
            //cout<<i<<". "<<line<<endl;
            i++;
        }
        myfile.close();
        bat_display_next();

    }
    if(balling_team=="South Africa")
    {
        myfile.open("southafrica.txt");
        int i=1;
        while(getline(myfile,line))
        {
            gotoxy(22,b++);
            batter_next[i]=line;
            //cout<<i<<". "<<line<<endl;
            i++;
        }
        myfile.close();
        bat_display_next();

    }
}

void Out_Batter_next(int a)
{
    visited_next[a] = 1;
    system("cls");
    bat_display_next();
}

void Out_Batter(int a)
{
    visited[a] = 1;
    system("cls");
    bat_display();
}


class Live_Score
{
public :

    // varialbles for match info
    string match_name,venue,result,series_type,team1,team2,toss_choice,toss_winner,toss_loser;
    int n,total_overs,series_match_no=1,no_of_matches;

    //variables for score card
    int total_runs;
    virtual void update_score_board() {}                                    // virtual function
    void toss_decision();
    void display()
    {
        All_teams();
        limited_overs_series();
        toss_decision();
    }


    int All_teams()
    {
        system("cls");
        int i;
        gotoxy(49,13);
        for(i=0 ; i<30 ; i++)
            cout<<"_";
        gotoxy(48,15);
        for(i=0 ; i<30 ; i++)
            cout<<"_";
        for(i=14 ; i<26 ; i++)
        {
            gotoxy(48,i);
            cout<<"|";
        }
        gotoxy(49,25);
        for(i=0 ; i<30 ; i++)
            cout<<"_";
        for(i=14 ; i<26 ; i++)
        {
            gotoxy(79,i);
            cout<<"|";
        }
        gotoxy(57,14);
        cout<<"Team Information";
        gotoxy(50,16);
        cout<<"1.Bangladesh";
        gotoxy(50,17);
        cout<<"2.India";
        gotoxy(50,18);
        cout<<"3.Pakistan";
        gotoxy(50,19);
        cout<<"4.England";
        gotoxy(50,20);
        cout<<"5.Australia";
        gotoxy(50,21);
        cout<<"6.New Zealand";
        gotoxy(50,22);
        cout<<"7.South Africa";
        gotoxy(49,30);
    }
    void limited_overs_series()
    {
        system("COLOR 0B");
        for(int x=49,y=4,i=0 ; i<30 ; i++)
        {
            gotoxy(x,y);
            cout<<"_";
            x++;
        }
        gotoxy(48,5);
        cout<<"|";
        gotoxy(79,5);
        cout<<"|";
        int i,j,x=49,y=6;
        for(i=0; i<30; i++)
        {
            gotoxy(x,y);
            cout<<"_";
            x++;
        }
        while(y<11)
        {
            y++;
            gotoxy(48,y);
            cout<<"|";

            gotoxy(79,y);
            cout<<"|";
        }
        x=49;
        for(i=0; i<30; i++)
        {
            gotoxy(x,y);
            cout<<"_";
            x++;
        }
        y=7;
        gotoxy(58,5);
        cout<<"Game Details";
        gotoxy(50,y++);
        cout<<"Venue  : ";
        gotoxy(50,y++);
        cout<<"Team 1 : ";
        gotoxy(50,y++);
        cout<<"Team 2 : ";
        gotoxy(50,y++);
        cout<<"OVER   : ";
        gotoxy(59,7);
        cin>>venue;
        gotoxy(59,8);
        cin>>team1;

        if(team1=="1")
            team1="Bangladesh";
        if(team1=="2")
            team1="India";
        if(team1=="3")
            team1="Pakistan";
        if(team1=="4")
            team1="England";
        if(team1=="5")
            team1="Australia";
        if(team1=="6")
            team1="New Zealand";
        if(team1=="7")
            team1="South Africa";
        gotoxy(59,9);

        cin>>team2;
        if(team2=="1")
            team2="Bangladesh";
        if(team2=="2")
            team2="India";
        if(team2=="3")
            team2="Pakistan";
        if(team2=="4")
            team2="England";
        if(team2=="5")
            team2="Australia";
        if(team2=="6")
            team2="New Zealand";
        if(team2=="7")
            team2="South Africa";
        gotoxy(59,10);
        cin>>total_overs;
        BALLS=(total_overs)*6;

        system("cls");
        //cout<<team1<<" "<<team2<<endl;
        //system("pause");
        gotoxy(19,4);
        for(i=0 ; i<30 ; i++)
            cout<<"_";
        gotoxy(19,6);
        for(i=0 ; i<30 ; i++)
            cout<<"_";
        for(i=5 ; i<20 ; i++)
        {
            gotoxy(18,i);
            cout<<"|";
        }
        gotoxy(19,19);
        for(i=0 ; i<30 ; i++)
            cout<<"_";
        for(i=5 ; i<20 ; i++)
        {
            gotoxy(48,i);
            cout<<"|";
        }
        gotoxy(26,5);
        cout<<team1;
        b=7;
        if(team1=="Bangladesh")
        {
            myfile.open("bd.txt");
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }
        if(team1=="India")
        {
            myfile.open("ind.txt");
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }
        if(team1=="Pakistan")
        {
            myfile.open("pakistan.txt");
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }
        if(team1=="England")
        {
            myfile.open("england.txt");
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }
        if(team1=="Australia")
        {
            myfile.open("australia.txt");
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }
        if(team1=="New Zealand")
        {
            myfile.open("newzland.txt");
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }
        if(team1=="South Africa")
        {
            myfile.open("southafrica.txt");
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }

        gotoxy(52,12);
        cout<<"Vs";


        gotoxy(57,4);
        for(i=0 ; i<30 ; i++)
            cout<<"_";
        gotoxy(57,6);
        for(i=0 ; i<30 ; i++)
            cout<<"_";
        for(i=5 ; i<20 ; i++)
        {
            gotoxy(56,i);
            cout<<"|";
        }
        gotoxy(57,19);
        for(i=0 ; i<30 ; i++)
            cout<<"_";
        for(i=5 ; i<20 ; i++)
        {
            gotoxy(87,i);
            cout<<"|";
        }
        gotoxy(66,5);



        cout<<team2;

        b=7;
        if(team2=="Bangladesh")
        {
            myfile.open("bd.txt");
            while(getline(myfile,line))
            {
                gotoxy(60,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }
        if(team2=="India")
        {
            myfile.open("ind.txt");
            while(getline(myfile,line))
            {
                gotoxy(60,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }
        if(team2=="Pakistan")
        {
            myfile.open("pakistan.txt");
            while(getline(myfile,line))
            {
                gotoxy(60,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }
        if(team2=="England")
        {
            myfile.open("england.txt");
            while(getline(myfile,line))
            {
                gotoxy(60,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }
        if(team2=="Australia")
        {
            myfile.open("australia.txt");
            while(getline(myfile,line))
            {
                gotoxy(60,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }
        if(team2=="New Zealand")
        {
            myfile.open("newzland.txt");
            while(getline(myfile,line))
            {
                gotoxy(60,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }
        if(team2=="South Africa")
        {
            myfile.open("southafrica.txt");
            while(getline(myfile,line))
            {
                gotoxy(60,b++);
                cout<<line<<endl;
            }
            myfile.close();
            gotoxy(49,20);

        }

        gotoxy(19,22);
        system("pause");

    }
    void toss()
    {
        system("cls");
        char ch,*chr;
        //string toss_winner;
        int c;

label:
        cout<<endl<<"It's Toss Time..."<<endl;
        getch();
        system("cls");
        cout<<endl<<"It's "<<team1<<"'s call !!";
        cout<<endl<<"H or T ?"<<endl;
        cin>>ch;
        srand(time(0));
        c=(rand());
        //cout<<c;                         // RANDOM FUNCTION
        if(ch=='H'||ch=='h')
        {
            if(c%2==0)
            {
                toss_winner=team1;
                toss_loser=team2;
                cout<<endl<<"Toss won by "<<team1;
                cout<<endl<<"What do you want to do??(ball/bat)";
                cin>>toss_choice;
                if(toss_winner == team1 && toss_choice == "bat" || toss_choice == "Bat" || toss_choice == "BAT")
                {
                    batting_team=team1;
                    balling_team=team2;
                }
                else
                {
                    batting_team=team2;
                    balling_team=team1;
                }
                cout<<endl<<team1<<" won the toss and decided to "<<toss_choice<<" first";
            }
            else
            {
                toss_winner=team2;
                toss_loser=team1;
                cout<<endl<<"Toss won by "<<team2;
                cout<<endl<<"What do you want to do?? (ball/bat)"<<endl;
                cin>>toss_choice;
                if(toss_winner == team2 && toss_choice == "bat" || toss_choice == "Bat" || toss_choice == "BAT")
                {
                    batting_team=team2;
                    balling_team=team1;
                }
                else
                {
                    batting_team=team1;
                    balling_team=team2;
                }
                cout<<endl<<endl<<team2<<" won the toss and decided to "<<toss_choice<<" first";
            }
        }
        else if(ch=='T'||ch=='t')
        {
            if(c%2==0)
            {
                toss_winner=team1;
                toss_loser=team2;
two:
                cout<<endl<<"Toss won by "<<team1;
                cout<<endl<<"What do you want to do??(ball/bat)";
                cin>>toss_choice;
                if(toss_winner == team1 && toss_choice == "bat" || toss_choice == "Bat" || toss_choice == "BAT")
                {
                    batting_team=team1;
                    balling_team=team2;
                }
                else
                {
                    batting_team=team2;
                    balling_team=team1;
                }
                if(toss_choice=="bat"||toss_choice=="BAT"||toss_choice=="ball"||toss_choice=="BALL")
                    cout<<endl<<team1<<" won the toss and decided to "<<toss_choice<<" first";
                else
                {
                    cout<<endl<<"Invalid choice";
                    goto two;
                }
            }
            else
            {
                toss_winner=team2;
                toss_loser=team1;
one:
                cout<<endl<<"Toss won by "<<team2;
                cout<<endl<<"What do you want to do??(ball/bat)";
                cin>>toss_choice;
                if(toss_winner == team2 && toss_choice == "bat" || toss_choice == "Bat" || toss_choice == "BAT")
                {
                    batting_team=team2;
                    balling_team=team1;
                }
                else
                {
                    batting_team=team1;
                    balling_team=team2;
                }
                if(toss_choice=="bat"||toss_choice=="BAT"||toss_choice=="ball"||toss_choice=="BALL")
                    cout<<endl<<team2<<" won the toss and decided to "<<toss_choice<<" first";
                else
                {
                    cout<<endl<<"Invalid choice";
                    goto one;
                }
            }
        }
        else
        {
            cout<<endl<<"Please Enter H or T"<<endl;
            goto label;
        }
        b=7;
        if(batting_team=="Bangladesh")
        {
            myfile.open("bd.txt");
            int i=1;
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                batter[i]=line;
                //cout<<i<<". "<<batter[i]<<endl;
                i++;
            }
            myfile.close();
            bat_display();

        }
        if(batting_team=="India")
        {
            myfile.open("ind.txt");
            int i=1;
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                batter[i]=line;
                //cout<<i<<". "<<line<<endl;
                i++;
            }
            myfile.close();
            bat_display();

        }
        if(batting_team=="Pakistan")
        {
            myfile.open("pakistan.txt");
            int i=1;
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                batter[i]=line;
                //cout<<i<<". "<<line<<endl;
                i++;
            }
            myfile.close();
            bat_display();

        }
        if(batting_team=="England")
        {
            myfile.open("england.txt");
            int i=1;
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                batter[i]=line;
                //cout<<i<<". "<<line<<endl;
                i++;
            }
            myfile.close();
            bat_display();

        }
        if(batting_team=="Australia")
        {
            myfile.open("australia.txt");
            int i=1;
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                batter[i]=line;
                //cout<<i<<". "<<line<<endl;
                i++;
            }
            myfile.close();
            bat_display();

        }
        if(batting_team=="New Zealand")
        {
            myfile.open("newzland.txt");
            int i=1;
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                batter[i]=line;
                //cout<<i<<". "<<line<<endl;
                i++;
            }
            myfile.close();
            bat_display();

        }
        if(batting_team=="South Africa")
        {
            myfile.open("southafrica.txt");
            int i=1;
            while(getline(myfile,line))
            {
                gotoxy(22,b++);
                batter[i]=line;
                //cout<<i<<". "<<line<<endl;
                i++;
            }
            myfile.close();
            bat_display();

        }


        // gotoxy(20,21);
        //cout<<"Striking Batsman :";
        //cin>>st.number;

        //gotoxy(20,22);
        // cout<<"Non Striking Batsman :";
        // cin>>nst.number;






    }



};
int instruction()
{
    system("cls");
    gotoxy(49,12);
    for(i=0 ; i<30 ; i++)
        cout<<"_";
    gotoxy(49,27);
    for(i=0 ; i<30 ; i++)
        cout<<"_";
    for(i=13 ; i<28 ; i++)
    {
        gotoxy(48,i);
        cout<<"|";
    }
    gotoxy(49,14);
    for(i=0 ; i<30 ; i++)
        cout<<"_";
    for(i=13 ; i<28 ; i++)
    {
        gotoxy(79,i);
        cout<<"|";
    }
    gotoxy(57,13);
    cout<<"Instructions";
    gotoxy(50,16);
    cout<<"1.Presss 0 for Dot Ball";
    gotoxy(50,17);
    cout<<"2.Presss 1 for 1 Run";
    gotoxy(50,18);
    cout<<"3.Presss 2 for 2 Run";
    gotoxy(50,19);
    cout<<"4.Presss 3 for 3 Run";
    gotoxy(50,20);
    cout<<"5.Presss 4 for 4 Run";
    gotoxy(50,21);
    cout<<"6.Presss 5 for Extra Runs";
    gotoxy(50,22);
    cout<<"7.Presss 6 for 6";
    gotoxy(50,23);
    cout<<"8.Presss 7 for Wicket";
    gotoxy(50,24);
    cout<<"8.Presss 8 for Score";
    //system("cls");
    //gotoxy(49,30);
}


class Team1 : public Live_Score
{
public :
    const int m;                                         //const member
    int total_runs,balls,wickets,ex,over,ball,rem_balls,rem_runs;
    string name;
    Team1(int a=10):m(a)                        //initializing constant member by initialier variable
    {
        mn++;
        total_runs=0;
        balls=0;
        wickets=0;
        ex=0;
        ball=0;
        over=0;
    }
    friend void fun();
    template <class y>
    friend void Score_board();                                   // Generic function as friend


    void update_score_card()
    {
        instruction();
        //system("cls");
        gotoxy(49,2);
        cout<<team1<<" vs "<<team2<<" Live From "<<venue;
        if(ball>5)
        {
            ball=0;
            over++;
        }
        gotoxy(49,4);
        for(i=0 ; i<50 ; i++)
            cout<<"_";
        for(i=5 ; i<=8; i++)
        {
            gotoxy(48,i);
            cout<<"|";
        }
        gotoxy(49,8);
        for(i=0 ; i<50 ; i++)
            cout<<"_";
        for(i=5 ; i<=8 ; i++)
        {
            gotoxy(99,i);
            cout<<"|";
        }
        gotoxy(50,5);
        cout<<team1<<" - "<<total_runs<<"/"<<wickets<<"   "<<"("<<over<<"."<<ball<<"overs)"<<" Extra :"<<ex;
        if(innings==2)
        {
            gotoxy(50,6);
            cout<<team1<<" require "<<rem_runs<<" runs of "<<rem_balls<<" balls ";
        }
        // getch();
    }

    void Full_Score()
    {
        system("cls");
        system("COLOR 0e");
        gotoxy(5,2);
        for(int i=0 ; i<40 ; i++)
            cout<<"_";
        for(int i=3 ; i<23 ; i++)
        {
            gotoxy(5,i);
            cout<<"|";

        }
        gotoxy(5,22);
        for(int i=0 ; i<40 ; i++)
            cout<<"_";
        for(int i=3 ; i<23 ; i++)
        {
            gotoxy(45,i);
            cout<<"|";
        }
        gotoxy(6,4);
        for(int i=0 ; i<39 ; i++)
            cout<<"_";
        gotoxy(10,3);
        cout<<batting_team;
        gotoxy(25,3);
        cout<<"Ov."<<over<<"."<<ball;
        gotoxy(35,3);
        cout<<total_runs <<"-"<<wickets;
        //cout<<team1<<" - "<<total_runs<<"/"<<wickets<<"   "<<"("<<over<<"."<<ball<<"overs)"<<" Extra :"<<ex;
        int y=6;
        for(int i = 1; i <= 11; i++)
        {
            double strike_rate = ((batter_info[i].first * 1.0) / (batter_info[i].second *1.0)) * 100.0;
            gotoxy(6,y);
            cout<<batter[i];
            gotoxy(28,y);
            cout<<batter_info[i].first<<"("<<batter_info[i].second<<")";
            gotoxy(33,y++);
            {
                if(strike_rate>0)
                    cout<<"S.R - "<<strike_rate;
                else
                    cout<<"0";
            }
            // cout << batter[i] << " run : " << batter_info[i].first << " ball : " << batter_info[i].second << " strike_rate : " << strike_rate ;
        }
        gotoxy(10,25);

        system("pause");
    }
    void second_Full_Score()
    {
        system("cls");
        system("COLOR 0e");
        gotoxy(5,2);
        for(int i=0 ; i<40 ; i++)
            cout<<"_";
        for(int i=3 ; i<23 ; i++)
        {
            gotoxy(5,i);
            cout<<"|";

        }
        gotoxy(5,22);
        for(int i=0 ; i<40 ; i++)
            cout<<"_";
        for(int i=3 ; i<23 ; i++)
        {
            gotoxy(45,i);
            cout<<"|";
        }
        gotoxy(6,4);
        for(int i=0 ; i<39 ; i++)
            cout<<"_";
        gotoxy(10,3);
        cout<<balling_team;
        gotoxy(25,3);
        cout<<"Ov. "<<over<<"."<<ball;
        gotoxy(35,3);
        cout<<total_runs <<"-"<<wickets;
        //cout<<team1<<" - "<<total_runs<<"/"<<wickets<<"   "<<"("<<over<<"."<<ball<<"overs)"<<" Extra :"<<ex;
        int y=6;
        for(int i = 1; i <= 11; i++)
        {
            double strike_rate = ((batter_next_info[i].first * 1.0) / (batter_next_info[i].second *1.0)) * 100.0;
            gotoxy(6,y);
            cout<<batter_next[i];
            gotoxy(28,y);
            cout<<batter_next_info[i].first<<"("<<batter_next_info[i].second<<")";
            gotoxy(33,y++);
            {
                if(strike_rate>0)
                    cout<<"S.R - "<<strike_rate;
                else
                    cout<<"0";
            }
            // cout << batter[i] << " run : " << batter_info[i].first << " ball : " << batter_info[i].second << " strike_rate : " << strike_rate ;
        }
        gotoxy(10,25);

        system("pause");
    }


    void run_score_board();
    void next_inning();

} T1;

class Team2 :public Live_Score
{
public :


    int total_runs,balls,wickets,ex,over,ball,rem_balls,rem_runs;
    string name;
    const int m;                                         //const member
    Team2(int a=10):m(a)                        //initializing constant member by initialier variable
    {
        mn++;
        total_runs=0;
        balls=0;
        wickets=0;
        ex=0;
        ball=0;
        over=0;
    }
    template <class y>
    friend void Score_board();                              //  generic Friend function

    void update_score_card()
    {
        instruction();
        //system("cls");
        gotoxy(49,2);
        cout<<team2<<" vs "<<team1<<" Live from "<<venue;
        if(ball>5)
        {
            ball=0;
            over++;
        }
        gotoxy(49,4);
        for(i=0 ; i<50 ; i++)
            cout<<"_";
        for(i=5 ; i<=8; i++)
        {
            gotoxy(48,i);
            cout<<"|";
        }
        gotoxy(49,8);
        for(i=0 ; i<50 ; i++)
            cout<<"_";
        for(i=5 ; i<=8 ; i++)
        {
            gotoxy(99,i);
            cout<<"|";
        }
        gotoxy(50,5);
        cout<<team1<<"-"<<total_runs<<"/"<<wickets<<"   "<<"("<<over<<"."<<ball<<"overs)"<<" Extra : "<<ex;
        //gotoxy(49,5);
        if(innings==2)
        {
            gotoxy(50,6);
            cout<<team1<<" require "<<rem_runs<<" runs of "<<rem_balls<<" balls ";
        }
        //	getch();
    }
    void Full_Score()
    {
        system("cls");
        system("COLOR 0e");
        gotoxy(5,2);
        for(int i=0 ; i<40 ; i++)
            cout<<"_";
        for(int i=3 ; i<23 ; i++)
        {
            gotoxy(5,i);
            cout<<"|";

        }
        gotoxy(5,22);
        for(int i=0 ; i<40 ; i++)
            cout<<"_";
        for(int i=3 ; i<23 ; i++)
        {
            gotoxy(45,i);
            cout<<"|";
        }
        gotoxy(6,4);
        for(int i=0 ; i<39 ; i++)
            cout<<"_";
        gotoxy(10,3);
        cout<<batting_team;
        gotoxy(25,3);
        cout<<"Ov. "<<over<<"."<<ball;
        gotoxy(35,3);
        cout<<total_runs <<"-"<<wickets;
        //cout<<team1<<" - "<<total_runs<<"/"<<wickets<<"   "<<"("<<over<<"."<<ball<<"overs)"<<" Extra :"<<ex;
        int y=6;
        for(int i = 1; i <= 11; i++)
        {
            double strike_rate = ((batter_info[i].first * 1.0) / (batter_info[i].second *1.0)) * 100.0;
            gotoxy(6,y);
            cout<<batter[i];
            gotoxy(28,y);
            cout<<batter_info[i].first<<"("<<batter_info[i].second<<")";
            gotoxy(33,y++);
            {
                if(strike_rate>0)
                    cout<<"S.R - "<<strike_rate;
                else
                    cout<<"0";
            }
            // cout << batter[i] << " run : " << batter_info[i].first << " ball : " << batter_info[i].second << " strike_rate : " << strike_rate ;
        }
        gotoxy(10,25);

        system("pause");
    }
    void second_Full_Score()
    {
        system("cls");
        system("COLOR 0e");
        gotoxy(5,2);
        for(int i=0 ; i<40 ; i++)
            cout<<"_";
        for(int i=3 ; i<23 ; i++)
        {
            gotoxy(5,i);
            cout<<"|";

        }
        gotoxy(5,22);
        for(int i=0 ; i<40 ; i++)
            cout<<"_";
        for(int i=3 ; i<23 ; i++)
        {
            gotoxy(45,i);
            cout<<"|";
        }
        gotoxy(6,4);
        for(int i=0 ; i<39 ; i++)
            cout<<"_";
        gotoxy(10,3);
        cout<<balling_team;
        gotoxy(25,3);
        cout<<"Ov. "<<over<<"."<<ball;
        gotoxy(35,3);
        cout<<total_runs <<"-"<<wickets;
        //cout<<team1<<" - "<<total_runs<<"/"<<wickets<<"   "<<"("<<over<<"."<<ball<<"overs)"<<" Extra :"<<ex;
        int y=6;
        for(int i = 1; i <= 11; i++)
        {
            double strike_rate = ((batter_next_info[i].first * 1.0) / (batter_next_info[i].second *1.0)) * 100.0;
            gotoxy(6,y);
            cout<<batter_next[i];
            gotoxy(28,y);
            cout<<batter_next_info[i].first<<"("<<batter_next_info[i].second<<")";
            gotoxy(33,y++);
            {
                if(strike_rate>0)
                    cout<<"S.R - "<<strike_rate;
                else
                    cout<<"0";
            }
            // cout << batter[i] << " run : " << batter_info[i].first << " ball : " << batter_info[i].second << " strike_rate : " << strike_rate ;
        }
        gotoxy(10,25);

        system("pause");
    }


    void run_score_board();
    void next_inning();

    Team2& operator=(const Team1 t1)                                   // operator overloding
    {
        Team2 temp;
        team1=t1.team2;
        team2=t1.team1;
        venue=t1.venue;
        series_match_no=t1.series_match_no;
        no_of_matches=t1.no_of_matches;
        //return temp;
    }

} T2;


void Team1::run_score_board()
{
    system("cls");

    cout<<endl<<" ***********************    Welcome To "<<team1<<" vs "<<team2<<" Match NO. "<<this->series_match_no<<" Live from "<<venue<<"   ****************";
    cout<<endl<<endl<<this->team1<<"-"<<this->total_runs<<"/"<<this->wickets<<"   "<<"("<<this->over<<"."<<this->ball<<"overs)"<<" Extra : "<<this->ex;
    Sleep(1000);
    cout<<endl<<endl<<"R";
    Sleep(1000);
    cout<<" U ";
    Sleep(1000);
    cout<<" Ready.....";
    getch();
    Score_board(T1);
}

void Team2::run_score_board()
{
    system("cls");
    cout<<endl<<" ***********************    Welcome To "<<team1<<" vs "<<team2<<" Match NO. "<<this->series_match_no<<" Live from "<<venue<<"   ****************";
    cout<<endl<<endl<<this->team1<<"-"<<this->total_runs<<"/"<<this->wickets<<"   "<<"("<<this->over<<"."<<this->ball<<"overs)"<<" Extra : "<<this->ex;
    Sleep(1000);
    cout<<endl<<endl<<"R";
    Sleep(1000);
    cout<<" U ";
    Sleep(1000);
    cout<<" Ready.....";
    getch();
    Score_board(T2);
}

void Team1:: next_inning()
{
    system("cls");
    target=T2.total_runs+1;
    rem_balls=BALLS;
    rem_runs=target;
    innings=2;
    cout<<endl<<"WELCOME TO SECOND INNINGS"<<endl<<endl<<"TARGET : "<<target;
    getch();
    second_innings_batter_info();
    T1.run_score_board();
}

void Team2:: next_inning()
{
    system("cls");
    target=T1.total_runs+1;
    rem_balls=BALLS;
    rem_runs=target;
    innings=2;
    cout<<endl<<"WELCOME TO SECOND INNINGS"<<endl<<endl<<"TARGET : "<<target;
    getch();
    second_innings_batter_info();
    T2.run_score_board();
}
template <class x> void MyTeam(x o)
{
    if(sizeof(o)==4)
    {
        //	cout<<endl<<"In myteam "<<T1.team1;

        T1.run_score_board();
        T2.next_inning();
    }
    else if(sizeof(o)==1)
    {
        //	cout<<endl<<"in myteam "<<T2.team2;
        T2.run_score_board();
        T1.next_inning();
    }
}


void Live_Score :: toss_decision()
{
    int a=10;                        // for team1
    char ch='a';                    // for team2
label:
    toss();
    T2=T1;                                       // operator overloding
    //cout<<endl<<T2.team2<<endl<<T2.toss_winner<<endl<<"t2 data"<<endl;
    getch();
    if(toss_choice=="bat"||toss_choice=="BAT")
    {

        if(toss_winner==team1)
            MyTeam(a);
        else
            MyTeam(ch);
    }
    else if(toss_choice=="ball"||toss_choice=="BALL")
    {
        if(toss_loser==team1)
            MyTeam(a);
        else
            MyTeam(ch);
    }

    else
    {
        cout<<endl<<"Invalid choice toss again...";
        goto label;
    }
}

template <class y>
void Score_board(y &t)
{

    int c,c1,extra=0,freehit=0,prevball,achived=0;
    string type_e,type_w;
    //getch();
    while(t.balls<BALLS&&t.wickets<10&&achived==0)
    {
        //system("cls");
        extra=0;
        if(freehit==1)
            prevball=(t.balls)-1;
        if(prevball!=(t.balls)-1)
            freehit=0;
        if(innings==2)
        {
            if(t.total_runs>=target)
                achived=1;
        }
        t.update_score_card();
        //cout"R U Ready for the next ball !!"<<endl;

        //instruction();

        if(freehit==1)
            cout<<endl<<"It's a freehit"<<endl<<endl;
        gotoxy(49,10);
        cout<<"Result : ";
        gotoxy(60,10);
        cin>>c;
        extra=0;

        switch (c)
        {
        case  0:
            t.balls++;
            t.ball++;
            if(innings==2)
            {
                t.rem_balls--;
            }
            t.update_score_card();
            freehit=0;
            if(innings==1)
                batter_info[st].second++;
            else
                batter_next_info[st].second++;
            break;
        case  1:
            t.total_runs+=1;
            t.balls++;
            freehit=0;
            if(innings==2)
            {
                t.rem_balls--;
                t.rem_runs--;
            }
            t.ball++;
            t.update_score_card();
            if(innings==1)
            {
                batter_info[st].first++;
                batter_info[st].second++;
                swap(st, nst);
            }
            else
            {
                batter_next_info[st].first++;
                batter_next_info[st].second++;
                swap(st, nst);
            }
            break;
        case  2:
            t.total_runs+=2;
            t.balls++;
            freehit=0;
            t.ball++;
            if(innings==2)
            {
                t.rem_balls--;
                t.rem_runs-=2;
            }
            t.update_score_card();
            if(innings==1)
            {
                batter_info[st].first += 2;
                batter_info[st].second++;
            }
            else
            {
                batter_next_info[st].first += 2;
                batter_next_info[st].second++;
            }
            break;
        case  3:
            t.total_runs+=3;
            t.balls++;
            freehit=0;
            if(innings==2)
            {
                t.rem_balls--;
                t.rem_runs-=3;
            }
            t.ball++;
            t.update_score_card();
            if(innings==1)
            {
                batter_info[st].first += 3;
                batter_info[st].second++;
                swap(st, nst);
            }
            else
            {
                batter_next_info[st].first += 3;
                batter_next_info[st].second++;
                swap(st, nst);
            }
            break;
        case  4:
            t.total_runs+=4;
            t.balls++;
            freehit=0;
            if(innings==2)
            {
                t.rem_balls--;
                t.rem_runs-=4;
            }
            t.ball++;
            t.update_score_card();
            if(innings==1)
            {
                batter_info[st].first += 4;
                batter_info[st].second++;
            }
            else
            {
                batter_next_info[st].first += 4;
                batter_next_info[st].second++;
            }
            break;
        case  5:
            cout<<endl<<"Type of extra? ";
            cin.ignore();
            getline(cin,type_e);
            cout<<endl<<"any other extra runs (0-6)? ";
            cin>>extra;
            //cin.ignore();
            getch();
            c1=extra_choice(type_e);
            switch(c1)
            {
            case 1  :
                t.total_runs+=extra+1;
                t.ex+=extra+1;
                freehit=0;
                if(innings==2)
                {
                    t.rem_runs-=(extra+1);
                }
                t.update_score_card();
                swap(st, nst);
                break;
            case 2 : //no ball
                t.total_runs+=extra+1;
                freehit=1;
                t.ex+=extra+1;
                if(innings==2)
                {
                    t.rem_runs-=(extra+1);
                }
                cout<<endl<<"Its a free hit!!!"<<endl;
                getch();
                t.update_score_card();
                break;
            case 3  :  //leg by
                t.total_runs+=extra;
                t.ball++;
                t.balls++;
                freehit=0;
                t.ex+=extra;
                if(innings==2)
                {
                    t.rem_balls--;
                    t.rem_runs-=extra;
                }
                t.update_score_card();
                if(innings==1)
                {
                    batter_info[st].second++;
                    swap(st, nst);
                }
                else
                {
                    batter_next_info[st].second++;
                    swap(st, nst);
                }
                break;
            case 4	:
                t.total_runs+=extra;
                t.ball++;
                t.balls++;
                freehit=0;
                t.ex+=extra;
                if(innings==2)
                {
                    t.rem_balls--;
                    t.rem_runs-=extra;
                }
                t.update_score_card();
                if(innings==1)
                {
                    batter_info[st].second++;
                }
                else
                {
                    batter_next_info[st].second++;
                }
                break;
            default      :
                t.total_runs+=extra;
                t.ex+=extra;
                t.balls++;
                freehit=0;
                t.ball++;
                if(innings==2)
                {
                    t.rem_balls--;
                    t.rem_runs-=extra;
                }
                t.update_score_card();
                if(innings==1)
                {
                    batter_info[st].second++;
                }
                else
                {
                    batter_next_info[st].second++;
                }
            }
            break;
        case  6:
            t.total_runs+=6;
            t.balls++;
            freehit=0;
            if(innings==2)
            {
                t.rem_balls--;
                t.rem_runs-=6;
            }
            t.ball++;
            t.update_score_card();
            if(innings==1)
            {
                batter_info[st].first += 6;
                batter_info[st].second++;
            }
            else
            {
                batter_next_info[st].first += 6;
                batter_next_info[st].second++;
            }

            break;
        case  7:
            cout<<endl<<"Type of wicket ? ";
            cin.ignore();
            int cbt;
            getline(cin,type_w);
            if(type_w=="runout"||type_w=="RUNOUT"||type_w=="run out"||type_w=="RUN OUT"||type_w=="stumping"||type_w=="STUMPING")
            {
                char ch;
                cout<<endl<<"Any Extra (y/n)";
                cin>>ch;
                if(ch=='Y'||ch=='y')
                {
                    cout<<endl<<"Type of extra ?";
                    cin>>type_e;
                    c1=extra_choice(type_e);
label:
                    cout<<endl<<"Any extra run ??(0-6)";
                    cin>>extra;
                    switch(c1)
                    {
                    case 1  ://wide ball
                        t.total_runs+=extra+1;
                        t.ex+=extra+1;
                        t.wickets++;
                        freehit=0;
                        if(innings==2)
                        {
                            t.rem_runs-=(extra+1);
                        }
                        t.update_score_card();
                        system("cls");
                        if(innings==1)
                        {
                            cout << "Choose batter_who will out : " << endl;
                            cout << st << ". " << batter[st] << endl;
                            cout << nst << ". " << batter[nst] << endl;
                            cin >> cbt;
                            //bat_display();
                            Out_Batter(cbt);
                        }
                        if(innings==2)
                        {
                            cout << "Choose batter_who will out : " << endl;
                            cout << st << ". " << batter_next[st] << endl;
                            cout << nst << ". " << batter_next[nst] << endl;
                            cin >> cbt;
                            //bat_display();
                            Out_Batter_next(cbt);
                        }
                        break;
                    case 2 ://no ball
                        t.total_runs+=extra+1;
                        freehit=1;
                        t.ex+=extra+1;
                        t.wickets++;
                        if(innings==2)
                        {
                            t.rem_runs-=(extra+1);
                        }
                        cout<<endl<<"Its a free hit!!!"<<endl;
                        getch();
                        t.update_score_card();
                        system("cls");
                        if(innings==1)
                        {
                            cout << "Choose batter_who will out : " << endl;
                            cout << st << ". " << batter[st] << endl;
                            cout << nst << ". " << batter[nst] << endl;
                            cin >> cbt;
                            //bat_display();
                            Out_Batter(cbt);
                            batter_info[st].second++;
                        }
                        if(innings==2)
                        {
                            cout << "Choose batter_who will out : " << endl;
                            cout << st << ". " << batter_next[st] << endl;
                            cout << nst << ". " << batter_next[nst] << endl;
                            cin >> cbt;
                            //bat_display();
                            batter_next_info[st].second++;
                            Out_Batter_next(cbt);
                        }
                        break;
                    case 3  :
                        t.total_runs+=extra;
                        t.ball++;
                        t.balls++;
                        t.ex+=extra;
                        t.wickets++;
                        freehit=0;
                        if(innings==2)
                        {
                            t.rem_runs-=extra;
                            t.rem_balls--;

                        }
                        t.update_score_card();


                        system("cls");
                        if(innings==1)
                        {
                            cout << "Choose batter_who will out : " << endl;
                            cout << st << ". " << batter[st] << endl;
                            cout << nst << ". " << batter[nst] << endl;
                            cin >> cbt;
                            //bat_display();
                            Out_Batter(cbt);
                            batter_info[st].second++;
                        }
                        if(innings==2)
                        {
                            cout << "Choose batter_who will out : " << endl;
                            cout << st << ". " << batter_next[st] << endl;
                            cout << nst << ". " << batter_next[nst] << endl;
                            cin >> cbt;
                            //bat_display();
                            Out_Batter_next(cbt);
                            batter_next_info[st].second++;
                        }
                        break;
                    case 4	:
                        t.total_runs+=extra;
                        t.ball++;
                        t.balls++;
                        t.ex+=extra;
                        t.wickets++;
                        freehit=0;
                        if(innings==2)
                        {
                            t.rem_runs-=extra;
                            t.rem_balls--;
                        }
                        t.update_score_card();
                        system("cls");
                        if(innings==1)
                        {
                            cout << "Choose batter_who will out : " << endl;
                            cout << st << ". " << batter[st] << endl;
                            cout << nst << ". " << batter[nst] << endl;
                            cin >> cbt;
                            //bat_display();
                            Out_Batter(cbt);
                        }
                        if(innings==2)
                        {
                            cout << "Choose batter_who will out : " << endl;
                            cout << st << ". " << batter_next[st] << endl;
                            cout << nst << ". " << batter_next[nst] << endl;
                            cin >> cbt;
                            //bat_display();
                            Out_Batter_next(cbt);
                        }
                        break;
                    default      :
                        cout << "Please Enter valid run(1-4)" << endl;
                        //system("cls");
                        goto label;
                        /*t.total_runs+=extra;
                        t.ex+=extra;
                        t.balls++;
                        t.ball++;
                        freehit=0;
                        t.wickets++;
                        if(innings==2)
                        {
                            t.rem_runs-=extra;
                            t.rem_balls--;
                        }
                        t.update_score_card();*/
                    }
                }
                else
                {
                    cout<<endl<<"any extra run in this runout??(0-6)";
                    cin>>extra;
                    t.total_runs+=extra;
                    freehit=0;
                    t.balls++;
                    t.ball++;
                    t.wickets++;
                    if(innings==2)
                    {
                        t.rem_runs-=extra;
                        t.rem_balls--;
                    }
                    t.update_score_card();
                    batter_info[st].first += extra - 1;
                    system("cls");
                    if(innings==1)
                    {
                        cout << "Choose batter_who will out : " << endl;
                        cout << st << ". " << batter[st] << endl;
                        cout << nst << ". " << batter[nst] << endl;
                        cin >> cbt;
                        //bat_display();
                        batter_info[st].second++;
                        Out_Batter(cbt);
                    }
                    if(innings==2)
                    {
                        cout << "Choose batter_who will out : " << endl;
                        cout << st << ". " << batter_next[st] << endl;
                        cout << nst << ". " << batter_next[nst] << endl;
                        cin >> cbt;
                        //bat_display();
                        batter_next_info[st].second++;
                        Out_Batter_next(cbt);
                    }
                }
            }
            else
            {
                char ch;
                cout<<endl<<"is it a no ball ?? (y/n)";
                cin>>ch;
                if(freehit==0&&(ch=='N'||ch=='n'))
                {
                    t.wickets++;
                    //t.total_runs+=extra;
                    t.balls++;
                    t.ball++;
                    freehit=0;
                    if(innings==2)
                    {
                        t.rem_balls--;
                    }
                    t.update_score_card();
                    system("cls");
                    if(innings==1)
                    {
                        cout << "Choose batter_who will out : " << endl;
                        cout << st << ". " << batter[st] << endl;
                        cout << nst << ". " << batter[nst] << endl;
                        cin >> cbt;
                        batter_info[st].second++;
                        //bat_display();
                        Out_Batter(cbt);
                    }
                    if(innings==2)
                    {
                        cout << "Choose batter_who will out : " << endl;
                        cout << st << ". " << batter_next[st] << endl;
                        cout << nst << ". " << batter_next[nst] << endl;
                        cin >> cbt;
                        //bat_display();
                        batter_next_info[st].second++;
                        Out_Batter_next(cbt);
                    }


                }
                else if(freehit==1&&(ch=='N'||ch=='n'))
                {
                    cout<<endl<<"any extra runs on this free hit ?? (0-6)"<<endl;
                    cin>>extra;
                    t.total_runs+=extra;
                    t.balls++;
                    t.ball++;
                    if(innings==2)
                    {
                        t.rem_runs-=extra;
                        t.rem_balls--;
                    }
                    freehit=0;
                    t.update_score_card();
                    if(innings==1)
                        batter_info[st].first += extra;
                    else
                        batter_next_info[st].first+=extra;
                    //Todo fix extra run kare dibo


                }
                else if(freehit==1&&(ch=='Y'||ch=='y'))
                {
                    cout<<endl<<"any extra runs on this free hit ?? (0-6)"<<endl;
                    cin>>extra;
                    cout<<endl<<"It's a Freehit...."<<endl;
                    Sleep(100);
                    //system("CLR");
                    t.total_runs+=extra+1;
                    t.ex+=extra+1;
                    freehit=1;
                    if(innings==2)
                    {
                        t.rem_runs-=extra;
                    }
                    t.update_score_card();
                    if(innings==1)
                    {
                        batter_info[st].first += extra;
                        batter_info[st].second++;
                    }
                    else
                    {
                        batter_next_info[st].first+=extra;
                        batter_next_info[st].second++;
                    }
                }
                else if(freehit==0&&(ch=='Y'||ch=='y'))
                {
                    cout<<endl<<"any extra runs on this no ball ?? (0-6)"<<endl;
                    cin>>extra;
                    cout<<endl<<"It's a freehit"<<endl;
                    Sleep(100);
                    //system("CLR");
                    t.total_runs+=extra+1;
                    t.ex+=extra+1;
                    freehit=1;
                    if(innings==2)
                    {
                        t.rem_runs-=extra;
                    }
                    getch();
                    t.update_score_card();
                    if(innings==1)
                    {
                        batter_info[st].first += extra - 1;
                        batter_info[st].second++;
                    }
                    else
                    {
                        batter_next_info[st].first+=extra-1;
                        batter_next_info[st].second++;
                    }

                }


            }
            break;
        case 8 :
            //t.update_score_card();
            if(innings == 1)
                t.Full_Score();
            else t.second_Full_Score();
            break;

        default:
            cout<<endl<<"Dead ball"<<endl;

        }
        //cout<<endl<<"Back in loop";
    }
    extra=0;
    if(innings==1)
    {
        system("cls");
        t.Full_Score();
        //getch();
        system("cls");
        cout<<endl<<endl<<"Innings Over..."<<endl;
        cout<<endl<<t.team2<<" REQUIRE "<<t.total_runs+1<<" RUNS of "<<BALLS<<" BALLS "<<endl;
        cout<<endl<<"Wait for next inning...";
        system("pause");
    }
    else
    {
        system("cls");

        if(t.total_runs>=target)
            cout<<endl<<endl<<t.team1<<" WON BY "<<10-t.wickets<<" wickets and "<<BALLS-t.balls<<" balls reamining"<<endl;
        else if(t.total_runs<target-1)
        {
            cout<<endl<<endl<<t.team2<<" WON BY "<<(target-1)-t.total_runs<<"runs";
        }
        else cout<<endl<<endl<<" MATCH IS TIED "<<endl;
    }
}
int extra_choice(string s)
{
    int c;
    if(s=="wide"||s=="WIDE")
        c=1;
    else if(s=="no ball"||s=="NO BALL"||s=="noball"||s=="NOBALL")
        c=2;
    else if(s=="bye"||s=="BYE")
        c=3;
    else if(s=="legbye"||s=="LEGBYE"||s=="legbye"||s=="LEGBYE")
        c=4;
    else
        c=6;
    return c;
}

int main()
{
    T1.display();
}
