
#ifndef Player_hpp
#define Player_hpp

class Player : public GameObject {
private:

public:
	// Constructors
	Player ();
	~Player();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
};

#endif /* Player_hpp */
