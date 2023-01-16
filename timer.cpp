#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>//necesario
#include <chrono>//necesario
using namespace std;
using namespace std::this_thread;//sleep for//hacer que  el programa duerma por una cantidad de tiempo
using namespace std::chrono;
int main (){
    int s=0;
    int m=0;
    int h=0;

    cout<<"Seleccione las horas, minutos y segundos\n";
    getch();
    system ("cls");
    cout<<"Horas:\n";
    cin>>h;
    system ("cls");
    cout<<"minutos:\n";
    cin>>m;
    system ("cls");
    cout<<"segundos:\n";
    cin>>s;

    while(1==1){
        system ("cls");
        cout<<h<<":"<<m<<":"<<s;
        sleep_for (seconds(1));//sleep for (min, seconds,hours(tiempo))
        s--;

        if (m==0 && s==0){
            if(h==0 && m==0 && s==0){
            break;
            }
            h--;
            m=59;
            s=60;
            
        }   
        if(s==0) {
            m--;
            s=60;
        }
        
        if(h==0 && m==0 && s==0){
            break;
        }
    }
    system("cls");
    cout<<"Se acabo el tiempo ";

}
