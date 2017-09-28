
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< globals >
------------------------------------------------------------------------------*/
Window* window = new Window("vania", SCREEN_WIDTH, SCREEN_HEIGHT);
RenderPass* renderPass = new RenderPass();
Game* game = new Game();


/*------------------------------------------------------------------------------
< clear >
------------------------------------------------------------------------------*/
void clear() {
	delete window;
	delete renderPass;
	delete game;
	glfwTerminate(); // glfw: terminate, clearing all previously allocated GLFW resources.
}


/*------------------------------------------------------------------------------
< start >
------------------------------------------------------------------------------*/
void start() {
	game->start();
	renderPass->start(1);
}


/*------------------------------------------------------------------------------
< update >
------------------------------------------------------------------------------*/
void update() {
	game->update();
}


/*------------------------------------------------------------------------------
< get functions >
------------------------------------------------------------------------------*/
Window* getWindow() {
	return window;
}
Game* getGame() {
	return game;
}


/*==============================================================================
< main >
==============================================================================*/
int main() {
	// Start
	start();

	// Game Loop
	while (!glfwWindowShouldClose(window->window)) {
		if (glfwGetKey(window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window->window, true);
		// Update
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		renderPass->use();
			update();
		renderPass->finish();
		renderPass->draw();
		glfwSwapBuffers(window->window);
		glfwPollEvents();
	}

	// clear
	clear();
	return 0;
}
