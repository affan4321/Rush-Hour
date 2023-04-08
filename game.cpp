//============================================================================
// Name        : 21i-0474_MuhammadAffan.cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

//Global board
string boardGame[20][20];


// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


int xI = 80, yI = -40, a = 0, b = 20;
int ct = 0;
int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
int score = 0;
bool ready1 = false;
bool ready2 = false;
bool ready3 = false;
bool ready4 = false;
bool picked1 = false;
bool picked2 = false;
bool picked3 = false;
bool picked4 = false;
char taxiColor = ' ';
bool mouse_clicked = false;
int carColor = GetRandInRange(1, 6);  //choose cars colors from 6 colors 
int YRrandom = GetRandInRange(1, 2);  //choose yellow or red when Random button is clicked
int personNum = GetRandInRange(3, 5); //decides if 3 or 4 or 5 persons will be shown on grid
int person1LocationX = GetRandInRange(2, 21);  //picks a number from 20x20 grid in X direction
int person1LocationY = GetRandInRange(0, 19);  //picks a number from 20x20 grid in Y direction
int person2LocationX = GetRandInRange(2, 21);  //picks a number from 20x20 grid in X direction
int person2LocationY = GetRandInRange(0, 19);  //picks a number from 20x20 grid in Y direction
int person3LocationX = GetRandInRange(2, 21);  //picks a number from 20x20 grid in X direction
int person3LocationY = GetRandInRange(0, 19);  //picks a number from 20x20 grid in Y direction
int person4LocationX = GetRandInRange(2, 21);  //picks a number from 20x20 grid in X direction
int person4LocationY = GetRandInRange(0, 19);  //picks a number from 20x20 grid in Y direction
int p1DestinationX = GetRandInRange(2, 21);
int p1DestinationY = GetRandInRange(0, 19);
int p2DestinationX = GetRandInRange(2, 21);
int p2DestinationY = GetRandInRange(0, 19);
int p3DestinationX = GetRandInRange(2, 21);
int p3DestinationY = GetRandInRange(0, 19);
int p4DestinationX = GetRandInRange(2, 21);
int p4DestinationY = GetRandInRange(0, 19);
bool arrived1 = false;
bool arrived2 = false;
bool arrived3 = false;
bool arrived4 = false;
bool final1 = false;
bool final2 = false;
bool final3 = false;
bool final4 = false;

void menu();
void leaderboard();
void game();
void crazyTaxi(float x, float y, char colorTaxi);
void DrawStickman(float x, float y, int id);
void DrawStickman1(float x, float y, int id);
void DrawCars(float x, float y);
void name();
void Obstacles();
void moveCar(int min, int max);
void moveCarUp();

void menu() {
	DrawRoundRect(0, 0, 1000, 900, colors[TURQUOISE]);
	DrawRoundRect(600, 600, 800, 800, colors[INDIGO]);
	DrawRoundRect(200, 200, 400, 400, colors[INDIAN_RED]);
	DrawTriangle(600, 0, 1000, 0, 1000, 500, colors[DARK_ORCHID]);
	DrawCircle(20, 50, 200, colors[NAVY]);
	DrawRoundRect(150, 300, 300, 150, colors[ORANGE]);
	DrawRoundRect(550, 300, 300, 150, colors[RED]);
	DrawRoundRect(350, 130, 300, 150, colors[ORANGE_RED]);
	DrawString(200, 800, "Welcome in Rush Hour By Muhammad Affan (21i-0474)", colors[WHITE]);
	DrawString(170, 650, "You can pick your taxi color. Pick according to your desired choice.", colors[VIOLET]);
	DrawString(235, 370, "Yellow TAXI", colors[BLACK]);
	DrawString(655, 370, "Red TAXI", colors[BLACK]);
	DrawString(455, 200, "Random", colors[BLACK]);
	if (mouse_clicked == true)   //Calling name when left mouse clicked on boxes.
	{
		glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors
		name();
	}
	glutPostRedisplay();
}
void leaderboard()
{
	bool a = true;
	while (a == true)
	{
		cout << "c" << endl;
		a = false;
	}

}
void name()
{
	//char nme[20];
	DrawRoundRect(0, 0, 1000, 900, colors[TURQUOISE]);
	DrawRoundRect(600, 600, 800, 800, colors[INDIGO]);
	DrawRoundRect(200, 200, 400, 400, colors[INDIAN_RED]);
	DrawTriangle(600, 0, 1000, 0, 1000, 500, colors[DARK_ORCHID]);
	DrawCircle(20, 50, 200, colors[NAVY]);
	DrawRectangle(550, 300, 300, 150, colors[RED]);
	/*DrawString(655, 370, "Enter Your Name", colors[BLACK]);
	cin.getline(nme, 20);
	string name = nme;
	cout << "Welcome " << name <<"!" << endl;
	DrawString(655, 330, name , colors[BLACK]);*/
	if (taxiColor == 'y' or taxiColor == 'r' or taxiColor == 'u') //calling game function when color found
	{
		glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors
		game();
	}

	glutPostRedisplay();



}

void game()
{
	
	ofstream myFile("highscores.txt");
	//Display Score
	DrawString(880, 770, "Score=" + to_string(score), colors[BLACK]);

	//Background Grid
	DrawLine(120, 0, 120, 800, 1, colors[BLACK]);
	DrawLine(160, 0, 160, 800, 1, colors[BLACK]);
	DrawLine(200, 0, 200, 800, 1, colors[BLACK]);
	DrawLine(240, 0, 240, 800, 1, colors[BLACK]);
	DrawLine(280, 0, 280, 800, 1, colors[BLACK]);
	DrawLine(320, 0, 320, 800, 1, colors[BLACK]);
	DrawLine(360, 0, 360, 800, 1, colors[BLACK]);
	DrawLine(400, 0, 400, 800, 1, colors[BLACK]);
	DrawLine(440, 0, 440, 800, 1, colors[BLACK]);
	DrawLine(480, 0, 480, 800, 1, colors[BLACK]);
	DrawLine(520, 0, 520, 800, 1, colors[BLACK]);
	DrawLine(560, 0, 560, 800, 1, colors[BLACK]);
	DrawLine(600, 0, 600, 800, 1, colors[BLACK]);
	DrawLine(640, 0, 640, 800, 1, colors[BLACK]);
	DrawLine(680, 0, 680, 800, 1, colors[BLACK]);
	DrawLine(720, 0, 720, 800, 1, colors[BLACK]);
	DrawLine(760, 0, 760, 800, 1, colors[BLACK]);
	DrawLine(800, 0, 800, 800, 1, colors[BLACK]);
	DrawLine(840, 0, 840, 800, 1, colors[BLACK]);

	DrawLine(80, 760, 880, 760, 1, colors[BLACK]);
	DrawLine(80, 720, 880, 720, 1, colors[BLACK]);
	DrawLine(80, 680, 880, 680, 1, colors[BLACK]);
	DrawLine(80, 640, 880, 640, 1, colors[BLACK]);
	DrawLine(80, 600, 880, 600, 1, colors[BLACK]);
	DrawLine(80, 560, 880, 560, 1, colors[BLACK]);
	DrawLine(80, 520, 880, 520, 1, colors[BLACK]);
	DrawLine(80, 480, 880, 480, 1, colors[BLACK]);
	DrawLine(80, 440, 880, 440, 1, colors[BLACK]);
	DrawLine(80, 400, 880, 400, 1, colors[BLACK]);
	DrawLine(80, 360, 880, 360, 1, colors[BLACK]);
	DrawLine(80, 320, 880, 320, 1, colors[BLACK]);
	DrawLine(80, 280, 880, 280, 1, colors[BLACK]);
	DrawLine(80, 240, 880, 240, 1, colors[BLACK]);
	DrawLine(80, 200, 880, 200, 1, colors[BLACK]);
	DrawLine(80, 160, 880, 160, 1, colors[BLACK]);
	DrawLine(80, 120, 880, 120, 1, colors[BLACK]);
	DrawLine(80, 80, 880, 80, 1, colors[BLACK]);
	DrawLine(80, 40, 880, 40, 1, colors[BLACK]);

	//Boundry
	DrawLine(80, 0, 880, 0, 1, colors[BLACK]); //bottom
	DrawLine(80, 0, 80, 800, 1, colors[BLACK]);  //left
	DrawLine(880, 0, 880, 800, 1, colors[BLACK]);  //right
	DrawLine(80, 800, 880, 800, 1, colors[BLACK]);  //top


	//Building 1

	for (int t = 160; t <= 240; t += 40)
	{
		DrawSquare(t, 680, 40, colors[FIREBRICK]);
		::boardGame[(t / 40) - 1][17] = "building";
	}

	//Building 2

	for (int t = 440; t <= 840; t += 40)
	{
		DrawSquare(t, 680, 40, colors[GOLD]);
		::boardGame[(t / 40) - 1][17] = "building";
	}

	//Building 3

	for (int t = 280; t <= 360; t += 40)
	{
		DrawSquare(t, 520, 40, colors[DARK_TURQUOISE]);
		::boardGame[(t / 40) - 1][13] = "building";
	}
	for (int t = 560; t <= 640; t += 40)
	{
		DrawSquare(360, t, 40, colors[DARK_TURQUOISE]);
		::boardGame[8][t / 40] = "building";
	}

	//Building 4

	for (int t = 440; t <= 520; t += 40)
	{
		DrawSquare(200, t, 40, colors[FIREBRICK]);
		::boardGame[4][t / 40] = "building";
	}
	DrawSquare(160, 520, 40, colors[FIREBRICK]);
	::boardGame[3][13] = "building";

	//Building 5

	for (int t = 600; t <= 680; t += 40)
	{
		DrawSquare(t, 520, 40, colors[GOLD]);
		::boardGame[(t / 40) - 1][13] = "building";
	}
	for (int t = 400; t <= 600; t += 40)
	{
		DrawSquare(560, t, 40, colors[GOLD]);
		::boardGame[13][t / 40] = "building";
	}

	//Building 6

	for (int t = 360; t <= 440; t += 40)
	{
		DrawSquare(t, 360, 40, colors[DARK_TURQUOISE]);
		::boardGame[(t / 40) - 1][9] = "building";
	}
	DrawSquare(440, 400, 40, colors[DARK_TURQUOISE]);
	::boardGame[10][10] = "building";

	//lonely square

	DrawSquare(440, 480, 40, colors[GOLD]);
	::boardGame[10][12] = "building";

	//Building 7

	for (int t = 360; t <= 520; t += 40)
	{
		DrawSquare(t, 200, 40, colors[FIREBRICK]);
		::boardGame[(t / 40) - 1][5] = "building";
	}
	DrawSquare(520, 240, 40, colors[FIREBRICK]);
	::boardGame[12][6] = "building";
	DrawSquare(520, 280, 40, colors[FIREBRICK]);
	::boardGame[12][7] = "building";

	//Building 8

	for (int t = 440; t <= 600; t += 40)
	{
		DrawSquare(800, t, 40, colors[DARK_TURQUOISE]);
		::boardGame[19][t / 40] = "building";
	}

	//Building 9

	for (int t = 80; t <= 320; t += 40)
	{
		DrawSquare(280, t, 40, colors[GOLD]);
		::boardGame[6][t / 40] = "building";
	}

	//Building 10

	for (int t = 160; t <= 240; t += 40)
	{
		DrawSquare(160, t, 40, colors[DARK_TURQUOISE]);
		::boardGame[3][t / 40] = "building";
	}
	for (int t = 160; t <= 240; t += 40)
	{
		DrawSquare(200, t, 40, colors[DARK_TURQUOISE]);
		::boardGame[4][t / 40] = "building";
	}

	//Building 11

	for (int t = 640; t <= 840; t += 40)
	{
		DrawSquare(t, 280, 40, colors[FIREBRICK]);
		::boardGame[(t / 40) - 1][7] = "building";
	}
	for (int t = 120; t <= 200; t += 40)
	{
		DrawSquare(640, t, 40, colors[FIREBRICK]);
		::boardGame[15][t / 40] = "building";
	}

	//Building 12

	for (int t = 0; t <= 80; t += 40)
	{
		DrawSquare(440, t, 40, colors[DARK_TURQUOISE]);
		::boardGame[10][t / 40] = "building";
	}

	//Building 13

	DrawSquare(760, 40, 40, colors[FIREBRICK]);
	::boardGame[18][1] = "building";
	DrawSquare(800, 40, 40, colors[FIREBRICK]);
	::boardGame[19][1] = "building";

	//Our Crazy Taxi
	crazyTaxi(xI, yI, taxiColor);


	while (ct != 1)  //randomizing the coordinates for persons since it's always in same position
	{
		person1LocationX = GetRandInRange(2, 21);
		person1LocationY = GetRandInRange(0, 19);
		person2LocationX = GetRandInRange(2, 21);
		person2LocationY = GetRandInRange(0, 19);
		person3LocationX = GetRandInRange(2, 21);
		person3LocationY = GetRandInRange(0, 19);
		person4LocationX = GetRandInRange(2, 21);
		person4LocationY = GetRandInRange(0, 19);
		p1DestinationX = GetRandInRange(2, 21);
		p1DestinationY = GetRandInRange(0, 19);
		p2DestinationX = GetRandInRange(2, 21);
		p2DestinationY = GetRandInRange(0, 19);
		p3DestinationX = GetRandInRange(2, 21);
		p3DestinationY = GetRandInRange(0, 19);
		p4DestinationX = GetRandInRange(2, 21);
		p4DestinationY = GetRandInRange(0, 19);
		carColor = GetRandInRange(1, 6);  //choose cars colors from 6 colors
		ct = 1;
	}

	//person1

	if (::boardGame[person1LocationX][person1LocationY] == "building")
	{
		cout << "::boardGame[" << person1LocationX << "][" << person1LocationY << "] == building" << endl;
		cout << "Building Occured" << endl;
	}
	while (::boardGame[person1LocationX][person1LocationY] == "building" or ::boardGame[person1LocationX][person1LocationY] == "obs")  //checking if buildings are there or not
	{
		person1LocationX = GetRandInRange(2, 21);
		person1LocationY = GetRandInRange(0, 19);
		cout << "Coordinates changed" << endl;
		cout << "New coordinated are: " << person1LocationX << " , " << person1LocationY << endl;
		if (::boardGame[person1LocationX][person1LocationY] == "building")
		{
			cout << "::boardGame[" << person1LocationX << "][" << person1LocationY << "] == building" << endl;
			cout << "Building Occured" << endl;
		}
	}
	::boardGame[person1LocationX][person1LocationY] = "person1";
	if (picked1 == true)   // After picking the person, it's place becomes empty so that taxi can move in that box as well
	{
		::boardGame[person1LocationX][person1LocationY] = " ";
	}
	DrawStickman((person1LocationX * 40), (person1LocationY * 40), 1);  //multiplying with 40 since each boz on grid is 40px

	//Person 1 Destination
	while ((p1DestinationX == person1LocationX and p1DestinationY == person1LocationY) or ::boardGame[p1DestinationX][p1DestinationY] == "building" or ::boardGame[p1DestinationX][p1DestinationY] == "obs")  //person's destination same as initial position or building is there
	{
		p1DestinationX = GetRandInRange(2, 21);
		p1DestinationY = GetRandInRange(0, 19);
	}
	if (picked1 == true)
	{
		if (final1 != true) // draw green box until arrived
			DrawSquare((p1DestinationX + 1) * 40, p1DestinationY * 40, 40, colors[GREEN]);
		::boardGame[p1DestinationX][p1DestinationY] = "d1";  //Assigning destination on board
	}


	//person2
	if (::boardGame[person2LocationX][person2LocationY] == "building")
	{
		cout << "::boardGame[" << person2LocationX << "][" << person2LocationY << "] == building" << endl;
		cout << "Building Occured" << endl;
	}
	while (::boardGame[person2LocationX][person2LocationY] == "building" or ::boardGame[person2LocationX][person2LocationY] == "obs")  //checking if buildings are there or not, person 2's location should be different from person1
	{
		person2LocationX = GetRandInRange(2, 21);
		person2LocationY = GetRandInRange(0, 19);
		cout << "Coordinates changed" << endl;
		cout << "New coordinated are: " << person2LocationX << " , " << person2LocationY << endl;
		if (::boardGame[person2LocationX][person2LocationY] == "building")
		{
			cout << "::boardGame[" << person2LocationX << "][" << person2LocationY << "] == building" << endl;
			cout << "Building Occured" << endl;
		}
	}
	::boardGame[person2LocationX][person2LocationY] = "person2";
	if (picked2 == true)   // After picking the person, it's place becomes empty so that taxi can move in that box as well
	{
		::boardGame[person2LocationX][person2LocationY] = " ";
	}
	DrawStickman((person2LocationX * 40), (person2LocationY * 40), 2);  //multiplying with 40 since each boz on grid is 40px

	//Person 2 Destination
	while ((p2DestinationX == person2LocationX and p2DestinationY == person2LocationY) or ::boardGame[p2DestinationX][p2DestinationY] == "building" or ::boardGame[p2DestinationX][p2DestinationY] == "obs")  //person's destination same as initial position or building is there
	{
		p2DestinationX = GetRandInRange(2, 21);
		p2DestinationY = GetRandInRange(0, 19);
	}
	if (picked2 == true)
	{
		if (final2 != true)  // draw green box until arrived
			DrawSquare((p2DestinationX + 1) * 40, p2DestinationY * 40, 40, colors[GREEN]);
		::boardGame[p2DestinationX][p2DestinationY] = "d2";  //Assigning destination on board
	}


	//person3
	if (::boardGame[person3LocationX][person3LocationY] == "building" or ::boardGame[person3LocationX][person3LocationY] == "obs")
	{
		cout << "::boardGame[" << person3LocationX << "][" << person3LocationY << "] == building" << endl;
		cout << "Building Occured" << endl;
	}
	while (::boardGame[person3LocationX][person3LocationY] == "building")  //checking if buildings are there or not
	{
		person3LocationX = GetRandInRange(2, 21);
		person3LocationY = GetRandInRange(0, 19);
		cout << "Coordinates changed" << endl;
		cout << "New coordinated are: " << person3LocationX << " , " << person3LocationY << endl;
		if (::boardGame[person3LocationX][person3LocationY] == "building")
		{
			cout << "::boardGame[" << person3LocationX << "][" << person3LocationY << "] == building" << endl;
			cout << "Building Occured" << endl;
		}
	}
	::boardGame[person3LocationX][person3LocationY] = "person3";
	if (picked3 == true)   // After picking the person, it's place becomes empty so that taxi can move in that box as well
	{
		::boardGame[person3LocationX][person3LocationY] = " ";
	}
	DrawStickman((person3LocationX * 40), (person3LocationY * 40), 3);  //multiplying with 40 since each boz on grid is 40px

	//Person 3 Destination
	while ((p3DestinationX == person3LocationX and p3DestinationY == person3LocationY) or ::boardGame[p3DestinationX][p3DestinationY] == "building" or ::boardGame[p3DestinationX][p3DestinationY] == "obs")  //person's destination same as initial position or building is there
	{
		p3DestinationX = GetRandInRange(2, 21);
		p3DestinationY = GetRandInRange(0, 19);
	}
	if (picked3 == true)
	{
		if (final3 != true)  // draw green box until arrived
			DrawSquare((p3DestinationX + 1) * 40, p3DestinationY * 40, 40, colors[GREEN]);
		::boardGame[p3DestinationX][p3DestinationY] = "d3";  //Assigning destination on board
	}


	//person4
	if (::boardGame[person4LocationX][person4LocationY] == "building" or ::boardGame[person4LocationX][person4LocationY] == "obs")
	{
		cout << "::boardGame[" << person4LocationX << "][" << person4LocationY << "] == building" << endl;
		cout << "Building Occured" << endl;
	}
	while (::boardGame[person4LocationX][person4LocationY] == "building")  //checking if buildings are there or not
	{
		person4LocationX = GetRandInRange(2, 21);
		person4LocationY = GetRandInRange(0, 19);
		cout << "Coordinates changed" << endl;
		cout << "New coordinated are: " << person4LocationX << " , " << person4LocationY << endl;
		if (::boardGame[person4LocationX][person4LocationY] == "building")
		{
			cout << "::boardGame[" << person4LocationX << "][" << person4LocationY << "] == building" << endl;
			cout << "Building Occured" << endl;
		}
	}
	::boardGame[person4LocationX][person4LocationY] = "person4";
	if (picked4 == true)   // After picking the person, it's place becomes empty so that taxi can move in that box as well
	{
		::boardGame[person4LocationX][person4LocationY] = " ";
	}
	DrawStickman((person4LocationX * 40), (person4LocationY * 40), 4);  //multiplying with 40 since each boz on grid is 40px

	//Person 4 Destination
	while ((p4DestinationX == person4LocationX and p4DestinationY == person4LocationY) or ::boardGame[p4DestinationX][p4DestinationY] == "building" or ::boardGame[p4DestinationX][p4DestinationY] == "obs")  //person's destination same as initial position or building is there
	{
		p4DestinationX = GetRandInRange(2, 21);
		p4DestinationY = GetRandInRange(0, 19);
	}
	if (picked4 == true)
	{
		if (final4 != true)  // draw green box until arrived
			DrawSquare((p4DestinationX + 1) * 40, p4DestinationY * 40, 40, colors[GREEN]);
		::boardGame[p4DestinationX][p4DestinationY] = "d4";  //Assigning destination on board
	}

	//...................................................................................................

		//person1 arrived

	if (final1 == true)   //Draw person1 on it's destination
	{
		DrawStickman1((p1DestinationX) * 40, p1DestinationY * 40, 1);
	}

	//person2 arrived

	if (final2 == true)   //Draw person2 on it's destination
	{
		DrawStickman1((p2DestinationX) * 40, p2DestinationY * 40, 2);
	}

	//person3 arrived

	if (final3 == true)   //Draw person3 on it's destination
	{
		DrawStickman1((p3DestinationX) * 40, p3DestinationY * 40, 3);
	}

	//person4 arrived

	if (final4 == true)   //Draw person4 on it's destination
	{
		DrawStickman1((p4DestinationX) * 40, p4DestinationY * 40, 4);
	}


	//DrawStickman(0, 0, 1);


	Obstacles();
	DrawCars(280, -320 + b);
	moveCarUp();
	DrawCars(400 + a, -160);
	moveCar(0, 800);
	DrawCars(320 + a, -650);
	moveCar(0, 280);

	if (score == 40)  // winning criteria
	{
		glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors
		DrawString(450, 450, "You Won!", colors[GOLD]);
	}
	else if (final1 == true and final2 == true and final3 == true and final4 == true and score < 40)  //losing criteria
	{
		glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors
		DrawString(450, 450, "You Lose!", colors[GOLD]);
	}
}

void crazyTaxi(float x, float y, char colorTaxi) {
	if (colorTaxi == 'y')
	{
		if (picked1 == true or picked2 == true or picked3 == true or picked4 == true)
			DrawRoundRect(13 + x, 830 + y, 4, 3, colors[RED]);
		else
			DrawRoundRect(13 + x, 830 + y, 4, 3, colors[ORANGE]);
		DrawRectangle(10 + x, 825 + y, 10, 5, colors[ORANGE]);
		DrawTriangle(5 + x, 825 + y, 10 + x, 825 + y, 10 + x, 828 + y, colors[ORANGE]);
		DrawTriangle(25 + x, 825 + y, 20 + x, 825 + y, 20 + x, 828 + y, colors[ORANGE]);
		DrawRectangle(2 + x, 815 + y, 35, 10, colors[ORANGE]);
		DrawRectangle(32.5 + x, 819 + y, 4, 4, colors[BLACK]);
		DrawCircle(9 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(25.5 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(9.5 + x, 815 + y, 1.5, colors[GRAY]);
		DrawCircle(25.5 + x, 815 + y, 1.5, colors[GRAY]);
	}
	else if (colorTaxi == 'r')
	{
		if (picked1 == true or picked2 == true or picked3 == true or picked4 == true)
			DrawRoundRect(13 + x, 830 + y, 4, 3, colors[ORANGE]);
		else
			DrawRoundRect(13 + x, 830 + y, 4, 3, colors[RED]);
		DrawRectangle(10 + x, 825 + y, 10, 5, colors[RED]);
		DrawTriangle(5 + x, 825 + y, 10 + x, 825 + y, 10 + x, 828 + y, colors[RED]);
		DrawTriangle(25 + x, 825 + y, 20 + x, 825 + y, 20 + x, 828 + y, colors[RED]);
		DrawRectangle(2 + x, 815 + y, 35, 10, colors[RED]);
		DrawRectangle(32.5 + x, 819 + y, 4, 4, colors[BLACK]);
		DrawCircle(9 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(25.5 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(9.5 + x, 815 + y, 1.5, colors[GRAY]);
		DrawCircle(25.5 + x, 815 + y, 1.5, colors[GRAY]);
	}
	else
	{

		if (YRrandom == 1)  //yellow
		{
			if (picked1 == true or picked2 == true or picked3 == true or picked4 == true)
				DrawRoundRect(13 + x, 830 + y, 4, 3, colors[RED]);
			else
				DrawRoundRect(13 + x, 830 + y, 4, 3, colors[ORANGE]);
			DrawRectangle(10 + x, 825 + y, 10, 5, colors[ORANGE]);
			DrawTriangle(5 + x, 825 + y, 10 + x, 825 + y, 10 + x, 828 + y, colors[ORANGE]);
			DrawTriangle(25 + x, 825 + y, 20 + x, 825 + y, 20 + x, 828 + y, colors[ORANGE]);
			DrawRectangle(2 + x, 815 + y, 35, 10, colors[ORANGE]);
			DrawRectangle(32.5 + x, 819 + y, 4, 4, colors[BLACK]);
			DrawCircle(9 + x, 815 + y, 4, colors[BLACK]);
			DrawCircle(25.5 + x, 815 + y, 4, colors[BLACK]);
			DrawCircle(9.5 + x, 815 + y, 1.5, colors[GRAY]);
			DrawCircle(25.5 + x, 815 + y, 1.5, colors[GRAY]);
		}
		else  //red
		{
			if (picked1 == true or picked2 == true or picked3 == true or picked4 == true)
				DrawRoundRect(13 + x, 830 + y, 4, 3, colors[ORANGE]);
			else
				DrawRoundRect(13 + x, 830 + y, 4, 3, colors[RED]);
			DrawRectangle(10 + x, 825 + y, 10, 5, colors[RED]);
			DrawTriangle(5 + x, 825 + y, 10 + x, 825 + y, 10 + x, 828 + y, colors[RED]);
			DrawTriangle(25 + x, 825 + y, 20 + x, 825 + y, 20 + x, 828 + y, colors[RED]);
			DrawRectangle(2 + x, 815 + y, 35, 10, colors[RED]);
			DrawRectangle(32.5 + x, 819 + y, 4, 4, colors[BLACK]);
			DrawCircle(9 + x, 815 + y, 4, colors[BLACK]);
			DrawCircle(25.5 + x, 815 + y, 4, colors[BLACK]);
			DrawCircle(9.5 + x, 815 + y, 1.5, colors[GRAY]);
			DrawCircle(25.5 + x, 815 + y, 1.5, colors[GRAY]);
		}
	}

	glutPostRedisplay();

}

void DrawStickman(float x, float y, int id) {
	if (picked1 == false and id == 1)
	{
		DrawCircle(60 + x, 28 + y, 5, colors[BLACK]);  //head
		DrawLine(60.5 + x, 14 + y, 60.5 + x, 28 + y, 3, colors[BLACK]); //body
		DrawLine(54 + x, 14 + y, 62 + x, 28 + y, 3, colors[BLACK]);  // left arm
		DrawLine(66 + x, 14 + y, 59 + x, 28 + y, 3, colors[BLACK]);   // right arm
		DrawLine(55 + x, 2 + y, 60.5 + x, 14 + y, 3, colors[BLACK]);   //left leg
		DrawLine(65.5 + x, 2 + y, 60.5 + x, 14 + y, 3, colors[BLACK]);    //right leg

	}
	else if (picked2 == false and id == 2)
	{
		DrawCircle(60 + x, 28 + y, 5, colors[BLACK]);  //head
		DrawLine(60.5 + x, 14 + y, 60.5 + x, 28 + y, 3, colors[BLACK]); //body
		DrawLine(54 + x, 14 + y, 62 + x, 28 + y, 3, colors[BLACK]);  // left arm
		DrawLine(66 + x, 14 + y, 59 + x, 28 + y, 3, colors[BLACK]);   // right arm
		DrawLine(55 + x, 2 + y, 60.5 + x, 14 + y, 3, colors[BLACK]);   //left leg
		DrawLine(65.5 + x, 2 + y, 60.5 + x, 14 + y, 3, colors[BLACK]);    //right leg
	}
	else if (picked3 == false and id == 3)
	{
		DrawCircle(60 + x, 28 + y, 5, colors[BLACK]);  //head
		DrawLine(60.5 + x, 14 + y, 60.5 + x, 28 + y, 3, colors[BLACK]); //body
		DrawLine(54 + x, 14 + y, 62 + x, 28 + y, 3, colors[BLACK]);  // left arm
		DrawLine(66 + x, 14 + y, 59 + x, 28 + y, 3, colors[BLACK]);   // right arm
		DrawLine(55 + x, 2 + y, 60.5 + x, 14 + y, 3, colors[BLACK]);   //left leg
		DrawLine(65.5 + x, 2 + y, 60.5 + x, 14 + y, 3, colors[BLACK]);    //right leg
	}
	else if (picked4 == false and id == 4)
	{
		DrawCircle(60 + x, 28 + y, 5, colors[BLACK]);  //head
		DrawLine(60.5 + x, 14 + y, 60.5 + x, 28 + y, 3, colors[BLACK]); //body
		DrawLine(54 + x, 14 + y, 62 + x, 28 + y, 3, colors[BLACK]);  // left arm
		DrawLine(66 + x, 14 + y, 59 + x, 28 + y, 3, colors[BLACK]);   // right arm
		DrawLine(55 + x, 2 + y, 60.5 + x, 14 + y, 3, colors[BLACK]);   //left leg
		DrawLine(65.5 + x, 2 + y, 60.5 + x, 14 + y, 3, colors[BLACK]);    //right leg
	}

	glutPostRedisplay();
}
void DrawStickman1(float x, float y, int id)
{
	DrawCircle(60 + x, 28 + y, 5, colors[GREEN]);  //head
	DrawLine(60.5 + x, 14 + y, 60.5 + x, 28 + y, 3, colors[GREEN]); //body
	DrawLine(54 + x, 14 + y, 62 + x, 28 + y, 3, colors[GREEN]);  // left arm
	DrawLine(66 + x, 14 + y, 59 + x, 28 + y, 3, colors[GREEN]);   // right arm
	DrawLine(55 + x, 2 + y, 60.5 + x, 14 + y, 3, colors[GREEN]);   //left leg
	DrawLine(65.5 + x, 2 + y, 60.5 + x, 14 + y, 3, colors[GREEN]);    //right leg
}

void Obstacles()
{
	//Trees
	DrawRectangle(12 + 480, 10 + 715, 10, 20, colors[BROWN]);
	DrawCircle(10 + 480, 30 + 715, 5, colors[GREEN]);
	DrawCircle(16 + 480, 30 + 715, 5, colors[GREEN]);
	DrawCircle(16 + 480, 38 + 715, 5, colors[GREEN]);
	DrawCircle(24 + 480, 32 + 715, 5, colors[GREEN]);
	::boardGame[11][18] = "obs";

	DrawRectangle(12 + 680, 10 + 480, 10, 20, colors[BROWN]);
	DrawCircle(10 + 680, 30 + 480, 5, colors[GREEN]);
	DrawCircle(16 + 680, 30 + 480, 5, colors[GREEN]);
	DrawCircle(16 + 680, 38 + 480, 5, colors[GREEN]);
	DrawCircle(24 + 680, 32 + 480, 5, colors[GREEN]);
	::boardGame[16][12] = "obs";

	DrawRectangle(12 + 240, 10 + 560, 10, 20, colors[BROWN]);
	DrawCircle(10 + 240, 30 + 560, 5, colors[GREEN]);
	DrawCircle(16 + 240, 30 + 560, 5, colors[GREEN]);
	DrawCircle(16 + 240, 38 + 560, 5, colors[GREEN]);
	DrawCircle(24 + 240, 32 + 560, 5, colors[GREEN]);
	::boardGame[5][14] = "obs";

	DrawRectangle(12 + 240, 10 + 200, 10, 20, colors[BROWN]);
	DrawCircle(10 + 240, 30 + 200, 5, colors[GREEN]);
	DrawCircle(16 + 240, 30 + 200, 5, colors[GREEN]);
	DrawCircle(16 + 240, 38 + 200, 5, colors[GREEN]);
	DrawCircle(24 + 240, 32 + 200, 5, colors[GREEN]);
	::boardGame[5][5] = "obs";

	//Trash cans
	DrawSquare(10 + 120, 5 + 600, 20, colors[NAVY]);
	DrawSquare(12.5 + 120, 7.5 + 600, 20, colors[NAVY]);
	DrawSquare(15 + 120, 10 + 600, 20, colors[NAVY]);
	DrawSquare(17.5 + 120, 12.5 + 600, 20, colors[NAVY]);
	DrawSquare(20 + 120, 15 + 600, 20, colors[BLUE]);
	::boardGame[2][15] = "obs";

	DrawSquare(10 + 640, 5 + 40, 20, colors[NAVY]);
	DrawSquare(12.5 + 640, 7.5 + 40, 20, colors[NAVY]);
	DrawSquare(15 + 640, 10 + 40, 20, colors[NAVY]);
	DrawSquare(17.5 + 640, 12.5 + 40, 20, colors[NAVY]);
	DrawSquare(20 + 640, 15 + 40, 20, colors[BLUE]);
	::boardGame[15][1] = "obs";

	DrawSquare(10 + 640, 5 + 320, 20, colors[NAVY]);
	DrawSquare(12.5 + 640, 7.5 + 320, 20, colors[NAVY]);
	DrawSquare(15 + 640, 10 + 320, 20, colors[NAVY]);
	DrawSquare(17.5 + 640, 12.5 + 320, 20, colors[NAVY]);
	DrawSquare(20 + 640, 15 + 320, 20, colors[BLUE]);
	::boardGame[15][8] = "obs";
}
void DrawCars(float x, float y)
{
	int ct1 = 0;
	while (ct1 != 1)
	{
		carColor = GetRandInRange(1, 6);  //choose cars colors from 6 colors
		ct1 = 1;
	}
	if (carColor == 1)
	{
		DrawRectangle(10 + x, 825 + y, 10, 5, colors[NAVY]);
		DrawTriangle(5 + x, 825 + y, 10 + x, 825 + y, 10 + x, 828 + y, colors[NAVY]);
		DrawTriangle(25 + x, 825 + y, 20 + x, 825 + y, 20 + x, 828 + y, colors[NAVY]);
		DrawRectangle(2 + x, 815 + y, 35, 10, colors[NAVY]);
		DrawRectangle(32.5 + x, 819 + y, 4, 4, colors[BLACK]);
		DrawCircle(9 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(25.5 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(9.5 + x, 815 + y, 1.5, colors[GRAY]);
		DrawCircle(25.5 + x, 815 + y, 1.5, colors[GRAY]);
	}
	else if (carColor == 2)
	{
		DrawRectangle(10 + x, 825 + y, 10, 5, colors[PINK]);
		DrawTriangle(5 + x, 825 + y, 10 + x, 825 + y, 10 + x, 828 + y, colors[PINK]);
		DrawTriangle(25 + x, 825 + y, 20 + x, 825 + y, 20 + x, 828 + y, colors[PINK]);
		DrawRectangle(2 + x, 815 + y, 35, 10, colors[PINK]);
		DrawRectangle(32.5 + x, 819 + y, 4, 4, colors[BLACK]);
		DrawCircle(9 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(25.5 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(9.5 + x, 815 + y, 1.5, colors[GRAY]);
		DrawCircle(25.5 + x, 815 + y, 1.5, colors[GRAY]);
	}
	else if (carColor == 3)
	{
		DrawRectangle(10 + x, 825 + y, 10, 5, colors[RED]);
		DrawTriangle(5 + x, 825 + y, 10 + x, 825 + y, 10 + x, 828 + y, colors[RED]);
		DrawTriangle(25 + x, 825 + y, 20 + x, 825 + y, 20 + x, 828 + y, colors[RED]);
		DrawRectangle(2 + x, 815 + y, 35, 10, colors[RED]);
		DrawRectangle(32.5 + x, 819 + y, 4, 4, colors[RED]);
		DrawCircle(9 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(25.5 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(9.5 + x, 815 + y, 1.5, colors[GRAY]);
		DrawCircle(25.5 + x, 815 + y, 1.5, colors[GRAY]);
	}
	else if (carColor == 4)
	{
		DrawRectangle(10 + x, 825 + y, 10, 5, colors[INDIGO]);
		DrawTriangle(5 + x, 825 + y, 10 + x, 825 + y, 10 + x, 828 + y, colors[INDIGO]);
		DrawTriangle(25 + x, 825 + y, 20 + x, 825 + y, 20 + x, 828 + y, colors[INDIGO]);
		DrawRectangle(2 + x, 815 + y, 35, 10, colors[INDIGO]);
		DrawRectangle(32.5 + x, 819 + y, 4, 4, colors[BLACK]);
		DrawCircle(9 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(25.5 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(9.5 + x, 815 + y, 1.5, colors[GRAY]);
		DrawCircle(25.5 + x, 815 + y, 1.5, colors[GRAY]);
	}
	else if (carColor == 5)
	{
		DrawRectangle(10 + x, 825 + y, 10, 5, colors[YELLOW_GREEN]);
		DrawTriangle(5 + x, 825 + y, 10 + x, 825 + y, 10 + x, 828 + y, colors[YELLOW_GREEN]);
		DrawTriangle(25 + x, 825 + y, 20 + x, 825 + y, 20 + x, 828 + y, colors[YELLOW_GREEN]);
		DrawRectangle(2 + x, 815 + y, 35, 10, colors[YELLOW_GREEN]);
		DrawRectangle(32.5 + x, 819 + y, 4, 4, colors[BLACK]);
		DrawCircle(9 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(25.5 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(9.5 + x, 815 + y, 1.5, colors[GRAY]);
		DrawCircle(25.5 + x, 815 + y, 1.5, colors[GRAY]);
	}
	else
	{
		DrawRectangle(10 + x, 825 + y, 10, 5, colors[CYAN]);
		DrawTriangle(5 + x, 825 + y, 10 + x, 825 + y, 10 + x, 828 + y, colors[CYAN]);
		DrawTriangle(25 + x, 825 + y, 20 + x, 825 + y, 20 + x, 828 + y, colors[CYAN]);
		DrawRectangle(2 + x, 815 + y, 35, 10, colors[CYAN]);
		DrawRectangle(32.5 + x, 819 + y, 4, 4, colors[BLACK]);
		DrawCircle(9 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(25.5 + x, 815 + y, 4, colors[BLACK]);
		DrawCircle(9.5 + x, 815 + y, 1.5, colors[GRAY]);
		DrawCircle(25.5 + x, 815 + y, 1.5, colors[GRAY]);
	}
	glutPostRedisplay();

}



bool flag = true;
void moveCar(int min, int max) {

	if (a >= min && flag) {
		a -= 5;
		if (a < min + 20)

			flag = false;

	}
	else if (a < max && !flag) {
		a += 5;
		if (a > max - 1)
			flag = true;
	}
}
bool flag2 = true;
void moveCarUp() {

	if (b > 60 && flag) {
		b -= 5;
		if (b < 100)

			flag2 = false;

	}
	else if (b < 600 && !flag) {
		b += 5;
		if (b > 580)
			flag2 = true;
	}
}

/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/ {
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
		1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	menu();       //Calling Menu
	glutSwapBuffers(); // do not modify this line..

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
	if (key == GLUT_KEY_LEFT and xI >= 110) /*left arrow key*/
	{
		xI -= 40;

		int x1 = xI / 40;
		int y1 = yI / 40;
		cout << "LEFT KEY" << endl;
		cout << "x1: " << x1 << endl;
		cout << "y1: " << y1 << endl;
		if (::boardGame[x1][y1] == "building" or ::boardGame[x1][y1] == "obs" or ::boardGame[x1][y1] == "person1" or ::boardGame[x1][y1] == "person2" or ::boardGame[x1][y1] == "person3" or ::boardGame[x1][y1] == "person4")
		{
			xI += 40;
			if (::boardGame[x1][y1] == "obs")
			{
				score -= 3;
			}
			if (::boardGame[x1][y1] == "person1")  //person 1 ready to be picked
			{
				ready1 = true;
				cout << "Person 1 Ready" << endl;

			}
			if (::boardGame[x1][y1] == "person2")  //person 2 ready to be picked
			{
				ready2 = true;
				cout << "Person 2 Ready" << endl;

			}
			if (::boardGame[x1][y1] == "person3") //person 3 ready to be picked
			{
				ready3 = true;
				cout << "Person 3 Ready" << endl;

			}
			if (::boardGame[x1][y1] == "person4")  //person 4 ready to be picked
			{
				ready4 = true;
				cout << "Person 4 Ready" << endl;

			}
			//..............................................................................
			if (::boardGame[x1][y1] != "person1")  //Taxi moved away from person 1
			{
				ready1 = false;
			}
			if (::boardGame[x1][y1] != "person2")  //Taxi moved away from person 2
			{
				ready2 = false;
			}
			if (::boardGame[x1][y1] != "person3") //Taxi moved away from person 3
			{
				ready3 = false;
			}
			if (::boardGame[x1][y1] != "person4")  //Taxi moved away from person 4
			{
				ready4 = false;
			}

		}
		if (picked1 == true)
		{
			if (::boardGame[x1][y1] == "d1")  //arrived at destination or not
			{
				arrived1 = true;
				cout << "Player 1 Arrived" << endl;
			}
		}
		if (picked2 == true)
		{
			if (::boardGame[x1][y1] == "d2")  //arrived at destination or not
			{
				arrived2 = true;
				cout << "Player 2 Arrived" << endl;
			}
		}
		if (picked3 == true)
		{
			if (::boardGame[x1][y1] == "d3")  //arrived at destination or not
			{
				arrived3 = true;
				cout << "Player 3 Arrived" << endl;
			}
		}
		if (picked4 == true)
		{
			if (::boardGame[x1][y1] == "d4")  //arrived at destination or not
			{
				arrived4 = true;
				cout << "Player 4 Arrived" << endl;
			}
		}
	}
	else if (key == GLUT_KEY_RIGHT and xI <= 800) /*right arrow key*/
	{
		xI += 40;
		int x1 = xI / 40;
		int y1 = yI / 40;
		cout << "RIGHT KEY" << endl;
		cout << "x1: " << x1 << endl;
		cout << "y1: " << y1 << endl;
		if (::boardGame[x1][y1] == "building" or ::boardGame[x1][y1] == "obs" or ::boardGame[x1][y1] == "person1" or ::boardGame[x1][y1] == "person2" or ::boardGame[x1][y1] == "person3" or ::boardGame[x1][y1] == "person4")
		{
			xI -= 40;
			if (::boardGame[x1][y1] == "obs")
			{
				score -= 3;
			}
			if (::boardGame[x1][y1] == "person1")  //person 1 ready to be picked
			{
				ready1 = true;
				cout << "Person 1 Ready" << endl;

			}
			if (::boardGame[x1][y1] == "person2")  //person 2 ready to be picked
			{
				ready2 = true;
				cout << "Person 2 Ready" << endl;

			}
			if (::boardGame[x1][y1] == "person3") //person 3 ready to be picked
			{
				ready3 = true;
				cout << "Person 3 Ready" << endl;

			}
			if (::boardGame[x1][y1] == "person4")  //person 4 ready to be picked
			{
				ready4 = true;
				cout << "Person 4 Ready" << endl;

			}
			//..............................................................................
			if (::boardGame[x1][y1] != "person1")  //Taxi moved away from person 1
			{
				ready1 = false;
			}
			if (::boardGame[x1][y1] != "person2")  //Taxi moved away from person 2
			{
				ready2 = false;
			}
			if (::boardGame[x1][y1] != "person3") //Taxi moved away from person 3
			{
				ready3 = false;
			}
			if (::boardGame[x1][y1] != "person4")  //Taxi moved away from person 4
			{
				ready4 = false;
			}

		}
		if (picked1 == true)
		{
			if (::boardGame[x1][y1] == "d1")  //arrived at destination or not
			{
				arrived1 = true;
				cout << "Player 1 Arrived" << endl;
			}
		}
		if (picked2 == true)
		{
			if (::boardGame[x1][y1] == "d2")  //arrived at destination or not
			{
				arrived2 = true;
				cout << "Player 2 Arrived" << endl;
			}
		}
		if (picked3 == true)
		{
			if (::boardGame[x1][y1] == "d3")  //arrived at destination or not
			{
				arrived3 = true;
				cout << "Player 3 Arrived" << endl;
			}
		}
		if (picked4 == true)
		{
			if (::boardGame[x1][y1] == "d4")  //arrived at destination or not
			{
				arrived4 = true;
				cout << "Player 4 Arrived" << endl;
			}
		}
	}
	else if (key == GLUT_KEY_DOWN and yI >= -790)   /*down arrow key*/
	{
		yI -= 40;

		int x1 = xI / 40;
		int y1 = yI / 40;
		cout << "DOWN KEY" << endl;
		cout << "x1: " << x1 << endl;
		cout << "y1: " << y1 << endl;
		if (::boardGame[x1][y1] == "building" or ::boardGame[x1][y1] == "obs" or ::boardGame[x1][y1] == "person1" or ::boardGame[x1][y1] == "person2" or ::boardGame[x1][y1] == "person3" or ::boardGame[x1][y1] == "person4")
		{
			yI += 40;
			if (::boardGame[x1][y1] == "obs")
			{
				score -= 3;
			}
			if (::boardGame[x1][y1] == "person1")  //person 1 ready to be picked
			{
				ready1 = true;
				cout << "Person 1 Ready" << endl;

			}
			if (::boardGame[x1][y1] == "person2")  //person 2 ready to be picked
			{
				ready2 = true;
				cout << "Person 2 Ready" << endl;

			}
			if (::boardGame[x1][y1] == "person3") //person 3 ready to be picked
			{
				ready3 = true;
				cout << "Person 3 Ready" << endl;

			}
			if (::boardGame[x1][y1] == "person4")  //person 4 ready to be picked
			{
				ready4 = true;
				cout << "Person 4 Ready" << endl;

			}
			//..............................................................................
			if (::boardGame[x1][y1] != "person1")  //Taxi moved away from person 1
			{
				ready1 = false;
			}
			if (::boardGame[x1][y1] != "person2")  //Taxi moved away from person 2
			{
				ready2 = false;
			}
			if (::boardGame[x1][y1] != "person3") //Taxi moved away from person 3
			{
				ready3 = false;
			}
			if (::boardGame[x1][y1] != "person4")  //Taxi moved away from person 4
			{
				ready4 = false;
			}
		}
		if (picked1 == true)
		{
			if (::boardGame[x1][y1] == "d1")  //arrived at destination or not
			{
				arrived1 = true;
				cout << "Player 1 Arrived" << endl;
			}
		}
		if (picked2 == true)
		{
			if (::boardGame[x1][y1] == "d2")  //arrived at destination or not
			{
				arrived2 = true;
				cout << "Player 2 Arrived" << endl;
			}
		}
		if (picked3 == true)
		{
			if (::boardGame[x1][y1] == "d3")  //arrived at destination or not
			{
				arrived3 = true;
				cout << "Player 3 Arrived" << endl;
			}
		}
		if (picked4 == true)
		{
			if (::boardGame[x1][y1] == "d4")  //arrived at destination or not
			{
				arrived4 = true;
				cout << "Player 4 Arrived" << endl;
			}
		}
	}
	else if (key == GLUT_KEY_UP and yI <= -80)   /*up arrow key*/
	{
		yI += 40;
		int x1 = xI / 40;
		int y1 = yI / 40;
		cout << "UP KEY" << endl;
		cout << "x1: " << x1 << endl;
		cout << "y1: " << y1 << endl;
		if (::boardGame[x1][y1] == "building" or ::boardGame[x1][y1] == "obs" or ::boardGame[x1][y1] == "person1" or ::boardGame[x1][y1] == "person2" or ::boardGame[x1][y1] == "person3" or ::boardGame[x1][y1] == "person4")
		{
			yI -= 40;
			if (::boardGame[x1][y1] == "obs")
			{
				score -= 3;
			}
			if (::boardGame[x1][y1] == "person1")  //person 1 ready to be picked
			{
				ready1 = true;
				cout << "Person 1 Ready" << endl;

			}
			if (::boardGame[x1][y1] == "person2")  //person 2 ready to be picked
			{
				ready2 = true;
				cout << "Person 2 Ready" << endl;

			}
			if (::boardGame[x1][y1] == "person3") //person 3 ready to be picked
			{
				ready3 = true;
				cout << "Person 3 Ready" << endl;

			}
			if (::boardGame[x1][y1] == "person4")  //person 4 ready to be picked
			{
				ready4 = true;
				cout << "Person 4 Ready" << endl;

			}
			//..............................................................................
			if (::boardGame[x1][y1] != "person1")  //Taxi moved away from person 1
			{
				ready1 = false;
			}
			if (::boardGame[x1][y1] != "person2")  //Taxi moved away from person 2
			{
				ready2 = false;
			}
			if (::boardGame[x1][y1] != "person3") //Taxi moved away from person 3
			{
				ready3 = false;
			}
			if (::boardGame[x1][y1] != "person4")  //Taxi moved away from person 4
			{
				ready4 = false;
			}

		}
		if (picked1 == true)
		{
			if (::boardGame[x1][y1] == "d1")  //arrived at destination or not
			{
				arrived1 = true;
				cout << "Player 1 Arrived" << endl;
			}
		}
		if (picked2 == true)
		{
			if (::boardGame[x1][y1] == "d2")  //arrived at destination or not
			{
				arrived2 = true;
				cout << "Player 2 Arrived" << endl;
			}
		}
		if (picked3 == true)
		{
			if (::boardGame[x1][y1] == "d3")  //arrived at destination or not
			{
				arrived3 = true;
				cout << "Player 3 Arrived" << endl;
			}
		}
		if (picked4 == true)
		{
			if (::boardGame[x1][y1] == "d4")  //arrived at destination or not
			{
				arrived4 = true;
				cout << "Player 4 Arrived" << endl;
			}
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
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
	{
		//do something if b is pressed
		cout << "b pressed" << endl;
	}
	if (key == 32)
	{
		cout << "space is pressed" << endl;
		if (ready1 == true)
		{
			picked1 = true;
			cout << "Player 1 Picked" << endl;
		}
		else if (ready2 == true)
		{
			picked2 = true;
			cout << "Player 2 Picked" << endl;
		}
		else if (ready3 == true)
		{
			picked3 = true;
			cout << "Player 3 Picked" << endl;
		}
		else if (ready4 == true)
		{
			picked4 = true;
			cout << "Player 4 Picked" << endl;
		}
		if (arrived1 == true)
		{
			final1 = true;
			while (s1 != 1)
			{
				score += 10;
				s1 = 1;
			}
		}
		if (arrived2 == true)
		{
			final2 = true;
			while (s2 != 1)
			{
				score += 10;
				s2 = 1;
			}
		}
		if (arrived3 == true)
		{
			final3 = true;
			while (s3 != 1)
			{
				score += 10;
				s3 = 1;
			}
		}
		if (arrived4 == true)
		{
			final4 = true;
			while (s4 != 1)
			{
				score += 10;
				s4 = 1;
			}
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


	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(2000, Timer, 0);
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
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
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON and (x >= 145 and x <= 455) and (y >= 445 and y <= 595)) // dealing only with left button
	{
		//yellow cab
		taxiColor = 'y';
		mouse_clicked = true;
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
	}
	else if (button == GLUT_LEFT_BUTTON and (x >= 550 and x <= 855) and (y >= 445 and y <= 595)) // dealing only with left button
	{
		//red cab
		taxiColor = 'r';
		mouse_clicked = true;
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
	}
	else if (button == GLUT_LEFT_BUTTON and (x >= 350 and x <= 650) and (y >= 625 and y <= 770)) // dealing only with left button
	{
		//random color
		taxiColor = 'u';
		mouse_clicked = true;
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		cout << "Right Button Pressed" << endl;
	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char* argv[]) {

	int width = 1000, height = 900; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Muhammad Affan (21i-0474)"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);


	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
