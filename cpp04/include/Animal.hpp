#pragma one

class Animal
{

protected:
    std::string _type;

public:

    Animal();
    void Animal(const std::string& type);
    void Animal(const Animal &other);
    Animal& operator=(const Animal& other);
    ~Animal();

    virtual void makeSound();
};



Animal::Animal():_type("default Animal") 
{

}

void Animal::Animal(const std::string& type) : _type(type)
{

}

void Animal::Animal()

void Animal::makeSound(const Animal &other)
{
    if (the != &other)
        *this = other;
}
{
    std::cout << "the animal made Sound Animal " << std::endl;
}


