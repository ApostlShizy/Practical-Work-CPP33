#include <iostream>

template<typename T1, typename T2>
class KeyValue {
    T1 key;
    T2 value;
public:
    KeyValue(T1 inKey, T2 inValue) : key{ inKey }, value{ inValue } {}
    T1 getKey() {
        return key;
    }
    T2 getValue() {
        return value;
    }
};

template<typename T3, typename T4>
class Registry {
private:
    int size = 0;
    int count = 0
    KeyValue<T3, T4>** hisKey = nullptr;
public:
    Registry() {}
    Registry(T3 inKey, T4 inValue) {
        count = 1;
        size = 1;
        hisKey = new KeyValue <T3, T4>* [count];
        hisKey = new KeyValue <T3, T4> ( inKey,inValue );
    }
    void getKeyValue() {
        for (int i = 0; i < size; ++i) {
            if (hisKey[i] != nullptr) std::cout << "\nKey : " << hisKey[i]->getKey() << " Value : " << hisKey[i]->getValue() << std::endl;
        }        
    }
    ~Registry() {
        for (int i = 0; i < size; ++i) {
            if(hisKey[i] != nullptr) delete hisKey[i];
        }
        delete[] hisKey;
    }
};

int main() {
    Registry <int, std::string> first( 10,"Ten" );
    first.getKeyValue();
    std::cout << "Done" << std::endl;
}

