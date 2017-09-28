
#ifndef Particle_hpp
#define Particle_hpp

class Particle : public GameObject {
private:

public:
	// Parameter
	glm::vec2 startLifeTimeRange = glm::vec2(0.2f,0.5f);
	glm::vec2 startSpeedRange = glm::vec2(0.1f,1.0f);
	glm::vec2 startSizeRange = glm::vec2(0.01f,0.1f);
	glm::vec2 startAngleRange = glm::vec2(0.0f,2.0f*PI);

	// status
	bool sizeOverLifeTime = true;
	float gravity = 1.5f;
	float verticalSpeed = 0.0f;
	float startLifeTime;
	float startSpeed;
	float startSize;
	float startAngle;

	// Constructors
	Particle();
	~Particle();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);

	// Functions
	void instantiate(Transform* transform);
};

#endif /* Particle_hpp */
