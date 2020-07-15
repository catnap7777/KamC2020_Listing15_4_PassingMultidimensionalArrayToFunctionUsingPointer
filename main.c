//Listing 15_4 Passing a multidimensional array to a function using a pointer; page 369



#include <stdio.h>

void printarray1(int (*ptr)[4]);
void printarray2(int (*ptr)[4], int n);

int main(void)
{
    int multi[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    //ptr is a pointer to an array of 4 integers
    int (*ptr)[4];
    int count;

    //set ptr to point to the first element of multi
    ptr = multi;

    //with each loop, ptr is incremented to point to the next
    //  element (that is, the next 4 element integer array) of multi
    for(count=0; count<3; count++) // ** calls the funtion to print 3 times
    {
        printarray1(ptr++);
    }

    puts("\n\nPress Enter...");
    getchar();
    printarray2(multi,3);  //3 is passed as and argument for the number of 4-element
                           //  arrays is in the multidimensional array ->  multi[3][4]
                           // ** calls the funtion to print just once
    printf("\n");
    return 0;

}

void printarray1(int (*ptr)[4])
{
    //prints the elements of a single 4-element array integer

    //p is a pointer to type int. You must use a typecast to make p
    //  equal to the address in ptr
    int *p, count;
    p = (int *)ptr; //typecast

    for(count=0; count<4; count++)
    {
        printf("\n%d", *p++);
    }
}

void printarray2(int (*ptr)[4], int n)
{
    //prints the elements of an n by 4-element array - the whole thing
    int *p, count;
    p = (int *)ptr; //typecast

    for(count=0; count<(4*n); count++)  // (4*n) -> 3 was passed in for multi[3][4]
    {
        printf("\n%d", *p++);
    }
}
