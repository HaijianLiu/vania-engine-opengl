
#ifndef Animation_hpp
#define Animation_hpp

class Animation {
private:
	Timer* timer;
	Resources* resources;

public:
	Texture* texture;
	std::vector<glm::mat3> slices;

	const char* textureName;
	glm::vec2 divide, sliceSize;
	float sampleTime, lastTime = 0;
	unsigned int sliceMax, currentSlice = 0;

	Animation(const char* textureName, float divideX, float divideY, float sampleTime);
	~Animation ();

	void start();
	void update(Sprite* sprite);
};

#endif /* Animation_hpp */
