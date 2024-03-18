
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::string abreviarNome(const std::string& nome) {
    if (nome.length() <= 2) {
        return nome;
    } else {
        return nome.substr(0, 1) + ".";
    }
}


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

            std::string ultimo_nome = palavras.back();
            std::string primeiro_nome = palavras.front();
//https://www.inf.pucrs.br/~flash/lapro2ec/aulas/aula_strings.html


            std::string nomes_meio_abreviados = "";
            for (size_t i = 1; i < palavras.size() - 1; ++i) {
                nomes_meio_abreviados += abreviarNome(palavras[i]) + " ";
            }

            std::cout << ultimo_nome << ", " << primeiro_nome << " " << nomes_meio_abreviados << std::endl;

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