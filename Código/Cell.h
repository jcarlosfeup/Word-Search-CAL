/*
 * Cell.h
 *
 *  Created on: 24 de Mai de 2011
 *      Author: Nuno e José
 */
#include <iostream>
#include <string>
using namespace std;

#ifndef CELL_H_
#define CELL_H_

class Cell {

private:
	bool occupied;
	bool hasWord;
	string content;

public:
	Cell();
	bool getOccupation();
	void setOccupation(bool _occupied);
	bool getHasWord();
	void setHasWord(bool has);
	string getContent();
	void setContent(string _content);
	void printCell();

	friend class System;

};


#endif /* CELL_H_ */
