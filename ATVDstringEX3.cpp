
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {
         std::ifstream arquivo("D:/faculdade/c++/4EXemC++/ListaNomes.txt");
    //https://www.w3schools.com/cpp/cpp_files.asp
    //https://site112.com/gerador-nomes-pessoas

    
    if (arquivo.is_open()) {
        std::string linha;
        std::vector<std::string> palavras;
        int num_linha = 1;
        int num_palavra = 1;

        while (std::getline(arquivo, linha)) {
            std::string palavra;
            std::ostringstream oss;
            oss << num_palavra;
            palavra = "s" + oss.str() + " = ";
            
            std::istringstream iss(linha);

            while (iss >> palavra) {
                palavras.push_back(palavra);
                palavra.clear();
                oss.str("");
                oss << num_palavra;
                palavra = "s" + oss.str() + " = ";
                num_palavra++;
            }

            // Identifica o último nome da linha
            std::string ultimo_nome = palavras.back();
            //https://www.inf.pucrs.br/~flash/lapro2ec/aulas/aula_strings.html

            std::cout << ultimo_nome << ", ";
            for (size_t i = 0; i < palavras.size() - 1; ++i) {
                std::cout << palavras[i];
                if (i != palavras.size() - 2) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;

            palavras.clear();
            num_palavra = 1;

            num_linha++;
        }

        arquivo.close();
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }

    return 0;
}