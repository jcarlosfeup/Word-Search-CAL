/**
 * System.cpp
 *
 *  Created on: 24 de Mai de 2011
 *      Author: Nuno e José
 */

#include "System.h"

/**
 * Constructor de um objecto do tipo System
 */
System::System()
{
}


/**
 * Função que vai "iniciar" o sistema,criando os vários vectores
 * que são atributos da classe System
 * @param total, é um vector de strings que contem as palavras que foram carregadas do ficheiro
 */
void System::buildSystem(vector<string> total)
{

	totalWords = total;

	field = vector< vector<Cell> >(MAX_ALTURA);

	for(size_t i = 0; i < field.size(); ++i)
	{
		field[i] = vector<Cell> (MAX_ALTURA);
	}

	Cell temp;

	for(size_t i = 0; i < field.size(); i++)
		for (size_t j = 0; j < field[i].size(); j++)
			field[i][j] = temp;



	vector<string> tmp;
	chosenWords = tmp;
	chosenWords.clear();


	alphabet = vector<string> (24, " ");

	alphabet[0] = "a";
	alphabet[1] = "b";
	alphabet[2] = "c";
	alphabet[3] = "d";
	alphabet[4] = "e";
	alphabet[5] = "f";
	alphabet[6] = "g";
	alphabet[7] = "h";
	alphabet[8] = "i";
	alphabet[9] = "j";
	alphabet[10] = "k";
	alphabet[11] = "l";
	alphabet[12] = "m";
	alphabet[13] = "n";
	alphabet[14] = "o";
	alphabet[15] = "p";
	alphabet[16] = "q";
	alphabet[17] = "r";
	alphabet[18] = "s";
	alphabet[19] = "t";
	alphabet[20] = "u";
	alphabet[21] = "v";
	alphabet[22] = "x";
	alphabet[23] = "z";


}


/**
 * Este método vai ser responsável por construir o nosso tabuleiro de jogo,
 * colocando já lá o numero de palavras que o jogador escolheu encontrar
 */
void System::buildField()
{
	system("CLS");
	string number;
	cout << "Quantas palavras pretende encontrar? " << endl;
	cin >> number;
	//cout << "going to build our field " << endl;
	//system("PAUSE");
	srand((unsigned)time(0));


	unsigned int _number = atoi(number.c_str());

	for (unsigned int i = 0; i < _number; i++)
	{
		vector<string> options (3, " ");
		options[0] = "vertical";
		options[1] = "horizontal";
		options[2] = "diagonal";

		int random_option = (rand()%3);
		string option = options[random_option];

		vector<string> modes (2, " ");
		modes[0] = "normal";
		modes[1] = "reverse";

		int random_mode = (rand()%2);
		string mode = modes[random_mode];


		string word = selectWordFromTotal();
		//cout << word + " "<< option + " " << mode + " " << endl;
		addWordToChosen(word);
		//cout << "Word added to chosen vector" << endl;
		cout << endl;
		placeWord(word, option, mode);
		cout <<endl << "Word placed" << endl <<endl;
		system("PAUSE");
	}

	for(size_t i = 0; i < MAX_ALTURA; i++)
		for (size_t j = 0; j < MAX_LARGURA; j++)
		{
			if (field[i][j].getOccupation() == false)
			{
				size_t range = alphabet.size();

				int random_integer;
				random_integer = (rand()%range);
				string character = alphabet[random_integer];
				field[i][j].setContent(character);
				field[i][j].setOccupation(true);

			}
		}


}

/**
 * Este método seleciona uma palavra aleatória do vector totalWords,
 * que contem as palavras carregadas a partir do ficheiro no inicio do jogo
 * @return word, palavra aleatoria escolhida
 */
string System::selectWordFromTotal()
{
	string word;
	size_t range = totalWords.size();

	srand((unsigned)time(0));
	int random_integer;
	random_integer = (rand()%range);
	word = totalWords[random_integer];

	return word;

}

/**
 * Método que coloca uma palavra numa determinada posição do tabuleiro
 * @param word, é a palavra que irá ser colocada
 * @param tipo,se a palavra vai ser colocada na vertical,na horizontal ou na diagonal
 * @param orient,indica se a palavra vai ser escrita de trás para a frente ou da frente para trás
 */
void System::placeWord(string word,string option,string orient)
{
	cout << "Going to place the word " << word << " with the option " << option << " and mode " << orient << endl <<endl;
	srand((unsigned)time(0));

	string pal = word;
	int pos_x;
	int pos_y;
	pos_x = rand() % MAX_LARGURA;
	pos_y = rand() % MAX_ALTURA;

	cout << "row " << pos_x <<endl;
	cout << "column " << pos_y <<endl;

	int tam_word = word.size();
	bool ciclo = true;


	switch(option[0])
	{
	//Se a palavra vai ser colocada na horizontal
	case 'h':


		if(tam_word + pos_x <= MAX_LARGURA && orient == "normal")
		{

			for(int i = 0;i < tam_word;i++)
			{
				if(field[pos_y][pos_x+i].getOccupation() == true)
				{
					ciclo = false;
				}

				if(ciclo == true)
				{
					field[pos_y][pos_x+i].setContent(word.substr(i,1));
					field[pos_y][pos_x+i].setOccupation(true);
				}
				else
				{
					placeWord(word,option,orient);
				}

			}
			break;
		}

		if(tam_word + pos_x <= MAX_LARGURA && orient == "reverse")
		{

			string nova = reverseString(word);
			//cout << "depois do reverse" <<endl << nova <<endl;
			for(int i = tam_word-1;i >= 0;i--)
			{
				if(field[pos_y][pos_x+i].getOccupation() == true)
				{
					ciclo = false;

				}

				if(ciclo == true)
				{
					field[pos_y][pos_x+i].setContent(nova.substr(i,1));
					field[pos_y][pos_x+i].setOccupation(true);
				}
				else
				{
					placeWord(word,option,orient);
				}

			}
			break;
		}

		else{

			placeWord(pal,option,orient);
			break;
		}

		//Se a palavra vai ser colocada na vertical
	case 'v':

		if(tam_word + pos_y <= MAX_ALTURA && orient == "normal")
		{
			for(int j = 0;j < tam_word;j++)
			{
				if(field[pos_y+j][pos_x].getOccupation() == true)
				{
					ciclo = false;

				}

				if(ciclo == true)
				{
					field[pos_y+j][pos_x].setContent(word.substr(j,1));
					field[pos_y+j][pos_x].setOccupation(true);
				}
				else
				{
					placeWord(word,option,orient);
				}


			}
			break;
		}

		if(tam_word + pos_x <= MAX_LARGURA && orient == "reverse")
		{

			string nova = reverseString(word);
			//cout << "depois do reverse" <<endl << nova <<endl;
			for(int j = tam_word-1;j >= 0;j--)
			{
				if(field[pos_y+j][pos_x].getOccupation() == true)
				{
					ciclo = false;

				}

				if(ciclo == true)
				{
					field[pos_y+j][pos_x].setContent(nova.substr(j,1));
					field[pos_y+j][pos_x].setOccupation(true);
				}
				else
				{
					placeWord(word,option,orient);
				}


			}
			break;
		}

		else{
			placeWord(pal,option,orient);
			break;
		}

	case 'd':

		if(tam_word + pos_x <= MAX_LARGURA && tam_word + pos_y <= MAX_ALTURA && orient == "normal" )
		{
			for(int k = 0;k < tam_word;k++)
			{
				if(field[pos_y+k][pos_x+k].getOccupation() == true)
				{
					ciclo = false;

				}

				if(ciclo == true)
				{
					field[pos_y+k][pos_x+k].setContent(word.substr(k,1));
					field[pos_y+k][pos_x+k].setOccupation(true);
				}
				else
				{
					placeWord(word,option,orient);
				}

			}
			break;
		}

		if(tam_word + pos_x <= MAX_LARGURA && tam_word + pos_y <= MAX_ALTURA && orient == "reverse")
		{

			string nova = reverseString(word);
			//cout << "depois do reverse" << endl << nova << endl;
			for(int k = tam_word-1;k >= 0;k--)
			{
				if(field[pos_y+k][pos_x+k].getOccupation() == true)
				{
					ciclo = false;
				}
			}

			if(ciclo == true)
			{
				for(int k = tam_word-1;k >= 0;k--)
				{
					field[pos_y+k][pos_x+k].setContent(nova.substr(k,1));
					field[pos_y+k][pos_x+k].setOccupation(true);
				}
			}
			else
			{
				placeWord(word,option,orient);
			}

		}
		break;
	}


}


/**
 * Esta função adiciona uma palavra ao vector de palavras escolhidas,
 * que tem o tamanho especificado pelo jogador
 * @param word, palavra a ser adicionada
 * @return true ou false
 */
bool System::addWordToChosen(string word)
{
	size_t max = chosenWords.size();

	for (size_t i = 0; i < max; i++)
	{
		if (word == chosenWords[i])
		{
			Sleep(1000);
			selectWordFromTotal();
			return false;
		}

	}

	chosenWords.push_back(word);

	return true;
}


/**
 * Este método é responsável por imprimir a nossa matriz de letras (tabuleiro)
 */
void System::printField()
{

	string top(40, (char)205);

	cout << "    "  << setw(40) << "   1 1 1 1 1 1 1 1 1 1 " << endl
			<< "    " << setw(33) << "0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 " << endl
			<< setw(4) << green << (char)201 << top << (char)187 << white << endl;

	// ciclo visualiza o conteudo do tabuleiro
	for(size_t i = 0; i < field.size(); ++i)
	{
		if (i < 10)
			cout << i << white << "  " << green << (char)186 << white;
		else
			cout << i << white << " " << green << (char)186 << white;
		for(size_t j = 0; j < field.size(); ++j)
		{
			if (field[i][j].getHasWord())
				cout << yellow << field[i][j].getContent() << " ";
			else
				cout << red << field[i][j].getContent() << " ";
		}
		cout << green << (char)186 << white << endl;
	}
	cout << setw(4) << green << (char)200 << top << (char)188 << white << endl;
}

/**
 * Lê uma string do input do utilizador
 * @param error_msg Mensagem de erro
 * @return Valor introduzido
 */
string System::obterInput(string error_msg) {
	string tempString = "";

	while (tempString.size() == 0) {
		cout << error_msg;
		getline(cin, tempString);
	}

	return tempString;
}

/**
 * Função auxiliar da kmp
 */
void System::pre_kmp(string pattern, vector<int> & prefix)
{
	int m = pattern.length();
	prefix[0] = -1;
	int k = -1;
	for (int q = 1; q < m; q++) {

		while (k > -1 && pattern[k+1] != pattern[q])
			k = prefix[k];

		if (pattern[k+1] == pattern[q]) k=k+1;
		prefix[q]=k;
	}
}

/**
 * algoritmo de Knuth–Morris–Pratt
 */
int System::kmp(string text, string pattern)
{
	int num = 0;
	int m = pattern.length();
	vector<int> prefix(m);
	pre_kmp(pattern, prefix);
	int n = text.length();

	int q = -1;
	for (int i=0; i < n; i++) {
		while (q > -1 && pattern[q+1]!=text[i])
			q=prefix[q];

		if (pattern[q+1]==text[i])
			q++;

		if (q==m-1) {
			cout <<"pattern occurs with shift" << i-m+1 << endl;
			num++;
			q=prefix[q];
		}
	}
	return num;
}

/**
 * Esta função inverte os caracteres de uma string
 * @param str, string que irá ser invertida
 * @return s, string invertida
 */
string System::reverseString(string str)
{

	string s(str.begin(),str.end());

	string::iterator pos;
	for (pos = s.begin(); pos != s.end(); ++pos) {

		cout << *pos;
	}
	cout << endl;


	reverse(s.begin(), s.end());


	return s;
}


/**
 * Função que contem a interface principal do nosso jogo
 */
void System::runGame()
{
	system("CLS");
	buildField();
	cout << "Field created" << endl;
	system("PAUSE");
	cout << "Here is our field: " << endl;
	printField();
	cout << endl;
	system("PAUSE");

	int wordsLeft = chosenWords.size();

	while (wordsLeft != 0)
	{
		bool ciclo = true;
		int x_ini,y_ini,x_fin,y_fin;
		system("CLS");
		printField();
		cout << endl << "Numero de palavras a encontrar: " << wordsLeft << endl;
		cout << "Lista de palavras a encontrar: " << endl <<endl;
		for (size_t i = 0; i < chosenWords.size(); i++)
			cout << chosenWords[i] << endl;

		cout <<endl;

		while(ciclo)
		{
			cout << "Inserir palavra: ";
			string pal_encontrada = obterInput("");
			cout << "Coordenada X inicial: " ;
			cin >> x_ini;
			cout << "Coordenada Y inicial: " ;
			cin >> y_ini;
			cout << "Coordenada X final: " ;
			cin >> x_fin;
			cout << "Coordenada Y final: ";
			cin >> y_fin;
			cout << "Vertical, horizontal ou diagonal? ";
			string option, mode;
			option = obterInput("");
			cout << "Sentido normal ou reverse? ";
			mode = obterInput("");

			system("PAUSE");

			if(compareWords(pal_encontrada,x_ini,x_fin,y_ini,y_fin,option,mode) == true)
			{
				cout << "Palavra encontrada!" <<endl;
				system("PAUSE");
				wordsLeft--;
				ciclo = false;
			}

			else
			{
				cout << "Nao encontrou!";
				system("PAUSE");
				ciclo = true;
			}
		}

		if (wordsLeft == 0)
		{
			cout << "Parabens! Encontrou todas as palavras! " << endl;
			system("PAUSE");
		}

	}

}

/**
 * Função que verifica se mediante os parametros que o jogador introduz na consola
 * para indicar uma palavra, verifica se essa palavra se encontra mesmo no tabuleiro
 * @param pal, palavra que o jogador supostamente encontrou
 * @param x_ini, coordenada X do inicio da palavra
 * @param x_fin, coordenada X do fim da palavra
 * @param y_ini, coordenada Y do inicio da palavra
 * @param y_fin, coordenada Y do fim da palavra
 * @param option, direcção da palavra (horizontal,vertical ou diagonal)
 * @param mode, sentido da palavra (normal ou reverse)
 * @return true, se a palavra se encontra no tabuleiro, false senão
 */
bool System::compareWords(string pal,int x_ini,int x_fin,int y_ini,int y_fin,string option,string mode)
{
	bool retorno;

	for (size_t i = 0; i < chosenWords.size(); i++)
	{
		if (pal == chosenWords[i])
		{
			switch(option[0])
			{
			case 'h':

				if(mode == "normal")
				{	for(int j = y_ini ; j < y_fin;j++)
				{
					size_t s = 0;
					while(s != chosenWords[i].size())
					{
						if(field[x_ini][j].getContent() == chosenWords[i].substr(s,1))
						{
							//cout << field[x_ini][j].getContent() << " e " << chosenWords[i].substr(s,1) << endl;
							//cout << "Sao iguais!!" <<endl;


							retorno = true;
							s++;
							j++;
						}
						else
						{
							//cout << field[x_ini][j].getContent() << " e " << chosenWords[i].substr(s,1) << endl;
							//cout << "Sao diferentes!!" <<endl;
							return false;;
						}

					}
					for(int j = y_ini ; j <= y_fin;j++)
					{
						field[x_ini][j].setHasWord(true);
					}
				}
				}

				if(mode == "reverse")
				{
					for(int j = y_ini ; j < y_fin;j++)
					{
						size_t s = 0;
						while(s !=  chosenWords[i].size())
						{
							string pal_reverse = reverseString(chosenWords[i]);

							if(field[x_ini][j].getContent() == pal_reverse.substr(s,1))
							{
								/*cout << field[x_ini][j].getContent() << " e " << pal_reverse.substr(s,1) << endl;
								cout << "Sao iguais!!" <<endl;*/


								retorno = true;
								s++;
								j++;
							}
							else
							{
								/*cout << field[x_ini][j].getContent() << " e " << pal_reverse.substr(s,1) << endl;
								cout << "Sao diferentes!!" <<endl;*/
								return false;;
							}
						}
						for(int j = y_ini ; j <= y_fin;j++)
						{
							field[x_ini][j].setHasWord(true);
						}
					}



				}

				break;


			case 'v':

				if(mode == "normal")
				{

					for(int j = x_ini ; j < x_fin;j++)
					{
						size_t s = 0;
						while(s != chosenWords[i].size())
						{
							if(field[j][y_ini].getContent() == chosenWords[i].substr(s,1))
							{
								/*cout << field[j][y_ini].getContent() << " e " << chosenWords[i].substr(s,1) << endl;
								cout << "Sao iguais!!" <<endl;*/

								retorno = true;
								s++;
								j++;
							}
							else
							{
								/*cout << field[j][y_ini].getContent() << " e " << chosenWords[i].substr(s,1) << endl;
								cout << "Sao diferentes!!" <<endl;*/
								return false;;
							}
						}
						for(int j = x_ini ; j <= x_fin;j++)
						{
							field[j][y_ini].setHasWord(true);
						}
					}
				}

				if(mode == "reverse")
				{
					for(int j = x_ini ; j < x_fin;j++)
					{
						size_t s = 0;
						while(s != chosenWords[i].size())
						{
							string pal_reverse2 = reverseString(chosenWords[i]);

							if(field[j][y_ini].getContent() == pal_reverse2.substr(s,1))
							{
								/*cout << field[j][y_ini].getContent() << " e " << pal_reverse2.substr(s,1) << endl;
								cout << "Sao iguais!!" <<endl;*/

								retorno = true;
								s++;
								j++;
							}
							else
							{
								/*cout << field[j][y_ini].getContent() << " e " << pal_reverse2.substr(s,1) << endl;
								cout << "Sao diferentes!!" <<endl;*/
								return false;;
							}
						}
						for(int j = x_ini ; j <= x_fin;j++)
						{
							field[j][y_ini].setHasWord(true);
						}
					}
				}

				break;

			case 'd':

				if(mode == "normal")
				{
					for(int j = x_ini ; j < x_fin;j++)
					{
						for(int k = y_ini;k < y_fin;k++)
						{
							size_t s = 0;
							while(s != chosenWords[i].size())
							{


								if(field[j][k].getContent() == chosenWords[i].substr(s,1))
								{
									/*cout << "O X é " << x_ini << " e " << j <<endl;
									cout << field[j][k].getContent() << " e " << chosenWords[i].substr(s,1) << endl;

									cout << "Sao iguais!!" <<endl;*/

									retorno = true;
									s++;
									j++;
									k++;
								}
								else
								{
									//cout << "Sao diferentes!!" <<endl;
									return false;;
								}
							}
						}
					}
					int a = x_ini;
					int b = y_ini;
					while (a <= x_fin)
					{
							field[a][b].setHasWord(true);
							b++;
							a++;
					}
				}

				if(mode == "reverse")
				{
					for(int j = x_ini ; j < x_fin;j++)
					{
						for(int k = y_ini;k < y_fin;k++)
						{
							size_t s = 0;
							while(s != chosenWords[i].size())
							{
								string pal_reverse3 = reverseString(chosenWords[i]);

								if(field[j][k].getContent() == pal_reverse3.substr(s,1))
								{
									/*cout << "O X é " << x_ini << " e " << j <<endl;
									cout << field[j][k].getContent() << " e " << pal_reverse3.substr(s,1) << endl;

									cout << "Sao iguais!!" <<endl;*/

									retorno = true;
									s++;
									j++;
									k++;
								}
								else
								{
									//cout << "Sao diferentes!!" <<endl;
									return false;;
								}
							}
							}

						}
					int a = x_ini;
					int b = y_ini;
					while (a <= x_fin)
					{
							field[a][b].setHasWord(true);
							b++;
							a++;
					}
					}
				}
				break;
			}
		}
	return retorno;
	}




