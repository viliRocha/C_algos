#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#define Size 7

//Don't need to worry about std:: command
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


//using algorithm library
string clear_text(string text) {

    //removes spaces from the string
    text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());

    //brings all character to lower case
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    return text;
}



//Just using native C stuff
string clear_text2 (string texto) {

    //also removes spaces from the string
    for (int c = 0; c < texto.length(); c++) {
        if (texto[c] == ' ') {
            for (int a = c; a < texto.length() - 1; a++) {
                texto[a] = texto[a + 1];
            }
            texto.pop_back();
        }
        //also brings all character to lower case
        if (texto[c] >= 'A' && texto[c] <= 'Z') {
                texto[c] += 32;
        }
    }
     return texto;
}

//algorithm that shows which is the smallest number in array
int findBig(int values[3]) {
    int bgNum = values[0];

    for(int i = 0; i < Size; i++) {
        if(i[values] < bgNum) {
           bgNum = i[values];
        }
    }
    return bgNum;
}

//Algorithm that reverses string
string str = "hello world!!!";

string rev_tex(string tex) {
    for(int k = 0; k < tex.length() / 2; k++) {
       char character = tex[k];

       tex[k] = tex[tex.length() - k - 1];

       tex[tex.length() - k - 1] = character;
    }

    return tex;
}

int main() {
    if (ePali(clear_text2("A basE dO Teto desAba"))) {
        cout << "E Palindromo: Verdadeiro" << endl;
    }
    else {
        cout << "E Palindromo: Falso" << endl;
    }

    int values[] = {9, 11, 9, 13, -4, 0, 7};

        cout << findBig(values) <<endl;

        string finalResult = rev_tex(str);

        for(int s = 0; s < finalResult.length(); s++) {
           printf("%c", finalResult[s]);
        }

    return 0;
}
