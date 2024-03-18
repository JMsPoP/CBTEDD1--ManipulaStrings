#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string tx1, tx2;
    
    std::cout << "Digite uma mensagem de texto: ";
    std::getline(std::cin, tx1);
    
	    tx1.erase(std::remove(tx1.begin(), tx1.end(), ' '), tx1.end());
    //https://stackoverflow.com/questions/44847526/how-does-the-c-code-x-erasestdremovex-begin-x-end-x-end-w

    for (int i = tx1.length() - 1; i >= 0; i--) {
        tx2 += tx1[i];
    }
    
    if (tx1 == tx2) {
        std::cout << "A mensagem e um palindromo." << std::endl;
    } else {
        std::cout << "A mensagem nao e um palindromo." << std::endl;
    }
    
    return 0;
}
