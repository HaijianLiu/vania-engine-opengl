
#ifndef NoneObject_hpp
#define NoneObject_hpp

class NoneObject : public GameObject {
private:
	/* data */

public:
	// Constructors
	NoneObject();
	~NoneObject();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
};

#endif /* NoneObject_hpp */
