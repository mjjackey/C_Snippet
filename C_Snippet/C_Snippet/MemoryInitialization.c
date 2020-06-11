//申请内存空间后要初始化，除非是linux内核这样的对每一ms的时间都要求严格
//应用层的程序，必须初始化
#include <stdio.h>
extern char** temp_pointer = NULL;
extern int memory_init()
{
  /*char **temp_pointer=NULL;*/
  int number = 8;
  temp_pointer=(char **)malloc(sizeof(char *) * number); // 申请内存空间
  if(temp_pointer==NULL) // 申请内存空间失败则退出
  {
	 return -1;
  }
  memset(*temp_pointer, 0, sizeof(char *) * number);    /// wrong    
  for(int i=0; i<number; i++)
  {
	  temp_pointer[i]=(char *)malloc(sizeof(char) * 60);
	  memset(temp_pointer[i], '\0', 60); // 初始化动态数组
  }
  return 0;
  system("pause");
}


