#include"lab10.h"

CEllipse::CEllipse() : CFigure() {
	BrushColor(RGB(255, 255, 0)); //���� �������
	SetName("CEllipse");

}

CEllipse::CEllipse(int pnx, int pny, int pnWidth, int pnHeight) : CFigure(pnx, pny, pnWidth, pnHeight) {
	BrushColor(RGB(255, 255, 0)); //���� �������
	SetName("CEllipse");
}
CEllipse::CEllipse(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor)
	: CFigure(pnx, pny, pnWidth, pnHeight, pbrushcolor, ppencolor) {
	SetName("CEllipse");
}
void CEllipse::Draw() {
	HWND hwnd = GetConsoleWindow();
	LOGBRUSH lpBrush;
	lpBrush.lbStyle = BS_SOLID;
	lpBrush.lbColor = BrushColor();


	HDC hdc = GetDC(hwnd);

	HBRUSH hbrush = CreateBrushIndirect(&lpBrush);
	SelectObject(hdc, hbrush);

	HPEN hpen = CreatePen(PS_SOLID, 2, PenColor());
	SelectObject(hdc, hpen);

	//HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 258, 255)), //pink
	//	pen2 = CreatePen(PS_SOLID, 2, RGB(0, 255, 0)), //green
	//	pen3 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)), //red
	//	pen4 = CreatePen(PS_SOLID, 2, RGB(255, 255, 0)); //yellow
	//LOGBRUSH Igbr{ PS_SOLID, RGB(78, 78, 78), 0 };
	//HBRUSH brush = CreateBrushIndirect(&Igbr);
	//SelectObject(hdc, pen2);
	//SelectObject(hdc, brush);

	Ellipse(hdc, Left(), Top(), Right(), Bottom());
	string text = to_string(ID());
	TextOutA(hdc, MiddleX(), MiddleY(), text.c_str(), text.length());
	DeleteObject(hbrush);
	DeleteObject(hpen);
	ReleaseDC(hwnd, hdc);
}