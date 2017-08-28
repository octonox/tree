#include <memory>
#include <string>
#include <iostream>

class Test
{
public:
    Test(std::string const& name)
    {
        std::cout << "Construction de " << name << std::endl;
    }

    ~Test()
    {
        std::cout << "Destruction" << std::endl;
    }

    void in()
    {
        std::cout << "utilisation" << std::endl;
    }
};

int main()
{
    //On crée un pointeur partagé
    std::shared_ptr<Test> ptr1 { std::make_shared<Test>("test") };
    ptr1->in();

        {
            //On copie l'objet dans un deuxieme pointeur
            std::shared_ptr<Test> ptr2 { ptr1 };
            //Deux objets gèrent maintenant l'objet alloué

            ptr2->in();
        }
        //Maintenant il n'y a plus que ptr1 qui gère l'objet
    ptr1->in();
    return 0;
}
