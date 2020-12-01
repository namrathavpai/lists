#include <stdlib.h>
#include <assert.h>
#include "slist.h"


Slist  slist_new(){
	Slist s1 = {NULL,NULL,0};
	return s1;
}

uint32_t slist_length(const Slist *list){
    assert(list != NULL);
	return list->length;
}


static Node* _get_new_node_(int32_t val){
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}


Slist*  slist_addnode_head(Slist *list,int32_t val){
	assert(list != NULL);
	Node *new_node= _get_new_node_(val);
	new_node->next=list->head;
	list->head = new_node;
	if(list->tail==NULL){
		list->tail=new_node;
	}
	++list->length;
	assert((list->length == 1) && (list->head == list->tail) || (list->length>1) && (list->head) != list->tail);
	return list;
}

Slist* slist_addnode_tail(Slist *list, int32_t val){
	assert(list!=NULL);
	Node *new_node = _get_new_node_(val);
	if(list->tail !=NULL){
		list->tail->next=new_node;
		list->tail=new_node;
	}else{
		list->head = list->tail = new_node;
	}
	++list->length;
	assert( (list->length == 1) && (list->head == list->tail) || (list->length>1) && (list->head)!=list->tail);
	return list;
}

uint8_t slist_lookup(const Slist *list,int32_t key){
	assert(list !=NULL);
	Node *cur = list->head;

	for(cur = list->head; cur != NULL; cur=cur->next){
		if(cur->data == key){
			break;
		}
	}
	return (cur != NULL);
}

Slist* slist_deletenode_head(Slist *list){
	assert(list!=NULL);
	Node *temp;
	if(list->head != NULL){
		temp = list->head;
		list->head = list->head->next;
		if(list->head != NULL){
			list->tail=NULL;
		}
		--list->length;
		free(temp);
	}
	return list;
}

Slist* slist_deletenode_tail(Slist *list){
	assert(list!=NULL);
	Node *cur;
	cur=list->head;
	if(cur->next==NULL){
		list->head=NULL;
		list->tail=NULL;
	}else{
		for(cur=list->head;cur->next!=list->tail;cur=cur->next);
		cur->next=NULL;
		free(list->tail);
	    list->tail=cur;
	}
	--list->length;
	return list;
}

Slist* slist_deletenode_any(Slist *list,int32_t val){
	assert(list!=NULL);
	Node *temp;
	temp=list->head;
	 while (list->head->data == val)
    {
        list->head = list->head->next;
    }
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            temp->next = temp->next->next;
            --list->length;
        }
        else
        {
            temp = temp->next;
        }
    }
    return list;
}

int32_t slist_min(Slist *list){
	assert(list!=NULL);
	int32_t min;
	Node *temp;
	if(list->head->next=NULL){
		min=list->head->data;
	}else{
		temp=list->head;
		min=list->head->data;
		while(temp!=NULL){
			temp=temp->next;
			if(min>temp->data){
				min=temp->data;
			}
		}
	}
	return min;
}

int32_t slist_max(Slist *list){
		assert(list!=NULL);
	int32_t max;
	Node *temp;
	if(list->head->next=NULL){
		max=list->head->data;
	}else{
		temp=list->head;
		max=list->head->data;
		while(temp!=NULL){
			temp=temp->next;
			if(max<temp->data){
				max=temp->data;
			}
		}

	}
	return max;
}

Slist* slist_reverse(Slist *list){
	    assert(list!=NULL);
	    Node *cur = list->head;
        Node *prev,*next;

        while (cur!= NULL) {

            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        list->head = prev;
        return list;
}

 int32_t slist_same(Slist *list1,Slist *list2){
	assert(list1!=NULL && list2!=NULL);
	Node *cur1=list1->head;
	Node *cur2=list2->head;
	while(list1->length==list2->length && cur1->data==cur2->data && cur1->next!=NULL && cur2->next!=NULL ){
		cur1=cur1->next;
		cur2=cur2->next;
	}
		return (cur1->next==NULL && cur2->next==NULL);
	}

Slist* slist_union(Slist *list1,Slist *list2){
	assert(list1!=NULL && list2!=NULL);
	Slist res = slist_new();
	Slist *reslist = &res;
    Node *cur1 = list1->head, *cur2 = list2->head;

    while (cur1 != NULL) {
        slist_addnode_head(reslist,cur1->data);
        cur1 = cur1->next;
    }

    while (cur2 != NULL) {
        if (!slist_lookup(reslist, cur2->data))
        slist_addnode_tail(reslist,cur2->data);
        cur2 = cur2->next;
    }

    return reslist;
}

Slist* slist_inter(Slist *list1,Slist *list2){
	assert(list1!=NULL && list2!=NULL);
	Slist res = slist_new();
	Slist *reslist = &res;
    Node *cur1 = list1->head;

    while (cur1 != NULL) {
        if (slist_lookup(list2, cur1->data))
        slist_addnode_tail(reslist, cur1->data);
        cur1 = cur1->next;
    }

    return reslist;
}









