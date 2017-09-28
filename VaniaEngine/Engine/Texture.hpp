
#ifndef Texture_hpp
#define Texture_hpp

class Texture {
private:
	/* data */

public:
	unsigned int textureID;
	int width, height, channel;

	Texture(const char* path);
	~Texture();

	void loadTexture(const char* path);
};

#endif /* Texture_hpp */
