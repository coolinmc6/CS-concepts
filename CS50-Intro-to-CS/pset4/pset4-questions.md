# Questions

## What's `stdint.h`?
- The `stdint.h` is a header file in the C Standard Library that specify various integer types.
- The C Standard Library is a standardized collection of header files (and library routines) used to implement common
operations

[https://en.wikibooks.org/wiki/C_Programming/stdint.h](https://en.wikibooks.org/wiki/C_Programming/stdint.h)

[https://en.wikibooks.org/wiki/C_Programming/Standard_libraries](https://en.wikibooks.org/wiki/C_Programming/Standard_libraries)

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?
- these are integer types of exact, specified sizes (i.e. uint8_t is 8 bits or 1 byte)
- it allows you to fill place, exactly, certain values in certain spots where it is needed. For example,
in the Bitmap file header

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?
- BYTE = 1 byte or 8 bits
- DWORD = 4 bytes or 32 bits
- LONG = 4 bytes or 32 bits
- WORD = 2 bytes or 16 bits

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."
- the letters BM in hexadecimal (0x42 0x4D)

## What's the difference between `bfSize` and `biSize`?
- bfSize = biSize + biSizeImage
- bfSize is the TOTAL size of the file. That total is the sum of the size of the file header and the size of the image
- biSize is the size of the file header
  - this can be broken into two parts: a file header and an info header
- biSizeImage is the size of the image
- We could re-write the whole equation as:
  - bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + biSizeImage
- ...and because we know the size of BITMAPFILEHEADER (exactly 14 bytes) and the size of
BITMAPINFOHEADER (exactly 40 bytes), we know that bfSize = 54 + biSizeImage (we don't do this because it is not best practice)

## What does it mean if `biHeight` is negative?
- If biHeight is positive, the bitmap is a bottom-up DIB and its origin is the lower-left corner.
- If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.
- DIB = device independent bitmap

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?
- biBitCount
- Great source for a breakdown of each item: [https://msdn.microsoft.com/en-us/library/windows/desktop/dd183376(v=vs.85).aspx](https://msdn.microsoft.com/en-us/library/windows/desktop/dd183376(v=vs.85).aspx)

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

- (More generally) There are many reasons fopen can return NULL including (but certainly not limited to):
  - The file doesn't exist
  - The file is opened in a mode that doesn't allow other accesses
  - The network is down
  - The file exists, but you don't have permissions
  - A file exists with the name you gave, but the current directory of the process is not what you
  expected so the relative pathname fails to find and open the file.

## Why is the third argument to `fread` always `1` in our code?
- The third argument is the number of elements and we always have 1 element

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?
- `int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;`

- (4-(3*3) % 4) % 4
- (4 - 1) % 4
- 3 % 4 = 3


## What does `fseek` do?
- It sets the file position of the stream to the given offset OR IN OTHER WORDS....it moves to a specific location in a file

## What is `SEEK_CUR`?
- SEEK_CUR is a a constant of fseek and it moves file pointer position to given location.

## Sources

- [https://github.com/sebpearce/cs50/blob/master/pset5/questions.txt](https://github.com/sebpearce/cs50/blob/master/pset5/questions.txt)
- [https://github.com/davidventuri/harvard-cs50/blob/master/pset4/questions.txt](https://github.com/davidventuri/harvard-cs50/blob/master/pset4/questions.txt)
- [https://github.com/nastysloper/cs50x-pset4/blob/master/questions.txt](https://github.com/nastysloper/cs50x-pset4/blob/master/questions.txt)
- [https://www.craigrodrigues.com/blog/2016/07/05/learning-to-code-week-8](https://www.craigrodrigues.com/blog/2016/07/05/learning-to-code-week-8)
- [https://stackoverflow.com/questions/25713117/what-is-the-difference-between-bisizeimage-bisize-and-bfsize](https://stackoverflow.com/questions/25713117/what-is-the-difference-between-bisizeimage-bisize-and-bfsize)
-
