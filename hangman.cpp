#include "include\includes.h"
#include "include\hangman.h"

string filename_normal_easy = "resources/words/words_normal_easy_crypt.txt"; //���� �� ������������ �������
string filename_normal_medium = "resources/words/words_normal_medium_crypt.txt"; //���� �� ������������ �������
string filename_normal_hard = "resources/words/words_normal_hard_crypt.txt"; //���� �� ������������ �������
string filename_normal_impossible = "resources/words_normal_impossidle_crypt.txt"; //���� �� ������������ �������
string filename_normal_all = "resources/words/words_normal_all_crypt.txt"; //���� �� ������������ �������

string filename_botany_easy = "resources/words/words_botany_easy_crypt.txt"; //���� �� ������� �� ���� ��������
string filename_botany_medium = "resources/words/words_botany_medium_crypt.txt"; //���� �� ������� �� ���� ��������
string filename_botany_hard = "resources/words/words_botany_hard_crypt.txt"; //���� �� ������� �� ���� ��������
string filename_botany_impossible = "resources/words/words_botany_impossible_crypt.txt"; //���� �� ������� �� ���� ��������
string filename_botany_all = "resources/words/words_botany_all_crypt.txt"; //���� �� ������� �� ���� ��������

string filename_city_easy = "resources/words/words_city_easy_crypt.txt"; //���� �� ������� �� ���� ������
string filename_city_medium = "resources/words/words_city_medium_crypt.txt"; //���� �� ������� �� ���� ������
string filename_city_hard = "resources/words/words_city_hard_crypt.txt"; //���� �� ������� �� ���� ������
string filename_city_impossible = "resources/words/words_city_impossidle_crypt.txt"; //���� �� ������� �� ���� ������
string filename_city_all = "resources/words/words_city_all_crypt.txt"; //���� �� ������� �� ���� ������

string filename_physics_easy = "resources/words/words_physics_easy_crypt.txt"; //���� �� ������� �� ���� ������
string filename_physics_medium = "resources/words/words_physics_medium_crypt.txt"; //���� �� ������� �� ���� ������
string filename_physics_hard = "resources/words/words_physics_hard_crypt.txt"; //���� �� ������� �� ���� ������
string filename_physics_impossible = "resources/words/words_physics_impossidle_crypt.txt"; //���� �� ������� �� ���� ������
string filename_physics_all = "resources/words/words_physics_all_crypt.txt"; //���� �� ������� �� ���� ������

string filename_fauna_easy = "resources/words/words_fauna_easy_crypt.txt"; //���� �� ������� �� ���� �����
string filename_fauna_medium = "resources/words/words_fauna_medium_crypt.txt"; //���� �� ������� �� ���� �����
string filename_fauna_hard = "resources/words/words_fauna_hard_crypt.txt"; //���� �� ������� �� ���� �����
string filename_fauna_impossible = "resources/words/words_fauna_impossidle_crypt.txt"; //���� �� ������� �� ���� �����
string filename_fauna_all = "resources/words/words_fauna_all_crypt.txt"; //���� �� ������� �� ���� �����

string filename_flora_easy = "resources/words/words_flora_easy_crypt.txt"; //���� �� ������� �� ���� �����
string filename_flora_medium = "resources/words/words_flora_medium_crypt.txt"; //���� �� ������� �� ���� �����
string filename_flora_hard = "resources/words/words_flora_hard_crypt.txt"; //���� �� ������� �� ���� �����
string filename_flora_impossible = "resources/words/words_flora_impossidle_crypt.txt"; //���� �� ������� �� ���� �����
string filename_flora_all = "resources/words/words_flora_all_crypt.txt"; //���� �� ������� �� ���� �����

string filename_all_easy = "resources/words/words_all_easy_crypt.txt"; //���� �� ������� �� ��� ���� ������ ������
string filename_all_medium = "resources/words/words_all_medium_crypt.txt"; //���� �� ������� �� ��� ���� ������ ������
string filename_all_hard = "resources/words/words_all_hard_crypt.txt"; //���� �� ������� �� ��� ���� ������ ������
string filename_all_impossible = "resources/words/words_all_impossidle_crypt.txt"; //���� �� ������� �� ��� ���� ������ ������
string filename_all_all = "resources/words/words_all_all_crypt.txt"; //���� �� ������� �� ��� ���� ������ ������

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

int start_game(int& choise_words)
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
	cout << "���� ���� �� ����� �� ������� � ������ ��������� � ������ ����, ��� ��������� ���������� �������" << endl;
	cout << "(���� ����� ����� �� ���� �����)" << endl;
	cout << "(������ - ������� - ������� - ���������� | �����)" << endl;
	cout << "1 - ������� (449 - 5 301 - 631 - 420 | 5167)" << endl;
	cout << "2 - �������� (125 - 141 - 175 - 100 | 541)" << endl;
	cout << "3 - ������ (1050 - 305 - 1000 - 749 | 3105)" << endl;
	cout << "4 - ������ (179 - 1161 - 358 - 256 | 1954)" << endl;
	cout << "5 - ����� (32 - 803 - 36 - 25 | 896)" << endl;
	cout << "6 - ����� (29 - 592 - 38 - 24 | 683)" << endl;
	cout << "7 - ��� ������ (1864 - 6666 - 2239 - 1574 | 12345)" << endl;
	setConsoleColor(4); //������ ���� ������ ������� �� �������
	cout << "��� ����� : ";
	cin >> choise_words;
	setConsoleColor(7); //������ ���� ������ ������� ������� �������
	return choise_words; //���������� ��� ����� � main.cpp, ��� �� ��� ����� �������� � �������� �� ��������������� case
}

int dificult(int& choise_dificult)
{
	cout << "��� ������ ����������� �� ����������" << endl;
	cout << "1 - ������ (� ������ �� 5 ����)" << endl;
	cout << "2 - ������� (� ������ �� 5 �� 8 ����)" << endl;
	cout << "3 - ������� (� ������ �� 8 �� 9 ����)" << endl;
	cout << "4 - ����������� � ������ ( �� 10 � ����� ����)" << endl;
	cout << "5 - ��� ��� ���� ����" << endl;
	setConsoleColor(4); //������ ���� ������ ������� �� �������
	cout << "��� ����� : ";
	cin >> choise_dificult;
	setConsoleColor(7); //������ ���� ������ ������� ������� �������
	return choise_dificult; //���������� ��� ����� � main.cpp, ��� �� ��� ����� �������� � �������� �� ��������������� case
}

void hangman_play(const string& theme, const string& filename, int word_count) //������������� ������� ��� ����
{
	int random_word;
	string line;
	ifstream file(filename);

	cout << "��� ����� ��� �� " << theme << endl;
	cout << "����, ��� � ����������� ���������, ����� �������� ����" << endl;

	miss = 0; //������� ����������� ��������� ����
	random_word = rand() % word_count; //����� ����� �� �����

	if (file.is_open()) //��������� ����
	{
		int currentLine = 1; //�������� ����� ����� � ��������� ����

		while (getline(file, line))
		{
			if (currentLine == random_word) //���������� ��������� �� ������ ����� �� �������� ��� ������� ���������� �����
			{
				break;
			}
			currentLine++; //�������� ��� �� ����� ���������
		}
		file.close(); //��������� ����
	}

	line = decrypt(line, 4); //������������ ���������� �����

	system("pause"); //������ ����� � �������
	system("cls"); //������� �������

	display_mistakes(miss, loss_game); //������� ������� �������� ��������
	hangman_play(line, won_game, loss_game, miss); //������� ������� �������� �����
}

void hangman_play_normal_easy() { hangman_play("������� ����� (��������� : �����)", filename_normal_easy, 449); }
void hangman_play_normal_medium() { hangman_play("������� ����� (��������� : ���������)", filename_normal_medium, 5301); }
void hangman_play_normal_hard() { hangman_play("������� ����� (��������� : ������)", filename_normal_hard, 631); }
void hangman_play_normal_impossible() { hangman_play("������� ����� (��������� : ����������)", filename_normal_impossible, 420); }
void hangman_play_normal_all() { hangman_play("������� ����� (��������� : ��� ������)", filename_normal_all, 5167); } 

void hangman_play_botany_easy() { hangman_play("����� �������� (��������� : �����)", filename_botany_easy, 125); }
void hangman_play_botany_medium() { hangman_play("����� �������� (��������� : ���������)", filename_botany_medium, 141); }
void hangman_play_botany_hard() { hangman_play("����� �������� (��������� : ������)", filename_botany_hard, 175); }
void hangman_play_botany_impossible() { hangman_play("����� �������� (��������� : ����������)", filename_botany_impossible, 100); }
void hangman_play_botany_all() { hangman_play("����� �������� (��������� : ��� ������)", filename_botany_all, 541); }

void hangman_play_city_easy() { hangman_play("��������� ����� (��������� : �����)", filename_city_easy, 1050); }
void hangman_play_city_medium() { hangman_play("��������� ����� (��������� : ���������)", filename_city_medium, 305); }
void hangman_play_city_hard() { hangman_play("��������� ����� (��������� : ������)", filename_city_hard, 1000); }
void hangman_play_city_impossible() { hangman_play("��������� ����� (��������� : ����������)", filename_city_impossible, 749); }
void hangman_play_city_all() { hangman_play("��������� ����� (��������� : ��� ������)", filename_city_all, 3105); }

void hangman_play_physics_easy() { hangman_play("���������� ����� (��������� : �����)", filename_physics_easy, 179); }
void hangman_play_physics_medium() { hangman_play("���������� ����� (��������� : ���������)", filename_physics_medium, 1161); }
void hangman_play_physics_hard() { hangman_play("���������� ����� (��������� : ������)", filename_physics_hard, 358); }
void hangman_play_physics_impossible() { hangman_play("���������� ����� (��������� : ����������)", filename_physics_impossible, 256); }
void hangman_play_physics_all() { hangman_play("���������� ����� (��������� : ��� ������)", filename_physics_all, 1954); }

void hangman_play_fauna_easy() { hangman_play("����� ����� (��������� : �����)", filename_fauna_easy, 32); }
void hangman_play_fauna_medium() { hangman_play("����� ����� (��������� : ���������)", filename_fauna_medium, 803); }
void hangman_play_fauna_hard() { hangman_play("����� ����� (��������� : ������)", filename_fauna_hard, 36); }
void hangman_play_fauna_impossible() { hangman_play("����� ����� (��������� : ����������)", filename_fauna_impossible, 25); }
void hangman_play_fauna_all() { hangman_play("����� ����� (��������� : ��� ������)", filename_fauna_all, 896); }

void hangman_play_flora_easy() { hangman_play("����� ����� (��������� : �����)", filename_flora_easy, 29); }
void hangman_play_flora_medium() { hangman_play("����� ����� (��������� : ���������)", filename_flora_medium, 592); }
void hangman_play_flora_hard() { hangman_play("����� ����� (��������� : ������)", filename_flora_hard, 38); }
void hangman_play_flora_impossible() { hangman_play("����� ����� (��������� : ����������)", filename_flora_impossible, 24); }
void hangman_play_flora_all() { hangman_play("����� ����� (��������� : ��� ������)", filename_flora_all, 683); }

void hangman_play_all_easy() { hangman_play("��� � ����� (��������� : �����)", filename_all_easy, 1864); }
void hangman_play_all_medium() { hangman_play("��� � ����� (��������� : ���������)", filename_all_medium, 6666); }
void hangman_play_all_hard() { hangman_play("��� � ����� (��������� : ������)", filename_all_hard, 2239); }
void hangman_play_all_impossible() { hangman_play("��� � ����� (��������� : ����������)", filename_all_impossible, 1574); }
void hangman_play_all_all() { hangman_play("��� � ����� (��������� : ��� ������)", filename_all_all, 12345); }