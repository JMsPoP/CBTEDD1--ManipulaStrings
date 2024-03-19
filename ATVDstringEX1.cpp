#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

void gotoxy(short x, short y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void waitHalfSecond() {
    Sleep(500); // variavel para espera meio segundo
}

int main() {
    setlocale(LC_ALL, "");

    string input;
    cout << "Digite uma mensagem: ";
    getline(cin, input);

    int screenWidth = 230; // Largura da tela
    int inputWidth = input.length();
    int posX = (screenWidth - inputWidth) / 2;
    int posY = 5;  //posicao incial
    int finalPosY = 20; //posicao final

    string result;

    // exibi a palavra inteira na linha 5
    gotoxy(posX, posY);
    cout << input;
    waitHalfSecond();

    for (int i = 0; i < inputWidth; i++) {
        char currentChar = input[i];
        result += currentChar;

		
		
		
        // move a letra para baixo até a linha 20 e espera
        for (int j = posY + 1; j <= finalPosY; j++) {


            
            gotoxy(posX + i, j - 1);
            cout << ' '; // apaga a letra na linha anterior
            gotoxy(posX + i, j); //vai pra posição
            cout << currentChar; //coloca o caractere
            waitHalfSecond();
            
            
        }
    }

    // exibi a mensagem final na linha 20
    gotoxy(posX, finalPosY);
    cout << result;

    return 0;
}
