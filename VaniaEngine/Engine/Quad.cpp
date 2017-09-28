
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Quad::Quad() {
	// setup plane VAO
	unsigned int vbo;
	float vertices[] = {
		// vertex             // texCoord
		-1.0f,  1.0f, 0.0f,   0.0f, 1.0f, // left top
		-1.0f, -1.0f, 0.0f,   0.0f, 0.0f, // left bottom
		 1.0f,  1.0f, 0.0f,   1.0f, 1.0f, // right top
		 1.0f, -1.0f, 0.0f,   1.0f, 0.0f, // right bottom
	};
	glGenVertexArrays(1, &this->vao);
	glGenBuffers(1, &vbo);
	glBindVertexArray(vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Quad::~Quad() {
	glDeleteBuffers(1, &this->vao);
}


/*------------------------------------------------------------------------------
< draw >
------------------------------------------------------------------------------*/
void Quad::draw() {
	glBindVertexArray(this->vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
}
