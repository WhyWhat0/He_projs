#include"lab6.h"

int map[32] = {
	0b1111'1111'1111'0111'1111'1111'1111'1111,//0
	0b1111'1111'1111'0111'1111'1111'1111'1111,//1
	0b1111'1111'1111'0000'0000'0000'0000'1111,//2
	0b1111'1111'1111'1111'1111'1111'1110'1111,//3
	0b1111'1111'1111'1111'1111'1111'1110'1111,//4
	0b1111'1111'0000'0001'1111'1111'1110'1111,//5
	0b1111'1111'1111'1101'1111'1111'1110'1111,//6
	0b1111'1110'1111'1101'1111'0000'0000'1111,//7
	0b1111'1110'1111'1101'1111'1110'1110'1111,//8
	0b1111'1110'1110'0000'0000'0000'0000'1111,//9
	0b1000'0000'0000'1111'1110'1111'1111'1111,//10
	0b1111'1110'1111'1111'1110'1111'1111'1111,//11
	0b1111'1100'1111'1111'1110'1111'1111'1111,//12
	0b1111'1101'1111'1111'1110'1111'1111'1111,//13
	0b1000'0000'0000'0000'0000'0000'0000'0011,//14
	0b1111'1111'1011'1111'1111'1111'1111'1111,//15
	0b1111'1111'1011'1111'1111'1111'1111'1111,//16
	0b1111'0000'0011'1111'1111'1111'1111'1111,//17
	0b1111'1111'1011'1111'1111'1111'1111'1111,//18
	0b1111'1111'1000'0000'0000'0000'1111'1111,//19
	0b1111'1111'1011'1111'1111'1110'1111'1111,//20
	0b1111'1111'1000'0000'0000'1110'1111'1111,//21
	0b1111'1111'1101'1111'1111'1110'1111'1111,//22
	0b1111'0000'0000'0000'0000'0000'1111'1111,//23
	0b1111'0111'1111'1111'1110'1111'1111'1111,//24
	0b1111'0111'1111'1111'1110'1110'1111'1111,//25
	0b1111'0111'1111'1111'1110'1110'1111'1111,//26
	0b1111'0111'1111'1111'1110'0000'1111'1111,//27
	0b1111'0111'1111'1111'1111'1110'1111'1111,//28
	0b1111'0111'1111'1111'1111'1110'1111'1111,//29
	0b1111'0000'0001'1111'1111'1111'1111'1111,//30
	0b1111'1111'1101'1111'1111'1111'1111'1111 //31
};



int c, curs, col_ways = 1, i = 0;
int nx, ny;
const int nbx = 12, nby = 0, nex = 10, ney = 31;
uint Bit = 0b1000'0000'0000'0000'0000'0000'0000'0000;	
const int Rows = 32, Cols = 32;
void lab6() {
	system("cls");
	for (ny = 0; ny < Rows; ny++) {
		for (nx = 0; nx < Cols; nx++) {
			if ((Bit >> nx) & map[ny]) {
				SetColor(7, 7);
				cout << "WW";
			}	
			else if (nx == nex && ny == ney) {
				SetColor(4, 4);
				cout << "  ";
			} 
			else{
				col_ways++;
				SetColor(0, 15);
				cout << "  ";
			}
			 
			
		}
		cout << endl;
	}
	uint* visited = new uint[col_ways];
	nx = nbx; ny = nby;
	do {
		move(nx, ny);
		c = _getch();
		if (c == 224) {
			curs = _getch();
			switch (curs) {
			case 72:
				if (((Bit >> nx) & map[ny - 1]) || edge(nx, ny - 1, Cols, Rows)) Beep(400, 100); else ny -= 1;
				break;
			case 80:
				if (((Bit >> nx) & map[ny + 1]) || edge(nx, ny + 1, Cols, Rows)) Beep(400, 100); else ny += 1;
				break;
			case 75:
				if (((Bit >> nx - 1) & map[ny]) || edge(nx - 1, ny, Cols, Rows)) Beep(400, 100); else nx -= 1;
				break;
			case 77:
				if (((Bit >> nx + 1) & map[ny]) || edge(nx + 1, ny, Cols, Rows)) Beep(400, 100); else nx += 1;
				break;
			}
		}
		else {
			switch (c) {
			case 119:
				if (((Bit >> nx) & map[ny - 1]) || edge(nx, ny - 1, Cols, Rows)) Beep(400, 100); else ny -= 1;
				break;
			case 115:
				if (((Bit >> nx) & map[ny + 1]) || edge(nx, ny + 1, Cols, Rows)) Beep(400, 100); else ny += 1;
				break;
			case 97:
				if (((Bit >> nx - 1) & map[ny]) || edge(nx - 1, ny, Cols, Rows)) Beep(400, 100); else nx -= 1;
				break;
			case 100:
				if (((Bit >> nx + 1) & map[ny]) || edge(nx + 1, ny, Cols, Rows)) Beep(400, 100); else nx += 1;
				break;
			default:
				Beep(400, 50); break;
			}
		}
		
	} while (c != 27 && !((nx == nex) && (ny == ney)));
	ofstream f("text.txt");
	for (int i = 0;i<sizeof(visited); i ++) f << visited[i] << endl; f.close();
	if (c == 27) {
		find_way(nx, ny, visited, map, col_ways, nex, ney);
		//mark(visited, nex, ney);
		_getch();
		SetColor(0, 15);
		system("cls");
	}
	else {
		SetColor(5, 15);
		system("cls");
		cout << "Easy win!!!" << endl;
		SetColor(0, 15);
		_getch();
	}
}