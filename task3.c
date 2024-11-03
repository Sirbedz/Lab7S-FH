#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *bitFile, *hexFile;
    char bit;
    unsigned char byte = 0;
    int bitCount = 0;

    bitFile = fopen("bitstream.bit", "r");
    if (bitFile == NULL) {
        printf("Error opening bitstream.bit file.\n");
        return 1;
    }

    hexFile = fopen("bitstream.hex", "w");
    if (hexFile == NULL) {
        printf("Error creating bitstream.hex file.\n");
        fclose(bitFile);
        return 1;
    }

    while ((bit = fgetc(bitFile)) != EOF) {
        if (bit == '0' || bit == '1') {
            byte = (byte >> 1) | ((bit - '0') << 7);
            bitCount++;

            if (bitCount == 8) {
                fprintf(hexFile, "%02X\n", byte);
                byte = 0;
                bitCount = 0;
            }
        }
    }

    if (bitCount > 0) {
        byte >>= (8 - bitCount);
        fprintf(hexFile, "%02X\n", byte);
    }

    fclose(bitFile);
    fclose(hexFile);

    printf("Conversion complete. Output written to bitstream.hex.\n");
    return 0;
}

