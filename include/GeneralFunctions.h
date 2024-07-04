#pragma once

#ifndef BMP_READER_GENERAL_FUNCTIONS_H
#define BMP_READER_GENERAL_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define error(...) fprintf(stderr, __VA_ARGS__)

void print_err_usage();

int check_file(const char *file_path);
int is_bmp_format(const char *filename);

#endif //BMP_READER_GENERAL_FUNCTIONS_H
