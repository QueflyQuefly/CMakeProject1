// CMakeProject1.cpp: определяет точку входа для приложения.
//

#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <math.h>
#include <map>

using namespace std;

int main()
{
    locale::global(locale(""));
    //char buff[4000]; // буфер считываемого из файла текста
    string fileName;
    string fileExt;
    unsigned char byte;
    size_t fileExpPosition;
    map<int, double> mymap;
    map<int, double>::iterator it;
    int exitbytes[255], i, exitbyte;
    int sum = 0;

    cin >> fileName;
    ifstream fin;
    fin.open(fileName, std::ifstream::binary); // Открываем файл
    ofstream fout;
    fileExpPosition = fileName.find(".") + 1;
    fileExt = string(fileName, fileExpPosition);
    
    fout.open(fileExt + "07.tab", ios_base::out | ios_base::trunc);

    if (!fin.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
    else
    {
        i = 0;
        while (fin.read((char*)&byte, sizeof(unsigned char))) {
            sum += sizeof byte;
            exitbyte = (int)byte;
            //cout << exitbyte << endl;

            mymap[exitbyte]++;

            //fin >> buff; // считали слово из файла
            //fout << buff << endl; // напечатали

        }
        for (it = mymap.begin(); it != mymap.end(); ++it) {
            exitbytes[it->first] = it->second / sum;
            cout << it->first << " = " << endl;
            printf("Переменная exitbytes[it->first] = %.3f", it->second / sum);
            cout << endl;
        }
        //fin.getline(buff, 50); // считали строку из файла
        //fout << buff << endl; // напечатали эту строку

        fin.close(); // закрываем файл
        fout.close();
    }
    system("pause");
    return 0;
}