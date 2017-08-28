#include "tree.hpp"

USTEMP
BasicTree<T>::BasicTree()
{
}

USTEMP
BasicTree<T>::BasicTree(T const& first_val)
{
    m_first_nodes.push_back(std::make_unique<Node<T>>(first_val)); //On ajoute un nouveau pointeur au tableau
}

USTEMP
BasicTree<T>::~BasicTree()
{
    for(auto& ref: m_first_nodes)
        ref.reset();
}
