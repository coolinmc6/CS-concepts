// ************************************************************************* //
// CS50 - Week 3: Resize
// this program resizes a bitmap file

// Key Take-aways:
//      - this isn't an "algorithm" problem; this is a know-what-a-bitmap-file-is problem. That means
//      that diving right in without understanding what a BITMAPFILEHEADER is WILL NOT WORK. Right away,
//      I should have AT THE VERY LEAST taken a look at the bmp.h file and the bitmap specs to get some
//      definitions...I wasted time trying to solve something that I didn't have the tools to solve (right away).
//      - The algorithm part was easy: write each pixel n times and do that for each line n times
//      - Why re-write the original variables (bi, bf)? Just create copies and move on. Creating those
//      other variables simplifies things
//      - Again, understand what a scanline is in bitmpap. Each scanline must be a multiple of 4 bytes and RGBTRIPLE's are
//      three bytes. So when an image is scaled, its scanline bytes change and therefore the padding must change
//      - make sure you are writing the fileheader and infoheader correctly.

// ************************************************************************* //

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // Code Given => only change was to argc from 3 to 4 => [file_name] [n] [input file] [output file]
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // Grab multiplier (n) and remember filenames
    int n = atoi(argv[1]);
    char *infile = argv[2];     // Code Given
    char *outfile = argv[3];    // Code Given

    // open input file => Code Given
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file => Code Given
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    // CM => instantiating two new variables of type BITMAPFILEHEADER
    // bf => the original file header we want to resize
    // bf_new => the new file header / result of the resizing
    BITMAPFILEHEADER bf, bf_new;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_new = bf;

    /*
    BITMAPFILEHEADER => variable is `bf` in this file
    WORD bfType; => The file type; must be BM
    DWORD bfSize; => The size, in bytes, of the bitmap file
    WORD bfReserved1; => Reserved; must be zero.
    WORD bfReserved2; => Reserved; must be zero.
    DWORD bfOffBits; => The offset, in bytes, from the beginning of the BITMAPFILEHEADER structure to the bitmap bits.
    */
    // printf("%c\n", bf.bfType);
    // printf("%d\n", bf.bfSize);
    // printf("%d\n", bf.bfReserved1);
    // printf("%d\n", bf.bfReserved2);
    // printf("%d\n", bf.bfOffBits);

    // read infile's BITMAPINFOHEADER
    // CM => instantiating two new variables of type BITMAPINFOHEADER
    // bi = the original info header
    // bi_new = the new / resized info header
    BITMAPINFOHEADER bi, bi_new;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_new = bi;

    /*
    BITMAPINFOHEADER
    DWORD biSize; => The number of bytes required by the structure.
    LONG biWidth; => The width of the bitmap, in pixels.
    LONG biHeight; => The height of the bitmap, in pixels.
    WORD biPlanes; => The number of planes for the target device. This value must be set to 1.
    WORD biBitCount; => The number of bits-per-pixel. Can be only the following values: 0,1,4,8,16,24,32
    DWORD biCompression; => The type of compression for a compressed bottom-up bitmap (top-down DIBs cannot be compressed).
    DWORD biSizeImage; => The size, in bytes, of the image. This may be set to zero for BI_RGB bitmaps.
    LONG biXPelsPerMeter; => The horizontal resolution, in pixels-per-meter, of the target device for the bitmap.
    LONG biYPelsPerMeter; => The vertical resolution, in pixels-per-meter, of the target device for the bitmap
    DWORD biClrUsed; => The number of color indexes in the color table that are actually used by the bitmap.
    DWORD biClrImportant; => The number of color indexes that are required for displaying the bitmap. If this value is zero, all colors are required.
    */

    // Code Given
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // **************************************************************************** //
    // By this point, we have read the file and have the following variables:
    //      n = resize multiplier
    //      bf and bf_new = BITMAPFILEHEADER
    //      bi and bi_new = BITMAPINFOHEADER
    // Most of the code written above is from the copy.c code I've been given
    // The only things that I've done are receive the multiplier variable and create variables for the
    // BITMAPFILEHEADER and BITMAPINFOHEADER. I haven't done ANY calculations yet.

    // Before I write anything, I need to the following:
    //      - bi_new.biWidth = bi.biWidth * n
    //      - bi_new.biHeight = bi.biHeight * n
    //      - bi_new.biSizeImage = ((biWidth * n) * sizeof(RGBTRIPLE) + padding) * abs(biHeight * n)
    //      - bf_new.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + biSizeImage

    // Everything builds off the new dimensions and the new width or height are just w * n or h * n
    bi_new.biWidth = bi.biWidth * n;
    bi_new.biHeight = bi.biHeight * n;

    // Calculate the new padding because the dimensions have changed
    // I need a multiple of four
    //      if 4 RGBTRIPLE's, no change is needed REGARDLESS of factor
    //      if 5 RGBTRIPLE's, I'd normally need 1 byte of padding but here I need 2 (10*3) + 2 = 32
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding_new = (4 - (bi_new.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Calculate the new sizes using the formulas from the lectures
    bi_new.biSizeImage = ((bi_new.biWidth) * sizeof(RGBTRIPLE) + padding_new) * abs(bi_new.biHeight);
    bf_new.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi_new.biSizeImage;

    // write outfile's BITMAPFILEHEADER => CODE GIVEN
    fwrite(&bf_new, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER => CODE GIVEN
    fwrite(&bi_new, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    // This outer loop iterates overall every line of the infile
    // For each individual line, I need to write each pixel n times
    // And because I need n rows in the outfile for every 1 row of the infile, I need to
    // read each line, write the pixel n times, and then fseek BACK and do it again
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++) // copy.c
    {
        // this is the inner loop. This loop runs n times to generate n rows per single row of the infile
        for(int inner = 0; inner < n; inner++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage => NO CHANGE
                RGBTRIPLE triple;

                // read RGB triple from infile => NO CHANGE
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile => MODIFIED
                // this needs to be done n times for each pixel
                for(int pixel = 0; pixel < n; pixel++) {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

            }
            // At this point, I have written each pixel n times. I now need to add the padding to complete the line
            // Add a new padding
            for (int l = 0; l < padding_new; l++) {
                fputc(0x00, outptr);
            }

            // I now have a complete line. My next step is dependent upon which iteration I'm in. If I have written
            // the 1st row of 3 rows, I need to move my cursor to the beginning of the scanline
            // Return to the beginning of a scanline
            if (inner < n - 1) {
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
            }

        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

    }
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}