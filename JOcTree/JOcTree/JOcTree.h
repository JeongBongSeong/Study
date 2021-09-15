#include"JNode.h"


class JOcTree{
public:
	JNode *m_pRootNode;
	std::map<std::string, JObject*> m_Dynamic_ObjectAllList;
	std::queue<JNode*> m_Queue;
public:
	float m_iWidth;
	float m_iHeight;
	static int g_newCounter;


public:
	void Init(float fWidth, float fHeight, float fLength);
	JNode* CreateNode(JNode* pParent, float fX, float fY, float fZ, float fWidth, float fHeight, float fLength, int iDepth);
	void BuildTree(JNode* pNode);
	JNode* FindNode(JNode* pNode, JVector3 pos);
	JNode* FindPlayerNode(JNode* pNode, JVector3 pos,std::string);
	void AddObject(JVector3 pos);
	void AddObject(JObject *player);
	JNode* FindIndexNode(int &iIndex);
	JNode* FindIndexQueue(JNode* pNode, int& iIndex);

	JNode* Preorder(JNode* pNode, int& iIndex);
	void Frame(JObject* Target, float fTime);

	bool isRact(JNode* pNode, JVector3 pos);

public:
	JOcTree() : m_pRootNode(nullptr),m_iHeight(NULL),m_iWidth(NULL) {};
	//JQuadTree(JNode*, float, float);
};