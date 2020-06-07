//C语言中模仿C#中的事件
//定义一个函数指针func
#include <stdio.h>
int (*func) (void);

//调用该函数相当于触发了事件。
//该事件触发后，会检查函数指针func是否为NULL，如果不为NULL，说明该指针已被赋值(相当于该事件被注册)。
//如果事件已被注册，则执行之。
extern void fireTheEvent()
{
	if(func != NULL)
    {
		func();
	}
}

extern void registerTheEvent(int (*function) (void))  //为fireTheEvent事件注册监听器。
{
	func = function;
}

extern int callBack()
{
	printf("Hello~this is a callBack\n");
}

//int main()
//{
//	registerTheEvent(callBack); //注册事件监听,回调函数为 callBack。
//	fireTheEvent();	//触发事件。由于已注册过监听，所以事件一旦触发就会调用 callBack 函数.
//}