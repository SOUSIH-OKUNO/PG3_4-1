#include <iostream>
using namespace std;


// 自作クラス
class MyClass {
public:
	void Update();

	void approach();
	void soothing();
	void exit();

	// メンバ関数ポインタのテーブル
	static void (MyClass::* table[])();

private:
	// メンバ関数ポインタのテーブルを参照するインデックス
	int index = 0;
};

void MyClass::approach() {
	cout << "敵の接近！" << endl;
}

void MyClass::soothing() {
	cout << "敵の攻撃！" << endl;
}

void MyClass::exit() {
	cout << "敵の後退！" << endl;
}

void MyClass::Update() {

	// 関数ポインタのテーブルから関数を実行
	(this->*table[index])();

	int kazu;

	puts( "次の行動へ");
	scanf_s("%d", &kazu);


	if (kazu==0) {
		index++;
		if (index > 2) 
			index = 0;
		
	}
}

// staticで宣言したメンバ関数ポインタテーブルの実体
void (MyClass::* MyClass::table[])() = {
  &MyClass::approach, 
  &MyClass::soothing, // インデックス番号1
  &MyClass::exit // インデックス番号2
};


int main()
{
	MyClass my;

	while (1) {
		my.Update();

	}

	return 0;
}