#include <stdio.h>
#include "BmpAnalyzer.h"

// Prints the BMP header information
void print_bmp_info(const char *file_path) {
    FILE *file = fopen(file_path, "rb");

    BMPHeader bmpHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, file);

    printf("Width            : %d\n", bmpHeader.width_px);
    printf("Height           : %d\n", bmpHeader.height_px);
    printf("Planes           : %d\n", bmpHeader.num_planes);
    printf("Bits/pixel       : %d\n", bmpHeader.bits_per_pixel);

    const char *compression_type;
    switch (bmpHeader.compression) {
        case 0:
            compression_type = "none";
            break;
        case 1:
            compression_type = "RLE 8-bit/pixel";
            break;
        case 2:
            compression_type = "RLE 4-bit/pixel";
            break;
        case 3:
            compression_type = "bit field or Huffman 1D";
            break;
        case 4:
            compression_type = "JPEG";
            break;
        case 5:
            compression_type = "PNG";
            break;
        default:
            compression_type = "unknown";
            break;
    }
    printf("Compression      : %s\n", compression_type);
    printf("Image Size       : %u\n", bmpHeader.size);
    printf("Pixels/meter     : %dx%d\n", bmpHeader.x_resolution_ppm, bmpHeader.y_resolution_ppm);

    fclose(file);
}