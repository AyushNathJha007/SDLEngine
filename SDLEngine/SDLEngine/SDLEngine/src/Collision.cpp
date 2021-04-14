
#include "Collision.h"

bool Collision::CheckCollisonAABB(const SDL_Rect & RectA, const SDL_Rect & RectB)
{
	return (RectA.x + RectA.w >= RectB.x && RectB.x + RectB.w >= RectA.x && RectA.y + RectA.h >= RectB.y && RectB.y + RectB.h >= RectA.y);
}
