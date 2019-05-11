#include"Tourism.h"
//从文件初始化信息
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
	cout << "各边：\n";
	ifstream edgefile("./Edge.txt", ios::in);
	for (int i = 0;; i++)
	{
		Edge edge;
		if (edgefile >> edge.vex1 >> edge.vex2 >> edge.weight)
		{
		  cout << edge.vex1 << "--->" << edge.vex2 << "\t" << edge.weight << endl;
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
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		cout << m_Graph.m_aVexs[i].num << " " << m_Graph.m_aVexs[i].name << endl;
	}
	cout << "请输入想要查询的景点编号：";
	cin >> choose;
	Vex vex = GetVex(m_Graph, choose);
	cout << vex.name<<"\n"<<vex.desc << endl;
	Edge edge[20];
	int num = FindEdge(m_Graph,choose,edge);
	for (int i = 0; i < num; i++)
	{
		cout << edge[i].vex1 << "======" << edge[i].vex2 << "     " << edge[i].weight << endl;
	}

}