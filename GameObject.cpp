#include "GameObject.h"

GameObject::GameObject() : m_Name("GameObject") { }

std::string GameObject::getName() const {
    return m_Name;
}
std::string GameObject::getDetailedName() const {
    return m_detailedName;
}
void GameObject::setDetailedName(std::string in_DetailedName) {
    m_detailedName = in_DetailedName;
}

GameObject::GameObject(std::string in_m_Name){
    m_Name = in_m_Name;
}

GameObject::~GameObject() {}
