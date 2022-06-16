/*-----------------------
Bill
José Emiliano Riosmena Castañón
A01704245
------------------------*/
#ifndef BILL_H
#define BILL_H
using namespace std;

class Bill {
private:
  double limitAmount, currentDebt, totalMoneySpent;

public:
  Bill();
  Bill(double);
  Bill(const Bill&);

  double getLimitAmount() const;
  double getCurrentDebt() const;
  double getTotalMoneySpent() const;

  void add(double);
  void pay(double);
  void changeTheLimit(double);
  bool check(double) const;
};
Bill::Bill(){
	limitAmount=0;
	currentDebt=0;
	totalMoneySpent=0;
}
Bill::Bill(double lim){
	if (lim<=0){
		lim=0;
	}
	limitAmount=lim;
	currentDebt=0;
	totalMoneySpent=0;
}
Bill::Bill(const Bill &other){
	limitAmount=other.limitAmount;
	currentDebt=other.currentDebt;
	totalMoneySpent=other.totalMoneySpent;
}
double Bill::getLimitAmount() const{
	return limitAmount;
}
double Bill::getCurrentDebt() const{
	return currentDebt;
}
double Bill::getTotalMoneySpent() const{
	return totalMoneySpent;
}
void Bill::add(double amount){
	if (amount>0){
		currentDebt+=amount;
	}
}
void Bill::pay(double amount){
	if (amount>0){
		if (amount>currentDebt){
			amount=currentDebt;
		}
		currentDebt-=amount;
		totalMoneySpent+=amount;
	}
}
void Bill::changeTheLimit(double amount){
	if (amount>0 || amount>currentDebt){
		limitAmount=amount;
	}
}
bool Bill::check(double amount) const{
	return (currentDebt+amount)<=limitAmount;
}
#endif
