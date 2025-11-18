#include "LinearEquation.h"
#include "QuadraticEquation.h"
#include <algorithm>

//bool compare(Equation*, Equation*);
int compare(const void*, const void*);
int LineralCompare(const void*, const void*);
int QuadraticCompare(const void*, const void*);

int main() {
	size_t ws{};
	size_t size{5};
	Equation* arr[size];
	arr[0] = new QuadraticEquation(2, 6, 8);
	arr[1] = new LineralEquation(8, 5);
	arr[2] = new LineralEquation(-50, 37);
	arr[3] = new QuadraticEquation(-6, 85, 98);
	arr[4] = new LineralEquation(6, 8);
	for(size_t i{}; i < size; ++i){
		arr[i]->print();
		arr[i]->solve();
		
	
	}
	std::cout << "============================================\n";
	
	std::cout << "1)Не имеют решений уравнения:\n";
	size_t counter{};
	for(size_t i{}; i < size; ++i){
		QuadraticEquation* temp = dynamic_cast<QuadraticEquation*>(arr[i]);  
		if(temp != nullptr){
			if(temp->disc() < 0){
				temp->print();
				std::cout << std::endl;
				++counter;
			}
		}
		else{
			LineralEquation* temp = dynamic_cast<LineralEquation*>(arr[i]);
			if(temp->getA() == 0){
				temp->print();
				std::cout << std::endl;
				++counter;
			}
		}
	}
	if(counter == 0) std::cout << "\tВсе уравнения имеют корни!\n";
	counter = 0;

	std::cout << "============================================\n";

	std::cout << "2)Имеют бесконечно много решений:\n";
	for(size_t i{}; i < size; ++i){
		LineralEquation* temp = dynamic_cast<LineralEquation*>(arr[i]);
		if(temp != nullptr){
			if(temp->getB() == 0){
				temp->print();
				std::cout << std::endl;
				++counter;
			}
		}
	}
	if(counter == 0) std::cout << "\tНет уравнений, имеющих бесконечно много решений!\n";
	counter = 0;

	std::cout << "============================================\n";

	std::cout << "3)Выполнить сортировку массива по старшему коэффициенту уравнений.\n";
	std::cout << "Изначальный вид массива сверху^\n";
	std::cout << "Отсортированный массив:\n";
	//std::sort(arr, arr + size, compare);
	qsort(arr, size, sizeof(Equation*), compare);

	for(size_t i{}; i < size; ++i){
		QuadraticEquation* temp = dynamic_cast<QuadraticEquation*>(arr[i]);  
		if(temp != nullptr){
			std::cout << "\t";
			temp->print();
			std::cout << "\n";
		}
		else{
			LineralEquation* temp = dynamic_cast<LineralEquation*>(arr[i]);
			std::cout << "\t";
			temp->print();
			std::cout << "\n";
		}
	}

	std::cout << "============================================\n";

	std::cout << "4)Все квадратные уравнения с отрицательным дискриминантом:\n";
	for(size_t i{}; i < size; ++i){
		QuadraticEquation* temp = dynamic_cast<QuadraticEquation*>(arr[i]);
		if(temp != nullptr){
			if(temp->disc() < 0){
				temp->print();
				std::cout << std::endl;
				++counter;
			}
		}
	}
	if(counter == 0) std::cout << "\tНет уравнений с отрицательным дискриминантом!\n";
	counter = 0;

	std::cout << "============================================\n";

	std::cout << "5)Все квадратные уравнения, график которых направлен ветвями вниз:\n";
	for(size_t i{}; i < size; ++i){
		QuadraticEquation* temp = dynamic_cast<QuadraticEquation*>(arr[i]);
		if(temp != nullptr){
			if(temp->getA() < 0){
				temp->print();
				std::cout << std::endl;
				++counter;
			}
		}
	}
	if(counter == 0) std::cout << "\tНет уравнений, график которых направлен ветвями вниз!\n";
	counter = 0;

	std::cout << "============================================\n";

	std::cout << "6)Найти все квадратные уравнения, представляющие собой полный квадрат, полученные уравнения отсортировать по возрастанию старшего коэффициента:\n";

	for(size_t i{}; i < size; ++i){
		QuadraticEquation* temp = dynamic_cast<QuadraticEquation*>(arr[i]);
		if(temp != nullptr){
			if(temp->disc() == 0){
				++counter;
			}
		}
	}
	if(counter != 0){
		QuadraticEquation* tempArr1[counter];
		counter = 0;
		for(size_t i{}; i < size; ++i){
			QuadraticEquation* temp = dynamic_cast<QuadraticEquation*>(arr[i]);
			if(temp != nullptr){
				if(temp->disc() == 0){
					tempArr1[counter] = dynamic_cast<QuadraticEquation*>(arr[i]);
					++counter;
				}
			}
		}
		qsort(tempArr1, counter, sizeof(QuadraticEquation*), QuadraticCompare);
		for(size_t i{}; i < counter; ++i){
			std::cout << "\t";
			tempArr1[i]->print();
			std::cout << "\n";
		}
	}
	else{
		std::cout << "\tНет уравнений, представляющие собой полный квадрат!\n";
	}
	counter = 0;

	std::cout << "============================================\n";

	std::cout << "7) Найти все линейные уравнения, у которых  b > a, отсортировать их по убыванию коэффициента b:\n";
	
	for(size_t i{}; i < size; ++i){
		LineralEquation* temp = dynamic_cast<LineralEquation*>(arr[i]);
		if(temp != nullptr){
			if(temp->getB() > temp->getA()){
				++counter;
			}
		}
	}

	if(counter != 0){
		LineralEquation* tempArr2[counter];
		counter = 0;
		for(size_t i{}; i < size; ++i){
			LineralEquation* temp = dynamic_cast<LineralEquation*>(arr[i]);
			if(temp != nullptr){
				if(temp->getB() > temp->getA()){
					tempArr2[counter] = dynamic_cast<LineralEquation*>(arr[i]);
					++counter;
				}
			}
		}
		qsort(tempArr2, counter, sizeof(LineralEquation*), LineralCompare);
		for(size_t i{}; i < counter; ++i){
			std::cout << "\t";
			tempArr2[i]->print();
			std::cout << "\n";
		}
	}
	else{
		std::cout << "\tНет линейных уравнений, у которых  b > a!\n";
	}
	counter = 0;




	return 0;
}

/*bool compare(Equation* a, Equation* b){
	double tempA{}, tempB{};
	QuadraticEquation* temp = dynamic_cast<QuadraticEquation*>(a);  
	if(temp != nullptr){
		tempA = temp->getA();
	}
	else{
		LineralEquation* temp = dynamic_cast<LineralEquation*>(a);
		tempA = temp->getA();
	}

	QuadraticEquation* tmp = dynamic_cast<QuadraticEquation*>(b);  
	if(tmp != nullptr){
		tempB = tmp->getA();
	}
	else{
		LineralEquation* tmp = dynamic_cast<LineralEquation*>(b);
		tempB = tmp->getA();
	}

	return tempA < tempB;
}*/


int compare(const void* a, const void* b) {
	Equation* A = *(Equation**)a;
	Equation* B = *(Equation**)b;

	double tempA{}, tempB{};
	QuadraticEquation* temp = dynamic_cast<QuadraticEquation*>(A);  
	if(temp != nullptr){
		tempA = temp->getA();
	}
	else{
		LineralEquation* temp = dynamic_cast<LineralEquation*>(A);
		tempA = temp->getA();
	}

	QuadraticEquation* tmp = dynamic_cast<QuadraticEquation*>(B);  
	if(tmp != nullptr){
		tempB = tmp->getA();
	}
	else{
		LineralEquation* tmp = dynamic_cast<LineralEquation*>(B);
		tempB = tmp->getA();
	}

	if(tempA < tempB) return -1;
	if(tempA > tempB) return 1;
	return 0;
}

int LineralCompare(const void* a, const void* b) {
	LineralEquation* A = *(LineralEquation**)a;
	LineralEquation* B = *(LineralEquation**)b;

	double tempA{}, tempB{};
	LineralEquation* temp = dynamic_cast<LineralEquation*>(A);
	tempA = temp->getB();

	LineralEquation* tmp = dynamic_cast<LineralEquation*>(B);
	tempB = tmp->getB();

	if(tempA < tempB) return -1;
	if(tempA > tempB) return 1;
	return 0;
}

int QuadraticCompare(const void* a, const void* b) {
	QuadraticEquation* A = *(QuadraticEquation**)a;
	QuadraticEquation* B = *(QuadraticEquation**)b;

	double tempA{}, tempB{};
	QuadraticEquation* temp = dynamic_cast<QuadraticEquation*>(A);
	tempA = temp->getA();

	QuadraticEquation* tmp = dynamic_cast<QuadraticEquation*>(B);
	tempB = tmp->getA();

	if(tempA < tempB) return -1;
	if(tempA > tempB) return 1;
	return 0;
}