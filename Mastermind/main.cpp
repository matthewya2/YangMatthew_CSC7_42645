/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on April 6, 2017, 1:52 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "MM.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int choice=0;
    int choice1,choice2,choice3,choice4;
    srand(time(0));
    cout<<"MASTERMIND!!!"<<endl;
    bool again=false;               //play again?
    MM menu;
    int picks[8];
    int rightNP=0;                  //right number and place
    int rightN=0;                   //right number but not place
    const int MAXTURN=10;           //max turn value
    cout <<"For this MasterMind game, the computer will select 4 numbers 1-8 "<<endl<<
            "and you must guess which numbers they are, and what order those"<<endl<<
            " numbers are in within 10 turns."<<endl;
    
    do{
        for(int i=0;i<=3;i++){
        picks[i]=menu.Rand();
        }
        
        for(int i=0;i<=3;i++){
        cout<<picks[i];
        }
        
        for(int turnC=0;turnC<MAXTURN;turnC++){
    cout << "what numbers do you want to guess?"<<endl;
    cin>>choice;
    choice1=choice%10;
    choice2=choice%100-choice1;
    choice3=choice%1000-(choice1+choice2);
    choice4=choice-(choice1+choice2+choice3);
        
        if(choice1==picks[0]){rightNP++;}
        if(choice2==picks[1]){rightNP++;}
        if(choice3==picks[2]){rightNP++;}
        if(choice4==picks[3]){rightNP++;}
    
    for(int j=0;j<4;j++){
            
        if (choice1==picks[j]){rightN++;}
        if (choice2==picks[j]){rightN++;}
        if (choice3==picks[j]){rightN++;}
        if (choice4==picks[j]){rightN++;}
        }
    cout <<"you have "<<rightNP<<" right numbers in the right place."<<endl;
    cout <<"you have "<<rightN<<" right numbers in the wrong place."<<endl;
    cout <<"you have "<<MAXTURN-turnC<<" turns left"<<endl;
                    
                    
                    
                    
        }   
    }while (again==true);
    return 0;
}

