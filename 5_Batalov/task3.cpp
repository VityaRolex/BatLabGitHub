#include <iostream>
#include <algorithm>
#include "footbaler.h"
#include "footbaler_in_arenda.h"

int main() {


    Footbaler* arr[6] = {
        new Footbaler((char*)"Ronaldo", Genre::Attacker, 2027),
        new Footbaler((char*)"Neuer", Genre::Vratar, 2030),
        new Footbaler_in_Arenda((char*)"Mbappe", Genre::Attacker, 2032, 5),
        new Footbaler_in_Arenda((char*)"Alvarez", Genre::Attacker, 2031, 2),
        new Footbaler((char*)"Pique", Genre::Zachitnik, 2025),
        new Footbaler_in_Arenda((char*)"Felix", Genre::Attacker, 2033, 7)
    };

    int n = 6;

    std::cout << "\n=== Исходный массив ===\n";
    for (int i = 0; i < n; i++)
        std::cout << *arr[i] << "\n";

    int specCount[5] = {0};
    for (int i = 0; i < n; i++)
        specCount[arr[i]->getSpec()]++;

    std::cout << "\n=== Подсчёт специализаций ===\n";
    std::cout << "Вратарь: " << specCount[Genre::Vratar] << "\n";
    std::cout << "Защитник: " << specCount[Genre::Zachitnik] << "\n";
    std::cout << "Полузащитник: " << specCount[Genre::demi_Zachitnik] << "\n";
    std::cout << "Нападающий: " << specCount[Genre::Attacker] << "\n";

    int baseCount = 0, derivedCount = 0;

    for (int i = 0; i < n; i++) {
        if (dynamic_cast<Footbaler_in_Arenda*>(arr[i]))
            derivedCount++;
        else
            baseCount++;
    }

    std::cout << "\n=== Количество объектов по типам ===\n";
    std::cout << "Footbaler: " << baseCount << "\n";
    std::cout << "Footbaler_in_Arenda: " << derivedCount << "\n";

    std::sort(arr, arr + n,
        [](Footbaler* a, Footbaler* b)
        {
            if (a->getEndigDate() != b->getEndigDate())
                return a->getEndigDate() > b->getEndigDate();


            auto* da = dynamic_cast<Footbaler_in_Arenda*>(a);
            auto* db = dynamic_cast<Footbaler_in_Arenda*>(b);

            if (da && db)
                return da->getClubCount() < db->getClubCount();

            return false;
        }
    );

    std::cout << "\n=== После сортировки ===\n";
    for (int i = 0; i < n; i++)
        std::cout << *arr[i] << "\n";

    int limit = 4;
    bool found = false;

    std::cout << "\n=== Арендованные с clubCount > " << limit << " ===\n";

    for (int i = 0; i < n; i++) {
        auto* d = dynamic_cast<Footbaler_in_Arenda*>(arr[i]);
        if (d && d->getClubCount() > limit) {
            std::cout << *d << "\n";
            found = true;
        }
    }

    if (!found)
        std::cout << "Нет таких футболистов.\n";


    for (int i = 0; i < n; i++)
        delete arr[i];

    return 0;
}
