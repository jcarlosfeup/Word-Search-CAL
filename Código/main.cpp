#include <iostream>
#include "System.h"
#include "Menu.h"

using namespace std;




/**
 * Função main
 * @return 0
 */
int main()
{
	//para mostrar acentos
	SetConsoleOutputCP(0xfde8);

	Menu menu;
	menu.welcome();
	menu.main_menu();

	return 0;
}
