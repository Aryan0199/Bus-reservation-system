#include <iostream>
#include <cstring>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
static int p=0;
class server{
    char busno[5];
    char driver[10];
    char arrival[5];
    char depart[5];
    char from[10];
    char to[10];
    char seat[8][4][10];
public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int l);
}
        bus[10];
void vline(char x){
    for(int i=120;i>=0;i--){
        cout<<x;
    }
}
void server::install() {
    cout<<"Enter bus number: ";
    cin>>bus[p].busno;
    cout<<"Enter driver's name: ";
    cin>>bus[p].driver;
    cout<<"Enter Arrival time: ";
    cin>>bus[p].arrival;
    cout<<"Enter Departure time: ";
    cin>>bus[p].depart;
    cout<<"From: \t\t\t";
    cin>>bus[p].from;
    cout<<"To: \t\t\t";
    cin>>bus[p].to;
    bus[p].empty();
    p++;
}
void server::allotment() {
    int seat;
    char number[5];
    top:
    cout<<"Enter bus number: ";
    cin>>number;
    int n;
    for (n = 0; n <=p; n++) {
        if(strcmp(bus[n].busno,number)==0)
            break;
    }
    int c;
    while(n<=p){
        cout<<"Enter seat no. you wish to have: ";
        cin>>seat;
        if(seat>32){
            cout<<"Sorry maximum seats in the bus are 32!\n";
        }
        else{

            if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0){
                cout<<"Enter passenger name: ";
                cin>>bus[n].seat[seat/4][(seat%4)-1];
                cout<<"Your booking has been confirmed\n";
                cout<<"Happy Journey:):)\n";
                break;
            }
            else{
                cout<<"Sorry the seat is already booked!\n";
                cout<<"Press 1 to book another seat\n";
                cout<<"Press 0 to select another bus\n";
                cin>>c;
                if(c==0){
                    goto top;
                }
            }
        }
    }
    if(n>p){
        cout<<"The bus-number you have entered is invalid\n";
        cout<<"Please enter valid bus number\n";
        goto top;
    }
}
void server::empty() {
    for (int i = 0; i <8 ; ++i) {
        for (int j = 0; j < 4; ++j) {
            strcpy(bus[p].seat[i][j],"Empty");
        }
    }
}
void server::show()  {
    int n;
    char number[5];
    cout<<"Enter Bus number\n";
    cin>>number;
    for(n=0;n<=p;n++){
        if(strcmp(bus[n].busno,number)==0)
            break;
    }
    while (n<=p){
        vline('*');
        cout<<"Bus number:\t"<<bus[n].busno
            <<"Driver:"<<" "<<bus[n].driver<<"Arrival time:"<<" "
            <<bus[n].arrival<<"\tDeparture time:"<<" "<<bus[n].depart
            <<"\From:\t"<<bus[n].from<<"\To:\t"<<bus[n].to<<endl;
        vline('*');
        bus[0].position(n);
        int a=0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 4; ++j) {
                a++;
                if(strcmp(bus[n].seat[i][j],"Empty")!=0)
                    cout<<"\nThe seat no. "<<a<<"is Reserved for: "<<bus[n].seat[i][j];
            }
        }
        break;
    }
    if(n>p){
        cout<<"Enter correct bus no.\n";
    }
}
void server::position(int l) {
    {
        int s=0;p=0;
        for (int i =0; i<8;i++)
        {
            cout<<"\n";
            for (int j = 0;j<4; j++)
            {
                s++;
                if(strcmp(bus[l].seat[i][j], "Empty")==0)
                {
                    cout.width(5);
                    cout.fill(' ');
                    cout<<s<<".";
                    cout.width(10);
                    cout.fill(' ');
                    cout<<bus[l].seat[i][j];
                    p++;
                }
                else
                {
                    cout.width(5);
                    cout.fill(' ');
                    cout<<s<<".";
                    cout.width(10);
                    cout.fill(' ');
                    cout<<bus[l].seat[i][j];
                }
            }
        }
        cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busno;
    }
}
void server::avail() {
    for (int n = 0; n < p; ++n) {
        vline('*');
        cout<<"Bus number: \t"<<bus[n].busno
            <<"Driver: \t"<<bus[n].driver<<"Arrival time: \t"
            <<bus[n].arrival<<"\tDeparture time: "<<bus[n].depart
            <<"\t\tFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<bus[n].to<<endl;
        vline('*');
        vline('_');
    }

}
int main(){
    int z;
    system("cls");
    while(1) {
        cout << "\n\n\n\n";
        cout << "\t\t\t1.Install\n\t\t\t";
        cout << "2.Reservation\n\t\t\t";
        cout << "3.Show\n\t\t\t";
        cout << "4.Buses Available\n\t\t\t";
        cout << "5.Exit\n";
        cout << "Select one option: ";
        cin >> z;
        switch (z) {
            case 1:
                bus[p].install();
                break;
            case 2:
                bus[p].allotment();
                break;
            case 3:
                bus[0].show();
                break;
            case 4:
                bus[0].avail();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}
