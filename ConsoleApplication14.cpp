#include <iostream>  
#include <fstream>  
#include <string>  
#include <vector>  

using namespace std;

class Car
{
protected:
	string model;
public:
	Car(string m)
	{
		model = m;
	}

	virtual ~Car() {}
};

class Mercedes : public Car
{
public:
	Mercedes(string m) : Car(m) {}
	~Mercedes()
	{
		cout << "Mercedes " << model << endl;
	}
};


class Audi : public Car
{
public:
	Audi(string m) : Car(m) {}
	~Audi()
	{
		cout << "Audi " << model << endl;
	}
};

class BMW : public Car
{
public:
	BMW(string m) : Car(m) {}
	~BMW()
	{
		cout << "BMW " << model << endl;
	}
};


int main()
{

	vector<Car*> cars;
	ifstream file("cars.txt");
	string brand;
	string model;
	while (file >> brand >> model)
	{
		if (brand == "Mercedes")
			cars.push_back(new Mercedes(model));
		else if (brand == "Audi")
			cars.push_back(new Audi(model));
		else if (brand == "BMW")
			cars.push_back(new BMW(model));
		else
			cout << "no brand" << endl;
	}
	for (int i = 0; i < cars.size(); i++)
	{
		delete cars[i];
	}

	return 0;
}