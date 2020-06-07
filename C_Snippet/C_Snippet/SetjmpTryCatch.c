//使用setjmp和longjmp模拟C++中的try和catch
#include<stdio.h>
#include<setjmp.h>
#include<stdlib.h>


#define try if (!(ret = setjmp(buf)))
#define catch(i) else
#define throw(i) longjmp(buf, i)


jmp_buf buf;


void sub1()
{
    printf("in sub1()\n");
    throw(1);   //longjmp(buf, 1)
    printf("you will never see this!");
}
void sub2()
{
    printf("in sub2()\n");
    throw(2);  //longjmp(buf, 2)
    printf("you will never see this!");
}
extern int setjmp_execute()
{
    int ret;
    try   //if (!(ret = setjmp(buf))) 即 setjmp(buf)的返回值为0
    {
        printf("first time through\n");
        sub1();
        sub2();
    }
    catch(ret)  //else
    {
        switch(ret)
        {
            case 1:
                printf("sub1 raised an exception\n");
                break;
            case 2:
                printf("sub2 raised an exception\n");
                break;
            default:
                break;
        }
    }
    printf("back in main()\n");
    
    system("pause");

    return 0;
}
