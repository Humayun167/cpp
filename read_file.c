#include <stdio.h>

int main()
{

    FILE *fptr;

    fptr = fopen("test.txt", "r");

    char cntnt[1000];

    if(fptr != NULL)
    {
      while (fgets(cntnt,1000,fptr))
      {
       printf("%s",cntnt);
      }
      
    }
    else
    {
        printf("file open failed\n");
    }

    return 0;
}


