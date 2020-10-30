#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

#define _MAZE vector<string>

_MAZE maze = {
	"####B######################",
	"# #       #   #      #    #",
	"# # # ###### #### ####### #",
	"# # # #       #   #       #",
	"#   # # ######### # ##### #",
	"# # # #   #       #     # #",
	"### ### ### ############# #",
	"# #   #     # #           #",
	"# # #   ####### ###########",
	"# # # #       # #         C",
	"# # ##### ### # # ####### #",
	"# # #     ### # #       # #",
	"#   ##### ### # ######### #",
	"######### ### #           #",
	"# ####### ### #############",
	"A           #   ###   #   #",
	"# ############# ### # # # #",
	"# ###       # # ### # # # #",
	"# ######### # # ### # # # F",
	"#       ### # #     # # # #",
	"# ######### # ##### # # # #",
	"# #######   #       #   # #",
	"# ####### ######### #######",
	"#         #########       #",
	"#######E############D######"
};

const vector<char> wall = { '#' };
const vector<char> searched = { '☺' };
const vector<char> space = { ' ' };
const vector<char> exitc = { 
	'A', 'B', 'C', 'D', 'E', 'F', 'G',
	'H', 'I', 'J', 'K', 'L', 'M', 'N',
	'O', 'P', 'Q', 'R', 'S', 'T', 'U', 
	'V', 'W', 'X', 'Y', 'Z' };

struct XCOORD {
	int X;
	int Y;
};

#define _QUEUE vector<XCOORD>

void Debug(_MAZE cmaze, _QUEUE queue, int X, int Y) {
	#include <cstdlib>
	system("cls");
	for (int i = 0; i < cmaze.size(); i++) {
		cout << cmaze[i] << endl;
	}
	cout << "Coordinates: " << X << "; " << Y;
	cout << endl << "QUEUE (last 12): ";
	for (int i = max(0, (int)queue.size()-11); i < queue.size(); i++) {
		cout << "[" << queue[i].X << "; " << queue[i].Y << "] ";
	}
	system("timeout -t 0 > nul");
}

template <typename T>
bool isIn(T element, vector<T> vect) {
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i] == element) {
			return true;
		}
	}
	return false;
}

char GetByCoord(_MAZE cmaze, int X, int Y) {
	return cmaze[Y][X];
}

void SetByCoord(_MAZE &cmaze, int X, int Y, char Value) {
	cmaze[Y][X] = Value;
}

bool CompareObjectByCoord(_MAZE cmaze, int X, int Y, vector<char> object) {
	return isIn(GetByCoord(cmaze, X, Y), object);
}

bool IsCoordinatesCorrect(_MAZE cmaze, int X, int Y) {
	return (X >= 0) && (Y >= 0) &&
		(X < cmaze[0].length()) && (Y < cmaze.size()) &&
		(!CompareObjectByCoord(cmaze, X, Y, wall)) &&
		(!CompareObjectByCoord(cmaze, X, Y, searched));
}

string BFS(int X, int Y) {
	_MAZE cmaze = maze;
	string found = "";
	int i = 0;
	_QUEUE queue = { {X, Y} };
	while (i < queue.size()) {
		X = queue[i].X;
		Y = queue[i].Y;
		i++;
		//Debug(cmaze, queue, X, Y);
		if (CompareObjectByCoord(cmaze, X, Y, exitc)) {
			found += GetByCoord(cmaze, X, Y);
			found += " ";
			SetByCoord(cmaze, X, Y, searched[0]);
			continue;
		}
		SetByCoord(cmaze, X, Y, searched[0]);
		if (IsCoordinatesCorrect(cmaze, X + 1, Y))
			queue.push_back(XCOORD{X+1, Y});
		if (IsCoordinatesCorrect(cmaze, X, Y + 1))
			queue.push_back(XCOORD{X, Y+1});
		if (IsCoordinatesCorrect(cmaze, X - 1, Y))
			queue.push_back(XCOORD{X-1, Y});
		if (IsCoordinatesCorrect(cmaze, X, Y - 1))
			queue.push_back(XCOORD{X, Y-1});
	}
	return found;
}


int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int X, Y;
	cin >> X >> Y;
	if (IsCoordinatesCorrect(maze, X, Y))
		cout << BFS(X, Y);
	else
		cout << "Не верные координаты";
}