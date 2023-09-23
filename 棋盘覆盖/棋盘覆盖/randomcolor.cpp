#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
void int2color2() {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 255);
    vector<sf::Color> randomColors; // 存储随机颜色的容器
    // 生成并保存随机颜色
    for (int i = 0; i < 10; ++i) { // 生成10个随机颜色
        sf::Color randomColor(dis(gen), dis(gen), dis(gen));
        randomColors.push_back(randomColor);
    }
    return ;
}
