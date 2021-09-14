#include"CQuadTree.h"
#define MAXSIZE_X 100
#define MAXSIZE_Y 100
int CQuadTree::g_iCounter = 0;
int main()
{
	CQuadTree*Quadtree = new CQuadTree();
	Quadtree->Init(MAXSIZE_X, MAXSIZE_Y);
	CQuadTree::g_iCounter++;
	
	srand(time(NULL));
	for (int i = 0; i < 1; i++)
	{
		CVector2 pos;
		/*pos.x = (float)(rand() % 100);
		pos.y = (float)(rand() % 100);*/
		pos.x = 50;
		pos.y = 50;
		cout << "{" << pos.x << ", " << pos.y << "}" << endl;
		Quadtree->AddObject(pos);
	}

	delete Quadtree;

}