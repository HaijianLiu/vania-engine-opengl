
#ifndef Camera_hpp
#define Camera_hpp

class Camera {
private:
	Window* window;
	int startScreenWidth, startScreenHeight;


public:
	// matrix uniform
	glm::mat4 projection, view;

	// Camera Position
	glm::vec3 position = glm::vec3(0.0f,0.0f,10.0f);
	// target
	GameObject* target = nullptr;
	bool switching = false;
	float switchSpeed = 0.5f;

	Camera();
	~Camera();

	void updatePosition();
	void updateUniform();

	void switchTarget(GameObject* target);
};

#endif /* Camera_hpp */
