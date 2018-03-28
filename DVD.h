#include<iostream>
#include<string>

using namespace std;

class DVD
{
public:
	DVD();
	DVD(string name, string company, double cost);
	void setName();
	void setCompany();
	void setCost();
	void set();
	string getName();
	string getCompany();
	double getCost();
	friend ostream& operator << (ostream& o, DVD X);

private:
	string name;
	string company;
	double cost;
};

ostream& operator << (ostream& o, DVD X)
{
	return o << X.name << " " << X.company << " " << X.cost << endl;
}

DVD::DVD()
{
	this->name = "";
}

DVD::DVD(string name, string company, double cost)
{
	this->name = name;
	this->company = company;
	this->cost = cost;
}

string DVD::getName()
{
	return this->name;
}

