#include <stdio.h>

void caesarCipherEncrypt(char message[], int key);
void caesarCipherDecrypt(char message[], int key);

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    scanf(" %[^\n]s", message);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Encrypt the message
    caesarCipherEncrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    caesarCipherDecrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void caesarCipherEncrypt(char message[], int key) {
    int i;
    for (i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'a' + (message[i] - 'a' + key) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + (message[i] - 'A' + key) % 26;
        }
    }
}

void caesarCipherDecrypt(char message[], int key) {
    int i;
    for (i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'a' + (message[i] - 'a' - key + 26) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + (message[i] - 'A' - key + 26) % 26;
        }
    }
}
