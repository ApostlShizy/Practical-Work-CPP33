#include <iostream>
#include <exception>
#include <map>

class InputErorr : public std::exception {
public:
    const char* what() const noexcept override {
        return "Input error";
    }
};

class NonExistErorr : public std::exception {
public:
    const char* what() const noexcept override {
        return "non-existent article";
    }
};

void add(std::map<int, int>& store) {
    int article;
    int number;
    std::cout << "\nEnter article and number : ";
    std::cin >> article >> number;
    if (!std::cin) {
        throw InputErorr();
    }
    if (number < 0) {
        throw std::invalid_argument("below zero");
    }    
    store[article] += number;       
}

void remove(std::map<int, int>& store) {
    int article;
    int number;
    std::cout << "\nEnter article and number : ";
    std::cin >> article >> number; 
    if (!std::cin) {
        throw InputErorr();
    }
    if (store.find(article) == store.end()) {
        throw NonExistErorr();
    }
    if (store[article] - number < 0) {
        throw std::invalid_argument("below zero");
    }
    store[article] -= number;
}

int main() {
    std::map<int, int> store;
    std::string choice;
    while (choice != "exit") {
        std::map<int, int>::iterator iter = store.begin();
        if (iter == store.end()) {
            std::cout << "\nStore empty" << std::endl;
        }
        else {
            std::cout << "\nStore goods now : " << std::endl;
            for (; iter != store.end(); ++iter) {
                std::cout << "Article : " << iter->first << " count goods : " << iter->second << std::endl;
            }               
        }        
        std::cout << "\nEnter choice \"add\" \"remove\" \"exit\" : ";
        std::cin >> choice;
        try {
            if (choice == "add") {
                add(store);
            }
            else if (choice == "remove") {
                remove(store);
            }
            else {
                std::cout << "\nWrong option" << std::endl;
            }
        }
        catch (const InputErorr& x) {
            std::cerr << "\nException cause : " << x.what() << std::endl;
            return -1;
        }
        catch (const std::invalid_argument& x) {
            std::cerr << "\nException cause : " << x.what() << std::endl;
        }
        catch (const std::exception& x) {
            std::cout << "\nException cause : " << x.what() << std::endl;            
        }
    }
}