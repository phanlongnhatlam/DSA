#include "graphics.h"
#include <windows.h> 
#include <iostream>
#pragma comment(lib, "graphics.lib")
using namespace std;
int main() {
    initwindow(1000, 500, "chuong trinh");
    int left = 50, top = 100;
    int right = 150, bottom = 150;

    // Vẽ các hình chữ nhật và đánh số thứ tự
    for (int i = 0; i < 8; i++) {
        // Vẽ hình chữ nhật
        rectangle(left, top, right, bottom);

        // Đánh số thứ tự
        char text[10];
        sprintf_s(text, sizeof(text), "%d", i ); // Số thứ tự bắt đầu từ 0
        int text_x = left + (right - left) / 2 - 5; // Căn giữa theo trục x
        int text_y = bottom + 10; // Cách hình chữ nhật một khoảng

        outtextxy(text_x, text_y, text);

        // Di chuyển tọa độ hình chữ nhật sang phải cho hình chữ nhật tiếp theo
        left += 150 - 50;
        right += 150 - 50;
    }
    // reset
    left = 50;
    right = 150;
    // Màu đỏ : đã sắp xếp
    for (int i = 0; i < 7; i++)
    {
        setfillstyle(SOLID_FILL, RED);
        bar(left, top, right, bottom);
        rectangle(left, top, right, bottom);
        delay(350);   
        left += 150 - 50;
        right += 150 - 50;
        // Đổ màu vàng và trở lại màu đen cho từng ô
        for (int j = i+1; j < 8; j++) {
            // Đổ màu nền vàng
            setfillstyle(SOLID_FILL, YELLOW);
            bar(left, top, right, bottom);
            // Vẽ lại đường viền sau khi đổ màu
            rectangle(left, top, right, bottom);
            // Đợi một khoảng thời gian ngắn
            delay(350);
            // Đổ màu nền đen
            setfillstyle(SOLID_FILL, BLACK);
            bar(left, top, right, bottom);
            // Vẽ lại đường viền sau khi đổ màu
            rectangle(left, top, right, bottom);
            // Di chuyển tọa độ hình chữ nhật sang phải cho hình chữ nhật tiếp theo
            left += 150 - 50;
            right += 150 - 50;
            // Nhấp nháy phần tử cuối cùng
            if (i == 6 && j == 7) {
                left -= 150 - 50;
                right -= 150 - 50;
                for (int i = 0; i < 3; i++)
                {
                    setfillstyle(SOLID_FILL, GREEN);
                    bar(left, top, right, bottom);
                    rectangle(left, top, right, bottom);
                    delay(150);
                    setfillstyle(SOLID_FILL, BLACK);
                    bar(left, top, right, bottom);
                    rectangle(left, top, right, bottom);
                    delay(150);
                    setfillstyle(SOLID_FILL, GREEN);
                    bar(left, top, right, bottom);
                    rectangle(left, top, right, bottom);
                    delay(150);
                }
            }
        }
        left = 50 + (i + 1) * (150-50);
        right = 150 + (i + 1) * (150-50);
    }
    getch();
    closegraph();
    return 0;
}
