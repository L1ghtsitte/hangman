#include "include\includes.h"
#include "include\hangman.h"

string filename_normal = "resources/words/words_normal.txt"; //���� �� ������������ �������
string filename_botany = "resources/words/words_botany.txt"; //���� �� ������� �� ���� ��������
string filename_city = "resources/words/words_city.txt"; //���� �� ������� �� ���� ������
string filename_physics = "resources/words/words_physics.txt"; //���� �� ������� �� ���� ������
string filename_fauna = "resources/words/words_fauna.txt"; //���� �� ������� �� ���� �����
string filename_flora = "resources/words/words_flora.txt"; //���� �� ������� �� ���� �����
string filename_all = "resources/words/words_all.txt"; //���� �� ������� �� ��� ���� ������ ������

int miss; //���������� ���������� ��������� ������
bool won_game; //���������� ���������� ���������� ����
bool loss_game; //���������� ���������� ��������� ����

// ������� ��� ������������ ������
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
	setConsoleColor(4); //������ ���� ������ ������� �� �������
	cout << "ver 0.1 made by L1ghtsitte" << endl;  //��-��-�� ��� �
	cout << "github.com/L1ghtsitte || t.me/hellsfrik" << endl;  //��-��-�� ��� ���� �
	setConsoleColor(7); //������ ���� ������ ������� ������� �� �����
	cout << "������ ��� ���� ��� ��������� �������� :(" << endl;
	cout << "� ���� ���� ��� ������� ������ �� ����" << endl;
	cout << "���� ���� �� ����� �� ������� � ������ ������ ����, ��� ��������� ���������� �������" << endl;
	cout << "(���� ����� ����� �� ���� �����)" << endl;
	cout << "1 - ������� (3 666 ����)" << endl;
	cout << "2 - �������� (141 ����)" << endl;
	cout << "3 - ������ (306 ����)" << endl;
	cout << "4 - ������ (305 ����)" << endl;
	cout << "5 - ����� (292 ����)" << endl;
	cout << "6 - ����� (592 ����)" << endl;
	cout << "7 - ��� ������ (5 301 ����)" << endl;
	setConsoleColor(4); //������ ���� ������ ������� �� �������
	cout << "��� ����� : ";
	cin >> choise;
	setConsoleColor(7); //������ ���� ������ ������� ������� �������
	return choise; //���������� ��� ����� � main.cpp, ��� �� ��� ����� �������� �� ��������������� case
}

void hangman_play_normal() //������� ��� ����������� ����
{
	string crypto_str;
	string line;
	string str;

	int random_word;

	cout << "��� ����� ��� �� ������� �����" << endl;
	cout << "���� ��� � ����������� ��������� ����� �������� ����" << endl;

	miss = 0; //������� ���������� �������� ����
	random_word = rand() % 3666; //����� ����� �� �����

	ifstream file(filename_normal);

	if (file.is_open()) //��������� ����
	{
		int currentLine;

		currentLine = 1; //�������� ����� ����� � �������� ����

		while (getline(file, line))
		{
			if (currentLine == random_word) //���������� �������� �� ������ ����� �� �������� ��� ������� ��������� �����, � ���������� �������� 
			{
				break;
			}
			currentLine++; //�������� ��� �� ����� ���������
		}
		file.close(); //��������� ����
	}

	line = decrypt(line, 4);

	system("pause"); //������ ����� � �������
	system("cls"); //������� �������

	display_mistakes(miss, loss_game); //������ ������� �������� ��������
	hangman_play(line, won_game, loss_game, miss); //������ ������� �������� �����
}
void hangman_play_botany() //������� ��� ���� �� ���� ��������
{
	int random_word;
	string line;
	ifstream file(filename_botany);

	cout << "��� ����� ��� �� �������� " << endl;
	cout << "���� ��� � ����������� ��������� ����� �������� ����" << endl;

	miss = 0; //������� ���������� �������� ����
	random_word = rand() % 141; //����� ����� �� �����

	if (file.is_open()) //��������� ����
	{
		int currentLine;

		currentLine = 1; //�������� ����� ����� � �������� ����

		while (getline(file, line))
		{
			if (currentLine == random_word) //���������� �������� �� ������ ����� �� �������� ��� ������� ��������� �����, � ���������� �������� 
			{
				break;
			}


			currentLine++; //�������� ��� �� ����� ���������
		}
		file.close(); //��������� ����
	}
	
	line = decrypt(line, 4); //������������ ��������� �����


	system("pause"); //������ ����� � �������
	system("cls"); //������� �������

	display_mistakes(miss, loss_game); //������ ������� �������� ��������
	hangman_play(line, won_game, loss_game, miss); //������ ������� �������� �����
}
void hangman_play_city() //������� ��� ���� �� ���� ������
{
	int random_word;
	string line;
	ifstream file(filename_city);

	cout << "��� ����� ��� �� ������" << endl;
	cout << "���� ��� � ����������� ��������� ����� �������� ����" << endl;

	miss = 0; //������� ���������� �������� ����
	random_word = rand() % 306; //����� ����� �� �����

	if (file.is_open()) //��������� ����
	{
		int currentLine;

		currentLine = 1; //�������� ����� ����� � �������� ����

		while (getline(file, line))
		{
			if (currentLine == random_word) //���������� �������� �� ������ ����� �� �������� ��� ������� ��������� �����, � ���������� �������� 
			{
				break;
			}
			currentLine++; //�������� ��� �� ����� ���������
		}
		file.close(); //��������� ����
	}

	line = decrypt(line, 4);

	system("pause"); //������ ����� � �������
	system("cls"); //������� �������

	display_mistakes(miss, loss_game); //������ ������� �������� ��������
	hangman_play(line, won_game, loss_game, miss); //������ ������� �������� �����
}
void hangman_play_physics() //������� ��� ���� �� ���� ������
{
	int random_word;
	string line;
	ifstream file(filename_physics);

	cout << "��� ����� ��� �� ������" << endl;
	cout << "���� ��� � ����������� ��������� ����� �������� ����" << endl;

	miss = 0; //������� ���������� �������� ����
	random_word = rand() % 305; //����� ����� �� �����

	if (file.is_open()) //��������� ����
	{
		int currentLine;

		currentLine = 1; //�������� ����� ����� � �������� ����

		while (getline(file, line))
		{
			if (currentLine == random_word) //���������� �������� �� ������ ����� �� �������� ��� ������� ��������� �����, � ���������� �������� 
			{
				break;
			}
			currentLine++; //�������� ��� �� ����� ���������
		}
		file.close(); //��������� ����
	}

	line = decrypt(line, 4);

	system("pause"); //������ ����� � �������
	system("cls"); //������� �������

	display_mistakes(miss, loss_game); //������ ������� �������� ��������
	hangman_play(line, won_game, loss_game, miss); //������ ������� �������� �����
}
void hangman_play_fauna() //������� ��� ���� �� ���� �����
{
	int random_word;
	string line;
	ifstream file(filename_fauna);

	cout << "��� ����� ��� �� �����" << endl;
	cout << "���� ��� � ����������� ��������� ����� �������� ����" << endl;

	miss = 0; //������� ���������� �������� ����
	random_word = rand() % 292; //����� ����� �� �����

	if (file.is_open()) //��������� ����
	{
		int currentLine;

		currentLine = 1; //�������� ����� ����� � �������� ����

		while (getline(file, line))
		{
			if (currentLine == random_word) //���������� �������� �� ������ ����� �� �������� ��� ������� ��������� �����, � ���������� �������� 
			{
				break;
			}
			currentLine++; //�������� ��� �� ����� ���������
		}
		file.close(); //��������� ����
	}

	line = decrypt(line, 4);

	system("pause"); //������ ����� � �������
	system("cls"); //������� �������

	display_mistakes(miss, loss_game); //������ ������� �������� ��������
	hangman_play(line, won_game, loss_game, miss); //������ ������� �������� �����
}
void hangman_play_flora() //������� ��� ���� �� ���� �����
{
	int random_word;
	string line;
	ifstream file(filename_flora);

	cout << "��� ����� ��� �� �����" << endl;
	cout << "���� ��� � ����������� ��������� ����� �������� ����" << endl;

	miss = 0; //������� ���������� �������� ����
	random_word = rand() % 592; //����� ����� �� �����

	if (file.is_open()) //��������� ����
	{
		int currentLine;

		currentLine = 1; //�������� ����� ����� � �������� ����

		while (getline(file, line))
		{
			if (currentLine == random_word) //���������� �������� �� ������ ����� �� �������� ��� ������� ��������� �����, � ���������� �������� 
			{
				break;
			}
			currentLine++; //�������� ��� �� ����� ���������
		}
		file.close(); //��������� ����
	}

	line = decrypt(line, 4);

	system("pause"); //������ ����� � �������
	system("cls"); //������� �������

	display_mistakes(miss, loss_game); //������ ������� �������� ��������
	hangman_play(line, won_game, loss_game, miss); //������ ������� �������� �����
}
void hangman_play_all()  //������� ��� ���� ���� �����
{
	int random_word;
	string line;
	ifstream file(filename_all);

	cout << "�� �������� ���� ��������� ������ ��� ������ �����" << endl;
	cout << "���� ��� � ����������� ��������� ����� �������� ����" << endl;

	miss = 0; //������� ���������� �������� ����
	random_word = rand() % 5301; //����� ����� �� �����

	if (file.is_open()) //��������� ����
	{
		int currentLine;

		currentLine = 1; //�������� ����� ����� � �������� ����

		while (getline(file, line))
		{
			if (currentLine == random_word) //���������� �������� �� ������ ����� �� �������� ��� ������� ��������� �����, � ���������� �������� 
			{
				break;
			}
			currentLine++; //�������� ��� �� ����� ���������
		}
		file.close(); //��������� ����
	}

	line = decrypt(line, 4);

	system("pause"); //������ ����� � �������
	system("cls"); //������� �������

	display_mistakes(miss, loss_game); //������ ������� �������� ��������
	hangman_play(line, won_game, loss_game, miss); //������ ������� �������� �����
}
