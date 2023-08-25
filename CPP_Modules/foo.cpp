module foo;

import foo;

#include <iostream>

Foo::Foo() {
    std::cout << "Constructor Foo" << std::endl;
}

Foo::~Foo() {
    std::cout << "Destructor Foo" << std::endl;
}

void Foo::helloworld() {
    std::cout << "Hello world Foo" << std::endl;
}



