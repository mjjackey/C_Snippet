#include <stdio.h>

void callBack();
void registerTheEvent(void (*function) (void));
void fireTheEvent();
int setjmp_execute();
void momory_test();


int main()
{
	registerTheEvent(callBack); //ע���¼�����,�ص�����Ϊ callBack��
	fireTheEvent();	//�����¼���������ע��������������¼�һ�������ͻ���� callBack ����.

	momory_test();

	setjmp_execute();

}
