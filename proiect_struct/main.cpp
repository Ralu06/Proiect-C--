#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<conio.h>
#include <cstring>
#include <iomanip>
#include <windows.h>

using namespace std;

struct utilizator
{
    char nume[20]="",prenume[20]="",user[30]="",parola[20]="";
    int admin;
    struct cursuri
    {
        char numeinfo[31]="",numemate[31]="",numefiz[31]="";
        int info=-1,mate=-1,fizica=-1;

    }curs;
}useri[100],util_curent;
int con_ca_admin=0;
int nr_util=0;

struct cusurile
{
    char nume[31];
    struct
    {
         char nume[31]="";
    }infor,matem,fizic;
}curs1;

void centerText(const string& text, int width) {
    int padding = (width - text.length()) / 2;
    cout << string(padding, ' ') << text;
}


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void incarca_utiliz()
{
    ifstream incarc("incarcare_util");
    int i=0;
    while(incarc>>useri[i].nume>>useri[i].prenume>>useri[i].user>>useri[i].parola)
    {
        i++;
        nr_util++;
    }
    incarc.close();

}
int util_fiz=0,util_mate=0,util_info=0;
void incarca_curs()
{
    ifstream fiz("fizica");
    ifstream info("informatica");
    ifstream mate("matematica");

    char nume[30]="";
    int i=0,ore=0, j;
    j=0;

    while(fiz>>nume>>ore)
    {
       for(i=0;i<nr_util;i++)
        {
            if(strcmp(nume,useri[i].nume)==0)
            {
                useri[i].curs.fizica=ore;
                strcpy(useri[j].curs.numefiz,useri[i].nume);
                j++;
            }
        }
    }
    util_fiz=j;
    j=0;

    while(info>>nume>>ore)
    {
       for(i=0;i<nr_util;i++)
        {
            if(strcmp(nume,useri[i].nume)==0)
            {

                useri[j].curs.info=ore;
                strcpy(useri[j].curs.numeinfo,useri[i].nume);
                j++;
            }
        }

    }
    util_info=j;
    j=0;

     while(mate>>nume>>ore)
    {
        for(i=0;i<nr_util;i++)
        {
            if(strcmp(nume,useri[i].nume)==0)
            {
                useri[j].curs.mate=ore;
                strcpy(useri[j].curs.numemate,useri[i].nume);
                j++;
            }
        }
    }
    util_mate=j;

    fiz.close();
    mate.close();
    info.close();
}


void print_util(utilizator ut)
{
    cout<<endl;
    cout<<ut.nume<<" "<<ut.prenume;
    if(ut.admin==1)
        cout<<"Administrator";
}
void scriefiz()
{
     ofstream scrie_fiz("fizica");
     for(int i=0;i<util_fiz;i++)
     {
         scrie_fiz<<useri[i].curs.numefiz<<' '<<useri[i].curs.fizica<<endl;
     }
     scrie_fiz.close();

}
void scrieinfo()
{
    ofstream scrie_info("informatica");
    for(int i=0;i<util_info;i++)
     {
         scrie_info<<useri[i].curs.numeinfo<<' '<<useri[i].curs.info<<endl;
     }
     scrie_info.close();

}
void scriemate()
{
    ofstream scrie_mate("matematica");

    for(int i=0;i<util_mate;i++)
    {
         scrie_mate<<useri[i].curs.numemate<<' '<<useri[i].curs.mate<<endl;
    }
    scrie_mate.close();
}
void afisareinfo()
{   setColor(5);
    system("CLS");
    int i,x=0,n,tasta=1,tast=9,exit_info=0,tasta_curs=0;
    cout<<util_curent.nume<<' '<<util_curent.prenume<<' ';
    if(util_curent.curs.info!=-1)
    {
         while(tasta!=0)
        {
            if(util_curent.curs.info<20)
            {
                x=20-util_curent.curs.info;
                cout<<x<<" "<<"ore ramase pana la luarea diplomei"<<endl;
                cout<<"Urmatoare sedinta este pe:"<<' ';
                cout<<28<<' '<<02<<endl;
                cout<<endl;
            }
            else
            {
                cout<<util_curent.curs.info<<' '<<"elevul isi poate ridica diploma"<<endl;
            }
            cout<<"Apasati 0 pentru a va intoarce";
            cin>>tasta;
        }
    }
    else
    {
        system("CLS");
        tast=9;
        while(tast!=0)
        {
            cout<<endl<<"Elevul nu este inscris la curs!"<<endl;
            cout<<endl;
            cout<<"Apasati 2 daca doriti sa va inscrieti"<<endl;
            cout<<"Apasati 0 ca sa iesiti"<<endl;
            cin>>tast;
            if(tast==2)
            {
                system("CLS");
                util_info++;
                useri[util_info-1].curs.info=0;
                strcpy(useri[util_info-1].curs.numeinfo,util_curent.nume);
                util_curent.curs.info=0;
                if(exit_info==1)
                {
                    system("CLS");
                    cout<<"DEJA INSCRIS"<<endl;
                }
                if (util_curent.curs.info != -1 && useri[util_info-1].curs.numeinfo !=  "" && exit_info==0)
                {
                    scrieinfo();
                    exit_info=1;
                    cout<<"Inscris cu succes!"<<endl;
                    cout<<"Apasati 0 pentru a iesi sau 4 pentru a vedea urmatoarea sedinta "<<endl;
                    cin>>tasta_curs;
                    if(tasta_curs==4)
                        afisareinfo();
                    if(tasta_curs==0)
                        tast=0;
                }

            }
        }
    }

}
void afisarefizica()
{   setColor(5);
    system("CLS");
    int i,x=0,n,tasta=1,exit_fiz=0,tast;
    cout<<util_curent.nume<<' '<<util_curent.prenume<<' ';
    if(util_curent.curs.fizica!=-1)
    {
         while(tasta!=0)
        {
            if(util_curent.curs.fizica<20)
            {
                x=20-util_curent.curs.fizica;
                cout<<x<<" "<<"ore ramase pana la luarea diplomei"<<endl;
                cout<<"Urmatoare sedinta este pe:"<<' ';
                cout<<28<<' '<<02<<endl;
                cout<<endl;
            }
            else
            {
                cout<<util_curent.curs.fizica<<' '<<"elevul isi poate ridica diploma"<<endl;
            }
            cout<<"Apasati 0 pentru a va intoarce";
            cin>>tasta;
        }
    }
    else
    {
         system("CLS");
         tast=9;
        while(tast!=0)
        {
            cout<<endl<<"Elevul nu este inscris la curs!"<<endl;
            cout<<endl;
            cout<<"Apasati 2 daca doriti sa va inscrieti"<<endl;
            cout<<"Apasati 0 ca sa iesiti"<<endl;
            cin>>tast;
            if(tast==2)
            {
                system("CLS");
                util_fiz++;
                useri[util_fiz-1].curs.fizica=0;
                strcpy(useri[util_fiz-1].curs.numefiz,util_curent.nume);
                util_curent.curs.fizica=0;
                if(exit_fiz==1)
                {
                    system("CLS");
                    cout<<"DEJA INSCRIS"<<endl;
                }
                if (util_curent.curs.fizica != -1 && useri[util_fiz-1].curs.numefiz !=  "" && exit_fiz==0)
                {
                    scriefiz();
                    exit_fiz=1;
                    cout<<"Inscris cu succes!"<<endl;
                    cout<<"Apasati 0 pentru a iesi sau 4 pentru a vedea urmatoarea sedinta "<<endl;
                    int tasta_curs;
                    cin>>tasta_curs;
                    if(tasta_curs==4)
                        afisarefizica();
                    if(tasta_curs==0)
                        tast=0;
                }

            }
    }


    }
}
void afisaremate()
{   setColor(5);
    system("CLS");
    int i,x=0,n,tasta=1,tast,exit_mate=0;
    cout<<util_curent.nume<<' '<<util_curent.prenume<<' ';
    if(util_curent.curs.mate!=-1)
    {
         while(tasta!=0)
        {
            if(util_curent.curs.mate<20)
            {
                x=20-util_curent.curs.mate;
                cout<<x<<" "<<"ore ramase pana la luarea diplomei"<<endl;
                cout<<"Urmatoare sedinta este pe:"<<' ';
                cout<<28<<' '<<02<<endl;
                cout<<endl;
            }
            else
            {
                cout<<util_curent.curs.mate<<' '<<"elevul isi poate ridica diploma"<<endl;
            }
            cout<<"Apasati 0 pentru a va intoarce";
            cin>>tasta;
        }
    }
    else
    {
        system("CLS");
          tast=9;
        while(tast!=0)
        {
            cout<<endl<<"Elevul nu este inscris la curs!"<<endl;
            cout<<endl;
            cout<<"Apasati 2 daca doriti sa va inscrieti"<<endl;
            cout<<"Apasati 0 ca sa iesiti"<<endl;
            cin>>tast;
            if(tast==2)
            {
                system("CLS");
                util_mate++;
                useri[util_mate-1].curs.mate=0;
                strcpy(useri[util_mate-1].curs.numemate,util_curent.nume);
                util_curent.curs.mate=0;
                if(exit_mate==1)
                {
                    system("CLS");
                    cout<<"DEJA INSCRIS"<<endl;
                }
                if (util_curent.curs.mate != -1 && useri[util_mate-1].curs.numemate !=  "" && exit_mate==0)
                {
                    scriemate();
                    exit_mate=1;
                    cout<<"Inscris cu succes!"<<endl;
                    cout<<"Apasati 0 pentru a iesi sau 4 pentru a vedea urmatoarea sedinta "<<endl;
                    int tasta_curs;
                    cin>>tasta_curs;
                    if(tasta_curs==4)
                        afisaremate();
                    if(tasta_curs==0)
                        tast=0;
                }

            }
        }
    }
}


void verificare_utilizator()
{   setColor(5);
    system("CLS");
    int fiz=0,info=0,mate=0,i,x=0,y=0,z=0;
    char user_name[20];
    int exit=0;
    int tasta=10;
    while(tasta!=0)
    {
        ///system("CLS");
        cout<<"1. Afisare ore ramase INFORMATICA pana la luarea diplomei"<<endl;
        cout<<"2. Afisare ore ramase MATEMATICA pana la luarea diplomei"<<endl;
        cout<<"3. Afisare ore ramase FIZICA pana la luarea diplomei"<<endl;
        cout<<"0. Apasati 0 pentru a iesi";
        cin>>tasta;
        switch(tasta)
        {
            case 1:
                {
                    system("CLS");
                    afisareinfo();
                }_getch;
                break;

            case 2:
            {
                system("CLS");
                afisaremate();
            }_getch;
                break;
            case 3:
                {
                    system("CLS");
                   afisarefizica();
                }_getch;
                break;

        }
    }

}

void afiseaza_utiliz()
{   setColor(5);
    system("CLS");

    int tasta_autentif;
    cout<<"Bine ai venit"<<' '<<util_curent.nume<<' '<<util_curent.prenume<<"!";
    cout<<endl;
    cout<<"1. Afiseaza cursuri inscrise"<<endl;
    cout<<"2. Apasati 0 pentru a iesi";
    cin>>tasta_autentif;
    while(tasta_autentif!=0)
    {

        switch(tasta_autentif)
        {
            case 1:
            {
                verificare_utilizator();
            }_getch;
            break;
        }
        cin>>tasta_autentif;
    }

}

int n=0;
char nume_utilizator[300]="",utilizator[200];
void transferare(char Nume[30], char Prenume[30], char User[30], char Parola[30])
{

    strcpy(useri[nr_util].nume,Nume);
    strcpy(useri[nr_util].prenume,Prenume);
    strcpy(useri[nr_util].user,User);
    strcpy(useri[nr_util].parola,Parola);

}
void tiparire()
{
    ofstream nou("incarcare_util");
    for(int i=0;i<=nr_util;i++)
    {
        nou<<useri[i].nume<<' ';
        nou<<useri[i].prenume<<' ';
        nou<<useri[i].user<<' ';
        nou<<useri[i].parola<<' ';
        nou<<endl;
    }
    nou.close();
}


void afiseaza_utiliz_nou()
{    setColor(5);
     system("CLS");

    int tasta_autentif,tasta_curs,exit_info=0,exit_mate=0,exit_fiz=0;
    cout<<"Bine ai venit"<<' '<<util_curent.nume<<' '<<util_curent.prenume<<"!";
    cout<<endl;
    cout<<"Apasati 1 pentru a va inscrie la cursuri";
    cin>>tasta_autentif;
    system("CLS");
    while(tasta_autentif!=0)
    {
        ///system("CLS");
        cout<<"Apasati tasta 1 pentru a va inscrie la cursul de matematica"<<endl;
        cout<<"Apasati tasta 2 pentru a va inscrie la cursul de informatica"<<endl;
        cout<<"Apasati tasta 3 pentru a va inscrie la cursul de fizica"<<endl;
        cout<<"Apasati tasta 0 pentru a va intoarce de tot"<<endl;
        cin>>tasta_autentif;
        switch(tasta_autentif)
        {
        case 1:
        {
            system("CLS");
            ///useri[nr_util].curs.mate=0;
            util_mate++;
            useri[util_mate-1].curs.mate=0;
            util_curent.curs.mate=0;
            strcpy(useri[util_mate-1].curs.numemate,util_curent.nume);
            if(exit_mate==1)
            {
                system("CLS");
                cout<<"DEJA INSCRIS"<<endl;
            }
            if (util_curent.curs.mate != -1 && useri[util_mate-1].curs.numemate !=  "" && exit_mate==0)
            {   scriemate();
                exit_mate=1;
                 cout<<"Inscris cu succes!"<<endl;
                cout<<"Apasati 0 pentru a iesi sau 4 pentru a vedea urmatoarea sedinta "<<endl;
                cin>>tasta_curs;
                if(tasta_curs==4)
                {
                    afisaremate();
                }
            }



        }_getch;
        break;
        case 2:
        {
            system("CLS");
            ///useri[nr_util].curs.info=0;
            util_info++;
            useri[util_info-1].curs.info=0;
            strcpy(useri[util_info-1].curs.numeinfo,util_curent.nume);
            util_curent.curs.info=0;
            if(exit_info==1)
            {
                system("CLS");
                cout<<"DEJA INSCRIS"<<endl;
            }
            if (util_curent.curs.info != -1 && useri[util_info-1].curs.numeinfo !=  "" && exit_info==0)
            {
                scrieinfo();
                exit_info=1;
                cout<<"Inscris cu succes!"<<endl;
                cout<<"Apasati 0 pentru a iesi sau 4 pentru a vedea urmatoarea sedinta "<<endl;
                cin>>tasta_curs;
                if(tasta_curs==4)
                    afisareinfo();
            }



        }_getch;
        break;
        case 3:
        {

            system("CLS");
           /// useri[nr_util].curs.fizica=0;
             util_fiz++;
            useri[util_fiz-1].curs.fizica=0;
            strcpy(useri[util_fiz-1].curs.numefiz,util_curent.nume);
            util_curent.curs.fizica=0;
            if(exit_fiz==1)
            {
                system("CLS");
                cout<<"DEJA INSCRIS"<<endl;
            }
            if (util_curent.curs.fizica != -1 && useri[util_fiz-1].curs.numefiz !=  "" && exit_fiz==0)
            {
                 scriefiz();
                cout<<"Inscris cu succes!"<<endl;
                cout<<"Apasati 0 pentru a iesi sau 4 pentru a vedea urmatoarea sedinta "<<endl;
                exit_fiz=1;
                cin>>tasta_curs;
                if(tasta_curs==4)
                    afisarefizica();
            }



        }_getch;
        break;
        case 4:
        {
            system("CLS");
            afiseaza_utiliz_nou();
        }_getch;
        break;
        }
    }
}
int verif_nume(char x[30])
{
    int i;
    for(i=0;i<nr_util;i++)
    {
        if(strcmp(x,useri[i].user)==0)
            return 0;
    }
    return 1;
}

void creare_cont()
{   setColor(5);
    system("CLS");
    int tast=0;
    char Nume[30]="",Prenume[30]="",User[30]="",Parola[30]="";
    cout<<"Nume:"<<endl;
    cin>>Nume;
    cout<<"Prenume"<<endl;
    cin>>Prenume;
    cout<<"Nume user (poate contine litere si cifre) :"<<endl;
    cin>>User;
    if(verif_nume(User)==0)
    {
       cout<<"Nume de user deja luat";
       cout<<endl;
       cout<<"Pentru reintroducere apasati 2"<<endl;
       cin>>tast;
       if(tast==2)
        creare_cont();
    }
    cout<<"Introduceti parola:"<<endl;
    cin>>Parola;
    int ok=1;
    if(ok==1)
    {
        cout<<"User creat cu succes!";
        nr_util++;
        cout<<endl;
        cout<<"Pentru a continua apasati 1";
    }
    int tasta_curs;

    transferare(Nume,Prenume,User,Parola);
    tiparire();
    strcpy(util_curent.nume,Nume);
    strcpy(util_curent.prenume,Prenume);
    strcpy(util_curent.user,User);
    strcpy(util_curent.parola,Parola);

    cin>>tasta_curs;
    if(tasta_curs==1)
    {
        afiseaza_utiliz_nou();
    }
}
void sortare_elevi_user()
{
    system("CLS");
    char user_elev[30]="",nume_elev[30]="",prenume_elev[30]="",parola_elev[30]="";
    int tasta=1,i=0,j=0;
    while(tasta!=0)
    {
        for(i=0;i<=nr_util;i++)
       {
            for(j=i+1;j<=nr_util;j++)
            {
                if(strcmp(useri[i].user,useri[j].user)>0)
                {
                    strcpy(nume_elev,useri[i].nume);
                    strcpy(useri[i].nume,useri[j].nume);
                    strcpy(useri[j].nume,nume_elev);
                    strcpy(prenume_elev,useri[i].prenume);
                    strcpy(useri[i].prenume,useri[j].prenume);
                    strcpy(useri[j].prenume,prenume_elev);
                    strcpy(user_elev,useri[i].user);
                    strcpy(useri[i].user,useri[j].user);
                    strcpy(useri[j].user,user_elev);
                    strcpy(parola_elev,useri[i].parola);
                    strcpy(useri[i].parola,useri[j].parola);
                    strcpy(useri[j].parola,parola_elev);


                }
            }
        }
        for(int i=0;i<nr_util;i++)
        {
            cout<<useri[i].user<<endl;
            cout<<useri[i].nume<<' '<<useri[i].prenume<<endl;
        }
        cout<<"Apasati 0 pentru a va intoarce";
        cin>>tasta;


    }
}
void sortare_elevi_nume()
{    setColor(5);
    system("CLS");
    char nume_elev[30]="",prenume_elev[30]="",user_elev[30]="",parola_elev[30]="";
    int col=0,tasta=1,i=0,j=0;
    while(tasta!=0)
    {
        for(i=0;i<nr_util;i++)
       {
            for(j=i+1;j<nr_util;j++)
            {
                if(strcmp(useri[i].nume,useri[j].nume)>0)
                {
                    strcpy(nume_elev,useri[i].nume);
                    strcpy(useri[i].nume,useri[j].nume);
                    strcpy(useri[j].nume,nume_elev);
                    strcpy(prenume_elev,useri[i].prenume);
                    strcpy(useri[i].prenume,useri[j].prenume);
                    strcpy(useri[j].prenume,prenume_elev);
                    strcpy(user_elev,useri[i].user);
                    strcpy(useri[i].user,useri[j].user);
                    strcpy(useri[j].user,user_elev);
                    strcpy(parola_elev,useri[i].parola);
                    strcpy(useri[i].parola,useri[j].parola);
                    strcpy(useri[j].parola,parola_elev);
                }
            }
        }
        for(int i=0;i<nr_util;i++)
        {   cout<<useri[i].nume<<' '<<useri[i].prenume<<endl;
            cout<<useri[i].user<<endl;
            cout<<endl;
        }
        cout<<"Apasati 0 pentru a va intoarce";
        cin>>tasta;


    }

}
void afis_elev()
{   setColor(5);
    system("CLS");
    int tasta=1;
    while(tasta!=0)
    {

        cout<<"Apasati 0 pentru a va reintoarce:"<<endl;
        cout<<"Apasati 1 pentru a sorta in ordine alfabetica elevii ~ dupa NUME"<<endl;
        cout<<"Apasati 2 pentru a sorta in ordine alfabetica elevii ~ dupa USER"<<endl;
        cout<<"Apasati 3 pentru a vedea elevii"<<endl;
        cin>>tasta;
        if(tasta==1)
        {
            sortare_elevi_nume();
            system("CLS");
        }
        if(tasta==2)
        {
            sortare_elevi_user();
            system("CLS");
        }
        if(tasta==3)
        {
            system("CLS");
            for(int i=0;i<nr_util;i++)
            {   cout<<useri[i].nume<<' '<<useri[i].prenume<<endl;
                cout<<useri[i].user<<endl;
                cout<<endl;
            }
        }

    }





}
void setare_user_curent(char x[30],char y[30],char z[30])
{
    strcpy(util_curent.nume,x);
    strcpy(util_curent.prenume,y);
    strcpy(util_curent.user,z);

}
void cautare()
{   setColor(5);
    ///ifstream util("incarcare_util");
    system("CLS");
    int ok=0,i;
    char nume_elev[30]="";
    cout<<"Introduceti numele elevului:"<<' ';
    cin>>nume_elev;
    for(i=0;i<nr_util && ok==0;i++)
    {
        if(strcmp(useri[i].nume,nume_elev)==0)
        {
            cout<<useri[i].user<<' ';
            ok=1;
        }
    }

    int tasta=0;
    while(tasta==0)
    {
        if(ok==0)
        {
            cout<<"NUMELE NU A FOST GASIT";
            cout<<endl;
            cout<<"Apasati 1 pentru reintroducere";
            tasta=1;
        }


        if(ok==1)
        {
             setare_user_curent(nume_elev,useri[i-1].prenume,useri[i-1].user);
             verificare_utilizator();
        }


    }
}
void sters()
{
    ofstream nou("incarcare_util");
    for(int i=0;i<nr_util;i++)
    {
        nou<<useri[i].nume<<' ';
        nou<<useri[i].prenume<<' ';
        nou<<useri[i].user<<' ';
        nou<<useri[i].parola<<' ';
        nou<<endl;
    }
    nou.close();
}
void stergere_elev_curs()
{   setColor(5);
    ifstream fiz("fizica");
    ifstream info("informatica");
    ifstream mate("matematica");
    int i,ok=0,poz=0;;
    for(i=0;i<util_fiz;i++)
    {
        if(strcmp(util_curent.nume,useri[i].curs.numefiz)==0)
            ok=1;
    }
    fiz.close();
    poz=i;
    if(ok==1)
    {
         for(i=poz;i<util_fiz-1;i++)
        {
            strcpy(useri[i].curs.numefiz,useri[i+1].curs.numefiz);
            useri[i].curs.fizica=useri[i+1].curs.fizica;
        }
        util_fiz--;
       ofstream nou("fizica");
        for(int i=0;i<util_fiz;i++)
        {
            nou<<useri[i].curs.numefiz<<' ';
            nou<<useri[i].curs.fizica<<' ';
            nou<<endl;
        }
        nou.close();
    }
    ok=0;
    for(i=0;i<util_mate;i++)
    {
        if(strcmp(util_curent.nume,useri[i].curs.numemate)==0)
            ok=1;
    }
    mate.close();
    poz=i;
    if(ok==1)
    {
         for(i=poz;i<util_mate-1;i++)
        {
            strcpy(useri[i].curs.numemate,useri[i+1].curs.numemate);
            useri[i].curs.mate=useri[i+1].curs.mate;
        }
        util_mate--;
       ofstream nou("matematica");
        for(int i=0;i<util_mate;i++)
        {
            nou<<useri[i].curs.numemate<<' ';
            nou<<useri[i].curs.mate;
            nou<<endl;
        }
        nou.close();
    }
    ok=0;
    for(i=0;i<util_info;i++)
    {
        if(strcmp(util_curent.nume,useri[i].curs.numeinfo)==0)
            ok=1;
    }
    info.close();
    poz=i;
    if(ok==1)
    {
         for(i=poz;i<util_info-1;i++)
        {
            strcpy(useri[i].curs.numeinfo,useri[i+1].curs.numeinfo);
            useri[i].curs.info=useri[i+1].curs.info;
        }
        util_info--;
       ofstream nou("informatica");
        for(int i=0;i<util_info;i++)
        {
            nou<<useri[i].curs.numeinfo<<' ';
            nou<<useri[i].curs.info;
            nou<<endl;
        }
        nou.close();
    }

}
void stergere_util()
{   setColor(5);
    int poz=0,ok=0,i=0,tasta=1;
    for(i=0;i<nr_util && ok==0;i++)
    {
        if(strcmp(useri[i].user,util_curent.user)==0)
        {
            poz=i;
            ok=1;
        }
    }
    for(i=poz;i<nr_util-1;i++)
    {
        strcpy(useri[i].user,useri[i+1].user);
        strcpy(useri[i].nume,useri[i+1].nume);
        strcpy(useri[i].prenume,useri[i+1].prenume);
        strcpy(useri[i].parola,useri[i+1].parola);
    }
    nr_util--;
    sters();
    stergere_elev_curs();
    while(tasta!=0)
    {
       cout<<"Elev sters cu succes!"<<endl<<"Apasati 0 pentru a continua";
        cin>>tasta;
    }


}

void stergere_elev()
{   setColor(5);
    system("CLS");
    int tasta;
    char nume_sters[30],parola[30]="";
    int ok=0,i;
    cout<<"Introduceti numele elevului:"<<' ';
    cin>>nume_sters;
    for(i=0;i<nr_util && ok==0;i++)
    {
        if(strcmp(useri[i].nume,nume_sters)==0)
        {
            cout<<useri[i].nume<<' '<<useri[i].prenume<<endl;
            cout<<useri[i].user<<endl;
            ok=1;
        }
    }
    if(ok==0)
    {
        cout<<"NUMELE NU A FOST GASIT";
        cout<<endl;
        cout<<"Apasati 1 pentru reintroducere";
        cin>>tasta;
        if(tasta==1)
            stergere_elev();
    }
    tasta=10;
    if(ok==1)
        {
            setare_user_curent(nume_sters,useri[i-1].prenume,useri[i-1].user);
            cout<<"Introduceti parola:";
            cin>>parola;
            if(strcmp(parola,"2024admin")==0)
            {
                cout<<"SUNTETI SIGUR CA DORITI SA-L STERGETI?"<<endl;
                cout<<"1 - continuare"<<endl;
                cout<<"0 - iesire"<<endl;
                cin>>tasta;
                if(tasta==1)
                     stergere_util();
            }
            else
            {
                cout<<"PAROLA GRESITA";
                cout<<endl<<"Pentru reintroducere apasati 1";
                cin>>tasta;
                if(tasta==1)
                    stergere_elev();
            }
        }

}
void administrator()
{   setColor(5);
    ifstream admin("administrator");
    int tasta_admin=1;
    while(tasta_admin!=0)
    {
        system("CLS");
        cout<<"1.Afisare elevi"<<endl;
        cout<<"2.Cautare dupa nume"<<endl;
        cout<<"3.Stergere elev"<<endl;
        cout<<"0.Apasati 0 pentru a iesi";
        cin>>tasta_admin;
        switch(tasta_admin)
            {
                case 1:
                {
                    afis_elev();

                }_getch();
                break;
                case 2:
                {
                    cautare();

                }_getch();
                break;
                case 3:
                {
                    tasta_admin=1;
                    stergere_elev();
                }_getch();
                break;
            }
    }
}


void autentificare()
{   setColor(5);
    int exit=0,ok=0,iesi=0;
    while(exit==0)
    {
        system("CLS");
        char parole[20]="";
        ///int ok=0;
        cout<<"Introduceti numele utilizatorului:"<<' ';
        cin>>nume_utilizator;
        cout<<"Introduceti parola:"<<' ';
        cin>>parole;
        if(strcmp(nume_utilizator,"admin")==0 && strcmp(parole,"2024admin")==0)
        {
            administrator();
            con_ca_admin=1;
            exit=1;
            break;

        }
        for(int i=0;i<nr_util;i++)
        {
            if(strcmp(useri[i].user,nume_utilizator)==0 && strcmp(useri[i].parola,parole)==0)
            {
                strcpy(util_curent.nume,useri[i].nume);
                strcpy(util_curent.prenume,useri[i].prenume);
                ifstream fiz("fizica");
                ifstream mate("matematica");
                ifstream info("informatica");
                char nume[30]="";
                int ore;
                while(fiz>>nume>>ore && iesi==0)
                {
                    if(strcmp(util_curent.nume,nume)==0)
                    {
                        util_curent.curs.fizica=ore;
                        iesi=1;
                    }
                }
                if(iesi==0)
                {
                    util_curent.curs.fizica=-1;
                }
                iesi=0;
                while(mate>>nume>>ore && iesi==0)
                {
                    if(strcmp(util_curent.nume,nume)==0)
                    {
                        util_curent.curs.mate=ore;
                        iesi=1;
                    }
                }
                if(iesi==0)
                {
                    util_curent.curs.mate=-1;
                }
                iesi=0;
                while(info>>nume>>ore && iesi==0)
                {
                    if(strcmp(util_curent.nume,nume)==0)
                    {
                        util_curent.curs.info=ore;
                        iesi=1;
                    }
                }
                if(iesi==0)
                {
                    util_curent.curs.info=-1;
                }
                con_ca_admin=0;
                exit=1;
            }
        }


        if (exit==0)
        {
            cout<<"USER SAU PAROLA GRESITA.";
            cout<<endl;
            cout<<"Apasati 1 pentru reintroducere, 2 pentru creare cont si 3 pentru revenirea la meniu";
            int tasta_user;
            cin>>tasta_user;
            switch(tasta_user)
            {
                case 1:
                {
                    break;
                }_getch();
                break;
                case 2:
                {
                    creare_cont();
                }_getch();
                break;
                case 3:
                {
                    exit=1;
                    ok=1;
                    break;
                }_getch();
                break;
            }
        }

    }
    if(util_curent.nume!="" && con_ca_admin!=1 && ok==0)
    {
        afiseaza_utiliz();
    }

    //Succes util_curent.nume!="" apelezi ecran dupa logare util_curent.nume=="" - meniu

}
void inf_mate()
{   setColor(5);
    int tasta=1;
    while(tasta!=0)
    {
        cout<<"Dobrescu Anca ~ coordonatoare catedra de matematica"<<endl;
        cout<<endl;
        cout<<"PROFESORI MEDITATORI:"<<endl;
        cout<<endl;
        cout<<"Dobrogean Mihai"<<endl;
        cout<<"Spaid Paulina"<<endl;
        cout<<"Mirica Sergiu"<<endl;
        cout<<"Apasati 0 pentru a va intoarce";
        cin>>tasta;
    }

}
void inf_info()
{   setColor(5);
    int tasta=1;
    while(tasta!=0)
    {
        cout<<"Dracea Bogdan ~ coordonator catedra de informatica"<<endl;
        cout<<endl;
        cout<<"PROFESORI MEDITATORI:"<<endl;
        cout<<endl;
        cout<<"Rona Irina"<<endl;
        cout<<"Darea Mihnea"<<endl;
        cout<<"Polan Claudia"<<endl;
        cout<<"William Sonya"<<endl;
        cout<<"Apasati 0 pentru a va intoarce";
        cin>>tasta;
    }

}
void inf_fiz()
{   setColor(5);
    int tasta=1;
    while(tasta!=0)
    {
        cout<<"Dracea Bogdan ~ coordonator catedra de fizica"<<endl;
        cout<<endl;
        cout<<"PROFESORI MEDITATORI:"<<endl;
        cout<<endl;
        cout<<"Oleg Nadia"<<endl;
        cout<<"Trandafirescu Adela"<<endl;
        cout<<"Moraru Damian"<<endl;
        cout<<"Irinescu Lidia"<<endl;
        cout<<"Apasati 0 pentru a va intoarce";
        cin>>tasta;
    }

}
void preturi()
{   setColor(5);
    int tasta=10;
    while(tasta!=0)
    {
        cout<<"150 de lei/2h ~ sedinta matematica"<<endl;
        cout<<"150 de lei/2h ~ sedinta informatica"<<endl;
        cout<<"150 de lei/2h ~ sedinta fizica"<<endl;
        cout<<"PACHET: 400 de lei ~ include curs: info, mate, fizica"<<endl;
        cout<<"Apasati 0 pentru a va intoarce"<<endl;
        cin>>tasta;
    }

}
void informatii_cursuri()
{   setColor(5);
    int tasta=10;
    while(tasta!=0)
    {
         system("CLS");
         cout<<"Apasati tasta 1 pentru matematica"<<endl;
         cout<<"Apasati tasta 2 pentru fizica"<<endl;
         cout<<"Apasati tasta 3 pentru informatica"<<endl;
         cout<<"Apasati pentru 4 a vedea preturile si pachetele"<<endl;
         cout<<"Apasati tasta 0 pentru a iesi"<<endl;
         cin>>tasta;
         switch(tasta)
         {
           case 1:
            {
                system("CLS");
                inf_mate();

            }_getch();
                break;
            case 2:
            {
                system("CLS");
                inf_info();

            }_getch();
                break;
            case 3:
            {
                system("CLS");
                inf_fiz();

            }_getch();
                break;
            case 4:
            {
                system("CLS");
                preturi();

            }_getch();
                break;
         }

    }
}

void meniu1()
{
    int tasta;
    int terminalWidth=80;
    int width=40;

    cout << string(50, '\n');
    ///incarca_curs();
    do
    {
        system("CLS");
        int startX = (terminalWidth - width) / 2;
        setColor(5);
        cout<< "                                                                 \n";
        cout<< "                                                                 \n";
        cout<< "                                                                 \n";
        cout<< "                                                                 \n";
        cout<< "                                                                 \n";
        cout<< "                                                                 \n";
        cout << string(startX, ' ') << "+--------------------------------------+\n";
        centerText("1. Autentificare", terminalWidth);
        cout << "\n";
        centerText("2. Inregistrare", terminalWidth);
        cout << "\n";
        centerText("3. Informatii cursuri", terminalWidth);
        cout << "\n";
        centerText("0. EXIT", terminalWidth);
        cout << "\n" << string(startX, ' ') << "+--------------------------------------+\n";
        setColor(7); // Revenire la culoarea implicită
        cin>>tasta;
        switch(tasta)
        {
            case 1:
            {
                system("CLS");
                autentificare();
            };
                break;;
            case 2:
            {
                system("CLS");
                creare_cont();
            }_getch();
                break;
            case 3:
            {
                system("CLS");
                informatii_cursuri();

            }_getch();
                break;
        }
    }
    while(tasta!=0);
}

void SetColor(int textColor, int bgColor) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, (bgColor << 4) | textColor);
}


int main()
{   system("COLOR 5");


    cout << "         _                    _                   _         _   _         _               \n";
    cout << "        / \\    ___  __ _   __| |  ___  _ __ ___  (_)  ___  | | | | _   _ | |__          \n";
    cout << "       / _ \\  / __|/ _` | / _` | / _ \\| '_ ` _ \\ | | / __| | |_| || | | || '_ \\        \n";
    cout << "      / ___ \\| (__| (_| || (_| ||  __/| | | | | || || (__  |  _  || |_| || |_) |        \n";
      cout << "     /_/   \\_\\___|\\__,_| \\__,|_|\\___||_| |_  | |_||_| \  \___| |_| |_| \\__,_||_._/\n";
    cout << "                                                                                           \n";
    cout << "                                                                                           \n";
    cout << "                                                                                           \n";

    string message = "Apasa Enter pentru a afisa meniul principal";
    int terminalWidth = 80;
    int width = message.length() + 4;
    int startX = max(0, (terminalWidth - width) / 2); // Asigurați-vă că startX este întotdeauna pozitiv

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < terminalWidth; j++) {
            if (j >= startX && j < startX + width) {
                if (i == 0 || i == 4 || j == startX || j == startX + width - 1) {
                    cout << "*";
                } else if (i == 2 && j == startX + 2) {
                    centerText(message, width - 4);
                    j += width - 4;
                } else {
                    cout << " ";
                }
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }




    SetColor(15, 0); // Revenire la culoarea implicita
    cin.get();

    int tasta;

    ///Se incarca toate datele de care are nevoie aplicatie
    incarca_utiliz();
    incarca_curs();
    meniu1();


    return 0;
}
