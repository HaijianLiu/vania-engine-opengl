
#ifndef Scene_hpp
#define Scene_hpp

class Scene {
private:
	// Scene GameObjects and Colliders
	std::vector<GameObject*> gameObjects;
	std::vector<BoxCollider*> colliders;

public:
	// tiled map
	TiledMap* tiledMap;
	// BGM
	Audio* bgm = nullptr;

	// Frame Delay
	bool frameSkip = true; // skip the first frame

	// Constructors
	Scene();
	virtual ~Scene();

	void start();
	void update();

	virtual void load() = 0;
	virtual void set() = 0;
	virtual void check() = 0;
	virtual void reset();

	void setBackground(unsigned int id, const char* textureName);
	void setBGM(const char* name);

	void fixCamera(const char* name);
	bool checkCollision(BoxCollider* a, BoxCollider* b);
	void checkCollider();
};


#endif /* Scene_hpp */
