#include "Menu.h"


using namespace std;

Menu::Menu()
{}

/**
 * Menu de boas-vindas
 */
void Menu::welcome()
{
	cout << "Bem-vindo 'a Sopa de Letras!" << endl;
	cout << endl;
	system("PAUSE");
	system("CLS");
}


/**
 * Funcao que manobra os menus
 * @param options Vector com as opções do menu
 * @param greet Titulo do menu
 * @return Indice da posição escolhida
 */
int Menu::menuHandler(const vector<string> & options, const string greet) {
	COORD coord;
	coord.X = 0;

	size_t size = options.size();
	size_t current = 0;
	int pressedkey = 0;
	int dummy = 0;

	system("CLS");

	size_t width = 80 - ((80 - greet.size()) / 2);

	cout << setw(width) << yellow << greet << white << endl << endl << endl;

	for (size_t i = 0; i < size; ++i) {
		if (i == 0) {
			cout << "   " << darkblue << options[i] << white << endl;
		} else
			cout << "   " << options[i] << endl;
	}

	while (dummy != '\r') {
		if (_kbhit()) {
			dummy = _getch();
			if (dummy == 224) {
				pressedkey = _getch();

				if (pressedkey == 72 && current > 0) {
					--current;
					coord.Y = 4 + current;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
							coord);
					cout << "   " << white << options[current + 1] << white
							<< endl;
					coord.Y = 3 + current;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
							coord);
					cout << "   " << darkblue  << options[current] << white << endl;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
							coord);
				}

				else if (pressedkey == 80 && current < (size - 1)) {
					++current;
					coord.Y = 3 + current;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
							coord);
					cout << "   " << darkblue  << options[current] << white << endl;
					coord.Y = 2 + current;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
							coord);
					cout << "   " << white << options[current - 1] << white
							<< endl;
				}
			}
		}
	}

	return (current + 1);
}


/**
 * Menu principal do Sistema
 */
void Menu::main_menu() {

	vector<string> options;
	options.push_back("Carregar dicionario");
	options.push_back("Jogar sopa de letras");
	options.push_back("Sair");

	string greet = "Jogo da Sopa de Letras";
	int option = 0;

	/* Ciclo while que corre enquanto o utilizador não escolher
	 a opção de saída */

	while(option != 3) {
		option = menuHandler(options, greet);

		switch(option) {

		case 1:
			initializeSystem();
			break;

		case 2:
			sys.runGame();
			break;

		case 3:
			exit(0);

		default:
			break;
		}
	}
}


/**
 * Função loadWords que carrega para um vector de strings uma lista de
 * palavras de um ficheiro
 * @return words, vector das palavras carregadas
 */
vector<string> Menu::loadWords()
{
	system("CLS");
	string tema;
	cout << "Temas disponiveis: " << endl <<endl,
	cout << "Cidades" << endl;
	cout << "Eventos" << endl;
	cout << "Infinitivos" << endl;
	cout << "Paises" << endl <<endl;
	cout << "Introduza o tema com o qual quer jogar: ";
	cin >> tema;
	vector<string> words;
	words.clear();
	ifstream file;
	string ficheiro = tema + ".txt";
	file.open(ficheiro.c_str());
	string word;
	if (file.is_open()) {
		while (!file.eof()) {

			getline(file,word);
			words.push_back(word);
		}
	}
	else
	{
		cout << "Erro ao abrir o ficheiro." << endl;
		system("PAUSE");
		main_menu();
	}
	file.close();

	for (size_t i = 0; i < words.size(); i++)
		cout << words[i] << endl;

	system("PAUSE");

	return words;

}

/**
 * Função que inicializa o sistema já com as palavras carregadas do ficheiro
 */
void Menu::initializeSystem()
{
	system("CLS");
	sys.buildSystem(loadWords());

}
