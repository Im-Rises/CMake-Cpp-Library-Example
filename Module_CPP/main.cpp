import foo;
import event;
import eventsystem;
import eventsystemother;

#include <functional>
#include <iostream>

void testEventFunc() { std::cout << "Function print" << std::endl; }

class MyTestClass {
public:
    void printFromClass() {
        std::cout << "Print from test class" << std::endl;
    }
};

int main() {
    foo f;
    f.helloworld();
    return 0;
}