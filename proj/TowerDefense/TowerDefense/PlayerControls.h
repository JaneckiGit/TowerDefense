#include <KeyHandler.h>

class PlayerControls
{
public:
	static void moveUp();
	static void moveDown();
	static void moveLeft();
	static void moveRight();

	static KeyHandler getControls();
};