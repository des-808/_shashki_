#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<locale>
#include<windows.h>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<ctime>
#include<stdlib.h>
#include<cstdlib>
#include <sstream>
#include <utility>

//using namespace System;

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::_Iosb;
using std::setw;
using std::pair;
using std::make_pair;

//using namespace std;

#define UP_ARROW	72
#define DOWN_ARROW	80
#define LEFT_ARROW  75
#define RIGHT_ARROW 77
#define SPACE  32
#define ENTER  13
#define ESCAPE  27
#define TAB '\t'

const char vertical_cherta = 179;
const char horizontal_cherta = 196;
const char ugol_l_up = 218;
const char ugol_l_down = 192;
const char ugol_r_up = 191;
const char ugol_r_down = 217;
const char probel = ' ';
const char teshka_down = 194;
const char teshka_up = 193;
const char teshka_left = 180;
const char teshka_right = 195;
const char krestik = 197;

pair<short, short> arrow(HANDLE output, short y, short x, const int row, const int column, const int zerro_pos_xx, const int zerro_pos_yy, const int step_xx, const int step_yy);
void fontSizeConsole(int L, CONSOLE_FONT_INFOEX fontInfo, HANDLE hConsole);

int main(void) {

	setlocale(LC_ALL, "Russian");

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

CONSOLE_FONT_INFOEX fontInfo;
const int kollvo_yacheek = 8;
const int zerro_pos_xx = 18;
const int zerro_pos_yy = 4;
const int step_xx = 14;
const int step_yy = 7;
int dl_yacheiki = 7;
const char probel = ' ';//176
const char black = ' ';
const char white = 178;// 219;//178;//0xDB;//153;178
const char vertical_cherta = 179;
const char horizontal_cherta = 196;
const char ugol_l_up = 218;
const char ugol_l_down = 192;
const char ugol_r_up = 191;
const char ugol_r_down = 217;
const char zapolnitel = 219;//'*';
short tmpX, tmpY, tmpOldX, tmpOldY, tmpXold, tmpYold, count;
tmpX = tmpY = tmpOldX = tmpOldY = tmpXold = tmpYold = count = 0;
bool game = true;
int old_shag = 0;
int new_shag = 0;
bool old_bool = true;
int temp = 0;
int digits_bytes[10][6]{ //10,7// Digits / Цифры 

		{0b00011000, 0b00100100, 0b00100100, 0b00100100, 0b00100100, 0b00011000 }, // Символ 48  <0> 
		{0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b00101000, 0b00011000 }, // Символ 49  <1> 
		{0b00111100, 0b00100000, 0b00010000, 0b00001000, 0b00100100, 0b00011000 }, // Символ 50  <2> 
		{0b00011000, 0b00100100, 0b00000100, 0b00001000, 0b00100100, 0b00011000 }, // Символ 51  <3> 
		{0b00000100, 0b00000100, 0b00011100, 0b00100100, 0b00010100, 0b00001100 }, // Символ 52  <4> 
		{0b00011000, 0b00100100, 0b00000100, 0b00011000, 0b00100000, 0b00111100 }, // Символ 53  <5> 
		{0b00011000, 0b00100100, 0b00100100, 0b00111000, 0b00100000, 0b00011000 }, // Символ 54  <6> 
		{0b00010000, 0b00010000, 0b00010000, 0b00001000, 0b00000100, 0b00111100 }, // Символ 55  <7> 
		{0b00011000, 0b00100100, 0b00100100, 0b00011000, 0b00100100, 0b00011000 }, // Символ 56  <8> 
		{0b00111000, 0b00000100, 0b00011100, 0b00100100, 0b00100100, 0b00011000 }  // Символ 57  <9> 
};

int chars_bytes[12][6]{
	// Roman Smalls / Латиница, строчные 
		{0b00001100, 0b00010010, 0b00011110, 0b00000010, 0b00010010, 0b00001100 }, // Символ 97  <a> 
		{0b00011100, 0b00010010, 0b00011010, 0b00010100, 0b00010000, 0b00010000 }, // Символ 98  <b> 
		{0b00001100, 0b00010010, 0b00010000, 0b00010010, 0b00001100, 0b00000000 }, // Символ 99  <c> 
		{0b00001010, 0b00010110, 0b00010010, 0b00001110, 0b00000010, 0b00000010 }, // Символ 100 <d> 
		{0b00001100, 0b00010010, 0b00010000, 0b00011100, 0b00010010, 0b00001100 }, // Символ 101 <e> 
		{0b00001000, 0b00001000, 0b00001000, 0b00011100, 0b00001000, 0b00000110 }, // Символ 102 <f> 
		{0b00001110, 0b00010000, 0b00001100, 0b00010010, 0b00010010, 0b00001100 }, // Символ 103 <g> 
		{0b00010010, 0b00010010, 0b00011010, 0b00010100, 0b00010000, 0b00010000 }, // Символ 104 <h> 
		{0b00011100, 0b00001000, 0b00001000, 0b00011000, 0b00000000, 0b00001000 }, // Символ 105 <i> 
		{0b00011000, 0b00000100, 0b00000100, 0b00011100, 0b00000000, 0b00000100 }, // Символ 106 <j> 
		{0b00010100, 0b00011000, 0b00011000, 0b00010100, 0b00010000, 0b00000000 }, // Символ 107 <k> 
		{0b00011100, 0b00001000, 0b00001000, 0b00001000, 0b00011000, 0b00000000 }  // Символ 108 <l> 
};

int shashki[8][8]{  {8,1,8,1,8,1,8,1},
					{1,8,1,8,1,8,1,8},
					{8,1,8,1,8,1,8,1},
					{0,8,0,8,0,8,0,8},
					{8,0,8,0,8,0,8,0},
					{2,8,2,8,2,8,2,8},
					{8,2,8,2,8,2,8,2},
					{2,8,2,8,2,8,2,8} };//стартовая таблица;

char shashki_white[7][14]{ {black,black,black,black,black,black,white,white,black,black,black,black,black,black},
							{black,black,black,black,white,white,white,white,white,white,black,black,black,black},
							{black,black,white,white,white,white,black,black,white,white,white,white,black,black},
							{black,white,white,white,white,black,black,black,black,white,white,white,white,black},
							{black,black,white,white,white,white,black,black,white,white,white,white,black,black},
							{black,black,black,black,white,white,white,white,white,white,black,black,black,black},
							{black,black,black,black,black,black,white,white,black,black,black,black,black,black} };

char shashki_black[7][14]{ {black,black,black,white,white,white,black,black,white,white,white,black,black,black},
							{black,black,white,white,black,black,black,black,black,black,white,white,black,black},
							{white,white,black,black,black,black,black,black,black,black,black,black,white,white},
							{black,black,black,black,black,black,black,black,black,black,black,black,black,black},
							{white,white,black,black,black,black,black,black,black,black,black,black,white,white},
							{black,white,white,white,black,black,black,black,black,black,white,white,black,black},
							{black,black,black,white,white,white,black,black,white,white,white,black,black,black} };

char shashki_white_damka[7][14]{ {black,black,black,black,black,black,white,white,black,black,black,black,black,black},
								{black,black,black,black,white,white,black,black,white,white,black,black,black,black},
								{black,black,white,white,white,black,black,black,black,white,white,white,black,black},
								{black,white,white,white,black,black,white,white,black,black,white,white,white,black},
								{black,black,white,white,white,black,black,black,black,white,white,white,black,black},
								{black,black,black,black,white,white,black,black,white,white,black,black,black,black},
								{black,black,black,black,black,black,white,white,black,black,black,black,black,black} };

char shashki_black_damka[7][14]{ {black,black,black,white,white,white,black,black,white,white,white,black,black,black},
								{black,black,white,white,black,black,black,black,black,black,white,white,black,black},
								{white,white,black,black,black,black,white,white,black,black,black,black,white,white},
								{black,black,black,black,black,white,black,black,white,black,black,black,black,black},
								{white,white,black,black,black,black,white,white,black,black,black,black,white,white},
								{black,white,white,white,black,black,black,black,black,black,white,white,black,black},
								{black,black,black,white,white,white,black,black,white,white,white,black,black,black} };

int mask, simvol, outs;
HANDLE output;
output = GetStdHandle(STD_OUTPUT_HANDLE);

do {

	setlocale(LC_ALL, "C");
	SetConsoleCursorPosition(output, { 0, 0 });//для построения таблицы курсор устанавливаем в положение 0.0
	for (int i = 1; i < kollvo_yacheek + 4; i++) { cout << probel; } cout << ugol_l_up;//относительно 4. Два пробела в начале и 2 после цифры
	for (int i = 0; i < kollvo_yacheek * dl_yacheiki; i++) { cout << horizontal_cherta << horizontal_cherta; }cout << ugol_r_up << endl;
	mask = simvol = outs = 0;
	for (int i = 0, t = kollvo_yacheek; i < kollvo_yacheek; i++, t--) {//мега квадрат строк
		int c = 0;
		for (int x = 0, j = 6; x < dl_yacheiki; x++, j--) {// строка квадратов
			simvol = (j > 5) ? 0 : digits_bytes[t][j];
			mask = 128;//маска для вычисления ненулевого байта
			cout << probel << probel;//Отступ перед цифрой
			for (int n = dl_yacheiki; n != 0; n--) {
				outs = simvol & mask; mask = mask >> 1; cout << ((outs) ? zapolnitel : probel);//преобразует байт в пробелы и заполнители 	
			}// в данном случае пишем цифры построчно относительно таблицы
			cout << probel << probel;//Отступ после цифры
			cout << vertical_cherta;//полоса в начале строки
			for (int z = 0; z < kollvo_yacheek; z++) {//строка
				if ((i + z) % 2 == 0) {
					for (int r = 0; r < dl_yacheiki; r++) { cout << zapolnitel << zapolnitel; }///белые клетки
				}
				else {
					//cout << ((c == 0)&& (k == (dl_yacheiki * 2)-1)&&tmpYold==z &&tmpXold==i ) ? white : shashki_white[c][k];//эта штука делает псевдовыделение при захвате шашки
					if (shashki[i][z] == 1) { for (int k = 0; k < dl_yacheiki * 2; k++) { cout << (((c == 0 || c == 6) && ((k == (dl_yacheiki * 2) - 1) || k == 0) && tmpYold == i && tmpXold == z) ? white : shashki_white[c][k]); } }
					else if (shashki[i][z] == 2) { for (int k = 0; k < dl_yacheiki * 2; k++) { cout << (((c == 0 || c == 6) && ((k == (dl_yacheiki * 2) - 1) || k == 0) && tmpYold == i && tmpXold == z) ? white : shashki_black[c][k]); } }
					else if (shashki[i][z] == 3) { for (int k = 0; k < dl_yacheiki * 2; k++) { cout << (((c == 0 || c == 6) && ((k == (dl_yacheiki * 2) - 1) || k == 0) && tmpYold == i && tmpXold == z) ? white : shashki_white_damka[c][k]); } }
					else if (shashki[i][z] == 4) { for (int k = 0; k < dl_yacheiki * 2; k++) { cout << (((c == 0 || c == 6) && ((k == (dl_yacheiki * 2) - 1) || k == 0) && tmpYold == i && tmpXold == z) ? white : shashki_black_damka[c][k]); } }
					//else if (shashki[i][z] == 8) {  }
					else if (shashki[i][z] == 0) { for (int s = 0; s < dl_yacheiki; s++) { cout << probel << probel; } }
					//else{}
				}
			}
			c++; //при каждом проходе инкрементируем строку массива считывания из символа
			cout << vertical_cherta; cout << endl;//полоса в конце строки
		}
	}
	for (int i = 1; i < kollvo_yacheek + 4; i++) { cout << probel; }cout << ugol_l_down;//относительно 4. Два пробела в начале и 2 после цифры
	for (int i = 0; i < kollvo_yacheek * dl_yacheiki; i++)cout << horizontal_cherta << horizontal_cherta;//полоса в низу мегаквадрата
	cout << ugol_r_down;
	cout << endl;

	int otstup_mezjdu_bukv = 7;
	mask, simvol, outs = 0;
	for (int j = 5; j >= 0; j--) {
		for (int i = 0; i <= 12; i++) { cout << probel; }
		for (int i = 0; i < kollvo_yacheek; i++) {
			simvol = chars_bytes[i][j];
			mask = 128;
			for (int i = 7; i != 0; i--) {
				outs = simvol & mask; mask = mask >> 1; cout << ((outs) ? zapolnitel : probel);//преобразует байт в пробелы и заполнители
			}
			for (int i = 0; i < otstup_mezjdu_bukv; i++) { cout << probel; }//Выводим отступы между буквами
		}cout << endl;
	}

	tmpOldX = tmpX; tmpOldY = tmpY;//сохраняем старые значения на случай неправильного выбора ячеек 
	//функция перемещает курсор по таблице и при нажатии ENTER возвращает позицию выбраной ячейки,принимает старое значение позиции что-бы курсор оставался в той же позиции
	//так же принимает размеры столбцов и ячеек,нулевые позиции по X и Y,и шаг перемещения по X и Y
	pair<short, short> mrvs = arrow(output, tmpY, tmpX, kollvo_yacheek, kollvo_yacheek, zerro_pos_xx, zerro_pos_yy, step_xx, step_yy);
	tmpY = mrvs.first; tmpX = mrvs.second;	//принимаем значения из функции 
	if (tmpY == 32767 || tmpX == 32767) { game = false; }//Если по Y = 32767 и X = 32767 то выход из пролграммы по ESCAPE
	else {//Продолжаем если не ESCAPE
		if (old_bool) { //выбор ячейки. если не ESCAPE продолжаем дальше
			if (shashki[tmpY][tmpX] == 0 || shashki[tmpY][tmpX] == 8) {//0 - пустая ячейка. 8 - белая ячейка
				old_shag = 0; new_shag = -1;// если ячейка пустая то ошибка
//old_bool = false;  
			}
			else {//ЗАХВАТ
				if (shashki[tmpY][tmpX] != 0) {//тут выбираем ячейку.Если ячейка нулевая захват не получится
					old_shag = shashki[tmpY][tmpX]; //выбор ячейки
					tmpYold = tmpY; tmpXold = tmpX;
					old_bool = false;
				}
			}
		}
		else { //Если после захвата шашки нажать на ту же шашку то захват снимется
			if (!old_bool && tmpY == tmpYold && tmpX == tmpXold) {
				old_shag = 0; new_shag = -1; tmpYold = 0; tmpXold = 0; old_bool = true;
			}
		}

		if (shashki[tmpY][tmpX] == 0) { new_shag = shashki[tmpY][tmpX]; old_bool = true; } //перенос ячейки
		else { new_shag = -1; }//Если клетка занята то ни чего не делаем
		if (old_shag != new_shag && new_shag == 0) {
			short proverka_X, proverka_Y;
			proverka_X = tmpX - tmpXold;
			proverka_Y = tmpY - tmpYold;
			//setlocale(LC_ALL, "Russian");
			//SetConsoleCursorPosition(output, { 0, 68 });
			//if (proverka_Y > 1 || proverka_X > 1 || proverka_Y < -1 || proverka_X < -1) { cout << "Error: шашки ходят на одну клетку " << endl;; }
			if ((proverka_Y == 2 && proverka_X == 2) || (proverka_Y == -2 && proverka_X == 2) ||
				(proverka_Y == 2 && proverka_X == -2) || (proverka_Y == -2 && proverka_X == -2))
			{
				(proverka_Y > 0) ? proverka_Y -= 1 : proverka_Y += 1;
				(proverka_X > 0) ? proverka_X -= 1 : proverka_X += 1;

				if ((old_shag != shashki[tmpYold + proverka_Y][tmpXold + proverka_X]) && (shashki[tmpYold + proverka_Y][tmpXold + proverka_X]) != 0) {
					shashki[tmpYold + proverka_Y][tmpXold + proverka_X] = 0;
				}
			}
			if (old_shag == 1 && tmpY == 7) { old_shag = 3; }//Если белая шака дошла до противоположного конца поля она становится белой дамкой
			if (old_shag == 2 && tmpY == 0) { old_shag = 4; }//Если чёрная шака дошла до противоположного конца поля она становится чёрной дамкой
			//if	  (proverka_Y < 0 && proverka_X > 0) { cout << "верх право                    ";/*shashki[tmpYold][tmpXold] = 0; shashki[tmpY][tmpX] = old_shag;*/ }
			//else if (proverka_Y < 0 && proverka_X < 0) { cout << "верх лево                     ";/*shashki[tmpYold][tmpXold] = 0; shashki[tmpY][tmpX] = old_shag;*/ }
			//else if (proverka_Y > 0 && proverka_X > 0) { cout << "низ правово                   ";/*shashki[tmpYold][tmpXold] = 0; shashki[tmpY][tmpX] = old_shag;*/ }
			//else if (proverka_Y > 0 && proverka_X < 0) { cout << "низ лево                      ";/*shashki[tmpYold][tmpXold] = 0; shashki[tmpY][tmpX] = old_shag;*/ }
			shashki[tmpYold][tmpXold] = 0;
			shashki[tmpY][tmpX] = old_shag;
			setlocale(LC_ALL, "Russian");
			SetConsoleCursorPosition(output, { 0, 64 });
			cout << "Y" << "        " << "X" << endl;
			cout << tmpYold << "        " << tmpXold << "        " << "Захват" << endl;
			cout << tmpY << "        " << tmpX << "        " << "Перенос" << endl;
			cout << tmpY - tmpYold << "        " << tmpX - tmpXold << "        ";
		}

	}

	/*setlocale(LC_ALL, "Russian");
	SetConsoleCursorPosition(output, { 0, 64 });*/
	//cout << endl << tmpY << TAB << tmpX;


} while (game);
SetConsoleCursorPosition(output, { 0, 64 });
cout << "THE END                                    " << endl;


system("pause");
}

pair<short, short> arrow(HANDLE output, short y, short x, const int row, const int column, const int zerro_pos_xx, const int zerro_pos_yy, const int step_xx, const int step_yy) {
	//int row = 3;//X               //  //int row = 8;//X 
	//int column = 3;//Y            //	//int column = 8;//Y 
	//short x = 1;                  //	//short x = 0;      
	//short y = 1;					//	//short y = 0;
	/*const int zerro_pos_xx = 3;   //	/*const int zerro_pos_xx = 18;
	const int zerro_pos_yy = 2;     //	const int zerro_pos_yy = 4;
	const int step_xx = 6;          //	const int step_xx = 14;
	const int step_yy = 4;*/        //	const int step_yy = 7;*/     
	short xx = zerro_pos_xx;//short xx = 3;// 3 =лево; 9 =центр; 15 = право;
	short yy = zerro_pos_yy;//short yy = 2;// 2 = нулевая строка; 6 = первая строка; 10 = вторая строка;
	for (int i = x; i != 0; i--) { xx += step_xx; }
	for (int j = y; j != 0; j--) { yy += step_yy; }
	int l = 0;
	SetConsoleCursorPosition(output, { xx, yy });//выводим курсор по координатам YY и XX
	while (l != ENTER && l != ESCAPE) {
		l = _getch();
		switch (l) {
		case UP_ARROW:		y--; yy -= step_yy; if (y == -1) { y = column - 1; yy = (y * step_yy) + zerro_pos_yy; }	break;//up
		case DOWN_ARROW:	y++; yy += step_yy; if (y == column) { y = 0;	   yy = zerro_pos_yy; }					break;//down
		case LEFT_ARROW:	x--; xx -= step_xx; if (x == -1) { x = row - 1;	   xx = (x * step_xx) + zerro_pos_xx; }	break;//left
		case RIGHT_ARROW:	x++; xx += step_xx; if (x == row) { x = 0;	   xx = zerro_pos_xx; }				break;//right
		case ESCAPE: x = 32767; y = 32767; break;
		case 224:break;
		default: break;
		}
		SetConsoleCursorPosition(output, { xx, yy });
	}
	return make_pair(y, x);
}

void fontSizeConsole(int L, CONSOLE_FONT_INFOEX fontInfo, HANDLE hConsole) {
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
	//wcscpy(fontInfo.FaceName, L"Lucida Console");
	fontInfo.dwFontSize.Y = L;
	SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
}