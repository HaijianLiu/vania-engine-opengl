
#ifndef OffsetObject_hpp
#define OffsetObject_hpp

class OffsetObject : public GameObject {
private:

public:
	GameObject* parent;
	glm::vec2 offset;

	// Constructors
	OffsetObject(GameObject* parent, float x, float y);
	~OffsetObject();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
	void fixedUpdate();
};

#endif /* OffsetObject_hpp */
