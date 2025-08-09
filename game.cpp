//============================================================================
// Name        : game.cpp
// Author      : Muhammad Absar Khalid
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
//#include <boost/lexical_cast.hpp>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
	int boost1=0;
        int speed=4;
	int speed2=4;
	int speed3=4;
	int pause2=0;
	float c1x = 406; 
	float c1y = 34; 
	float c2x = 358; 
	float c2y = 34;
	float c3x=418;
	float c3y=760;
	double touch[10][10]; 
	int score=0,lives=3,money=0;
	int state1=0,state2=0,state3=0,state4=0,state5=0,state6=0,state7=0,state8=1,state9=0,state10=0;
	int state11=0,state12=0,state13=0,state14=0,state15=0,state16=0;
	int firex,firey,firex2,firey2;
	int highScore[10];
	string line;
	bool loadScore = true;
	int level=1;
	int counter[4];
	int var=0;
	int newgameloading1=0;
	int condition1=0;
	int ngame=0;
	float* colourofcar=colors[BLUE];
	float* colourofarena=colors[YELLOW];
	int firingon=0;



/*
if (condition1==1){	
c3x = 418;
c3y = 760;
}*/


	//string mystr= boost::lexical_cast<string>(score); 
	//stringstream string;
	//string<<score;
	//string s;
	//string>>s; 


    //std::string str = std::to_string(score);
//string str=to_string(score);


// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
void refiller(){
int aaaa=0;
int bbbb=0;
for(aaaa=0;aaaa<10;aaaa++){
for (bbbb=0;bbbb<10;bbbb++){
	
	touch[bbbb][aaaa]=0;
	}
	bbbb=0;
	}
}



void startermenu()
{
	DrawSquare(0,0,880,colors[BLACK]);
	DrawString( 270,640,"ASPHALT 1.0 VERSION", colors[BLUE]);
	DrawString( 270,510,"START A NEW GAME", colors[WHITE]);
	DrawString( 310,450," HIGH SCORE", colors[WHITE]);
	DrawString( 350,390,"HELP", colors[WHITE]);
	DrawString( 760,40,"SHOP", colors[MEDIUM_SPRING_GREEN]);
	DrawString( 15,40,"UPGRADES", colors[MEDIUM_SPRING_GREEN]);
	DrawString( 320,40,"MULTIPLAYER", colors[MEDIUM_SPRING_GREEN]);
	DrawString( 350,330,"QUIT", colors[WHITE]);
	speed=0;
	speed2=0;
	speed3=0;
}

void menu()    //Function for Menu Display
{
	DrawSquare(0,0,880,colors[BLACK]);
	DrawString( 270,700,"ASPHALT 1.0 VERSION", colors[BLUE]);
	DrawString( 270,570,"START A NEW GAME", colors[WHITE]);
	DrawString( 300,510,"RESUME GAME", colors[WHITE]);
	DrawString( 310,450," HIGH SCORE", colors[WHITE]);
	DrawString( 350,390,"HELP", colors[WHITE]);
	DrawString( 760,40,"SHOP", colors[MEDIUM_SPRING_GREEN]);
	DrawString( 15,40,"UPGRADES", colors[MEDIUM_SPRING_GREEN]);
	DrawString( 320,40,"MULTIPLAYER", colors[MEDIUM_SPRING_GREEN]);
	DrawString( 350,330,"QUIT", colors[WHITE]);
	speed=0;
	speed2=0;
	speed3=0;

	//DrawString(45, 840, "Score="+ (realscore), colors[DARK_GOLDEN_ROD]);
	//DrawString( 381, 840, "Level="+ (reallevel), colors[DARK_GOLDEN_ROD]);
	//DrawString( 718, 840, "Lives="+ (reallives), colors[DARK_GOLDEN_ROD]);
}	



int convertStringToIntGame(string s){
	stringstream required(s);
	int x = 0;
	required >> x;
	return x;	
}

string convertIntToStringGame(int x){
	ostringstream required;
	required << x;
	string ans = required.str();
	return ans;
}

void loadHighScore(){
	ifstream fin;
	fin.open("highscore.txt");
	int i=0;
	while(fin){
		getline(fin,line);
		if(i<10){
			highScore[i] = convertStringToIntGame(line);
			i++;
		}
	}
	
	fin.close();
}

void highscore()
{
	DrawSquare(0,0,880,colors[BLACK]);
	ifstream fin;

	fin.open("highscore.txt");
	DrawString(340, 750, "HIGHSCORES", colors[BLUE]);
int yaxis=670;


	for(int i=0;i<10;i++){
		DrawString(365, yaxis,convertIntToStringGame(highScore[i]), colors[SKY_BLUE]);
		yaxis -= 40;
	}



	DrawString( 365,120,"BACK", colors[WHITE]);
	speed=0;
	speed2=0;
        speed3=0;
}

void shop()
{
	DrawSquare(0,0,880,colors[MEDIUM_SPRING_GREEN]);
	DrawString(365, 750, "SHOP", colors[BLUE]);
	DrawString(160, 450, "VEHICLES", colors[DARK_RED]);
	DrawString(360, 450, "ARENAS", colors[DARK_RED]);
	DrawString(570, 450, "WEAPONS", colors[DARK_RED]);
	DrawString( 365,120,"BACK", colors[BLACK]);
	speed=0;
	speed2=0;
	speed3=0;


}
void buyingerror()
{
	DrawRectangle(135, 360, 570, 250,colors[DARK_SEA_GREEN]); 
	DrawString( 160,540,"You Have Not Enough Rupees To Buy This Product.", colors[RED]);
	DrawString( 370,410,"OKAY", colors[RED]);
}
void buyingcongrats()
{
	DrawRectangle(50, 360, 740, 250,colors[DARK_SEA_GREEN]); 
	DrawString( 60,540,"CONGRATULATIONS You Have Successfully Purchased This Product.", colors[BLUE]);
	DrawString( 365,410,"OKAY", colors[BLUE]);
}


void vehicles()
{
	DrawSquare(0,0,880,colors[BLACK]);
	
	DrawString( 365,30,"BACK", colors[WHITE]);
	speed=0;
	speed2=0;
	speed3=0;
}

void weapons()
{
	DrawSquare(0,0,880,colors[BLACK]);
	DrawString(365, 820, "WEAPONS", colors[DARK_RED]);
	DrawString(390, 740, "GUNS", colors[DARK_SEA_GREEN]);
	DrawString(30, 660, "COLT M4", colors[BLUE]);
	DrawString(30, 630, "5000 Rs/", colors[BLUE]);
	DrawString( 365,30,"BACK", colors[WHITE]);
	speed=0;
	speed2=0;
	speed3=0;

}


void arena()
{
	DrawSquare(0,0,880,colors[BLACK]);
	DrawString(365, 820, "ARENAS", colors[DARK_RED]);
	DrawString(357, 740, "4-ROADS", colors[DARK_SEA_GREEN]);
	DrawString(30, 660, "GOLDEN WALLS", colors[DARK_GOLDEN_ROD]);
	DrawString(67, 630, "20000 Rs/", colors[BLUE]);
	DrawString( 365,30,"BACK", colors[WHITE]);
	speed=0;
	speed2=0;
	speed3=0;


}



void upgrades()
{
	DrawSquare(0,0,880,colors[MEDIUM_SPRING_GREEN]);
	DrawString(340, 750, "UPGRADES", colors[BLUE]);

	DrawString( 365,120,"BACK", colors[BLACK]);
	speed=0;
	speed2=0;
	speed3=0;




}


void help() //Function for Help in Menu
{
	DrawSquare(0,0,880,colors[BLACK]);
	DrawString( 290,760,"HELP FOR GAMEPLAY", colors[ORANGE]);
	DrawString( 50,560,"1- PRESS (ARROW UP) KEY TO MOVE UPWARD", colors[ORANGE]);
	DrawString( 50,520,"2- PRESS (ARROW DOWN) KEY TO MOVE DOWNWARD", colors[ORANGE]);
	DrawString( 50,480,"3- PRESS (ARROW LEFT) KEY TO MOVE LEFT", colors[ORANGE]);
	DrawString( 50,440,"4- PRESS (ARROW RIGHT) KEY TO MOVE RIGHT", colors[ORANGE]);
	DrawString( 50,400,"5- PRESS (SPACEBAR) FOR DOUBLE ACCERLATION", colors[ORANGE]);
	DrawString( 50,360,"6- PRESS (P OR ESCAPE) FOR MENU AND PAUSE THE GAME ", colors[ORANGE]);
	DrawString( 50,320,"7- PRESS (F) FOR FIRING TO DESTROY OPPONENT'S CAR ", colors[ORANGE]);
	
	DrawString( 365,120,"BACK", colors[WHITE]);
	speed=0;
	speed2=0;
	speed3=0;

}

void saveHighScore(){
	for(int i=0;i<10;i++){
	int temp = highScore[i],temp2;
	if(score>highScore[i]){
		for(int j=i+1;j<10;j++){
			temp2=highScore[j];
			highScore[j]=temp;
			temp=temp2;
		}
		highScore[i]=score;
		break;
	}
}

	ofstream fout;
    	fout.open("highscore.txt");
	int i= 0; 
    while (fout) { 
  
	if(i<10){
         line = convertIntToStringGame(highScore[i]); 
        fout << line << endl;
        if (i==9){
            break;
	}
	i++;
	}
    } 
	fout.close();		
}

bool saveScoreFinal = true;
void won()
{

	DrawSquare(0,0,880,colors[BLACK]);
	DrawString( 350,440,"YOU WON", colors[BLUE]);
	DrawString( 320,120,"BACK TO MENU", colors[WHITE]);
	if(saveScoreFinal){
		saveHighScore();
		saveScoreFinal = false;
	}
}

void endgame()     //Function for Quit Game in Menu
{
	DrawSquare(0,0,880,colors[BLACK]);
	DrawString( 350,440,"GAME OVER", colors[RED]);
	DrawString( 365,120,"BACK", colors[WHITE]);
	if(saveScoreFinal){
		saveHighScore();
		saveScoreFinal = false;
	}
	speed=0;
	speed2=0;
	speed3=0;
	condition1=0;


}


void exit()     //Function for Quit Game in Menu
{

	DrawSquare(0,0,880,colors[BLACK]);
	DrawString( 220,570,"ARE YOU SURE YOU WANT TO QUIT?", colors[RED]);
	DrawString( 270,430,"YES", colors[RED]);
	DrawString( 530,430,"NO", colors[RED]);
	speed=0;
	speed2=0;
	speed3=0;
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;

void GameDisplay()/**/{

	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score(400,400);
//static_cast<string>(score);
if(loadScore){
	loadHighScore();
}
//


//std::stringstream ss;
//std::string s = "123";
//ss << s;
//int result; 
//ss >> result;

//const string Score[] = {"333", "153", "330", "340", "AsafsdaDV"};
	//string myscore= boost::lexical_cast<string>(score); 


	//FOR converting score int to integer
	ostringstream myscore;
	myscore << score;
	string realscore=myscore.str();


	//FOR converting lives int to integer
	ostringstream mylives;
	mylives << lives;
	string reallives=mylives.str();


	//FOR converting  int to integer
	ostringstream glevel;
	glevel << level;
	string reallevel=glevel.str();

	//FOR converting  int to integer
	ostringstream gmoney;
	gmoney << money;
	string realmoney=gmoney.str();



	//string mylives= boost::lexical_cast<string>(lives); 
//mystr=string(score);

	//DrawString( 45, 840, "Score=", colors[DARK_GOLDEN_ROD]);
	DrawString(45, 840, "Score="+ (realscore), colors[DARK_GOLDEN_ROD]);
	//DrawInteger (45,800,score, colors[DARK_GOLDEN_ROD]);

	//DrawString( 50, 840, qqq, colors[DARK_GOLDEN_ROD]);
	
	DrawString( 290, 840, "Level="+ (reallevel), colors[DARK_GOLDEN_ROD]);
	DrawString( 470, 840, "Money="+ (realmoney), colors[DARK_GOLDEN_ROD]);
	DrawString( 718, 840, "Lives="+ (reallives), colors[DARK_GOLDEN_ROD]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );

	
	
	//Drawing Food For Car

	int foodx=50;
	int foody=785;
	int xx=0,yy=0;
	for (xx=0;xx<10;xx++)
	{
	for (yy=0;yy<10;yy++)
	{
	if(touch[xx][yy]==0)
	{
		if ((c1x>=foodx-40 &&c1x<=foodx+10 ) && (c1y>=foody-40 && c1y<=foody+10 ))
		{
		
		touch[xx][yy]=1;
		score=score+10;
		money+=100;
		cout<<"\a";
		counter[var]++;
		}
	}
	if (touch[xx][yy]==0)
		{
		DrawCircle(foodx,foody,8,colors[PURPLE]);
		}

	foody-=81;
	}
	foodx+=82;
	foody=785;
	yy=0;
	}
	
	










	DrawRectangle(360, 360, 110, 110,colors[BLACK]); // bottom left



	//Users CAR
	float width = 9.2; 
	float height = 7.4;
	float* color =colourofcar; 
	float radius = 2.55;
	DrawRoundRect(c1x,c1y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(c1x+width*3,c1y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(c1x+width*3,c1y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(c1x,c1y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(c1x, c1y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(c1x+width, c1y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(c1x+width*3, c1y+height*2, width, height, color, radius/2); // body right rect


	// Drawing opponent car
	float width2 = 9.2; 
	float height2 = 7.4;
	float* color2 = colors[RED]; 
	float radius2 = 2.55;
	DrawRoundRect(c2x,c2y,width2,height2,color2,radius2); // bottom left tyre
	DrawRoundRect(c2x+width2*3,c2y,width2,height2,color2,radius2); // bottom right tyre
	DrawRoundRect(c2x+width2*3,c2y+height2*4,width2,height2,color2,radius2); // top right tyre
	DrawRoundRect(c2x,c2y+height2*4,width2,height2,color2,radius2); // top left tyre
	DrawRoundRect(c2x, c2y+height2*2, width2, height2, color2, radius2/2); // body left rect
	DrawRoundRect(c2x+width2, c2y+height2, width2*2, height2*3, color2, radius2/2); // body center rect
	DrawRoundRect(c2x+width2*3, c2y+height2*2, width2, height2, color2, radius2/2); // body right rect


	if (condition1==1){

	//Drawing 2nd Opponents Car
	float width3 = 9.2; 
	float height3 = 7.4;
	float* color3 = colors[RED]; 
	float radius3 = 2.55;
	DrawRoundRect(c3x,c3y,width3,height3,color3,radius3); // bottom left tyre
	DrawRoundRect(c3x+width3*3,c3y,width3,height3,color3,radius3); // bottom right tyre
	DrawRoundRect(c3x+width3*3,c3y+height3*4,width3,height3,color3,radius3); // top right tyre
	DrawRoundRect(c3x,c3y+height3*4,width3,height3,color3,radius3); // top left tyre
	DrawRoundRect(c3x, c3y+height3*2, width3, height3, color3, radius3/2); // body left rect
	DrawRoundRect(c3x+width3, c3y+height3, width3*2, height3*3, color3, radius3/2); // body center rect
	DrawRoundRect(c3x+width3*3, c3y+height3*2, width3, height3, color3, radius3/2); // body right rect
	}




	// Drawing Arena
	int gap_turn = 90;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor =colourofarena;
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down




        int gap2_turn = 90;
	int sx2 = 100;
	int sy2 = 93;
	int swidth2 = 640/2 - gap2_turn/2; // half width
	int sheight2 = 7.5;
	float *scolor2 = colourofarena;
	DrawRectangle(sx2, sy2, swidth2, sheight2, scolor2); // bottom left
	DrawRectangle(sx2 + swidth2 + gap2_turn, sy2, swidth2, sheight2, scolor2); // bottom right
	DrawRectangle(sx2+swidth2*2+gap2_turn, sy2+sheight2, sheight2*2, swidth2, scolor2); // right down
	DrawRectangle(sx2+swidth2*2+gap2_turn, sy2+sheight2+swidth2+gap2_turn, sheight2*2, swidth2, scolor2); // right up
	DrawRectangle(sx2 + swidth2 + gap2_turn, sy2+650, swidth2, sheight2, scolor2); // top left
	DrawRectangle(sx2, sy2+650, swidth2, sheight2, scolor2); // top right
	DrawRectangle(sx2-sheight2*2, sy2+sheight2+swidth2+gap2_turn, sheight2*2, swidth2, scolor2); // left up
        DrawRectangle(sx2-sheight2*2, sy2+sheight2, sheight2*2, swidth2, scolor2); // left down




        int gap3_turn = 90;
	int sx3 = 185;
	int sy3 = 180;
	int swidth3 = 470/2 - gap3_turn/2; // half width
	int sheight3 = 5;
	float *scolor3 =colourofarena;
	DrawRectangle(sx3, sy3, swidth3, sheight3, scolor3); // bottom left
	DrawRectangle(sx3 + swidth3 + gap3_turn, sy3, swidth3, sheight3, scolor3); // bottom right
	DrawRectangle(sx3+swidth3*2+gap3_turn, sy3+sheight3, sheight3*2, swidth3, scolor3); // right down
	DrawRectangle(sx3+swidth3*2+gap3_turn, sy3+sheight3+swidth3+gap3_turn, sheight3*2, swidth3, scolor3); // right up
	DrawRectangle(sx3 + swidth3 + gap3_turn, sy3+475, swidth3, sheight3, scolor3); // top left
	DrawRectangle(sx3, sy3+475, swidth3, sheight3, scolor3); // top right
	DrawRectangle(sx3-sheight3*2, sy3+sheight3+swidth3+gap3_turn, sheight3*2, swidth3, scolor3); // left up
	DrawRectangle(sx3-sheight3*2, sy3+sheight3, sheight3*2, swidth3, scolor3); // left down



        int gap4_turn = 90;
	int sx4 = 270;
	int sy4 = 265;
	int swidth4 = 300/2 - gap4_turn/2; // half width
	int sheight4 = 4;
	float *scolor4 =colourofarena;
	DrawRectangle(sx4, sy4, swidth4, sheight4, scolor4); // bottom left
	DrawRectangle(sx4 + swidth4 + gap4_turn, sy4, swidth4, sheight4, scolor4); // bottom right
	DrawRectangle(sx4+swidth4*2+gap4_turn, sy4+sheight4, sheight4*2, swidth4, scolor4); // right down
	DrawRectangle(sx4+swidth4*2+gap4_turn, sy4+sheight4+swidth4+gap4_turn, sheight4*2, swidth4, scolor4); // right up
	DrawRectangle(sx4 + swidth4 + gap4_turn, sy4+305, swidth4, sheight4, scolor4); // top left
	DrawRectangle(sx4, sy4+305, swidth4, sheight4, scolor4); // top right
	DrawRectangle(sx4-sheight4*2, sy4+sheight4+swidth4+gap4_turn, sheight4*2, swidth4, scolor4); // left up
	DrawRectangle(sx4-sheight4*2, sy4+sheight4, sheight4*2, swidth4, scolor4); // left down


        int gap5_turn = 0;
	int sx5 = 355;
	int sy5 = 352.50;
	int swidth5 = 130/2 - gap5_turn/2; // half width
	int sheight5 = 3;
	float *scolor5 = colourofarena;
	DrawRectangle(sx5, sy5, swidth5, sheight5, scolor5); // bottom left
	DrawRectangle(sx5 + swidth5 + gap5_turn, sy5, swidth5, sheight5, scolor5); // bottom right
	DrawRectangle(sx5+swidth5*2+gap5_turn, sy5+sheight5, sheight5*2, swidth5, scolor5); // right down
	DrawRectangle(sx5+swidth5*2+gap5_turn, sy5+sheight5+swidth5+gap5_turn, sheight5*2, swidth5, scolor5); // right up
	DrawRectangle(sx5 + swidth5 + gap5_turn, sy5+135, swidth5, sheight5, scolor5); // top left
	DrawRectangle(sx5, sy5+135, swidth5, sheight5, scolor5); // top right
	DrawRectangle(sx5-sheight5*2, sy5+sheight5+swidth5+gap5_turn, sheight5*2, swidth5, scolor5); // left up
	DrawRectangle(sx5-sheight5*2, sy5+sheight5, sheight5*2, swidth5, scolor5); // left down



if (firingon==1){
		DrawCircle(firex,firey,11,colourofcar);  //FIRING
		DrawCircle(firex2,firey2,11,colourofcar);  //FIRING
}

if (state7==1)
{
level=1;
won();
speed=0;
speed2=0;
speed3=0;

}
	if (state1==1)
{
menu();
DrawString(10, 840, "Score="+ (realscore), colors[DEEP_PINK]);
DrawString( 270, 840, "Level="+ (reallevel), colors[DEEP_PINK]);
DrawString( 460, 840, "Money="+ (realmoney), colors[DEEP_PINK]);
DrawString( 760, 840, "Lives="+ (reallives), colors[DEEP_PINK]);
}

if (state8==1)//For Starter Menu
{
startermenu();
refiller();
state7=0;
}




	if (state2==1)
{

endgame();
}

if (state4==1)
{
help ();
}


if (state5==1 || state9==1)
{
exit();
}



if (state6==1)// For Display of HIGH Score
{
highscore();
}


if (state10==1)// For Display of Shop
{
shop();
DrawString( 520, 30, "Remaining Rupees="+ (realmoney), colors[BLACK]);
}

if (state11==1)// For Display of Upgrades
{
upgrades();
DrawString( 520, 30, "Remaining Rupees="+ (realmoney), colors[BLACK]);
}

if (state12==1)// For Display of Vehicles
{
vehicles();


	float width_showroom1 = 36.8; 
	float height_showroom1 = 29.6;
	float* color_showroom1 = colors[WHITE]; 
	float radius_showroom1 = 11.150;
	int car_showroomx=30;
	int car_showroomy=720;

//models 

for (int xshowroom=0;xshowroom<3;xshowroom++) {


for (int yshowroom=0;yshowroom<3;yshowroom++) {



if ((xshowroom==0) && (yshowroom==0)){
color_showroom1 = colors[WHITE]; 
}
if ((xshowroom==1) && (yshowroom==0)){
color_showroom1 = colors[MEDIUM_SPRING_GREEN]; 
}
if ((xshowroom==2) && (yshowroom==0)){
color_showroom1 = colors[FOREST_GREEN]; 
}
if ((xshowroom==0) && (yshowroom==1)){
color_showroom1 = colors[AQUA]; 
}
if ((xshowroom==1) && (yshowroom==1)){
color_showroom1 = colors[THISTLE]; 
}
if ((xshowroom==2) && (yshowroom==1)){
color_showroom1 = colors[DARK_GOLDEN_ROD]; 
}
if ((xshowroom==0) && (yshowroom==2)){
color_showroom1 = colors[LIGHT_SKY_BLUE]; 
}
if ((xshowroom==1) && (yshowroom==2)){
color_showroom1 = colors[MAROON]; 
}
if ((xshowroom==2) && (yshowroom==2)){
color_showroom1 = colors[DEEP_PINK]; 
}

	DrawRoundRect(car_showroomx,car_showroomy,width_showroom1,height_showroom1,color_showroom1,radius_showroom1); // bottom left tyre
	DrawRoundRect(car_showroomx+width_showroom1*3,car_showroomy,width_showroom1,height_showroom1,color_showroom1,radius_showroom1); // 	bottom right tyre
	DrawRoundRect(car_showroomx	+width_showroom1*3,car_showroomy											+height_showroom1*4,width_showroom1,height_showroom1,color_showroom1,radius_showroom1);
	DrawRoundRect(car_showroomx,car_showroomy+height_showroom1*4,width_showroom1,height_showroom1,color_showroom1,radius_showroom1); // 	top left tyre
	DrawRoundRect(car_showroomx, car_showroomy+height_showroom1*2, width_showroom1, height_showroom1, color_showroom1, radius_showroom1/2); // body left 	rect
	DrawRoundRect(car_showroomx+width_showroom1, car_showroomy+height_showroom1, width_showroom1*2, height_showroom1*3, color_showroom1,radius_showroom1/2); // body center rect
	DrawRoundRect(car_showroomx+width_showroom1*3, car_showroomy+height_showroom1*2, width_showroom1, height_showroom1, color_showroom1,
	radius_showroom1/2); // body right rect

car_showroomy-=284;
}
car_showroomx+=315;
car_showroomy=720;
}
DrawString(55, 690, "Angle A1", colors[BLUE]);
DrawString(50, 660, "100000 Rs/", colors[BLUE]);

DrawString(55, 410, "Angle A2", colors[BLUE]);
DrawString(50, 380, "273000 Rs/", colors[BLUE]);

DrawString(55, 130, "Angle A3", colors[BLUE]);
DrawString(50, 100, "581000 Rs/", colors[BLUE]);

DrawString(370, 690, "Angle V1", colors[BLUE]);
DrawString(365, 660, "173000 Rs/", colors[BLUE]);

DrawString(685, 410, "Angle Z2", colors[BLUE]);
DrawString(680, 380, "560000 Rs/", colors[BLUE]);

DrawString(685, 690, "Angle Z1", colors[BLUE]);
DrawString(680, 660, "340000 Rs/", colors[BLUE]);

DrawString(370, 410, "Angle V2", colors[BLUE]);
DrawString(365, 380, "450000 Rs/", colors[BLUE]);

DrawString(370, 130, "Angle V3", colors[BLUE]);
DrawString(365, 100, "610000 Rs/", colors[BLUE]);

DrawString(685, 130, "Angle Z3", colors[BLUE]);
DrawString(680, 100, "879000 Rs/", colors[BLUE]);

DrawString( 520, 30, "Remaining Rupees="+ (realmoney), colors[DARK_GOLDEN_ROD]);
}

if (state13==1)// For Display of Weapons
{
weapons();
DrawString( 520, 30, "Remaining Rupees="+ (realmoney), colors[DARK_GOLDEN_ROD]);
}
if (state14==1)// For Display of Arenas
{
arena();
DrawString( 520, 30, "Remaining Rupees="+ (realmoney), colors[DARK_GOLDEN_ROD]);
}
if (state15==1)// For Display of Buying Error
{
buyingerror();
}
if (state16==1) // For Display of Buying Congrats
{
buyingcongrats();
}




	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

//c3x-=8;


	if ((c1y<=422 && c1y>=378 && c1x<=770 && c1x>=610) || (c1y<=422 && c1y>=378 && c1x>=114 && c1x<=274)) 
{
c1x-=80;
       	}


} 
	
	else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
//c3x+=8;
if ((c1y<=422 && c1y>=378 && c1x<=690 && c1x>=530) || (c1y<=422 && c1y>=378 && c1x>=34 && c1x<=194)) 
{
	c1x+=80;
	} 
}
	else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
//c3y+=8;
	if ((c1x>=378 && c1x<=426 && c1y<=202 && c1y>=34) || (c1x>=378 && c1x<=426 && c1y<=686 && c1y>=518)) 
	{	
	
	c1y+=84;
	}

}
	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
 {
//c3y-=8;
	if ((c1x>=378 && c1x<=426 && c1y<=286 && c1y>=118) || (c1x>=378 && c1x<=426 && c1y<=770 && c1y>=602)) 
	{	
	c1y-=84;
	}

}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/




	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		 state1=1;
		pause2++;
if (pause2%2==0){
state1=0;
speed=4;
speed2=4;
speed3=4;
}
	}

	if (key == 'f' || key == 'F')
	{
if (c1x>420){
		firex=c1x;
		firey=c1y+18;
}
if (c1x<420){
		firex2=c1x;
		firey2=c1y+18;
}
	}

	if (key ==32)
			{
				//exit(1); // exit the program when escape key is pressed.

if (c1y==34 && c1x<760)
	c1x+=8;
if (c1x==770 && c1y<760)
	c1y+=8;
if (c1y==770 && c1x>44)
	c1x-=8;
if (c1x==34 && c1y>44)
	c1y-=8;



if (c1y==118 && c1x<680 && c1x>=114)
	c1x+=8;
if (c1x==690 && c1y<676 && c1y>=118)
	c1y+=8;
if (c1y==686 && c1x>124 && c1x<=690)
	c1x-=8;
if (c1x==114 && c1y>128 && c1y<=686)
	c1y-=8;


if (c1y==202 && c1x<600 && c1x>=194)
	c1x+=8;
if (c1x==610 && c1y<592 && c1y>=202)
	c1y+=8;
if (c1y==602 && c1x>204 && c1x<=610)
	c1x-=8;
if (c1x==194 && c1y>212 && c1y<=602)
	c1y-=8;


if (c1y==286 && c1x<520 && c1x>=274)
	c1x+=8;
if (c1x==530 && c1y<508 && c1y>=286)
	c1y+=8;
if (c1y==518 && c1x>284 && c1x<=530)
	c1x-=8;
if (c1x==274 && c1y>296 && c1y<=518)
	c1y-=8;


	}

	if (key == 'p' || key == 'P')
			{
		speed=0;
		speed2=0;
		speed3=0;
     		pause2++;

		//state1=1;
		if (pause2%2==0)
       		{
 		speed=4;
		speed2=4;
		speed3=4;
		//state1=0;
                }

	}
	
		
               

	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	//if (c1x>420){
	firex-=20;
	//}

	//if (c1x<420){
	firex2+=20;
	//}

	//cout<<"CAR1x  "<<c1x<<endl;
        //cout<<"CAR1y  "<<c1y<<endl;
        //cout<<"Lives are "<<lives<<endl;
	//cout<<"CAR1x  "<<c1x<<endl;	
	//cout<<"CAR3x  "<<c3x<<endl;
	//cout<<"CAR3y  "<<c3y<<endl; 
	//cout<<"This is Testing  "<<ngame<<endl;
	


if (c1y==34 && c1x<770)
	c1x+=speed;
if (c1x==770 && c1y<770)
	c1y+=speed;
if (c1y==770 && c1x>34)
	c1x-=speed;
if (c1x==34 && c1y>34)
	c1y-=speed;



if (c1y==118 && c1x<690 && c1x>=114)
	c1x+=speed;
if (c1x==690 && c1y<686 && c1y>=118)
	c1y+=speed;
if (c1y==686 && c1x>114 && c1x<=690)
	c1x-=speed;
if (c1x==114 && c1y>118 && c1y<=686)
	c1y-=speed;


if (c1y==202 && c1x<610 && c1x>=194)
	c1x+=speed;
if (c1x==610 && c1y<602 && c1y>=202)
	c1y+=speed;
if (c1y==602 && c1x>194 && c1x<=610)
	c1x-=speed;
if (c1x==194 && c1y>202 && c1y<=602)
	c1y-=speed;


if (c1y==286 && c1x<530 && c1x>=274)
	c1x+=speed;
if (c1x==530 && c1y<518 && c1y>=286)
	c1y+=speed;
if (c1y==518 && c1x>274 && c1x<=530)
	c1x-=speed;
if (c1x==274 && c1y>286 && c1y<=518)
	c1y-=speed;



if (level==1)	{
 //first boundry line 1 of opponent car
      if ((c2x>=17 && c2x<=781 ) && (c2y>=22 && c2y<=54))
         {
         c2x-=speed2;
         }
	 //first boundry line 2 of opponent car
         if ((c2x>=753 && c2x<=782) && (c2y>=22 && c2y<=782))
         {
         c2y-=speed2;
         }
   //first boundry line 3 of opponent car
         if ((c2x<=782 && c2x>=17) && (c2y>=750 && c2y<=782))
         {
         c2x+=speed2; 
         }
 //first boundry line 4 of opponent car
         if ((c2x>=17 && c2x<=49) && (c2y<=782 && c2y>=22))
         {
         c2y+=speed2;
	 }
condition1=0;
}
	


     



















	


		if (counter[var]>=96 && level==1)   //For Level 2
{
var++;
level++;
money+=100000;
c1x=426; 
c1y=34;
c2x=370; 
c2y=34;
refiller();
//c1x+=4;
}



		if (counter[var]>=96 && level==2) //For Level 3
{
var++;
level++;
money+=200000;
c1x=426; 
c1y=34;
c2x=370; 
c2y=34;
refiller();
//c1x+=4;
}


	/*	if (counter[var]>=96 && level==3)  //For Level 4
{
var++;
level++;
c1x=426; 
c1y=34;
c2x=370; 
c2y=34;

//c1x+=4;
}
*/


		if (counter[var]>=96 && level==3)  //For Level Complete
{
var++;
level++;
money+=300000;
c1x=426; 
c1y=34;
c2x=370; 
c2y=34;
c3x = 418;
c3y = 760;
refiller();
//c1x+=4;
}




		if (counter[var]>=96 && level==4)  //For Display of "You Won"
{
state7=1;
for (int aab=0;aab<1;aab++){
money+=400000;
}
}












if (level==2 || level==3 || level==4)
{



      if ((c2x>=17 && c2x<=781 ) && (c2y>=22 && c2y<=54))
         {
         c2x-=speed2;
         }


        if ((c2x>=17 && c2x<=49) && (c2y<=414 && c2y>=22))
         {
         c2y+=speed2;
	 }




 if ((c2x>=22 && c2x<=202 ) && (c2y>=374 && c2y<=426))
{
c2x+=speed2;
}
      if ((c2x>=194 && c2x<=210 ) && (c2y>=202 && c2y<=590))
{
c2y+=speed2;
}
if ((c2x>=198 && c2x<=594 ) && (c2y>=574 && c2y<=618))
{
c2x+=speed2;
}
if ((c2x>=582 && c2x<=610 ) && (c2y>=210 && c2y<=594))
{
c2y-=speed2;
}
if ((c2x>=374 && c2x<=618 ) && (c2y>=186 && c2y<=226))
{
c2x-=speed2;
}
if ((c2x>=378 && c2x<=426 ) && (c2y>=34 && c2y<=226))
{
c2y-=speed2;
}	
	
}


if (level==3 || level==4)
{
speed2=8;
}
if (level==4)
{
condition1=1;

if ((state1==0) && (state4==0) && (state5==0) && (state6==0) && (state7==0) && (state8==0))
{
         if ((c3x<=764 && c3x>=17) && (c3y>=750 && c3y<=782))
         {
         c3x+=speed3; 
         }
         if ((c3x>=753 && c3x<=774) && (c3y>=30 && c3y<=782))
         {
         c3y-=speed3;
         }
      if ((c3x>=414 && c3x<=774 ) && (c3y>=22 && c3y<=54))
         {
         c3x-=speed3;
         }

      if ((c3x>=374 && c3x<=430 ) && (c3y>=24 && c3y<=288))
         {
         c3y+=speed3;
         }
      if ((c3x>=290 && c3x<=426 ) && (c3y>=272 && c3y<=304))
         {
         c3x-=speed3;
         }
      if ((c3x>=274 && c3x<=314 ) && (c3y>=272 && c3y<=400))
         {
         c3y+=speed3;
         }
      if ((c3x>=126 && c3x<=314 ) && (c3y>=376 && c3y<=424))
         {
         c3x-=speed3;
         }
      if ((c3x>=106 && c3x<=138 ) && (c3y>=376 && c3y<=672))
         {
         c3y+=speed3;
         }
      if ((c3x>=106 && c3x<=394 ) && (c3y>=664 && c3y<=704))
         {
         c3x+=speed3;
         }
      if ((c3x>=378 && c3x<=426 ) && (c3y>=664 && c3y<=768))
         {
         c3y+=speed3;
         }
}

}







	// FOR Firing collision 
	if ((c2x>=firex-40 && c2x<=firex+10 ) && (c2y>=firey-40 && c2y<=firey+10 ))
{
c2x=1000;
c2y=1000;
}


	if ((c2x>=firex2-40 && c2x<=firex2+10 ) && (c2y>=firey2-40 && c2y<=firey2+10 ))
{
c2x=-1000;
c2y=-1000;
}


	if ((c3x>=firex-40 && c3x<=firex+10 ) && (c3y>=firey-40 && c3y<=firey+10 ))
{
c3x=1000;
c3y=1000;
}


	if ((c3x>=firex2-40 && c3x<=firex2+10 ) && (c3y>=firey2-40 && c3y<=firey2+10 ))
{
c3x=-1000;
c3y=-1000;
}



cout<<"This is counter "<<counter[var]<<endl;
cout<<"This is Money "<<money<<endl;
//cout<<"Variable "<<var<<endl;
//cout<<"newgame "<<newgameloading1<<endl;
	//Collision of TWO Cars
	
	if ((c1x+36>=c2x && c1x<=c2x+36) && (c1y+36>=c2y && c1y<=c2y+36)) 
	{

	c1x=426; c1y=34;
	c2x=370; c2y=34;
	c3x=418;
	c3y=760;
	lives--;
	money-=50000;
	counter[var]=0;

//For Refilling
refiller();



		if (lives==-1) {
		state2=1; 	
		counter[var]=0;
		}

	}






if (((level==4)) && ((c1x+36>=c3x && c1x<=c3x+36) && (c1y+36>=c3y && c1y<=c3y+36))){
	c1x=426; c1y=34;
	c2x=370; c2y=34;
	c3x=418;
	c3y=760;
	lives--;
	counter[var]=0;
//For Refilling
refiller();
		if (lives==-1) {
		state2=1; 	
		counter[var]=0;
		}
}










	
	
	
         
        glutPostRedisplay();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0/80, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int mousex1, int mousey1) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int mousex2, int mousey2) {



//if ((mousex2>=353 && mousex2<=407) && (mousey2>=333 && mousey2<=351))
//{
//cout<<"GOOD"<<endl;
//exit(1);
//state3=1;
//}

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int mousex3, int mousey3) {

	cout<<"Mouse X3 position this "<<mousex3<<endl;
	cout<<"Mouse Y3 position this "<<mousey3<<endl;

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
	
if ((mousex3>=299 && mousex3<=479) && (mousey3>=279 && mousey3<=299) && (state1%2!=0)) //For Resume Game
{
	state1=0;
	speed=4;
	speed2=4;
	speed3=4;
}

if ((mousex3>=346 && mousex3<=410) && (mousey3>=378 && mousey3<=395) && (state1%2!=0 || state8==1)) //to go into help
{
state4=1;
}

if ((mousex3>=365 && mousex3<=434) && (mousey3>=597 && mousey3<=619) && (state4==1) && (state12==0) && (state13==0) && (state14==0))  //to back from help to menu
{
	state4=0;
}

if ((mousex3>=348 && mousex3<=412) && (mousey3>=426 && mousey3<=446) && (state1%2!=0 || state8==1) && (state12==0) && (state10==0)) //For Exit to ask user that he selects YES or NO
{
	state5=1;
}


if ((mousex3>=267 && mousex3<=314) && (mousey3>=345 && mousey3<=370) && (state5==1)) //For Exit on YES CLICK
{
exit(1);
}




if ((mousex3>=529 && mousex3<=565) && (mousey3>=346 && mousey3<=363) && (state5==1) && (state12==0) && (state13==0) && (state14==0)) //For BACK on MENU from exit
{
state5=0;
}


if ((mousex3>=315 && mousex3<=466) && (mousey3>=329 && mousey3<=349) && (state1%2!=0 || state8==1)) //For Display of High score
{
state6=1;

}


if ((mousex3>=364 && mousex3<=434) && (mousey3>=598 && mousey3<=620) && (state6==1) && (state12==0) && (state13==0) && (state14==0)) //For BACK on MENU from HIGH Score
{
state6=0;

}


if ((mousex3>=365 && mousex3<=434) && (mousey3>=597 && mousey3<=619) && (state2==1) && (state12==0) && (state13==0) && (state14==0))  //to back from Gameover to startermenu
{
state8=1;
state2=0;
score=0;
lives=3;
level=1;
var++;
c1x = 406; 
c1y = 34; 
c2x = 358; 
c2y = 34;
speed=4;
speed2=4;
speed3=4;
state1=0;
c3x = 418;
c3y = 760;
condition1=0;
}


if ((mousex3>=269 && mousex3<=511) && (mousey3>=232 && mousey3<=250) && (state1==1))  //For Starting new game
{
refiller();
score=0;
lives=3;
level=1;
var++;
c1x = 406; 
c1y = 34; 
c2x = 358; 
c2y = 34;
newgameloading1++;
speed=4;
speed2=4;
speed3=4;
state1=0;
c3x = 418;
c3y = 760;
condition1=0;
ngame++;
}

if ((mousex3>=365 && mousex3<=434) && (mousey3>=597 && mousey3<=619) && (state7==1) && (state12==0) && (state13==0) && (state14==0))  //to back from Won to Starter Menu
{
	state7=0;
	state8=1;
}

if ((mousex3>=271 && mousex3<=513) && (mousey3>=281 && mousey3<=301) && (state8==1))  //Form Starter Menu to game
{
	state8=0;
	speed=4;
	speed2=4;
	speed3=4;
	state7=0;
        score=0;
	lives=3;
	level=1;
	newgameloading1++;
	var++;
	ngame++;
	c3x = 418;
	c3y = 760;
	c1x = 406; 
	c1y = 34; 
	c2x = 358; 
	c2y = 34;
	condition1=0;

}


if ((mousex3>=346 && mousex3<=413) && (mousey3>=428 && mousey3<=449) && (state1%2!=0 || state8==1) && (state12==0) && (state10==0))  //Form Starter Menu to exit 
{
state5=1;
}

if ((mousex3>=320 && mousex3<=505) && (mousey3>=599 && mousey3<=615) && (state7==1)) //From Won to Menu
{
	state7=0;
	state8=1;
	score=0;
	lives=3;
	level=1;
	var++;
	c1x = 406; 
	c1y = 34; 
	c2x = 358; 
	c2y = 34;
	speed=0;
	speed2=0;
	speed3=0;
	c3x = 418;
	c3y = 760;
	condition1=0;


}

if ((mousex3>=756 && mousex3<=828) && (mousey3>=663 && mousey3<=685) && (state1%2!=0 || state8==1)) //For Shop
{
state10=1;

}

if ((mousex3>=364 && mousex3<=434) && (mousey3>=598 && mousey3<=620) && (state10==1) && (state12==0) && (state13==0) && (state14==0)) //For BACK on MENU from Shop
{
state10=0;

}

if ((mousex3>=10 && mousex3<=145) && (mousey3>=664 && mousey3<=682) && (state1%2!=0 || state8==1)) //For Upgrades
{
state11=1;

}
if ((mousex3>=364 && mousex3<=434) && (mousey3>=598 && mousey3<=620) && (state11==1) && (state12==0) && (state13==0) && (state14==0)) //For BACK on MENU from Upgrades
{
state11=0;

}

if ((mousex3>=157 && mousex3<=280) && (mousey3>=328 && mousey3<=349) && (state10==1)) //For Vehicles
{
state12=1;

}
if ((mousex3>=364 && mousex3<=434) && (mousey3>=672 && mousey3<=691) && (state12==1) && (state13==0) && (state14==0)) //For BACK on SHOP from Vehicles
{
state12=0;
}
if ((mousex3>=567 && mousex3<=693) && (mousey3>=331 && mousey3<=347) && (state10==1)) //For Weapons
{
state13=1;
state10=1;
}
if ((mousex3>=364 && mousex3<=434) && (mousey3>=672 && mousey3<=691) && (state13==1) && (state12==0) && (state14==0)) //For BACK on SHOP from Weapons
{
state13=0;
state10=1;
}
if ((mousex3>=363 && mousex3<=457) && (mousey3>=331 && mousey3<=347) && (state10==1)) //For Arena
{

state14=1;
state10=1;
}
if ((mousex3>=364 && mousex3<=434) && (mousey3>=672 && mousey3<=691) && (state14==1) && (state12==0) && (state13==0)) //For BACK on SHOP from Arena
{
state14=0;
state10=1;
}
if ((mousex3>=27 && mousex3<=180) && (mousey3>=8 && mousey3<=176) && (state12==1)) //For Colour of Car
{
if (money>=100000){
colourofcar=colors[WHITE];
money=money-100000;
state16=1;
}
else 
{
state15=1;
}
}
if ((mousex3>=342 && mousex3<=496) && (mousey3>=8 && mousey3<=177) && (state12==1)) //For Colour of Car
{
if (money>=173000){
colourofcar=colors[MEDIUM_SPRING_GREEN];
money=money-173000;
state16=1;
}
else 
{
state15=1;
}
}
if ((mousex3>=658 && mousex3<=813) && (mousey3>=8 && mousey3<=177) && (state12==1)) //For Colour of Car
{
if (money>=340000){
colourofcar=colors[FOREST_GREEN];
money=money-340000;
state16=1;
}
else 
{
state15=1;
}
}
if ((mousex3>=27 && mousex3<=180) && (mousey3>=237 && mousey3<=406) && (state12==1)) //For Colour of Car
{
if (money>=273000){
colourofcar=colors[AQUA];
money=money-273000;
state16=1;
}
else 
{
state15=1;
}
}
if ((mousex3>=342 && mousex3<=496) && (mousey3>=237 && mousey3<=406) && (state12==1)) //For Colour of Car
{
if (money>=450000){
colourofcar=colors[THISTLE];
money=money-450000;
state16=1;
}
else 
{
state15=1;
}
}
if ((mousex3>=658 && mousex3<=813) && (mousey3>=237 && mousey3<=406) && (state12==1)) //For Colour of Car
{
if (money>=560000){
colourofcar=colors[DARK_GOLDEN_ROD];
money=money-560000;
state16=1;
}
else 
{
state15=1;
}
}
if ((mousex3>=27 && mousex3<=180) && (mousey3>=465 && mousey3<=634) && (state12==1)) //For Colour of Car
{
if (money>=581000){
colourofcar=colors[LIGHT_SKY_BLUE];
money=money-581000;
state16=1;
}
else 
{
state15=1;
}
}
if ((mousex3>=342 && mousex3<=496) && (mousey3>=465 && mousey3<=634) && (state12==1)) //For Colour of Car
{
if (money>=610000){
colourofcar=colors[MAROON];
money=money-610000;
state16=1;
}
else 
{
state15=1;
}
}
if ((mousex3>=658 && mousex3<=813) && (mousey3>=465 && mousey3<=634) && (state12==1)) //For Colour of Car
{
if (money>=879000){
colourofcar=colors[DEEP_PINK];
money=money-879000;
state16=1;
}
else 
{
state15=1;
}
}

if ((mousex3>=28 && mousex3<=143) && (mousey3>=156 && mousey3<=203) && (state13==1)) //For Buying Colt M4 Gun
{
if (money>=5000){
firingon=1;
money=money-5000;
state16=1;
}
else 
{
state15=1;
}
}


if ((mousex3>=28 && mousex3<=214) && (mousey3>=156 && mousey3<=207) && (state14==1)) //For Buying Golden Arena
{
if (money>=20000){
colourofarena=colors[DARK_GOLDEN_ROD];
money=money-20000;
state16=1;
}
else 
{
state15=1;
}
}

if ((mousex3>=366 && mousex3<=434) && (mousey3>=366 && mousey3<=382) && ((state12==1) || (state13==1) || (state14==1)) && (state15==1)) //For BACK on Vehicle from Error of Buying
{
state15=0;
}
if ((mousex3>=364 && mousex3<=433) && (mousey3>=366 && mousey3<=383) && ((state12==1) || (state13==1) || (state14==1)) && (state16==1)) //For BACK on Vehicle from Congrats of Buying
{
state16=0;
}




		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 880; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("ASPHALT"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0/80, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
