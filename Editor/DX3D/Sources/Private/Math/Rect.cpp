#include <Math/Rect.h>

DX3D::Rect::Rect(int Width, int Height)
	: Left(0), Top(0), Width(Width), Height(Height)
{
}

DX3D::Rect::Rect(int Left, int Top, int Width, int Height)
	: Left(Left), Top(Top), Width(Width), Height(Height)
{
}
