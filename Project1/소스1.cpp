#include <iostream>
#include <vector>

using namespace std;


class Animal {


public:
	virtual void speak() const = 0;

};

class Cat : public Animal {
public:
	virtual void speak() const override {
		cout << "具克~~~~~" << endl;
	}
};


class Dog : public Animal {
public:
	virtual void speak() const override {
		cout << "港港~~~~~" << endl;
	}
};

class Cow : public Animal {
public:
	virtual void speak() const override {
		cout << "栏皋~~~~~" << endl;
	}
};

class Zoo {
private:
	vector<Animal*> array;

public:
	void addAnimal(Animal* const pAnimal) {
		array.push_back(pAnimal);
	}

	void speak()
	{
		for (const auto& pAnimal : array) {
			pAnimal->speak();
		}
	}
};

bool InitInstance(Zoo* pZoo) {
	Cat cat;
	Dog dog;
	Cow cow;

	pZoo->addAnimal(&cat);
	pZoo->addAnimal(&dog);
	pZoo->addAnimal(&cow);

	return true;

}

bool Run(Zoo* pZoo) {
	pZoo->speak();

	return true;
}


bool ExitInstance(Zoo* pZoo) {
	return true;
}

int main()
{
	Zoo zoo;


	InitInstance(&zoo);

	Run(&zoo);

	ExitInstance(&zoo);


	return 0;
}


using namespace std;


//class Animal {
//
//
//public:
//	virtual void speak() const = 0;
//
//};
//
//class Cat : public Animal {
//public:
//	virtual void speak() const override {
//		cout << "具克~~~~~" << endl;
//	}
//};
//
//
//class Dog : public Animal {
//public:
//	virtual void speak() const override {
//		cout << "港港~~~~~" << endl;
//	}
//};
//
//class Cow : public Animal {
//public:
//	virtual void speak() const override {
//		cout << "栏皋~~~~~" << endl;
//	}
//};
//
//class Zoo {
//private:
//	vector<Animal> array;
//
//public:
//	void addAnimal(Animal const &pAnimal) {
//		array.push_back(pAnimal);
//	}
//
//	void speak()
//	{
//		for (auto animal :array) {
//			array.speak();
//		}
//	}
//};
//
//
//int main()
//{
//	Zoo zoo;
//	Cat cat;
//	Dog dog;
//	Cow cow;
//
//	zoo.addAnimal(cat);
//	zoo.addAnimal(dog);
//	zoo.addAnimal(cow);
//
//	zoo.speak();
//
//
//	return 0;
//}