#include "Main_Manager.h"

Main_Manager::Main_Manager(int width, int height, const std::string& title) {
	this->height = height;
	this->width = width;
	bg_color = new Color(0.5f, 0.5f, 0.5f, 1.0f);
	Init_Scene();
	display = new Display(width, height, title);
	event_system = Event_System::getInstance();
	render = new Renderer;
	render->Init(static_cast<Camera*>(Scene["camera"]));
}

Main_Manager::~Main_Manager() {
	render->ShutUp();
	delete bg_color;
	delete render;
	delete display;
	Event_System::deleteInstance();
	for (std::map<std::string, BaseObject*>::iterator i = Scene.begin(); i != Scene.end(); ++i) {
		delete (*i).second;
	}
}

void Main_Manager::Set_Bg_Color(const Color& color) {
	bg_color->red = color.red;
	bg_color->green = color.green;
	bg_color->blue = color.blue;
	bg_color->alpha = color.alpha;
}

void Main_Manager::Init_Scene() {
	Add_Camera();
}

void Main_Manager::Add_Camera() {
	Transform_Component_Info trans(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	Add_Object<Camera>("camera", &trans);
	Camera_Component_Info cam(90.0f, 0.1f, 100.0f, (float)width / (float)height);
	Scene["camera"]->Add_Component<Camera_Component>(CAMERA_COMPONENT, &cam);
}

void Main_Manager::Update_Objects() {
	for (int i = 0; i < objects_names.size(); ++i) {
		Scene[objects_names[i]]->Update();
	}
}

void Main_Manager::Update(float r, float g, float b, float a) {
	display->Clean_Display(r, g, b, a);
	Update_Objects();
	render->Update(Scene);
	display->Swap();
}

void Main_Manager::Game_Loop() {
	while (true) {
		event_system->Get_Events();
		if (event_system->Is_App_Closed()) {
			break;
		}
		Update(bg_color->red, bg_color->green, bg_color->blue, bg_color->alpha);
	}
}

BaseObject* Main_Manager::GetObjectByName(const std::string& name) {
	return Scene[name];
}