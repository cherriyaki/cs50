#include <stdio.h>
#include <stdlib.h>
#define BLOCKNUM 512

int main(int argc, char *argv[])
{
    //create block array, its date type being a byte (repped by unsigned char)
    unsigned char block[BLOCKNUM];

    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // open input file
    FILE *cardp = fopen(argv[1], "r");
    if (cardp == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    // create ints: stating jpeg found status, new jpeg number
    int isjpgfound = 0;
    int jpgnum = 0;

    // create array for jpg name
    char jpeg[8];

    // make output file
    FILE *imgp;

    // iterate over each block only if block is size of blocknum
    while (fread(block, BLOCKNUM, 1, cardp) == 1)
    {
        // if new jpeg read
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            // if prev jpeg has already been found
            if (isjpgfound == 1)
            {
                // close previous image
                fclose(imgp);
            }
            else // if jpeg not yet found
            {
                // update found status
                isjpgfound = 1;
            }

            // open new jpeg
            sprintf(jpeg, "%03i.jpg", jpgnum);
            imgp = fopen(jpeg, "w");
            jpgnum++;
        }

        // now on current jpeg
        if (isjpgfound == 1)
        {
            // write to current image
            fwrite(block, BLOCKNUM, 1, imgp);
        }
    }

    // close all files
    fclose(imgp);
    fclose(cardp);

    // success
    return 0;
}