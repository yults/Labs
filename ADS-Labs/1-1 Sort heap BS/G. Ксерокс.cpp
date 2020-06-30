#include <iostream>

using namespace std;
int NOD(int a, int b)
{
    int temp;
    if(a < b)
    {
        swap(a, b);
    }
    temp = b;
    while(temp % a != 0)
        temp += b;
    return temp;
}

int main()
{
    int cop, fp, sp;
    int time = 0;
    cin >> cop >> fp >> sp;
    if (fp > sp)
        swap(fp, sp);
    time = fp;
    cop--;
    int nod = NOD(fp, sp);
    time += (cop / (nod / fp + nod / sp)) * nod;
    cop = cop % (nod / fp + nod / sp);
    int fptemp = 0;
    int sptemp = 0;
    while(cop > 0)
    {
        fptemp++;
        sptemp++;
        time++;
        if(fptemp >= fp)
        {
            cop--;
            fptemp = fptemp % fp;
        }
        if(sptemp>=sp)
        {
            cop--;
            sptemp = sptemp % sp;
        }
    }
    cout << time;
    return 0;
}

