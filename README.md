<div align="center">

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/license/mit)
<h1>BMP Header Reader</h1>

</div>

This project is a C application that reads a BMP image file and prints the BMP headers in a
human-readable format. The application supports BMP versions 3, 4, and 5.

## Features

- Reads BMP image files
- Prints BMP headers in a readable format
- Supports BMP versions 3, 4, and 5

## Example Output

```text
./main example.bmp
Width : 9
Height : 9
Planes : 1
Bits/pixel : 24
Compression : none
Image Size : 252
Pixels/meter : 3779x3779
```

## Requirements

- C Compiler (GCC recommended)
- QEMU
- Cross-compiler for ARM or RISC-V

## Installation

### 1. Install QEMU

```shell
sudo apt install qemu-user
```

### 2. Install Cross-Toolchain

For ARM:

```shell
sudo apt install gcc-arm-linux-gnueabi
```

For RISC-V:

```shell
sudo apt install gcc-riscv64-linux-gnu
```

## Building the Application

### Cross-Compile for RISC-V

```shell
riscv64-linux-gnu-gcc -static -I./include main.c src/GeneralFunctions.c src/BmpAnalyzer.c -o main.out
```

### Cross-Compile for ARM

```shell
arm-linux-gnueabi-gcc -static -I./include main.c src/GeneralFunctions.c src/BmpAnalyzer.c -o main.out
```

### Run with QEMU

```shell
qemu-riscv64 ./main example.bmp
```

Or

```shell
qemu-arm ./main example.bmp
```

## License

See [LICENSE][license-url] for more information.

[license-url]: https://github.com/VersusXX/bmp-reader/blob/main/LICENSE