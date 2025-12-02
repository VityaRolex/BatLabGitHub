#include "footbaler_in_arenda.h"

int main() {
    std::cout << "=== Создание базового футболиста ===\n";
    Footbaler f1((char*)"Ronaldo", Spec::Attacker, 2027);
    std::cout << f1 << std::endl;

    std::cout << "\n=== Копирование футболиста (copy ctor) ===\n";
    Footbaler f2 = f1;
    std::cout << f2 << std::endl;

    std::cout << "\n=== Перемещение футболиста (move ctor) ===\n";
    Footbaler f3 = std::move(f2);
    std::cout << f3 << std::endl;

    std::cout << "\n=== Работа operator= копирования ===\n";
    Footbaler f4((char*)"Messi", Spec::Attacker, 2026);
    std::cout << "Было: " << f4 << std::endl;
    f4 = f1;
    std::cout << "Стало: " << f4 << std::endl;

    std::cout << "\n=== Работа operator= перемещения ===\n";
    Footbaler f5((char*)"Buffon", Spec::Vratar, 2025);
    std::cout << "Было: " << f5 << std::endl;
    f5 = std::move(f4);
    std::cout << "Стало: " << f5 << std::endl;

    std::cout << "\n=== Проверка set/get методов ===\n";
    f5.setSurname((char*)"Neuer");
    f5.setEndingDate(2030);
    std::cout << f5 << std::endl;

    std::cout << "\n=== Проверка сравнений по специализации ===\n";
    std::cout << "f1 и f3 имеют одинаковую специализацию? -> "
              << (isSameSpec(f1, f3) ? "да" : "нет") << std::endl;

    std::cout << "\n=== Работа класса Footbaler_in_Arenda ===\n";
    Footbaler_in_Arenda a1((char*)"Mbappe", Spec::Attacker, 2032, 5);
    std::cout << "Арендованный игрок: " << a1.getSurname()
              << ", клубов было: " << a1.getClubCount() << std::endl;

    std::cout << "\n=== Copy ctor для Footbaler_in_Arenda ===\n";
    Footbaler_in_Arenda a2 = a1;
    std::cout << "Копия: " << a2.getSurname()
              << ", клубов: " << a2.getClubCount() << std::endl;

    std::cout << "\n=== Move ctor для Footbaler_in_Arenda ===\n";
    Footbaler_in_Arenda a3 = std::move(a2);
    std::cout << "После move: "
              << a3.getSurname() << ", клубов: " << a3.getClubCount() << std::endl;

    std::cout << "\n=== Тестируем setClubCount ===\n";
    a3.setClubCount(10);
    std::cout << "Клубов теперь: " << a3.getClubCount() << std::endl;

    return 0;
}
