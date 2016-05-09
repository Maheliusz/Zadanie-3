#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
    int *tab=new int[argc-1];
    for(int i=1; i<argc; i++) tab[i-1]=atoi(argv[i]);
    //for(int i=0; i<argc-1; i++) cout<<tab[i]<<endl;
    if(argc>10){
        if(((tab[0]!=tab[1] || tab[2]==tab[3]) && tab[4]<=tab[5]) || (tab[6]>tab[7] || tab[8]!=tab[9]))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }else if(argc>8){
        if((tab[0]!=tab[1] || tab[2]==tab[3]) && (tab[4]<=tab[5] || tab[6]>tab[7]))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }else if(argc>6){
        if(((tab[0]!=tab[1] || tab[2]==tab[3]) && tab[4]<=tab[5]))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    } else cout<<"Za malo argumentow";
    return 0;
}
