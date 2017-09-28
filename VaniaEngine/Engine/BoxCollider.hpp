
#ifndef BoxCollider_hpp
#define BoxCollider_hpp

class BoxCollider {
private:
	std::vector<BoxCollider*>* colliders;

public:
	GameObject* gameObject;

	const char* tag = "none";
	glm::vec2 offset, size, halfSize;

	bool trigger = false; // if check collision with others
	bool active = true; // if check collision
	bool enter = false; // will be set to true before OnTriggerEnter and be set to false after OnTriggerEnter

	BoxCollider(GameObject* gameObject, float x, float y, float w, float h);
	~BoxCollider();
};

#endif /* BoxCollider_hpp */
