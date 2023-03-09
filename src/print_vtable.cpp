#include <iostream>
#include <functional>

typedef void(*Fun)(void);  //函数指针

class Base {
public:
    virtual void f() { std::cout << "Base::f" << std::endl; }
    virtual void g() { std::cout << "Base::g" << std::endl; }
    virtual void e() { std::cout << "Base::e" << std::endl; }
private:
    int value;
};

class ChildOne : public Base
{
public:
    virtual void f() { std::cout << "ChildOne::f" << std::endl; }
    virtual void g() { std::cout << "ChildOne::g" << std::endl; }
};


int main()
{
    Base *p = nullptr;
    Fun pfun;

    std::cout << "--------------- base class vtable -----------------" << std::endl;
    p = new Base();
    printf("虚表地址:%p\n", *(int64_t *)p);
    printf("第一个虚函数地址:%p\n", *(int64_t *)*(int64_t *)p);
    printf("第二个虚函数地址:%p\n", *((int64_t *)*(int64_t *)p + 1));
    printf("第三个虚函数地址:%p\n", *((int64_t *)*(int64_t *)p + 2));
 
    pfun = (Fun)*((int64_t *)*(int64_t *)p);  //vitural f();
    printf("f():%p\n", pfun);
    pfun();
 
    pfun = (Fun)(*((int64_t *)*(int64_t *)p + 1));  //vitural g();
    printf("g():%p\n", pfun);
    pfun();

    pfun = (Fun)(*((int64_t *)*(int64_t *)p + 2));  //vitural g();
    printf("e():%p\n", pfun);
    pfun();
    delete p;

    std::cout << "--------------- derived class vtable -----------------" << std::endl;
    p = new ChildOne();
    printf("虚表地址:%p\n", *(int64_t *)p);
    printf("第一个虚函数地址:%p\n", *(int64_t *)*(int64_t *)p);
    printf("第二个虚函数地址:%p\n", *((int64_t *)*(int64_t *)p + 1));
    printf("第三个虚函数地址:%p\n", *((int64_t *)*(int64_t *)p + 2));
    
    pfun = (Fun)*((int64_t *)*(int64_t *)p);  //vitural f();
    printf("f():%p\n", pfun);
    pfun();
 
    pfun = (Fun)(*((int64_t *)*(int64_t *)p + 1));  //vitural g();
    printf("g():%p\n", pfun);
    pfun();

    pfun = (Fun)(*((int64_t *)*(int64_t *)p + 2));  //vitural g();
    printf("e():%p\n", pfun);
    pfun();
    delete p;
}