#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[1000], ciphertext[1000];
    char mapping[26];

    // Taking Input
    printf("Enter a plaintext message: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the substitution mapping (26 uppercase letters): ");
    fgets(mapping, sizeof(mapping), stdin);

    // Encrypting the message
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char currentChar = plaintext[i];

        if (isalpha(currentChar)) {
            char base = islower(currentChar) ? 'a' : 'A';
            int index = currentChar - base;

            // Check if the mapping array is valid
            char mappedChar = mapping[index];
            if (!isalpha(mappedChar)) {
                printf("Invalid substitution mapping.\n");
                return 1; // Exit with an error code
            }

            ciphertext[i] = mappedChar;
        } else {
            ciphertext[i] = currentChar;
        }
    }

    // Ensure null-termination
    ciphertext[strlen(plaintext)] = '\0';

    // Output the encrypted message
    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}

