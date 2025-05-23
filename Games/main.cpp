#include <Sources/PCH.h>

int main()
{
	try
	{
		DX3D::Game Game({ { 1280, 720 }, DX3D::Logger::LogLevel::Information });
		Game.Run();
	}
	catch (const std::runtime_error&)
	{
		return EXIT_FAILURE;
	}
	catch (const std::exception&)
	{
		return EXIT_FAILURE;
	}
	catch (...)
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}