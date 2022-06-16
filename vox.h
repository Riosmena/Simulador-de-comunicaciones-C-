/*-----------------------
Vox
José Emiliano Riosmena Castañón
A01704245
------------------------*/
#ifndef VOXOPERATOR_H
#define VOXOPERATOR_H

#include "operator.h"
using namespace std;

class VoxOperator : public Operator {
public:
  VoxOperator(int, double, double, double, int, OperatorType);
  VoxOperator(const VoxOperator&);

  double calculateTalkingCost(int, int);
  double calculateMessageCost(int, int, int);
  double calculateNetworkCost(double);
};
VoxOperator::VoxOperator(int i, double tc, double mc, double nc, int dr, OperatorType t)
	: Operator(i,tc,mc,nc,dr,t){
}
VoxOperator::VoxOperator(const VoxOperator &other)
	: Operator(other){		
}
double VoxOperator::calculateTalkingCost(int minute, int age){
	double price=0;
	if (minute>0 && age>0){
		price=minute*talkingCharge;
		if (age<18 || age>65){
			price-=price*discountRate/100;
		}
	}
	return price;
}
double VoxOperator::calculateMessageCost(int quantity, int thisOpId, int otherOpId){
	double price=0;
	if (quantity>0){
		price=quantity*messageCost;
		if(thisOpId==otherOpId){
			price-=price*discountRate/100;
		}
	}
	return price;
}
double VoxOperator::calculateNetworkCost(double amount){
	double price=0;
	if (amount>0){
		price=amount*networkCharge;	
	}
	return price;
}
#endif
