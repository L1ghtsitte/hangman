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
	int choise_dificult = 0;
	int choise_words = 0;
	int choise = 0;
	string crypto_str;
	string str;

	SetFullscreenMode();
	system("chcp 1251"); //Русская раскладка
	system("cls"); //Очистка консоли

	srand(time(nullptr)); //Для рандомного выбора слов ( с помощью ... = rand() % 50

	game_timer.start(); //Начало таймера

	start_game(choise_words); //Начало игры
	dificult(choise_dificult); //Выбор сложности

	if (choise_dificult == 5) choise = 30 + (choise_words - 1);
	else choise = (choise_words - 1) * 4 + choise_dificult + 1;

	switch (choise) //Выбор режима игры
	{
	case 2: 
	{
		hangman_play_normal_easy(); 
		break;
	}
	case 3: 
	{ 
		hangman_play_normal_medium(); 
		break;
	}
	case 4: 
	{ 
		hangman_play_normal_hard(); 
		break;
	}
	case 5: 
	{ 
		hangman_play_normal_impossible(); 
		break;
	}
	case 6: 
	{ 
		hangman_play_botany_easy(); 
		break;
	}
	case 7:
	{ 
		hangman_play_botany_medium(); 
		break;
	}
	case 8: 
	{ 
		hangman_play_botany_hard(); 
		break;
	}
	case 9:
	{
		hangman_play_botany_impossible();
		break;
	}
	case 10: 
	{
		hangman_play_city_easy(); 
		break;
	}
	case 11: 
	{
		hangman_play_city_medium(); 
		break;
	}
	case 12:
	{
		hangman_play_city_hard();
		break;
	}
	case 13:
	{
		hangman_play_city_impossible();
		break;
	}
	case 14:
	{
		hangman_play_physics_easy();
		break;
	}
	case 15:
	{
		hangman_play_physics_medium();
		break;
	}
	case 16:
	{
		hangman_play_physics_hard(); 
		break;
	}
	case 17:
	{
		hangman_play_physics_impossible(); 
		break;
	}
	case 18:
	{ 
		hangman_play_fauna_easy();
		break;
	}
	case 19: 
	{
		hangman_play_fauna_medium();
		break;
	}
	case 20: 
	{
		hangman_play_fauna_hard();
		break;
	}
	case 21:
	{
		hangman_play_fauna_impossible();
		break;
	}
	case 22: 
	{
		hangman_play_flora_easy();
		break;
	}
	case 23: 
	{
		hangman_play_flora_medium(); 
		break;
	}
	case 24: 
	{
		hangman_play_flora_hard();
		break;
	}
	case 25: 
	{
		hangman_play_flora_impossible();
		break;
	}
	case 26: 
	{ 
		hangman_play_all_easy(); 
		break;
	}
	case 27: 
	{
		hangman_play_all_medium(); 
		break;
	}
	case 28: 
	{ 
		hangman_play_all_hard();
		break;
	}
	case 29: 
	{
		hangman_play_all_impossible(); 
		break;
	}
	case 30: 
	{
		hangman_play_normal_all();
		break;
	}
	case 31: 
	{
		hangman_play_botany_all();
		break;
	}
	case 32:
	{
		hangman_play_city_all();
		break;
	}
	case 33:
	{
		hangman_play_physics_all();
		break;
	}
	case 34:
	{
		hangman_play_fauna_all();
		break;
	}
	case 35: 
	{ 
		hangman_play_flora_all(); 
		break;
	}
	case 36: {
		hangman_play_all_all();
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