#include "include\includes.h"
#include "include\hangman.h"
#include "include\statistics.h"

void save(int& attemp, int& game, int& total_win, int& total_loss) ///������� ��� ���������� ���������� �� 
{
    ofstream out("statistics.txt");
    if (out.is_open())
    {
        out << "-----------------------------" << endl;
        out << "���������� ������� : " << attemp << endl;
        out << "���������� ��� : " << game << endl;
        out << "���������� ����� : " << total_win << endl;
        out << "���������� ���������� : " << total_loss << endl;
        out << "-----------------------------" << endl;
        out.close();
    }
}
