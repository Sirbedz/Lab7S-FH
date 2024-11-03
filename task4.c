#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int caesarCipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((text[i] - 'A' + shift + 26) % 26) + 'A';
        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((text[i] - 'a' + shift + 26) % 26) + 'a';
    }
    return 0;
}

int encryptFromFile(const char *inputFilename, const char *outputFilename, int shift) {
    FILE *file = fopen(inputFilename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error creating output file.\n");
        fclose(file);
        return 1;
    }

    char text[1000];
    while (fgets(text, sizeof(text), file) != NULL) {
        caesarCipher(text, shift);
        fputs(text, outputFile);
    }

    fclose(file);
    fclose(outputFile);
    return 0;
}

int encryptFromString(char *text, int shift) {
    caesarCipher(text, shift);
    printf("Encrypted text: %s\n", text);
    return 0;
}

int main() {
    char choice, method, filename[50], text[1000];
    int shift = -3;

    printf("Do you want to perform (E)ncryption or (D)ecryption?\n> ");
    scanf(" %c", &choice);
    if (choice == 'D') shift = 3;

    printf("Do you want to use a (F)ile or enter a (S)tring?\n> ");
    scanf(" %c", &method);

    if (method == 'F') {
        printf("Enter the filename: ");
        scanf("%s", filename);
        const char *outputFilename = (choice == 'E') ? "encrypted.txt" : "decrypted.txt";
        if (encryptFromFile(filename, outputFilename, shift) == 0) {
            printf("Operation complete. Check %s.\n", outputFilename);
        } else {
            printf("File encryption/decryption failed.\n");
        }
    } else if (method == 'S') {
        printf("Enter the text: ");
        scanf(" %[^\n]s", text);
        if (encryptFromString(text, shift) == 0) {
            printf("%s text: %s\n", choice == 'E' ? "Encrypted" : "Decrypted", text);
        } else {
            printf("String encryption/decryption failed.\n");
        }
    }

    return 0;
}

