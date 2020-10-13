#include <stdio.h>

void callBack();
void registerTheEvent(void (*function) (void));
void fireTheEvent();
int setjmp_execute();
void momory_test();


int main()
{
	registerTheEvent(callBack); //注册事件监听,回调函数为 callBack。
	fireTheEvent();	//触发事件。由于已注册过监听，所以事件一旦触发就会调用 callBack 函数.

	momory_test();

	setjmp_execute();

}
