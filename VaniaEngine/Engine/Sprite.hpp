
#ifndef Sprite_hpp
#define Sprite_hpp

class Sprite {
private:
	Quad* quad;
	// uniform
	glm::mat3 matFlipX = {
		-1.0f,0.0f,0.0f,
		 0.0f,1.0f,0.0f,
		 1.0f,0.0f,1.0f,
	};
	glm::vec4 color = glm::vec4(1.0f);

	// effect
	float startEffect = 0;
	float flashTime = 0.5f;
	bool flashing = false;

public:
	// this gameObject
	GameObject* gameObject;
	// sprite member
	Shader* shader;
	Texture* texture;
	// uniform
	glm::mat3 slice = glm::mat3(1.0f);
	// flip flag
	bool flipX = false;


	Sprite();
	~Sprite();

	void start();
	void draw();

	void setSlice(float offsetX, float offsetY, float sizeX, float sizeY);
	void setColor(float r, float g, float b, float a);
	void effect();
	void flash(float duration);
};

#endif /* Sprite_hpp */
