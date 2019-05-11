#include"Graph.h"
//初始化图结构。
void Init(Graph& m_Graph) {
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++) 
		{
			m_Graph.m_aAdjMatrix[i][j] = 0;
		}
	}
	m_Graph.m_nVexNum = 0;
}

// 将顶点添加到顶点数组中
int InsertVex(Graph &m_Graph,Vex sVex) {
	if (m_Graph.m_nVexNum == MAX_VERTEX_NUM)
	{
		//顶点已满
		return false;
	}
	m_Graph.m_aVexs[m_Graph.m_nVexNum++] = sVex;  //插入顶点信息
	return true;
}
// 将边保存到邻接矩阵中。
int InsertEdge(Graph &m_Graph,Edge sEdge) {
	if (sEdge.vex1 < 0 || sEdge.vex1 >= m_Graph.m_nVexNum || sEdge.vex2 < 0 || sEdge.vex2 >= m_Graph.m_nVexNum)
		{
			// 下标越界
		return false;
		}
		// 插入边的信息
	m_Graph.m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	m_Graph.m_aAdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.weight;
	return true;


}
// 查询指定顶点信息
Vex GetVex(Graph m_Graph,int nVex) {
	return m_Graph.m_aVexs[nVex];

}
// 查询与指定顶点相连的边。
int FindEdge(Graph m_Graph,int nVex, Edge aEdge[]) {
	int k = 0;
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		if (m_Graph.m_aAdjMatrix[nVex][i] > 0)
		{
			aEdge[k].vex1 = nVex;
			aEdge[k].vex2 = i;
			aEdge[k].weight = m_Graph.m_aAdjMatrix[i][nVex];
			k++;
		}
	}
	return k;
}
//获取当前顶点数
int GetVexnum(Graph m_Graph) {
	return m_Graph.m_nVexNum;
}