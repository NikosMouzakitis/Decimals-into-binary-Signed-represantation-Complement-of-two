#include <stdio.h>
#include<math.h>
#include <stdlib.h>

struct binary_representation_8 {
    int bits[8];
} binary,*pb;


// Written by Mouzakitis Nikolaos,March 2016.

//-----------------------------------------------------------------------------------//
//One's & Two's complement implementation.Using the binary_representation_8 struct.
//             (actually its an array of 8 integers.)
//-----------------------------------------------------------------------------------//


void one_complement(struct binary_representation_8 *bin_rep)
{
        int i;
        for(i = 0; i < 8 ; i ++)
        {
                if( bin_rep->bits[i] == 0)
                        bin_rep->bits[i] = 1;
                else
                        bin_rep->bits[i] = 0;
        }
//switching vice - versa the digits 0->1,and so on..
}

int main(void)
{
    int i,j,n,rm;
    pb = &binary;
    printf("Enter a possitive integer\n");
    scanf("%d",&i);

    if(i == 0)
    {
        binary.bits[0] = 0;
        binary.bits[1] = 0;
        binary.bits[2] = 0;
        binary.bits[3] = 0;
        binary.bits[4] = 0;
        binary.bits[5] = 0;
        binary.bits[6] = 0;
        binary.bits[7] = 0;
    }
    else if  ( i < 0 )
    {
        printf("Number is not possitive.\n");
        exit(1);

    }
    else if (i >255)
    {
        printf("Too large.enter possitive between 0-255");
        exit(1);
    }
    else if ( i == 1)
    {
        binary.bits[0] = 0;
        binary.bits[1] = 0;
        binary.bits[2] = 0;
        binary.bits[3] = 0;
        binary.bits[4] = 0;
        binary.bits[5] = 0;
        binary.bits[6] = 0;
        binary.bits[7] = 1;
    }

    else
    {
        for( n = 0; pow(2.0,n) <= i; n++)
            ;

        rm = 8 - n;

        binary.bits[0] =0;

        rm --;
        for(j = 0; j < rm; j++)
            binary.bits[j+1] = 0;
        n--;
        while(n >= 0) {

            if( i >= pow(2.0,n))
            {
                rm ++;
                binary.bits[rm] =1;
                i = i % (int ) pow(2.0,n);
                n--;
            }
            else if (i < pow(2.0,n))
            {
                rm ++;
                binary.bits[rm] = 0;
                n--;
            }

        }

    }
    printf("Binary representation: ");
    for( i = 0; i< 8; i++)
        printf("%d",binary.bits[i]);
    one_complement(pb);
    printf("\n");
    printf("One's complement      :");
    for(i = 0; i < 8 ;i++)
        printf("%d",binary.bits[i]);
    printf("\n");

    return 0;
}
