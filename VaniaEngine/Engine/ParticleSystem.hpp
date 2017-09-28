
#ifndef ParticleSystem_hpp
#define ParticleSystem_hpp

class ParticleSystem {
private:

public:
	std::vector<Particle*> particles;
	int rate = 10;
	bool rateOverTime = true;

	ParticleSystem(unsigned int size);
	~ParticleSystem();

	void setTexture(const char* name);
	void instantiate(Transform* transform);

	// Set Parameters
	void setStartLifeTimeRange(float min, float max);
	void setStartSpeedRange(float min, float max);
	void setStartSizeRange(float min, float max);
	void setStartAngleRange(float min, float max);
	void setGravity(float gravity);
	void setColor(float r, float g, float b, float a);
};

#endif /* ParticleSystem_hpp */
