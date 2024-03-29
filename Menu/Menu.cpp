﻿#include "Header.h" //Заголовки функций для лабораторных работ

int main(){
	system("color F0");
	uchar i; // для выбора пункта меню
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		system("cls"); // очистка экрана
		cout << "Основное меню программы\n\n";
		cout << "Выберите лабораторную работу из:\n\n";
		cout << "i) Сведения о программисте\n\n";
		cout << "1) 1 семестр\n\n";
		cout << "2) Битовая маска\n\n";
		cout << "3) Лабиринт\n\n";
		cout << "4) Рекурсия\n\n";
		cout << "5) Макросы\n\n";
		cout << "6) Шифрование\n\n";
		cout << "7) Сортировка массива строк\n\n";
		cout << "8) Классы\n\n";
		cout << "0) Выход из программы \n\n";
		i = _getch();
		system("cls");
		switch (i){ // управление выбором в меню
		case 'i':
			cout << "Выполнил студент группы 1бИТС2 Долгов Семен Вадимович"; _getch();
			system("cls");
			break;
		case '1':
			menu1(); break;			
		case '2':
			lab5(); break;
		case '3':
			lab6(); break;
		case '4':
			RecMenu(); break;
		case '5':
			lab_macros(); break;
		case '6':
			CordingMenu(); break;
		case '7':
			LabSort(); break;
		case '8':
			ClassesMenu(); break;
		case '0':
			return 0;
		default:
			cout << "Ошибочный ввод. Нажмите любую кнопку для продолжения...";
			_getch();			

		}		
	}
} 


int menu1() {
	while (true) {
		system("cls");
		cout << "Меню лабораторных работ\n\n";
		cout << "Выберите лабораторную работу:\n\n";
		cout << "1) Задание 2.1 Вычисления с выбором формул \n\n";
		cout << "2) Задание 2.2. Анализ данных и принятие решения\n\n";
		cout << "3) Задание 3.1 Обработка одномерных массивов (типовая)\n\n";
		cout << "4) Задание 3.2 Обработка одномерных массивов: с ветвлением алгоритма\n\n";
		cout << "5) Задание 4. Обработка матриц 6X6\n\n";
		cout << "0) Выход в главное меню \n\n";

		uchar i;
		i = _getch();
		system("cls");
		switch (i) {
		case '1':
			lab2_1(); break;
		case '2':
			lab2_2(); break;
		case '3':
			lab3_1(); _getch(); break;
		case '4':
			lab3_2(); break;
		case '5':
			lab4(); break;
		case '0':
			return 0;
		default:
			cout << "Ошибочный ввод. Нажмите любую кнопку для продолжения...";
			_getch();
		}
	}
}

