#include "Engine.h"


int main()
{
	std::unique_ptr<Tsrt::Engine> Sandbox;
	Sandbox = std::make_unique<Tsrt::Engine>();
	Sandbox->EngineRun();
	Sandbox->EngineDestroyer();
}