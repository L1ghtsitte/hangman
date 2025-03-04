#include "include\includes.h"
#include "include\hangman.h"

string filename_normal_easy = "resources/words/words_normal_easy_crypt.txt"; //Файл со СТАНДАРТНЫМИ словами
string filename_normal_medium = "resources/words/words_normal_medium_crypt.txt"; //Файл со СТАНДАРТНЫМИ словами
string filename_normal_hard = "resources/words/words_normal_hard_crypt.txt"; //Файл со СТАНДАРТНЫМИ словами
string filename_normal_impossible = "resources/words_normal_impossidle_crypt.txt"; //Файл со СТАНДАРТНЫМИ словами
string filename_normal_all = "resources/words/words_normal_all_crypt.txt"; //Файл со СТАНДАРТНЫМИ словами

string filename_botany_easy = "resources/words/words_botany_easy_crypt.txt"; //Файл со словами на тему БОТАНИКА
string filename_botany_medium = "resources/words/words_botany_medium_crypt.txt"; //Файл со словами на тему БОТАНИКА
string filename_botany_hard = "resources/words/words_botany_hard_crypt.txt"; //Файл со словами на тему БОТАНИКА
string filename_botany_impossible = "resources/words/words_botany_impossible_crypt.txt"; //Файл со словами на тему БОТАНИКА
string filename_botany_all = "resources/words/words_botany_all_crypt.txt"; //Файл со словами на тему БОТАНИКА

string filename_city_easy = "resources/words/words_city_easy_crypt.txt"; //Файл со словами на тему ГОРОДА
string filename_city_medium = "resources/words/words_city_medium_crypt.txt"; //Файл со словами на тему ГОРОДА
string filename_city_hard = "resources/words/words_city_hard_crypt.txt"; //Файл со словами на тему ГОРОДА
string filename_city_impossible = "resources/words/words_city_impossidle_crypt.txt"; //Файл со словами на тему ГОРОДА
string filename_city_all = "resources/words/words_city_all_crypt.txt"; //Файл со словами на тему ГОРОДА

string filename_physics_easy = "resources/words/words_physics_easy_crypt.txt"; //Файл со словами на тему ФИЗИКА
string filename_physics_medium = "resources/words/words_physics_medium_crypt.txt"; //Файл со словами на тему ФИЗИКА
string filename_physics_hard = "resources/words/words_physics_hard_crypt.txt"; //Файл со словами на тему ФИЗИКА
string filename_physics_impossible = "resources/words/words_physics_impossidle_crypt.txt"; //Файл со словами на тему ФИЗИКА
string filename_physics_all = "resources/words/words_physics_all_crypt.txt"; //Файл со словами на тему ФИЗИКА

string filename_fauna_easy = "resources/words/words_fauna_easy_crypt.txt"; //Файл со словами на тему ФАУНА
string filename_fauna_medium = "resources/words/words_fauna_medium_crypt.txt"; //Файл со словами на тему ФАУНА
string filename_fauna_hard = "resources/words/words_fauna_hard_crypt.txt"; //Файл со словами на тему ФАУНА
string filename_fauna_impossible = "resources/words/words_fauna_impossidle_crypt.txt"; //Файл со словами на тему ФАУНА
string filename_fauna_all = "resources/words/words_fauna_all_crypt.txt"; //Файл со словами на тему ФАУНА

string filename_flora_easy = "resources/words/words_flora_easy_crypt.txt"; //Файл со словами на тему ФЛОРА
string filename_flora_medium = "resources/words/words_flora_medium_crypt.txt"; //Файл со словами на тему ФЛОРА
string filename_flora_hard = "resources/words/words_flora_hard_crypt.txt"; //Файл со словами на тему ФЛОРА
string filename_flora_impossible = "resources/words/words_flora_impossidle_crypt.txt"; //Файл со словами на тему ФЛОРА
string filename_flora_all = "resources/words/words_flora_all_crypt.txt"; //Файл со словами на тему ФЛОРА

string filename_all_easy = "resources/words/words_all_easy_crypt.txt"; //Файл со словами на ВСЕ темы вместе взятые
string filename_all_medium = "resources/words/words_all_medium_crypt.txt"; //Файл со словами на ВСЕ темы вместе взятые
string filename_all_hard = "resources/words/words_all_hard_crypt.txt"; //Файл со словами на ВСЕ темы вместе взятые
string filename_all_impossible = "resources/words/words_all_impossidle_crypt.txt"; //Файл со словами на ВСЕ темы вместе взятые
string filename_all_all = "resources/words/words_all_all_crypt.txt"; //Файл со словами на ВСЕ темы вместе взятые

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

int start_game(int& choise_words)
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
	cout << "Чтож если ты готов то погнали к выбору сложности и режима игры, или просмотру информации профиля" << endl;
	cout << "(Этот выбор вляет на сами слова)" << endl;
	cout << "(легкая - средняя - сложная - невозможно | общее)" << endl;
	cout << "1 - Обычная (449 - 5 301 - 631 - 420 | 5167)" << endl;
	cout << "2 - Ботаника (125 - 141 - 175 - 100 | 541)" << endl;
	cout << "3 - Города (1050 - 305 - 1000 - 749 | 3105)" << endl;
	cout << "4 - Физика (179 - 1161 - 358 - 256 | 1954)" << endl;
	cout << "5 - Фауна (32 - 803 - 36 - 25 | 896)" << endl;
	cout << "6 - Флора (29 - 592 - 38 - 24 | 683)" << endl;
	cout << "7 - Все вместе (1864 - 6666 - 2239 - 1574 | 12345)" << endl;
	setConsoleColor(4); //Меняет цвет текста консоли на красный
	cout << "Ваш выбор : ";
	cin >> choise_words;
	setConsoleColor(7); //Меняет цвет текста консоли обратно набелый
	return choise_words; //Возвращаеи ваш выбор в main.cpp, где он уже будет посчитан и раскидан по соответствующим case
}

int dificult(int& choise_dificult)
{
	cout << "Так теперь расзберемся со сложностью" << endl;
	cout << "1 - Легкая (в словах до 5 букв)" << endl;
	cout << "2 - Средняя (в словах от 5 до 8 букв)" << endl;
	cout << "3 - Сложная (в словах от 8 до 9 букв)" << endl;
	cout << "4 - Невозможная в словах ( от 10 и более букв)" << endl;
	cout << "5 - Все что было выше" << endl;
	setConsoleColor(4); //Меняет цвет текста консоли на красный
	cout << "Ваш выбор : ";
	cin >> choise_dificult;
	setConsoleColor(7); //Меняет цвет текста консоли обратно набелый
	return choise_dificult; //Возвращаеи ваш выбор в main.cpp, где он уже будет посчитан и раскидан по соответствующим case
}

void hangman_play(const string& theme, const string& filename, int word_count) //Универсальная функция для игры
{
	int random_word;
	string line;
	ifstream file(filename);

	cout << "Ваш выбор пал на " << theme << endl;
	cout << "Чтож, раз с подготовкой закончено, время начинать игру" << endl;

	miss = 0; //Счетчик неправильно введенных букв
	random_word = rand() % word_count; //Выбор слова из файла

	if (file.is_open()) //Открывает файл
	{
		int currentLine = 1; //Ставится точка входа в текстовый файл

		while (getline(file, line))
		{
			if (currentLine == random_word) //Сравнивает выбранное на рандом слово со строчкой под номером выбранного числа
			{
				break;
			}
			currentLine++; //Проходит так по всему документу
		}
		file.close(); //Закрывает файл
	}

	line = decrypt(line, 4); //Дешифрование выбранного слова

	system("pause"); //Ставим паузу в консоли
	system("cls"); //Очистка консоли

	display_mistakes(miss, loss_game); //Выводит текущий прогресс виселицы
	hangman_play(line, won_game, loss_game, miss); //Выводит текущий прогресс слова
}

void hangman_play_normal_easy() { hangman_play("Обычный режим (Сложность : ЛЕГКО)", filename_normal_easy, 449); }
void hangman_play_normal_medium() { hangman_play("Обычный режим (Сложность : НОРМАЛЬНО)", filename_normal_medium, 5301); }
void hangman_play_normal_hard() { hangman_play("Обычный режим (Сложность : СЛОЖНО)", filename_normal_hard, 631); }
void hangman_play_normal_impossible() { hangman_play("Обычный режим (Сложность : НЕВОЗМОЖНО)", filename_normal_impossible, 420); }
void hangman_play_normal_all() { hangman_play("Обычный режим (Сложность : ВСЕ ВМЕСТЕ)", filename_normal_all, 5167); } 

void hangman_play_botany_easy() { hangman_play("Режим ботаника (Сложность : ЛЕГКО)", filename_botany_easy, 125); }
void hangman_play_botany_medium() { hangman_play("Режим ботаника (Сложность : НОРМАЛЬНО)", filename_botany_medium, 141); }
void hangman_play_botany_hard() { hangman_play("Режим ботаника (Сложность : СЛОЖНО)", filename_botany_hard, 175); }
void hangman_play_botany_impossible() { hangman_play("Режим ботаника (Сложность : НЕВОЗМОЖНО)", filename_botany_impossible, 100); }
void hangman_play_botany_all() { hangman_play("Режим ботаника (Сложность : ВСЕ ВМЕСТЕ)", filename_botany_all, 541); }

void hangman_play_city_easy() { hangman_play("Городской режим (Сложность : ЛЕГКО)", filename_city_easy, 1050); }
void hangman_play_city_medium() { hangman_play("Городской режим (Сложность : НОРМАЛЬНО)", filename_city_medium, 305); }
void hangman_play_city_hard() { hangman_play("Городской режим (Сложность : СЛОЖНО)", filename_city_hard, 1000); }
void hangman_play_city_impossible() { hangman_play("Городской режим (Сложность : НЕВОЗМОЖНО)", filename_city_impossible, 749); }
void hangman_play_city_all() { hangman_play("Городской режим (Сложность : ВСЕ ВМЕСТЕ)", filename_city_all, 3105); }

void hangman_play_physics_easy() { hangman_play("Физический режим (Сложность : ЛЕГКО)", filename_physics_easy, 179); }
void hangman_play_physics_medium() { hangman_play("Физический режим (Сложность : НОРМАЛЬНО)", filename_physics_medium, 1161); }
void hangman_play_physics_hard() { hangman_play("Физический режим (Сложность : СЛОЖНО)", filename_physics_hard, 358); }
void hangman_play_physics_impossible() { hangman_play("Физический режим (Сложность : НЕВОЗМОЖНО)", filename_physics_impossible, 256); }
void hangman_play_physics_all() { hangman_play("Физический режим (Сложность : ВСЕ ВМЕСТЕ)", filename_physics_all, 1954); }

void hangman_play_fauna_easy() { hangman_play("Режим фауна (Сложность : ЛЕГКО)", filename_fauna_easy, 32); }
void hangman_play_fauna_medium() { hangman_play("Режим фауна (Сложность : НОРМАЛЬНО)", filename_fauna_medium, 803); }
void hangman_play_fauna_hard() { hangman_play("Режим фауна (Сложность : СЛОЖНО)", filename_fauna_hard, 36); }
void hangman_play_fauna_impossible() { hangman_play("Режим фауна (Сложность : НЕВОЗМОЖНО)", filename_fauna_impossible, 25); }
void hangman_play_fauna_all() { hangman_play("Режим фауна (Сложность : ВСЕ ВМЕСТЕ)", filename_fauna_all, 896); }

void hangman_play_flora_easy() { hangman_play("Режим флора (Сложность : ЛЕГКО)", filename_flora_easy, 29); }
void hangman_play_flora_medium() { hangman_play("Режим флора (Сложность : НОРМАЛЬНО)", filename_flora_medium, 592); }
void hangman_play_flora_hard() { hangman_play("Режим флора (Сложность : СЛОЖНО)", filename_flora_hard, 38); }
void hangman_play_flora_impossible() { hangman_play("Режим флора (Сложность : НЕВОЗМОЖНО)", filename_flora_impossible, 24); }
void hangman_play_flora_all() { hangman_play("Режим флора (Сложность : ВСЕ ВМЕСТЕ)", filename_flora_all, 683); }

void hangman_play_all_easy() { hangman_play("Все в одном (Сложность : ЛЕГКО)", filename_all_easy, 1864); }
void hangman_play_all_medium() { hangman_play("Все в одном (Сложность : НОРМАЛЬНО)", filename_all_medium, 6666); }
void hangman_play_all_hard() { hangman_play("Все в одном (Сложность : СЛОЖНО)", filename_all_hard, 2239); }
void hangman_play_all_impossible() { hangman_play("Все в одном (Сложность : НЕВОЗМОЖНО)", filename_all_impossible, 1574); }
void hangman_play_all_all() { hangman_play("Все в одном (Сложность : ВСЕ ВМЕСТЕ)", filename_all_all, 12345); }