#pragma once

struct Stats 
{
    int attemp;
    int game;
    double total_win;
    double total_los;
};

void save(int& attemp, int& game, int& total_win, int& total_loss);
