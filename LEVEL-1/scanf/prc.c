#include <stdio.h>

int main() {
    int num;
    float height;

    printf("整数と浮動小数点数を入力してください: ");
    // 整数と浮動小数点数を読み込む
    scanf("%d %f", &num, &height);

    printf("入力された整数: %d\n", num);
    printf("入力された浮動小数点数: %.2f\n", height);

    return 0;
}
