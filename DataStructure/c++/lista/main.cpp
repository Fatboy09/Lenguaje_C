#include <iostream>

#include "lista.hpp"
#include "lista.cpp"

int main() {
    Lista<int> l{};
    //l.clear();
    l.insert_at(0,-1);
    l.remove_first();
    l.remove_last();
    std::cout << l.size() << '\n';
    l.print();
    l.insert_head(3);
    l.insert_head(1);
    l.insert_end(4);
    std::cout << l.size() << '\n';
    l.print();
    l.insert_at(2,1);
    l.insert_at(0,0);
    l.insert_at(5,4);
    l.insert_end(6);
    l.insert_end(8);
    l.insert_end(9);
    std::cout << l.size() << '\n';
    l.print();
    l.insert_at(7,7);
    l.insert_at(6,-1);
    l.remove_first();
    std::cout << l.size() << '\n';
    l.print();
    l.remove_last();
    l.remove_at(0);
    l.remove_at(l.size()-1);
    l.remove_at(2);
    std::cout << l.size() << '\n';
    l.print();
    std::cout << l.get_element_at(0) << '\n';
    std::cout << l.get_element_at(4) << '\n';
    std::cout << l.get_element_at(2) << '\n';
    std::cout << l.search(5) << '\n';
    std::cout << l.search(11) << '\n';
    l.clear();
    std::cout << l.size() << '\n';
    l.print();

    return 0;
}