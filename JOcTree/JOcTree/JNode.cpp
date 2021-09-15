#include "JNode.h"


JNode::JNode(JNode* pParent, float fX, float fY, float fZ, float fWidth, float fHeight, float fLength, int iDepth,int iIndex){
	this->m_Rect.whl = JVector3(fWidth, fHeight, fLength);
	this->m_Rect.p0 = JVector3(fX, fY, fZ);
	this->m_Rect.p1 = this->m_Rect.p0 + this->m_Rect.whl;
	
	this->m_iDepth = iDepth;
	this->m_pParent = pParent;
	this->m_iIndex = iIndex;
	

}

