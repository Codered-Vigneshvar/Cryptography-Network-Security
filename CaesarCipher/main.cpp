#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[1000], ciphertext[1000];
    char mapping[26];
    char startLetter;
    int key;

    // Taking Input
    printf("Enter a plaintext message: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the starting letter for substitution mapping (uppercase): ");
    scanf(" %c", &startLetter); // Note the space before %c to consume the newline character

    // Validate the starting letter
    if (!isalpha(startLetter) || !isupper(startLetter)) {
        printf("Invalid starting letter. Please enter an uppercase letter.\n");
        return 1; // Exit with an error code
    }

    // Determine the key based on the starting letter
    key = startLetter - 'A';

    // Generate substitution mapping based on the key
    for (int i = 0; i < 26; i++) {
        mapping[i] = 'A' + (i + key) % 26;
    }

    // Encrypting the message
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char currentChar = plaintext[i];

        if (isalpha(currentChar)) {
            char base = islower(currentChar) ? 'a' : 'A';
            int index = currentChar - base;

            // Check if the mapping array is valid
            char mappedChar = mapping[index];
            if (!isalpha(mappedChar)) {
                printf("Error in mapping generation.\n");
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

