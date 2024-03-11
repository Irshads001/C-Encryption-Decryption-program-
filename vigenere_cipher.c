#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenereCipherEncrypt(char message[], char key[]);
void vigenereCipherDecrypt(char message[], char key[]);

int main() {
    char message[100];
    char key[100];

    printf("Enter message to encrypt: ");
    scanf(" %[^\n]s", message);

    printf("Enter encryption key: ");
    scanf(" %[^\n]s", key);

    // Encrypt the message
    vigenereCipherEncrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    vigenereCipherDecrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void vigenereCipherEncrypt(char message[], char key[]) {
    int i, j;
    int messageLen = strlen(message);
    int keyLen = strlen(key);

    for (i = 0, j = 0; i < messageLen; ++i, ++j) {
        if (j == keyLen) {
            j = 0;  // Reset key index if it reaches end
        }

        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = base + (message[i] - base + key[j] - 'a') % 26;
        }
    }
}

void vigenereCipherDecrypt(char message[], char key[]) {
    int i, j;
    int messageLen = strlen(message);
    int keyLen = strlen(key);

    for (i = 0, j = 0; i < messageLen; ++i, ++j) {
        if (j == keyLen) {
            j = 0;  // Reset key index if it reaches end
        }

        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = base + (message[i] - base - (key[j] - 'a') + 26) % 26;
        }
    }
}

