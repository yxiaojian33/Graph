#include"Tourism.h"
//从文件初始化信息
void ShowVex(Graph m_Graph) {
	cout << "编号\t名称\n";
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		cout << m_Graph.m_aVexs[i].num << "\t" << m_Graph.m_aVexs[i].name << endl;
	}
}

int CreateGraph(Graph& m_Graph) {
	ifstream vexfile("./Vex.txt", ios::in);
	if (!vexfile)
	{
		return 0;
	}
	int vexnum;

	vexfile >> vexnum;//从文件获得顶点个数
	cout << "顶点数目："<<vexnum << endl;
	for (int i = 0; i < vexnum; i++)
	{
		Vex vex;
		vexfile >> vex.num >> vex.name >> vex.desc;
		cout << vex.num << "-" << vex.name << endl;
		if (!InsertVex(m_Graph, vex))
			cout << "顶点已满\n";
	}

	vexfile.close();
	//Vex.txt文件读取完毕
	cout << "顶点1\t顶点2\t路径长度：\n";
	ifstream edgefile("./Edge.txt", ios::in);
	for (int i = 0;; i++)
	{
		Edge edge;
		if (edgefile >> edge.vex1 >> edge.vex2 >> edge.weight)
		{
		  cout << edge.vex1 << "\t" << edge.vex2 << "\t" << edge.weight << endl;
			if (!InsertEdge(m_Graph, edge))
				cout << "下标越界\n";
		}
		else break;
	}
	edgefile.close();
	return 1;

}
void GetSpotInfo(Graph m_Graph) {
	int choose;
	ShowVex(m_Graph);
	cout << "请输入想要查询的景点编号：";
	cin >> choose;
	Vex vex = GetVex(m_Graph, choose);
	cout << vex.name<<"\n"<<vex.desc << endl;
	Edge edge[20];
	cout << "附近景点\t距离\n";
	int num = FindEdge(m_Graph,choose,edge);
	for (int i = 0; i < num; i++)
	{
		cout << m_Graph.m_aVexs[edge[i].vex2 ].name<< "\t\t" << edge[i].weight << endl;
	}

}
void TravelPath(Graph m_Graph) {
	PathList pList = new Path;
	int choose;
	ShowVex(m_Graph);
	cout << "请输入起始的景点编号：";
	cin >> choose;
	DFSTraverse( m_Graph, choose, pList);

}
void FindShortPath(Graph m_Graph) {
	int start;
	int end;
	Edge edge[20];
	ShowVex(m_Graph);
	cout << "请输入起始的景点编号：";
	cin >> start;
	cout << "请输入目标的景点编号：";
	cin >> end;
	int index=0;
	cout<<"最短路径："<<FindShortPath(m_Graph, start, end, edge,index)<<endl;
	if (index) {
		for (int i = 0; i < index; i++) {
			cout << "【" << m_Graph.m_aVexs[edge[i].vex1].name << "】----" << edge[i].weight << "---->";
		}
		cout << "【" << m_Graph.m_aVexs[edge[index - 1].vex2].name << "】" << endl;
	}
	else
		cout << "不可到达\n";
}
void DesignPath(Graph m_Graph) {
	Edge edge[20];
	cout<<"最短电缆长度"<<FindMinTree(m_Graph, edge)<<endl;
	for (int i = 0; i < m_Graph.m_nVexNum-1; i++) {
		cout << "【"<<m_Graph.m_aVexs[ edge[i].vex1].name << "】---->【" << m_Graph.m_aVexs[edge[i].vex2].name << "】  " << edge[i].weight << endl;
	}
}