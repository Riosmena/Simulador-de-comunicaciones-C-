/*-----------------------
Internet
José Emiliano Riosmena Castañón
A01704245
------------------------*/
#ifndef InternetOperator_H
#define InternetOperator_H

#include "operator.h"
using namespace std;

class InternetOperator : public Operator {
private:
  const double LIMITGB = 1.0;

public:
  InternetOperator(int, double, double, double, int, OperatorType);
  InternetOperator(const InternetOperator&);

  double calculateTalkingCost(int, int);
  double calculateMessageCost(int, int, int);
  double calculateNetworkCost(double);
};
InternetOperator::InternetOperator(int i, double tc, double mc, double nc, int dr, OperatorType t)
	: Operator(i,tc,mc,nc,dr,t){
}
InternetOperator::InternetOperator(const InternetOperator &other)
	: Operator(other){
}
double InternetOperator::calculateTalkingCost(int minute, int age){
	double price=0;
	if (minute>0 && age>0){
		price=minute*talkingCharge;
		if (minute<2){
			price-=price*discountRate/100;
		}
	}
	return price;
}
double InternetOperator::calculateMessageCost(int quantity, int thisOpId, int otherOpId){
	double price=0;
	if (quantity>0){
		price=quantity*messageCost;
		if (quantity<3){
			price-=price*discountRate/100;
		}
	}
	return price;
}
double InternetOperator::calculateNetworkCost(double amount){
  double price=0;
  if (amount>LIMITGB){
    price=(amount-LIMITGB)*networkCharge;
  }
  return price;
}    

#endif
