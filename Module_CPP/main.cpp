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

    Event myEvent;
    myEvent += testEventFunc;
    myEvent.triggerEvent();

    EventSystem myEventSystem;
    myEventSystem += std::bind(&foo::helloworld, &f);
    myEventSystem += testEventFunc;
    myEventSystem.triggerEvent();

    // MyTestClass mytestclass;
    // MethodPointer sdqsdq;
    // MethodPointer mymethodpointer(&mytestclass, &mytestclass::printFromClass);
    // EventSystemOther eventsystemother();

    return 0;
}