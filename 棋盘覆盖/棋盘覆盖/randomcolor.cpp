#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
void int2color2() {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 255);
    vector<sf::Color> randomColors; // �洢�����ɫ������
    // ���ɲ����������ɫ
    for (int i = 0; i < 10; ++i) { // ����10�������ɫ
        sf::Color randomColor(dis(gen), dis(gen), dis(gen));
        randomColors.push_back(randomColor);
    }
    return ;
}
