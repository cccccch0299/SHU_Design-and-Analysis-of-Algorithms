#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <random>
using namespace std;
int board[1024][1024];
int count = 0;
void cb(int br, int bc, int tr, int tc,int size)//br,bc�������Ͻ����У�tr,tcĿ������
{
	if (size == 1)
		return;
	int c;
	c = ::count++;//ȫ�ֱ���
	 int n = size / 2;
	 //���Ͻ�
	if (br + n > tr && bc + n > tc )
	{
		//��������
		cb(br, bc, tr, tc, n);
	}
	else
	{
		//��������ⷽ�飬��ָ�
		board[br + n - 1][bc + n - 1] = c;
		cb(br, bc, br + n -1, bc + n - 1, n);
	}
	//���Ͻ�
	if (br + n > tr && bc + n <= tc)
	{
		cb(br, bc + n, tr, tc, n);
	}
	else
	{
		board[br + n -1 ][bc + n] = c;
		cb(br, bc+n, br + n - 1, bc + n, n);
	}
	//���½�
	if (br + n <= tr && bc + n > tc)
	{
		cb(br + n, bc, tr, tc, n);
	}
	else
	{
		board[br + n][bc + n - 1] = c;
		cb(br+n, bc, br + n, bc + n - 1, n);
	}
	//���½�
	if (br + n <= tr && bc + n <= tc)
	{
		cb(br + n, bc + n, tr, tc, n);
	}
	else
	{
		board[br + n][bc + n ] = c;
		cb(br + n, bc+n, br + n, bc + n, n);
	}
}

sf::Color int2color(int a)
{
	int ans = a % 9;
	switch (ans) 
	{
	case 0:
		return sf::Color::Red;         
	case 1:
		return sf::Color::Green;
	case 2:
		return sf::Color::Blue;
	case 3:
		return sf::Color::Yellow;
	case 4:
		return sf::Color::Magenta;
	case 5:
		return sf::Color::Cyan;
	case 6:
		return sf::Color (139, 69, 19); //��
	case 7:
		return sf::Color(255, 165, 0);//��
	case 8:
		return sf::Color(255, 192, 203);//��
	}
}

int main()
{
	int temp = 0;
	int k, x, y;
	
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 255);//���ȷֲ�
	while (cin >> k >> x >> y)
	{ 
		::count = 0;
		vector<sf::Color> randomColors; // �洢�����ɫ������
		int n = pow(2, k);
		int num = (n * n - 1) / 3 + 1;//��������
		//��ʼ��������ɫ
		
		randomColors.clear();
		// ���ɲ����������ɫ
		for (int i = 0; i < num; ++i) 
		{ 
			sf::Color randomColor(dis(gen), dis(gen), dis(gen));
			randomColors.push_back(randomColor);
		}
		temp++;
		x--;
		y--;
		board[x][y] = -1;
		cb(0, 0, x, y, n);
		cout << "case " << temp << ": n=" << n << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(board[i][j] == -1)
					cout <<setw(2) << "#  ";
				else
					cout << setw(2)<<board[i][j] << ' ';
			}
			cout << endl;
		}
		sf::RenderWindow window(sf::VideoMode(n*50, n*50), "Chessboard");
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.clear();
			// ��������
			sf::RectangleShape square(sf::Vector2f(50, 50));
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					square.setFillColor(board[i][j] == -1 ? sf::Color::Black : randomColors[board[i][j]]);
					square.setPosition(j * 50, i * 50);
					window.draw(square);
				}
			}
			window.display();
		}
	}
	return 0;
}
