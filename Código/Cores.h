
#ifndef CORES_H_
#define CORES_H_

#ifdef _WIN32

#include <iostream>
#include <windows.h>
//#include "stdafx.h"
#include "WinConsole.h"

using namespace std;



/**
 * Esta funcao permite imprimir caracteres na cor magenta
 * @param s stream na qual vao ser feitas alteracoes
 */
inline ostream& magenta(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE
			|FOREGROUND_RED|FOREGROUND_INTENSITY);
	return s;
}

/**
 * Esta funcao permite imprimir caracteres na cor azul escuro
 * @param s stream na qual vao ser feitas alteracoes
 */
inline ostream& darkblue(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE
			|FOREGROUND_INTENSITY);
	return s;
}

/**
 * Esta funcao permite imprimir caracteres na cor azul
 * @param s stream na qual vao ser feitas alteracoes
 */
inline ostream& blue(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE
			|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	return s;
}

/**
 * Esta funcao permite imprimir caracteres na cor vermelha
 * @param s stream na qual vao ser feitas alteracoes
 */
inline ostream& red(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
			FOREGROUND_RED|FOREGROUND_INTENSITY);
	return s;
}

/**
 * Esta funcao permite imprimir caracteres na cor verde
 * @param s stream na qual vao ser feitas alteracoes
 */
inline ostream& green(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
			FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	return s;
}

/**
 * Esta funcao permite imprimir caracteres na cor amarela
 * @param s stream na qual vao ser feitas alteracoes
 */
inline ostream& yellow(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
			FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
	return s;
}

/**
 * Esta funcao permite imprimir caracteres na cor branca
 * @param s stream na qual vao ser feitas alteracoes
 */
inline ostream& white(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
			FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	return s;
}

/**
 * Definicao da estrutura color
 */
struct color {
	color(WORD attribute):m_color(attribute){};
	WORD m_color;
};

/**
 * Redefinicao do operador <<
 */
template <class _Elem, class _Traits>
basic_ostream<_Elem,_Traits>& operator<<(basic_ostream<_Elem,_Traits>& i, color& c)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,c.m_color);
	return i;
}

#else

#include <string>

using namespace std;

const string magenta = "";
const string darkblue = "";
const string red = "";
const string white = "";
const string yellow = "";
const string blue = "";
const string green = "";

#endif

#endif
