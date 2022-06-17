/*-----------------------
Customer
Jos� Emiliano Riosmena Casta��n
A01704245
------------------------*/
#ifndef CUSTOMER_H //Checha si la clase est� definida
#define CUSTOMER_H //Define la clase

#include <string> //Importa los strings
#include <sstream> //Importa los stringstream
#include <iomanip> //Importa los manipuladores
#include "bill.h" //Importa la clase bill
#include "operator.h" //Importa la clase operator
using namespace std; //Permite utilizar atributos std

class Customer { //Crea una clase
private: //Crea la secci�n para variables privadas
  int id, age, totalSpentTalkingTime, totalMessageSent, totalInternetUsage; //Crea variables
  string name; //Crea una variable
  Operator* op; //Crea un apuntador
  Bill *bill; //Crea un apuntador

public: //Crea la secci�n para variables p�blicas
  Customer(int, string, int, Operator*, double); //Crea un constructor
  Customer(const Customer&); //Crea un constructor de copia
  ~Customer(); //Crea un destructor

  int getId() const; //Crea una funci�n getter
  int getAge() const; //Crea una funci�n getter
  int getTotalSpentTalkingTime() const; //Crea una funci�n getter
  int getTotalMessageSent() const; //Crea una funci�n getter
  double getTotalInternetUsage() const; //Crea una funci�n getter
  string getName() const; //Crea una funci�n getter
  Operator* getOperator() const; //Crea una funci�n getter
  Bill* getBill() const; //Crea una funci�n getter
  
  void addTalkingTime(int); //Crea una funci�n
  void addTotalMessageSent(int); //Crea una funci�n
  void addTotalInternetUsage(double); //Crea una funci�n
  void setOperator(Operator*); //Crea una funci�n setter

  string toString() const; //Crea una funci�n

  void talk (int, Customer&); //Crea una funci�n
  void message(int, const Customer&); //Crea una funci�n
  void connection(double); //Crea una funci�n
  void pay(double); //Crea una funci�n
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
} //Cierra la funci�n
Customer::Customer(const Customer &other){ //Llama al constructor de copia con los parametros establecidos
	id=other.id; //Guarda el valor en la variable
	name=other.name; //Guarda el valor en la variable
	age=other.age; //Guarda el valor en la variable
	op=other.op; //Guarda el valor en la variable
	bill=other.bill; //Guarda el valor en la variable
	totalSpentTalkingTime=other.totalSpentTalkingTime; //Guarda el valor en la variable
	totalMessageSent=other.totalMessageSent; //Guarda el valor en la variable
	totalInternetUsage=other.totalInternetUsage; //Guarda el valor en la variable
} //Cierra la funci�n
Customer::~Customer(){ //Llama al destructor
	delete bill; //Borra el apuntador
	bill=NULL; //Anula el apuntador
	op=NULL; //Anula el apuntador
} //Cierra la funci�n
int Customer::getId() const{ //Llama a la funci�n
	return id; //Regresa el valor
} //Cierra la funci�n
int Customer::getAge() const{ //Llama a la funci�n
	return age; //Regresa el valor
} //Cierra la funci�n
int Customer::getTotalSpentTalkingTime() const{ //Llama a la funci�n
	return totalSpentTalkingTime; //Regresa el valor
} //Cierra la funci�n
int Customer::getTotalMessageSent() const{ //Llama a la funci�n
	return totalMessageSent; //Regresa el valor
} //Cierra la funci�n
double Customer::getTotalInternetUsage() const{ //Llama a la funci�n
	return totalInternetUsage; //Regresa el valor
} //Cierra la funci�n
string Customer::getName() const{ //Llama a la funci�n
	return name; //Regresa el valor
} //Cierra la funci�n
Operator* Customer::getOperator() const{ //Llama a la funci�n
	return op; //Regresa el valor
} //Cierra la funci�n
Bill* Customer::getBill() const{ //Llama a la funci�n
	return bill; //Regresa el valor
} //Cierra la funci�n
void Customer::addTalkingTime(int minute){ //Llama a la funci�n con los parametros establecidos
	if (minute>0){
		totalSpentTalkingTime+=minute;
	}
} //Cierra la funci�n
void Customer::addTotalMessageSent(int mc){ //Llama a la funci�n con los parametros establecidos
	if (mc>0){ //Condicional si los mensajes son mayores a 0
		totalMessageSent+=mc; //Agrega el valor a la variable
	} //Cierra la condicional
} //Cierra la funci�n
void Customer::addTotalInternetUsage(double amount){ //Llama a la funci�n con los parametros establecidos
	if (amount>0){
		totalInternetUsage+=amount;
	}
} //Cierra la funci�n
void Customer::setOperator(Operator *o){ //Llama a la funci�n con los parametros establecidos
	op=o;
} //Cierra la funci�n
void Customer::talk(int minutes, Customer &other){ //Llama a la funci�n con los parametros establecidos
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
} //Cierra la funci�n
void Customer::message(int quantity, const Customer &other){ //Llama a la funci�n con los parametros establecidos
	double price=0;
	if (quantity>0 && other.getId()!=id){
		price=op->calculateMessageCost(quantity, op->getId(), other.op->getId());
		if (bill->check(price)){
			bill->add(price);
			addTotalMessageSent(quantity);
			op->addTotalMessageSent(quantity);
		}
	}
} //Cierra la funci�n
void Customer::connection(double amount){ //Llama a la funci�n con los parametros establecidos
	double price=0;
	if (amount>0){
		price=op->calculateNetworkCost(amount);
		if (bill->check(price)){
			bill->add(price);
			addTotalInternetUsage(amount);
			op->addTotalInternetUsage(amount);
		}
	}
} //Cierra la funci�n
void Customer::pay(double amount){ //Llama a la funci�n con los parametros establecidos
	bill->pay(amount);
} //Cierra la funci�n
string Customer::toString() const{ //Llama a la funci�n con los parametros establecidos
	stringstream aux;
	aux<<"Customer "<<fixed<<getId()<<": "
	   <<fixed<<setprecision(2)<<bill->getTotalMoneySpent()<<" "
	   <<fixed<<setprecision(2)<<bill->getCurrentDebt()<<endl;
	return aux.str();
} //Cierra la funci�n
#endif //Finaliza si la clase esta definida
//Fin del programa
