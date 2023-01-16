#include <iostream>
#include <conio.h>//para ver que tecla ha sido presionada//kbhit()
#include <stdlib.h>
#include <time.h>
#include <thread>//necesario
#include <chrono>//necesario
#include <stdio.h>
#include <sstream>
using namespace std;
using namespace std::this_thread;//sleep for//hacer que  el programa duerma por una cantidad de tiempo
using namespace std::chrono;

string tiempoTranscurrido (int x, int y, int z);

int main (){
    int s=0;
    int m=0;
    int h=0;
    string c;

    cout<<"Pulse una tecla para empezar a cronometrar";
    getch();
    system("cls");
    
    while(!kbhit()){//mientras no se pulse ninguna tecla

        cout<<"\nPulse una tecla para dejar de cronometrar: ";
        ostringstream hour;
        ostringstream min;
        ostringstream sec;
        
        string horas; 
        string minutos;
        string segundos;

        hour<<h;
        min<<m;
        sec<<s;

        if(hour.str().size()==1){
            horas="0"+hour.str();
        }
        else{
            horas=hour.str();
        }

        if(min.str().size()==1){
            minutos ="0"+min.str();
        }
        else{
            minutos=min.str();
        }

        if(sec.str().size()==1){
            segundos ="0"+sec.str();
        }
        else{
            segundos=sec.str();
        }

        cout<<horas<<":"<<minutos<<":"<<segundos;
        s++;
        if (s==60){
            s=0;
            m++;
            if(m==60) {
                m=0;
                h++;
            }
        }
        sleep_for (seconds(1));//sleep for (min, seconds,hours(tiempo))
        system ("cls");
        c=tiempoTranscurrido (h, m, s);
    }
    
    cout<<"Tiempo transcurrido: "<<c;
}

string tiempoTranscurrido (int x, int y, int z){
    string tempo;
    ostringstream t;
    t<<x<<":"<<y<<":"<<z;
    tempo =t.str();
    return tempo;
}