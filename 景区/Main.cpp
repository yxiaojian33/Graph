#include"Tourism.h"
int main()
{
	Graph m_Graph;
	Init(m_Graph);
	string menu = "<========景区信息管理系统========>\n\t1.创建景区信息\n\t2.查询景点信息\n\t3.旅游景点导航\n";
	cout << "	へ　　　　　／|" << endl;
	cout << "　　/＼7　　　 ∠＿/" << endl;
	cout << "　 /　│　　 ／　／" << endl;
	cout << "　│　Z ＿,＜　／　　 /`ヽ" << endl;
	cout << "　│　　　　　ヽ　　 /　　〉" << endl;
	cout << "　 Y　　　　　`　 /　　/" << endl;
	cout << "　ｲ●　､　●　　⊂⊃〈　　/" << endl;
	cout << "　()　 へ　　　　|　＼〈" << endl;
	cout << "　　>ｰ ､_　 ィ　 │ ／／" << endl;
	cout << "　 / へ　　 /　ﾉ＜| ＼＼" << endl;
	cout << "　 ヽ_ﾉ　　(_／　 │／／" << endl;
	cout << "　　7　　　　　　　|／" << endl;
	cout << "　　＞―r￣￣`-―＿" << endl;
	while (1) {
		cout << menu;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
			CreateGraph(m_Graph);
			break;
		case 2:
			GetSpotInfo(m_Graph);
			break;
		case 3:
			TravelPath( m_Graph);
			break;

		}
	}
	
	return 0;
}