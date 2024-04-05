#include <iostream>
#include <string>

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

int main() {
    if (ePali("arara") == true) {
        cout << "E Palindromo: Verdadeiro" << endl;
    }
    else {
        cout << "E Palindromo: Falso" << endl;
    }

    return 0;
}
