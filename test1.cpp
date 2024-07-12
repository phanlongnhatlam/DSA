#include "graphics.h"
#include <windows.h>
#include <iostream>
#pragma comment(lib, "graphics.lib")
using namespace std;

void veHinhChuNhat(int trai, int tren, int phai, int duoi, int mau, char* chu, int soThuTu) {
    setfillstyle(SOLID_FILL, mau);// thiết lập màu và kiểu tô
    bar(trai, tren, phai, duoi);
    setcolor(WHITE);
    rectangle(trai, tren, phai, duoi);// vẽ hình chữ nhật

    // Căn giữa văn bản bên trong ô chữ nhật
    int textX = trai + (phai - trai) / 2 - textwidth(chu) / 2;
    int textY = tren + (duoi - tren) / 2 - textheight(chu) / 2;
    outtextxy(textX, textY, chu);

    // Số thứ tự bên ngoài ô chữ nhật
    char thuTu[10];
    sprintf_s(thuTu, sizeof(thuTu), "%d", soThuTu);
    int thuTuX = trai + (phai - trai) / 2 - textwidth(thuTu) / 2;
    int thuTuY = duoi + 10; 
    outtextxy(thuTuX, thuTuY, thuTu);
}

int main() {
    initwindow(1000, 800, "Hình minh họa thuật toán sắp xếp chọn");
    int trai = 50, tren = 100;
    int phai = 150, duoi = 150;
    int mang[8] = { 64, 25, 12, 22, 11, 90, 33, 45 }; // Ví dụ mảng

    // Vẽ ban đầu các hình chữ nhật với các số và số thứ tự
    for (int i = 0; i < 8; i++) {
        char chu[10];
        sprintf_s(chu, sizeof(chu), "%d", mang[i]);
        veHinhChuNhat(trai + i * 100, tren, trai + i * 100 + 100, duoi, BLACK, chu, i);
    }

    // Minh họa thuật toán sắp xếp chọn
    for (int i = 0; i < 7; i++) {
        int min_idx = i;
        // Tô sáng phần tử hiện tại đang được xem xét để hoán đổi
        char chu[10];
        sprintf_s(chu, sizeof(chu), "%d", mang[i]);
        veHinhChuNhat(trai + i * 100, tren, trai + i * 100 + 100, duoi, RED, chu, i);
        delay(500);

        for (int j = i + 1; j < 8; j++) {
            // Tô sáng phần tử hiện tại đang được so sánh
            sprintf_s(chu, sizeof(chu), "%d", mang[j]);
            veHinhChuNhat(trai + j * 100, tren, trai + j * 100 + 100, duoi, YELLOW, chu, j);
            delay(500);

            if (mang[j] < mang[min_idx]) {
                min_idx = j;
            }

            // Reset màu sau khi so sánh
            sprintf_s(chu, sizeof(chu), "%d", mang[j]);
            veHinhChuNhat(trai + j * 100, tren, trai + j * 100 + 100, duoi, BLACK, chu, j);
        }

        // Hoán đổi phần tử nhỏ nhất được tìm thấy với phần tử đầu tiên
        if (min_idx != i) {
            int temp = mang[min_idx];
            mang[min_idx] = mang[i];
            mang[i] = temp;

            // Vẽ lại các hình chữ nhật sau khi hoán đổi
            sprintf_s(chu, sizeof(chu), "%d", mang[min_idx]);
            veHinhChuNhat(trai + min_idx * 100, tren, trai + min_idx * 100 + 100, duoi, BLACK, chu, min_idx);
            sprintf_s(chu, sizeof(chu), "%d", mang[i]);
            veHinhChuNhat(trai + i * 100, tren, trai + i * 100 + 100, duoi, RED, chu, i);
        }

        // Reset màu của phần tử hiện tại sau khi sắp xếp
        sprintf_s(chu, sizeof(chu), "%d", mang[i]);
        veHinhChuNhat(trai + i * 100, tren, trai + i * 100 + 100, duoi, GREEN, chu, i);
        delay(500);
    }

    // Phần tử cuối cùng đã sắp xếp
    char chu[10];
    sprintf_s(chu, sizeof(chu), "%d", mang[7]);
    veHinhChuNhat(trai + 7 * 100, tren, trai + 7 * 100 + 100, duoi, GREEN, chu, 7);

    getch();
    closegraph();
    return 0;
}
