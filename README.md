# Questions

## What's `stdint.h`?

A header file including the definitions of all new integer data types.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

They are needed to form the data types of byte, unsigned integer, signed integer and string respectively.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1, 4, 4, 2.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x42 and 0x4d

## What's the difference between `bfSize` and `biSize`?

bfSize is the size, in bytes, of the entire bitmap file including the two headers. biSize is the size, in bytes, of the BITMAPINFOHEADER structure.

## What does it mean if `biHeight` is negative?

The file is a top-down DIB. The first bytes in memory make up the top left pixel, and the top row of the image is the top row in memory.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

The file to be copied might not exist.

## Why is the third argument to `fread` always `1` in our code?

We only need to read each structure once.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3.

## What does `fseek` do?

It changes the location of the file pointer.

## What is `SEEK_CUR`?

It is the new position of the file pointer in relation to its current position.
