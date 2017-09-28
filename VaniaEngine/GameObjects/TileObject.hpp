
#ifndef TileObject_hpp
#define TileObject_hpp

class TileObject : public GameObject {
private:
	/* data */

public:
	// Constructors
	TileObject();
	~TileObject();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
};

#endif /* TileObject_hpp */
