/*-----------------------
Customer
José Emiliano Riosmena Castañón
A01704245
------------------------*/
#ifndef CUSTOMER_H //Checha si la clase está definida
#define CUSTOMER_H //Define la clase

#include <string> //Importa los strings
#include <sstream> //Importa los stringstream
#include <iomanip> //Importa los manipuladores
#include "bill.h" //Importa la clase bill
#include "operator.h" //Importa la clase operator
using namespace std; //Permite utilizar atributos std

class Customer { //Crea una clase
private: //Crea la sección para variables privadas
  int id, age, totalSpentTalkingTime, totalMessageSent, totalInternetUsage; //Crea variables
  string name; //Crea una variable
  Operator* op; //Crea un apuntador
  Bill *bill; //Crea un apuntador

public: //Crea la sección para variables públicas
  Customer(int, string, int, Operator*, double); //Crea un constructor
  Customer(const Customer&); //Crea un constructor de copia
  ~Customer(); //Crea un destructor

  int getId() const; //Crea una función getter
  int getAge() const; //Crea una función getter
  int getTotalSpentTalkingTime() const; //Crea una función getter
  int getTotalMessageSent() const; //Crea una función getter
  double getTotalInternetUsage() const; //Crea una función getter
  string getName() const; //Crea una función getter
  Operator* getOperator() const; //Crea una función getter
  Bill* getBill() const; //Crea una función getter
  
  void addTalkingTime(int); //Crea una función
  void addTotalMessageSent(int); //Crea una función
  void addTotalInternetUsage(double); //Crea una función
  void setOperator(Operator*); //Crea una función setter

  string toString() const; //Crea una función

  void talk (int, Customer&); //Crea una función
  void message(int, const Customer&); //Crea una función
  void connection(double); //Crea una función
  void pay(double); //Crea una función
}; //Cierra la clase
Customer::Customer(int i, string n, int a, Operator *o, double lim){ //Llama al constructor con los parametros establecidos
	id=i; //Guarda el valor en la variable
	name=n; //Guarda el valor en la variable
	age=a; //Guarda el valor en la variable
	op=o; //Guarda el valor en la variable
	bill=new Bill(lim); //Guarda el valor en la variable
	totalSpentTalkingTime=0; //Guarda el valor en la variable
	totalMessageSent=0; //Guarda el valor en la variable
	totalInternetUsage=0; //Guarda el valor en la variable
} //Cierra la función
Customer::Customer(const Customer &other){ //Llama al constructor de copia con los parametros establecidos
	id=other.id; //Guarda el valor en la variable
	name=other.name; //Guarda el valor en la variable
	age=other.age; //Guarda el valor en la variable
	op=other.op; //Guarda el valor en la variable
	bill=other.bill; //Guarda el valor en la variable
	totalSpentTalkingTime=other.totalSpentTalkingTime; //Guarda el valor en la variable
	totalMessageSent=other.totalMessageSent; //Guarda el valor en la variable
	totalInternetUsage=other.totalInternetUsage; //Guarda el valor en la variable
} //Cierra la función
Customer::~Customer(){ //Llama al destructor
	delete bill; //Borra el apuntador
	bill=NULL; //Anula el apuntador
	op=NULL; //Anula el apuntador
} //Cierra la función
int Customer::getId() const{ //Llama a la función
	return id; //Regresa el valor
} //Cierra la función
int Customer::getAge() const{ //Llama a la función
	return age; //Regresa el valor
} //Cierra la función
int Customer::getTotalSpentTalkingTime() const{ //Llama a la función
	return totalSpentTalkingTime; //Regresa el valor
} //Cierra la función
int Customer::getTotalMessageSent() const{ //Llama a la función
	return totalMessageSent; //Regresa el valor
} //Cierra la función
double Customer::getTotalInternetUsage() const{ //Llama a la función
	return totalInternetUsage; //Regresa el valor
} //Cierra la función
string Customer::getName() const{ //Llama a la función
	return name; //Regresa el valor
} //Cierra la función
Operator* Customer::getOperator() const{ //Llama a la función
	return op; //Regresa el valor
} //Cierra la función
Bill* Customer::getBill() const{ //Llama a la función
	return bill; //Regresa el valor
} //Cierra la función
void Customer::addTalkingTime(int minute){ //Llama a la función con los parametros establecidos
	if (minute>0){
		totalSpentTalkingTime+=minute;
	}
} //Cierra la función
void Customer::addTotalMessageSent(int mc){ //Llama a la función con los parametros establecidos
	if (mc>0){ //Condicional si los mensajes son mayores a 0
		totalMessageSent+=mc; //Agrega el valor a la variable
	} //Cierra la condicional
} //Cierra la función
void Customer::addTotalInternetUsage(double amount){ //Llama a la función con los parametros establecidos
	if (amount>0){
		totalInternetUsage+=amount;
	}
} //Cierra la función
void Customer::setOperator(Operator *o){ //Llama a la función con los parametros establecidos
	op=o;
} //Cierra la función
void Customer::talk(int minutes, Customer &other){ //Llama a la función con los parametros establecidos
	double price;
	if (minutes>0 && other.getId()!=id){
		price=op->calculateTalkingCost(minutes, age);
		if (bill->check(price)){
			bill->add(price);
			addTalkingTime(minutes);
			op->addTalkingTime(minutes);
			if (op->getId()!=other.op->getId()){
				other.op->addTalkingTime(minutes);
			}
		}
	}
} //Cierra la función
void Customer::message(int quantity, const Customer &other){ //Llama a la función con los parametros establecidos
	double price=0;
	if (quantity>0 && other.getId()!=id){
		price=op->calculateMessageCost(quantity, op->getId(), other.op->getId());
		if (bill->check(price)){
			bill->add(price);
			addTotalMessageSent(quantity);
			op->addTotalMessageSent(quantity);
		}
	}
} //Cierra la función
void Customer::connection(double amount){ //Llama a la función con los parametros establecidos
	double price=0;
	if (amount>0){
		price=op->calculateNetworkCost(amount);
		if (bill->check(price)){
			bill->add(price);
			addTotalInternetUsage(amount);
			op->addTotalInternetUsage(amount);
		}
	}
} //Cierra la función
void Customer::pay(double amount){ //Llama a la función con los parametros establecidos
	bill->pay(amount);
} //Cierra la función
string Customer::toString() const{ //Llama a la función con los parametros establecidos
	stringstream aux;
	aux<<"Customer "<<fixed<<getId()<<": "
	   <<fixed<<setprecision(2)<<bill->getTotalMoneySpent()<<" "
	   <<fixed<<setprecision(2)<<bill->getCurrentDebt()<<endl;
	return aux.str();
} //Cierra la función
#endif //Finaliza si la clase esta definida
//Fin del programa
