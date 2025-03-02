#include <stdio.h>
#include <string.h>

#define SQUARE_SIZE 24

typedef struct{
    struct {
        char signature[2];
        unsigned int file_size;
        unsigned int reserved;
        unsigned int data_offset;
    } __attribute__((packed)) /*<-> INSTRUCTION FOR THE COMPILER
                              PLACE OE PACK THE BITS OF STRUCT TOGETHER*/ header;

    struct {
        unsigned int dib_size;
        signed int width;
        signed int height;
        unsigned short num_of_planes;
        unsigned short bits_per_pixel;
        unsigned int compression;
        unsigned int image_size;
        signed int x_resolution;
        signed int y_resolution;
        unsigned int num_of_colors;
        unsigned int important_colors;
    } __attribute__((packed)) dib_header;
} __attribute__((packed)) bmp_header;

typedef struct {
    // NOTHING
} __attribute__((packed)) color_palatte;

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} __attribute__((packed)) pixel;

typedef struct {
    bmp_header file_header;
    color_palatte palatte;
    pixel pixel_data[SQUARE_SIZE][SQUARE_SIZE];
} __attribute__((packed)) image; 
