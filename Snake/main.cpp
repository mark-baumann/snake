#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool gameover;
const int width = 20; //Größe der Karte
const int height = 17; 
int x, y, fruitX, fruitY, score; 
int tailX[100], tailY[100]; //Snake Koordinaten
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN }; // Controls
eDirecton dir;

void Setup() {
	gameover = false;
	x = width / 2;
	y = height / 2; 
	fruitX = rand() % width; //Früchte random erstellen
	fruitY = rand() % height; score = 0;
}

void Draw() {
	system("cls");
	for (int i = 0; i < width + 2; i++)
		cout << "#"; //Obere Reihe erstellen
	cout << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0)
				cout << "#"; //Linke Reihe erstellen
			
			if (i == y && j == x)
				cout << "*"; // snake erstellen
			else if (i == fruitY && j == fruitX)
				cout << "%"; //Frucht erstellen
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						cout << "*"; print = true;
					}
				}
				if (!print) cout << " ";//Sonst gebe nichts aus
			}
			if (j == width - 1) //Rechte Reihe erstellen
				cout << "#";
				
		}
		cout << endl;
	}
	//untere Reihe erstellen
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
	}



void Input()
{
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			break;
		}

	}

}




void Algorithm() {

	//Change direction
	switch (dir) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	
	//wenn die x Koordinate und y Koordinate die Koordinaten der Frucht haben
	if (x == fruitX && y == fruitY) {

		score += 10;

		fruitX = rand() % width; //Setze die Frucht an eine neue Pos

		fruitY = rand() % height;

		nTail++; //Variable das immer ein neues Sternchen hinzukommt 

	}

	int prevX = tailX[0];

	int prevY = tailY[0]; //Speichere die Alte Koordinate in einer variable

	int prev2X, prev2Y;

	tailX[0] = x; //Speichere neuen Koordinaten 

	tailY[0] = y; 

	for (int i = 1; i < 10; i++) { //ab 1 beginnend damit nicht ein Stern in der Eckem hängt

		prev2X = tailX[i]; //neue Pos in der Variablen prev2X

		prev2Y = tailY[i];

		tailX[i] = prevX; //alte Pos in der Variablen tailX

		tailY[i] = prevY;

		prevX = prev2X; //neue Pos in der Variablen prevX

		prevY = prev2Y;

	}
	
}

	

int main() {

	while (true) {
		Draw();
		Input();
		Algorithm();
	}

	

	system("pause");
	return 0;
}