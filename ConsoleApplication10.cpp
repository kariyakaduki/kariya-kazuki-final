#include <iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Kendo {
	string name;
	
public:
	int point = 0;
	void setName(const string& newName) { name = newName; }
	string getName() { return name; }


};

class KENDO :public Kendo{
	string pattern;
public:
	void setPattern(const string& newPattern) { pattern = newPattern; }
	string getPattern() { return pattern; }
	void setPoint(int newPoint) { point = newPoint; }
	int getPoint() { return point; }
};




int main() {
	cout << "都立大試合結果" << "(" << "有効打突部位" <<" )"<<"勝敗" << "\n";
	int score1 = 0;
	int score2 = 0;
	int score3 = 0;
	int score4 = 0;
	
	ifstream datafile("toritu.txt");
	if (!datafile) {
		cout << "ファイルが見つからない";
	}
	else {
		vector<KENDO> vec;
		string str;
		string name;
		string pattern;
		int point;
		int i = 0;

		while (datafile >> name >> pattern >> point) {
			vec.emplace_back();
			vec[i].setName(name);
			vec[i].setPattern(pattern);
			vec[i].setPoint(point);
			cout << vec[i].getName() << "(" << vec[i].getPattern() << ")" << vec[i].getPoint() << "\n" << endl;
			
			score1 = score1 + vec[i].getPoint();
			if (vec[i].getPattern() == "無") {
				
              }
			else {
				size_t size = vec[i].getPattern().length();
				score2 = score2 + size/2;
				
			}
			i++;
		}
		cout <<"勝ち数"<< score1 << endl;
		cout <<"本数"<<score2 << endl;
	}
	cout << "府立大試合結果" << "(" << "有効打突部位" << " )" << "勝敗" << "\n";


	ifstream datafilee("huritu.txt");
	if (!datafilee) {
		cout << "ファイルが見つからない";
	}
	else {
		vector<KENDO> vec;
		string str;
		string name;
		string pattern;
		int point;
		int i = 0;

		while (datafilee >> name >> pattern >> point) {
			vec.emplace_back();
			vec[i].setName(name);
			vec[i].setPattern(pattern);
			vec[i].setPoint(point);
			cout << vec[i].getName() << "(" << vec[i].getPattern() << ")" << vec[i].getPoint() << "\n" << endl;

			score3 = score3 + vec[i].getPoint();
			if (vec[i].getPattern() == "無") {

			}
			else {
				size_t size = vec[i].getPattern().length();
				score4 = score4 + size / 2;

			}
			i++;
		}
		cout << "勝ち数" << score3 << endl;
		cout << "本数" << score4 << endl;
	}
	if (score3 == score1) {
		if(score4 < score2){
			cout << "都立大の勝利" << endl;

		}
		if (score2 < score4) {
			cout << "府立大の勝利" << endl;

		}
		if (score2 == score4) {
			cout << "引き分け" << endl;

		}


	}
	if (score3 < score1) {
		cout << "都立大の勝利" << endl;

	}
	if (score1 < score3) {
		cout << "府立大の勝利" << endl;

	}
}

