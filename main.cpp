#include <iostream>
#include<cstdlib>
#include <time.h>

using namespace std;
int i,x,win,z;
string t[10];
long long int a;
void start(){

    cout<<"[";
        for(x=0;x<9;x++){
        if(x%3==0 && x!=0){
            cout<<"]"<<endl;
            cout<<"[";
        }
        if(x%3!=0){
            cout<<"|";
        }
        cout<<t[x];
        }
        cout<<"]"<<endl;
};
int checkWin(){
    if(t[1]=="X" && t[2]=="X" && t[0]=="X" || t[1]=="O" && t[2]=="O" && t[0]=="O"){
        return 2;
    }
    else if(t[4]=="X" && t[5]=="X" && t[3]=="X" || t[4]=="O" && t[5]=="O" && t[3]=="O"){
        return 2;
    }
    else if(t[7]=="X" && t[8]=="X" && t[6]=="X" || t[7]=="O" && t[8]=="O" && t[6]=="O"){
       return 2;
    }
    else if(t[0]=="X" && t[4]=="X" && t[8]=="X" || t[0]=="O" && t[4]=="O" && t[8]=="O"){
        return 2;
    }
    else if(t[2]=="X" && t[4]=="X" && t[6]=="X" || t[2]=="O" && t[4]=="O" && t[6]=="O"){
        return 2;
    }
    else if(t[0]=="X" && t[3]=="X" && t[6]=="X" || t[0]=="O" && t[3]=="O" && t[6]=="O"){
          return 2;

    }
    else if(t[1]=="X" && t[4]=="X" && t[7]=="X" || t[1]=="O" && t[4]=="O" && t[7]=="O"){
            return 2;
    }
     else if(t[2]=="X" && t[5]=="X" && t[8]=="X" || t[2]=="O" && t[5]=="O" && t[8]=="O"){
            return 2;
    }
    else if(t[0]=="X" && t[3]=="X" && t[6]=="X" || t[0]=="O" && t[3]=="O" && t[6]=="O"){
            return 2;
    }
    else if(t[1]=="X" && t[4]=="X" && t[7]=="X" || t[1]=="O" && t[4]=="O" && t[7]=="O"){
            return 2;
    }
    else{
         return 0;
    }

}
int losowanie(){
		return rand() % 10;
};

void click(){
    cout<<"podaj numer kratki=";
     cin>>a;
     if(a>9){
        cout<<"podaj liczbe w zakresie 1-9"<<endl;
        click();
    }else if(t[a-1]=="O" || t[a-1]=="X"){
        cout<<"nie mozna nadpisac kratki sprobuj ponownie"<<endl;
        click();
    }
    else{
        t[a-1]="O";
        start();
        win=checkWin();
    }
}
void enemy(){
    z=losowanie()-1;
    if(t[z+1]=="X" || t[z+1]=="O"){
        enemy();
    }else{
    t[z+1]="X";
    start();
    }
}
int main()
{
    srand (time(NULL));
    for(int x=0;x<9;x++) t[x]=" ";
    start();
    do{
        click();
        cout<<"----------------"<<'\a'<<endl;
        enemy();
    }while(win<1);
      cout<<"wygrana!"<<endl;
    return 0;
}
