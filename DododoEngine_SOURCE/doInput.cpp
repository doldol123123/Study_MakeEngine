#include "doInput.h"

namespace dododo
{
	vector<Input::Key> Input::Keys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M', 
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		
	};

	void Input::Initailize()
	{
		CreateKeys();
	}
	
	void Input::Update()
	{
		UpdateKeys();
	}

	void Input::CreateKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	void Input::UpdateKeys()
	{
		for (size_t i = 0; i < Keys.size(); i++)
		{
			//키가 눌렸다
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (Keys[i].bPressed == true)		//앞 전에도 눌러져 있었다면
				{
					Keys[i].state = eKeyState::Pressed;
				}
				else
				{
					Keys[i].state = eKeyState::Down;
				}
				Keys[i].bPressed = true;
			}
			else
			{
				if (Keys[i].bPressed == true)		//앞 전에도 눌러져 있었다면
				{
					Keys[i].state = eKeyState::Up;
				}
				else
				{
					Keys[i].state = eKeyState::None;
				}
				Keys[i].bPressed = false;
			}
		}
	}
}
