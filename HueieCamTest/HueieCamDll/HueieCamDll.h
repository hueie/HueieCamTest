// HUEIECAMDLL.h

#ifdef HUEIECAMDLL_EXPORTS
#define HUEIECAMDLL_API __declspec(dllexport)
#else
#define HUEIECAMDLL_API __declspec(dllimport)
#endif

namespace HueieCam
{
	// This class is exported from the HUEIECAMDLL.dll
	class HueieCam
	{
	public:
		HUEIECAMDLL_API void run();
		HUEIECAMDLL_API void test();
		HUEIECAMDLL_API void setPosition(int t, int b, int l, int r);

	};
}
