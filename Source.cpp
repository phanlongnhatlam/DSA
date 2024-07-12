#include "graphics.h"
#include <windows.h> 
#include <iostream>
#include <cstdlib>
#pragma comment(lib, "graphics.lib")
using namespace std;
int main() {
    initwindow(1000, 500, "chuong trinh");
// random giá trị cho mảng
    const int n = 8;
    int a[n] = {};
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }
    for (int i = 0; i < n; i++)cout << a[i] << " ";
    int left = 50, top = 100;
    int right = 150, bottom = 150;
    char giatri[10];
    char text[10];
    // Vẽ các hình chữ nhật và đánh số thứ tự
    for (int i = 0; i < 8; i++) {
        // Vẽ hình chữ nhật
        rectangle(left, top, right, bottom);
        // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
        sprintf_s(giatri, sizeof(giatri), "%d", a[i]);
        double giatri_x = left + (right - left) / 2-5;
        double giatri_y = top + (bottom - top) / 2.5; 
        outtextxy(giatri_x,giatri_y, giatri);
        // Đánh số thứ tự
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
    for (int i = 0; i < n-1; i++)
    {
        int min_pos = i;
        setfillstyle(SOLID_FILL, RED);
        bar(left, top, right, bottom);  
        // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
        sprintf_s(giatri, sizeof(giatri), "%d", a[i]);
        int giatri_x = left + (right - left) / 2 - 5;
        int giatri_y = top + (bottom - top) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);

        rectangle(left, top, right, bottom);
        delay(500);   
        left += 150 - 50;
        right += 150 - 50;
        // Đổ màu vàng và trở lại màu đen cho từng ô
        for (int j = i+1; j < n; j++) {
            // Đổ màu nền vàng
            setfillstyle(SOLID_FILL, YELLOW);
            bar(left, top, right, bottom);

            // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
            sprintf_s(giatri, sizeof(giatri), "%d", a[j]);
            double giatri_x = left + (right - left) / 2 - 5;
            double giatri_y = top + (bottom - top) / 2.5;
            outtextxy(giatri_x, giatri_y, giatri);

            // Vẽ lại đường viền sau khi đổ màu
            rectangle(left, top, right, bottom);
            // Đợi một khoảng thời gian ngắn
            delay(500);
            // Đổ màu nền đen
            setfillstyle(SOLID_FILL, BLACK);
            bar(left, top, right, bottom);

            // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
            sprintf_s(giatri, sizeof(giatri), "%d", a[j]);
             giatri_x = left + (right - left) / 2 - 5;
             giatri_y = top + (bottom - top) / 2.5;
            outtextxy(giatri_x, giatri_y, giatri);

            // Vẽ lại đường viền sau khi đổ màu
            rectangle(left, top, right, bottom);
            // Di chuyển tọa độ hình chữ nhật sang phải cho hình chữ nhật tiếp theo
            left += 150 - 50;
            right += 150 - 50;
            /*===============================*/
            /*Selection Sort*/
            if (a[j]<a[min_pos]) {
                min_pos = j;
            }
            /*===============================*/
            // Nhấp nháy phần tử cuối cùng
            if (i == 6 && j == 7) {
                left -= 150 - 50;
                right -= 150 - 50;
                for (int i = 0; i < 3; i++)
                {
                    setfillstyle(SOLID_FILL, GREEN);
                    bar(left, top, right, bottom);

                    // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
                    sprintf_s(giatri, sizeof(giatri), "%d", a[j]);
                     giatri_x = left + (right - left) / 2 - 5;
                     giatri_y = top + (bottom - top) / 2.5;
                    outtextxy(giatri_x, giatri_y, giatri);

                    rectangle(left, top, right, bottom);
                    delay(150);
                    setfillstyle(SOLID_FILL, BLACK);
                    bar(left, top, right, bottom);

                    // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
                    sprintf_s(giatri, sizeof(giatri), "%d", a[j]);
                     giatri_x = left + (right - left) / 2 - 5;
                     giatri_y = top + (bottom - top) / 2.5;
                    outtextxy(giatri_x, giatri_y, giatri);

                    rectangle(left, top, right, bottom);
                    delay(150);
                    setfillstyle(SOLID_FILL, GREEN);
                    bar(left, top, right, bottom);

                    // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
                    sprintf_s(giatri, sizeof(giatri), "%d", a[j]);
                     giatri_x = left + (right - left) / 2 - 5;
                     giatri_y = top + (bottom - top) / 2.5;
                    outtextxy(giatri_x, giatri_y, giatri);

                    rectangle(left, top, right, bottom);
                    delay(150);
                }
            }
        }
        int temp = a[min_pos];
        a[min_pos] = a[i];
        a[i] = temp;    
     // Vẽ lại
        left = 50 + (i ) * (150 - 50);
        right = 150 + (i) * (150 - 50);
        setfillstyle(SOLID_FILL, GREEN);
        bar(left, top, right, bottom);
        // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
        sprintf_s(giatri, sizeof(giatri), "%d", a[i]);
        giatri_x = left + (right - left) / 2 - 5;
        giatri_y = top + (bottom - top) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        rectangle(left, top, right, bottom);
        

        left = 50 + (i + 1) * (150-50);
        right = 150 + (i + 1) * (150-50);
    }
    for (int i = 0; i < n; i++)cout << a[i] << " ";
    getch();
    closegraph();
    return 0;
}
