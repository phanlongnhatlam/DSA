#include<iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;

int main() {
	initwindow(900, 600, "test");
	rectangle(20, 20, 520, 100);
	line(120, 20, 120, 100);
	line(220, 20, 220, 100);
	line(320, 20, 320, 100);
	line(420, 20, 420, 100);
	line(520, 20, 520, 100);

	int x = 20, y = 20;
	int width = 100;  // Chiều rộng mỗi ô (giữa hai đường thẳng dọc)
	for (int i = 0; i < 5; i++) {
		char text[10];
		sprintf_s(text, sizeof(text), "%d", i ); // Số thứ tự từ 0

		// Điều chỉnh tọa độ (x, y) của text
		int text_x = x + i * width + width / 2 - 5; // Tọa độ x để căn giữa số thứ tự
		int text_y = y + 105; // Tọa độ y để hiển thị số thứ tự bên trên các ô

		outtextxy(text_x, text_y, text);
	}

	getch();
	closegraph();
	system("pause");
	return 0;
}