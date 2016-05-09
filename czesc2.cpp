#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

int getkey(){
    string pressed;
    do{
        cin>>pressed;
    }while(pressed.compare("0")!=0&&pressed.compare("1")!=0&&pressed.compare("2")!=0);
    if(pressed.compare("0")==0) return 0;
    if(pressed.compare("1")==0) return 1;
    if(pressed.compare("2")==0) return 2;
}

void intro(){
    cout<<"Michal Zakrzewski's Projekt na Logike"<<endl;
    cout<<"Smok Wawelogiczny"<<endl<<endl;
    cout<<"Swiatu zagraza Logiczny Smok!"<<endl;
    cout<<"Stawic mu czola moga jedynie Rycerze Logiki!"<<endl<<endl;
    cout<<"Kazdy rycerz moze miec na wyposazeniu miecz i tarcze"<<endl;
    cout<<"Jednak bedzie mogl zadac smoku obrazenia tylko wtedy,"<<endl<<"gdy dobrze podasz wartosc logiczna jego wypowiedzi"<<endl<<endl;
    cout<<"Mam = 1, Nie mam = 0, Nie wiem = X"<<endl<<endl;
    cout<<"Podawaj swoje odpowiedzi przez klawisze: "<<endl<<"0 (nieprawda)"<<endl<<"1 (prawda)"<<endl<<"2 (X)"<<endl<<"i potwierdz je klawiszem ENTER"<<endl<<endl;
    cout<<"PS Negacja neguje wartosc calego zdania"<<endl<<endl;
    cout<<"Powodzenia!"<<endl;

}

void desc(int flag, int val){
    if(flag==0&&val==0) cout<<" Nie mam miecza ";
    if(flag==1&&val==0) cout<<" Nie mam tarczy "<<endl;
    if(flag==0&&val==1) cout<<" Mam miecz ";
    if(flag==1&&val==1) cout<<" Mam tarcze "<<endl;
    if(flag==0&&val==2) cout<<" Nie wiem czy mam miecz ";
    if(flag==1&&val==2) cout<<" Nie wiem czy mam tarcze "<<endl;
}

int and_res(int and_table[3][9], int arg1, int arg2){
    for(int i=0; i<9; i++){
        if(and_table[0][i]==arg1&&and_table[1][i]==arg2) return and_table[2][i];
    }
}

int or_res(int or_table[3][9], int arg1, int arg2){
    for(int i=0; i<9; i++){
        if(or_table[0][i]==arg1&&or_table[1][i]==arg2) return or_table[2][i];
    }
}

int impl_res(int impl_table[3][9], int arg1, int arg2){
    for(int i=0; i<9; i++){
        if(impl_table[0][i]==arg1&&impl_table[1][i]==arg2) return impl_table[2][i];
    }
}

int not_res(int not_table[2][3], int or_table[3][9], int and_table[3][9], int impl_table[3][9], int flag, int arg1, int arg2){
    int result;
    if(flag==0) result=or_res(or_table, arg1, arg2);      //flag=0 - negujemy OR
    if(flag==1) result=and_res(and_table, arg1, arg2);    //flag=1 - negujemy AND
    if(flag==2) result=impl_res(impl_table, arg1, arg2);  //flag=2 - negujemy IMPL
    for(int i=0; i<3; i++){
        if(not_table[0][i]==result) return not_table[1][i];
    }
}


int level5(int not_table[2][3], int or_table[3][9], int and_table[3][9], int impl_table[3][9]){
    cout<<endl<<"Poziom piaty: musisz zdobyc 100% poprawnych odpowiedzi"<<endl;
    int score=0;
    int res;

    int arg1=0;
    int arg2=2;
    desc(0, arg1);
    cout<<" i ";
    desc(1, arg2);
    res=getkey();
    if(res==and_res(and_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;



    arg1=0;
    arg2=0;
    cout<<" Jesli ";
    desc(0, arg1);
    cout<<" to ";
    desc(1, arg2);
    res=getkey();
    if(res==impl_res(impl_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=0;
    arg2=1;
    cout<<" Nieprawda, ze ";
    desc(0, arg1);
    cout<<" i ";
    desc(1, arg2);
    res=getkey();
    if(res==not_res(not_table, or_table, and_table, impl_table, 1, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=2;
    arg2=0;
    desc(0, arg1);
    cout<<" lub ";
    desc(1, arg2);
    res=getkey();
    if(res==or_res(or_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :("<<endl;


    arg1=2;
    arg2=1;
    cout<<" Nieprawda, ze ";
    desc(0, arg1);
    cout<<" lub ";
    desc(1, arg2);
    res=getkey();
    if(res==not_res(not_table, or_table, and_table, impl_table, 0, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;

        if(score>=5){
        cout<<"Twoj wynik na 5. poziomie to "<<score<<"/5 pkt"<<endl;
        cout<<"BRAWO! Z TWOJA POMOCA RYCERZE POKONALI SMOKA!"<<endl<<endl;
        return score;
    }else{
        cout<<"Niestety pokonanie Smoka przeroslo Twoje mozliwosci :("<<endl;
        cout<<"Twoj wynik na 5. poziomie to "<<score<<"/5 pkt"<<endl;
        cout<<"KONIEC GRY";
        return score;
    }

}

int level4(int not_table[2][3], int or_table[3][9], int and_table[3][9], int impl_table[3][9]){
    cout<<endl<<"Poziom czwarty: musisz zdobyc 80% poprawnych odpowiedzi"<<endl;
    int score=0;
    int res;

    int arg1=1;
    int arg2=2;
    cout<<" Jesli ";
    desc(0, arg1);
    cout<<" to ";
    desc(1, arg2);
    res=getkey();
    if(res==impl_res(impl_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;



    arg1=2;
    arg2=1;
    desc(0, arg1);
    cout<<" lub ";
    desc(1, arg2);
    res=getkey();
    if(res==or_res(or_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :("<<endl;


    arg1=2;
    arg2=2;
    cout<<" Nieprawda, ze jesli ";
    desc(0, arg1);
    cout<<" to ";
    desc(1, arg2);
    res=getkey();
    if(res==not_res(not_table, or_table, and_table, impl_table, 2, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=1;
    arg2=0;
    desc(0, arg1);
    cout<<" i ";
    desc(1, arg2);
    res=getkey();
    if(res==and_res(and_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=1;
    arg2=1;
    cout<<" Nieprawda, ze ";
    desc(0, arg1);
    cout<<" i ";
    desc(1, arg2);
    res=getkey();
    if(res==not_res(not_table, or_table, and_table, impl_table, 1, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;

        if(score>=4){
        cout<<"Twoj wynik na 4. poziomie to "<<score<<"/5 pkt"<<endl;
        cout<<"Przechodzisz na piąty poziom!"<<endl<<endl;
        return score+level5(not_table, or_table, and_table, impl_table);
    }else{
        cout<<"Niestety pokonanie Smoka przeroslo Twoje mozliwosci :("<<endl;
        cout<<"Twoj wynik na 4. poziomie to "<<score<<"/5 pkt"<<endl;
        cout<<"KONIEC GRY";
        return score;
    }

}

int level3(int not_table[2][3], int or_table[3][9], int and_table[3][9], int impl_table[3][9]){
    cout<<endl<<"Poziom trzeci: musisz zdobyc 60% poprawnych odpowiedzi"<<endl;
    int score=0;
    int res;

    int arg1=2;
    int arg2=2;
    cout<<" Nieprawda, ze jesli";
    desc(0, arg1);
    cout<<" to ";
    desc(1, arg2);
    res=getkey();
    if(res==not_res(not_table, or_table, and_table, impl_table, 2, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=1;
    arg2=2;
    cout<<" Nieprawda, ze ";
    desc(0, arg1);
    cout<<" lub ";
    desc(1, arg2);
    res=getkey();
    if(res==not_res(not_table, or_table, and_table, impl_table, 0, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=0;
    arg2=1;
    desc(0, arg1);
    cout<<" i ";
    desc(1, arg2);
    res=getkey();
    if(res==and_res(and_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=0;
    arg2=0;
    cout<<" Nieprawda, ze ";
    desc(0, arg1);
    cout<<" i ";
    desc(1, arg2);
    res=getkey();
    if(res==not_res(not_table, or_table, and_table, impl_table, 1, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=2;
    arg2=1;
    cout<<" Jesli ";
    desc(0, arg1);
    cout<<" to ";
    desc(1, arg2);
    res=getkey();
    if(res==impl_res(impl_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    if(score>=3){
        cout<<"Twoj wynik na 3. poziomie to "<<score<<"/5 pkt"<<endl;
        cout<<"Przechodzisz na czwarty poziom!"<<endl<<endl;
        return score+level4(not_table, or_table, and_table, impl_table);
    }else{
        cout<<"Niestety pokonanie Smoka przeroslo Twoje mozliwosci :("<<endl;
        cout<<"Twoj wynik na 3. poziomie to "<<score<<"/5 pkt"<<endl;
        cout<<"KONIEC GRY";
        return score;
    }
}

int level2(int not_table[2][3], int or_table[3][9], int and_table[3][9], int impl_table[3][9]){
    cout<<endl<<"Poziom drugi: musisz zdobyc 40% poprawnych odpowiedzi"<<endl;
    int score=0;
    int res;

    int arg1=2;
    int arg2=1;
    desc(0, arg1);
    cout<<" lub ";
    desc(1, arg2);
    res=getkey();
    if(res==or_res(or_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=1;
    arg2=0;
    cout<<" Jesli ";
    desc(0, arg1);
    cout<<" to ";
    desc(1, arg2);
    res=getkey();
    if(res==impl_res(impl_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=2;
    arg2=0;
    cout<<" Nieprawda, ze ";
    desc(0, arg1);
    cout<<" lub ";
    desc(1, arg2);
    res=getkey();
    if(res==not_res(not_table, or_table, and_table, impl_table, 0, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=0;
    arg2=2;
    cout<<" Jesli ";
    desc(0, arg1);
    cout<<" to ";
    desc(1, arg2);
    res=getkey();
    if(res==impl_res(impl_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=0;
    arg2=2;
    cout<<" Nieprawda, ze ";
    desc(0, arg1);
    cout<<" i ";
    desc(1, arg2);
    res=getkey();
    if(res==not_res(not_table, or_table, and_table, impl_table, 1, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;

        if(score>=2){
        cout<<"Twoj wynik na 2. poziomie to "<<score<<"/5 pkt"<<endl;
        cout<<"Przechodzisz na trzeci poziom!"<<endl<<endl;
        return score+level3(not_table, or_table, and_table, impl_table);
    }else{
        cout<<"Niestety pokonanie Smoka przeroslo Twoje mozliwosci :("<<endl;
        cout<<"Twoj wynik na 2. poziomie to "<<score<<"/5 pkt"<<endl;
        cout<<"KONIEC GRY";
        return score;
    }

}

int level1(int not_table[2][3], int or_table[3][9], int and_table[3][9], int impl_table[3][9]){
    cout<<endl<<"Poziom pierwszy: musisz zdobyc 20% poprawnych odpowiedzi"<<endl;
    int score=0;
    int res;


    int arg1=1;
    int arg2=0;
    desc(0, arg1);
    cout<<" i ";
    desc(1, arg2);
    res=getkey();
    if(res==and_res(and_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=2;
    arg2=0;
    cout<<" Jesli ";
    desc(0, arg1);
    cout<<" to ";
    desc(1, arg2);
    res=getkey();
    if(res==impl_res(impl_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;


    arg1=0;
    arg2=1;
    desc(0, arg1);
    cout<<" lub ";
    desc(1, arg2);
    res=getkey();
    if(res==or_res(or_table, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :("<<endl;

    arg1=0;
    arg2=2;
    cout<<" Nieprawda, ze ";
    desc(0, arg1);
    cout<<" lub ";
    desc(1, arg2);
    res=getkey();
    if(res==not_res(not_table, or_table, and_table, impl_table, 0, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;

    arg1=1;
    arg2=1;
    cout<<" Nieprawda, ze ";
    desc(0, arg1);
    cout<<" i ";
    desc(1, arg2);
    res=getkey();
    if(res==not_res(not_table, or_table, and_table, impl_table, 1, arg1, arg2)){
        cout<<"Dobrze!"<<endl;
        score++;
    }else cout<<"Zla odpowiedz :/"<<endl;

    if(score>=1){
        cout<<"Twoj wynik na 1. poziomie to "<<score<<"/5 pkt"<<endl;
        cout<<"Przechodzisz na drugi poziom!"<<endl<<endl;
        return score+level2(not_table, or_table, and_table, impl_table);
    }else{
        cout<<"Niestety pokonanie Smoka przeroslo Twoje mozliwosci :("<<endl;
        cout<<"Twoj wynik na 1. poziomie to "<<score<<"/5 pkt"<<endl;
        cout<<"KONIEC GRY";
        return score;
    }
}

void fill_not(int not_table[2][3], string not_file){
	string in;
	char tmp=' ';
	int pointer=0;
	int i=0;
	int j=0;
	fstream infile;
	infile.open(not_file.c_str());
	while(getline(infile, in)){
            pointer=0;
            i=0;
            while(tmp!='\n'){
                tmp=in[pointer];
                if(tmp==0) {
                    break;
                }
                while(tmp==' '){
                        pointer++;
                        tmp=in[pointer];
                }
                if(tmp=='0')not_table[i][j]=0;
                else if(tmp=='1')not_table[i][j]=1;
                else not_table[i][j]=2;
                pointer++;
                i++;
            }
            j++;
	}
	infile.close();
}

void fill_or(int or_table[3][9], string or_file){
    string in;
	char tmp=' ';
	int pointer=0;
	int i=0;
	int j=0;
	fstream infile;
    infile.open(or_file.c_str());
    while(getline(infile, in)){
        pointer=0;
        i=0;
        while(tmp!='\n'){
            tmp=in[pointer];
            if(tmp==0) {
                break;
            }
            while(tmp==' '){
                    pointer++;
                    tmp=in[pointer];
            }
            if(tmp=='0')or_table[i][j]=0;
            else if(tmp=='1')or_table[i][j]=1;
            else or_table[i][j]=2;
            pointer++;
            i++;
        }
        j++;
    }
	infile.close();
}

void fill_and(int and_table[3][9], string and_file){
    string in;
	char tmp=' ';
	int pointer=0;
	int i=0;
	int j=0;
	fstream infile;
    infile.open(and_file.c_str());
    while(getline(infile, in)){
        pointer=0;
        i=0;
        while(tmp!='\n'){
            tmp=in[pointer];
            if(tmp==0) {
                break;
            }
            while(tmp==' '){
                    pointer++;
                    tmp=in[pointer];
            }
            if(tmp=='0')and_table[i][j]=0;
            else if(tmp=='1')and_table[i][j]=1;
            else and_table[i][j]=2;
            pointer++;
            i++;
        }
        j++;
    }
	infile.close();
}

void fill_impl(int impl_table[3][9], string impl_file){
    string in;
	char tmp=' ';
	int pointer=0;
	int i=0;
	int j=0;
	fstream infile;
	infile.open(impl_file.c_str());
    while(getline(infile, in)){
        pointer=0;
        i=0;
        while(tmp!='\n'){
            tmp=in[pointer];
            if(tmp==0) {
                break;
            }
            while(tmp==' '){
                    pointer++;
                    tmp=in[pointer];
            }
            if(tmp=='0')impl_table[i][j]=0;
            else if(tmp=='1')impl_table[i][j]=1;
            else impl_table[i][j]=2;
            pointer++;
            i++;
        }
        j++;
    }
	infile.close();
}

int main(int argc, char *argv[])
{
    int not_table[2][3];
	int or_table[3][9];
	int and_table[3][9];
	int impl_table[3][9];
	if(argc>9){
        cout<<"Za duzo argumentow";
        cout<<"Przykladowe wywolanie: "<<endl;
        cout<<"zadanie2 --not not.txt --and and.txt --or or.txt --impl impl.txt"<<endl;
        return 0;
	}
	if(argc<9){
        cout<<"Za malo argumentow"<<endl;
        cout<<"Przykladowe wywolanie: "<<endl;
        cout<<"zadanie2 --not not.txt --and and.txt --or or.txt --impl impl.txt"<<endl;
        return 0;
	}
	string not_file="";
	string or_file;
	string impl_file;
	string and_file;
	for(int i=1; i<9; i+=2){
		if(static_cast<string>(argv[i])=="--not") not_file=argv[i+1];
		if(static_cast<string>(argv[i])=="--or") or_file=argv[i+1];
		if(static_cast<string>(argv[i])=="--impl") impl_file=argv[i+1];
		if(static_cast<string>(argv[i])=="--and") and_file=argv[i+1];
	}
	/*
	if(not_file.length()==0) cout<<"Nie podano pliku NOT"<<endl;
	if(or_file.length()==0) cout<<"Nie podano pliku OR"<<endl;
	if(impl_file.length()==0) cout<<"Nie podano pliku IMPL"<<endl;
	if(and_file.length()==0) cout<<"Nie podano pliku AND"<<endl;
	*/
	fill_not(not_table, not_file);
	fill_or(or_table, or_file);
	fill_and(and_table, and_file);
	fill_impl(impl_table, impl_file);

//-------------------------------------------------------------------------------------------------

    intro();
    int final_res=level1(not_table, or_table, and_table, impl_table);
    cout<<endl<<endl<<"Twoj wynik koncowy to "<<final_res<<"/25 punktow";
    return 0;
}
