#include <stdio.h>

void registerTheEvent(int (*function) (void));
void callBack();
void fireTheEvent();
int setjmp_execute();
int memory_init();

char** temp_pointer;

int main()
{
	registerTheEvent(callBack); //注册事件监听,回调函数为 callBack。
	fireTheEvent();	//触发事件。由于已注册过监听，所以事件一旦触发就会调用 callBack 函数.

	setjmp_execute();

	int r=memory_init();
	printf("%d%s", r,*temp_pointer);
	
}
