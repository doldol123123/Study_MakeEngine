#pragma once
#include "CommonInclude.h"

using namespace std;

namespace dododo
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		Left, Right, Down, Up,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initailize();
		static void Update();

		static void CreateKeys();
		static void UpdateKeys();

		static bool GetKeyDown(eKeyCode code)	{ return Keys[(UINT)code].state == eKeyState::Down; };
		static bool GetKeyUp(eKeyCode code)		{ return Keys[(UINT)code].state == eKeyState::Up; };
		static bool GetKey(eKeyCode code)		{ return Keys[(UINT)code].state == eKeyState::Pressed; };
	private:
		//eKeyState mState[] = eKeyState::Up;
		static vector<Key> Keys;
	};
}


