/*-----------------------
Bill
José Emiliano Riosmena Castañón
A01704245
------------------------*/
#ifndef BILL_H //Checha si el header está definido
#define BILL_H //Define la clase
using namespace std; //Permite utilizar atributos std

class Bill { //Crea una clase
private: //Crea la sección para variables privadas
  double limitAmount, currentDebt, totalMoneySpent; //Crea variables

public: //Crea la sección para variables públicas
  Bill(); //Crea un constructor por defecto
  Bill(double); //Crea un constructor
  Bill(const Bill&); //Crea un constructor de copia

  double getLimitAmount() const; //Crea una función getter
  double getCurrentDebt() const; //Crea una función getter
  double getTotalMoneySpent() const; //Crea una función getter

  void add(double); //Crea una función
  void pay(double); //Crea una función
  void changeTheLimit(double); //Crea una función
  bool check(double) const; //Crea una función
}; //Cierra la clase
Bill::Bill(){ //Llama al constructor por defecto
	limitAmount=0; //Guarda el valor en la variable
	currentDebt=0; //Guarda el valor en la variable
	totalMoneySpent=0; //Guarda el valor en la variable
} //Cierra la función
Bill::Bill(double lim){ //Llama al constructor con los parámetros establecidos
	if (lim<=0){ //Condicional si el limite es menor o igual a 0
		lim=0; //Guarda el valor en la variable
	} //Cierra la condicional
	limitAmount=lim; //Guarda el valor en la variable
	currentDebt=0; //Guarda el valor en la variable
	totalMoneySpent=0; //Guarda el valor en la variable
} //Cierra la función
Bill::Bill(const Bill &other){ //Llama al constructor de copia con los parámetros establecidos
	limitAmount=other.limitAmount; //Guarda el valor en la variable
	currentDebt=other.currentDebt; //Guarda el valor en la variable
	totalMoneySpent=other.totalMoneySpent; //Guarda el valor en la variable
} //Cierra la función
double Bill::getLimitAmount() const{ //Llama a la función
	return limitAmount; //Regresa el valor
} //Cierra la función
double Bill::getCurrentDebt() const{ //Llama a la función
	return currentDebt; //Regresa el valor
} //Cierra la función
double Bill::getTotalMoneySpent() const{ //Llama a la función
	return totalMoneySpent; //Regresa el valor
} //Cierra la función
void Bill::add(double amount){ //Llama a la función con los parámetros establecidos
	if (amount>0){ //Condicional si el monto es mayor a 0
		currentDebt+=amount; //Aumenta el valor en la variable
	} //Cierra la condicional
} //Cierra la función
void Bill::pay(double amount){ //Llama a la función con los parámetros establecidos
	if (amount>0){ //Condicional si el monto es mayor a 0
		if (amount>currentDebt){ //Condicional si el monto es mayor que la deuda actual
			amount=currentDebt; //Iguala las variables
		} //Cierra la condicional
		currentDebt-=amount; //Resta el valor a la variable
		totalMoneySpent+=amount; //Aumenta el valor en la variable
	} //Cierra la condicional
} //Cierra la función
void Bill::changeTheLimit(double amount){ //Llama a la función con los parámetros establecidos
	if (amount>0 || amount>currentDebt){ //Condicional si el monto es mayor a 0 o si el monto es mayor que la deuda actual
		limitAmount=amount; //Iguala las variables
	} //Cierra la condicional
} //Cierra la función
bool Bill::check(double amount) const{ //Llama a la función con los parámetros establecidos
	return (currentDebt+amount)<=limitAmount; //Regresa el valor
} //Cierra la función
#endif //Finaliza el header
//Fin del programa
