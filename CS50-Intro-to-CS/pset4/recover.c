// ************************************************************************* //
/*
CS50 - Week 3: Recover
- Assignment: I need to read the card.raw file and return 50 jpegs.

- This is what I think I need to do:
  - open the file using fopen
  - read the file using fread
    - because I know the first three bytes of a JPEG are: 0xff 0xd8 0xff, I can look for them
    - the first 4 bits of the 4th byte are 1110 so I can look for that as well.
*/
// ************************************************************************* //
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Checks for two arguments => the second being the file we are reading (card.raw)
    if (argc != 2)
    {
        fprintf(stderr, "This program requires the name of the file that you wish to recover.\n");
        return 1;
    }

    // Grabs the file at index 1 (second argument) and sets it to 'infile'
    char* infile = argv[1];

    // opens the infile
    FILE *inptr = fopen(infile, "r");

    // if inptr is null, you can't open the file
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    unsigned char buffer[512];               // buffer variable; holds a single block of 512 bytes

    // int i = 0;
    int fileCount = 0;        // fileCount variable
    FILE *img = NULL;        // initialize first image file


    // *************************************************************************************** //
    // Iterate over file contents using fread
    // fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
    // ptr − This is the pointer to a block of memory with a minimum size of size*nmemb bytes.
    //      buffer => this is the block of memory that RECEIVES the content that is being read
    // size − This is the size in bytes of each element to be read.
    //      512 => this is how big each block is; we KNOW THIS from the problem set instructions
    //              and that this is how big a block is for JPEGs
    // nmemb − This is the number of elements, each one with a size of size bytes.
    //      1 => number of elements we are reading
    // stream − This is the pointer to a FILE object that specifies an input stream.
    //      inptr => this is the file we are reading
    // *************************************************************************************** //

    // this loop only continues if we are successfully reading from the file. If the number differs
    // from the nmemb parameter (for us it is 1), than either an error occurred OR it's the end of
    // the file. Assuming no error, this loop will close when we reach the end of the file
    while (fread(buffer, 512, 1, inptr))
    {
        // Looks for the JPEG signature. If these conditions are true, that is the beginning of a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
            && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            // we set img to NULL initially but if it is not null, we must CLOSE the current file
            if (img != NULL) {
                fclose(img);
            }

            // filename
            char filename[8];
            sprintf(filename, "%03d.jpg", fileCount);

            // Open a new JPEG file for writing
            img = fopen(filename, "w");

            // increment the fileCount
            fileCount++;
        }

        // Case #1: Block of memory (buffer) does NOT match JPEG signature AND img == NULL: we haven't found a JPEG
        //          yet therefore there is nothing to write
        // Case #2: The buffer DOES match the JPEG signature AND img == NULL: this is our first JPEG. Because we met
        //          the conditions above, img is NULL so nothing to close, we initialize a filename and write it using
        //          the proper fileCount, we set img to fopen(filename, "w"), and then increment the fileCount.
        //          Now that img != NULL, we write our buffer variable to img
        // Case #3: The buffer does NOT match the JPEG signature AND img != NULL: this means that we still writing the
        //          previous file. So, we simply write our buffer to our img file
        // Case #4: The buffer DOES match the JPEG signature AND img != NULL: this means that we currently have a file
        //          open AND this current buffer marks the start of a new one. We must close the old one first but only
        //          if img != NULL. This is really only applicable for the first JPEG.
        if (img != NULL) {
            fwrite(buffer, 512, 1, img);
        }
    }

    // This case will be reached when the loop closes (we have finished reading inptr). If img != NULL, we
    // need to close it. Given that we know there are 50 JPEG's in the file, we could probably just fclose(img)

    if (img != NULL) {
        fclose(img);
    }

    // close the file we are reading.
    fclose(inptr);

    return 0;
 }