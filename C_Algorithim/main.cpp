#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;


//Verifies if sentence is a palindrome
bool ePali(string text) {
    int beg = 0;
    int fin = text.length() - 1;

    while (beg < fin) {
        if (text[beg] != text[fin]) {
            return false;
        }

        beg = beg + 1;
        fin = fin - 1;
    }
    return true;
}


//using algorithim labrary
string clear_text(string text) {

    //removes spaces from the string
    text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());

    //brings all character to lower case
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    return text;
}



//Just using native C stuff
string clear_text2 (string texto) {

    //removes spaces from the string
    for (int c = 0; c < texto.length(); c++) {
        if (texto[c] == ' ') {
            for (int a = c; a < texto.length() - 1; a++) {
                texto[a] = texto[a + 1];
            }
            texto.pop_back();
        }
        if (texto[c] >= 'A' && texto[c] <= 'Z') {
                texto[c] += 32;
        }
    }
     return texto;
}

int main() {
    if (ePali(clear_text2("A basE dO Teto desAba"))) {
        cout << "E Palindromo: Verdadeiro" << endl;
    }
    else {
        cout << "E Palindromo: Falso" << endl;
    }

    return 0;
}
