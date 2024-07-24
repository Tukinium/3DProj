#pragma once
class Application
{
public:
	void Start();
	void Update();
	void Draw();
private:
	Application() = default;
	~Application() = default;


public:
	static Application& GetInstance()
	{
		static Application instance;
		return instance;
	}
};
