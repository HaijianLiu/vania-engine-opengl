
#ifndef Timer_hpp
#define Timer_hpp

class Timer {
private:
	float lastTime = 0;

public:
	float currentTime = 0;
	float deltaTime = 0;

	Timer();
	~Timer();

	void start();
	void setTime();
	void update();
	bool checkFPS(int frameRate);
};

#endif /* Time_hpp */
