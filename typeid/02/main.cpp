//from:: http://en.wikipedia.org/wiki/Typeid

#include <iostream>    // cout
#include <typeinfo>    // for 'typeid'

class Person {
public:
    // ... Person members ...
    virtual ~Person() {}
};

class Employee : public Person {
    // ... Employee members ...
};

int main()
{
    Person person;
    Employee employee;
    Person* ptr = &employee;
    Person& ref = employee;
    // The string returned by typeid::name is implementation-defined
    std::cout << typeid(person).name() << std::endl;   // Person (statically known at compile-time)
    std::cout << typeid(employee).name() << std::endl; // Employee (statically known at compile-time)
    std::cout << typeid(ptr).name() << std::endl;      // Person* (statically known at compile-time)
    std::cout << typeid(*ptr).name() << std::endl;     // Employee (looked up dynamically at run-time
    //           because it is the dereference of a
    //           pointer to a polymorphic class)
    std::cout << typeid(ref).name() << std::endl;      // Employee (references can also be polymorphic)
    
    Person* p = nullptr;
    try {
        typeid(*p); // not undefined behavior; throws std::bad_typeid
        // *p, *(p), *((p)), etc. all behave identically
    }
    catch (...)
    {}
    
    Person& pRef = *p; // Undefined behavior: dereferencing null
    typeid(pRef);      // does not meet requirements to throw std::bad_typeid
    // because the expression for typeid is not the result
    // of applying the unary * operator
}
