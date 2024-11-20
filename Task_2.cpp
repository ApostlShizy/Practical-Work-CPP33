#include <iostream>
#include <exception>
#include <ctime>

class FishCatchException : public std::exception {
public:
    const char* what() const noexcept override {
        return "You catch fish!!!";
    }
};

void display(char river[]) {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0) {
            std::cout << std::endl;
        }
        if (river[i] == ' ') {
            std::cout << '.';
        }
        else {
            std::cout << river[i];
        }       
    }
}

int main() {
    srand(std::time(nullptr));
    char river[] {' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    river[rand() % 9] = 'F';
    int boot = 3;
    do {
        int temp = rand() % 9;
        if (river[temp] == ' ') {
            river[temp] = 'B';
            --boot;
        }
    } while (boot != 0);
    
    while (true) {
        int choice;
        std::cout << "\nEnter choice (0-8) : ";        
        try {
            std::cin >> choice;
            if(!std::cin) {
                throw std::invalid_argument("input error");
            }
            if (river[choice] == 'F') {
                throw FishCatchException();
            }
            else if (river[choice] == 'B') {  
                /*In Visual Studio*/              
                /*throw std::exception("You cath boot");*/
                throw std::exception();
            }
            else {
                std::cout << "\nThat sector is empty, try again" << std::endl;
            }
        }
        catch (const std::invalid_argument& x){
            std::cerr <<"\nException cause : " << x.what() << std::endl;
            return -1;
        }
        catch (const FishCatchException& x) {
            std::cerr << "\nException cause : " << x.what() << std::endl;
            display(river);
            return 0;
        }
        catch (std::exception) {
            /*In Visual Studio*/
            /*catch (const std::exception& x)*/
            /*std::cerr << "\nException cause : << x.what() << std::endl;"*/
            std::cerr << "\nException cause : You cath boot " << std::endl;
            display(river);
            return 0;
        }        
    }
}

