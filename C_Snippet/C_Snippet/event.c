//C������ģ��C#�е��¼�
#include <stdio.h>
void (*func) (void); //����һ������ָ��func

//���øú����൱�ڴ������¼���
//���¼������󣬻��麯��ָ��func�Ƿ�ΪNULL�������ΪNULL��˵����ָ���ѱ���ֵ(�൱�ڸ��¼���ע��)��
//����¼��ѱ�ע�ᣬ��ִ��֮��
extern void fireTheEvent()
{
	if(func != NULL)
    {
		func();
	}
}

extern void registerTheEvent(void (*function) (void))  //ΪfireTheEvent�¼�ע���������
{
	func = function;
}

extern void callBack(void)
{
	printf("Hello~this is a callBack\n");
}

//int main()
//{
//	registerTheEvent(callBack); //ע���¼�����,�ص�����Ϊ callBack��
//	fireTheEvent();	//�����¼���������ע��������������¼�һ�������ͻ���� callBack ������
//}