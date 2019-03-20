#include <iostream>
#include<cstdlib>
#include <time.h>  +
using namespace std;
int i,x,win=0,z;
string array[10];
int a;
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
        cout<<array[x];
        }
        cout<<"]"<<endl;
};
int losowanie(){
		return rand() % 10;
};
void click(){
    cout<<"podaj numer kratki="<<endl;
     cin>>a;
    if(array[a-1]=="O" || array[a-1]=="X"){
        cout<<"nie mozna nadpisac kratki sprobuj ponownie";
        click();
    }else{
        array[a-1]="O";
        start();
    }
}
void enemy(){
    z=losowanie()-1;
    if(array[z]=="X" || array[z]=="O"){
        enemy();
    }else{
    array[z]="X";
    start();
    }
}
int checkWin(){
    if(array[1]=="X" && array[2]=="X" && array[0]=="X" || array[1]=="O" && array[2]=="O" && array[0]=="O"){
        return 2;
    }else if(array[4]=="X" && array[5]=="X" && array[3]=="X" || array[4]=="O" && array[5]=="O" && array[3]=="O"){
        return 2;
    }
    else if(array[7]=="X" && array[8]=="X" && array[6]=="X" || array[7]=="O" && array[8]=="O" && array[6]=="O"){
       return 2;
    }else if(array[0]=="X" && array[4]=="X" && array[8]=="X" || array[0]=="O" && array[4]=="O" && array[8]=="O"){
        return 2;
    }
    else if(array[2]=="X" && array[4]=="X" && array[6]=="X" || array[2]=="O" && array[4]=="O" && array[6]=="O"){
        return 2;
    } else if(array[0]=="X" && array[3]=="X" && array[6]=="X" || array[0]=="O" && array[3]=="O" && array[6]=="O"){
          return 2;
    }
    else if(array[1]=="X" && array[4]=="X" && array[7]=="X" || array[1]=="O" && array[4]=="O" && array[7]=="O"){
            return 2;
    }
     else if(array[2]=="X" && array[5]=="X" && array[8]=="X" || array[2]=="O" && array[5]=="O" && array[8]=="O"){
            return 2;
    }
    else{
         return 0;
    }

}//6,15,24
int main()
{
    srand (time(NULL));
    for(int x=0;x<9;x++) array[x]=" ";
    start();
    do{
        click();
        cout<<"---------------"<<'\a'<<endl;
        enemy();
    }while(checkWin()<1);
      cout<<"wygrana!"<<endl;
    return 0;
}
