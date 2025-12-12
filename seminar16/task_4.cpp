#include <iostream>
#include <vector>

class Entity {
protected:
    std::string name;
    int hp;

public:
    Entity(const std::string& name, int hp);
    virtual ~Entity();
    
    virtual void update() = 0;                // чисто виртуальное обновление за один игровой тик
    virtual std::string type() const;         // по умолчанию "Entity"
    virtual void printInfo() const;           // печать типа, имени и hp
    virtual bool isAlive() const;             // hp > 0
};