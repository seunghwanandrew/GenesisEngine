#pragma once

namespace DX3D
{
	class Rect
	{
	public:
		Rect() = default;
		Rect(int Width, int Height);
		Rect(int Left, int Top, int Width, int Height);

	public:
		int Left{};
		int Top{};
		int Width{};
		int Height{};
	};
}


