
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
void sales(map<int,Sales>&s,map<int,Client>& c,map<int,Fuel>& f);

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
    map<int,Sales>sales;

    init(client,fuel);
    listClient(client);
    listFuel(fuel);
   

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
=======
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <cstdlib>
#include <ctime>

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

int randomId()
{
    srand(time(0));
    int randomNumber = 100 + rand() % 899;
    return randomNumber;
}


void cadastrarUsuario(){
    system("clear||cls");
    string nome;
    bool ativo;
    Client novo;
    map<int, Client> Client;


    cout<<"-------------Cadastrar venda---------------\n";
    cout<<"Digite o nome do cliente\n";
    cin>> nome;
    cout<<"Cliente ativo(true or false)?\n";
    cin>> ativo;

    int id = 1;

    novo.code = id++;
    novo.name = nome;
    novo.active = ativo;
    Client[novo.code] = novo;
    system("clear||cls");
}

int menu(){

int opcao;
    cout<<"-------------------MENU----------------------\n";
    cout<<"1.Cadastrar usuário\n";
    cout<<"2.Cadastrar venda\n";
    cout<<"3.Verificar venda para cliente\n";
    cout<<"4.Verificar \n";
    cout<<"4.Teste random value \n";
    cout<<"---------------------------------------------\n";
cin>> opcao;


    switch(opcao){
        case 1:
               cadastrarUsuario();
            break;

        case 2:

            break;

        case 3:

            break;
        case 4:
                int value = randomId();
                cout<< value;
            break;
    }

}

int main() {

    menu();

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

>>>>>>> c2b696f86ab8b6aa1b8e022e4753099fba566d85
