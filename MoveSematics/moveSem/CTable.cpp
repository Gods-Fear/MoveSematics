#include"CTable.h"

CTab::CTab()
{
	pi_tab = new int[DEF_TAB_SIZE];
	i_size = DEF_TAB_SIZE;
	cout << "Const " << endl;
}


CTab::CTab(const CTab &pcOther)
{
	v_copy(pcOther);
	cout << "Copy " <<endl;
}


CTab::CTab(CTab &&pcOther)
{
	pi_tab = pcOther.pi_tab;
	i_size = pcOther.i_size;
	pcOther.pi_tab = NULL;
	cout << "MOVE -------------"<<endl;
}



CTab::~CTab()
{
	if (pi_tab != NULL) delete pi_tab;
	cout << "Destr " << endl;
}


CTab CTab::operator=(const CTab &pcOther)
{
	if (pi_tab != NULL) delete pi_tab;
	v_copy(pcOther);
	cout << "op= ";
	return *this;
}



void CTab::v_copy(const CTab &pcOther)
{
	pi_tab = new int[pcOther.i_size];
	i_size = pcOther.i_size;
	for (int ii = 0; ii < pcOther.i_size; ii++)
		pi_tab[ii] = pcOther.pi_tab[ii];
}

bool CTab::bSetSize(int iNewSize)
{
	if (iNewSize <= 0) return false;

	int *i_Arr_NewSize;
	i_Arr_NewSize = new int[iNewSize];

	int min = std::min(i_size, iNewSize);

	for (int i = 0; i < min; i++)  
	{
		i_Arr_NewSize[i] = pi_tab[i_size];
	}
	  delete[]pi_tab;

	i_size = iNewSize;
	pi_tab = i_Arr_NewSize;


	return true;
}


CTab CTab::cCreateTab()   
{
	CTab c_result;
	c_result.bSetSize(5);

	return(move(c_result));
}

void CTab::vPrint()
{
	for (int i = 0; i < i_size; i++)
	{
		pi_tab[i] = i;
		cout << pi_tab[i];
	}
	
	cout << " "<< endl;
}



CTab& CTab::operator=(CTab &&pcOther)
{
	if (this->pi_tab != NULL)
		delete(this->pi_tab);

	pi_tab = pcOther.pi_tab;
	i_size = pcOther.i_size;

	pcOther.pi_tab = NULL;

	cout << "MOVE op=" << endl;

	return *this;
}
