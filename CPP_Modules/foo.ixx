module;

// Put needed includes here for the .h which wont be shared when importing module

export module foo;

// Put imported element here when importing the modules

struct MyStruct {
    bool mybool;
};

export class Foo {
public:
    Foo();
    ~Foo();
    void helloworld();
};
