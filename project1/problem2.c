// Written by Zachary Stephens
#include<stdio.h>
#include<stdlib.h>

char convertToChar(int z)
{
    switch(z)
    {
        case 1 :
            return '1';
        break;
        case 2 :
            return '2';
        break;
        case 3:
            return '3';
        break;
        case 4:
            return '4';
        break;
        case 5:
            return '5';
        break;
        case 6:
            return '6';
        break;
        case 7:
            return '7';
        break;
        case 8:
            return '8';
        break;
         case 9:
            return '9';
        break;
        case 10 :
            return 'a';
        break;
        case 11 :
            return 'b';
        break;
        case 12:
            return 'c';
        break;
        case 13:
            return 'd';
        break;
        case 14:
            return 'e';
        break;
        case 15:
            return 'f';
        break;
    }
}


void convertToHex(char *final, int r, int g, int b)
{

    int bitMask = 0b1111;

    final[0] = '#';
    final[1] = convertToChar(r >> 4);
    final[2] = convertToChar(r & bitMask);
    final[3] = convertToChar(g >> 4);
    final[4] = convertToChar(g & bitMask);
    final[5] = convertToChar(b >> 4);
    final[6] = convertToChar(b & bitMask);


    //char rr = convertToChar(r >> 4);
    //char rrr = convertToChar(r & bitMask);

    //printf("Jason: %c\n", rr);
    //printf("Dima: %c\n", rrr);

}

int main()
{
    char result[8];

    convertToHex(result, 100,150,200);
    printf("Result: %s\n", result);

    return 0;
}