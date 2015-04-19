#include "CrossListNetwork.h"
#include "ShortestPathBellmanFord.h"
int main()
{
	try
	{
		int infity = DEFAULT_INFINITY;
		int I = DEFAULT_INFINITY;
		char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
		int m[6][6] = {
		//		 A  B  C  D  E  F
		/*A*/	{I, I, I, I, I, I},
		/*B*/	{1, I, 2, I, I, I},
		/*C*/	{3, I, I, 4, I, I},
		/*D*/	{I, I, I, I, 5, I},
		/*E*/	{I, I, I, 6, I, I},
		/*F*/	{I, I, I, I, I, I},
		};
		char e, e1, e2;
		int n = 6, v, v1, v2, w;
		CrossListNetwork<char, int> net(vexs, n);
		for (int v = 0; v < n; v++)
			for (int u = 0; u < n; u++)
				if (m[v][u] != infity)
					net.InsertArc(v, u, m[v][u]);
		char c = 'x';
	    while (c != '0')
		{
            cout << endl << "1. 有向网清空.";
            cout << endl << "2. 显示有向网.";
            cout << endl << "3. 取指定顶点的值.";
            cout << endl << "4. 设置指定顶点的值.";
            cout << endl << "5. 删除顶点.";
            cout << endl << "6. 插入顶点.";
            cout << endl << "7. 删除边.";
            cout << endl << "8. 插入边.";
            cout << endl << "9. 设置指定边的权.";
			cout << endl << "a. 计算最短路径.";
		    cout << endl << "0. 退出";
		    cout << endl << "选择功能(0~9):";
		    cin >> c;
		    switch (c)
			{
			    case '1':
			        net.Clear();
				    break;
			    case '2':
                    if (net.IsEmpty())
                        cout << "该有向网为空。" << endl;
                    else 
			            net.Display();
				    break;
			    case '3':
			        cout << endl << "输入顶点序号（有向网的顶点序号从0开始）:";
			        cin >> v;
		            net.GetElem(v, e);
		            cout << "序号为" << v << "的顶点为" << e;
			        break;
			    case '4':
			        cout << endl << "输入顶点序号（有向网的顶点序号从0开始）:";
			        cin >> v;
			        cout << endl << "输入" << v <<"号顶点的值:";
			        cin >> e;
		            net.SetElem(v, e);
			        break;
			    case '5':
			        cout << endl << "输入被删除顶点的值:";
			        cin >> e;
		            net.DeleteVex(e);
			        break;
			    case '6':
			        cout << endl << "输入插入顶点的值:";
			        cin >> e;
		            net.InsertVex(e);
			        break;
			    case '7':
			        cout << endl << "输入与被删除边关联的两个顶点值:";
			        cin >> e1 >> e2;
			        v1 = net.GetOrder(e1);
			        v2 = net.GetOrder(e2);
		            net.DeleteArc(v1, v2);
			        break;
			    case '8':
			        cout << endl << "输入与插入边关联的两个顶点值和边的权值:";
			        cin >> e1 >> e2 >> w;
			        v1 = net.GetOrder(e1);
			        v2 = net.GetOrder(e2);
		            net.InsertArc(v1, v2, w);
			        break;
			    case '9':
			        cout << endl << "输入与插入边关联的两个顶点值和边的权值:";
			        cin >> e1 >> e2 >> w;
			        v1 = net.GetOrder(e1);
			        v2 = net.GetOrder(e2);
		            net.SetWeight(v1, v2, w);
			        break;
				case 'a':
			        cout << "原网:" << endl;
					net.Display();
					cout << endl;
					system("PAUSE");
					int dist[n], path[n], v0 = 0;
					ShortestPathBellmanFord(net, v0, path, dist);
					DisplayPathAndDist(net, v0, path, dist);
					cout << endl;
					system("PAUSE");
					break;
       	      }
         }
	}
	catch (Error err)					// 捕捉并处理异常
	{
		err.Show();						// 显示异常信息
	}
	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
	return 0;
}
