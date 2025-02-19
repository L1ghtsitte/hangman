#include "include\includes.h"
#include "include\hangman.h"
#include "include\statistics.h"

void save(int& attemp, int& game, int& total_win, int& total_loss) ///Функция для сохранения информации об 
{
    ofstream out("statistics.txt");
    if (out.is_open())
    {
        out << "-----------------------------" << endl;
        out << "Количество попыток : " << attemp << endl;
        out << "Количество игр : " << game << endl;
        out << "Количество побед : " << total_win << endl;
        out << "Количество проигрышей : " << total_loss << endl;
        out << "-----------------------------" << endl;
        out.close();
    }
}
