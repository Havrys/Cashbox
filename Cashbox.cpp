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

// добавить один товар на склад
void Cashbox::storeItem(int id, int cost, int count) {
    m_storage[id] = std::make_pair(cost, count);
}

// посчитать стоимость заказа для одного ид
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
