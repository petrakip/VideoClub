#include "graphics.h"
#include "Movie.h"
#include "config.h"
#include "App.h"

using namespace graphics;

void draw() {
	App* app = reinterpret_cast<App*>(getUserData());
	app->draw();
}

void update(float ms) {
	App* app = reinterpret_cast<App*>(getUserData());
	app->update();
}

int main(int argc, char** argv)
{
	App app;

	createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Video Club");
	setUserData(&app);

	setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	//setFullScreen(true);

	setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
	preloadBitmaps(ASSET_PATH);
	
	setDrawFunction(draw);
	setUpdateFunction(update);

	startMessageLoop();

	destroyWindow();
	return 0;
}