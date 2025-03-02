#include "bmp.h"

int main(){
    image o_file;

    // INITIALLISING BMP HEADER WHICH DESCRIBES THE BMP FILE
    o_file.file_header.header.signature[0] = 'B';
    o_file.file_header.header.signature[1] = 'M';
    o_file.file_header.header.file_size    = sizeof(o_file);
    o_file.file_header.header.reserved     = 0;
    o_file.file_header.header.data_offset  = sizeof(o_file.file_header);

    // INITIALLISING DIB HEADER WHICH DESCRIBES THE BMP IMAGE
    o_file.file_header.dib_header.dib_size = sizeof(o_file.file_header.dib_header);
    o_file.file_header.dib_header.width = SQUARE_SIZE;
    o_file.file_header.dib_header.height = SQUARE_SIZE;
    o_file.file_header.dib_header.num_of_planes = 1;
    o_file.file_header.dib_header.bits_per_pixel = sizeof(pixel) * 8;
    o_file.file_header.dib_header.compression = 0;
    o_file.file_header.dib_header.image_size = sizeof(o_file.pixel_data);
    o_file.file_header.dib_header.x_resolution = 0;
    o_file.file_header.dib_header.y_resolution = 0;
    o_file.file_header.dib_header.num_of_colors = 0;
    o_file.file_header.dib_header.important_colors = 0;

    // generating pixel data
    for(int x = 0; x < SQUARE_SIZE; x++){
        for(int y = 0; y < SQUARE_SIZE; y++){
            o_file.pixel_data[x][y].red = 150;
            o_file.pixel_data[x][y].green = 255;
            o_file.pixel_data[x][y].blue = 20;
        }
    }

        // WRITING BMP FILE
        FILE *file = fopen("square.bmp", "wb");
        if (!file){
            printf("ERROR CREATING FILE.\n");
            return 1;
        }

        fwrite(&o_file, sizeof(o_file), 1, file);
        fclose(file);
        return 0;
}
