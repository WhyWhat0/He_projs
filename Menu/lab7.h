#pragma once
#include "Header.h"



typedef struct _stRecItem{
	int IdSet; // ������ ������ ������
	double value1, //�������� 1
		value2; // �������� 2

	_stRecItem() : IdSet(0), value1(0), value2(0) {}
	_stRecItem(int pID, double pValue1, double pValue2) : IdSet(pID), value1(pValue1), value2(pValue2) {}

}stRecItem, *pstRecItem;

typedef struct _stRecursion {
	int count;	//��������� ��������� �������� � ������ ������
	pstRecItem setRec; // ������ ��������

	_stRecursion(): count(0), setRec(NULL){}
	_stRecursion(int pCount) { setRec = new stRecItem[count]; }
	~_stRecursion() { delete[] setRec; }

	int AddItem(int pID, double pValue1, double pValue2) { //�������� � ����� ����� ����� ������
		count++;
		setRec = (pstRecItem)realloc(setRec, sizeof(stRecItem) * count); //������� ����� ����� ������

		setRec[count - 1].IdSet = pID;
		setRec[count - 1].value1 = pValue1;
		setRec[count - 1].value2 = pValue2;
		return count;
	}
	void Clear() {
		count = 0;
		if (setRec != NULL) { free(setRec); setRec = NULL; }
	}
	int SetCount(int pCount) {
		Clear();
		count = pCount;
		setRec = new stRecItem[pCount];
		return count;
	}

}stRecursion, *pstRecursion;

typedef struct stRect {
	uint Left,
		Top,
		Width,
		Height;
	stRect() : Left(0), Top(0), Width(0), Height(0) {}
	stRect(uint pLeft, uint pTop) : Width(0), Height(0), Left(pLeft), Top(pTop) {}
	stRect(uint pLeft, uint pTop, uint pWidth, uint pHeight) :
		Left(pLeft), Top(pTop), Width(pWidth), Height(pHeight) {}
	uint Bottom() { return Top + Height; }
	uint Right() { return Left + Width; }

}stRECT, *pstRECT;
void lab7(bool pause = true);
void lab7_graf();
void DrawGraf(const stRect prect, stRecursion& pRecData);