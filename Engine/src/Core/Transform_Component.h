#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "Core/Base_Component.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class Transform_Component: public Base_Component{
public:
	Transform_Component();
	~Transform_Component();
	glm::vec3 Get_Position();
	glm::vec3 Get_Rotation();
	glm::vec3 Get_Scale();
	virtual void Init(Base_Info* info) override;
	void Send_Model(GLuint prog);
private:
	glm::mat4 Get_Model();
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

#endif