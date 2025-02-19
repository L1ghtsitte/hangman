#pragma once
#pragma comment (lib, "winmm.lib") //Для вывода звука

#include <iostream> //Стандартная библеотека
#include <random> //Для генерации рандомного числа
#include <ctime> //Для работы со временем
#include <fstream> //Для чтения/записи информации в файл
#include <string> //Для работы со строками
#include <chrono> //Для измерения интервалов времени 
#include <thread> //Для того же звка
#include <Windows.h> //Для изменения цвета в консоли
#include <sstream> // Для потоковой передачи

using namespace std; //Позволяет писать сразу cout, вместо std::cout
using namespace std::chrono; //Так же помогает ускорить процесс написания кода
using namespace std::this_thread; //Так же помогает ускорить процесс написания задержки в коде

void setConsoleColor(int colorCode); //Функция для смены цвета консоли
void SetFullscreenMode(); //Функция полноэкраного режима