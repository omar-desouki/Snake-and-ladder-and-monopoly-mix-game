#include "GameObject.h"


GameObject::GameObject()
{
}

GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}


bool GameObject:: AreOverlapping(GameObject* Obj) const 
{
	return false;
}

GameObject::~GameObject()
{
}