#include <stdio.h>

void registerTheEvent(int (*function) (void));
void callBack();
void fireTheEvent();
int setjmp_execute();
int memory_init();

char** temp_pointer;

int main()
{
	registerTheEvent(callBack); //ע���¼�����,�ص�����Ϊ callBack��
	fireTheEvent();	//�����¼���������ע��������������¼�һ�������ͻ���� callBack ����.

	setjmp_execute();

	int r=memory_init();
	printf("%d%s", r,*temp_pointer);
	
}
