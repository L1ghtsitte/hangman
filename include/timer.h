#pragma once

class Timer //Класс для вычесления времени прошедщим с момента начала до завершиния программы
{
public:
    Timer();
    void start();
    void stop();
    double get_elapsed_time() const;

private:
    time_point<high_resolution_clock> start_time;
    time_point<high_resolution_clock> stop_time;
    bool is_running;
};

