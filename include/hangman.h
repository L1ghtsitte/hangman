#pragma once

void hangman_play_normal(); //������� �������� ������
void hangman_play_botany(); //������� ���� ��������
void hangman_play_city(); //������� ���� ������
void hangman_play_physics(); //������� ���� ������ 
void hangman_play_fauna(); //������� ���� ����� 
void hangman_play_flora(); //������� ���� �����
void hangman_play_all(); //������� ������ ���� ��� �����
int start_game(int& choise); //������� ������ ����
string displayWord(const string& word, const vector<char>& guessed_letters); //������� ��� ������ �������� ��������� �����
void hangman_play(string& line, bool& won_game, bool& loss_game, int& miss); //�������� ������� ����
void display_mistakes(int& miss, bool& loss_game); //������� �������� � ������
void display_won(bool& won_game); //������� ��������
