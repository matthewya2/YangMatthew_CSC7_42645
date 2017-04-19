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
    bool again=true;               //play again?
    MM menu;
    int picks[4];
    int rightNP=0;                  //right number and place
    int rightN=0;                   //right number but not place
    const int MAXTURN=15;           //max turn value
    char buffer;
    
    
    
    
    cout <<"For this MasterMind game, the computer will select 4 unique numbers 0-9 "<<endl<<
            "and you must guess which numbers they are, and what order those"<<endl<<
            "numbers are in within 15 turns."<<endl;
    
    do{      
        for(int i=0;i<=3;i++){          //makes random code for user to break
            picks[i]=menu.Rand();
        }
        for(int turnC=1;turnC<=MAXTURN;turnC++){
            
        
        for(int i=0;i<=3;i++){
        cout<<picks[i];
        }
        cout<<endl;
        
    cout << "what numbers do you want to guess?"<<endl;
    cin>>choice;
    
    while (choice>9999 ){
        cout << "please input 4 numbers only"<<endl;
        cin>>choice;
    } 
    
//    for (int i=0;i<4;i++){
//        
//    }
    
    choice4=choice%10;
    choice3=((choice%100-choice4))/10;
    choice2=(choice%1000-(choice4+choice3))/100;
    choice1=(choice-(choice4+choice3+choice2))/1000;
    cout <<choice1<<" "<<choice2<<" "<<choice3<<" "<<choice4<<endl;
      
    
    
    
    if(choice1==picks[0]){rightNP++;}
    if(choice2==picks[1]){rightNP++;}
    if(choice3==picks[2]){rightNP++;}
    if(choice4==picks[3]){rightNP++;}
    
    for(int j=0;j<4;j++){
            
        if (choice1==picks[j]){rightN++;continue;}
        if (choice2==picks[j]){rightN++;continue;}
        if (choice3==picks[j]){rightN++;continue;}
        if (choice4==picks[j]){rightN++;continue;}
        }
    cout <<"you have "<<rightNP<<" right numbers in the right place."<<endl;
    cout <<"you have "<<rightN<<" right numbers in the wrong place."<<endl;
    if (rightNP<4){
        cout <<"you have "<<MAXTURN-turnC<<" turns left"<<endl;
    }   
         
    if (rightNP==4){                    //asks if you would like to play again
        cout << "You have won!"<<endl<<
                "turns it took to achieve victory:"<<turnC<<endl<<
                "Play Again? (y/n)"<<endl;
        
        cin >>buffer;
        if (buffer=='y'){
            turnC=MAXTURN;
        }
        if (buffer=='n'){
            again=false;
            turnC=MAXTURN;
        }
        else{
            turnC=MAXTURN;
        }
    }
    rightNP=0;
    rightN=0;
        }   
    }while (again==true);
    return 0;
}

