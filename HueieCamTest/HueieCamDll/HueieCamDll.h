// HUEIECAMDLL.h
#ifdef __cplusplus
extern "C" {
#endif

#ifdef HUEIECAMDLL_EXPORTS
#define HUEIECAMDLL_API __declspec(dllexport)
#else
#define HUEIECAMDLL_API __declspec(dllimport)
#endif


	/**
	* Analyze Data
	* @param data [in] array of doubles
	* @param dataLength [in] number of floats in data
	* @param weight [in]
	* @param status [in] enum with data status
	* @param results  [out] array of MaxResults (pre-allocated) DLLResult structs.
	*                    Up to MaxResults results will be returned.
	* @param nResults  [out] the actual number of results being returned.
	* https://stackoverflow.com/questions/20419415/c-sharp-call-c-dll-passing-pointer-to-pointer-argument
	*/

namespace HueieCam
{
	// This class is exported from the HUEIECAMDLL.dll
	class HueieCam
	{
	public:
		
			HUEIECAMDLL_API void run();
			HUEIECAMDLL_API void test();
			HUEIECAMDLL_API void __thiscall setPosition(int t, int b, int l, int r);
	};
}

#ifdef __cplusplus
}
#endif