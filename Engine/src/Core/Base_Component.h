#ifndef BASE_COMPONENT_H
#define BASE_COMPONENT_H

#include <glew.h>
#include <map>
#include <string>
#include "Core/Component_Structs.h"

class Base_Component {
public:
	Base_Component();
	~Base_Component();
	virtual void Init(Base_Info* info);
	virtual void Init_Dependencies(const std::map<int, Base_Component*>& comps);
};

#endif