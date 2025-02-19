#include "include\statistics.h"
#include "include\includes.h"
#include "include\hangman.h"
#include "include\timer.h"

void setConsoleColor(int colorCode) //������ ���� � �������
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorCode);
}
void SetFullscreenMode() 
{
	HWND hwnd = GetConsoleWindow(); // �������� handle ����������� ����
	SendMessage(hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0); // ����������� � ������������� �����
}
int main(int& attemp, int& game, int& total_win, int& total_loss)
{

	Timer game_timer;
	int choise = 0;
	string crypto_str;
	string str;

	SetFullscreenMode();
	system("chcp 1251"); //������� ���������
	system("cls"); //������� �������

	srand(time(nullptr)); //��� ���������� ������ ���� ( � ������� ... = rand() % 50

	game_timer.start(); //������ �������

	start_game(choise); //������ ����

	switch (choise) //����� ������ ����
	{
	case 1:
	{
		hangman_play_normal(); //����� �������� ������
		break;
	}
	case 2:
	{
		hangman_play_botany(); //����� ���� ��������
		break;
	}
	case 3:
	{
		hangman_play_city(); //����� ���� ������
		break;
	}
	case 4:
	{
		hangman_play_physics(); //����� ���� ������
		break;
	}
	case 5:
	{
		hangman_play_fauna();  //����� ���� �����
		break;
	}
	case 6:
	{
		hangman_play_flora(); //����� ���� ����� 
		break;
	}
	case 7:
	{
		hangman_play_all(); //����� ���� ��� �����
		break;
	}
	case 8:
	{
		break;
	}
	default: break;
	}

	game_timer.stop(); //����� �������
	cout << "����� � ���� : " << game_timer.get_elapsed_time() << " ������" << std::endl; //������� ��������� �������
	cout << "-----------------------------" << endl;
	system("pause");
	mciSendString(L" play resources/music/ben_bb.mp3", NULL, 0, 0);
	PlaySound(TEXT("resources/music/ben_bb.mp3"), NULL, SND_FILENAME | SND_ASYNC);
	sleep_for(milliseconds(1400));
}