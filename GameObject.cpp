#include "GameObject.h"

GameObject::GameObject() {
    m_Name = "GameObject";
}

std::string GameObject::name() const {
    return m_Name;
}

GameObject::GameObject(std::string in_m_Name){
    m_Name = in_m_Name;
}

GameObject::~GameObject() {}
