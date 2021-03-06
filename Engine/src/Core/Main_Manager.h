#ifndef MAIN_MANAGER_H
#define MAIN_MANAGER_H

#include <map>
#include <string>
#include <vector>
#include "Core/Base_Object.h"
#include "Core/Display.h"
#include "Event_System/Event_System.h"
#include "Renderer/Camera.h"
#include "Renderer/Renderer.h"

class Main_Manager {
public:
	Main_Manager(int width, int height, const std::string& title);
	~Main_Manager();
	template<typename T>
	void Add_Object(const std::string& name, Transform_Component_Info* tinf) {
		Scene[name] = new T;
		Scene[name]->Init(tinf);
		objects_names.push_back(name);
	}
	void Set_Bg_Color(const Color& color);
	BaseObject* GetObjectByName(const std::string& name);
	void Game_Loop();
private:
	void Update_Objects();
	void Init_Scene();
	void Add_Camera();
	void Update(float r, float g, float b, float a);
	std::map<std::string, BaseObject*> Scene;
	std::vector<std::string> objects_names;
	Renderer* render;
	Display* display;
	Event_System* event_system;
	Color* bg_color;
	int width;
	int height;
};

#endif