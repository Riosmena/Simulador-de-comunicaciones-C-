/*-----------------------
Vox
José Emiliano Riosmena Castañón
A01704245
------------------------*/
#ifndef VOXOPERATOR_H //Checha si el header está definido
#define VOXOPERATOR_H //Define la clase

#include "operator.h" //Importa la clase operator
using namespace std; //Permite utilizar atributos std

class VoxOperator : public Operator { //Crea una clase tomando la sección publica de la clase operator
public: //Crea la sección para variables públicas
  VoxOperator(int, double, double, double, int, OperatorType); //Crea un constructor
  VoxOperator(const VoxOperator&); //Crea un constructor de copia

  double calculateTalkingCost(int, int); //Crea una función
  double calculateMessageCost(int, int, int); //Crea una función
  double calculateNetworkCost(double); //Crea una función
}; //Cierra la clase
VoxOperator::VoxOperator(int i, double tc, double mc, double nc, int dr, OperatorType t) //Llama al constructor con los parámetros establecidos
	: Operator(i,tc,mc,nc,dr,t){ //Invoca a las variables de la clase operator
} //Cierra la función
VoxOperator::VoxOperator(const VoxOperator &other) //Llama al constructor de copia con los parámetros establecidos
	: Operator(other){ //Invoca a las variables de la clase operator	
} //Cierra la función
double VoxOperator::calculateTalkingCost(int minute, int age){ //Llama a la función con los parámetros establecidos
	double price=0; //Crea una variable
	if (minute>0 && age>0){ //Condicional si los minutos y la edad son mayores a 0
		price=minute*talkingCharge; //Realiza la operación
		if (age<18 || age>65){ //Condicional si la edad es menor que 18 o mayor que 65
			price-=price*discountRate/100; //Resta el valor a la variable
		} //Cierra la condicional
	} //Cierra la condicional
	return price; //Regresa el valor
} //Cierra la función
double VoxOperator::calculateMessageCost(int quantity, int thisOpId, int otherOpId){ //Llama a la función con los parámetros establecidos
	double price=0; //Crea una variable
	if (quantity>0){ //Condicional si la cantidad de mensajes enviados es mayor a 0
		price=quantity*messageCost; //Realiza la operación
		if(thisOpId==otherOpId){ //Condicional si el id original es igual al id de copia
			price-=price*discountRate/100; //Resta el valor a la variable
		} //Cierra la condicional
	} //Cierra la condicional
	return price; //Regresa el valor
} //Cierra la función
double VoxOperator::calculateNetworkCost(double amount){ //Llama a la función con los parámetros establecidos
	double price=0; //Crea una variable
	if (amount>0){ //Condicional si el monto es mayor a 0
		price=amount*networkCharge;	//Realiza la operación
	} //Cierra la condicional
	return price; //Regresa el valor
} //Cierra la función
#endif //Finaliza el header
//Fin del programa
