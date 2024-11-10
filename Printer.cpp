#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model; // 모델명
	string manufacturer; // 제조사
	int printedCount; // 인쇄 매수
	int availableCount; // 인쇄 종이 잔량
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
			cout << "프린트하였습니다." << endl;
		}
		else {
			cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		}
	}
	void showPrinter(int pages) {
		cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장";
	}
};

class InkJetPrinter : public Printer {
	int availableInk; // 잉크 잔량
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
			print(pages); // 용지가 부족하다면 여기서 걸러짐
			availableInk -= pages;
		}
		else cout << "잉크가 부족하여 프린트를 할 수 없습니다." << endl;
	}
	void ShowInkPrinter(int pages) {
		showPrinter(pages);
		cout << ", 남은 잉크" << availableInk << endl;
	}
};

class LaserPrinter : public Printer {
	int availableToner; // 토너 잔량
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
			print(pages); // 용지가 부족하다면 여기서 걸러짐
			availableToner -= pages;
		}
		else cout << "잉크가 부족하여 프린트를 할 수 없습니다." << endl;
	}
	void ShowLaserPrinter(int pages) {
		showPrinter(pages);
		cout << ", 남은 토너" << availableToner << endl;
	}
};

int main() {
	cout << "현재 작동중인 2 대의 프린터는 다음과 같다." << endl;
	InkJetPrinter ijp("Officejet V40", "HP", 5, 10);
	cout << "잉크젯: ";
	ijp.ShowInkPrinter(0);
	LaserPrinter lp("SCX-6x45", "삼성전자", 3, 20);
	cout << "레이저: ";
	lp.ShowLaserPrinter(0);

	string cont = "y";
	int type, pages;
	do {
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
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
		cout << "계속 프린트 하시겠습니까?(y/n)";
		cin >> cont;
	} while (cont == "y");
}