#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

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

string clear_text(string text) {
    //removes spaces from the string
    text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
    //brings all character to lower case
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    return text;
}

int main() {
    if (ePali(clear_text("A basE dO Teto desaba"))) {
        cout << "E Palindromo: Verdadeiro" << endl;
    }
    else {
        cout << "E Palindromo: Falso" << endl;
    }

    return 0;
}

