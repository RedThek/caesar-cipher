#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char* message, int key);
void decrypt(char* message, int key);

int main() {
    char message[] = "Hello World";
    int key = 3;
    printf("The original message is : %s \n", message);
    encrypt(message, key);
    printf("The encrypted message is : %s \n", message);
    decrypt(message, key);
    printf("The decrypted message is : %s \n", message);
    return 0;
}

void encrypt(char* message, int key) {
    int alphabet = 26, message_length = strlen(message), base_character, current_character, encrypted_character;

    key = key % alphabet;
    if (key < 0) key = key + alphabet;
    
    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if(islower(message[i])) base_character = 'a';
            if(isupper(message[i])) base_character = 'A';
            encrypted_character = (message[i] - base_character + key) % alphabet + base_character;
            message[i] = (char)encrypted_character;
        }
    }
}

void decrypt(char* message, int key) {
    int alphabet = 26;
    encrypt(message, alphabet - key);
}