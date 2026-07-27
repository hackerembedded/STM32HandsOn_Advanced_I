#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
extern "C" volatile char changeScreen;
#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/Application.hpp>

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if(changeScreen == 2)
	{
		changeScreen = 0;
		FrontendApplication* app = static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
		app->gotoScreen2ScreenNoTransition();
	}
	if(changeScreen == 1)
	{
		changeScreen = 0;
		FrontendApplication* app = static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
		app->gotoScreen1ScreenNoTransition();
	}
}
