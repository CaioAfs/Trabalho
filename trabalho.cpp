#include <map>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

typedef struct date{
    int day;
    int month;
    int year;
}Date;

typedef struct client {
    int code;
    string name;
    bool active;

    void print(){
     cout<<"Codigo: "<< code << ";"<< " Nome: " << name << ";" << " Ativo: "
    << (active  ? "Sim" : "Nao" ) << ";"<<endl;
    }
}Client;

typedef struct fuel{
    int code;
    string name;
    float price;
    Date changeDatePrice;

    void print(){
        cout<<"Codigo: " << code << ";" << " Nome: " << name << ";" << " Preco: " << price << ";"<<
        " Data de alteracao: "<< changeDatePrice.day <<"/"<< changeDatePrice.month <<"/" <<
         changeDatePrice.year << ";"<<endl;
    }
}Fuel;


void init(map<int,Client>& c, map<int,Fuel>& f);
void printClient(map<int,Client>&c);

int main() {

    int opcao;
    cout<<"-------------------MENU----------------------\n";
    cout<<"1.Cadastrar venda realizada\n";
    cout<<"2.Verificar venda\n";
    cout<<"3.Verificar compras de cliente\n";
    cout<<"4.Gerar dados automaticamente\n";
    cout<<"---------------------------------------------\n";
    cin>> opcao;

    map<int,Client>client;
    map<int,Fuel>fuel;

    init(client,fuel);

    cout << "\n  CLIENTES \n\n";
    for(auto i: client){
        if(i.second.active){
        i.second.print();
        }
    }

}





void init(map<int,Client>& c,map<int,Fuel>& f){
    Client client;

    client.code = 2235;
    c[client.code].code = 45265;
    c[client.code].name = "Hugo Ferreira";
    c[client.code].active = true;

    client.code = 4444;
    c[client.code].code = 48964;
    c[client.code].name = "Vitor alexandre";
    c[client.code].active = false;

    client.code = 2877;
    c[client.code].code = 66958;
    c[client.code].name = "Fulano Ciclano";
    c[client.code].active = true;

}
