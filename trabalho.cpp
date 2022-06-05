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
void listFuel(map<int,Fuel>&fuel);
void listClient(map<int,Client>&Client);

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

void listClient(map<int,Client>&client){
    cout << "\n  Clientes \n\n";
    for(auto i: client){
        if(i.second.active){
        i.second.print();
        }
    }
}

void listFuel(map<int,Fuel>&fuel){
    cout << "\n  Combustiveis \n\n";
    for(auto i: fuel){
        i.second.print();
    }
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

    fuel.code = 3654;
    f[fuel.code].code = 568916;
    f[fuel.code].name = "Diesel s10";
    f[fuel.code].price = 5.30;
    f[fuel.code].changeDatePrice.day = 30;
    f[fuel.code].changeDatePrice.month = 11;
    f[fuel.code].changeDatePrice.year = 2022;

    fuel.code = 5584;
    f[fuel.code].code = 56562;
    f[fuel.code].name = "Gasolina comum";
    f[fuel.code].price = 6.49;
    f[fuel.code].changeDatePrice.day = 23;
    f[fuel.code].changeDatePrice.month = 6;
    f[fuel.code].changeDatePrice.year = 2021;

    fuel.code = 2987;
    f[fuel.code].code = 65631;
    f[fuel.code].name = "Etanol comum";
    f[fuel.code].price = 7.49;
    f[fuel.code].changeDatePrice.day = 02;
    f[fuel.code].changeDatePrice.year = 2022;
}
