#include <iostream>
#include <exception>

template<typename T>
void input(T array[]) {
    for (int i = 0; i < 8;++i) {
        std::cout << "\nEnter num " << i << " : ";
        std::cin >> array[i];
        if (!std::cin) {
            throw std::invalid_argument("Not a number !!!");
        }
    }
}

template<typename M>
M mean(M array[]) {
    M aMean = (M)0;    
    for (int i = 0; i < 8; ++i) {
        aMean += array[i];
    }
    return aMean / (M)8;
}


int main() {
    double array[8];
    try {
        input(array);
    }
    catch(const std::invalid_argument& x){
        std::cerr << "\nException cause : " << x.what() << std::endl;
        return -1;
    }
    std::cout << "\nArithmetic mean : " << mean(array) << std::endl;    
}
