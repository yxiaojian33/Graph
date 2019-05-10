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
void DFS(Graph m_Graph, int nVex, bool aVisited[], int& nIndex, PathList& pList)
//使用深度优先搜索算法遍历图
{
	aVisited[nVex] = true;  // 改为已访问
	pList->vexs[nIndex++] = nVex;  //访问顶点nVex
	for (int i = 0; i < m_Graph.m_nVexNum;i++)  //搜索v的所有邻接点
	{
		if (m_Graph.m_aAdjMatrix[i][nVex] && !aVisited[i])
		{
			DFS(m_Graph,i, aVisited, nIndex, pList);  //递归调用DFS
		}
	}

}
void BetterDfs(Graph m_Graph,int v, bool bVisited[], int aPath[], int &index)
{
	bVisited[v] = true;  // 改为已访问
	aPath[index++] = v;  // 访问顶点v
	bool flag = true;
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
		flag &= bVisited[i];
	if (flag)
	{
		// 1、保存一条路径
		for (int i = 0; i < m_Graph.m_nVexNum; i++)
		{
			cout << m_Graph.m_aVexs[ aPath[i]].name << " -------";
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < m_Graph.m_nVexNum; i++)  // 搜素v的所有邻接点
		{
			if ( !bVisited[i]&& m_Graph.m_aAdjMatrix[v][i]>0 )
			{
				BetterDfs(m_Graph,i, bVisited, aPath, index); // 递归调用DFS
				bVisited[i] = false;  // 2、改为未访问
				index--;  // 索引值减1
			}
		}
	}
}
void DFSTraverse(Graph m_Graph, int nVex, PathList& pList)
//通过调用DFS()函数，得到深度优先搜索遍历结果
{
	int nIndex = 0;
	int aPath[20] = { 0 };
	bool aVisited[MAX_VERTEX_NUM] = { false };
	//DFS(m_Graph,nVex, aVisited, nIndex, pList);
	BetterDfs(m_Graph, nVex, aVisited, aPath, nIndex);
}