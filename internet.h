/*-----------------------
Internet
José Emiliano Riosmena Castañón
A01704245
------------------------*/
#ifndef InternetOperator_H //Checha si el header está definido
#define InternetOperator_H //Define la clase

#include "operator.h" //Importa la clase operator
using namespace std; //Permite utilizar atributos std

class InternetOperator : public Operator { //Crea una clase tomando la sección publica de la clase operator
private: //Crea la sección para variables privadas
  const double LIMITGB = 1.0; //Crea una constante

public: //Crea la sección para variables públicas
  InternetOperator(int, double, double, double, int, OperatorType); //Crea un constructor
  InternetOperator(const InternetOperator&); //Crea un constructor de copia

  double calculateTalkingCost(int, int); //Crea una función
  double calculateMessageCost(int, int, int); //Crea una función
  double calculateNetworkCost(double); //Crea una función
}; //Cierra la clase
InternetOperator::InternetOperator(int i, double tc, double mc, double nc, int dr, OperatorType t) //Llama al constructor con los parámetros establecidos
	: Operator(i,tc,mc,nc,dr,t){ //Invoca a las variables de la clase operator
} //Cierra la función
InternetOperator::InternetOperator(const InternetOperator &other) //Llama al constructor de copia con los parámetros establecidos
	: Operator(other){ //Invoca a las variables de la valse operator
} //Cierra la función
double InternetOperator::calculateTalkingCost(int minute, int age){ //Llama a la función con los parámetros establecidos
	double price=0; //Crea una variable
	if (minute>0 && age>0){ //Condicional si los minutos y la edad son mayores a 0
		price=minute*talkingCharge; //Realiza la operación
		if (minute<2){ //Condicional si los minutos son menores a 2
			price-=price*discountRate/100; //Resta el valor a la variable
		} //Cierra la condicional
	} //Cierra la condicional
	return price; //Regresa el valor
} //Cierra la función
double InternetOperator::calculateMessageCost(int quantity, int thisOpId, int otherOpId){ //Llama a la función con los parámetros establecidos
	double price=0; //Crea una variable
	if (quantity>0){ //Condicional si la cantidad de mensajes es mayor a 0
		price=quantity*messageCost; //Realiza la operación
		if (quantity<3){ //Condicional si la cantidad de mensajes es menor a 3
			price-=price*discountRate/100; //Resta el valor a la variable
		} //Cierra la condicional
	} //Cierra la condicional
	return price; //Regresa el valor
} //Cierra la función
double InternetOperator::calculateNetworkCost(double amount){ //Llama a la función con los parámetros establecidos
  double price=0; //Crea una variable
  if (amount>LIMITGB){ //Condiconal si el monto es mayor al límite de GB
    price=(amount-LIMITGB)*networkCharge; //Realiza la operación
  } //Cierra la condicional
  return price; //Regresa el valor
} //Cierra la función
#endif //Finaliza el header
//Fin del programa
