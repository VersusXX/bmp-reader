#include <stdint.h>
#include "GeneralFunctions.h"

void print_err_usage() {
    error("Usage: ./BMP_Reader [bmp_file_location]");
}

int file_exists(FILE *file) {
    if (file) {
        return 1;
    }
    return 0;
}

// Check if the file has a .bmp extension
int is_bmp_format(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if (!dot || strcmp(dot, ".bmp") != 0) {
        return 0;
    }

    return 1;
}

int check_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file_exists(file)) {
        error("Error: File does not exist: %s\n", file_path);
        return 2;
    }

    if (!is_bmp_format(file_path)) {
        error("Error: File is not in BMP format: %s\n", file_path);
        return 2;
    }

    // Check BMP file magic number
    uint16_t bfType;
    fread(&bfType, sizeof(uint16_t), 1, file);
    fclose(file);

    if (bfType != 0x4D42) { // 'BM' in little-endian
        error("Error: %s is not a valid BMP file\n", file_path);
        return 2;
    }

    return 0;
}