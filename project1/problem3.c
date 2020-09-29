// Written by Zachary Stephens
#include<stdio.h>

//returns the value of an
int binarySplitA(int n)
{
    //i1, i3, i5 ...
    int an = 0;
    int bitMask = 0b1;
    //starts true to capture first 1 bit
    int alternator = 1;

    for(int i = 0; i < 32; i++)
    {
        if(n & bitMask)
        {
            if (alternator)
            {
                an |= bitMask;
                alternator = 0;
            }
            else
            {
                alternator = 1;
            }
        }

        bitMask <<= 1;
    }

    return an;
}

//returns the valueof bn
int binarySplitB(int n)
{
    //i2, i4, i6 ...
    int bn = 0;
    int bitMask = 0b1;
    //starts false to capture 2nd 1 bit
    int alternator = 0;

    for(int i = 0; i < 32; i++)
    {
        if(n & bitMask)
        {
            if (alternator)
            {
                bn |= bitMask;
                alternator = 0;
            }
            else
            {
                alternator = 1;
            }
        }

        bitMask <<= 1;
    }

    return bn;
}

int main()
{
    int input;

    do
    {
        scanf("%d\n", &input);
        //printf("%d\n", input);
        if (input != 0)
        {
            printf("%d %d\n", binarySplitA(input), binarySplitB(input));
        }
    } while (input != 0);


    return 0;
}

//Testing
//gcc problem3.c -o problem3
//./problem3 < test3.in