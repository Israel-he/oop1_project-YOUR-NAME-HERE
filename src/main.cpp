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

//#include "MainMenu.h"
//int main() {
//    MainMenu menu;
//    menu.run();  // ����� �����
//    return 0;
//}