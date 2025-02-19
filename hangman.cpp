#include "include\includes.h"
#include "include\hangman.h"

string filename_normal = "resources/words/words_normal.txt"; //Файл со СТАНДАРТНЫМИ словами
string filename_botany = "resources/words/words_botany.txt"; //Файл со словами на тему БОТАНИКА
string filename_city = "resources/words/words_city.txt"; //Файл со словами на тему ГОРОДА
string filename_physics = "resources/words/words_physics.txt"; //Файл со словами на тему ФИЗИКА
string filename_fauna = "resources/words/words_fauna.txt"; //Файл со словами на тему ФАУНА
string filename_flora = "resources/words/words_flora.txt"; //Файл со словами на тему ФЛОРА
string filename_all = "resources/words/words_all.txt"; //Файл со словами на ВСЕ темы вместе взятые

int miss; //Глобальная переменная ошибочных вводов
bool won_game; //Глобальная переменная выигрышной игры
bool loss_game; //Глобальная переменная роиграной игры

// Функция для дешифрования строки
string decrypt(string& str, int num_crypt) {
	string decrypted;
	for (char ch : str) {
		decrypted.push_back((char)((int)ch - num_crypt));
	}
	return decrypted;
}



int start_game(int& choise)
{
	mciSendString(L" play resources/music/allo_ben.mp3", NULL, 0, 0);
	PlaySound(TEXT("resources/music/allo_ben.mp3"), NULL, SND_FILENAME | SND_ASYNC);
	sleep_for(milliseconds(3400));
	setConsoleColor(4); //Меняет цвет текста консоли на красный
	cout << "ver 0.1 made by L1ghtsitte" << endl;  //Да-да-да это я
	cout << "github.com/L1ghtsitte || t.me/hellsfrik" << endl;  //Да-да-да это тоже я
	setConsoleColor(7); //Меняет цвет текста консоли обратно на белый
	cout << "Привет это игра под названием виселица :(" << endl;
	cout << "В этой игре все зависет только от тебя" << endl;
	cout << "Чтож если ты готов то погнали к выбору режима игры, или просмотру информации профиля" << endl;
	cout << "(Этот выбор вляет на сами слова)" << endl;
	cout << "1 - Обычная (3 666 слов)" << endl;
	cout << "2 - Ботаника (141 слов)" << endl;
	cout << "3 - Города (306 слов)" << endl;
	cout << "4 - Физика (305 слов)" << endl;
	cout << "5 - Фауна (292 слов)" << endl;
	cout << "6 - Флора (592 слов)" << endl;
	cout << "7 - Все вместе (5 301 слов)" << endl;
	setConsoleColor(4); //Меняет цвет текста консоли на красный
	cout << "Ваш выбор : ";
	cin >> choise;
	setConsoleColor(7); //Меняет цвет текста консоли обратно набелый
	return choise; //Возвращаеи ваш выбор в main.cpp, где он уже будет раскидан по соответствующим case
}

void hangman_play_normal() //Функция для СТАНДАРТНЫХ слов
{
	string crypto_str;
	string line;
	string str;

	int random_word;

	cout << "Ваш выбор пал на Обычный режим" << endl;
	cout << "Чтож раз с подготовкой закончено время начинать игру" << endl;

	miss = 0; //Счетчик неправлено введеных букв
	random_word = rand() % 3666; //Выбор слова из файла

	ifstream file(filename_normal);

	if (file.is_open()) //Открывает файл
	{
		int currentLine;

		currentLine = 1; //Ставится точка входа в тектовый файл

		while (getline(file, line))
		{
			if (currentLine == random_word) //Сравнивает выбраное на рандом слово со строчкой под номером выбраного числа, и записывает значение 
			{
				break;
			}
			currentLine++; //Проходит так по всему документу
		}
		file.close(); //Закрывает файл
	}

	line = decrypt(line, 4);

	system("pause"); //Ставим паузу в консоли
	system("cls"); //Очистка консоли

	display_mistakes(miss, loss_game); //Выводи текуший прогресс висилицы
	hangman_play(line, won_game, loss_game, miss); //Выводи текуший прогресс слова
}
void hangman_play_botany() //Функция для слов на тему БОТАНИКА
{
	int random_word;
	string line;
	ifstream file(filename_botany);

	cout << "Ваш выбор пал на Ботанику " << endl;
	cout << "Чтож раз с подготовкой закончено время начинать игру" << endl;

	miss = 0; //Счетчик неправлено введеных букв
	random_word = rand() % 141; //Выбор слова из файла

	if (file.is_open()) //Открывает файл
	{
		int currentLine;

		currentLine = 1; //Ставится точка входа в тектовый файл

		while (getline(file, line))
		{
			if (currentLine == random_word) //Сравнивает выбрвное на рандом слово со строчкой под номером выбраного числа, и записывает значение 
			{
				break;
			}


			currentLine++; //Проходит так по всему документу
		}
		file.close(); //Закрывает файл
	}
	
	line = decrypt(line, 4); //Дешифрование выбраного слова


	system("pause"); //Ставим паузу в консоли
	system("cls"); //Очистка консоли

	display_mistakes(miss, loss_game); //Выводи текуший прогресс висилицы
	hangman_play(line, won_game, loss_game, miss); //Выводи текуший прогресс слова
}
void hangman_play_city() //Функция для слов на тему ГОРОДА
{
	int random_word;
	string line;
	ifstream file(filename_city);

	cout << "Ваш выбор пал на Города" << endl;
	cout << "Чтож раз с подготовкой закончено время начинать игру" << endl;

	miss = 0; //Счетчик неправлено введеных букв
	random_word = rand() % 306; //Выбор слова из файла

	if (file.is_open()) //Открывает файл
	{
		int currentLine;

		currentLine = 1; //Ставится точка входа в тектовый файл

		while (getline(file, line))
		{
			if (currentLine == random_word) //Сравнивает выбрвное на рандом слово со строчкой под номером выбраного числа, и записывает значение 
			{
				break;
			}
			currentLine++; //Проходит так по всему документу
		}
		file.close(); //Закрывает файл
	}

	line = decrypt(line, 4);

	system("pause"); //Ставим паузу в консоли
	system("cls"); //Очистка консоли

	display_mistakes(miss, loss_game); //Выводи текуший прогресс висилицы
	hangman_play(line, won_game, loss_game, miss); //Выводи текуший прогресс слова
}
void hangman_play_physics() //Функция для слов на тему ФИЗИКА
{
	int random_word;
	string line;
	ifstream file(filename_physics);

	cout << "Ваш выбор пал на Физику" << endl;
	cout << "Чтож раз с подготовкой закончено время начинать игру" << endl;

	miss = 0; //Счетчик неправлено введеных букв
	random_word = rand() % 305; //Выбор слова из файла

	if (file.is_open()) //Открывает файл
	{
		int currentLine;

		currentLine = 1; //Ставится точка входа в тектовый файл

		while (getline(file, line))
		{
			if (currentLine == random_word) //Сравнивает выбрвное на рандом слово со строчкой под номером выбраного числа, и записывает значение 
			{
				break;
			}
			currentLine++; //Проходит так по всему документу
		}
		file.close(); //Закрывает файл
	}

	line = decrypt(line, 4);

	system("pause"); //Ставим паузу в консоли
	system("cls"); //Очистка консоли

	display_mistakes(miss, loss_game); //Выводи текуший прогресс висилицы
	hangman_play(line, won_game, loss_game, miss); //Выводи текуший прогресс слова
}
void hangman_play_fauna() //Функция для слов на тему ФАУНА
{
	int random_word;
	string line;
	ifstream file(filename_fauna);

	cout << "Ваш выбор пал на Фауну" << endl;
	cout << "Чтож раз с подготовкой закончено время начинать игру" << endl;

	miss = 0; //Счетчик неправлено введеных букв
	random_word = rand() % 292; //Выбор слова из файла

	if (file.is_open()) //Открывает файл
	{
		int currentLine;

		currentLine = 1; //Ставится точка входа в тектовый файл

		while (getline(file, line))
		{
			if (currentLine == random_word) //Сравнивает выбрвное на рандом слово со строчкой под номером выбраного числа, и записывает значение 
			{
				break;
			}
			currentLine++; //Проходит так по всему документу
		}
		file.close(); //Закрывает файл
	}

	line = decrypt(line, 4);

	system("pause"); //Ставим паузу в консоли
	system("cls"); //Очистка консоли

	display_mistakes(miss, loss_game); //Выводи текуший прогресс висилицы
	hangman_play(line, won_game, loss_game, miss); //Выводи текуший прогресс слова
}
void hangman_play_flora() //Функция для слов на тему ФЛОРА
{
	int random_word;
	string line;
	ifstream file(filename_flora);

	cout << "Ваш выбор пал на Флору" << endl;
	cout << "Чтож раз с подготовкой закончено время начинать игру" << endl;

	miss = 0; //Счетчик неправлено введеных букв
	random_word = rand() % 592; //Выбор слова из файла

	if (file.is_open()) //Открывает файл
	{
		int currentLine;

		currentLine = 1; //Ставится точка входа в тектовый файл

		while (getline(file, line))
		{
			if (currentLine == random_word) //Сравнивает выбрвное на рандом слово со строчкой под номером выбраного числа, и записывает значение 
			{
				break;
			}
			currentLine++; //Проходит так по всему документу
		}
		file.close(); //Закрывает файл
	}

	line = decrypt(line, 4);

	system("pause"); //Ставим паузу в консоли
	system("cls"); //Очистка консоли

	display_mistakes(miss, loss_game); //Выводи текуший прогресс висилицы
	hangman_play(line, won_game, loss_game, miss); //Выводи текуший прогресс слова
}
void hangman_play_all()  //Функция для ВСЕХ слов сразу
{
	int random_word;
	string line;
	ifstream file(filename_all);

	cout << "Вы доказали свою решимости выбрав все режимы разом" << endl;
	cout << "Чтож раз с подготовкой закончено время начинать игру" << endl;

	miss = 0; //Счетчик неправлено введеных букв
	random_word = rand() % 5301; //Выбор слова из файла

	if (file.is_open()) //Открывает файл
	{
		int currentLine;

		currentLine = 1; //Ставится точка входа в тектовый файл

		while (getline(file, line))
		{
			if (currentLine == random_word) //Сравнивает выбрвное на рандом слово со строчкой под номером выбраного числа, и записывает значение 
			{
				break;
			}
			currentLine++; //Проходит так по всему документу
		}
		file.close(); //Закрывает файл
	}

	line = decrypt(line, 4);

	system("pause"); //Ставим паузу в консоли
	system("cls"); //Очистка консоли

	display_mistakes(miss, loss_game); //Выводи текуший прогресс висилицы
	hangman_play(line, won_game, loss_game, miss); //Выводи текуший прогресс слова
}
