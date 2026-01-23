#include "GameObject.h"
#include "doInput.h"

namespace dododo
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += 0.01f;
		}
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC hdc)
	{
		//파랑 브러쉬 생성
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));

		//파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);


		Rectangle(hdc, 100 + mX, 200 + mY, 200 + mX, 100 + mY);

		//다시 흰색 원본브러쉬로 선택
		SelectObject(hdc, oldbrush);

		//파랑 브러쉬 삭제
		DeleteObject(brush);
	}
}


