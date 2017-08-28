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
    BasicTree(); //Le constructeur sans première valeur
    BasicTree(T const& first_val); //Constructeur avec première valeur
    virtual ~BasicTree(); //Le destructeur est virtuel car le BasicTree pourrat être dérivé pour faire un binary tree

    Node<T> operator[](BasicTree<T> const& tr);

protected:
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
