#ifndef TREE_HPP
#define TREE_HPP
#define USTEMP template<typename T>
#include "node.hpp"

//fournir les operateurs [], =, ==, <, >, <=, >=, parcourir les noeud

//Classe template a semantique de valeur qui represente un arbre
template<typename T>
class BasicTree
{
public:
    BasicTree()
    {
    }//Le constructeur sans première valeur

    BasicTree(T const& first_val)
    {
        m_first_nodes.push_back(std::make_unique<Node<T>>(first_val)); //On ajoute un nouveau pointeur au tableau
    }

    //Constructeur avec première valeur
    virtual ~BasicTree()
    {
        for(auto& ref: m_first_nodes)
            ref.reset();
    }//Le destructeur est virtuel car le BasicTree pourrat être dérivé pour faire un binary tree

    std::size_t size()
    {
        std::size_t i { 0 }; //Compteur
        for(auto& ref: m_first_nodes)
        {
            ++i;
            i += parcourir_for_size(ref);
        }
        return i;
    }//Renvoie le nombre de noeud de l'arbre

    std::vector<std::unique_ptr<Node<T>>>& child()
    {
        return m_first_nodes;
    }

    Node<T> operator[](BasicTree<T> const& tr)
    {
        return Node<int>(5);
    }

protected:
    std::size_t parcourir_for_size(std::unique_ptr<Node<T>>& ptr)
    {
        std::size_t i { 0 };
        for(auto& ref: ptr->children())
        {
            ++i;
            i += parcourir_for_size(ref);
        }
        return i;
    }

    std::vector<std::unique_ptr<Node<T>>> m_first_nodes;
};

USTEMP
bool operator==(BasicTree<T> const& tr1, BasicTree<T> const& tr2);

USTEMP
bool operator!=(BasicTree<T> const& tr1, BasicTree<T> const& tr2);

USTEMP
bool operator<(BasicTree<T> const& tr1, BasicTree<T> const& tr2);

USTEMP
bool operator>(BasicTree<T> const& tr1, BasicTree<T> const& tr2);

USTEMP
bool operator<=(BasicTree<T> const& tr1, BasicTree<T> const& tr2);

USTEMP
bool operator>=(BasicTree<T> const& tr1, BasicTree<T> const& tr2);

#endif // TREE_HPP
