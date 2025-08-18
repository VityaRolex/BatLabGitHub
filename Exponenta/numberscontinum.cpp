#include <iostream>

int32_t pow(int32_t a, int32_t b)
{
	int32_t temp{a};
	while (b != 1)
	{
		a = a * temp;
		b -= 1;
	}
	return a;
} 
int32_t poryadokChislaAdress(int32_t number) //������� ���������� ������� �����, �� ���� �������� ��������� ������ �����
{
	int32_t y{ 2 };
	int32_t k{ 1 };
	k = 90;
	if (number - 9 <= 0)
	{
		return 1;
	}
	else
	{
		number -= 9;
		while (number - y*k > 0)
		{
			number = number - (y * k);
			y += 1;
			k = 10 * (k);
		}
		return  y;
	}

}
int32_t rasstoyaniedoblizhpred(int32_t number) //������� ���������� ���������� �� ����� �� ������������ ����� ������� ������� �����
{
	int32_t y{ 2 };
	int32_t k{ 1 };
	k = 90;
	if (number - 9 <= 0)
	{
		return number;
	}
	else
	{
		number -= 9;
		while (number - y*k > 0)
		{
			number = number - (y * k);
			y += 1;
			k = 10 * (k);
		}
		return  number;
	}

}
int32_t nomerznakasprava(int32_t nomerotblizhpred,int32_t poryadok) //������� ���������� ����� ����� �����, �� ������� ��������� ����� � ������ �����
{
	int32_t k = poryadok - 1;
	int32_t i{1};
	while (i < nomerotblizhpred)
	{
		if (k == 0)
		{
			k = poryadok - 1;
		}
		else
		{
			k -= 1;
		}
		++i;
	}
	return k;
}
void chislo(int32_t number)
{
	int32_t nomerotblizhpred{ rasstoyaniedoblizhpred(number) };
	int32_t poryadok{ poryadokChislaAdress(number) };
	int32_t nomerznaka{ nomerznakasprava(nomerotblizhpred, poryadok) };
	int32_t chislo{};
	if (poryadok == 1)
	{
		std::cout << number << '\n';
	}
	else
	{
		chislo = pow(10, poryadok - 1) + (rasstoyaniedoblizhpred(number) - 1) / poryadok;
		while (nomerznaka > 0)
		{
			chislo /= 10;
			nomerznaka -= 1;
		}
		std::cout << chislo % 10 << '\n';
	}
}
bool checkNaturality(double number)
{
	return (number > 0 && number - static_cast<int32_t>(number) == 0);
}
void inputNumber(int32_t* number)
{
	double temp{};
	std::cout << "input natural number" << '\n';
	std::cin >> temp;
	if (checkNaturality(temp))
	{
		*number = temp;
	}
	else
	{
		std::cout << "number isn't natural";
	}
	std::cout << '\n';
}
int main()
{
	int32_t number{};
	//inputNumber(&number);
	//if (checkNaturality(number))
	//{
	//	chislo(number);
	//}
	for (int32_t i=1; i < 3000; ++i)
	{
		std::cout << i << ' ';
		chislo(i);
		std::cout << ' ';
	}
	std::cout << "ABOBA";
	return 0;
}


//lavrik_pidor
