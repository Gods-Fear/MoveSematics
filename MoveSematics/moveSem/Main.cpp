#include"CTable.h"


int main(){

	
	CTab c_tab;
	CTab c_other;

	c_tab.bSetSize(5);
	c_other.bSetSize(3);

	c_tab.vPrint();
	c_other.vPrint();
	
	c_tab = move(c_other);

	//c_tab.vPrint();
	//c_other.vPrint();
	return 0;
}