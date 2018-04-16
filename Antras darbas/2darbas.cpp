#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
//---
void iv(const char file[], int &n, int &k, string M[]);
void is(int &n, int &k, string M[]);
//---
int main()
{
    int n=0, k=0;
    string M[99];
    const char fiv[]="kontaktai.txt";
    iv(fiv, n, k, M);
    is(n, k, M);
    system("pause");
    return 0;
}
void iv(const char file[], int &n, int &k, string M[])
{
    ifstream fd(file);
    while(!fd.eof())
    {
        getline(fd, M[n], '\n');
        n++;
    }
    fd.clear();
    fd.seekg (0, ios::beg);
    while(!fd.eof())
    {
        fd>>M[k];
        char ch=*M[k].rbegin();
        if(ch==',') M[k]=M[k].substr(0, M[k].size()-1);
        k++;
    }
    k=k/n;
    fd.close();
}
void is(int &n, int &k, string M[])
{
    ofstream fr("kontaktai.js");
    fr<<"["<<endl;
    int s=0;
    while((n-1)!=0)
    {
        fr<<"\t {"<<endl;
        for(int i=0; i<k; i++)
        {
            fr<<"\t"<<"\t"<<"\""<<M[i]<<"\": ";
            fr<<"\""<<M[i+k+s]<<"\","<<endl;
        }
        fr<<"\t ),"<<endl;
        n--;
        s=s+k;
    }
    fr<<"]"<<endl;
    fr.close();
}
