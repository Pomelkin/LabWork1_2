#include <iostream>
#include <fstream>
#include <iomanip>
#include "pt4exam.h"
using namespace std;

// Для ввода используйте поток cin
// Для вывода используйте поток cout
void Solve()
{
    Task("ExamExt4");

    int n = 0;

    cin >> n;

    cin.ignore();

    struct Human
    {
        int month;
        int year;
        int ID;
        int time;
    } Owner[100] = {};

    int Max = 0, MaxI=0;
    for (int i = 0; i < n; i++)
    {
        cin >> Owner[i].month >> Owner[i].year >> Owner[i].ID >> Owner[i].time;
        if (Max <= Owner[i].time)
        {
            Max = Owner[i].time;
            MaxI = i;
        }
    }

    int MaxDate = MaxI;
    for (int i = 0; i < n; i++)
    {
        if (Max == Owner[i].time)
        {
            if ((Owner[MaxDate].month + Owner[MaxDate].year) <= (Owner[i].month + Owner[i].year)) {
        
                if ((Owner[MaxDate].month + Owner[MaxDate].year) == (Owner[i].month + Owner[i].year))
                {
                    if (Owner[MaxDate].year < Owner[i].year)
                        MaxDate = i;
                }

                else
                {
                    MaxDate = i;
                }
            }
        }
    }
    cout << Owner[MaxDate].time << endl << Owner[MaxDate].year << endl << Owner[MaxDate].month << endl;
}
