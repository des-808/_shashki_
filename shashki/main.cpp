#include"Header.h"

#define UP_ARROW	72
#define DOWN_ARROW	80
#define LEFT_ARROW  75
#define RIGHT_ARROW 77
#define SPACE  32
#define ENTER  13
#define ESCAPE  27
#define TAB '\t'

const char teshka_down = 194;
const char teshka_up = 193;
const char teshka_left = 180;
const char teshka_right = 195;
const char krestik = 197;
const int  zerro_pos_xx = 18;
const int  zerro_pos_yy = 5;
const int  step_xx = 14;
const int  step_yy = 7;
const int  dl_yacheiki = 7;
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
const int  kollvo_yacheek = 8;

void print(int i, int SIZE, char ch);
void print(int i, int SIZE, char ch0, char ch1);
void print(HANDLE output, short x, short y, string s); 
void arrow(HANDLE output, short& y, short& x, const int row, const int column, const int zerro_pos_xx, const int zerro_pos_yy, const int step_xx, const int step_yy,int& tmpVspomogatelnaya);
template<typename T>void proverka_kletok(T& proverka_Y, T& proverka_X);
short proverka_kletok_X(short proverka_X);
short proverka_kletok_Y(short proverka_Y);
void fontSizeConsole(int L, CONSOLE_FONT_INFOEX fontInfo, HANDLE hConsole);
void print_step(HANDLE output, short tmpYold, short tmpXold, short tmpY, short tmpX, short stepperY, short stepperX);

int main(void) {
	setlocale(LC_ALL, "Russian");
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_FONT_INFOEX fontInfo;
short tmpX, tmpY, tmpOldX, tmpOldY, tmpXold, tmpYold, count;
tmpX = tmpY = tmpOldX = tmpOldY = tmpXold = tmpYold = count = 0;
bool game = true;
bool peremeshenie = true;
bool hod = true;//true-ходят белые. false-ходят чёрные
int old_shag = 0;
int new_shag = 0;
bool old_bool = true;
int temp = 0;
int tmpVspomogatelnaya = 0;//через эту переменную будут передаваться комманды SPACE,или ESCAPE и возможно что-то ещё
int mask, simvol, outs;
bool smena_hoda = false;// true;
int stepperX, stepperY;//сделал для просчета клеток для хода дамок
stepperX = stepperY = 0;
#include"massivy.h"
//int shashki[8][8]{{8,1,8,1,8,1,8,1},
//					{1,8,1,8,1,8,1,8},
//					{8,1,8,1,8,1,8,1},
//					{0,8,0,8,0,8,0,8},
//					{8,0,8,0,8,0,8,0},
//					{2,8,2,8,2,8,2,8},
//					{8,2,8,2,8,2,8,2},
//					{2,8,2,8,2,8,2,8} };//стартовая таблица;
int shashki[8][8]{  {8,4,8,1,8,1,8,1},
					{3,8,0,8,0,8,1,8},
					{8,0,8,1,8,1,8,1},
					{0,8,2,8,0,8,0,8},
					{8,2,8,2,8,1,8,0},
					{3,8,0,8,0,8,0,8},
					{8,0,8,2,8,2,8,2},
					{2,8,0,8,2,8,0,8} };//стартовая таблица;

HANDLE output;
output = GetStdHandle(STD_OUTPUT_HANDLE);

do {
	setlocale(LC_ALL, "Russian");
	if (hod) { print(output, 0, 0, "                                                           ХОДЯТ БЕЛЫЕ ШАШКИ     ");  }
	else{	   print(output, 0, 0, "                                                           ХОДЯТ ЧЁРНЫЕ ШАШКИ    ");  }
	
	setlocale(LC_ALL, "C");
	SetConsoleCursorPosition(output, { 0, 1 });//для построения таблицы курсор устанавливаем в положение 0.1
	print(1, kollvo_yacheek + 4,probel);cout << ugol_l_up;//4 - это 2 пробела в начале и 2 после цифры
	print(0, kollvo_yacheek * dl_yacheiki, horizontal_cherta, horizontal_cherta);cout << ugol_r_up << endl;
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
					if		(shashki[i][z] == 0) { for (int s = 0; s < dl_yacheiki; s++) { cout << probel << probel; } }//если ячейка нулевая то пишем в неё пробелы так как это чёрная клетка
					else if (shashki[i][z] == 1) { for (int k = 0; k < dl_yacheiki * 2; k++) { cout << (((c == 0 || c == 6) && ((k == (dl_yacheiki * 2) - 1) || k == 0) && tmpYold == i && tmpXold == z) ? white : shashki_white[c][k]); } }
					else if (shashki[i][z] == 2) { for (int k = 0; k < dl_yacheiki * 2; k++) { cout << (((c == 0 || c == 6) && ((k == (dl_yacheiki * 2) - 1) || k == 0) && tmpYold == i && tmpXold == z) ? white : shashki_black[c][k]); } }
					else if (shashki[i][z] == 3) { for (int k = 0; k < dl_yacheiki * 2; k++) { cout << (((c == 0 || c == 6) && ((k == (dl_yacheiki * 2) - 1) || k == 0) && tmpYold == i && tmpXold == z) ? white : shashki_white_damka[c][k]); } }
					else if (shashki[i][z] == 4) { for (int k = 0; k < dl_yacheiki * 2; k++) { cout << (((c == 0 || c == 6) && ((k == (dl_yacheiki * 2) - 1) || k == 0) && tmpYold == i && tmpXold == z) ? white : shashki_black_damka[c][k]); } }
					//else if (shashki[i][z] == 8) {  }
					//else{}
				}
			}
			c++; //при каждом проходе инкрементируем строку массива считывания из символа
			cout << vertical_cherta << endl;//Вертикальная полоса в конце строки
		}
	}
	print(1, kollvo_yacheek + 4,probel);cout << ugol_l_down;// 4 - это 2 пробела в начале и 2 после цифры
	print(0, kollvo_yacheek* dl_yacheiki, horizontal_cherta, horizontal_cherta);cout << ugol_r_down << endl;//полоса в низу мегаквадрата и закрывающий угол рамки
	
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
	setlocale(LC_ALL, "Russian");
	
	tmpOldX = tmpX; tmpOldY = tmpY;//сохраняем старые значения на случай неправильного выбора ячеек 
	//функция перемещает курсор по таблице и при нажатии ENTER возвращает позицию выбраной ячейки,принимает старое значение позиции что-бы курсор оставался в той же позиции
	//так же принимает размеры столбцов и ячеек,нулевые позиции по X и Y,и шаг перемещения по X и Y
	arrow(output, tmpY, tmpX, kollvo_yacheek, kollvo_yacheek, zerro_pos_xx, zerro_pos_yy, step_xx, step_yy,tmpVspomogatelnaya);
	print(output, 0, 69, "                                              ");
	//tmpY; tmpX;//меняются значения в функции по ссылкам.В tmpVspomogatelnaya будут передаваться события ESCAPE,SPACE и возможно что то ещё
	if (tmpVspomogatelnaya == 32767) { game = false; }//Если tmpVspomogatelnaya = 32767 то выход из пролграммы по ESCAPE
	else {//Продолжаем если не ESCAPE
		if (tmpVspomogatelnaya == 16382) {tmpVspomogatelnaya = 0;//если нажали пробел смена хода между белыми и чёрными шашками
		old_shag = 0; new_shag = -1;hod = ((hod) ? false : true);//смена хода
		}
		else{//если нажали пробел(передача хода) то в этот блок не заходим на этой итерации
			if (old_bool && peremeshenie) { //выбор ячейки. если не ESCAPE И не SPACE продолжаем дальше
				if  (shashki[tmpY][tmpX] == 0 || shashki[tmpY][tmpX] == 8) {//0 - пустая ячейка. 8 - белая ячейка
					old_shag = 0; new_shag = -1;// если ячейка пустая то ошибка
					//old_bool = false;  
				}
				else {//ЗАХВАТ
					if ((shashki[tmpY][tmpX] != 0) &&((shashki[tmpY][tmpX] == 1 || shashki[tmpY][tmpX] == 3) &&  hod) ||
													 ((shashki[tmpY][tmpX] == 2 || shashki[tmpY][tmpX] == 4) && !hod)) {//тут выбираем ячейку.Если ячейка нулевая захват не получится
						old_shag = shashki[tmpY][tmpX]; //выбор ячейки
						tmpYold = tmpY; tmpXold = tmpX;
						old_bool = false;
						print_step(output, tmpYold, tmpXold, tmpY, tmpX, stepperY, stepperX);
					}
				}
			}
			else { //Если после захвата шашки нажать на ту же шашку то захват снимется
				if (!old_bool && tmpY == tmpYold && tmpX == tmpXold) {
					old_shag = 0; new_shag = -1; tmpYold = 0; tmpXold = 0; old_bool = true;
				}
			}
		}
		if (shashki[tmpY][tmpX] == 0) { new_shag = shashki[tmpY][tmpX]; old_bool = true; } //перенос ячейки
		else { new_shag = -1; }//Если клетка занята то ни чего не делаем
		if (old_shag != new_shag && new_shag == 0) {
			short proverka_X, proverka_Y;
			proverka_X = tmpX - tmpXold;
			proverka_Y = tmpY - tmpYold;

			if (old_shag == 1 && tmpY == 7) { old_shag = 3; }//Если белая шака дошла до противоположного конца поля она становится белой дамкой
			if (old_shag == 2 && tmpY == 0) { old_shag = 4; }//Если чёрная шака дошла до противоположного конца поля она становится чёрной дамкой
			
			peremeshenie = true;
			if (old_shag == 1 || old_shag == 2)//для обычных шашек
				{
				if (proverka_Y > 1 || proverka_X > 1 || proverka_Y < -1 || proverka_X < -1) {
					peremeshenie = false;
					if ((proverka_Y == 2 && proverka_X == 2) || (proverka_Y == -2 && proverka_X == 2) ||//если шашка сделала ход в какую либо сторону на 2 клетки
						(proverka_Y == 2 && proverka_X == -2) || (proverka_Y == -2 && proverka_X == -2))
					{
						proverka_kletok(proverka_Y, proverka_X);//вычисляем псевдо адрес промежуточной клетки
						//(proverka_Y > 0) ? proverka_Y -= 1 : proverka_Y += 1;//вычисляем псевдо адрес промежуточной клетки
						//(proverka_X > 0) ? proverka_X -= 1 : proverka_X += 1;//вычисляем псевдо адрес промежуточной клетки

						if ((old_shag != shashki[tmpYold + proverka_Y][tmpXold + proverka_X]) && (shashki[tmpYold + proverka_Y][tmpXold + proverka_X]) != 0) {//проверяем что в промежуточной клетке находится вражеская шашка и промежуточная клетка не является пустой
							shashki[tmpYold + proverka_Y][tmpXold + proverka_X] = 0;//убираем вражескую шашку
							SetConsoleCursorPosition(output, { 129, 9 });
							smena_hoda = true;
							if (hod) {//true ход белых проверяем чёрные по соседству
								if (((shashki[tmpY +  1][tmpX +  1] == 2) || (shashki[tmpY +  1][tmpX +  1] == 4)) && (shashki[tmpY +  2][tmpX +  2] == 0)) { smena_hoda = false; cout << "доступен ещё ход можно бить чёрную шашку"; }
								if (((shashki[tmpY + -1][tmpX +  1] == 2) || (shashki[tmpY + -1][tmpX +  1] == 4)) && (shashki[tmpY + -2][tmpX +  2] == 0)) { smena_hoda = false; cout << "доступен ещё ход можно бить чёрную шашку"; }
								if (((shashki[tmpY +  1][tmpX + -1] == 2) || (shashki[tmpY +  1][tmpX + -1] == 4)) && (shashki[tmpY +  2][tmpX + -2] == 0)) { smena_hoda = false; cout << "доступен ещё ход можно бить чёрную шашку"; }
								if (((shashki[tmpY + -1][tmpX + -1] == 2) || (shashki[tmpY + -1][tmpX + -1] == 4)) && (shashki[tmpY + -2][tmpX + -2] == 0)) { smena_hoda = false; cout << "доступен ещё ход можно бить чёрную шашку"; }
							}
							else {//false чод чёрных проверяем белые по соседству
								if (((shashki[tmpY +  1][tmpX +  1] == 1) || (shashki[tmpY +  1][tmpX +  1] == 3)) && (shashki[tmpY +  2][tmpX +  2] == 0)) { smena_hoda = false; cout << "доступен ещё ход можно бить белую шашку "; }
								if (((shashki[tmpY + -1][tmpX +  1] == 1) || (shashki[tmpY + -1][tmpX +  1] == 3)) && (shashki[tmpY + -2][tmpX +  2] == 0)) { smena_hoda = false; cout << "доступен ещё ход можно бить белую шашку "; }
								if (((shashki[tmpY +  1][tmpX + -1] == 1) || (shashki[tmpY +  1][tmpX + -1] == 3)) && (shashki[tmpY +  2][tmpX + -2] == 0)) { smena_hoda = false; cout << "доступен ещё ход можно бить белую шашку "; }
								if (((shashki[tmpY + -1][tmpX + -1] == 1) || (shashki[tmpY + -1][tmpX + -1] == 3)) && (shashki[tmpY + -2][tmpX + -2] == 0)) { smena_hoda = false; cout << "доступен ещё ход можно бить белую шашку "; }
							}
							
							peremeshenie = true;//разрешаем перемещение выбранной шашки на новое место
						}
					}
					if (peremeshenie) {//перемещаем выбранную шашку на новое место
					shashki[tmpYold][tmpXold] = 0;
					shashki[tmpY][tmpX] = old_shag;
					if (smena_hoda) { hod = ((hod) ? false : true); }
					print(output, 129, 9, "                                              "); cout << endl;
					
					}
					else { print(output, 129, 9, "Error: шашки могут бить только через клетку  "); cout << endl; }
				}
				else {//если шашка просто делает ход проверяем что она не ходит назад
					peremeshenie = false;//устанавливаем переменныю разрешение в false. если будет правильный ход то переменная поменяется на true
					if (old_shag == 1 && ((proverka_Y > 0 && proverka_X > 0) || (proverka_Y > 0 && proverka_X < 0))) { peremeshenie = true; }//проверка для белых
					if (old_shag == 2 && ((proverka_Y < 0 && proverka_X > 0) || (proverka_Y < 0 && proverka_X < 0))) { peremeshenie = true; }//проверка для чёрных
					if(peremeshenie){//если ход правильный то перемещаем шашку
						shashki[tmpYold][tmpXold] = 0;
						shashki[tmpY][tmpX] = old_shag;
						print(output, 0, 68, "                                    "); cout << endl;
						hod = ((hod) ? false : true); //tmpY = 0; tmpX = 0;//смена хода
					}
					else { print(output, 129, 9, "Error: шашки не ходят назад                "); cout << endl; }//если ход был неправильный. выводим сообщение
				}
			}
			
			if (old_shag == 3 || old_shag == 4) //для дамок
				{
				SetConsoleCursorPosition(output, { 128, 10 });
				stepperX = (tmpX > tmpXold) ? tmpX - tmpXold : tmpXold - tmpX;
				stepperY = (tmpY > tmpYold) ? tmpY - tmpYold : tmpYold - tmpY;
				if (stepperX == stepperY) {//проверка на корректность хода дамки. Если stepperX != stepperY то ход был не по диагонали и мы ни чего не делаем
					int* arrHod = new int[stepperX + 1]{};
					if (proverka_Y < 0 && proverka_X > 0) {//Верх право
						for (int i = 0; i <= stepperX; i++) {
							arrHod[i] = shashki[tmpYold - i][tmpXold + i];
						}
					}
					else if (proverka_Y < 0 && proverka_X < 0) {//Верх лево
						for (int i = 0; i <= stepperX; i++) {
							arrHod[i] = shashki[tmpYold - i][tmpXold - i];
						}
					}
					else if (proverka_Y > 0 && proverka_X > 0) {//низ правово 
						for (int i = 0; i <= stepperX; i++) {
							arrHod[i] = shashki[tmpYold + i][tmpXold + i];
						}
					}
					else if (proverka_Y > 0 && proverka_X < 0) {//низ лево  
						for (int i = 0; i <= stepperX; i++) {
							arrHod[i] = shashki[tmpYold + i][tmpXold - i];
							//cout << arrHod[i] << "|";
						}//cout <<  "                             ";
					}
					//true-ходят белые. false-ходят чёрные
					/*for(int i = 1;i <= stepperX;i++){cout << arrHod[i] << "|";}cout << "                             ";*/
					SetConsoleCursorPosition(output, { 128, 11 });
					bool svoi = false;
					bool vrazjeskiye = false;
					bool pustay_kletka = false;
					bool povtor = false;
					int count = 0;
					if (hod) {
						for (int i = 1; i <= stepperX; i++) {
							svoi = true;
							if (arrHod[i] == 0) {pustay_kletka = true;
								count++;
							}
							else if ((arrHod[i] == 1 || arrHod[i] == 3)) {
									if(i == stepperX) {
										if ((arrHod[i] == 1 || arrHod[i] == 3)) { povtor = true; }
									}else {
										if ((arrHod[i + 1] != 0 || arrHod[i + 1] != 0)) { povtor = true; }
									}
								svoi = true;
								}
								else if ((arrHod[i] == 2 || arrHod[i] == 4)) {
									if ((arrHod[i + 1] != 0 || arrHod[i + 1] != 0)) { povtor = true; }
									//vrazjeskiye = true;
								}
						}
					}
					else {
						for (int i = 1; i <= stepperX; i++) {
							if (arrHod[i] == 0) {
								count++;
								pustay_kletka = true;
							}
							if ((arrHod[i] == 1 || arrHod[i] == 3)) {
								if (i == stepperX){
									if ((arrHod[i] == 1 || arrHod[i] == 3)) { povtor = true; }
								}
								else {
									if ((arrHod[i + 1] != 0 || arrHod[i + 1] != 0)) { povtor = true; }
								}
								svoi = true;
							}
							if ((arrHod[i] == 2 || arrHod[i] == 4)) {
								if ((arrHod[i + 1] != 0 || arrHod[i + 1] != 0)) { povtor = true; }
								//vrazjeskiye = true;
							}

						}
					}
					if (!svoi) { cout << "недопустимый ход!! svoi"; }
					else {
						if (povtor) {
							cout << "недопустимый ход!! povtor";
							svoi = false; pustay_kletka = false; vrazjeskiye = false; povtor = false;
						}
						else {
							//if ((old_shag != shashki[tmpYold + proverka_Y][tmpXold + proverka_X]) && (shashki[tmpYold + proverka_Y][tmpXold + proverka_X] != 0)) {//проверяем что в промежуточной клетке находится вражеская шашка и промежуточная клетка не является пустой
							//	if ((shashki[tmpYold + proverka_Y + proverka_kletok_Y(proverka_Y)][tmpXold + proverka_X + proverka_kletok_X(proverka_X)] != old_shag)) {
							//		shashki[tmpYold + proverka_Y][tmpXold + proverka_X] = 0;//убираем вражескую шашку
							//		peremeshenie = true;//разрешаем перемещение выбранной шашки на новое место
							//		shashki[tmpY][tmpX] = old_shag;
							//	}
							//}
							if (peremeshenie) {
								
								
								if (stepperX != 1) {
									for (int i = 0; i < stepperX; i++) {
										proverka_kletok(proverka_Y, proverka_X);

										if ((old_shag != shashki[tmpYold + proverka_Y][tmpXold + proverka_X]) && (shashki[tmpYold + proverka_Y][tmpXold + proverka_X] != 0)) {//проверяем что в промежуточной клетке находится вражеская шашка и промежуточная клетка не является пустой
											if ((shashki[tmpYold + proverka_Y + proverka_kletok_Y(proverka_Y)][tmpXold + proverka_X + proverka_kletok_X(proverka_X)] != old_shag)) {
												shashki[tmpYold + proverka_Y][tmpXold + proverka_X] = 0;//убираем вражескую шашку
												peremeshenie = true;//разрешаем перемещение выбранной шашки на новое место
												shashki[tmpY][tmpX] = old_shag;
											}
										}
										//else { print(output, 129, 9, "                    XZXZXZXZXZXZXZ                              "); cout << endl; }
									}shashki[tmpYold][tmpXold] = 0;
									if(count == stepperX){ shashki[tmpY][tmpX] = old_shag; }
								}
								else {
									shashki[tmpYold][tmpXold] = 0;
									shashki[tmpY][tmpX] = old_shag;
								}

							}
						}
						delete[] arrHod;
					}
				}
				else {
					cout << "Дамки так не ходят "; peremeshenie = false;
				}
			}

			//if (old_shag == 1 && tmpY == 7) { old_shag = 3; }//Если белая шака дошла до противоположного конца поля она становится белой дамкой
			//if (old_shag == 2 && tmpY == 0) { old_shag = 4; }//Если чёрная шака дошла до противоположного конца поля она становится чёрной дамкой
			print_step(output, tmpYold, tmpXold, tmpY, tmpX, stepperY, stepperX);
		}
	}
} while (game);

SetConsoleCursorPosition(output, { 0, 65 });
cout << "                                    THE END                                    " << endl;
cout << "                                                                               " << endl;
cout << "                                                                               " << endl;
cout << "                                                                               " << endl;
system("pause");
}
void print(int i,int SIZE,char ch) {
	for (; i < SIZE; i++) { cout << ch; }//for (int i = 1; i < kollvo_yacheek + 4; i++) { cout << probel; }
}
void print(int i, int SIZE, char ch0, char ch1) {
	for (; i < SIZE; i++) { cout << ch0 << ch1; }
}
void print(HANDLE output,short x,short y,string stroka) {
	SetConsoleCursorPosition(output, { x, y });
	cout << stroka;
}
void arrow(HANDLE output, short& y, short& x, const int row, const int column, const int zerro_pos_xx, const int zerro_pos_yy, const int step_xx, const int step_yy,int& tmpVspomogatelnaya) {
	//функция перемещает курсор по таблице и при нажатии ENTER возвращает позицию выбраной ячейки,принимает старое значение позиции что-бы курсор оставался в той же позиции
	//так же принимает размеры столбцов и ячеек,нулевые позиции по X и Y,и шаг перемещения по X и Y
	//  //int row = 8;//X 
	//	//int column = 8;//Y 
	//	//short x = 0;      
	//	//short y = 0;
	//	/*const int zerro_pos_xx = 18;
	//	const int zerro_pos_yy = 4;
	//	const int step_xx = 14;
	//	const int step_yy = 7;*/     
	short xx = zerro_pos_xx;//инициализируем нулевую позицию по координате x
	short yy = zerro_pos_yy;//инициализируем нулевую позицию по координате y
	for (int i = x; i != 0; i--) { xx += step_xx; }//переносим курсор на x шагов. в step_xx хранится значение шага между точками перемещения курсора по оси xx
	for (int j = y; j != 0; j--) { yy += step_yy; }//переносим курсор на y шагов. в step_yy хранится значение шага между точками перемещения курсора по оси yy
	int l = 0;// в l будем принимать введённый символ с клавиатуры
	SetConsoleCursorPosition(output, { xx, yy });//выводим курсор по координатам YY и XX
	while (l != ENTER && l != ESCAPE && l != SPACE) {
		l = _getch();
		print(output, 128, 9,  "                                                      ");
		print(output, 128, 10, "                                                      ");
		print(output, 128, 11, "                                                      ");
		switch (l) {
		case UP_ARROW:		y--; yy -= step_yy; if (y == -1)     { y = column - 1; yy = (y * step_yy) + zerro_pos_yy; }	break;//up 
		case DOWN_ARROW:	y++; yy += step_yy; if (y == column) { y = 0;	       yy = zerro_pos_yy; }					break;//down
		case LEFT_ARROW:	x--; xx -= step_xx; if (x == -1)     { x = row - 1;	   xx = (x * step_xx) + zerro_pos_xx; }	break;//left
		case RIGHT_ARROW:	x++; xx += step_xx; if (x == row)    { x = 0;	       xx = zerro_pos_xx; }				    break;//right
		case ESCAPE: tmpVspomogatelnaya = 32767; break;
		case SPACE:  tmpVspomogatelnaya = 16382; break;
		case 224:break;
		default:  break;
		}
		SetConsoleCursorPosition(output, { xx, yy }); //перемещаем курсор при нажатиях стрелок на клавиатуре
	}
}
template<typename T>void proverka_kletok(T& proverka_Y,T& proverka_X){
(proverka_Y > 0) ? proverka_Y -= 1 : proverka_Y += 1;//вычисляем псевдо адрес промежуточной клетки
(proverka_X > 0) ? proverka_X -= 1 : proverka_X += 1;//вычисляем псевдо адрес промежуточной клетки
}
short proverka_kletok_X( short proverka_X) {
	(proverka_X > 0) ? proverka_X -= 1 : proverka_X += 1;//вычисляем псевдо адрес промежуточной клетки
	return proverka_X;
}
short proverka_kletok_Y(short proverka_Y) {
	(proverka_Y > 0) ? proverka_Y -= 1 : proverka_Y += 1;//вычисляем псевдо адрес промежуточной клетки
	return proverka_Y;
}
void fontSizeConsole(int L, CONSOLE_FONT_INFOEX fontInfo, HANDLE hConsole) {
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
	//wcscpy(fontInfo.FaceName, L"Lucida Console");
	fontInfo.dwFontSize.Y = L;
	SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
}

void print_step(HANDLE output, short tmpYold, short tmpXold, short tmpY, short tmpX, short stepperY, short stepperX) {
	SetConsoleCursorPosition(output, { 128, 3 }); cout << setw(3) << "Y"            << "\t" << "X" << endl;
	SetConsoleCursorPosition(output, { 128, 4 }); cout << setw(3) << tmpYold        << "\t" << tmpXold        << "        " << "Захват" << endl;
	SetConsoleCursorPosition(output, { 128, 5 }); cout << setw(3) << tmpY           << "\t" << tmpX           << "        " << "Перенос" << endl;
	SetConsoleCursorPosition(output, { 128, 6 }); cout << setw(3) << tmpY - tmpYold << "\t" << tmpX - tmpXold << "        " << endl;
	SetConsoleCursorPosition(output, { 128, 7 }); cout << setw(3) << tmpYold - tmpY << "\t" << tmpXold - tmpX << "        " << endl;
	SetConsoleCursorPosition(output, { 128, 8 }); cout << setw(3) << stepperY       << "\t" << stepperX       << "        " << endl;
}