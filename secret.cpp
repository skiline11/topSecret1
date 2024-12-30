#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<unistd.h>

using namespace std;

int xSize = 100, ySize = 100;
char mark = 'X';
char page[100][100];

// ..XXXXX
// ..X   X
// ..XXXXX
// ..X   X
// ..X   X

// ..XXXXX
// ..X
// ..X  XX
// ..X   X
// ..XXXXX

void printA(int startX, int startY) {
	for (int i = 0; i < 5; i++) {
		page[startX + i][startY] = mark;
		page[startX + i][startY + 2] = mark;
		page[startX][startY + i] = mark;
		page[startX + 4][startY + i] = mark;
	}
}

void printG(int startX, int startY) {
	for (int i = 0; i < 5; i++) {
		page[startX + i][startY] = mark;
		page[startX][startY + i] = mark;
		page[startX + i][startY + 4] = mark;
	}
	page[startX + 3][startY + 2] = mark;
	page[startX + 4][startY + 2] = mark;
	page[startX + 4][startY + 3] = mark;
}

void printO(int startX, int startY) {
	for (int i = 0; i < 5; i++) {
		page[startX + i][startY] = mark;
		page[startX + i][startY + 4] = mark;
		page[startX][startY + i] = mark;
		page[startX + 4][startY + i] = mark;
	}
}

void printS(int startX, int startY) {
	for (int i = 0; i < 5; i++) {
		page[startX + i][startY] = mark;
		page[startX + i][startY + 2] = mark;
		page[startX + i][startY + 4] = mark;
	}
	page[startX][startY + 1] = mark;
	page[startX + 4][startY + 3] = mark;
}

void printI(int startX, int startY) {
	for (int i = 0; i < 5; i++) {
		page[startX + i][startY] = mark;
		page[startX + 1][startY + i] = mark;
		page[startX + 2][startY + i] = mark;
		page[startX + 3][startY + i] = mark;
		page[startX + i][startY + 4] = mark;
	}
}


void printChar(char x) {
	if (x == '\0') {
		cout << " ";
	} else cout << x;
}

void printPage() {
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < xSize; x++) {
			printChar(page[x][y]);
		}
		cout << endl;
	}
	cout << "------------------------------------------------------" << endl;
}

void printGosia() {
	system("clear");
	printG(0, 0);
	printO(10, 0);
	printS(20, 0);
	printI(30, 0);
	printA(40, 0);
	printPage();
}

int main() {
	int x = 0;
	while (x < 10) {
		printGosia();
		usleep(1000000);
		system("clear");
		usleep(1000000);
		x++;
	}
	return 0;
}
