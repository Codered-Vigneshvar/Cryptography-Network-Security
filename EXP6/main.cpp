#include <stdio.h>

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

int main() {
    char mostFrequent = 'B';  // Most frequent letter in the ciphertext
    char secondMostFrequent = 'U';  // Second most frequent letter in the ciphertext

    int y1 = mostFrequent - 'A' + 1;
    int y2 = secondMostFrequent - 'A' + 1;

    // Calculate a and b
    int a = (y2 - y1 + 26) % 26;
    int x1Inverse = modInverse(y1, 26);
    if (x1Inverse == -1) {
        printf("Error: Modular inverse does not exist.\n");
        return 1;
    }
    int b = (y1 - a * x1Inverse + 26) % 26;

    // Display the calculated key values
    printf("Calculated Key Values:\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);

    return 0;
}

