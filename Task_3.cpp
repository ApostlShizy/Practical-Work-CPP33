#include <iostream>
#include <vector>
#include <exception>

template<typename T1, typename T2>
class Registry {
private:
    int size = 0;
    int count = 0;
    T1** key = nullptr;
    T2** value = nullptr;
    void replace(T1 inKey, T2 inValue) {
        for (int i = 0; i < size; ++i) {
            if (key[i] == nullptr) {
                key[i] = new T1(inKey);
                value[i] = new T2(inValue);
                break;
            }
        }
    }
public:
    Registry() {};
    void add(T1 inKey, T2 inValue) {        
        if (count + 1 > size) {
            ++count;
            ++size;
            T1** tempKey = new T1 * [count];
            T2** tempValue = new T2 * [count];
            for (int i = 0; i < count - 1; ++i) {
                tempKey[i] = key[i];
                tempValue[i] = value[i];
            }
            tempKey[count - 1] = new T1(inKey);
            tempValue[count - 1] = new T2(inValue);
            key = new T1 * [count];
            value = new T2 * [count];
            for (int i = 0; i < count; ++i) {
                key[i] = tempKey[i];
                value[i] = tempValue[i];
            }
            delete[] tempKey;
            delete[] tempValue;
        } 
        else {
            ++count;
            replace(inKey, inValue);
        }        
    }

    void remove(T1 inKey) {
        bool find = false;
        for (int i = 0; i < size; ++i) {
            if (key[i] != nullptr && *key[i] == inKey) {
                std::cout<< "\nRemove : " << *key[i] << " his value : "<< *value[i] <<std::endl;
                delete key[i];
                delete value[i];
                key[i] = nullptr;
                value[i] = nullptr;
                --count;
                find = true;                
            }
        }
        if(!find) {
            std::cout<<"\nNot find : "<< inKey << std::endl;
        }
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            if (key[i] != nullptr) std::cout << "\nKey : " << *key[i] << " Value : " << *value[i] << std::endl;
        }        
    }

    void find(T1 inKey) {
        bool find = false;
        for (int i = 0; i < size; ++i) {
            if (key[i] != nullptr && *key[i] == inKey) {
                std::cout << "\nFind :  key " << *key[i] << " value " << *value[i] << std::endl;
                find = true;
            }
        }
        if(!find){
            std::cout<<"\nNot find : "<< inKey << std::endl; 
        }
    }

    void getSizeCount() {
        std::cout << "\nSize : " << size << " Count " << count << std::endl;
    }

    ~Registry() {
        for (int i = 0; i < count; ++i) {
            if (key[i] != nullptr)delete key[i];
            if (value[i] != nullptr)delete value[i];
        }
        delete[] key;
        delete[] value;
    }
};

int main() {    
    Registry<int,std::string> first;    
    std::string choice;
    while (choice != "exit") {
        first.getSizeCount();
        std::cout << "\nChoice\n\"add\"\n\"remove\"\n\"find\"\n\"print\"\nEnter : ";
        std::cin >> choice;
        try {
            if (choice == "add") {
                int temp;
                std::string tempStr;
                std::cout << "\nEnter key : ";
                std::cin >> temp;
                std::cout << "\nEnter value : ";
                std::cin >> tempStr;
                if (!std::cin) {
                    /*In Visual Studio*/
                    /*throw std::exceptio("Input error");*/
                    throw std::exception();
                }
                first.add(temp, tempStr);
            }
            else if (choice == "remove") {
                int temp;
                std::cout << "\nEnter key to remove : ";
                std::cin >> temp;
                if (!std::cin) {
                    /*In Visual Studio*/
                    /*throw std::exceptio("Input error");*/
                    throw std::exception();
                }
                first.remove(temp);
            }
            else if (choice == "find") {
                int temp;
                std::cout << "\nEnter key to find : ";
                std::cin >> temp;
                if (!std::cin) {
                    /*In Visual Studio*/
                    /*throw std::exceptio("Input error");*/
                    throw std::exception();
                }
                first.find(temp);
            }
            else if (choice == "print") {
                first.print();
            }
        }
        catch (std::exception) {
            /*In Visual Studio*/
            /*catch (const std::exception& x)*/
            /*std::cerr << "\nException cause : "<< x.what()<<std::endl;*/
            std::cerr << "\nException cause : Input error" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::cout << '\n' + std::string(20, '-');        
    }
}

