using namespace std;
#include <string>
#include <iostream>

class Duck
{
    public:
    virtual ~Duck()=default;
    virtual void quack()=0;
    virtual void fly()=0;
};

class MallardDuck : public Duck
{
    void quack() override
    {
        cout<<"Mallard Duck Quack"<<endl;
    }

    void fly() override
    {
        cout<<"Mallard Duck Fly"<<endl;
    }
};

class Turkey
{
    public:
    Turkey(){}
    virtual ~Turkey()=default;
    virtual void gobble()=0;
    virtual void fly()=0;
};

class WildTurkey : public Turkey
{
    public:
    void gobble()override
    {
        cout<<"Gobble Gobble "<<endl;
    }

    void fly() override
    {
        cout<<"Turkey fly short distance"<<endl;
    }
};

class TurkeyAdapter:public Duck
{
    public:
    Turkey *turkey;
    TurkeyAdapter(Turkey *turkey) : turkey(turkey){}
    void quack()override
    {
        turkey->gobble();
    }
    void fly() override
    {
        for(int i=0;i<5;i++)
            turkey->fly();
    }
};

void testDuck(Duck *duck)
{
    duck->quack();
    duck->fly();
}

int main()
{
    Duck *duck = new MallardDuck();
    Turkey *turkey = new WildTurkey();
    Duck *turkeyAdapter = new TurkeyAdapter(turkey);
    cout<<"The Turkey says..."<<endl;
    turkey->gobble();
    turkey->fly();
    cout<<"The Duck says..."<<endl;
    testDuck(duck);
    cout<<"The TurkeyAdapter says..."<<endl;
    testDuck(turkeyAdapter);
}