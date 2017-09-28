
#ifndef SceneManager_hpp
#define SceneManager_hpp

class SceneManager {
private:
	void createScene(const char* name, Scene* scene);

public:
	std::map<const char*, Scene*> scenes;
	const char* activeScene;
	const char* checkedScene;

	// Constructors
	SceneManager();
	~SceneManager();

	void start();
	void update();

	void setActiveScene(const char* name);

};

#endif /* SceneManager_hpp */

/*
Static Functions

CreateScene	Create an empty new scene at runtime with the given name.
GetActiveScene	Gets the currently active scene.
GetSceneAt	Get the scene at index in the SceneManager's list of added scenes.
GetSceneByBuildIndex	Get a scene struct from a build index.
GetSceneByName	Searches through the scenes added to the SceneManager for a scene with the given name.
GetSceneByPath	Searches all scenes added to the SceneManager for a scene that has the given asset path.
LoadScene	Loads the scene by its name or index in Build Settings.
LoadSceneAsync	Loads the scene asynchronously in the background.
MergeScenes	This will merge the source scene into the destinationScene.
MoveGameObjectToScene	Move a GameObject from its current scene to a new Scene.
SetActiveScene	Set the scene to be active.
UnloadSceneAsync	Destroys all GameObjects associated with the given scene and removes the scene from the SceneManager.
*/
