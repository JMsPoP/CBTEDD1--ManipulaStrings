#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

int main() {
    string texto;
    cout << "Insira um texto: ";
    getline(cin, texto);

    int larguraTela = 205;
    int larguraTexto = texto.length();
    int espacosEsquerda = (larguraTela - larguraTexto) / 2 + 5;

    // Mostrar o texto na linha 5
    for (int i = 0; i < 3; i++) {
        cout << endl;
    }
    cout << setw(espacosEsquerda + larguraTexto) << texto << endl;

    // Mostrar o texto na linha 20, caractere por caractere
    int delay = 100; // Atraso entre caracteres em milissegundos
    int linhaAtual = 20;
    int colunaAtual = espacosEsquerda;
    for (int i = 0; i < larguraTexto; i++) {
        COORD coord = { static_cast<SHORT>(colunaAtual), static_cast<SHORT>(linhaAtual) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << texto[i];
        colunaAtual++;
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); // Limpar o buffer de entrada
        Sleep(delay);
    }

    cout << endl;

    return 0;
}