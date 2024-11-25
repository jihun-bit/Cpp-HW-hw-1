#include<iostream>
#include<vector>
using namespace std;

class Shape {
protected:
	virtual void draw() = 0;
public:
	void paint() { draw(); }
};

class Circle : public Shape {
protected:
	virtual void draw() { cout << "Circle" << endl; }
};

class Rect :public Shape {
protected:
	virtual void draw() { cout << "Rectangle" << endl; }
};

class Line :public Shape {
protected:
	virtual void draw() { cout << "Line" << endl; }
};

class UI {
public:
	static int selectMenu() {
		int n;
		cout << "����:1, ����:2, ��κ���:3, ����:4 >>";
		cin >> n;
		return n;
	}
	static int selctShape() {
		int n;
		cout << "��:1, ��:2, �簢��:3 >>";
		cin >> n;
		return n;
	}
	static int selecDelIndex() {
		int n;
		cout << "�����ϰ��� �ϴ� ������ �ε��� >>";
		cin >> n;
		return n;
	}
	static void showAll(vector<Shape*>& v, vector<Shape*>::iterator &it) { 
		int i = 0;
		for (it = v.begin(); it != v.end(); it++, i++) {
			cout << i << ": ";
			v.at(i)->paint();
		}
	}
};
class GraphicEditor {
	vector<Shape*> v;
	vector<Shape*>::iterator it;
public:
	GraphicEditor() {
		cout << "�׷��� �������Դϴ�. \n";
		start();
	}
	void start() {
		while (true) {
			int n;
			n = UI::selectMenu();
			switch (n) {
			case 1:
				n = UI::selctShape();
				switch (n) {
				case 1:
					v.push_back(new Line());
					break;
				case 2:
					v.push_back(new Circle());
					break;
				case 3:
					v.push_back(new Rect());
					break;
				default:
					cout << "�߸� �����ϼ̽��ϴ�. \n";
					break;
				}
				break;
			case 2: {
				n = UI::selecDelIndex();
				if (n >= v.size() || n < 0) {
					cout << "���� �ε��� �Դϴ�. \n";
					break;
				}
				it = v.begin();
				Shape* tmp = *(it + n);
				v.erase(it + n);
				delete tmp;
				break;
			}
			case 3:
				UI::showAll(v, it);
				break;
			case 4:
				return;
			default:
				cout << "�߸� �Է��ϼ̽��ϴ�. \n";
				break;
			}
		}
	}
};

int main() {
	new GraphicEditor();
}