#include <iostream>
using namespace std;

void encrypt(char* message, int key);
void decrypt(char* message, int key);

int main() {
    char message[] = "Hello World";
    int key = 3;
    cout << "The original message is : " << message << endl;
    encrypt(message, key);
    cout << "The encrypted message is : " << message << endl;
    decrypt(message, key);
    cout << "The decrypted message is : " << message << endl;
    return 0;
}

void encrypt(char* message, int key) {
    int alphabet = 26;
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }
}

void decrypt(char* message, int key) {
    int alphabet = 26;
    encrypt(message, alphabet - key);
}