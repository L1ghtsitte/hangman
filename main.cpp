#include "include\statistics.h"
#include "include\includes.h"
#include "include\hangman.h"
#include "include\timer.h"

void setConsoleColor(int colorCode) //Меняет цвет в консоле
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorCode);
}
void SetFullscreenMode() 
{
	HWND hwnd = GetConsoleWindow(); // Получаем handle консольного окна
	SendMessage(hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0); // Переключаем в полноэкранный режим
}
int main(int& attemp, int& game, int& total_win, int& total_loss)
{

	Timer game_timer;
	int choise = 0;
	string crypto_str;
	string str;

	SetFullscreenMode();
	system("chcp 1251"); //Русская раскладка
	system("cls"); //Очистка консоли

	srand(time(nullptr)); //Для рандомного выбора слов ( с помощью ... = rand() % 50

	game_timer.start(); //Начало таймера

	start_game(choise); //Начало игры

	switch (choise) //Выбор режима игры
	{
	case 1:
	{
		hangman_play_normal(); //Выбор ОБЫЧНОГО режима
		break;
	}
	case 2:
	{
		hangman_play_botany(); //Выбор темы БОТАНИКИ
		break;
	}
	case 3:
	{
		hangman_play_city(); //Выбор темы ГОРОДА
		break;
	}
	case 4:
	{
		hangman_play_physics(); //Выбор темы ФИЗИКИ
		break;
	}
	case 5:
	{
		hangman_play_fauna();  //Выбор темы ФАУНЫ
		break;
	}
	case 6:
	{
		hangman_play_flora(); //Выбор темы ФЛОРЫ 
		break;
	}
	case 7:
	{
		hangman_play_all(); //Выбор ВСЕХ тем сразу
		break;
	}
	case 8:
	{
		break;
	}
	default: break;
	}

	game_timer.stop(); //конец таймера
	cout << "Время в игре : " << game_timer.get_elapsed_time() << " секунд" << std::endl; //Выводит результат таймера
	cout << "-----------------------------" << endl;
	system("pause");
	mciSendString(L" play resources/music/ben_bb.mp3", NULL, 0, 0);
	PlaySound(TEXT("resources/music/ben_bb.mp3"), NULL, SND_FILENAME | SND_ASYNC);
	sleep_for(milliseconds(1400));
}