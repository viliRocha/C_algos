#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Algorithm to generate a random password with a user determined length
int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char otChars[] = {'!', '@', '#', '$', '%', '¨', '&', '*', '(', ')', '|', '/', '*', '=', '+', ' ', '_', '-', '`', '^', '~', '[', ']', '}', '{', ';', ':', ',', '.', '>', '<', '"', '\''};

int psw_ln = 0;

int random_num = 0;

int random_char = 0;

char password[100] = "";

void generate_password() {
    for(int i = 0; i < psw_ln; i++) {
        random_num = rand() % 3;

        if(random_num == 1) {
            random_char = rand()% sizeof(nums) / sizeof(nums[0]);
            password[i] = nums[random_char] + '0';
        }

        else if(random_num == 2) {
            random_char = rand()% sizeof(letters) / sizeof(nums[0]);
            password[i] = letters[random_char] + '0';
        }

        else {
            random_char = rand()% sizeof(otChars) / sizeof(nums[0]);
            password[i] = otChars[random_char] + '0';
        }
    }

    printf("random password:  %s\n", password);
}

int main() {
    printf("number of chars in password:");
    scanf("%d", &psw_ln);

    srand(time(0)); // Initializes the seed for the generation of random numbers

    generate_password();

    return 0;
}
