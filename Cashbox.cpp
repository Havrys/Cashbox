/*Description
Develop a cashbox program for a shop that sells different goods.
Each good has the following properties:
    ·ID
    ·Price
    ·Available quantity in stock
Every day the shop receives a list of orders for goods. If a required good is not available in the shop,
then the requirement is ignored; if less quantity is available, then the shop sells all available amount 
of the good (and ignores the rest of the order for such a good).
The program must calculate the total price of the goods sold every day.

Input:
1.An array of integers, where consecutive groups of three numbers describe goods:
    1.1.ID, unique.
    1.2.Price.
    1.3.Available quantity in stock.
2.Termination number -1.
3.Number of days.
4.For each day:
    a.An array of integers, where consecutive groups of two numbers describe good orders:
        i.ID.
        ii.The ordered quantity of the item.
    b.Termination number -1.

Note: If there are several orders for the same ID, then corresponding quantities are summed for that good.

The order of IDs in the input data is arbitrary.*/

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>


class Cashbox {
public:
    void storeItem(int id, int cost, int count);
    int performRequest(int id, int count);
private:
    std::map<int, std::pair<int, int>> m_storage;
};

// äîáàâèòü îäèí òîâàð íà ñêëàä
void Cashbox::storeItem(int id, int cost, int count) {
    m_storage[id] = std::make_pair(cost, count);
}

// ïîñ÷èòàòü ñòîèìîñòü çàêàçà äëÿ îäíîãî èä
int Cashbox::performRequest(int id, int count) {
    auto item = m_storage.find(id);
    if (item == m_storage.end())
        return 0;

    int& avCount = item->second.second;

    if (avCount > count)
    {
        avCount -= count;
        return item->second.first * count;
    }
    auto ret = avCount * item->second.first;
    avCount = 0;
    return ret;
}

int main(const int argc, const char* argv) {
    std::vector<int> shop;
    int member_1{};

    while (member_1 != -1)
    {
        std::cin >> member_1;
        shop.push_back(member_1);
    }

    Cashbox shopWithItem;
    for (int i{}; i < shop.size()-1; i += 3)
    {
        shopWithItem.storeItem(shop[i], shop[i+1], shop[i+2]);
    }

    int days{};
    std::cin >> days;
    std::vector<int> daysN(days);
    
    
    for (int i{}; i < days; i++)
    {
        int a{};
        std::vector<int> a1;
        daysN[i] = 0;
        while (a != -1)
        {
            std::cin >> a;
            a1.push_back(a);
        }
        for (int j{}; j < a1.size()-1; j += 2)
        {
            daysN[i] += shopWithItem.performRequest(a1[j], a1[j+1]);
        }
    }

    for (const auto& i : daysN)
    {
        std::cout << i << ' ';
    }
    std::cout << -1;
}
