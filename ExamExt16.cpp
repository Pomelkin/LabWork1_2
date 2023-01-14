#include <iostream>
#include <fstream>
#include <iomanip>
#include "pt4exam.h"
using namespace std;

// Для ввода используйте поток cin
// Для вывода используйте поток cout
// Между полученными результатами надо выводить символ пробела
void Solve()
{
    Task("ExamExt16");
    int n = 0, k;

    cin >> k >> n;

    struct Humans
    {
        int month;
        int year;
        int ID;
        int time;
    } Owners[100] = {};

    struct Years
    {
        int month;
        int time;
    } years[2011] = {};

    for (int i = 2000; i <= 2010; i++)
        years[i].time = 31;

    for (int i = 0; i < n; i++)
    {
        cin >> Owners[i].time >> Owners[i].ID >> Owners[i].year >> Owners[i].month;
        if (Owners[i].ID == k)
        {
            if (years[Owners[i].year].time >= Owners[i].time)
            {
                if (years[Owners[i].year].time == Owners[i].time)
                {
                    if (years[Owners[i].year].month < Owners[i].month) {

                        years[Owners[i].year].month = Owners[i].month;
                    }
                }
                else
                {
                    years[Owners[i].year].time = Owners[i].time;
                    years[Owners[i].year].month = Owners[i].month;
                }
            }
        }
    }
    for (int i = 2000; i <= 2010; i++)
        if (years[i].time != 0 && years[i].time != 31)
            cout << years[i].time << " " << i << " " << years[i].month << endl;
}
