
#ifndef Audio_hpp
#define Audio_hpp

class Audio {
private:
	const char* path;

public:
	bool loop = false;

	Audio(const char* path);
	~Audio();

	bool load();
	void play();
	bool playing();
	void stop();
	void reset();
};

#endif /* Audio_hpp */
