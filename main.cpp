#include<iostream>
#include<string>
#include"DVDCollection.h"


using namespace std;

int main()
{
	DVDCollection myCollection;

	for (size_t i = 0; i < 10; i++)
	{
		string name, company;
		double cost;
		cin >> name >> company >> cost;
		myCollection.add(*(new DVD(name,company, cost)));
		//myCollection.add(*(new DVD("Passengers", "HBO", 5)));
	}
		

	myCollection.display();
	cout << "------------" << endl;
	myCollection.deleteDVD("Passengers");
	myCollection.display();
	cout << "------------" << endl;

	myCollection.add(*(new DVD("Hobbit1", "British",420)));
	myCollection.add(*(new DVD("Hobbit2", "British", 840)));
	myCollection.display();

	system("pause");

}