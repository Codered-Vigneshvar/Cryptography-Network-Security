#include <stdio.h>
#include <string.h>

void decryptMessage(char cipherText[]) {
    // Calculate the length of the ciphertext
    size_t length = strlen(cipherText);

    // Create an array to store the frequency of each character
    int frequency[256] = {0};

    // Calculate the frequency of each character in the ciphertext
    for (size_t i = 0; i < length; i++) {
        frequency[(int)cipherText[i]]++;
    }

    // Find the most frequent character in the ciphertext
    int maxFrequency = 0;
    char mostFrequentChar = '\0';  // Initialize to a default value

    for (int i = 0; i < 256; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mostFrequentChar = (char)i;
        }
    }

    // Assuming the most frequent character corresponds to 'e'
    char key = mostFrequentChar - 'e' + 'E';

    // Decrypt the ciphertext using the key
    for (size_t i = 0; i < length; i++) {
        if ('a' <= cipherText[i] && cipherText[i] <= 'z') {
            cipherText[i] = (char)(((cipherText[i] - 'a' + 26 - key + 'A') % 26) + 'a');
        } else if ('A' <= cipherText[i] && cipherText[i] <= 'Z') {
            cipherText[i] = (char)(((cipherText[i] - 'A' + 26 - key + 'A') % 26) + 'A');
        }
    }

    // Display the decrypted message
    printf("Decrypted Message: %s\n", cipherText);
}

int main() {
    // Given ciphertext
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";

    // Decrypt the message
    decryptMessage(ciphertext);

    return 0;
}


