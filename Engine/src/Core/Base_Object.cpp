#include "Base_Object.h"

BaseObject::BaseObject() {

}

BaseObject::~BaseObject() {
	for (std::map<int, Base_Component*>::iterator i = components.begin(); i != components.end(); ++i) {
		delete (*i).second;
	}
}

void BaseObject::Init_Component_By_Name(int name, Base_Info* init_info) {
	components[name]->Init(init_info);
	components[name]->Init_Dependencies(components);
}

void BaseObject::Init_Entity() {

}

void BaseObject::Update_Entity() {

}

void BaseObject::Update() {
	Update_Entity();
}

void BaseObject::Init_Object(Transform_Component_Info* inf) {
	Add_Component<Transform_Component>(TRANSFORM_COMPONENT, inf);
}

void BaseObject::Init(Transform_Component_Info* inf) {
	Init_Object(inf);
	Init_Entity();
}

Base_Component* BaseObject::GetComponentByName(int name) {
	if (components.find(name) != components.end()) {
		return components[name];
	}
	else {
		return nullptr;
	}
}