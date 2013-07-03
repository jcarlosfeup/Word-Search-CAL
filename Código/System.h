/*
 * System.h
 *
 *  Created on: 24 de Mai de 2011
 *      Author: Nuno e José
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "Cores.h"
#include "Cell.h"


#define MAX_ALTURA 20
#define MAX_LARGURA 20

using namespace std;

#ifndef SYSTEM_H_
#define SYSTEM_H_

class System{

private:
	 vector< vector< Cell> > field;
	 vector<string> totalWords;
	 vector<string> chosenWords;
	 vector<string> alphabet;

public:
	 System();
	 void buildSystem(vector<string> total);
	 void printField();
	 void buildField();
	 string selectWordFromTotal();
	 bool addWordToChosen(string word);
	 void selectWord(vector<string> total);
	 void placeWord(string word, string option, string orient);
	 string obterInput(string error_msg);
	 void pre_kmp(string pattern, vector<int> & prefix);
	 int kmp(string text, string pattern);
	 string reverseString(string str);
	 void runGame();
	 bool compareWords(string pal,int x_ini,int x_fin,int y_ini,int y_fin,string option, string mode);


	 friend class Cell;
	 friend class Menu;





};


#endif /* SYSTEM_H_ */
