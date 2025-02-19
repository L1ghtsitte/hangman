#include "include\includes.h"
#include "include\timer.h"

double total_time = 0;

Timer::Timer() : is_running(false) 
{
}
void Timer::start()  //������� ������ �������
{
    if (!is_running) 
    {
        start_time = high_resolution_clock::now();
        is_running = true;
    }
}
void Timer::stop() //������� ����� �������
{
    if (is_running) 
    {
        stop_time = high_resolution_clock::now();
        is_running = false;
    }
}
double Timer::get_elapsed_time() const //������� ��� ��������� ���������� �������
{
    if (is_running) 
    {
        auto now = high_resolution_clock::now();
        total_time = duration<double>(now - start_time).count();
        return duration<double>(now - start_time).count();
    }
    else 
    {
        total_time = duration<double>(stop_time - start_time).count();
        return duration<double>(stop_time - start_time).count();
    }
}