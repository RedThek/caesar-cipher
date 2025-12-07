#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* encrypt(char* message, int key);
char* decrypt(char* message, int key);

int main() {
    char* message = "Hello World";
    int key = 3;
    printf("The encrypted message is : %s", encrypt(message, key));
    return 0;
}

char* encrypt(char* message, int key)
{
    int alphabet = 26;
    int message_length = strlen(message);
    char base_character, encrypted_character;
    char* encrypted_message[message_length];

    key = key % alphabet;
    if (key < 0)
    {
        key = key + alphabet;
    }
    
    for (int i = 0; i < message_length; i++)
    {
        if (isalpha(message[i]) == 1)
        {
            if(isupper(message[i]) == 1){
                base_character = 'A';
                encrypted_character = (message[i] - base_character + key) % alphabet + base_character;
                encrypted_message[i] = encrypted_character;
                encrypted_message[i + 1] = '\0';
            } else {
                base_character = 'a';
                encrypted_character = (message[i] - base_character + key) % alphabet + base_character;
                encrypted_message[i] = encrypted_character;
                encrypted_message[i + 1] = '\0';
            }
        } else {
            encrypted_message[i] = message[i];
            encrypted_message[i + 1] = '\0';
        }
        
    }

    return encrypted_message;
}

char* decrypt(char* message, int key)
{
    int alphabet = 26;
    return encrypt(message, alphabet - key);
}