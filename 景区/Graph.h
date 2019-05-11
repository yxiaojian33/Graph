#pragma once
#define MAX_VERTEX_NUM 20
#include"Vex.h"
#include"Edge.h"
#include<fstream>
#include<iostream>
using namespace std;
struct Graph {
	int m_aAdjMatrix[20][20]; // 邻接矩阵
	Vex m_aVexs[20]; // 顶点数组
	int m_nVexNum; // 顶点个数
};  
void Init(Graph &m_Graph);
//初始化图结构。
int InsertVex(Graph &m_Graph,Vex sVex);
// 将顶点添加到顶点数组中。
int InsertEdge(Graph& m_Graph,Edge sEdge);
// 将边保存到邻接矩阵中。
Vex GetVex(Graph m_Graph,int nVex);
// 查询指定顶点信息。
int FindEdge(Graph m_Graph,int nVex, Edge aEdge[]);
// 查询与指定顶点相连的边。
int GetVexnum(Graph m_Graph);
//获取当前顶点数。

