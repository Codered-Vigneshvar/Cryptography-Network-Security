#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;  // Inverse doesn't exist
}

int isCoprime(int a, int b) {
    return gcd(a, b) == 1;
}

int isValidKey(int a, int b) {
    return isCoprime(a, 26);
}

char encryptChar(int a, int b, char p) {
    if ('A' <= p && p <= 'Z') {
        return (char)((a * (p - 'A') + b) % 26 + 'A');
    } else if ('a' <= p && p <= 'z') {
        return (char)((a * (p - 'a') + b) % 26 + 'a');
    } else {
        return p;  // Keep non-alphabetic characters unchanged
    }
}

int main() {
    int a, b;
    char plaintext[100];
    char ciphertext[100];

    printf("Enter the value of a (must be coprime with 26): ");
    scanf("%d", &a);

    // Check if 'a' is valid
    if (!isValidKey(a, 26)) {
        printf("Invalid value of 'a'. It must be coprime with 26.\n");
        return 1;
    }

    printf("Enter the value of b: ");
    scanf("%d", &b);

    printf("Enter the plaintext: ");
    getchar();  // Clear the newline from the previous input
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encrypt the plaintext using the affine Caesar cipher
    size_t len = strlen(plaintext);
    for (size_t i = 0; i < len; i++) {
        ciphertext[i] = encryptChar(a, b, plaintext[i]);
    }

    // Null-terminate the ciphertext
    ciphertext[len] = '\0';

    // Display the encrypted text
    printf("Encrypted Text: %s\n", ciphertext);

    return 0;
}


