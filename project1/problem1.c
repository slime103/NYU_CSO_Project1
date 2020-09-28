// Written by Zachary Stephens
#include<stdio.h>

//validates whether a given day is in a given month
int validateDay(int MM, int DD)
{
    switch (MM)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (DD <= 31)
            {
                return 1;
            }
        break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (DD <= 30)
            {
                return 1;
            }
        break;
        case 2:
            if (DD <= 29) //29 to include leap years
            {
                return 1;
            }
        break;
    }
    return 0;
}

//Takes Date and Time integers and stores them in a single int32
int compressDate(int MM, int DD, int hh, int mm, int ss)
{
    int  final = 0;

    //verify input
    if (MM > 12 || DD > 31 || hh > 23 || mm > 59 || ss > 59 || MM <= 0 || DD <= 0)
    {
        return 0;
    }
    if (!validateDay(MM,DD))
    {
        return 0;
    }

    //set the bits from left to right i.e months -> days etc. and tens -> ones

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
    //TODO
    return dateTime;
}

int main()
{
    int n;

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        //11/25 12:53:32
        int MM,DD,hh,mm,ss;
        char temp;

        scanf("%d %c %d %d %c %d %c %d\n", &MM,&temp,&DD,&hh,&temp,&mm,&temp,&ss);
        printf("%d/%d  %d:%d:%d\n", MM,DD,hh,mm,ss);

        if (compressDate(MM,DD,hh,mm,ss))
        {
            printf("Compressed Version: %d \n", compressDate(MM,DD,hh,mm,ss));
        }
        else
        {
            printf("INVALID\n");
        }
    }

    return 0;
}

//Testing
//gcc problem1.c -o problem1
//./problem1 < test1.in