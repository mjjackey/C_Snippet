//申请内存空间后要初始化，除非是linux内核这样的对每一ms的时间都要求严格
//应用层的程序，必须初始化
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define number 8
#define number2 60

char** temp_pointer = NULL;

int memory_init()
{
    /*char** temp_pointer=NULL;*/
  
    temp_pointer=(char **)malloc(sizeof(char *) * number); 
    if(temp_pointer==NULL) 
    {
	    return -1;
    }
    //memset(*temp_pointer, 0, sizeof(char *) * number);    /// wrong   
    //*temp_pointer = (char*)malloc(sizeof(char) * number2);
    for(int i=0; i<number; i++)
    {
        *(temp_pointer + i) =(char *)malloc(sizeof(char) * number2);  //or replace *(temp_pointer + i) to temp_pointer[i]
        if (*(temp_pointer + i) == NULL) 
        {
            return -1;
        }
	    memset(*(temp_pointer + i), '\0', number2); 
        strcpy_s(*(temp_pointer + i),sizeof("hello"), "hello");
    }

    return 0;
    //system("pause");
}

void memory_free()
{
    for (int i = 0; i < number; i++)
    {
        if (!*(temp_pointer+i)) free(temp_pointer[i]);
    }
    if (!temp_pointer) free(temp_pointer);
}

extern void momory_test()
{
    int r = memory_init();
    printf("%d %s\n", r, temp_pointer[number-1]);
    printf("%s\n", *temp_pointer);
    //printf("%s\n", **temp_pointer);  //wrong
    //printf("%s\n", temp_pointer[0][0]); //wrong
    printf("%s\n", *(temp_pointer+1));
    //printf("%s\n", *(temp_pointer + 1)[0]); //wrong
    //printf("%s\n", *(*(temp_pointer + 1)+1)); //wrong
    memory_free();
}

test()
{
    int** p;
    p = (int**)malloc(sizeof(int*) * 12);
    for (int i = 0; i < 12; i++) p[i] = (int*)malloc(sizeof(int));


    for (int i = 0; i < 12; i++) free(p[i]);
    free(p);

}


