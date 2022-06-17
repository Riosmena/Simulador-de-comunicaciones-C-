/*-----------------------
Operador
José Emiliano Riosmena Castañón
A01704245
------------------------*/
#ifndef OPERATOR_H //Checha si el header está definido
#define OPERATOR_H //Define la clase

#include <string> //Importa los strings
#include <sstream> //Importa los stringstream
#include <iomanip> //Importa los manipuladores
using namespace std; //Permite utilizar atributos std

typedef enum{VOX, INTERNET} OperatorType; //Crea nuevos tipos de variables

class Operator { //Crea una clase
protected: //Crea la sección para las variables protegidas
  int id, discountRate; //Crea variables
  double talkingCharge, messageCost, networkCharge, totalInternetUsage; //Crea variables
  int totalSpentTalkingTime, totalMessageSent; //Crea variables
  OperatorType type; //Crea una variable

public: //Crea la sección para las variables públicas
  Operator(int, double, double, double, int, OperatorType); //Crea un constructor
  Operator(const Operator&); //Crea un constructor de copia

  int getId() const; //Crea una función getter
  int getDiscountRate() const; //Crea una función getter
  double getTalkingChage() const; //Crea una función getter
  double getMessageCost() const; //Crea una función getter
  double getNetworkCharge() const; //Crea una función getter
  int getTotalSpentTalkingTime() const; //Crea una función getter
  int getTotalMessageSent() const; //Crea una función getter
  double getTotalInternetUsage() const; //Crea una función getter
  OperatorType getType() const; //Crea una función getter

  void addTalkingTime(int); //Crea una función
  void addTotalMessageSent(int); //Crea una función
  void addTotalInternetUsage(double); //Crea una función

  string toString() const; //Crea una función

  virtual double calculateTalkingCost(int, int) = 0; //Crea una función virtual
  virtual double calculateMessageCost(int, int, int) = 0; //Crea una función virtual
  virtual double calculateNetworkCost(double) = 0; //Crea una función virtual
}; //Cierra la clase
Operator::Operator(int i, double tc, double mc, double nc, int dr, OperatorType t){ //Llama al constructor con los parámetros establecidos
	id=i; //Guarda el valor en la variable
	discountRate=dr; //Guarda el valor en la variable
	talkingCharge=tc; //Guarda el valor en la variable
	messageCost=mc; //Guarda el valor en la variable
	networkCharge=nc; //Guarda el valor en la variable
	type=t; //Guarda el valor en la variable
	totalInternetUsage=0; //Guarda el valor en la variable
	totalSpentTalkingTime=0; //Guarda el valor en la variable
	totalMessageSent=0; //Guarda el valor en la variable
} //Cierra la función
Operator::Operator(const Operator &other){ //Llama al constructor de copia con los parámetros establecidos
	id=other.id; //Guarda el valor en la variable
	discountRate=other.discountRate; //Guarda el valor en la variable
	talkingCharge=other.talkingCharge; //Guarda el valor en la variable
	messageCost=other.messageCost; //Guarda el valor en la variable
	networkCharge=other.networkCharge; //Guarda el valor en la variable
	totalInternetUsage=other.totalInternetUsage; //Guarda el valor en la variable
	totalSpentTalkingTime=other.totalSpentTalkingTime; //Guarda el valor en la variable
	totalMessageSent=other.totalMessageSent; //Guarda el valor en la variable
	type=other.type; //Guarda el valor en la variable
} //Cierra la función
int Operator::getId() const{ //Llama a la función
	return id; //Regresa el valor
} //Cierra la función
int Operator::getDiscountRate() const{ //Llama a la función
	return discountRate; //Regresa el valor
} //Cierra la función
double Operator::getTalkingChage() const{ //Llama a la función
	return talkingCharge; //Regresa el valor
} //Cierra la función
double Operator::getMessageCost() const{ //Llama a la función
	return messageCost; //Regresa el valor
} //Cierra la función
double Operator::getNetworkCharge() const{ //Llama a la función
	return networkCharge; //Regresa el valor
} //Cierra la función
int Operator::getTotalSpentTalkingTime() const{ //Llama a la función
	return totalSpentTalkingTime; //Regresa el valor
} //Cierra la función
int Operator::getTotalMessageSent() const{ //Llama a la función
	return totalMessageSent; //Regresa el valor
} //Cierra la función
double Operator::getTotalInternetUsage() const{ //Llama a la función
	return totalInternetUsage; //Regresa el valor
} //Cierra la función
OperatorType Operator::getType() const{ //Llama a la función
	return type; //Regresa el valor
} //Cierra la función
void Operator::addTalkingTime(int minute){ //Llama a la función con los parámetros establecidos
	if (minute>0){ //Condicional si los minutos son mayores a 0
		totalSpentTalkingTime+=minute; //Agrega el valor a la variable
	} //Cierra la condicional
} //Cierra la función
void Operator::addTotalMessageSent(int mc){ //Llama a la función con los parámetros establecidos
	if (mc>0){ //Condicional si los mensajes son mayores a 0
		totalMessageSent+=mc; //Agrega el valor a la variable
	} //Cierra la condicional
} //Cierra la función
void Operator::addTotalInternetUsage(double amount){ //Llama a la función con los parámetros establecidos
	if (amount>0){ //Condicional si el monto es mayor a 0
		totalInternetUsage+=amount; //Agrega el valor a la variable
	} //Cierra la condicional
} //Cierra la función
string Operator::toString() const{ //Llama a la función con los parámetros establecidos
	stringstream aux; //Crea una variable de salida
	aux<<"Operator "<<fixed<<getId()<<": " //Muestra el texto en la pantalla
	   <<fixed<<getTotalSpentTalkingTime()<<" " //Muestra el texto en la pantalla
	   <<fixed<<getTotalMessageSent()<<" " //Muestra el texto en la pantalla
	   <<fixed<<setprecision(2)<<getTotalInternetUsage()<<endl; //Muestra el texto en la pantalla
	return aux.str(); //Regresa la variable
} //Cierra la función
#endif //Finaliza el header
//Fin del programa
