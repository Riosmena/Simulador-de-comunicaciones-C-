/*---------------------------
TC1030 Programación orientado a objetos
José Emiliano Riosmena Castañón
A01704245
Simulador de comunicaciones
----------------------------*/
#include <iostream> //Importa las entradas y salidas del programa
#include <string> //Importa los strings
#include <sstream> //Importa los stringstream
#include <iomanip> //Importa los manipuladores
#include <fstream> //Impora la entrada y salida de archivos
#include <vector> //Importa los vectores
#include "bill.h" //Importa la clase bill
#include "operator.h" //Importa la clase operator
#include "vox.h" //Importa la clase vox
#include "internet.h" //Importa la clase internet
#include "customer.h" //Importa la clase customer
using namespace std; //Permite utilizar atributos std

int main(int argc, char* argv[]) { //Crea la función principal con los atributos establecidos
	ifstream inputFile; //Crea un archivo de entrada
	ofstream outputFile; //Crea un archivo de salida
	int C, O, N, inst, age, idop, discountrate, id1, id2, minutes, quantity; //Crea variables
	double lim, talkingcharge, messagecost, networkcharge, amount; //Crea variables
	string name; //Crea una variable
	int type; //Crea una variable
	if (argc!=3){ //Condicional para abrir archivos
		cout<<"usage: "<<argv[0]<<"input_file output_file"<<endl; //Muestra el texto en la pantalla
		return -1; //Regresa -1
	} //Cierra la condicional
	inputFile.open(argv[1]); //Abre el archivo de entrada
	if(!inputFile.is_open()){ //Condicional si el archivo de entrada no esta abierto
		cout<<argv[0]<<": File  \""<<argv[1]<<"\" not found"<<endl; //Muestra el texto en la pantalla
		return -1; //Resgresa -1
	} //Cierra la condicional
	outputFile.open(argv[2]); //Abre el archivo de salida
	inputFile>>C>>O>>N; //Llama al archivo de entrada con las variables establecidas
	
	vector<Customer *> customers; //Crea un vector
	vector<Operator *> operators; //Crea un vector
	customers.resize(C); //Establece el tamaño del vector
	operators.resize(O); //Establece el tamaño del vector
	int opCount=0; //Crea una variable
	int customerCount=0; //Crea una variable
	for (int i=0;i<N;i++){ //Crea un ciclo for
		inputFile>>inst; //Llama al archivo de entrada con la variable establecida
		switch (inst){ //Genera un menú de posiblidades
			case 1: //Primer caso
				inputFile>>name>>age>>idop>>lim; //Llama al archivo de entrada con las variables establecidas
				customers.at(customerCount)=new Customer(customerCount, name, age, operators.at(idop),lim); //Crea un nuevo objeto con la clase establecida
				customerCount++; //Aumenta la variable en 1
				break; //Cierra el caso
			case 2: //Segundo caso
				inputFile>>type>>talkingcharge>>messagecost>>networkcharge>>discountrate; //Llama al archivo de entrada con las variables establecidas
				if (type==1){ //Condicional si el tipo operador es VOX
					operators.at(opCount)=new VoxOperator(opCount, talkingcharge, messagecost, networkcharge, discountrate, VOX); //Crea un nuevo objeto con la clase establecida
					opCount++; //Aumenta la variable en 1
				} //Cierra la condicional
				else if (type==2){ //Condicional si el tipo operador es INTERNET
					operators.at(opCount)=new InternetOperator(opCount, talkingcharge, messagecost, networkcharge, discountrate, INTERNET); //Crea un nuevo objeto con la clase establecida
					opCount++; //Aumenta la variable en 1
				} //Cierra la condicional
				break; //Cierra el caso 
			case 3: //Tercer caso
				inputFile>>id1>>id2>>minutes; //Llama al archivo de entrada con las variables establecidas
				customers.at(id1)->talk(minutes, *customers.at(id2)); //Crea un nuevo objeto con el apuntador establecido
				break; //Cierra el caso
			case 4: //Cuarto caso
				inputFile>>id1>>id2>>quantity; //Llama al archivo de entrada con las variables establecidas
				customers.at(id1)->message(quantity, *customers.at(id2)); //Crea un nuevo objeto con el apuntador establecido
				break; //Cierra el caso
			case 5: //Quinto caso
				inputFile>>id1>>amount; //Llama al archivo de entrada con las variables establecidas
				customers.at(id1)->connection(amount); //Crea un nuevo objeto con el apuntador establecido
				break; //Cierra el caso
			case 6: //Sexto caso
				inputFile>>id1>>amount; //Llama al archivo de entrada con las variables establecidas
				customers.at(id1)->pay(amount); //Crea un nuevo objeto con el apuntador establecido
				break; //Cierra el caso
			case 7: //Septimo caso
				inputFile>>id1>>idop; //Llama al archivo de entrada con las variables establecidas
				customers.at(id1)->setOperator(operators.at(idop)); //Crea un nuevo objeto con el apuntador establecido
				break; //Cierra el caso
			case 8: //Octavo caso
				inputFile>>id1>>lim; //Llama al archivo de entrada con las variables establecidas
				customers.at(id1)->getBill()->changeTheLimit(lim); //Crea un nuevo objeto con el apuntador establecido
			default: //Caso por defecto
				break; //Cierra el caso
		} //Cierra el switch
	} //Cierra el ciclo for
	vector<Operator *>::iterator itrop; //Crea un vector
	for (itrop=operators.begin();itrop!=operators.end();itrop++){ //Crea un ciclo for
		outputFile<<(*itrop)->toString(); //LLama el archivo de salida con el apuntador establecido
	} //Cierra el ciclo for
	
	int maxTime=0; //Crea una variable
	int maxMessages=0; //Crea una variable
	double maxConnection=0; //Crea una variable
	int idMaxTime=0; //Crea una variable
	int idMaxMessages=0; //Crea una variable
	int idMaxConnection=0; //Crea una variable
	
	vector<Customer *>::iterator itrc; //Crea un vector
	for (itrc=customers.begin();itrc!=customers.end();itrc++){ //Crea un ciclo for
		outputFile<<(*itrc)->toString(); //Llama al archivo de salida con el apuntador establecido
		if ((*itrc)->getTotalSpentTalkingTime()>maxTime){ //Condicional si el tiempo empleado en llamadas supera al tiempo máximo
			maxTime=(*itrc)->getTotalSpentTalkingTime(); //Llama a la función del apuntador
			idMaxTime=(*itrc)->getId(); //Llama a la función del apuntador
		} //Ciera la condicional
		if ((*itrc)->getTotalMessageSent()>maxMessages){ //Condicional si los mensajes enviados supera la cantidad máxima
			maxMessages=(*itrc)->getTotalMessageSent(); //Llama a la función del apuntador
			idMaxMessages=(*itrc)->getId(); //Llama a la función del apuntador
		} //Ciera la condicional
		if ((*itrc)->getTotalInternetUsage()>maxConnection){ //Condicional si uso total del interne supera la conexión máxima
			maxConnection=(*itrc)->getTotalInternetUsage(); //Llama a la función del apuntador
			idMaxConnection=(*itrc)->getId(); //Llama a la función del apuntador
		} //Ciera la condicional
	} //Ciera el ciclo for
	outputFile<<customers[idMaxTime]->getName()<<": " //Muestra el texto en el archivo
			  <<customers[idMaxTime]->getTotalSpentTalkingTime()<<endl; //Muestra el texto en el archivo
	outputFile<<fixed<<setprecision(2)<<customers[idMaxMessages]->getName()<<": " //Muestra el texto en el archivo
			  <<customers[idMaxMessages]->getTotalMessageSent()<<endl; //Muestra el texto en el archivo
	outputFile<<fixed<<setprecision(2)<<customers[idMaxConnection]->getName()<<": " //Muestra el texto en el archivo
			  <<customers[idMaxConnection]->getTotalInternetUsage()<<endl; //Muestra el texto en el archivo
	
	for (int i=0;i<customers.size();i++){ //Crea un ciclo for
		delete customers[i]; //Borra los apuntadores de customers
	} //Cierra el ciclo for
	for (int i=0;i<operators.size();i++){ //Crea un ciclo for
		delete operators[i]; //Borra los apuntadores de operators
	} //Cierra el ciclo for
	customers.clear(); //Borra el arreglo
	operators.clear(); //Borra el arreglo
	inputFile.close(); //Cierra el archivo de entrada
	outputFile.close();	 //Cierra el archivo de salida
	return 0; //Regresa 0
} //Cierra la función principal
//Fin del programa
