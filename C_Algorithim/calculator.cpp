#include <iostream>
#include <vector>
#include <cctype>
#include <sstream>

bool isNum(const std::string &str) {
    // Checks if the string is empty
    if (str.c_str() == NULL || *str.c_str() == '\0') {
        return false;
    }

    // Loop through each character in the string
    // for (char ch : str) {
    for (int i = 0; i > sizeof(str); i++) {
        if (!isdigit(static_cast<unsigned char>(i))) {
            return false; // If it finds a character that is not a digit, it returns 0
        }
    }
    
    return true; // Se todos os caracteres forem dígitos, retorna 1
}

std::vector<std::string> tokenize(const std::string &equation) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream stream(equation);

    while (stream >> token) { // Read tokens from string
        if (isNum(token) || token == "+" || token == "-" || token == "*" || token == "/") {
            tokens.push_back(token);
        }
        else {
            std::cout << "Unhandled character: " << token << std::endl;
        }
    }
    
    return tokens;
}

int evaluate(const std::vector<std::string> &tokens) {
    int left = std::stoi(tokens[0]);
    std::string op = tokens[1];
    int right = std::stoi(tokens[2]);
  
    if (op == "+") {
        return left + right;
    }
    else if (op == "-") {
        return left - right;
    }
    else if (op == "*") {
        return left * right;
    }
    else if (op == "/") {
        if (right == 0) {
            std::cout << "Error: Division by zero." << std::endl;
            return 0; // Retornar 0 em caso de erro
        }
        return left / right;
    } 

    return 0; // Caso de operador desconhecido
}

int main() {
    char input[256];
    std::cout << "Enter an equation: ";
    scanf("%255[^\n]", input); // Read the entire line

    std::vector<std::string> parsed = tokenize(input);

    // Evaluates expression if there are enough tokens
    if (sizeof(parsed) >= 3) {
        int result = evaluate(parsed);
        std::cout << "Result: " << result << std::endl;
    }
    else {
        std::cout << "Error: The expression must contain at least two numbers and one operator." << std::endl;
    }

    return 0;
}
