#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

void gotoxy (int x, int y) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void BorrarMapa() {
	for (int i=0; i < 15; ++i) {
		for (int j=0; j < 45; ++j) {
			gotoxy(j,i); cout << " ";
		}
	}
}

int main () {
	bool isPlay = true;
	bool encontrada = false;
	srand(time(NULL));
	
	vector<string> Words(51);
	// a
	Words[0]="azucar"; Words[1]="arbol"; Words[2]="amor"; Words[3]="angel";
	// b
	Words[4]="botella";
	// c
	Words[5]="camioneta"; Words[6]="celular"; Words[7]="computador"; Words[8]="controlador"; Words[9]="cama";
	Words[10]="corazon"; Words[11]="cielo"; Words[12]="conejo"; Words[13]="cartera"; Words[14]="camara";
	// d
	Words[15]="dulce";
	// e
	Words[16]="escalera"; Words[17]="emilia";
	// f
	Words[18]="familia"; Words[19]="flores"; Words[20]="fruta"; Words[21]="frio";
	// g
	Words[22] = "gato";
	// h
	Words[23] = "hola";
	// i
	Words[24] = "iguana";
	// j
	Words[25]="juguete";
	// k
	Words[26] = "kilogramo";
	// l
	Words[27]="lentes";
	// m
	Words[28]="madera"; Words[29]="morado"; Words[30]="moneda"; Words[31]="mujer"; Words[32]="mariposa";
	// n
	Words[33]="navidad";
	// o
	Words[34]="ojo";
	// p
	Words[35]="pelota"; Words[36]="puerta"; Words[37]="perro"; Words[38]="piedra";
	// q
	Words[39] = "quiosco";
	// r
	Words[40] = "raton";
	// s
	Words[41]="sillon"; Words[42]="septiembre";
	// t
	Words[43]="television"; Words[44]="taladro";
	// u
	Words[45] = "universo";
	// v
	Words[46]="ventana";
	// w
	Words[47] = "whisky";
	// x
	Words[48] = "examen";
	// y
	Words[49] = "yegua";
	// z
	Words[50] = "zoologico";

	vector<string> encontrar; // guardara cantidad de ___
	
	vector<char> abc(28);
	abc[0] = 'a';abc[1] = 'b';abc[2] = 'c';abc[3] = 'd';abc[4] = 'e';abc[5] = 'f';abc[6] = 'g';abc[7] = 'h';abc[8] = 'i';abc[9] = 'j';abc[10] = 'k';
	abc[11] = 'l';abc[12] = 'm';abc[13] = 'n';abc[14] = '�';abc[15] = 'o';abc[16] = 'p';abc[17] = 'q';abc[18] = 'r';abc[19] = 's';abc[20] = 't';
	abc[21] = 'u';abc[22] = 'v';abc[23] = 'w';abc[24] = 'x';abc[25] = 'y';abc[26] = 'z';
	
	vector<bool> abc2(28); 
	abc2[0] = true;abc2[1] = true;abc2[2] = true;abc2[3] = true;abc2[4] = true;abc2[5] = true;abc2[6] = true;abc2[7] = true;abc2[8] = true;
	abc2[9] = true;abc2[10] = true;abc2[11] = true;abc2[12] = true;abc2[13] = true;abc2[14] = true;abc2[15] = true;abc2[16] = true;abc2[17] = true;
	abc2[18] = true;abc2[19] = true;abc2[20] = true;abc2[21] = true;abc2[22] = true;abc2[23] = true;abc2[24] = true;abc2[25] = true;abc2[26] = true;
	
	while(isPlay) {
		int num = rand()%(Words.size()+1);
		string Palabra = Words[num];
		int contador = 0;
		for(int i=0; i < Palabra.size(); ++i) { // reestable los valores para que tenga cantidad de _ de la palabra random
			encontrar.push_back("___");
		}
		for (int i=0; i < abc2.size(); ++i) { // reestablece los valores de letras disponibles para proximo juego
			abc2[i] = true;
		}
		while (encontrada==false) { // se empieza a buscar la palabra
			gotoxy(0,15);
			cout << "Letras que aun no ha ocupado: \n";
			for (int i = 0; i < abc.size(); ++i) { // muestra letras que aun no se ocupan
				if (abc2[i] == true) {
					cout << abc[i] << " ";
				}
			}
			gotoxy(0,0);
			cout << "La Palabra ha sido escogida. Encuentrela.\n" << endl;
			for (int i=0; i < encontrar.size(); ++i) { // muestra durante el juego las letras encontradas y por encontrar
				cout << encontrar[i] << "  ";
			}
			cout << endl;
			cout << "\nIngrese una letra: "; char letra; cin >> letra;
			for (int i=0; i < Palabra.size(); ++i) { // comprueba si la letra es correcta
				if (letra == Palabra[i]) {
					++contador;
					encontrar[i] = letra;
					cout << "Letra correcta!\n\n";
					
				}
				for (int i=0; i < abc.size(); ++i) { // quita la letra ingresada del vocabulario ayuda
					if (abc[i] == letra) {
						abc2[i] = false;
					}
				}
			}
			if (contador == Palabra.size()) { // se comprueba si ya se encontraron todas las letras
				encontrada = true;
			}
			BorrarMapa();
			gotoxy(0,0);
			cout << endl;
		}
		cout << "La palabra era: ";
		for (int i=0; i < encontrar.size(); ++i) {
			cout << encontrar[i];
		}
		cout << "\nHa ganado!\n";
		string volver;
		cout << "--------------------------------" << endl;
		cout << "Volver a jugar? (si/no): "; cin >> volver;
		cout << "--------------------------------" << endl;
		BorrarMapa();
		gotoxy(0,0);
		if (volver=="si") {
			isPlay = true;
			encontrada = false;
			encontrar.erase(encontrar.begin(),encontrar.end());
		}
		else {
			isPlay = false;
		}
	}
	cout << "Adios\n";
	return 0;
}