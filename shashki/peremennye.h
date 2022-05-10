#pragma once







int digits_bytes[10][6]{ //10,7// Digits / ����� 

		{0b00011000, 0b00100100, 0b00100100, 0b00100100, 0b00100100, 0b00011000 }, // ������ 48  <0> 
		{0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b00101000, 0b00011000 }, // ������ 49  <1> 
		{0b00111100, 0b00100000, 0b00010000, 0b00001000, 0b00100100, 0b00011000 }, // ������ 50  <2> 
		{0b00011000, 0b00100100, 0b00000100, 0b00001000, 0b00100100, 0b00011000 }, // ������ 51  <3> 
		{0b00000100, 0b00000100, 0b00011100, 0b00100100, 0b00010100, 0b00001100 }, // ������ 52  <4> 
		{0b00011000, 0b00100100, 0b00000100, 0b00011000, 0b00100000, 0b00111100 }, // ������ 53  <5> 
		{0b00011000, 0b00100100, 0b00100100, 0b00111000, 0b00100000, 0b00011000 }, // ������ 54  <6> 
		{0b00010000, 0b00010000, 0b00010000, 0b00001000, 0b00000100, 0b00111100 }, // ������ 55  <7> 
		{0b00011000, 0b00100100, 0b00100100, 0b00011000, 0b00100100, 0b00011000 }, // ������ 56  <8> 
		{0b00111000, 0b00000100, 0b00011100, 0b00100100, 0b00100100, 0b00011000 }  // ������ 57  <9> 
};

int chars_bytes[12][6]{
	// Roman Smalls / ��������, �������� 
		{0b00001100, 0b00010010, 0b00011110, 0b00000010, 0b00010010, 0b00001100 }, // ������ 97  <a> 
		{0b00011100, 0b00010010, 0b00011010, 0b00010100, 0b00010000, 0b00010000 }, // ������ 98  <b> 
		{0b00001100, 0b00010010, 0b00010000, 0b00010010, 0b00001100, 0b00000000 }, // ������ 99  <c> 
		{0b00001010, 0b00010110, 0b00010010, 0b00001110, 0b00000010, 0b00000010 }, // ������ 100 <d> 
		{0b00001100, 0b00010010, 0b00010000, 0b00011100, 0b00010010, 0b00001100 }, // ������ 101 <e> 
		{0b00001000, 0b00001000, 0b00001000, 0b00011100, 0b00001000, 0b00000110 }, // ������ 102 <f> 
		{0b00001110, 0b00010000, 0b00001100, 0b00010010, 0b00010010, 0b00001100 }, // ������ 103 <g> 
		{0b00010010, 0b00010010, 0b00011010, 0b00010100, 0b00010000, 0b00010000 }, // ������ 104 <h> 
		{0b00011100, 0b00001000, 0b00001000, 0b00011000, 0b00000000, 0b00001000 }, // ������ 105 <i> 
		{0b00011000, 0b00000100, 0b00000100, 0b00011100, 0b00000000, 0b00000100 }, // ������ 106 <j> 
		{0b00010100, 0b00011000, 0b00011000, 0b00010100, 0b00010000, 0b00000000 }, // ������ 107 <k> 
		{0b00011100, 0b00001000, 0b00001000, 0b00001000, 0b00011000, 0b00000000 }  // ������ 108 <l> 
};

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