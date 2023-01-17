#include "pt4.h"
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

void Solve()
{
    Task("File34");
    char in[250], t[250];
    pt >> in;
    OemToChar(in, t);

    string FileOfNum;

    ifstream FileIn(t, ios::binary | ios::in );
    FileIn.seekg(0);
    int Mass[100] = {}, i = 0;
    while (!FileIn.eof())
    {
        int num = 0;
        FileIn.read((char*)&num, sizeof(num));
        Mass[i] = num;
        i++;
    }

    int NewI = 0;
    int NewMass[100] = {};

    for (int j = 0; j <= i; j++) if (Mass[j] >= 0) { NewMass[NewI] = Mass[j]; NewI++; }

    FileIn.close();

    remove(t);

    ofstream FileOut(t, ios::out | ios::binary);
    
    FileOut.seekp(0);
    for (int n = 0; n < NewI-2; n++)
    {
        FileOut.write((char*)&NewMass[n], sizeof(NewMass[n]));
    }

    FileIn.close();
}
