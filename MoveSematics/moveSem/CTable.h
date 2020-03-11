#include<iostream>
#include<algorithm>

using namespace std;
#define DEF_TAB_SIZE 10 

class CTab
{

private:
	void v_copy(const CTab &cOther);
	int *pi_tab;
	int i_size;


public:
	CTab();
	CTab(const CTab &cOther);
	CTab(CTab &&cOther);
	CTab operator=(const CTab &cOther);
	~CTab();
	bool bSetSize(int iNewSize);
	CTab cCreateTab();
	int iGetSize() { return(i_size); }

	CTab& operator=(CTab &&cOther);

	void vPrint();

};
