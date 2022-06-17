/*-----------------------
Customer
Jos� Emiliano Riosmena Casta��n
A01704245
------------------------*/
#ifndef CUSTOMER_H //Checha si el header est� definido
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
	if (minute>0){ //Condicional si los minutos son mayores a 0
		totalSpentTalkingTime+=minute; //Agrega el valor a la variable
	} //Cierra la condicional
} //Cierra la funci�n
void Customer::addTotalMessageSent(int mc){ //Llama a la funci�n con los parametros establecidos
	if (mc>0){ //Condicional si los mensajes son mayores a 0
		totalMessageSent+=mc; //Agrega el valor a la variable
	} //Cierra la condicional
} //Cierra la funci�n
void Customer::addTotalInternetUsage(double amount){ //Llama a la funci�n con los parametros establecidos
	if (amount>0){ //Condicional si el monto es mayor a 0
		totalInternetUsage+=amount; //Agrega el valor a la variable
	} //Cierra la condicional
} //Cierra la funci�n
void Customer::setOperator(Operator *o){ //Llama a la funci�n con los parametros establecidos
	op=o; //Guarda el valor en la variables
} //Cierra la funci�n
void Customer::talk(int minutes, Customer &other){ //Llama a la funci�n con los parametros establecidos
	double price; //Crea una variable
	if (minutes>0 && other.getId()!=id){ //Condicional si los minutos son mayores a 0 y si el otro id es diferente al original
		price=op->calculateTalkingCost(minutes, age); //LLama a la funci�n del apuntador
		if (bill->check(price)){ //Condicional si hay l�mite de cr�dito
			bill->add(price); //Llama a ala funci�n del apuntador
			addTalkingTime(minutes); //Llama a la funci�n con los par�metros establecidos
			op->addTalkingTime(minutes); //Llama a la funci�n del apuntador
			if (op->getId()!=other.op->getId()){ //Condicional para si los usuarios son diferentes
				other.op->addTalkingTime(minutes); //Llama a la funci�n del apuntador
			} //Cierra la condicional
		} //Cierra la condicional
	} //Cierra la condicional
} //Cierra la funci�n
void Customer::message(int quantity, const Customer &other){ //Llama a la funci�n con los parametros establecidos
	double price=0; //Crea una variable
	if (quantity>0 && other.getId()!=id){ //Condicional si la cantidad de mensajes es mayor a 0 y si el otro id es diferente al original
		price=op->calculateMessageCost(quantity, op->getId(), other.op->getId()); //Llama a la funci�n del apuntador
		if (bill->check(price)){ //Condicional si hay limite de cr�dito
			bill->add(price); //Llama a la funci�n del apuntador
			addTotalMessageSent(quantity); //Llama a la funci�n con los par�metros establecidos
			op->addTotalMessageSent(quantity); //Llama a la funci�n del apuntador
		} //Cierra la condicional
	} //Cierra la condicional
} //Cierra la funci�n
void Customer::connection(double amount){ //Llama a la funci�n con los parametros establecidos
	double price=0; //Crea una variable
	if (amount>0){ //Condicional si el monto es mayor a 0
		price=op->calculateNetworkCost(amount); //Llama a la funci�n del apuntador
		if (bill->check(price)){ //Condicional si hay l�mite de cr�dito
			bill->add(price); //Llama a la funci�n del apuntador
			addTotalInternetUsage(amount); //Llama a la funci�n con los par�metros establecidos
			op->addTotalInternetUsage(amount); //Llama a la funci�n del apuntador
		} //Cierra la condicional
	} //Cierra la condicional
} //Cierra la funci�n
void Customer::pay(double amount){ //Llama a la funci�n con los parametros establecidos
	bill->pay(amount); //Llama ala funci�n del apuntador
} //Cierra la funci�n
string Customer::toString() const{ //Llama a la funci�n con los parametros establecidos
	stringstream aux; //Crea una variable de salida
	aux<<"Customer "<<fixed<<getId()<<": " //Muestra el texto en la pantalla
	   <<fixed<<setprecision(2)<<bill->getTotalMoneySpent()<<" " //Muestra el texto en la pantalla
	   <<fixed<<setprecision(2)<<bill->getCurrentDebt()<<endl; //Muestra el texto en la pantalla
	return aux.str(); //Regresa la variable
} //Cierra la funci�n
#endif //Finaliza el header
//Fin del programa
