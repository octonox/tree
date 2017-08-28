#ifndef NODE_HPP
#define NODE_HPP
#define DEBUG
#include <memory>
#include <vector>
#include <iostream>

//Classe template à sémantique d'identitée(*) qui represente un noeud de l'arbre
template<typename T>
class Node
{
public:
    Node(T const& value) : m_value { value }
    {
        std::cout << "created" << std::endl;
    }//Le constructeur implicite(***) crée un nouveau noeud en initialisant sa valeur

    ~Node()
    {
        for(auto& ref : m_children) //On détruit tout les objets gérés par les pointeurs
            ref.reset();
        std::cout << "destructed" << std::endl;
    }

    T value() const
    {
        return m_value;
    }

    void setValue(T const& newValue)
    {
        m_value = newValue;
    }//Respectivement accesseur et mutateur de la valeur du noeud

    void addChild(T const& value)
    {
        m_children.push_back(std::make_unique<Node<T>>(value)); //On ajoute dans le vector un unique_ptr qui gère une classe Node que l'on initialise avec value
        std::cout << "Node created" << std::endl;
    }//Va créer un noeud enfant

    std::vector<std::unique_ptr<Node<T>>>& children()
    {
        return m_children;
    }//Retourne une référence(****) sur le tableau de pointeur sur les noeuds enfants (utile pour parcourir les noeuds)


private:
    std::vector<std::unique_ptr<Node<T>>> m_children; //Vector qui contient UN pointeur(**) pour chaque noeud enfant
    T m_value;
};

template<typename T>
std::ostream& operator<<(std::ostream& flux, Node<T> const& node)
{
    flux << node.value();
    return flux;
}

template<typename T>
std::istream& operator>>(std::istream& flux, Node<T>& node)
{
    T newValue;
    flux >> newValue;
    node.setValue(newValue);
    return flux;
}

#endif // NODE_HPP



//NOTES
/*:*Sémantique d'identitée car deux noeud ne peuvent pas avoir les mêmes noeuds enfants, donc on ne peut pas copier deux noeuds*/

/*:**On aurait pas pu utiliser des shared pointers,
car en recopiant l'arbre plusieurs pointeur se seraient partagé une même ressource et si le noeud d'un des arbres étaient supprimé,
celui de l'autre le serait aussi, ce qui est impossible*/

/*:***Pour ajouter un noeud il faudra bien faire un push_back(Node())*/
/*:****Il faut absolument récupérer la référence sur le tableau dans une référence car les unique_ptr ne sont pas copiables!!!*/
