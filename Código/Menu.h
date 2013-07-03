#ifndef MENU_H_
#define MENU_H_

#include "System.h"
#include <iomanip>
#include <conio.h>
#include<fstream>



class Menu {

private:
	System sys;

public:
	Menu();
	void main_menu();
	void welcome();
	int menuHandler(const vector<string> &, const string);
	vector<string> loadWords();
	void initializeSystem();

	friend class System;
};

#endif
