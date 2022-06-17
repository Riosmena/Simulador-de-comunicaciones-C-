/*-----------------------
Operador
Jos� Emiliano Riosmena Casta��n
A01704245
------------------------*/
#ifndef OPERATOR_H //Checha si el header est� definido
#define OPERATOR_H //Define la clase

#include <string> //Importa los strings
#include <sstream> //Importa los stringstream
#include <iomanip> //Importa los manipuladores
using namespace std; //Permite utilizar atributos std

typedef enum{VOX, INTERNET} OperatorType; //Crea nuevos tipos de variables

class Operator { //Crea una clase
protected: //Crea la secci�n para las variables protegidas
  int id, discountRate; //Crea variables
  double talkingCharge, messageCost, networkCharge, totalInternetUsage; //Crea variables
  int totalSpentTalkingTime, totalMessageSent; //Crea variables
  OperatorType type; //Crea una variable

public: //Crea la secci�n para las variables p�blicas
  Operator(int, double, double, double, int, OperatorType); //Crea un constructor
  Operator(const Operator&); //Crea un constructor de copia

  int getId() const; //Crea una funci�n getter
  int getDiscountRate() const; //Crea una funci�n getter
  double getTalkingChage() const; //Crea una funci�n getter
  double getMessageCost() const; //Crea una funci�n getter
  double getNetworkCharge() const; //Crea una funci�n getter
  int getTotalSpentTalkingTime() const; //Crea una funci�n getter
  int getTotalMessageSent() const; //Crea una funci�n getter
  double getTotalInternetUsage() const; //Crea una funci�n getter
  OperatorType getType() const; //Crea una funci�n getter

  void addTalkingTime(int); //Crea una funci�n
  void addTotalMessageSent(int); //Crea una funci�n
  void addTotalInternetUsage(double); //Crea una funci�n

  string toString() const; //Crea una funci�n

  virtual double calculateTalkingCost(int, int) = 0; //Crea una funci�n virtual
  virtual double calculateMessageCost(int, int, int) = 0; //Crea una funci�n virtual
  virtual double calculateNetworkCost(double) = 0; //Crea una funci�n virtual
}; //Cierra la clase
Operator::Operator(int i, double tc, double mc, double nc, int dr, OperatorType t){ //Llama al constructor con los par�metros establecidos
	id=i; //Guarda el valor en la variable
	discountRate=dr; //Guarda el valor en la variable
	talkingCharge=tc; //Guarda el valor en la variable
	messageCost=mc; //Guarda el valor en la variable
	networkCharge=nc; //Guarda el valor en la variable
	type=t; //Guarda el valor en la variable
	totalInternetUsage=0; //Guarda el valor en la variable
	totalSpentTalkingTime=0; //Guarda el valor en la variable
	totalMessageSent=0; //Guarda el valor en la variable
} //Cierra la funci�n
Operator::Operator(const Operator &other){ //Llama al constructor de copia con los par�metros establecidos
	id=other.id; //Guarda el valor en la variable
	discountRate=other.discountRate; //Guarda el valor en la variable
	talkingCharge=other.talkingCharge; //Guarda el valor en la variable
	messageCost=other.messageCost; //Guarda el valor en la variable
	networkCharge=other.networkCharge; //Guarda el valor en la variable
	totalInternetUsage=other.totalInternetUsage; //Guarda el valor en la variable
	totalSpentTalkingTime=other.totalSpentTalkingTime; //Guarda el valor en la variable
	totalMessageSent=other.totalMessageSent; //Guarda el valor en la variable
	type=other.type; //Guarda el valor en la variable
} //Cierra la funci�n
int Operator::getId() const{ //Llama a la funci�n
	return id; //Regresa el valor
} //Cierra la funci�n
int Operator::getDiscountRate() const{ //Llama a la funci�n
	return discountRate; //Regresa el valor
} //Cierra la funci�n
double Operator::getTalkingChage() const{ //Llama a la funci�n
	return talkingCharge; //Regresa el valor
} //Cierra la funci�n
double Operator::getMessageCost() const{ //Llama a la funci�n
	return messageCost; //Regresa el valor
} //Cierra la funci�n
double Operator::getNetworkCharge() const{ //Llama a la funci�n
	return networkCharge; //Regresa el valor
} //Cierra la funci�n
int Operator::getTotalSpentTalkingTime() const{ //Llama a la funci�n
	return totalSpentTalkingTime; //Regresa el valor
} //Cierra la funci�n
int Operator::getTotalMessageSent() const{ //Llama a la funci�n
	return totalMessageSent; //Regresa el valor
} //Cierra la funci�n
double Operator::getTotalInternetUsage() const{ //Llama a la funci�n
	return totalInternetUsage; //Regresa el valor
} //Cierra la funci�n
OperatorType Operator::getType() const{ //Llama a la funci�n
	return type; //Regresa el valor
} //Cierra la funci�n
void Operator::addTalkingTime(int minute){ //Llama a la funci�n con los par�metros establecidos
	if (minute>0){ //Condicional si los minutos son mayores a 0
		totalSpentTalkingTime+=minute; //Agrega el valor a la variable
	} //Cierra la condicional
} //Cierra la funci�n
void Operator::addTotalMessageSent(int mc){ //Llama a la funci�n con los par�metros establecidos
	if (mc>0){ //Condicional si los mensajes son mayores a 0
		totalMessageSent+=mc; //Agrega el valor a la variable
	} //Cierra la condicional
} //Cierra la funci�n
void Operator::addTotalInternetUsage(double amount){ //Llama a la funci�n con los par�metros establecidos
	if (amount>0){ //Condicional si el monto es mayor a 0
		totalInternetUsage+=amount; //Agrega el valor a la variable
	} //Cierra la condicional
} //Cierra la funci�n
string Operator::toString() const{ //Llama a la funci�n con los par�metros establecidos
	stringstream aux; //Crea una variable de salida
	aux<<"Operator "<<fixed<<getId()<<": " //Muestra el texto en la pantalla
	   <<fixed<<getTotalSpentTalkingTime()<<" " //Muestra el texto en la pantalla
	   <<fixed<<getTotalMessageSent()<<" " //Muestra el texto en la pantalla
	   <<fixed<<setprecision(2)<<getTotalInternetUsage()<<endl; //Muestra el texto en la pantalla
	return aux.str(); //Regresa la variable
} //Cierra la funci�n
#endif //Finaliza el header
//Fin del programa
