// Written by Eduardo Wallén and Junior Corazza 2020-03-05
#include "header.h"

int main() {
	testInsertionSortAscending_L1();
	testInsertionSortDescending_L1();
	testInsertionSortAscending_L2();
	testInsertionSortDescending_L2();
	testInsertionSortAscending_pnum();
	testInsertionSortDescending_pnum();
	resetLists();
	testMergeSort_L1();
	testMergeSort_L2();
	testMergeSort_pnum();
}