/*---------------------------
TC1030 Programación orientado a objetos
José Emiliano Riosmena Castañón
A01704245
Simulador de comunicaciones
----------------------------*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bill.h"
#include "operator.h"
#include "vox.h"
#include "internet.h"
#include "customer.h"
using namespace std;

int main(int argc, char* argv[]) {
	ifstream inputFile;
	ofstream outputFile;
	int C, O, N, inst, age, idop, discountrate, id1, id2, minutes, quantity;
	double lim, talkingcharge, messagecost, networkcharge, amount;
	string name;
	int type;
	if (argc!=3){
		cout<<"usage: "<<argv[0]<<"input_file output_file"<<endl;
		return -1;
	}
	inputFile.open(argv[1]);
	if(!inputFile.is_open()){
		cout<<argv[0]<<": File  \""<<argv[1]<<"\" not found"<<endl;
		return -1;
	}
	outputFile.open(argv[2]);
	inputFile>>C>>O>>N;
	
	vector<Customer *> customers;
	vector<Operator *> operators;
	customers.resize(C);
	operators.resize(O);
	int opCount=0;
	int customerCount=0;
	for (int i=0;i<N;i++){
		inputFile>>inst;
		switch (inst){
			case 1:
				inputFile>>name>>age>>idop>>lim;
				customers.at(customerCount)=new Customer(customerCount, name, age, operators.at(idop),lim);
				customerCount++;
				break;
			case 2:
				inputFile>>type>>talkingcharge>>messagecost>>networkcharge>>discountrate;
				if (type==1){
					operators.at(opCount)=new VoxOperator(opCount, talkingcharge, messagecost, networkcharge, discountrate, VOX);
					opCount++;
				}
				else if (type==2){
					operators.at(opCount)=new InternetOperator(opCount, talkingcharge, messagecost, networkcharge, discountrate, INTERNET);
					opCount++;
				}
				break;
			case 3:
				inputFile>>id1>>id2>>minutes;
				customers.at(id1)->talk(minutes, *customers.at(id2));
				break;
			case 4:
				inputFile>>id1>>id2>>quantity;
				customers.at(id1)->message(quantity, *customers.at(id2));
				break;
			case 5:
				inputFile>>id1>>amount;
				customers.at(id1)->connection(amount);
				break;
			case 6:
				inputFile>>id1>>amount;
				customers.at(id1)->pay(amount);
				break;
			case 7:
				inputFile>>id1>>idop;
				customers.at(id1)->setOperator(operators.at(idop));
				break;
			case 8:
				inputFile>>id1>>lim;
				customers.at(id1)->getBill()->changeTheLimit(lim);
			default:
				break;
		}
	}
	vector<Operator *>::iterator itrop;
	for (itrop=operators.begin();itrop!=operators.end();itrop++){
		outputFile<<(*itrop)->toString();
	}
	
	int maxTime=0;
	int maxMessages=0;
	double maxConnection=0;
	int idMaxTime=0;
	int idMaxMessages=0;
	int idMaxConnection=0;
	
	vector<Customer *>::iterator itrc;
	for (itrc=customers.begin();itrc!=customers.end();itrc++){
		outputFile<<(*itrc)->toString();
		if ((*itrc)->getTotalSpentTalkingTime()>maxTime){
			maxTime=(*itrc)->getTotalSpentTalkingTime();
			idMaxTime=(*itrc)->getId();
		}
		if ((*itrc)->getTotalMessageSent()>maxMessages){
			maxMessages=(*itrc)->getTotalMessageSent();
			idMaxMessages=(*itrc)->getId();
		}
		if ((*itrc)->getTotalInternetUsage()>maxConnection){
			maxConnection=(*itrc)->getTotalInternetUsage();
			idMaxConnection=(*itrc)->getId();
		}
	}
	outputFile<<customers[idMaxTime]->getName()<<": "
			  <<customers[idMaxTime]->getTotalSpentTalkingTime()<<endl;
	outputFile<<fixed<<setprecision(2)<<customers[idMaxMessages]->getName()<<": "
			  <<customers[idMaxMessages]->getTotalMessageSent()<<endl;
	outputFile<<fixed<<setprecision(2)<<customers[idMaxConnection]->getName()<<": "
			  <<customers[idMaxConnection]->getTotalInternetUsage()<<endl;
	
	for (int i=0;i<customers.size();i++){
		delete customers[i];
	}
	for (int i=0;i<operators.size();i++){
		delete operators[i];
	}
	customers.clear();
	operators.clear();
	inputFile.close();
	outputFile.close();	
}
