#include "graphics.h"
#include <windows.h> 
#include <iostream>
#include <cstdlib>
#pragma comment(lib, "graphics.lib")
using namespace std;


int main() {
    int luachon;
    cout << "Ban muon sap xep tang dan hay giam dan ?" << endl;
    cout << "1. Tang dan" << endl;
    cout << "2. Giam dan" << endl;
    cout << "Lua chon cua ban : "; cin >> luachon;
    initwindow(1000, 500, "chuong trinh");
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    // Chuỗi cần vẽ lên cửa sổ đồ họa
    char vanban[] = "Selection Sort";
    // Vẽ chuỗi "SelectionSort" tại tọa độ (200, 150)
    outtextxy(375, 50, vanban);
    // random giá trị cho mảng
    const int n = 8;
    int a[n] = {};
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }
    int left = 50, top = 100;
    int right = 150, bottom = 150;
    char giatri[10];
    char text[10];
    int l, r;
    // Vẽ các hình chữ nhật và đánh số thứ tự
    for (int i = 0; i < 8; i++) {
        // Vẽ hình chữ nhật
        rectangle(left, top, right, bottom);
        // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
        sprintf_s(giatri, sizeof(giatri), "%d", a[i]);
        double giatri_x = left + (right - left) / 2 - 5;
        double giatri_y = top + (bottom - top) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        // Đánh số thứ tự
        sprintf_s(text, sizeof(text), "%d", i); // Số thứ tự bắt đầu từ 0
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
    int text_x = 300;
    int text_y = 225;

    /*=================================*/
    char min_pos_text[50];
    char j_text[50];

    for (int i = 0; i < n - 1; i++) {
        int min_pos = i;
        sprintf_s(min_pos_text, sizeof(min_pos_text), "min_pos = %d", min_pos);
        setfillstyle(SOLID_FILL, BLACK);
        bar(text_x, text_y, text_x + 200, text_y + 60);
        outtextxy(text_x, text_y, min_pos_text);

        setfillstyle(SOLID_FILL, RED);
        bar(left, top, right, bottom);
        // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
        sprintf_s(giatri, sizeof(giatri), "%d", a[i]);
        double giatri_x = left + (right - left) / 2 - 5;
        double giatri_y = top + (bottom - top) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        rectangle(left, top, right, bottom);
        delay(500);
        left += 150 - 50;
        right += 150 - 50;
        // Đổ màu vàng và trở lại màu đen cho từng ô
        for (int j = i + 1; j < n; j++) {
            // Đổ màu nền vàng
            setfillstyle(SOLID_FILL, YELLOW);
            bar(left, top, right, bottom);
            // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
            sprintf_s(giatri, sizeof(giatri), "%d", a[j]);
            giatri_x = left + (right - left) / 2 - 5;
            giatri_y = top + (bottom - top) / 2.5;
            outtextxy(giatri_x, giatri_y, giatri);
            // Vẽ lại đường viền sau khi đổ màu
            rectangle(left, top, right, bottom);

            // Cập nhật lại j
            sprintf_s(j_text, sizeof(j_text), "j = %d", j);
            setfillstyle(SOLID_FILL, BLACK);
            bar(text_x, text_y + 20, text_x + 200, text_y + 40);
            outtextxy(text_x, text_y + 20, j_text);

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

            /*===============================*/
            /*Selection Sort*/
            if (luachon == 1) {
                if (a[j] < a[min_pos]) {
                    min_pos = j;
                    sprintf_s(min_pos_text, sizeof(min_pos_text), "min_pos = %d", min_pos);
                    setfillstyle(SOLID_FILL, BLACK);
                    bar(text_x, text_y, text_x + 200, text_y + 20);
                    outtextxy(text_x, text_y, min_pos_text);
                }
            }
            else {
                if (a[j] > a[min_pos]) {
                    min_pos = j;
                    sprintf_s(min_pos_text, sizeof(min_pos_text), "min_pos = %d", min_pos);
                    setfillstyle(SOLID_FILL, BLACK);
                    bar(text_x, text_y, text_x + 200, text_y + 20);
                    outtextxy(text_x, text_y, min_pos_text);
                }
            }
            /*===============================*/
            // Di chuyển tọa độ hình chữ nhật sang phải cho hình chữ nhật tiếp theo
            left += 150 - 50;
            right += 150 - 50;
        }
        int temp = a[min_pos];
        a[min_pos] = a[i];
        a[i] = temp;
        // VẼ LẠI CÁC PHẦN TỬ ĐÃ SẮP XẾP
        left = 50 + (i) * (150 - 50);
        right = 150 + (i) * (150 - 50);
        setfillstyle(SOLID_FILL, GREEN);
        bar(left, top, right, bottom);
        sprintf_s(giatri, sizeof(giatri), "%d", a[i]);
        giatri_x = left + (right - left) / 2 - 5;
        giatri_y = top + (bottom - top) / 2.5;
        outtextxy(giatri_x, giatri_y, giatri);
        rectangle(left, top, right, bottom);
        if (a[i] != a[min_pos]) {
            left = 50 + (150 - 50) * min_pos;
            right = 150 + (150 - 50) * min_pos;
            setfillstyle(SOLID_FILL, BLACK);
            bar(left, top, right, bottom);
            sprintf_s(giatri, sizeof(giatri), "%d", a[min_pos]);
            giatri_x = left + (right - left) / 2 - 5;
            giatri_y = top + (bottom - top) / 2.5;
            outtextxy(giatri_x, giatri_y, giatri);
            rectangle(left, top, right, bottom);
        }
        left = 50 + (i + 1) * (150 - 50);
        right = 150 + (i + 1) * (150 - 50);
        // Phần tử cuối cùng
        if (i == n - 2) {
            left = 50 + (i + 1) * (150 - 50);
            right = 150 + (i + 1) * (150 - 50);
            // Nhấp nháy 3 lần phần tử cuối cùng
            for (int k = 1; k <= 3; k++) {
                setfillstyle(SOLID_FILL, GREEN);
                bar(left, top, right, bottom);
                // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
                sprintf_s(giatri, sizeof(giatri), "%d", a[i + 1]);
                giatri_x = left + (right - left) / 2 - 5;
                giatri_y = top + (bottom - top) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(left, top, right, bottom);
                delay(150);
                setfillstyle(SOLID_FILL, BLACK);
                bar(left, top, right, bottom);
                // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
                sprintf_s(giatri, sizeof(giatri), "%d", a[i + 1]);
                giatri_x = left + (right - left) / 2 - 5;
                giatri_y = top + (bottom - top) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(left, top, right, bottom);
                delay(150);
                setfillstyle(SOLID_FILL, GREEN);
                bar(left, top, right, bottom);
                // Chèn số vào giữa các hình chữ nhật các giá trị của mảng   
                sprintf_s(giatri, sizeof(giatri), "%d", a[i + 1]);
                giatri_x = left + (right - left) / 2 - 5;
                giatri_y = top + (bottom - top) / 2.5;
                outtextxy(giatri_x, giatri_y, giatri);
                rectangle(left, top, right, bottom);
                delay(150);
            }
        }
    }
    getch();
    closegraph();
    return 0;
}

