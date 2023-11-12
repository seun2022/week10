#include "yuhanCG.h"
#include <Windows.h>
void DrawBonobono(HWND drawingView, HDC hdc, int Shape, bool SpacePressed) {
	if (Shape == 3 && SpacePressed == false) {// ���뺸�� ����
		PAINTSTRUCT ps;
		// �Ǻλ�
		HBRUSH skinBrush = CreateSolidBrush(RGB(127, 200, 255));
		SelectObject(hdc, skinBrush);
		// �׸��� ���� �Ǻ� �κ��� �׸��ϴ�.
		Ellipse(hdc, 211, 37, 541, 367);

		// �� ��
		HBRUSH mouthBrush = CreateSolidBrush(RGB(255, 150, 255));
		SelectObject(hdc, mouthBrush);
		Ellipse(hdc, 356, 195, 396, 320);

		// �� �� �κ�
		HBRUSH Whites = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, Whites);
		Ellipse(hdc, 326, 210, 376, 250);
		Ellipse(hdc, 376, 210, 426, 250);

		// �� �κ� (�� ���� Ư���� ������� �ʾ����Ƿ� �⺻ �������� ����մϴ�.)
		HBRUSH Blacks = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hdc, Blacks);
		Ellipse(hdc, 256, 170, 266, 190);
		Ellipse(hdc, 496, 170, 486, 190);

		// ���� �� �κ�
		Ellipse(hdc, 356, 190, 396, 230);

		// �� ������
		SelectObject(hdc, Whites);
		Ellipse(hdc, 258, 175, 266, 180);
		Ellipse(hdc, 488, 175, 496, 180);
		//����
		MoveToEx(hdc, 346, 225, NULL);
		LineTo(hdc, 316, 210);

		MoveToEx(hdc, 406, 225, NULL);
		LineTo(hdc, 436, 210);

		MoveToEx(hdc, 346, 235, NULL);
		LineTo(hdc, 316, 250);

		MoveToEx(hdc, 406, 235, NULL);
		LineTo(hdc, 436, 250);
		// ����� �귯�� ���ҽ��� �����մϴ�.
		DeleteObject(skinBrush);
		DeleteObject(mouthBrush);
		DeleteObject(Whites);
		DeleteObject(Blacks);

		/*// �߾Ӽ� ���߿� �����
		MoveToEx(hdc, 376, 0, NULL);
		LineTo(hdc, 376, 480);
		MoveToEx(hdc, 0, 184, NULL);
		LineTo(hdc, 800, 184);*/

		EndPaint(drawingView, &ps);
	}
	else if (Shape == 3 && SpacePressed == true) {// ���뺸�� ������
		PAINTSTRUCT ps;
		// �Ǻλ�
		HBRUSH skinBrush = CreateSolidBrush(RGB(127, 200, 255));
		SelectObject(hdc, skinBrush);
		// �׸��� ���� �Ǻ� �κ��� �׸��ϴ�.
		Ellipse(hdc, 211, 37, 541, 367);

		// �� ��
		HBRUSH mouthBrush = CreateSolidBrush(RGB(255, 150, 255));
		SelectObject(hdc, mouthBrush);
		Ellipse(hdc, 356, 195, 396, 320);

		// �� �� �κ�
		HBRUSH Whites = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, Whites);
		Ellipse(hdc, 326, 210, 376, 250);
		Ellipse(hdc, 376, 210, 426, 250);

		// �� �κ�
		//�޴�
		MoveToEx(hdc, 261, 175, NULL);
		LineTo(hdc, 246, 165);
		MoveToEx(hdc, 261, 175, NULL);
		LineTo(hdc, 246, 185);
		//������
		MoveToEx(hdc, 491, 175, NULL);
		LineTo(hdc, 506, 165);
		MoveToEx(hdc, 491, 175, NULL);
		LineTo(hdc, 506, 185);

		// ���� �� �κ�
		HBRUSH Blacks = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hdc, Blacks);
		Ellipse(hdc, 356, 190, 396, 230);

		//����
		MoveToEx(hdc, 346, 225, NULL);
		LineTo(hdc, 316, 210);

		MoveToEx(hdc, 406, 225, NULL);
		LineTo(hdc, 436, 210);

		MoveToEx(hdc, 346, 235, NULL);
		LineTo(hdc, 316, 250);

		MoveToEx(hdc, 406, 235, NULL);
		LineTo(hdc, 436, 250);
		// ����� �귯�� ���ҽ��� �����մϴ�.
		DeleteObject(skinBrush);
		DeleteObject(mouthBrush);
		DeleteObject(Whites);
		DeleteObject(Blacks);

		/*// �߾Ӽ� ���߿� �����
		MoveToEx(hdc, 376, 0, NULL);
		LineTo(hdc, 376, 480);
		MoveToEx(hdc, 0, 184, NULL);
		LineTo(hdc, 800, 184);*/

		EndPaint(drawingView, &ps);
	}
}

void DrawRyan(HWND drawingView, HDC hdc, int Shape, int left, int top, int right, int bottom) {
	if (Shape == 4) { // ���̾��� ��ġ�� ���� ������� ��������
		int startPointX = left;
		int startPointY = top;
		int endPointX = right;
		int endPointY = bottom;
		//���� ���۰� ���� �����ͼ� �����.
		POINT MINPOINT = { 0 };
		POINT MAXPOINT = { 0 };

		// �� ��ġ ����
		MINPOINT.x = min(startPointX, endPointX);
		MINPOINT.y = min(startPointY, endPointY);
		MAXPOINT.x = max(startPointX, endPointX);
		MAXPOINT.y = max(startPointY, endPointY);

		RECT face = { MINPOINT.x, MINPOINT.y,MAXPOINT.x,MAXPOINT.y };

		int width = abs(MINPOINT.x - MAXPOINT.x);
		int height = abs(MINPOINT.y - MAXPOINT.y);
		int centerX = width / 2;
		int centerY = height / 2;
		POINT centerPoint = { MINPOINT.x + centerX, MINPOINT.y + centerY };

		// �Ǻλ�
		HBRUSH RskinBrush = CreateSolidBrush(RGB(255, 200, 15));
		SelectObject(hdc, RskinBrush);

		// �ͺκ� �»󿡼� ����
		RECT L_ear = { MINPOINT.x , MINPOINT.y, MINPOINT.x + width / 3, MINPOINT.y + height / 3 };
		RECT R_ear = { MAXPOINT.x , MINPOINT.y, MAXPOINT.x - width / 3, MINPOINT.y + height / 3 };

		// �ޱ�
		Ellipse(hdc, L_ear.left, L_ear.top, L_ear.right, L_ear.bottom);
		// ������
		Ellipse(hdc, R_ear.left, R_ear.top, R_ear.right, R_ear.bottom);
		// ��
		Ellipse(hdc, face.left, face.top, face.right, face.bottom);

		POINT L_eye = { MINPOINT.x + centerX / 2, MINPOINT.y + (centerY / 6 * 5) };
		POINT R_eye = { MAXPOINT.x - centerX / 2, MINPOINT.y + (centerY / 6 * 5) };
		RECT L_eyes = { L_eye.x, L_eye.y, L_eye.x + width / 20, L_eye.y + height / 20 };
		RECT R_eyes = { R_eye.x, R_eye.y, R_eye.x - width / 20, R_eye.y + height / 20 };

		// ��
		HBRUSH Blacks = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hdc, Blacks);
		Ellipse(hdc, L_eyes.left, L_eyes.top, L_eyes.right, L_eyes.bottom);
		Ellipse(hdc, R_eyes.left, R_eyes.top, R_eyes.right, R_eyes.bottom);

		// ����3����
		MoveToEx(hdc, MINPOINT.x + centerX / 4, MINPOINT.y + centerY / 3 * 2, NULL);
		LineTo(hdc, MINPOINT.x + (centerX / 4 * 3), MINPOINT.y + (centerY / 3 * 2));
		MoveToEx(hdc, MINPOINT.x + centerX / 4, MINPOINT.y + centerY / 3 * 2 + 2, NULL);
		LineTo(hdc, MINPOINT.x + (centerX / 4 * 3), MINPOINT.y + (centerY / 3 * 2) + 2);
		MoveToEx(hdc, MINPOINT.x + centerX / 4, MINPOINT.y + centerY / 3 * 2 + 4, NULL);
		LineTo(hdc, MINPOINT.x + (centerX / 4 * 3), MINPOINT.y + (centerY / 3 * 2) + 4);

		MoveToEx(hdc, MAXPOINT.x - centerX / 4, MINPOINT.y + centerY / 3 * 2, NULL);
		LineTo(hdc, MAXPOINT.x - (centerX / 4 * 3), MINPOINT.y + (centerY / 3 * 2));
		MoveToEx(hdc, MAXPOINT.x - centerX / 4, MINPOINT.y + centerY / 3 * 2 + 2, NULL);
		LineTo(hdc, MAXPOINT.x - (centerX / 4 * 3), MINPOINT.y + (centerY / 3 * 2) + 2);
		MoveToEx(hdc, MAXPOINT.x - centerX / 4, MINPOINT.y + centerY / 3 * 2 + 4, NULL);
		LineTo(hdc, MAXPOINT.x - (centerX / 4 * 3), MINPOINT.y + (centerY / 3 * 2) + 4);

		// ��
		RECT L_nose = { centerPoint.x - centerX / 5, centerPoint.y, centerPoint.x, centerPoint.y + centerY / 5 };
		RECT R_nose = { centerPoint.x, centerPoint.y, centerPoint.x + centerX / 5, centerPoint.y + centerY / 5 };
		HBRUSH Whites = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, Whites);
		Ellipse(hdc, L_nose.left, L_nose.top, L_nose.right, L_nose.bottom);
		Ellipse(hdc, R_nose.left, R_nose.top, R_nose.right, R_nose.bottom);

	}
}