#include "include\includes.h"
#include "include\hangman.h"
#include "include\statistics.h"

void hangman_play(string& line, bool& won_game, bool& loss_game, int& miss)
{

    string secretWord = line; // ������ ��������� �����
    vector<char> guessed_letters;
    int attemp = 0; //���������� �������
    char guess;
    int total_win; //���������� ���������
    int total_loss; //���������� ����������
    int game; //���������� ���

    game = 0;
    total_loss = 0;
    total_win = 0;
    game++;

    while (miss < 10) 
    {
        display_mistakes(miss, loss_game);
        cout << "����� : " << displayWord(secretWord, guessed_letters) << endl;
        cout << "�������� ����� : ";
        for (char letter : guessed_letters) // �������� �� ��� �������� �����
        {
            cout << letter << " ";  //������� �� ��� �������� �����
        }
        cout << endl;
        cout << "������� ���� ����� : ";
        cin >> guess;
        attemp++;
        guess = tolower(guess); // �������� �� ���� ����

        if (find(guessed_letters.begin(), guessed_letters.end(), guess) != guessed_letters.end()) // �������� �� �������� �������� �����
        {
            cout << "�� ��� ������� ��� �����" << endl;
            continue;
        }
        if (secretWord.find(guess) == string::npos) miss++; // �������� �� ����������� �������� �����
        guessed_letters.push_back(guess);
        if (displayWord(secretWord, guessed_letters).find('_') == string::npos) // �������� �� �������
        {
            mciSendString(L" play resources/music/won.mp3", NULL, 0, 0);
            PlaySound(TEXT("resources/music/won.mp3"), NULL, SND_FILENAME | SND_ASYNC);
            display_won(won_game);
            total_win += 1;
            cout << "-----------------------------" << endl;
            cout << "�� ��������" << endl;
            cout << "����� ���� : " << secretWord << endl; 
            cout << "���������� ������� : " << attemp << endl;
            cout << "�������� ����� : ";
            for (char letter : guessed_letters) // �������� �� ��� �������� �����
            {
                cout << letter << " ";  //������� �� ��� �������� �����
            }
            cout << endl;
            cout << "-----------------------------" << endl;
            save(attemp, game, total_win, total_loss);
            //encript_normal(cript);
            break;
        }
    }
    if (miss == 10) // �������� �� ��������
    {
        mciSendString(L" play resources/music/loss.mp3", NULL, 0, 0);
        PlaySound(TEXT("resources/music/loss.mp3"), NULL, SND_FILENAME | SND_ASYNC);
        display_mistakes(miss, loss_game);
        total_loss += 1;
        cout << "-----------------------------" << endl;
        cout << "�� ���������" << endl;
        cout << "����� ���� : " << secretWord << endl;
        cout << "���������� ������� : " << attemp << endl;
        cout << "�������� ����� : ";
        for (char letter : guessed_letters) // �������� �� ��� �������� �����
        {
            cout << letter << " "; //������� �� ��� �������� �����
        }
        cout << endl;
        save(attemp, game, total_win, total_loss);
    }
}
