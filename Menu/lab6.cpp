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
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
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

	int c, curs;
	int nx, ny, nbx = 24, nby = 0, nex = 64, ney = 14;
	unsigned int Bit = 0b1000'0000'0000'0000'0000'0000'0000'0000;
void lab6() {
	system("cls");
	for (ny = 0; ny < 32; ny++) {
		for (nx = 0; nx < 32; nx++) {
			if ((Bit >> nx) & map[ny]) {
				SetColor(7, 7);
				cout << "WW";
			}
			else {
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
				if (!end(nx, ny - 1, nex, ney) and !wall(nx, ny - 1, map))
					ny -= 1; break;
			case 80:
				if (!end(nx, ny + 1, nex, ney) and !wall(nx, ny + 1, map))
					ny += 1; break;
			case 75:
				if (!end(nx - 1, ny, nex, ney) and !wall(nx - 1, ny, map))
					nx -= 1; break;
			case 77:
				if (!end(nx + 1, ny, nex, ney) and !wall(nx + 1, ny, map))
					nx += 1; break;
			}
		}
		else {
			switch (c) {
			case 119:
				if (!end(nx, ny - 1, nex, ney) and !wall(nx, ny - 1, map))
					ny -= 1; break;
			case 115:
				if (!end(nx, ny + 1, nex, ney) and !wall(nx, ny + 1, map))
					ny += 1; break;
			case 97:
				if (!end(nx - 1, ny, nex, ney) and !wall(nx - 1, ny, map))
					nx -= 1; break;
			case 100:
				if (!end(nx + 1, ny, nex, ney) and !wall(nx + 1, ny, map))
					nx += 1; break;
			default:
				Beep(400, 50);
			}
		}
	} while (c != 27);
	system("cls");
	SetColor(0, 15);

}