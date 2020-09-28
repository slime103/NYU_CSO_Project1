// Written by Zachary Stephens
#include<stdio.h>
#include<stdlib.h>

//Takes an int 0-15 to convert to Hex Value char
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
        default:
            return '0';
    }
}

//Takes RGB int values to convert to characters and insert into a char[]
void convertToHex(char *final, int r, int g, int b)
{
    //validate input
    if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b <0)
    {
        final[0] = 'I';
        final[1] = 'N';
        final[2] = 'V';
        final[3] = 'A';
        final[4] = 'L';
        final[5] = 'I';
        final[6] = 'D';
        return;
    }

    int bitMask = 0b1111;

    final[0] = '#';
    final[1] = convertToChar(r >> 4);
    final[2] = convertToChar(r & bitMask);
    final[3] = convertToChar(g >> 4);
    final[4] = convertToChar(g & bitMask);
    final[5] = convertToChar(b >> 4);
    final[6] = convertToChar(b & bitMask);

}

int main()
{
    char result[8];

    int n;

    int r,g,b;

    scanf("%i", &n);

    //printf("%i\n", n);

    for(int i = 0; i < n; i++)
    {
        //Grab input
        scanf("%d %*s %d %*s %d\n", &r,&g,&b);
        //printf("%d %d %d\n", r,g,b);

        //put the input into result
        convertToHex(result, r,g,b);
        printf("%s\n", result);
    }

    return 0;
}


//Testing
//gcc problem2.c -o problem2
//./problem2 < test2.in