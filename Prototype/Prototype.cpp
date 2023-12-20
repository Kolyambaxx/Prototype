// Prototype.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <unordered_map>


class Prototype {
public:
    virtual ~Prototype() = default;
    virtual Prototype* clone() const = 0;
    virtual void printInfo() const = 0;
};


class ConcretePrototypeA : public Prototype {
public:
    Prototype* clone() const override {
        return new ConcretePrototypeA(*this);
    }

    void printInfo() const override {
        std::cout << "Concrete Prototype A" << std::endl;
    }
};


class ConcretePrototypeB : public Prototype {
public:
    Prototype* clone() const override {
        return new ConcretePrototypeB(*this);
    }

    void printInfo() const override {
        std::cout << "Concrete Prototype B" << std::endl;
    }
};


class PrototypeManager {
public:
    Prototype* getPrototype(const std::string& key) const {
        auto it = prototypes.find(key);
        if (it != prototypes.end()) {
            return it->second->clone();
        }
        return nullptr;
    }

    void registerPrototype(const std::string& key, Prototype* prototype) {
        prototypes[key] = prototype;
    }

private:
    std::unordered_map<std::string, Prototype*> prototypes;
};

int main() {
    
    ConcretePrototypeA prototypeA;
    ConcretePrototypeB prototypeB;

    
    PrototypeManager manager;
    manager.registerPrototype("A", &prototypeA);
    manager.registerPrototype("B", &prototypeB);

   
    Prototype* clonedA = manager.getPrototype("A");
    Prototype* clonedB = manager.getPrototype("B");

    
    if (clonedA) {
        clonedA->printInfo();
        delete clonedA;
    }

    if (clonedB) {
        clonedB->printInfo();
        delete clonedB;
    }

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
