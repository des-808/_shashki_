#pragma once







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