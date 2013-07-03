/**
 * Cell.cpp
 *
 *  Created on: 24 de Mai de 2011
 *      Author: Nuno e José
 */

#include "Cell.h"

/**
 * Construtor de um objecto do tipo Cell,
 * que irá representar cada célula do nosso tabuleiro
 *
 */
Cell::Cell()
{
	content = "NULL";
	occupied = false;
	hasWord = false;
}

/**
 *get que permite obter o atributo occupied de uma célula,
 * que indica se uma celula estám ocupada ou não
 * @return true, se estiver ocupada, false caso contrário
 */
bool Cell::getOccupation()
{
	return occupied;
}

/**
 * set que permite alterar o atributo occupied de uma célula,
 * @param _occupied, true para indicar que está ocupada, false para o contrário
 */
void Cell::setOccupation(bool _occupied)
{
	occupied = _occupied;
}

/**
 * Método que permiter obter o conteudo de uma célula que é uma string
 * @return content, conteudo de uma Cell
 */
string Cell::getContent()
{
	return content;
}

/**
 * Método que permiter alterar o conteudo de uma célula que é uma string
 * @param _content, novo conteudo da Cell
 */
void Cell::setContent(string _content)
{
	content = _content;
}

/**
 * Método que imprime o conteudo de uma Cell,
 * ou seja, uma string
 */
void Cell::printCell()
{
	cout << getContent() << " ";
}


/**
 * Método que devolve o atributo hasWord de uma célula
 * @return true, se tiver lá uma string, false caso contrário
 */
bool Cell::getHasWord()
{
	return hasWord;
}

/**
 * Método que altera o atributo hasWord de uma célula
 * @param has,true ou false
 */
void Cell::setHasWord(bool has)
{
	hasWord = has;
}

