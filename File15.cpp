#include "pt4.h"
#include <fstream>
using namespace std;

void Solve()
{
    Task("File15");

    char in[250], t[250];
    pt >> in;
    OemToChar(in, t);

    ifstream FileIn(t,ios::binary);

    int mig = 0;
    double Sum = 0;

    while (!FileIn.eof())
    {
        mig += 1;
        double Num;
        FileIn.read((char*)&Num,sizeof(Num));
        if (mig % 2 == 0) Sum += Num;
        
    }
    pt << Sum;
    FileIn.close();
}
