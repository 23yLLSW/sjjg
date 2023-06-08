#include <stdio.h>

// 定义物品结构体
struct item {
    int weight;  // 物品重量
    int value;   // 物品价值
};

// 计算物品单位价值
double calc_unit_value(struct item i) {
    return (double)i.value / i.weight;
}

// 小数背包函数
double fractional_knapsack(struct item items[], int n, int size) {
    // 按照单位价值排序
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (calc_unit_value(items[j]) < calc_unit_value(items[j + 1])) {
                struct item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    double max_value = 0.0;
    int current_weight = 0;

    // 依次放入单位价值最高的物品
    for (int i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= size) {
            current_weight += items[i].weight;
            max_value += items[i].value;
        }
        else {
            int remaining_capacity = size - current_weight;
            max_value += remaining_capacity * calc_unit_value(items[i]);
            break;
        }
    }

    return max_value;
}

int main() {
    struct item items[] = { {35, 60}, {20, 100}, {30, 120} };
    int n = sizeof(items) / sizeof(items[0]);
    int size = 50;

    double max_value = fractional_knapsack(items, n, size);

    printf("The maximum value that can be obtained is: %.2f\n", max_value);

    return 0;
}
