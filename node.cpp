//#include "node.hpp"
/*#define USTEMP template<typename T> //C'est lourd d'écrire "template<typename T>" à chaque fois

USTEMP
Node<T>::Node(T const value) : m_value { value }
{
#ifdef DEBUG
    std::cout << "created" << std::endl;
#endif
}

USTEMP
Node<T>::~Node()
{
    /*detruire tout les objets pointé par les pointeurs du vector
#ifdef DEBUG
    std::cout << "destructed" << std::endl;
#endif
}

USTEMP
T Node<T>::value() const
{
    return m_value;
}

USTEMP
void Node<T>::setValue(T const newValue)
{
    m_value = newValue;
}

USTEMP
void Node<T>::addChild(T const value)
{
    m_children.push_back(std::make_unique<Node<T>>(value)); //On ajoute dans le vector un unique_ptr qui gère une classe Node que l'on initialise avec value
    std::cout << "Node created" << std::endl;
}
*/
