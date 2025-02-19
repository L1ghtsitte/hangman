#pragma once
#pragma comment (lib, "winmm.lib") //��� ������ �����

#include <iostream> //����������� ����������
#include <random> //��� ��������� ���������� �����
#include <ctime> //��� ������ �� ��������
#include <fstream> //��� ������/������ ���������� � ����
#include <string> //��� ������ �� ��������
#include <chrono> //��� ��������� ���������� ������� 
#include <thread> //��� ���� �� ����
#include <Windows.h> //��� ��������� ����� � �������
#include <sstream> // ��� ��������� ��������

using namespace std; //��������� ������ ����� cout, ������ std::cout
using namespace std::chrono; //��� �� �������� �������� ������� ��������� ����
using namespace std::this_thread; //��� �� �������� �������� ������� ��������� �������� � ����

void setConsoleColor(int colorCode); //������� ��� ����� ����� �������
void SetFullscreenMode(); //������� ������������� ������