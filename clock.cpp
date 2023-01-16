#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>//sleep_for//thread
#include <sstream>//forma avanzada de la libreria string.h//no la uso aca pero completare mas adelante :v
//para que salgan 2 digitos en vez de uno

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

string meses_año(int mes);
string semana(int dia);

//para que se actualice la hora debes definir la semilla//time()//dentro del bucle
//sino como pendejo vas a estar viendo como parpadea y se actualiza la horas
int main (){
    while(true){
        string a,b;
        time_t tiempo;
        tiempo =time(0);
        struct tm *fecha;
        fecha=localtime(&tiempo);
        auto dormir = seconds(1);

        int hora =fecha->tm_hour;
        int minutos = fecha->tm_min;
        int segundos = fecha->tm_sec;
        
        ostringstream h;
        ostringstream m;
        ostringstream s;

        string hour; 
        string min;
        string sec;

        h<<hora;
        m<<minutos;
        s<<segundos;

        if(h.str().size()==1){
            hour="0"+h.str();
        }
        else{
            hour=h.str();
        }

        if(m.str().size()==1){
            min ="0"+m.str();
        }
        else{
            min=m.str();
        }

        if(s.str().size()==1){
            sec ="0"+s.str();
        }
        else{
            sec=s.str();
        }

        int anios = fecha->tm_year+1900;
        int mes = fecha->tm_mon+1;
        int dia = fecha->tm_wday;
        int mesdia = fecha->tm_mday;
        a=meses_año(mes);
        b=semana(dia);
        cout<<"Fecha: "<<b<<" "<<mesdia<<" "<<a<<"\tAño: "<<anios<<endl;
        cout<<hour<<":"<<min<<":"<<sec;
        sleep_for(dormir);
        system("cls");
    }
    return 0;
}

string meses_año(int mes){
    switch (mes){
    case 1:return "Enero"; break;
    case 2:return "Febrero"; break;
    case 3:return "Marzo"; break;
    case 4:return "Abril"; break;
    case 5:return "Mayo"; break;
    case 6:return "Junio"; break;
    case 7:return "Julio"; break;
    case 8:return "Agosto"; break;
    case 9:return "Setiembre"; break;
    case 10:return "Octubre"; break;
    case 11:return "Noviembre"; break;
    case 12:return "Diciembre"; break;
    default: cout<<"error";break;
    }
}

string semana (int dia ){
    switch (dia){
        case 0: return "Domingo"; break;
        case 1: return "Lunes"; break;
        case 2: return "Martes"; break;
        case 3: return "Miercoles"; break;
        case 4: return "Jueves"; break;
        case 5: return "Viernes"; break;
        case 6: return "Sabado"; break;
        default:cout<<"error"; break;
    }
}
