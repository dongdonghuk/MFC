#include <iostream>
#include <vector>

using namespace std;

int add(const int a, const int b)
{
	return a + b;
}

int sub(const int a, const int b)
{
	return a - b;
}

typedef int (*FP_CALC)(const int, const int);
FP_CALC calc;


class Calc
{
public:
	virtual int calc(const int a, const int b) = 0;
};

class AddCalc : public Calc {
public:
	virtual int calc(const int a, const int b) override {
		return a + b;
	}

};

class SubCalc : public Calc {
public:
	virtual int calc(const int a, const int b) override {
		return a - b;
	}

};

class MulCalc : public Calc {
public:
	virtual int calc(const int a, const int b) override {
		return a * b;
	}

};


//ocp ¿­¸²´ÝÈûÀÇ ±ÔÄ¢
int MYCalc(Calc& obj, const int a, const int b)
{
	return obj.calc(a, b);
}


int main()
{


	int a = 10;
	int b = 20;

	int* p1 = &a;
	int* p2 = &b;

	int sum;
	int result = 0;

	calc = add;
	result = calc(a, b);

	calc = sub;
	result = calc(a, b);

	Calc* pCalc = new AddCalc();
	result = pCalc->calc(a, b);
	delete pCalc;

	AddCalc addCalc;
	Calc& objA = addCalc;
	result = objA.calc(a, b);

	SubCalc subCalc;
	MulCalc mulCalc;


	result = MYCalc(addCalc, a, b);
	result = MYCalc(subCalc, a, b);
	result = MYCalc(mulCalc, a, b);

	vector<Calc*> arr = {&addCalc, &subCalc, &mulCalc};

	for (auto& pCalc : arr) {
		MYCalc(*pCalc, a, b);
	}


	return 0;
}