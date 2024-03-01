#include <stdio.h>

char monocipher_encr(char);

char alpha[26][2] = {
    {'a', 'f'}, {'b', 'a'}, {'c', 'g'}, {'d', 'u'},
    {'e', 'n'}, {'f', 'i'}, {'g', 'j'}, {'h', 'k'},
    {'i', 'l'}, {'j', 'm'}, {'k', 'o'}, {'l', 'p'},
    {'m', 'q'}, {'n', 'r'}, {'o', 's'}, {'p', 't'},
    {'q', 'v'}, {'r', 'w'}, {'s', 'x'}, {'t', 'y'},
    {'u', 'z'}, {'v', 'b'}, {'w', 'c'}, {'x', 'd'},
    {'y', 'e'}, {'z', 'h'}
};

int main() {
    char str[20], str2[20];
    int i;

    printf("\n Enter String: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        str2[i] = monocipher_encr(str[i]);
    }

    str2[i] = '\0';
    printf("\n Before Encryption: %s", str);
    printf("\n After Encryption: %s\n", str2);

    return 0;
}

char monocipher_encr(char a) {
    int i;

    for (i = 0; i < 26; i++) {
        if (a == alpha[i][0]) {
            break;
        }
    }

    return alpha[i][1];
}

