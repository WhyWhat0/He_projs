#include "Header.h"
#include "lab7.h"


int _max(int a, int b, int c, int& k) { 
	int m;
	if (a > b) {
		m = a;k = 1;
	}
	else {
		m = b;k = 2;
	}
	if (c > m) {
		m = c;k = 3;
	}
	return m;
}
int _min(int a, int b, int c, int& k) { 
	int m;
	if (a < b) {
		m = a;k = 1;
	}
	else {
		m = b;k = 2;
	}
	if (c < m) {
		m = c;k = 3;
	}
	return m;
}

float f(float a, float x, float k) { //������� ���������� �������� Y
	if (x < k * a) {
		return -pow(abs(16 * pow(a, 2) + 4 * pow(a, 2) \
			* pow(x + a, 2)), 0.5) - pow(x + a, 2) - pow(a, 2);
	}
	return pow(abs(pow(a, 2) - (x + pow(a, 2))), 0.5) - 2 * a;
}

void lab2_1()
{
	float b1 = 0, b2 = 0, b3 = 0;
	int i1 = 0, i2 = 0, a = 1; //������� ����������
	cout << "\n�������������� �������� � ������� ������\n" << endl;
	cout << "\n������� ������ � ���� ���� ����� ����� � ��������� ����������� � ������������ �����, � ����� �� �������,\
	\n��������� ������� �������� ���� �����, � ����� ���������� � ����������� ���� ����� �� ��������:\n" << endl;
	cout << "\n������� ������ �����: ";
	cin >> b1;
	cout << "\n������� ������ �����: ";
	cin >> b2;
	cout << "\n������� ������ �����: ";
	cin >> b3;
	if (b1 == b2 && b2 == b3) {
		cout << "��� �������";
		exit(1);
	}
	//����� ������ 
	cout << "�����:" << endl;
	float bmin = _min(b1, b2, b3, i1);
	cout << "bmin = " << bmin << ", index = " << i1 << endl;
	float bmax = _max(b1, b2, b3, i2);
	cout << "bmax = " << bmax << ", index = " << i2 << endl;
	float bmid = (b1 + b2 + b3) / 3;
	cout << "b������� = " << round(bmid * 100) / 100 << endl;
	float d = bmax - bmin;
	float d1 = abs(b1 - bmid); float d1_c = d1 / (bmax - bmin) * 100;
	cout << "���������� � ����������� b1 �� ��������: " << round(d1 * 100) / 100 << ", " << round(d1_c * 100) / 100 << "%" << endl;
	float d2 = abs(b2 - bmid); float d2_c = d2 / (bmax - bmin) * 100;
	cout << "���������� � ����������� b2 �� ��������: " << round(d2 * 100) / 100 << ", " << round(d2_c * 100) / 100 << "%" << endl;
	float d3 = abs(b3 - bmid); float d3_c = d3 / (bmax - bmin) * 100;
	cout << "���������� � ����������� b3 �� ��������: " << round(d3 * 100) / 100 << ", " << round(d3_c * 100) / 100 << "%" << endl;
	_getch();
}
void lab2_2()
{
	int C, F, H;
	int a = 1; // �������� ��������� ���������
	cout << "\n�������������� �������� � �������� �������� ������ � �������� �������\n";
	cout << "\n���� �� ����� ���� ����� �����, ������� ����� �������� �������� ���� ������.\n���� ��, �� �������� ��� �����\n";
	while (a == 1) { // ���� ������� ������� ���������
		cout << "\n������� ������ � ���� ���� ����� �����:\n";
		cout << "\n������� ������ �����: ";
		cin >> C;
		cout << "\n������� ������ �����: ";
		cin >> F;
		cout << "\n������� ������ �����: ";
		cin >> H;
		if (C == F && F == H) {
			cout << "��� ���������" << endl;
		}
		//����� ������ � ����������� �� �������
		else if (C == pow(F - H, 2)) {
			cout << "������� �������� ����� " << C << endl;
		}
		else if (F == pow(C - H, 2)) {
			cout << "������� �������� ����� " << F << endl;
		}
		else if (H == pow(C - F, 2)) {
			cout << "������� �������� ����� " << H << endl;
		}
		else {
			cout << "��� ��������������� ������� �����" << endl;
		}
		cout << endl << "������ ����������?" << endl << "��: ������� 1" << endl << "���: ������� 0" << endl;
		cin >> a;
		if (a == 0) cout << endl << "��������� ��������� ������.";
	}
	_getch();
}

void lab3_1()
{
	cout << "����������� �������� � ����������� ����������� � ��������� �������\n\n";
	cout << "�������� � ������� N �������� �������:\n\n";
	cout << "-sqrt(|16 * a^2 + 4 * a^2 * (x + a)^2)|) - (x+a)^2 - a^2, ���� x < k * a\n";
	cout << " sqrt(|a^2 - (x + a^2)|) - 2 * a, ���� x >= k*a\n";
	cout << "\n������� ����� N" << endl;
	float a, k;
	unsigned int n;
	cin >> n;
	cout << "\n������� ����� A:" << endl;
	cin >> a;
	cout << "\n������� ����� K:" << endl;
	cin >> k; cout << endl;


	// ���������� ��������� ��������
	float x = a * (-2.2);
	float dx = 0.4;
	//����� ������
	cout << right << "N" << setw(10) << "X" << setw(10) << "Y" << endl;
	for (int i = 0; i < 27; i++) {
		cout << "_";
		if (i == 26) cout << endl;
	}
	RecData.SetCount(0);
	RecData.model = mod_An_Y;
	for (int i = 0; i < n; i++) {
		RecData.AddItem(n, x, f(a, x, k));
		x = x + dx;
		if (n == 11) x = 0;
		cout << right << i+1 << setw(10) << x << setw(15) << f(a, x, k) << endl;
	}
}
void lab3_2()
{
	int  i = 0;
	float sum = 0, A, y[12], F[sizeof(y)];
	cout << "����������� �������� ��������� ����������� �������" << endl;
	cout << "\n������� ������ ������� A � ���� ����� ����� ��� ����������� ������ ������� B,\n��� Bi = sum(A) + 2*Ai ���� Ai > 2,\n� ��������� ������ Bi = sum(A) + 3*Ai, \
��� sum(A) - ����� ��������� ������ �������:\n\n " << endl;
	cout << "������� ��� ������: ������ ���������� ������� ������ ���� ������ �������� ����� ������������� � ������������ �������� �������\n\n";
	sum = 0;
	for (i = 0;i < 12;i++) {
		do { //�������� �� ��������� �������� ����
			cout << "\n������� ��������� ��������" << i + 1 << "/12 �����" << endl;
			cin >> y[i];
		} while (y[i] == 0);
		sum += (1 - y[i]) / pow(y[i], 2); // ����� ��������� ������� y      
	}
	sum = round(sum * 100) / 100;
	for (i = 0; i < 12; i++) {// ���������� ������ �������
		A = y[i] > 2 ? 3 : 2;
		F[i] = sum + A * y[i];
	}
	int Fmin = F[0], Fmax = F[0];
	for (i = 1;i < 12;i++) { // ���������� ������������� � ������������ �������� � �������
		Fmin = Fmin < F[i] ? Fmin : F[i];
		Fmax = Fmax > F[i] ? Fmax : F[i];
	}
	cout << "\n����� ������ F: ";
	for (i = 0;i < 12;i++) { //����� ������� F
		cout << F[i] << " ";
	}
	unsigned int l = 0; //������ ������� F ������� �������
	cout << endl << "\n������� �������: ";
	for (i = 0;i < 12;i++) { //����� ������� F ������� �������
		if (F[i] <= (Fmin + Fmax) / 2) {
			l++;
			cout << F[i] << " ";
		}
	}
	cout << endl << "\n���������� �����, ������������� ��������: " << l;
	_getch();
}
void lab4()
{
	const int ROW = 6, COL = 6;
	cout << "����������� ��������� ��������� �������\n(���� ������������ ��������� ������� ������� ������ ��� ����� 0, �� ����� ������� ����������� ������) " << endl;
	
	float x[ROW][COL]; //�������� �������
	bool ch[COL]; //������ ��� �������� ������� ���������� ��������
	int i, j, count, prod;
	cout << "��������� ������� �������� " << ROW << "x" << COL << endl;
	for (j = 0;j < COL;j++) {
		ch[j] = false;
	}
	//���� �������
	for (i = 0;i < ROW;i++) {
		for (j = 0;j < COL;j++) {
			cin >> x[i][j];
		}
	}
	//����� �������� �������
	cout << endl << "����������" << endl << endl;
	cout << "�������� �������" << endl;
	for (i = 0;i < ROW;i++) {	// ����� ����������� �������
		for (j = 0;j < COL;j++) {
			cout << right << setw(6) << x[i][j];
		}
		cout << endl;
	}
	cout << endl;
	//���������� ��������
	for (j = 1;j < COL;j += 2) {
		prod = 1; count = 0;
		for (i = 0;i < ROW;i++) {
			if (x[i][j] < 0) {
				count++;
				prod *= x[i][j];
			}
		}

		cout << "������������ � ���������� ������������� ����� ������� " << j + 1 << ": " << prod << " " << count << endl << endl;
		if (prod < 0) ch[j] = true;
	}
	//����� ���������� ��������
	cout << "������� �� ������ -> ������ ���������� ��������: "; //����� ������� ���������� ��������
	for (j = 0;j < COL;j++) {
		if (ch[j]) cout << j + 1 << " ";
	}
	cout << endl;
	//����� �������� �������
	for (i = 0;i < ROW;i++) {
		for (j = 0;j < COL;j++) {
			if (ch[j]) x[i][j] = 0;
			cout << right << setw(6) << x[i][j];
		}
		cout << endl;
	}
	_getch();
}