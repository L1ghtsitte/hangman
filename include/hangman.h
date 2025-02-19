#pragma once

void hangman_play_normal(); //Функция ОБЫЧНОГО режима
void hangman_play_botany(); //Функция темы БОТАНИКИ
void hangman_play_city(); //Функция темы ГОРОДА
void hangman_play_physics(); //Функция темы ФИЗИКИ 
void hangman_play_fauna(); //Функция темы ФАУНЫ 
void hangman_play_flora(); //Функция темы ФЛОРЫ
void hangman_play_all(); //Функция выбора ВСЕХ тем сразу
int start_game(int& choise); //Функция начало игры
string displayWord(const string& word, const vector<char>& guessed_letters); //Функция для показа текущего прогресса слова
void hangman_play(string& line, bool& won_game, bool& loss_game, int& miss); //Оснавная функция игры
void display_mistakes(int& miss, bool& loss_game); //Функция проигрыш и ошибок
void display_won(bool& won_game); //Функция выигрыша
