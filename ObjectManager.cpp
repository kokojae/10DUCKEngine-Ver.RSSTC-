#include "DXUT.h"
#include "ObjectManager.h"
#include "10DUCKEngine.h"

std::list<GameObject*> ObjectManager::object_list = std::list<GameObject*>();
std::list<GameObject*> ObjectManager::collider_list = std::list<GameObject*>();

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

bool ObjectManager::Sort(const GameObject* a, const GameObject* b)
{
	return a->z > b->z;
}

void ObjectManager::Update()
{
	std::list<GameObject*>::iterator it = object_list.begin();

	while (it != object_list.end())
	{
		GameObject* inst = it._Ptr->_Myval;

		if (inst->destroy)
		{
			if (inst->destroy_me)
				inst->DestroyMe();
			collider_list.remove(inst);
			object_list.erase(it++);
			delete(inst);
			continue;
		}

		inst->Update();
		it++;
	}
}

void ObjectManager::LateUpdate()
{
	for (GameObject* inst : object_list)
	{
		if (inst->destroy)
			continue;
		inst->LateUpdate();
	}
}

void ObjectManager::Render()
{
	for (GameObject* inst : object_list)
	{
		if (inst->destroy)
			continue;
		inst->Render();
	}
}

void ObjectManager::Release()
{
	TextureManager::ReleaseTexture();
}

void ObjectManager::Clear()
{
	for (GameObject* inst : object_list)
	{
		inst->destroy = true;
		inst->destroy_me = false;
	}
}

GameObject* ObjectManager::ColliderCheck(RECT* objRect, int layer)
{
	for (GameObject* inst : object_list)
	{
		if ((layer & inst->collider.layer) == 0)
			continue;
		if (inst->collider.enable == false)
			continue;
		if (inst->destroy)
			continue;

		if (IntersectRect(&RECT(), objRect, inst->GetRect()))
			return inst;
	}
	return nullptr;
}

GameObject* ObjectManager::SearchObject(std::wstring objName)
{
	for (GameObject* inst : object_list)
	{
		if (inst->name == objName)
			return inst;
	}
	return nullptr;
}
