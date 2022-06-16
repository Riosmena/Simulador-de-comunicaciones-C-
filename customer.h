/*-----------------------
Customer
José Emiliano Riosmena Castañón
A01704245
------------------------*/
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <sstream>
#include <iomanip>
#include "bill.h"
#include "operator.h"
using namespace std;

class Customer {
private:
  int id, age, totalSpentTalkingTime, totalMessageSent, totalInternetUsage;
  string name;
  Operator* op;
  Bill *bill;

public:
  Customer(int, string, int, Operator*, double);
  Customer(const Customer&);
  ~Customer();

  int getId() const;
  int getAge() const;
  int getTotalSpentTalkingTime() const;
  int getTotalMessageSent() const;
  double getTotalInternetUsage() const;
  string getName() const;
  Operator* getOperator() const;
  Bill* getBill() const;

  void setOperator(Operator*);

  string toString() const;

  void talk (int, Customer&);
  void message(int, const Customer&);
  void connection(double);
  void pay(double);
};
Customer::Customer(int i, string n, int a, Operator *o, double lim){
	id=i;
	name=n;
	age=a;
	op=o;
	bill=new Bill(lim);
	totalSpentTalkingTime=0;
	totalMessageSent=0;
	totalInternetUsage=0;
}
Customer::Customer(const Customer &other){
	id=other.id;
	name=other.name;
	age=other.age;
	op=other.op;
	bill=other.bill;
	totalSpentTalkingTime=other.totalSpentTalkingTime;
	totalMessageSent=other.totalMessageSent;
	totalInternetUsage=other.totalInternetUsage;
}
Customer::~Customer(){
	delete bill;
	bill=NULL;
	op=NULL;
}
int Customer::getId() const{
	return id;
}
int Customer::getAge() const{
	return age;
}
int Customer::getTotalSpentTalkingTime() const{
	return totalSpentTalkingTime;
}
int Customer::getTotalMessageSent() const{
	return totalMessageSent;
}
double Customer::getTotalInternetUsage() const{
	return totalInternetUsage;
}
string Customer::getName() const{
	return name;
}
Operator* Customer::getOperator() const{
	return op;
}
Bill* Customer::getBill() const{
	return bill;
}
void Customer::setOperator(Operator *o){
	op=o;
}
void Customer::talk(int minutes, Customer &other){
	double price;
	if (minutes>0 && other.getId()!=id){
		price=op->calculateTalkingCost(minutes, age);
		if (bill->check(price)){
			bill->add(price);
			op->addTalkingTime(minutes);
			other.op->addTalkingTime(minutes);
			op->addTalkingTime(minutes);
			if (op->getId()!=other.op->getId()){
				other.op->addTalkingTime(minutes);
			}
		}
	}
}
void Customer::message(int quantity, const Customer &other){
	double price=0;
	if (quantity>0 && other.getId()!=id){
		price=op->calculateMessageCost(quantity, op->getId(), other.op->getId());
		if (bill->check(price)){
			bill->add(price);
			op->addTotalMessageSent(quantity);
			op->addTotalMessageSent(quantity);
		}
	}
}
void Customer::connection(double amount){
	double price=0;
	if (amount>0){
		price=op->calculateNetworkCost(amount);
		if (bill->check(price)){
			bill->add(price);
			op->addTotalInternetUsage(amount);
			op->addTotalInternetUsage(amount);
		}
	}
}
void Customer::pay(double amount){
	bill->pay(amount);
}
string Customer::toString() const{
	stringstream aux;
	aux<<"Customer "<<fixed<<getId()<<": "
	   <<fixed<<setprecision(2)<<bill->getTotalMoneySpent()<<" "
	   <<fixed<<setprecision(2)<<bill->getCurrentDebt()<<endl;
	return aux.str();
}
#endif
