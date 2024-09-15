#include "Engine.h"
#include <memory>


int main()
{
	std::unique_ptr<TsrtEngine::tsrtEngine> engine = std::make_unique<TsrtEngine::tsrtEngine>();
	engine->RunEngine();
	engine->DestroyEngine();

}