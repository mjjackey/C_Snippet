//C������ģ��C#�е��¼�
//����һ������ָ��func
#include <stdio.h>
int (*func) (void);

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

extern void registerTheEvent(int (*function) (void))  //ΪfireTheEvent�¼�ע���������
{
	func = function;
}

extern int callBack()
{
	printf("Hello~this is a callBack\n");
}

//int main()
//{
//	registerTheEvent(callBack); //ע���¼�����,�ص�����Ϊ callBack��
//	fireTheEvent();	//�����¼���������ע��������������¼�һ�������ͻ���� callBack ����.
//}