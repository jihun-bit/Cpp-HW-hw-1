#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model; // �𵨸�
	string manufacturer; // ������
	int printedCount; // �μ� �ż�
	int availableCount; // �μ� ���� �ܷ�
public:
	Printer(string model, string manufacturer, int availableCount) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->availableCount = availableCount;
	}
	bool canPrint(int pages) {
		if (availableCount - pages >= 0) return true;
		else return false;
	}
	void print(int pages) {
		if (canPrint(pages)) {
			availableCount -= pages;
			printedCount += pages;
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
		}
		else {
			cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		}
	}
	void showPrinter(int pages) {
		cout << model << ", " << manufacturer << ", ���� ���� " << availableCount << "��";
	}
};

class InkJetPrinter : public Printer {
	int availableInk; // ��ũ �ܷ�
public:
	InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk) : Printer(model, manufacturer, availableCount) {
		this->availableInk = availableInk;
	}
	bool canInkPrint(int pages) {
		if (availableInk - pages >= 0) return true;
		else return false;
	}
	void printInkJet(int pages) {
		if (canInkPrint(pages)) {
			print(pages); // ������ �����ϴٸ� ���⼭ �ɷ���
			availableInk -= pages;
		}
		else cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �� �����ϴ�." << endl;
	}
	void ShowInkPrinter(int pages) {
		showPrinter(pages);
		cout << ", ���� ��ũ" << availableInk << endl;
	}
};

class LaserPrinter : public Printer {
	int availableToner; // ��� �ܷ�
public:
	LaserPrinter(string model, string manufacturer, int availableCount, int availableToner) : Printer(model, manufacturer, availableCount) {
		this->availableToner = availableToner;
	}
	bool canLaserPrint(int pages) {
		if (availableToner - pages >= 0) return true;
		else return false;
	}
	void printLaser(int pages) {
		if (canLaserPrint(pages)) {
			print(pages); // ������ �����ϴٸ� ���⼭ �ɷ���
			availableToner -= pages;
		}
		else cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �� �����ϴ�." << endl;
	}
	void ShowLaserPrinter(int pages) {
		showPrinter(pages);
		cout << ", ���� ���" << availableToner << endl;
	}
};

int main() {
	cout << "���� �۵����� 2 ���� �����ʹ� ������ ����." << endl;
	InkJetPrinter ijp("Officejet V40", "HP", 5, 10);
	cout << "��ũ��: ";
	ijp.ShowInkPrinter(0);
	LaserPrinter lp("SCX-6x45", "�Ｚ����", 3, 20);
	cout << "������: ";
	lp.ShowLaserPrinter(0);

	string cont = "y";
	int type, pages;
	do {
		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> type >> pages;
		switch (type) {
		case 1:
			ijp.printInkJet(pages);
			break;
		case 2:
			lp.printLaser(pages);
			break;
		default:
			break;
		}
		ijp.ShowInkPrinter(pages);
		lp.ShowLaserPrinter(pages);
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n)";
		cin >> cont;
	} while (cont == "y");
}