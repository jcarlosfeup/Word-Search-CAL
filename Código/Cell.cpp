/**
 * Cell.cpp
 *
 *  Created on: 24 de Mai de 2011
 *      Author: Nuno e Jos�
 */

#include "Cell.h"

/**
 * Construtor de um objecto do tipo Cell,
 * que ir� representar cada c�lula do nosso tabuleiro
 *
 */
Cell::Cell()
{
	content = "NULL";
	occupied = false;
	hasWord = false;
}

/**
 *get que permite obter o atributo occupied de uma c�lula,
 * que indica se uma celula est�m ocupada ou n�o
 * @return true, se estiver ocupada, false caso contr�rio
 */
bool Cell::getOccupation()
{
	return occupied;
}

/**
 * set que permite alterar o atributo occupied de uma c�lula,
 * @param _occupied, true para indicar que est� ocupada, false para o contr�rio
 */
void Cell::setOccupation(bool _occupied)
{
	occupied = _occupied;
}

/**
 * M�todo que permiter obter o conteudo de uma c�lula que � uma string
 * @return content, conteudo de uma Cell
 */
string Cell::getContent()
{
	return content;
}

/**
 * M�todo que permiter alterar o conteudo de uma c�lula que � uma string
 * @param _content, novo conteudo da Cell
 */
void Cell::setContent(string _content)
{
	content = _content;
}

/**
 * M�todo que imprime o conteudo de uma Cell,
 * ou seja, uma string
 */
void Cell::printCell()
{
	cout << getContent() << " ";
}


/**
 * M�todo que devolve o atributo hasWord de uma c�lula
 * @return true, se tiver l� uma string, false caso contr�rio
 */
bool Cell::getHasWord()
{
	return hasWord;
}

/**
 * M�todo que altera o atributo hasWord de uma c�lula
 * @param has,true ou false
 */
void Cell::setHasWord(bool has)
{
	hasWord = has;
}

