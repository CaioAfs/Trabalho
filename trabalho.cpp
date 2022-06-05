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
     cout<<"Codigo: "<< code << ","<< " Nome: " << name << "," << " Ativo: "
    << (active  ? "Sim" : "Nao" ) << ";"<<endl;
    }
}Client;

typedef struct fuel{
    int code;
    string name;
    float price;
    Date changeDatePrice;

    void print(){
        cout<<"Codigo: " << code << "," << " Nome: " << name << "," << " Preco: " << price << ","<<
        " Data de alteracao: "<< changeDatePrice.day <<"/"<< changeDatePrice.month <<"/" <<
         changeDatePrice.year << ";"<<endl;
    }
}Fuel;

typedef struct sales{
    Client codeClient;
    Fuel codeFuel;
    bool paidOut;
    double theAmount;
    double literValue;
    double total;
    string responsible;
    Date date;



    void print(){
        cout << "Data: " << date.day <<"/"<< date.month <<"/" << date.year<< ", Codigo do cliente: "
        << codeClient.code << ", Codigo do combustivel: "<< codeFuel.code<< ", Quantidade: " << theAmount
        << ", Valor do litro: " << literValue << ", Total: "<< total << ", Reponsavel: "<< responsible
        << ", Pago: " << paidOut << ";"<< endl;
        }
}Sales;


void init(map<int,Client>& c, map<int,Fuel>& f);
void printClient(map<int,Client>&c);
void listClient(map<int,Client>& c);
void listFuel(map<int,Fuel>& f);

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
    listClient(client);
    listFuel(fuel);

}


void init(map<int,Client>& c,map<int,Fuel>& f){
    Client client;
    Fuel fuel;

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

    fuel.code = 4558;
    f[fuel.code ].code = 68745;
    f[fuel.code ].name = "Diesel s10";
    f[fuel.code ].price = 6.25;
    f[fuel.code ].changeDatePrice.day = 26;
    f[fuel.code ].changeDatePrice.month = 06;
    f[fuel.code ].changeDatePrice.year = 2021;

    fuel.code = 6489;
    f[fuel.code ].code = 45689;
    f[fuel.code ].name = "Gasolina";
    f[fuel.code ].price = 7.49;
    f[fuel.code ].changeDatePrice.day = 31;
    f[fuel.code ].changeDatePrice.month = 11;
    f[fuel.code ].changeDatePrice.year = 2021;

    fuel.code = 5122;
    f[fuel.code ].code = 45689;
    f[fuel.code ].name = "Etanol comum";
    f[fuel.code ].price = 6.79;
    f[fuel.code ].changeDatePrice.day = 14;
    f[fuel.code ].changeDatePrice.month = 05;
    f[fuel.code ].changeDatePrice.year = 2022;
}

void listFuel(map<int,Fuel>& f){
    cout << "\n  Combustivel \n\n";
    for(auto i: f){
        i.second.print();
    }
}

void listClient(map<int,Client>& c){
    cout << "\n  CLIENTES \n\n";
    for(auto i: c){
        if(i.second.active){
        i.second.print();
        }
    }
}
