#pragma once
typedef struct Path
{
	int vexs[20];  //保存一条路径
	Path* next;  //下一条路径
}*PathList;
