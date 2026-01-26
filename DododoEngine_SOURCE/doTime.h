#pragma once
#include "CommonInclude.h";

namespace dododo
{
	class Time
	{
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }
	private:
		static LARGE_INTEGER CpuFrequency;		// 내 CPU의 고유 진동 수
		static LARGE_INTEGER PrevFrequency;	// 이전 진동 수
		static LARGE_INTEGER CurrentFrequency;	// 현재 진동수
		static float DeltaTimeValue;

	};
}


