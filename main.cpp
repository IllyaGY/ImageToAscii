#include <iostream>
#include <vector>
#include <fstream>
#include <ostream>
#include <filesystem>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STBI_NO_HDR


int main() {


    int scanlineInc = 1;
    std::string imgName = "";
    std::cin >> scanlineInc;
    std::cin >> imgName;

    std::ofstream file("image.txt");


    std::vector<char> set {'@','#','8', '&','o',':','*','.',' '};

    char *pixelsSet = nullptr;




    int x,y,n;
    unsigned char *data = stbi_load(imgName.c_str(), &x, &y, &n, 0);


    for(int scanlines = 0; scanlines < y; scanlines+=scanlineInc) {
        int arrCount = 0;
        static int ma = 0;
        pixelsSet = new char [x];
        for (int pixels = 0; pixels < x; pixels++) {
            int r,g,b;
            r = *(data + (scanlines * x + pixels) * unsigned(n) + 0);
            g = *(data + (scanlines * x + pixels) * unsigned(n) + 1);
            b = *(data + (scanlines * x + pixels) * unsigned(n) + 2);
            int maxN = std::max(r/31, g/31);
            maxN = std::max(maxN, b/31);
            pixelsSet[arrCount] = set.at(maxN);
            arrCount++;
        }
        file.write (pixelsSet, x-1);
        file.write("\r\n",4);
    }

    delete [] pixelsSet;


    file.close();

    //std::cout << (int)data[0] << (int)data[1] << (int)data[2];

    //printf("Picture is of %i by %i pixels, channel %i",x,y,n);

    stbi_image_free(data);


    return 0;
}
