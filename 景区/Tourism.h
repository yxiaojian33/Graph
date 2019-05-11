#pragma once
#include"Graph.h"
int CreateGraph(Graph& m_Graph);//读取文件，创建景区景点图。
void GetSpotInfo(Graph m_Graph);//查询指定景点信息，显示到相邻景点的距离。
void TravelPath(Graph m_Graph);
//通过调用DFSTraverse()函数，实现旅游景点导航功能，将查询到的景点导航路线显示在界面上。
void FindShortPath(Graph m_Graph);
//通过调用m_Graph()函数查询两个景点间的最短路径和距离。
void DesignPath(Graph m_Graph);
//通过调用Graph.cpp文件中的FindMinTree()方法查询铺设电路规划图

