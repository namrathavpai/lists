#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"


void test_empty_list(){
	Slist s1 = slist_new();
	Slist *list = &s1;
	assert(slist_length(list)==0);
}

void test_add_at_head(){
	Slist s1=slist_new();
	Slist *list = &s1;
	assert(slist_length(list)==0);
	list=slist_addnode_head(list,10);
	assert(slist_length(list)==1);
	list=slist_addnode_head(list,20);
	list=slist_addnode_head(list,30);
	assert(slist_length(list)==3);
	assert(slist_lookup(list,10)==1);
}

void test_delete_head(){
	Slist s1 = slist_new();
	Slist *list = &s1;
	assert(slist_length(list)==0);
	list=slist_addnode_head(list,10);
	assert(slist_length(list)==1);
	list=slist_addnode_head(list,20);
	list=slist_addnode_head(list,30);
	assert(slist_length(list)==3);
	assert(slist_lookup(list,20)==1);
	list=slist_addnode_head(list,40);
	list=slist_addnode_head(list,50);
	list=slist_deletenode_head(list);
	assert(slist_lookup(list,50)==0);
	assert(slist_lookup(list,20)==1);
	assert(slist_length(list)==4);
}

void test_add_at_tail(){
	Slist s1 = slist_new();
	Slist *list = &s1;
	assert(slist_length(list)==0);
	list = slist_addnode_tail(list,10);
	assert(slist_length(list)==1);
	list=slist_addnode_tail(list,20);
	list=slist_addnode_tail(list,30);
	assert(slist_length(list)==3);
}
void test_delete_tail(){
	Slist s1=slist_new();
	Slist *list = &s1;
	assert(slist_length(list)==0);
	list=slist_addnode_tail(list,10);
	assert(slist_length(list)==1);
	list=slist_addnode_tail(list,20);
	list=slist_addnode_tail(list,30);
	assert(slist_length(list)==3);
	list=slist_deletenode_tail(list);
	assert(slist_length(list)==2);
	assert(slist_lookup(list,30)==0);
	assert(slist_lookup(list,20)==1);
	list=slist_addnode_tail(list,40);
	assert(slist_length(list)==3);
	assert(slist_lookup(list,40)==1);
}
void test_min(){
	Slist s1=slist_new();
	Slist *list = &s1;
	assert(slist_length(list)==0);
	list=slist_addnode_tail(list,10);
	assert(slist_length(list)==1);
	list=slist_addnode_tail(list,20);
	list=slist_addnode_tail(list,30);
	assert(slist_length(list)==3);
	assert(slist_min(list)==10);
	list=slist_addnode_head(list,5);
	assert(slist_min(list)==5);
}
void test_max(){
	Slist s1=slist_new();
	Slist *list = &s1;
	assert(slist_length(list)==0);
	list=slist_addnode_tail(list,10);
	assert(slist_length(list)==1);
	list=slist_addnode_tail(list,20);
	list=slist_addnode_tail(list,30);
	assert(slist_length(list)==3);
	assert(slist_max(list)==30);
	list=slist_addnode_head(list,45);
	assert(slist_max(list)==45);
}
void test_same_list(){
	Slist s1=slist_new();
	Slist s2=slist_new();
	Slist *list1=&s1;
	Slist *list2=&s2;
	list1=slist_addnode_head(list1,10);
	assert(slist_length(list1)==1);
	list2=slist_addnode_head(list2,10);
	assert(slist_length(list2)==1);
	list1=slist_addnode_head(list1,20);
	assert(slist_length(list1)==2);
	list2=slist_addnode_head(list2,20);
	assert(slist_length(list2)==2);
	list1=slist_addnode_head(list1,30);
	assert(slist_length(list1)==3);
	list2=slist_addnode_head(list2,30);
	assert(slist_length(list2)==3);
	assert(slist_same(list1,list2)==1);
}

void test_union(){
	Slist s1=slist_new();
	Slist s2=slist_new();
	Slist *list1=&s1;
	Slist *list2=&s2;
	list1=slist_addnode_head(list1,10);
	assert(slist_length(list1)==1);
	list2=slist_addnode_head(list2,50);
	assert(slist_length(list2)==1);
	list1=slist_addnode_head(list1,20);
	assert(slist_length(list1)==2);
	list2=slist_addnode_head(list2,40);
	assert(slist_length(list2)==2);
	list1=slist_addnode_head(list1,30);
	assert(slist_length(list1)==3);
	list2=slist_addnode_head(list2,60);
	assert(slist_length(list2)==3);
	Slist *list3=slist_union(list1,list2);
	assert(slist_length(list3)==6);
}

void test_intersection(){
	Slist s1=slist_new();
	Slist s2=slist_new();
	Slist *list1=&s1;
	Slist *list2=&s2;
	list1=slist_addnode_head(list1,10);
	assert(slist_length(list1)==1);
	list2=slist_addnode_head(list2,50);
	assert(slist_length(list2)==1);
	list1=slist_addnode_head(list1,20);
	assert(slist_length(list1)==2);
	list2=slist_addnode_head(list2,10);
	assert(slist_length(list2)==2);
	list1=slist_addnode_head(list1,30);
	assert(slist_length(list1)==3);
	list2=slist_addnode_head(list2,20);
	assert(slist_length(list2)==3);
	Slist *list3=slist_inter(list1,list2);
	assert(slist_length(list3)==2);

}



int main(int argc, char *argv[]) {
	test_empty_list();
	test_add_at_head();
	test_delete_head();
	test_add_at_tail();
	test_delete_tail();
	test_min();
	test_max();
	test_same_list();
	test_union();
	test_intersection();
	return 0;
}
