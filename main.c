#include "GeneralFunctions.h"
#include "BmpAnalyzer.h"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        print_err_usage();
        return 1;
    }

    const char *file_path = argv[1];

    int file_check_result = check_file(file_path);
    if (file_check_result != 0) {
        return file_check_result;
    }

    print_bmp_info(file_path);

    return 0;
}
