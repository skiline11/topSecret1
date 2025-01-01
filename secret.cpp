#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<unistd.h>

using namespace std;

int xSize = 120, ySize = 100, topPadding = 18, leftPadding = 35;
char mark = 'X';
char page[120][100];

void printA(int startX, int startY) {
// ..XXXXX
// ..X   X
// ..XXXXX
// ..X   X
// ..X   X
	for (int i = 0; i < 5; i++) {
		page[startX + i][startY] = mark;
		page[startX + i][startY + 2] = mark;
		page[startX][startY + i] = mark;
		page[startX + 4][startY + i] = mark;
	}
}

void printC(int startX, int startY) {
// .. XXXX
// ..XX
// ..XX
// ..XX
// .. XXXX
	for (int i = 0; i < 3; i++) {
		page[startX][startY + 1 + i] = mark;
		page[startX + 1][startY + 1 + i] = mark;
		page[startX + 1 + i][startY] = mark;
		page[startX + 1 + i][startY + 4] = mark;
	}
	page[startX + 4][startY] = mark;
	page[startX + 4][startY + 4] = mark;
}

void printE2(int startX, int startY) {
// ..XXXXX
// ..X
// ..XXXXX
// ..X
// ..XXXX
// .....XX
	for (int i = 0; i < 5; i++) {
		page[startX + i][startY] = mark;
		page[startX + i][startY + 2] = mark;
		page[startX][startY + i] = mark;
	}
	for (int i = 0; i < 4; i++) page[startX + i][startY + 4] = mark;
	for (int i = 0; i < 2; i++) page[startX + 3 + i][startY + 5] = mark;
}

void printG(int startX, int startY) {
// ..XXXXX
// ..X
// ..X  XX
// ..X   X
// ..XXXXX
	for (int i = 0; i < 5; i++) {
		page[startX + i][startY] = mark;
		page[startX][startY + i] = mark;
		page[startX + i][startY + 4] = mark;
	}
	page[startX + 3][startY + 2] = mark;
	page[startX + 4][startY + 2] = mark;
	page[startX + 4][startY + 3] = mark;
}

void printH(int startX, int startY) {
// ..X...X
// ..X...X
// ..XXXXX
// ..X...X
// ..X...X
	for (int i = 0; i < 5; i++) {
		page[startX][startY + i] = mark;
		page[startX + 4][startY + i] = mark;
		page[startX + i][startY + 2] = mark;
	}
}

void printI(int startX, int startY) {
// ..XXXXX
// ...XXX.
// ...XXX.
// ...XXX.
// ..XXXXX
	for (int i = 0; i < 5; i++) {
		page[startX + i][startY] = mark;
		page[startX + 1][startY + i] = mark;
		page[startX + 2][startY + i] = mark;
		page[startX + 3][startY + i] = mark;
		page[startX + i][startY + 4] = mark;
	}
}

void printK(int startX, int startY) {
// ..X  XX
// ..X XX
// ..XXX
// ..X XX
// ..X  XX
	for (int i = 0; i < 3; i++) {
		page[startX][startY + 2 - i] = mark;
		page[startX][startY + 2 + i] = mark;
		page[startX + 1 + i][startY + 2 - i] = mark;
		page[startX + 1 + i][startY + 2 + i] = mark;
		page[startX + 2 + i][startY + 2 - i] = mark;
		page[startX + 2 + i][startY + 2 + i] = mark;
	}
}

void printM(int startX, int startY) {
// ..XX XX
// ..X X X
// ..X X X
// ..X X X
// ..X   X
	for (int i = 0; i < 5; i++) {
		page[startX][startY + i] = mark;
		page[startX + 4][startY + i] = mark;
	}
	for (int i = 0; i < 3; i++) page[startX + 2][startY + 1 + i] = mark;
	page[startX + 1][startY] = mark;
	page[startX + 3][startY] = mark;
}

void printO(int startX, int startY) {
// ..XXXXX
// ..X...X
// ..X...X
// ..X...X
// ..XXXXX
	for (int i = 0; i < 5; i++) {
		page[startX + i][startY] = mark;
		page[startX + i][startY + 4] = mark;
		page[startX][startY + i] = mark;
		page[startX + 4][startY + i] = mark;
	}
}

void printS(int startX, int startY) {
// ..XXXXX
// ..X....
// ..XXXXX
// ......X
// ..XXXXX
	for (int i = 0; i < 5; i++) {
		page[startX + i][startY] = mark;
		page[startX + i][startY + 2] = mark;
		page[startX + i][startY + 4] = mark;
	}
	page[startX][startY + 1] = mark;
	page[startX + 4][startY + 3] = mark;
}

void printChar(char x) {
	if (x == '\0') {
		cout << " ";
	} else cout << x;
}

void printTopPadding() {
	for (int i = 0; i < topPadding; i++) cout << endl;
}

void printPage() {
	system("clear");
	printTopPadding();
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < leftPadding; x++) cout << " ";
		for (int x = 0; x < xSize; x++) {
			printChar(page[x][y]);
		}
		cout << endl;
	}
}

void printKochamGosie() {
	printK(0, 0);
	printO(10, 0);
	printC(20, 0);
	printH(30, 0);
	printA(40, 0);
	printM(50, 0);
	printG(70, 0);
	printO(80, 0);
	printS(90, 0);
	printI(100, 0);
	printE2(110, 0);
	printPage();
}

int main() {
	int x = 0;
	while (x < 10) {
		printKochamGosie();
		usleep(1000000);
		system("clear");
		usleep(1000000);
		x++;
	}
	return 0;
}
