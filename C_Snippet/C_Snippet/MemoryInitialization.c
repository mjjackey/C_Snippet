//�����ڴ�ռ��Ҫ��ʼ����������linux�ں������Ķ�ÿһms��ʱ�䶼Ҫ���ϸ�
//Ӧ�ò�ĳ��򣬱����ʼ��
#include <stdio.h>
extern char** temp_pointer = NULL;
extern int memory_init()
{
  /*char **temp_pointer=NULL;*/
  int number = 8;
  temp_pointer=(char **)malloc(sizeof(char *) * number); // �����ڴ�ռ�
  if(temp_pointer==NULL) // �����ڴ�ռ�ʧ�����˳�
  {
	 return -1;
  }
  memset(*temp_pointer, 0, sizeof(char *) * number);    /// wrong    
  for(int i=0; i<number; i++)
  {
	  temp_pointer[i]=(char *)malloc(sizeof(char) * 60);
	  memset(temp_pointer[i], '\0', 60); // ��ʼ����̬����
  }
  return 0;
  system("pause");
}


