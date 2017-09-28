
#ifndef Status_hpp
#define Status_hpp

class Status {
private:
	/* data */

public:
	float birthTime = 0;
	float hp = 0;
	float damage = 0;
	const char* tag = "none";

	Status();
	~Status();
};

#endif /* Status_hpp */
