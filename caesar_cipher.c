#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototype 
void caesarCipherEncrypt(char message[], int key);
void caesarCipherDecrypt(char message[], int key);
void vigenereCipherEncrypt(char message[], char key[]);
void vigenereCipherDecrypt(char message[], char key[]);

int main() {
    int choice, key;
    char message[100], vigenereKey[100];

    printf("Choose an option:\n");
    printf("1. Caesar Cipher Encryption\n");
    printf("2. Caesar Cipher Decryption\n");
    printf("3. Vigenère Cipher Encryption\n");
    printf("4. Vigenère Cipher Decryption\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the message to encrypt: ");
            scanf(" %[^\n]s", message);
            printf("Enter the key: ");
            scanf("%d", &key);
            caesarCipherEncrypt(message, key);
            break;
        case 2:
            printf("Enter the message to decrypt: ");
            scanf(" %[^\n]s", message);
            printf("Enter the key: ");
            scanf("%d", &key);
            caesarCipherDecrypt(message, key);
            break;
        case 3:
            printf("Enter the message to encrypt: ");
            scanf(" %[^\n]s", message);
            printf("Enter the key: ");
            scanf(" %[^\n]s", vigenereKey);
            vigenereCipherEncrypt(message, vigenereKey);
            break;
        case 4:
            printf("Enter the message to decrypt: ");
            scanf(" %[^\n]s", message);
            printf("Enter the key: ");
            scanf(" %[^\n]s", vigenereKey);
            vigenereCipherDecrypt(message, vigenereKey);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

void caesarCipherEncrypt(char message[], int key) {
    char encryptedMessage[100];
    int i;

    for (i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encryptedMessage[i] = 'a' + (message[i] - 'a' + key) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encryptedMessage[i] = 'A' + (message[i] - 'A' + key) % 26;
        } else {
            encryptedMessage[i] = message[i];
        }
    }

    encryptedMessage[i] = '\0';

    printf("Encrypted message: %s\n", encryptedMessage);
}

void caesarCipherDecrypt(char message[], int key) {
    char decryptedMessage[100];
    int i;

    for (i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            decryptedMessage[i] = 'a' + (message[i] - 'a' - key + 26) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            decryptedMessage[i] = 'A' + (message[i] - 'A' - key + 26) % 26;
        } else {
            decryptedMessage[i] = message[i];
        }
    }

    decryptedMessage[i] = '\0';

    printf("Decrypted message: %s\n", decryptedMessage);
}

void vigenereCipherEncrypt(char message[], char key[]) {
    char encryptedMessage[100];
    int i, j;

    for (i = 0, j = 0; message[i] != '\0'; ++i, ++j) {
        if (key[j] == '\0') {
            j = 0; // Reset key index if end of key is reached
        }

        if (message[i] >= 'a' && message[i] <= 'z') {
            encryptedMessage[i] = 'a' + (message[i] - 'a' + key[j] - 'a') % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encryptedMessage[i] = 'A' + (message[i] - 'A' + key[j] - 'A') % 26;
        } else {
            encryptedMessage[i] = message[i];
            --j; // Do not increment key index for non-alphabetic characters
        }
    }

    encryptedMessage[i] = '\0';

    printf("Encrypted message: %s\n", encryptedMessage);
}

void vigenereCipherDecrypt(char message[], char key[]) {
    char decryptedMessage[100];
    int i, j;

    for (i = 0, j = 0; message[i] != '\0'; ++i, ++j) {
        if (key[j] == '\0') {
            j = 0; // Reset key index if end of key is reached
        }

        if (message[i] >= 'a' && message[i] <= 'z') {
            decryptedMessage[i] = 'a' + (message[i] - key[j] + 26) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            decryptedMessage[i] = 'A' + (message[i] - key[j] + 26) % 26;
        } else {
            decryptedMessage[i] = message[i];
            --j; // Do not increment key index for non-alphabetic characters
        }
    }

    decryptedMessage[i] = '\0';

    printf("Decrypted message: %s\n", decryptedMessage);
}

