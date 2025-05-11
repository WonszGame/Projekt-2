// projektdos.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "projektdos.h"
using namespace std;

int main() {
	srand(time(0));
	array <bool, 12> present0;
	array <bool, 12> vert0;
	array <bool, 12> up0;
	present0.fill(false);
	vert0.fill(false);
	up0.fill(false);
	array <int, 12> distance0;
	distance0.fill(0);
	array <bool, 12> present;
	array <char, 12> planeId;
	array <bool, 12> vert;
	array <bool, 12> up;
	array <int, 12> distance;
	array <int, 12> x;
	array <int, 12> y;
	array <bool, 12> LR;
	planeId = { 'A','B','C','D','E','F','G','H','I','J','K','L' };

	for (int i = 0; i < 84; i++) {
		cout << '=';
	}
	cout << endl;
	for (int i = 0; i < 15; i++) {
		cout << "||";
		for (int j = 0; j < 16; j++) {
			cout << "     ";
		}
		cout << "||";
		cout << endl;
	}
	for (int i = 0; i < 84; i++) {
		cout << '=';
	}
	cout << endl;
	for (int i = 0; i < 12; i++) {
		array<bool, 15> picked;
		array<bool, 2> p2;
		picked.fill(false);
		p2.fill(false);
		int r = rand() % 10;
		if (r == 1) {
			present0.at(i) = true;
			bool test = true;
			while (test) {
				int start = rand() % 2;
				int start2 = rand() % 15;
				if (!picked.at(start2) && !p2.at(start)) {
					y.at(i) = start2;
					if (start == 1) {
						LR.at(i) = true;
					}
					else {
						LR.at(i) = false;
					}
					test = false;
				}
			}
		}

	}
	while (true) {
		char plane;
		int planenum;
		char n0;
		char n1;
		char move;
		int height;
		string command;
		bool collision = false;
		getline(cin, command);
		plane = command[0];
		if (plane >= 'A' && plane <= 'L') {
			planenum = plane - 'A';
			move = command[1];
			if (move == 'c') {
				vert0.at(planenum) = false;
				distance0.at(planenum) = 0;
			}
			else if (move == '/') {

				n0 = command[2];
				n1 = command[3];
				if (n0 >= '0' && n0 <= '9') {
					if (n1 >= '0' && n1 <= '9') {
						height = (n0 - '0') * 10 + (n1 - '0');
					}
					else {
						height = n0 - '0';
					}
					if (height <= x.at(planenum)) {
						distance0.at(planenum) = height;
						vert0.at(planenum) = true;
						up0.at(planenum) = true;
					}
					else {
						cout << "wprowadź poprawną wartość" << endl;
					}
				}
				else {

					cout << "wprowadź poprawną wartość" << endl;
				}
			}
			else if (move == '\\') {
				n0 = command[2];
				n1 = command[3];
				if (n0 >= '0' && n0 <= '9') {
					if (n1 >= '0' && n1 <= '9') {
						height = (n0 - '0') * 10 + (n1 - '0');
					}
					else {
						height = n0 - '0';
					}
					if (height <= 15 - x.at(planenum)) {
						distance0.at(planenum) = height;
						vert0.at(planenum) = true;
						up0.at(planenum) = false;
					}
					else {
						cout << "wprowadź poprawną wartość" << endl;
					}
				}
				else {

					cout << "wprowadź poprawną wartość" << endl;
				}
			}
			else {
				cout << "wprowadź poprawną wartość" << endl;
			}
		}
		else if (plane == ' ') {
			for (int i = 0; i < 12; i++) {
				if (!present0.at(i)) {
					array<bool, 15> picked;
					array<bool, 2> p2;
					picked.fill(false);
					p2.fill(false);
					int r = rand() % 10;
					if (r == 1) {
						present0.at(i) = true;
						bool test = true;
						while (test) {
							int start = rand() % 2;
							int start2 = rand() % 15;
							if (!picked.at(start2) && !p2.at(start)) {
								y.at(i) = start2;
								if (start == 1) {
									LR.at(i) = true;
								}
								else {
									LR.at(i) = false;
								}
								test = false;
							}
						}
					}
				}
				if (present.at(i)) {
					if (LR.at(i)) {
						x.at(i)++;
					}
					else {
						x.at(i)--;
					}
					if (x.at(i) < 0 || x.at(i) > 15) {
						present.at(i) = false;
						present0.at(i) = false;
					}
					if (vert.at(i) && distance.at(i) > 0) {
						if (up.at(i)) {
							y.at(i)--;
						}
						else {
							y.at(i)++;
						}
						distance0.at(i)--;
					}
					if (distance.at(i) == 0) {
						vert.at(i) = false;
					}
				}

			}

			for (int i = 0; i < 84; i++) {
				cout << '=';
			}
			cout << endl;
			for (int i = 0; i < 15; i++) {
				bool b1 = false;
				char c1 = 0;
				for (int k = 0; k < 12; k++) {
					if (LR.at(k) && y.at(k) == i && !present.at(k) && present0.at(k)) {
						c1 = planeId.at(k);
						b1 = true;
						x.at(k) = -1;
					}
				}
				if (b1) {
					cout << c1;
				}
				else {
					cout << '|';
				}

				cout << '|';
				for (int j = 0; j < 16; j++) {
					int loc = 0;
					bool test = false;
					for (int k = 0; k < 12; k++) {
						if (y.at(k) == i && x.at(k) == j && present.at(k)) {
							test = true;
							loc = k;
						}
					}
					if (test) {
						if (LR.at(loc) == true) {
							if (vert.at(loc) == true) {
								if (up.at(loc) == true) {
									cout << '(' << planeId.at(loc) << distance.at(loc) << ")/";
								}
								else {
									cout << '(' << planeId.at(loc) << distance.at(loc) << ')' << '\\';
								}
							}
							else {
								cout << "=(" << planeId.at(loc) << distance.at(loc) << ')';
							}
						}
						else {
							if (vert.at(loc) == true) {
								if (up.at(loc) == true) {
									cout << '\\' << '(' << planeId.at(loc) << distance.at(loc) << ')';
								}
								else {
									cout << "/(" << planeId.at(loc) << distance.at(loc) << ')';
								}
							}
							else {
								cout << '(' << planeId.at(loc) << distance.at(loc) << ")=";
							}
						}
					}
					else {
						cout << "     ";
					}
				}
				bool b2 = false;
				char c2 = 0;
				cout << '|';
				for (int k = 0; k < 12; k++) {
					if (!LR.at(k) && y.at(k) == i && !present.at(k) && present0.at(k)) {
						c2 = planeId.at(k);
						b2 = true;
						x.at(k) = 16;
					}
				}
				if (b2) {
					cout << c2;
				}
				else {
					cout << '|';
				}
				cout << endl;

			}
			for (int i = 0; i < 84; i++) {
				cout << '=';
			}
			cout << endl;
			present = present0;
			vert = vert0;
			up = up0;
			distance = distance0;

		}
		else {

			cout << "wprowadź poprawną wartość" << endl;
		}

		for (int i = 0; i < 11; i++) {
			if (present.at(i)) {
				for (int j = i + 1; j < 12; j++) {
					if (present.at(j)) {
						if (y.at(i) == y.at(j)) {
							if (LR.at(i) != LR.at(j)) {
								int p;
								int q;
								p = x.at(i);
								q = x.at(j);
								if (p == q || p == q - 1 || p == q + 1) {
									collision = true;
									break;

								}
							}
						}
					}
				}
			}
		}
		if (collision) {
			break;
		}

	}

	return 0;
}