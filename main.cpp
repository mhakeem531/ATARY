#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

/* A & B to print the fighter int its place .... i put them here not in the main
 as i used them int the function (stop_game )to make the fighter be printed int its first place
 if the user press (y or Y)
 to under stand goto the function (stop_game)*/
int A = 1;
int B = 18;
// this variable to make the score increase by time
int nn=0 ;
// this variable for the score of the level two
int score2 = 0;

// this variable to make speed increase by time
int increase_speed=0;
/* hint .....
 i used to variables(nn & increase_speed) in the function (stop_game).to make speed normally as i determine (250 ms)
and score begin from zero if three tries was finished
 and the user press (y or Y) to begin the game more time*/
//***************************************************************
//the coming function used to control the dimensions of the console (width & length) during runtime
void SetWindow(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}
//*************************************************************
 /*this function to control places in the console to print in
 it used to print the fighter & ($ & H) int the beginning of the game*/
void gotoxy(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
}
// this function played in the beginning
void presentation()
{

    SetWindow(55,20);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	string wlcm = ".............. WELLCOM TO OUR GAME ...............";
	gotoxy(2, 1);
	for(int i=0; i<wlcm.size(); i++){
		cout<<wlcm[i];
		Sleep(100);
	}
	Sleep(2000);
	string wlcw2= ".......... WE WESH YOU HAVE A NICE TIME ..........";
	gotoxy(2, 4);
	for(int i=0 ; i<wlcw2.size() ; i++)
    {
        cout<<wlcw2[i];
        Sleep(100);
    }
	Sleep(2000);
	string wlcm4= ".............. YOU HAVE THREE TRIES................" ;
	gotoxy(2, 7);
    for (int i=0 ; i<wlcm4.size() ; i++)
    {
        cout<<wlcm4[i];
        Sleep(100);
    }

    Sleep(1000);
	string wlcm3 = "................... GOOD LUCK ....................";
    gotoxy(2, 11);
	for(int i=0 ; i<wlcw2.size() ; i++)
    {
        cout<<wlcm3[i];
        Sleep(100);
    }



	Sleep(1500);
	system("CLS");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_RED);
	string wlcm5 =  "_if you have finished your tries for the first level... \n"  ;
	gotoxy(2, 1);
	for(int i=0 ; i<wlcm5.size() ; i++)
    {
        cout<<wlcm5[i];
        Sleep(100);
    }
    string wlc = "press [Y] to begin a game one time more \n";
    gotoxy(2, 4);
	for(int i=0 ; i<wlc.size() ; i++)
    {
        cout<<wlc[i];
        Sleep(100);
    }
    Sleep(500);

    string flm="press [N] to exit";
    gotoxy(2,7);
    for(int i=0 ; i<flm.size() ; i++)
    {
        cout<<flm[i];
        Sleep(100);
    }
    Sleep(250);
    string ll="if your score reached 500 in the first level \n\n\n   you will go to the second level";
    gotoxy(2,10);
   for(int i=0 ; i<ll.size() ; i++)
    {
        cout<<ll[i];
        Sleep(100);
    }
    Sleep(250);
	Sleep(2500);
	system("CLS");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE);

	string wlcm6 =  ".............. THIS IS THE FIRST TRY .............." ;
	gotoxy(2, 8);
	for(int i=0 ; i<wlcm6.size() ; i++)
    {
        cout<<wlcm6[i];
        Sleep(100);
    }
	Sleep(1500);

	system("CLS");

}
// the shape of the fighter
char xf[3][4] = {
  /*"0=0",
	"|X|",
	"0=0",*/
            "\xc9\x20\xbb",
            "\xc8\xcb\xbc",
            "\xc9\xca\xbb",

};
/*the function to print the fighter at a end of the track;
 hint ....
 if there was not (d++);
 the shape will be
        0=0
       |x|
       0=0                                               */
void print_fighter(int c, int d)
{
	for (int i = 0; i<3; i++)
	{
		gotoxy(c, d);
		cout << xf[i] << endl;
		d++;
	}
}
// the array of the track;
char yf[20][19] = {
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",
	"|                |",


};
// these two function to modify the size of the console to be suite to the size of the track
// the first to handle the width from 55 to 21
void set_width()
{
    int nx = 55;
    while(nx>=25)
    {
         Sleep(75);
         SetWindow(nx,20);
         nx--;


    }

}
// this function to handle length from 20 to 25;
void set_length()
{
    int nx2 = 20;
    while(nx2<=30)
    {
         Sleep(75);
         SetWindow(21,nx2);
         nx2++;


    }

}

// the function to print the track;

void print_track()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_GREEN | FOREGROUND_INTENSITY );

	for (int i = 0; i<20; i++)

	{
		cout << yf[i] << endl;
	}
};

// this function for direction
// (r , s) = (a , b) int the main function
void directions(int&r,int&s)//,int &hh2 , int &ii2 , int &jj2 , int &kk2 , int &ee2 , int &ff2 , int &ll2 , int &mm2)
{
		if (GetAsyncKeyState(VK_LEFT))
		{

			if (r == 1)
			{
				r = r+1;
			}
			r--;
		}

		/////////////////////////////////////////////////////

    if (GetAsyncKeyState(VK_RIGHT))
		{
			if (r+2 == 16)
			{
				r = r - 1;
			}
			r++;
		}

		  if(GetAsyncKeyState(VK_DOWN))
          {
              s++;
              if(s+2==23)
              {
                  s=s-1;
              }

          }


  if(GetAsyncKeyState(VK_UP))
  {
      if(s==0)
      {
         s=1;
      }
      s--;
  }
}
/*this function to print every $ and H character
  (h & i)&&(j & k)=====>to print every $
  (e & f)&&(l & m)=====>to print every H
  hint .....
  calling by reference as these variables their values will change within calling the function.....
  so this change should by saved
  (s) to store the score in it in each time the fighter collect a ($)...... the function will return
  it
  if (f1 or m1) reached to the end of the track .... it  will begin another time randomly from the
  beginning of the track
   hint.....
  if one of (H)s hit the fighter any where another try will begin and in this function i make this (H)
  to begin down of the fighter directly
  if one of ($)s  hit the fighter any where the score will increase by 3
  after this i make this($) to disappear in the whole track down of the fighter and begin from the top
  of the track randomly*/
int print_and_calc_score(int &e1 , int &h1 , int &i1 , int &f1 , int &j1 , int &k1 , int &l1 , int &m1 ,  int &a1 , int &b1)
{

        int s = 0;
        gotoxy(h1 , i1);
		cout << "$";
		gotoxy(j1 , k1);
		cout << "$";
		gotoxy(e1 , f1);
		cout << "H";
		gotoxy(l1 , m1);
		cout << "H";
		if((a1==e1&&b1+1==f1)||(a1+1==e1&&b1+1==f1)||(a1+2==e1&&b1+1==f1))
        {
          f1 = b1+3;//=== this part to disappear H in the next try if a H hit the fighter under the fighter [1];


        }

        if (f1 >= 21)//**************22
		{
			f1 = rand()%2;
			e1 = rand()%16 + 1;
		}

     if((a1==l1&&b1+1==m1)||(a1+1==l1&&b1+1==m1)||(a1+2==l1&&b1+1==m1))
     {
         m1= b1+3;
         if (m1 >= 21)//***********22
		{
			m1 = rand()%2;
			l1 = rand()%16 +1;
		}

     }
          if((a1==l1&&b1+2==m1)||(a1+1==l1&&b1+2==m1)||(a1+2==l1&&b1+2==m1))
     {
         m1=b1+3;
         if (m1 >=21)
		{
			m1 = rand()%2;
			l1 = rand()%16 +1;
		}

     }

      if (m1 == 21)
		{
			m1 = rand()%2;
			l1 = rand()%16 +1;
		}
		///////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////


       if((a1 == h1 && b1 == i1)||(a1+1 == h1 && b1 == i1)||(h1==a1+2 && i1==b1))
        {
            s=s+3;
            i1 = 0;
           h1 = rand()% 16+1;

        }
        if((a1 == h1 && b1+1 == i1)||(a1+2 == h1 && b1+1 == i1))
        {
            s=s+3;
            i1 = 0;
            h1 = rand()% 16+1;

        }

         if((a1 == h1 && b1+2 == i1)||(a1+1 == h1 && b1+2 == i1)||(h1==a1+2 && i1==b1+2))
        {
            s=s+3;
            i1 =0;
            h1 = rand()% 16+1;

        }
        if(a1+1==h1&&b1+1==i1)
        {
            i1=0;
            h1=rand()%16+1;

        }


        if (i1 == 21)
		{
			i1 = 0;
			h1 = rand() % 16 + 1;
		}
  //////////////////////////////////////////////////////////////////////////////////////////////////
 //                              calculate score                                                 //
//////////////////////////////////////////////////////////////////////////////////////////////////

        if((a1 == j1 && b1 == k1)||(a1+1 == j1 && b1 == k1)||(j1==a1+2 && k1==b1))
        {
            s=s+3;
            k1 =0;
            j1 = rand()% 16+1;

        }
        if((a1 == j1 && b1+1 == k1)||(a1+2 == j1 && b1+1 == k1))
        {
            s=s+3;
            k1 = 0;
            j1 = rand()% 16+1;

        }

         if((a1 == j1 && b1+2 == k1)||(a1+1 == j1 && b1+2 == k1)||(j1==a1+2 && k1==b1+2))
        {
            s=s+3;
            k1 =0;
            j1 = rand()% 16+1;

        }

       if(a1+1==j1&&b1+1==k1)
       {
           k1=0;
           j1=rand()%16+1;
       }

     if (k1 == 21)
		{
			k1 = 0;
			j1 = rand() % 16 + 1;
		}

return s;

};
/* this function to make game stop after 3 tries and if the user press(Y or y) it will begin as the first time
   in the end of this function i make (nn==0 && increase_speed==0) to make the game begin normally as the first time
   and the score itself will be 0
   hint....
   if one of (H)s hit the fighter the score will decrease by 1 int the beginning of the next try
   but............ HOW THIS WILL BE MADE????
   THE shape of the fighter will divided into (0 & = & 0 & | & | & 0 & = & 0)
   so if one of (H)s hit the fighter hit one of these parts this will count as one of the 3 tries
   if the number of tries is 3 ....the user will be asked press(Y or y) to begin or (N or n) to exit the game
   if he pressed y or Y ...(nn && increase_speed)will be 0 to make the game begin randomly as the first time*/
int stop_game(int &aa, int &bb, int &ee, int &ff, int &ll, int &mm, int &Score, int &tries_Counter)
{
    int to_exite_game;
	char user_ans;
	if ((aa == ee&&bb == ff) || (aa + 1 == ee&&bb == ff) || (aa + 2 == ee&&bb == ff) || (aa == ee&&bb + 1 == ff) || (aa + 2 == ee&&bb + 1 == ff) || (aa == ee&&bb + 2 == ff) || (aa + 1 == ee&&bb + 2 == ff) || (aa + 2 == ee&&bb + 2 == ff))
	{
	    //to make a sound in case of hitting on of (H)s
	    cout<<"\a";
		Score = Score - 1;
		if (Score<0)
		{
			Score = 0;
		}
		tries_Counter = tries_Counter + 1;
		Sleep(2500);
		system("CLS");
		if (tries_Counter<4)

		{
			//SetWindow(055,025);//====>make the console in its normal size till the message print
			//gotoxy(8, 18);
			gotoxy(1,1);
			cout << "sorry you filed \n here your try number\n       "<<tries_Counter << endl;
			Sleep(2500);
			//SetWindow(21,25);
		}
		if (tries_Counter == 4)
		{
			Score = 0;
			Sleep(500);
			system("CLS");
			//SetWindow(055,025);//====>make the console in its normal size till the message print
			//cout << "now you have finished all your tries" << endl << endl << "  please press [Y] to begin the game one more" << endl << endl << "  press [N] to exit" << endl;
			string v1 = " you have finished all your tries\n\n please:\n press [Y] to begin\n the game one more\n\n press [N] to exit" ;
			gotoxy(0,1);
			for (int i=0 ; i<v1.size() ; i++)
            {
                cout<<v1[i];
                Sleep(15);
            }
             cout << endl;
			 cin >> user_ans;
			if (user_ans == 'N' || user_ans == 'n')
			{
				tries_Counter = 0;
				system("CLS");
				gotoxy(7, 18);
				cout << "the game will be closed";
				Sleep(1500);
				exit(0);
			}
			else if (user_ans == 'y' || user_ans == 'Y')
			{
				to_exite_game = 1;
				tries_Counter = 0;
				aa = A;
				bb = B;
				nn = 0;
                increase_speed = 0;

			}


		}

	}
	if ((aa == ll&&bb == mm) || (aa + 1 == ll&&bb == mm) || (aa + 2 == ll&&bb == mm) || (aa == ll&&bb + 1 == mm) || (aa + 2 == ll&&bb + 1 == mm) || (aa == ll&&bb + 2 == mm) || (aa + 1 == ll&&bb + 2 == mm) || (aa + 2 == ll&&bb + 2 == mm))
	{
        //to make a sound in case of hitting on of (H)s
        cout<<"\a";
		Score = Score - 1;
		if (Score<0)
		{
			Score = 0;
		}
		tries_Counter = tries_Counter + 1;
		Sleep(2500);
		system("CLS");
		if (tries_Counter<4)
		{
          //  SetWindow(055,025);//====>make the console in its normal size till the message print
			//gotoxy(8, 18);
			gotoxy(1,1);
			cout << "sorry you filed \n here your try number\n       " << tries_Counter << endl;
			Sleep(2500);
		}
		if (tries_Counter == 4)
		{
			Score = 0;
			Sleep(500);
			system("CLS");
			//SetWindow(055,025);//====>make the console in its normal size till the message print
			//gotoxy(8, 18);
			//cout << " now you have finished all your tries" << endl << endl << "  please press [Y] to begin the game one more" << endl << endl << "  press [N] to exit" << endl;
			string v1 = " you have finished all your tries\n\n please:\n press [Y] to begin\n the game one more\n\n press [N] to exit" ;
			gotoxy(0,1);
			for (int i=0 ; i<v1.size() ; i++)
            {
                cout<<v1[i];
                Sleep(15);
            }
			 cout<<endl;
			 cin >> user_ans;
			if (user_ans == 'N' || user_ans == 'n')
			{
				tries_Counter = 0;
				system("CLS");
				gotoxy(7, 18);
				cout << "the game will be closed";
				Sleep(1500);
				exit(0);
			}
			else if (user_ans == 'y' || user_ans == 'Y')
			{
				Score = 0;
				to_exite_game = 1;
				tries_Counter = 0;
                increase_speed = 0;
				ee = 1;
				aa = A;
				bb = B;
				nn = 0;

			}

		}
	}
	return to_exite_game;

}
/////////////////////////////////////////////////////////////////////////////

     /////////////////////////////////////////////////
    /////////////////////////////////////////////////
   //////FUNCTIONS FOR THE SECOND LEVEL/////////////
  /////////////////////////////////////////////////
 /////////////////////////////////////////////////
 char block[3] = "**";
 /////////////////////////////////////


    void stop_game2(int &aa, int &bb, int &ee, int &ff, int &ll, int &mm, int &Score2, int &tries_Counter)
{
   // int to_exite_game;
	//char user_ans;
	if ((aa == ee&&bb == ff) || (aa + 1 == ee&&bb == ff) || (aa + 2 == ee&&bb == ff) || (aa == ee&&bb + 1 == ff) || (aa + 2 == ee&&bb + 1 == ff) || (aa == ee&&bb + 2 == ff) || (aa + 1 == ee&&bb + 2 == ff) || (aa + 2 == ee&&bb + 2 == ff))
	{
		Score2 = Score2 - 1;
		if (Score2<0)
		{
			Score2 = 0;
		}
		tries_Counter = tries_Counter + 1;
		Sleep(2500);
		system("CLS");
		if (tries_Counter<4)
		{
			gotoxy(0, 10);
			cout << "sorry you filed \n\n here your try number" <<endl<<endl<<"    "<<tries_Counter << endl;
			Sleep(2500);
		}
		if (tries_Counter == 4)
		{
			//Score = 0;
			Sleep(500);
			system("CLS");
			cout << "now you have finished all your tries" ;
			Sleep(750);
			system("CLS");
			gotoxy(0 , 10);
			cout<<"the game will exit";
			Sleep(750);
			system("CLS");
			gotoxy(0,10);
			cout<<"THANKS FOR YOU";
			Sleep(1500);
			exit(0);

		}

	}
	if ((aa == ll&&bb == mm) || (aa + 1 == ll&&bb == mm) || (aa + 2 == ll&&bb == mm) || (aa == ll&&bb + 1 == mm) || (aa + 2 == ll&&bb + 1 == mm) || (aa == ll&&bb + 2 == mm) || (aa + 1 == ll&&bb + 2 == mm) || (aa + 2 == ll&&bb + 2 == mm))
	{
		Score2 = Score2 - 1;
		if (Score2<0)
		{
			Score2 = 0;
		}
		tries_Counter = tries_Counter + 1;
		Sleep(2500);
		system("CLS");
		if (tries_Counter<4)
		{
			gotoxy(0, 10);
			cout << "sorry you filed \n\n here your try number" <<endl<<endl<<"    "<<tries_Counter << endl;
			Sleep(2500);
		}
		if (tries_Counter == 4)
		{
			Score2 = 0;
			Sleep(500);
			system("CLS");
			gotoxy(0, 10);
			cout << " now you have finished all your tries" ;
			Sleep(250);
			system("CLS");
			gotoxy(0 , 10);
			cout<<"the game will exit";
			Sleep(250);
			system("CLS");
			gotoxy(0,10);
			cout<<"THANKS FOR YOU";
			Sleep(1000);
			exit(0);

		}
	}


}

////////////////////////////////*************************///////////////////***********
// this function to print blocks and (H)s end ($)s
void print_blocks_Hs_$S( int & a1 , int &b1 , int &n1 , int &o1 , int &p1 , int &q1 , int &h1 , int &i1 , int &j1 , int &k1 , int &e1 , int &f1 , int &l1 , int &m1, int &Score2)// , int &t1 , int &u1  )
{
    gotoxy(n1 , o1);
    cout<<block;
    gotoxy(p1 , q1);
    cout<<block;
    //**********//
    gotoxy(h1 , i1);
    cout<<"$";
    gotoxy(j1 , k1);
    cout<<"$";
    gotoxy(e1 , f1);
    cout<<"H";
    gotoxy(l1 , m1);
    cout<<"H";
    //////////////////////////////////////////////
        //if the fighter hit the right block;
      if(p1==a1+1&&q1==b1)
      {
       q1=b1+3;
       Score2 = Score2 - 10;
        if(Score2 < 0)
        {
            Score2 = 0;
        }

      }
      if(p1==a1+2&&b1==q1)
      {
        q1=b1+3;
        Score2 = Score2 - 10;
        if(Score2 < 0)
        {
            Score2 = 0;
        }
      }
      if(p1==a1+2&&q1==b1+1)
      {
        q1=b1+3;
       Score2 = Score2 - 10;
        if(Score2 < 0)
        {
            Score2 = 0;
        }
      }
      if(p1==a1+1&&q1==b1+2)
      {
        q1=b1+3;
       Score2 = Score2 - 10;
        if(Score2 < 0)
        {
            Score2 = 0;
        }
      }
      if(p1==a1+2&&q1==b1+2)
      {
       q1=b1+3;
       Score2 = Score2 - 10;
        if(Score2 < 0)
        {
            Score2 = 0;
        }
      }

    //if the fighter hit the left block;
    if(n1==a1&&o1==b1)
   {
        Score2 = Score2 - 10;
        o1=b1+3;
        if(Score2 < 0)
        {
            Score2 = 0;
        }
    }
    if(n1+1==a1&&o1==b1)
    {
        o1=b1+3;

        Score2 = Score2 - 10;
        if(Score2 < 0)
        {
            Score2 = 0;
        }
    }
    if(n1+1==a1&&o1==b1+1)
        {
         o1=b1+3;

        Score2 = Score2 - 10;
        if(Score2 < 0)
        {
            Score2 = 0;
        }
    }
    if(n1==a1&&o1==b1+2)
    {
        o1=b1+3;
        Score2 = Score2 - 10;
        if(Score2 < 0)
        {
            Score2 = 0;
        }
    }
    if(n1+1==a1&&o1==b1+2)
    {
       o1=b1+3;
        Score2 = Score2 - 10;
        if(Score2 < 0)
        {
            Score2 = 0;
        }
    }

///////////////////////////////////////////////////////////////////
    if(o1 >= 21)
    {
        o1 = 0;
        n1 = 1;
    }
    if(q1 >= 21)
    {
        q1 =0; rand() % 2+1;
        p1 =15;
    }
    ///////////////////////
    if (i1 >= 21)
		{
			i1 = 0;
			h1 = rand() % 16 + 1;
		}
    if(k1 >= 21)
    {
        k1 = 0;
        j1 = rand()%8+9;
    }
    if(f1>=22)
    {
        e1=rand()%8+1;
        f1=rand()%2;
    }
    if(m1>=22)
    {
        l1=rand()%8+9;
        m1=0;
    }

}
/////////////////////****************//////////////////************///////////////////



 ////////////////////////////////////////////////////////////////////////////////
 //ÇáÏÇáå Ïå åÇÊÑÌå ÇáÓßæÑ áæ  ÎÈØ Ýí $ æßãÇä ÈÊØÈÚ ßá H  æ $ ÌæÇ ÇáÊÑÇß
//áæ HÎÈØ ÈÊÒæÏ ÇáÇÍÏÇËí ÇáÕÇÏí áå 3 ÚÔÇä ÇáãÍÇæáí Çááí ÌÇíå Çäå íÙåÑ ãä ÊÍÊ Çáfighter
 // this function to print every H or $ and calc score if one of $ hit the fighter
 // print every H in the next try after hitting the fighter
void calculate_score(int &a1 , int &b1 , int &e1 , int &f1 , int &l1 , int &m1 , int &p1 , int &q1 , int &n2 , int &o2 , int &h1 , int &i1 , int &j1 , int &k1 , int &score2)// , int &t1 , int &u1  )
{
   // int s = 0;
     // now we will calc score if one of $ hit the fighter

       if((a1 == h1 && b1 == i1)||(a1+1 == h1 && b1 == i1)||(h1==a1+2 && i1==b1))
        {
            score2=score2+5;
            i1 = 0;
           h1 = rand()% 16+1;

        }
        if((a1 == h1 && b1+1 == i1)||(a1+2 == h1 && b1+1 == i1))
        {
            score2=score2+5;
            i1 = 0;
            h1 = rand()% 16+1;

        }

         if((a1 == h1 && b1+2 == i1)||(a1+1 == h1 && b1+2 == i1)||(h1==a1+2 && i1==b1+2))
        {
            score2=score2+5;
            i1 =0;
            h1 = rand()% 16+1;

        }
        if(a1+1==h1&&b1+1==i1)
        {
            i1=0;
            h1=rand()%16+1;

        }


        if (i1 >= 21)
		{
			i1 = 0;
			h1 = rand() % 16 + 1;
		}

    ///////////////////////////////////////
////////////////////////////////////////////
if((a1 == j1 && b1 == k1)||(a1+1 == j1 && b1 == k1)||(j1==a1+2 && k1==b1))
        {
            score2=score2+5;
            k1 =0;
            j1 = rand()% 16+1;

        }
        if((a1 == j1 && b1+1 == k1)||(a1+2 == j1 && b1+1 == k1))
        {
            score2=score2+5;
            k1 = 0;
            j1 = rand()% 16+1;

        }

         if((a1 == j1 && b1+2 == k1)||(a1+1 == j1 && b1+2 == k1)||(j1==a1+2 && k1==b1+2))
        {
            score2=score2+5;
            k1 =0;
            j1 = rand()% 16+1;

        }

       if(a1+1==j1&&b1+1==k1)
       {
           k1=0;
           j1=rand()%16+1;
       }

    if(k1 >= 21)
    {
        k1 = 0;
        j1 = rand()%8+9;
    }
/////////////////////////
////////////////////////////////////////
   if((a1==e1&&b1+1==f1)||(a1+1==e1&&b1+1==f1)||(a1+2==e1&&b1+1==f1))
        {
          f1 = b1+3;//=== this part to disappear H in the next try if a H hit the fighter under the fighter [1];


        }

        if((a1==e1&&b1+2==f1)||(a1+1==e1&&b1+2==f1)||(a1+2==e1&&b1+2==f1))
        {
            f1 = b1+3;//=== this part to disappear H in the next try if a H hit the fighter under the fighter [1];
        }

    if(f1>=22)
    {
        e1=rand()%8+1;
        f1=rand()%2;
    }
    //////////////////////////
    ////////////////////
    if((a1==l1&&b1+1==m1)||(a1+1==l1&&b1+1==m1)||(a1+2==l1&&b1+1==m1))
     {
         m1= b1+3;
         if (m1 >= 22)
		{
			m1 = rand()%2;
			l1 = rand()%16 +1;
		}

     }
    if((a1==l1&&b1+2==m1)||(a1+1==l1&&b1+2==m1)||(a1+2==l1&&b1+2==m1))
     {
         m1=b1+3;
         if (m1 >=22)
		{
			m1 = rand()%2;
			l1 = rand()%16 +1;
		}

     }

    if(m1>=22)
    {
        l1=rand()%8+9;
        m1=0;//rand()%2;
    }
     ///////////////////////////////////////////////
    // this part to not make one of (H)s appear int the same place of one of the blocks
   // the right block
    if((p1==l1&&q1==m1)||p1+1==l1&&q1==m1)
    {
       l1 = q1 - 1;
    }
    // the left block
    if((e1==n2&&f1==o2)||(e1==n2+1&&f1==o2))
    {
        e1=o2-1;
    }

}

 ////////////////////// THE END ////////////////
///////////////////////////////////////////////
// this function to move the user to level two if his score reached a certain number
bool check_to_move(int &sss)
{
    if(sss>=500)
        return 1;
    else
        return 0;
}
///////////////////////////////////////////////////
int increase_Speed(int &SPEED)
{
        increase_speed++;
        if(increase_speed >= 0 && increase_speed<150)
        {
            SPEED=250;
        }
        if(increase_speed >= 150 && increase_speed < 300)
        {
            SPEED = 200;
        }
        if(increase_speed >= 300 && increase_speed < 700)
        {
            SPEED = 130;
        }
        if(increase_speed >= 700 && increase_speed < 1300)
        {
            SPEED = 80;
        }
        if(increase_speed >= 1750)
        {
            SPEED = 50;
        }
        return SPEED;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////FOR LEVEL TWO///////////////////////////

int main()
{
   	int speed=250;
   	int increase_speed=0;
   	int toexite;//this variable will be 1 if the user press Y OR Y to could complete the game
	int tries_counter = 1;
	int skipe;
	cout<<"to skip the presentation... press 1 "<<endl;
	cout<<"for showing  the presentation... press 2"<<endl;
	cin>>skipe;
	system("CLS");
	if(skipe!=1)
	presentation();
	else
    {
        cout<<"now the game will begin"<<endl;
   }
   system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
    set_width();
    Sleep(50);
    set_length();
	srand(time(0));
	int score = 0;
	int a = A;
	int b = B;
// this variables are the argument of the function of ......... print_and_calc_score;
	int e = 1;
	int h = 15;
	int i = 4;
	int f = 0;
	int j = 3;
	int k = 2;
	int l = 2;
	int m = 5;

	do


	{

		print_track();
        int w = print_and_calc_score(e , h , i , f , j , k , l , m , a , b);
		score = score + w;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
        if(check_to_move(score)==1)
        {
        Sleep(500);
        system("CLS");
        Sleep(1000);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
        string move_message="now you will\n goto level two";
        gotoxy(1,12);
        for(int i=0 ; i<move_message.size() ; i++)
        {
        cout<<move_message[i];
        Sleep(150);
        }
        Sleep(250);
        system("CLS");
        break;
        }
		print_fighter(a, b);

		directions(a,b);// ,h,i,j,k,e, f,l,m);

		toexite = stop_game(a, b, e, f, l, m, score, tries_counter);


		f++;
		i++;
		k++;
		m++;
		nn++;

		// this part to increase the score with time passing
		     if(nn>360)
               {
                   if(nn%20 == 0)
                     {score=score+5;}

               }
        ///////////////////////////////////

        int y = increase_Speed(speed);
		gotoxy(0, 23);
		cout << "score now is : " << score;
		Sleep(y);
		system("CLS");


	} while (toexite = 1);


 	// the beginning of the second level
	score ;
	int w2 = 0;
//for the fighter
	a = A;
	b = b;
// variables for (H)s;
    e = 4;
    f = 1;
    l = 13;
    m = 4;
//variables for ($)s;
    h = 9;
    i = 0;
    j = 11;
    k = 3;
//variables for the blocks;
    int n = 1;
    int o = 7;
    int p = 15;
    int q = 0;
    //////////
    do
    {
       srand(time(0));
       if(check_to_move(score2)==1)
       {
           Sleep(750);
           system("CLS");
           string mmmm = "congratulation\n you have won\n ";
           gotoxy(0,12);
           for(int i=0 ; i<mmmm.size() ; i++)
           {
               cout<<mmmm[i];
               Sleep(250);
           }
           break;
       }
       print_track();
       print_fighter(a , b);
       // this function the same of the first level;
       directions(a , b);
      print_blocks_Hs_$S(a,b,n,o,p,q,h,i,j,k,e,f,l,m,score2);
      calculate_score(a,b,e,f,l,m,p,q,n,o,h,i,j,k,score2);
     stop_game2(a,b,e,f,l,m,score2,tries_counter);

     o++;
     q++;
     f++;
     m++;
     i++;
     k++;

     int y = increase_Speed(speed);
     gotoxy(0,23);
     cout<<"your score now is :"<<score2;
     Sleep(y);
     system("CLS");}while(1);


	system("PAUSE");
    return 0;
}


