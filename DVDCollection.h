#include<iostream>
#include"DVD.h"

using namespace std;

class DVDCollection
{
public:
	DVDCollection();
	DVDCollection(int maxDVDs);
	void add(DVD& X);
	int search(string title);
	void deleteDVD(string title);
	void display();
	




private:
	DVD *DVDlist = nullptr;
	int maxDVDs;
	int currentDVDs = 0;
	double TotalCost;

	void increaseSize();

};



DVDCollection::DVDCollection()
{
	this->maxDVDs = 5;
	this->DVDlist = new DVD[5];
}

DVDCollection::DVDCollection(int maxDVDs)
{
	this->maxDVDs = maxDVDs;
	this->DVDlist = new DVD[maxDVDs];
}

void DVDCollection::add(DVD& X)
{
	if (currentDVDs >= maxDVDs)
	{
		cout << "\n\nAdjustments made \n" << endl;
		increaseSize();
		add(X);
	}

	else
	{
		this->DVDlist[this->currentDVDs] = X;
		this->currentDVDs++;
	}
	
}

int DVDCollection::search(string title)
{
	int i, flag =0;
	for (i = 0; i < this->currentDVDs; i++)
	{
		if (this->DVDlist[i].getName()== title)
		{
			flag = 1;
			break;
		}
		
	}
	if (flag == 1)
	{
		return i;
	}
	else
	{
		return -1;
	}
	

}

void DVDCollection::increaseSize()
{
	DVD *newDVDlist = new DVD[this->maxDVDs * 2];

	this->maxDVDs *= 2;

	for (int i = 0; i < this->currentDVDs; i++)
	{
		newDVDlist[i] = this->DVDlist[i];
	}
	delete[] this->DVDlist;
	this->DVDlist = newDVDlist;
}

void DVDCollection::deleteDVD(string title)
{
	int index = this->search(title);

	//delete[] &(this->DVDlist[index]);
	if (index != -1)
	{
		for (int i = index; i < this->currentDVDs; i++)
		{

			// Assign the next element to current location.             
			this->DVDlist[i] = this->DVDlist[i + 1];

			// Remove the last element as it has been moved to previous index.
			//delete &(this->DVDlist[this->currentDVDs - 1]);


		}
		this->currentDVDs--;
	}
	else
	{
		cout << "\n\nNo such DVD exists.\n" << endl;
	}
	

}

void DVDCollection::display()
{
	for (int i = 0; i < this->currentDVDs; i++)
	{
		cout << this->DVDlist[i];
	}
}

