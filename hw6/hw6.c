#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;
int f (int x);
int m ();
bool oracle(int x, int y, int t, int i, int j, int k,
int xP, int yP, int tP, int iP, int jP, int kP);
bool R(int x, int y, int t, int i, int j, int k,
int xP, int yP, int tP, int iP, int jP, int kP);
bool domR(int x, int y, int t, int i, int j, int k);
int Fib (int x);
int x,y,t,i,j,k;
int Px,Py,Pt,Pi,Pj,Pk;
int fb[40];
int main(){
    bool verif = true;
    int count=0; for (int z=1; z<=38;z++) {fb[z]=Fib(z);}
    for (int xi=1; xi<=10; xi++){
        for (int yi=5; yi<=100; yi=yi+3){
            for (int ti=1; ti<=10; ti++)
                for (int ii=2; ii<=35; ii++)
                    for (int ji=ii/2; ji<=ii; ji++)
                        for (int ki=5; ki<=10; ki=ki+7){
                            x=xi; 
                            y=yi; 
                            t=ti; 
                            i=ii; 
                            j=ji; 
                            k=ki;
                            m();
                            verif = verif && oracle(xi,yi,ti,ii,ji,ki,x,y,t,i,j,k);
                            count++;
                        }
                    }
        }
    cout << "number of random tests: " << count << endl;
    if (verif) {cout << "all verified" << endl;}
    else {cout << "some unverified" << endl;}
}
int f(int x){x=3*x+3;return x;};
int m(){
    t= i-j;
    if (i>j){
        x= 0; y= f(x);
            while (i!=j){i=i+k; k=k+1; i=i-k; y=f(y);} ;}
    else
        {if (j>i)
            {while (j != i)
                {j=j+k; k=k-1; j=j-k; y=f(y);};}
        else
            {while (t!=i)
                {for(int z=0;z!=y;z=z+1){x=x+1;}
                    y= x-y;  t= t+1;} ;}}
    k=i+j; j=2*k;
}
bool oracle(int x, int y, int t, int i, int j, int k,
            int xP, int yP, int tP, int iP, int jP, int kP)
    {return !domR(x,y,t,i,j,k) || R(x,y,t,i,j,k,xP,yP,tP,iP,jP,kP);}
bool domR(int x,int y,int t,int i,int j,int k)
    { return  y>=0 && i!=j && t>0 && k>=0 ;}
bool R(int x, int y, int t, int i, int j, int k,
        int xP, int yP, int tP, int iP, int jP, int kP)
    {return (i>j && yP == (3^(i-j+2)-3)/2) || (yP == x*Fib(j)+y*Fib(jP-1));}
int Fib(int x)
    {if (x<=2) {return 1;} else {return Fib(x-1)+Fib(x-2);}}