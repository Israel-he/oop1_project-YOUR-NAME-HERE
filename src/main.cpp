#include "GameControl.h"
int main()
{
	GameControl  b;
		while (b.windowIsOpen())
		{
			b.render();
			b.update();
		}
}
