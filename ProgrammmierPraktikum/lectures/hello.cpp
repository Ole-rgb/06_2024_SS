#include <iostream>

class User{
    public:
        std::string name;
        User(){
            name = "No Name";
  
        }
        User(std::string name){
            name = name;
        }
};

void printName(std::string name, int age);

int main(){
    std::cout << "your name: " << std::flush;
    std::string name;
    std::cin >> name;
    std::cout << std::endl;
    printName(name, 22);
    User user = User("Username");
    std::cout << user.name;
    return 0;
}

void printName(std::string name, int){
    std::cout << "Hello " + name << std::endl;
}