#pragma once

void hangman_play(const string& theme, const string& filename, int word_count);

void hangman_play_normal_easy();
void hangman_play_normal_medium();
void hangman_play_normal_hard(); 
void hangman_play_normal_impossible(); 
void hangman_play_normal_all();

void hangman_play_botany_easy();
void hangman_play_botany_medium();
void hangman_play_botany_hard();
void hangman_play_botany_impossible();
void hangman_play_botany_all();

void hangman_play_city_easy();
void hangman_play_city_medium();
void hangman_play_city_hard();
void hangman_play_city_impossible();
void hangman_play_city_all();

void hangman_play_physics_easy();
void hangman_play_physics_medium();
void hangman_play_physics_hard();
void hangman_play_physics_impossible();
void hangman_play_physics_all();

void hangman_play_fauna_easy();
void hangman_play_fauna_medium();
void hangman_play_fauna_hard();
void hangman_play_fauna_impossible();
void hangman_play_fauna_all();

void hangman_play_flora_easy();
void hangman_play_flora_medium();
void hangman_play_flora_hard();
void hangman_play_flora_impossible();
void hangman_play_flora_all();

void hangman_play_all_easy();
void hangman_play_all_medium();
void hangman_play_all_hard();
void hangman_play_all_impossible();
void hangman_play_all_all();

int start_game(int& choise_words); // фунеция выбора сложности игры
int dificult(int& choise_dificult); //Функция начало игры
string displayWord(const string& word, const vector<char>& guessed_letters); //Функция для показа текущего прогресса слова
void hangman_play(string& line, bool& won_game, bool& loss_game, int& miss); //Оснавная функция игры
void display_mistakes(int& miss, bool& loss_game); //Функция проигрыш и ошибок
void display_won(bool& won_game); //Функция выигрыша
