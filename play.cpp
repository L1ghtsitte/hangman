#include "include\includes.h"
#include "include\hangman.h"
#include "include\statistics.h"

void hangman_play(string& line, bool& won_game, bool& loss_game, int& miss)
{

    string secretWord = line; // Задает загаданое слово
    vector<char> guessed_letters;
    int attemp = 0; //Количество попыток
    char guess;
    int total_win; //Количество выигрышей
    int total_loss; //Количество проигрышей
    int game; //Количество игр

    game = 0;
    total_loss = 0;
    total_win = 0;
    game++;

    while (miss < 10) 
    {
        display_mistakes(miss, loss_game);
        cout << "Слово : " << displayWord(secretWord, guessed_letters) << endl;
        cout << "Введённые буквы : ";
        for (char letter : guessed_letters) // Отвечает за уже введеные буквы
        {
            cout << letter << " ";  //Выводит за уже введеные буквы
        }
        cout << endl;
        cout << "Введите вашу букву : ";
        cin >> guess;
        attemp++;
        guess = tolower(guess); // Отвечает за ввод букв

        if (find(guessed_letters.begin(), guessed_letters.end(), guess) != guessed_letters.end()) // Отвечает за повторно введеные буквы
        {
            cout << "Вы уже вводили эту букву" << endl;
            continue;
        }
        if (secretWord.find(guess) == string::npos) miss++; // Отвечает за неправельно введеные буквы
        guessed_letters.push_back(guess);
        if (displayWord(secretWord, guessed_letters).find('_') == string::npos) // Отвечает за выигрыш
        {
            mciSendString(L" play resources/music/won.mp3", NULL, 0, 0);
            PlaySound(TEXT("resources/music/won.mp3"), NULL, SND_FILENAME | SND_ASYNC);
            display_won(won_game);
            total_win += 1;
            cout << "-----------------------------" << endl;
            cout << "Вы выиграли" << endl;
            cout << "Слово было : " << secretWord << endl; 
            cout << "Количество попыток : " << attemp << endl;
            cout << "Введённые буквы : ";
            for (char letter : guessed_letters) // Отвечает за уже введеные буквы
            {
                cout << letter << " ";  //Выводит за уже введеные буквы
            }
            cout << endl;
            cout << "-----------------------------" << endl;
            save(attemp, game, total_win, total_loss);
            //encript_normal(cript);
            break;
        }
    }
    if (miss == 10) // Отвечает за проигрыш
    {
        mciSendString(L" play resources/music/loss.mp3", NULL, 0, 0);
        PlaySound(TEXT("resources/music/loss.mp3"), NULL, SND_FILENAME | SND_ASYNC);
        display_mistakes(miss, loss_game);
        total_loss += 1;
        cout << "-----------------------------" << endl;
        cout << "Вы проиграли" << endl;
        cout << "Слово было : " << secretWord << endl;
        cout << "Количество попыток : " << attemp << endl;
        cout << "Введённые буквы : ";
        for (char letter : guessed_letters) // Отвечает за уже введеные буквы
        {
            cout << letter << " "; //Выводит за уже введеные буквы
        }
        cout << endl;
        save(attemp, game, total_win, total_loss);
    }
}
