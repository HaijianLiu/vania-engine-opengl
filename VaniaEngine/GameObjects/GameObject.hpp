
#ifndef GameObject_hpp
#define GameObject_hpp

class GameObject {
private:
	// List of GameObjects
	std::vector<GameObject*>* gameObjects;

public:
	// GameObject members
	Transform* transform;
	Sprite* sprite;
	Status* status;

	// setting
	bool active = true; // wont update() fixedUpdate() draw() checkCollider()
	bool visible = true; // wont draw()

	GameObject();
	virtual ~GameObject();

	void defaultStart();
	void draw();

	virtual void start() = 0;
	virtual void update() = 0;
	virtual void onTriggerEnter(BoxCollider* other) = 0;
	virtual void fixedUpdate();
	virtual void UIUpdate();
	virtual void reset();
};

#endif /* GameObject_hpp */
