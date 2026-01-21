#include "GameObject.h"

dododo::GameObject::GameObject()
{
}

dododo::GameObject::~GameObject()
{
}

void dododo::GameObject::Update()
{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}
}

void dododo::GameObject::LateUpdate()
{
}

void dododo::GameObject::Render(HDC hdc)
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

