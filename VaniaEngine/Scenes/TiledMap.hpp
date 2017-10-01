
#ifndef TiledMap_hpp
#define TiledMap_hpp

class TiledMap {
private:
	// tiled map Setting
	int tileSize = 16;
	glm::i32vec2 mapSize = glm::i32vec2(225,90);
	glm::i32vec2 tilesetsSize = glm::i32vec2(384/16,320/16);

public:
	// tiled map data
	std::map<const char*, std::vector<glm::i32vec2>> mapDatas;
	std::map<const char*, std::vector<GameObject*>> gameObjects;

	TiledMap();
	~TiledMap();

	bool loadMapData(const char* name, const char* path);
	void createGameObject(const char* name);
	void setGameObject(const char* name);
	void setTile(GameObject* gameObject, int mapID, int tileID);
	void setPosition(GameObject* gameObject, int mapID);
	void reset();
};

#endif /* TiledMap_hpp */
