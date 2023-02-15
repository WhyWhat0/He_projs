#include"lab6.h"

int map[32] = {
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1110'1111'0001'1111'1111'1111'1111,
	0b1111'1110'1111'1101'1111'1111'1111'1111,
	0b1111'1110'1110'0001'1111'1111'1111'1111,
	0b1111'1110'0000'1111'1111'1111'1111'1111,
	0b1111'1110'1111'1111'1111'1111'1111'1111,
	0b1111'1100'1111'1111'1111'1111'1111'1111,
	0b1111'1101'1111'1111'1111'1111'1111'1111,
	0b1111'1100'0000'0000'0000'0000'0000'0000,
	0b1111'1111'1011'1111'1111'1111'1111'1111,
	0b1111'1111'1011'1111'1111'1111'1111'1111,
	0b1111'1111'1011'1111'1111'1111'1111'1111,
	0b1111'1111'1011'1111'1111'1111'1111'1111,
	0b1111'1111'1000'0000'1111'1111'1111'1111,
	0b1111'1111'1011'1111'1111'1111'1111'1111,
	0b1111'1111'1000'0000'0000'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111
};


int c, curs, col_ways = 0, i = 0;
int nx, ny;
int nbx = 24, nby = 0, nex = 64, ney = 14;
unsigned int Bit = 0b1000'0000'0000'0000'0000'0000'0000'0000;	

//int find_way(int nx, int ny) {
//	fout << nx << "  " << ny << endl;
//	if (nx == nex && ny == ney) {
//		return 1;
//	}
//	if (!((Bit >> nx + 1) & map[ny])) {
//		return find_way(nx + 1, ny);
//	}
//	if (!((Bit >> nx - 1) & map[ny])) {
//		return find_way(nx - 1, ny);
//	}
//	if (!((Bit >> nx) & map[ny + 1])) {
//		return find_way(nx, ny + 1);
//	}
//	if (!((Bit >> nx) & map[ny - 1])) {
//		return find_way(nx, ny - 1);
//	}
//	return 0;
//}

void lab6() {
	system("cls");
	for (ny = 0; ny < 32; ny++) {
		for (nx = 0; nx < 32; nx++) {
			if ((Bit >> nx) & map[ny]) {
				SetColor(7, 7);
				cout << "WW";
			}	
			else{
				col_ways++;
				SetColor(0, 15);
				cout << "  ";
			}
			 
			
		}
		cout << endl;
	}

	nx = nbx; ny = nby;
	do {
		move(nx, ny);
		c = _getch();
		if (c == 224) {
			curs = _getch();
			switch (curs) {
			case 72:
				ny -= 1;
				break;
			case 80:
				ny += 1;
				break;
			case 75:
				nx -= 1;
				break;
			case 77:
				nx += 1;
				break;
			}
			if (nx != nex && ny != ney) check_wall(nx, ny, map, curs);
		}
		else {
			switch (c) {
			case 119:
				ny -= 1; break;
			case 115:
				ny += 1; break;
			case 97:
				nx -= 1; break;
			case 100:
				nx += 1; break;

			default:
				Beep(400, 50);
			}
			if (nx != nex && ny != ney) check_wall(nx, ny, map, c);
		}
	} while (c != 27 && !end(nx, ny, nex, ney));
	SetColor(0, 15);
	system("cls");

}