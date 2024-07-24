#include "Application.h"

void Application::Start()
{
}

void Application::Update()
{
}

void Application::Draw()
{
	Kd3DDevice::GetInstance().Begin();


	Kd3DDevice::GetInstance().End();
}
