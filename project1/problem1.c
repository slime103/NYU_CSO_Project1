// implement your program here
#include<stdio.h>

int compressDate(int MM, int DD, int hh, int mm, int ss)
{
    int  final = 0;

    //verify input
    if (MM > 12 || DD > 31 || hh > 23 || mm > 59 || ss > 59 || MM <= 0 || DD <= 0)
    {
        return 0;
    }

    //load the bits in from right to left i.e months -> days etc. and tens -> ones

    //bit 30 - month tens
    final |= (MM >= 10) ? 0b1 << 30 : 0;

    //bit 26 - 29 - month ones
    final |= (MM%10) << 26;

    //bits 24 - 25 - days tens
    final |= (DD/10) << 24;

    //bits 20-23 - days ones
    final |= (DD%10) << 20;

    //bits 18-19 - hours tens
    final |= (hh/10) << 18;

    //bits 14-17 - hours ones
    final |= (hh%10) << 14;

    //bits 11-13 - minutes tens
    final |= (mm/10) << 11;

    //bits 7-10 - minutes ones
    final |= (mm%10) << 7;

    //bits 4-6 - seconds tens
    final |= (ss/10) << 4;

    //bits 0-3 - seconds ones
    final |= (ss%10);

    return final;
}

int decompressDate(int dateTime)
{
    return dateTime;
}

int main()
{
    //Test Value 11/25 12:53:32
    printf("Compressed Date/time: %d \n", compressDate(11,25,12,53,32));
    printf("1179953586\n");


    return 0;
}