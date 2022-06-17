/*-----------------------
Vox
Jos� Emiliano Riosmena Casta��n
A01704245
------------------------*/
#ifndef VOXOPERATOR_H //Checha si el header est� definido
#define VOXOPERATOR_H //Define la clase

#include "operator.h" //Importa la clase operator
using namespace std; //Permite utilizar atributos std

class VoxOperator : public Operator { //Crea una clase tomando la secci�n publica de la clase operator
public: //Crea la secci�n para variables p�blicas
  VoxOperator(int, double, double, double, int, OperatorType); //Crea un constructor
  VoxOperator(const VoxOperator&); //Crea un constructor de copia

  double calculateTalkingCost(int, int); //Crea una funci�n
  double calculateMessageCost(int, int, int); //Crea una funci�n
  double calculateNetworkCost(double); //Crea una funci�n
}; //Cierra la clase
VoxOperator::VoxOperator(int i, double tc, double mc, double nc, int dr, OperatorType t) //Llama al constructor con los par�metros establecidos
	: Operator(i,tc,mc,nc,dr,t){ //Invoca a las variables de la clase operator
} //Cierra la funci�n
VoxOperator::VoxOperator(const VoxOperator &other) //Llama al constructor de copia con los par�metros establecidos
	: Operator(other){ //Invoca a las variables de la clase operator	
} //Cierra la funci�n
double VoxOperator::calculateTalkingCost(int minute, int age){ //Llama a la funci�n con los par�metros establecidos
	double price=0; //Crea una variable
	if (minute>0 && age>0){ //Condicional si los minutos y la edad son mayores a 0
		price=minute*talkingCharge; //Realiza la operaci�n
		if (age<18 || age>65){ //Condicional si la edad es menor que 18 o mayor que 65
			price-=price*discountRate/100; //Resta el valor a la variable
		} //Cierra la condicional
	} //Cierra la condicional
	return price; //Regresa el valor
} //Cierra la funci�n
double VoxOperator::calculateMessageCost(int quantity, int thisOpId, int otherOpId){ //Llama a la funci�n con los par�metros establecidos
	double price=0; //Crea una variable
	if (quantity>0){ //Condicional si la cantidad de mensajes enviados es mayor a 0
		price=quantity*messageCost; //Realiza la operaci�n
		if(thisOpId==otherOpId){ //Condicional si el id original es igual al id de copia
			price-=price*discountRate/100; //Resta el valor a la variable
		} //Cierra la condicional
	} //Cierra la condicional
	return price; //Regresa el valor
} //Cierra la funci�n
double VoxOperator::calculateNetworkCost(double amount){ //Llama a la funci�n con los par�metros establecidos
	double price=0; //Crea una variable
	if (amount>0){ //Condicional si el monto es mayor a 0
		price=amount*networkCharge;	//Realiza la operaci�n
	} //Cierra la condicional
	return price; //Regresa el valor
} //Cierra la funci�n
#endif //Finaliza el header
//Fin del programa
