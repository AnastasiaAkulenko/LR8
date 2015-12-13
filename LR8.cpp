#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

struct spisok1
{
int znachenie;
struct spisok1 *pred;
struct spisok1 *sled;
} *start_rab=NULL, *start_for_print=NULL; 

void dobav();
void printList2();
void printList1();
void copyList();

int main(int argc, char* argv[])
{printf("\n");
 for(int i=0; i<9; i++)
  {
   dobav();
  }
 copyList();
 printf("poluchennii massiv:\n");
 printList1();
 dobav();
 printf("izmenennii massiv: \n");
 printList2();
 return 0;
}

void dobav()
{struct spisok1 *element, *point;
 element=(spisok1 *)malloc(sizeof(spisok1));
 puts("Vvedite element massiva: ");
 scanf("%d", &element->znachenie);
 element->pred=NULL;
 element->sled=NULL; 
 if(start_rab==NULL) //���� ��� ������
  start_rab=element; 
  else  //�� ��� ������
   {point=start_rab;
    while(point->sled!=NULL) //������ �� ������ � ���� �����, ���� ���� ����� �������� ����� �������
	  {if(element->znachenie<point->znachenie) break;
	   point=point->sled;
	  }
    if(start_rab==point)//���� ������� ������������
	 {if(element->znachenie<point->znachenie) //� ��������� ������ ��������� ������
	    {element->sled=point; 
		 point->pred=element;
		 start_rab=element; //������� ������ ������ �� ������� ������ �������
		}
	   else   //��������� ����� �� ��������
	    {point->sled=element; 
	     element->pred=point;
	    }
	 }
    else //���� �� ������������ �������
     if(element->znachenie<point->znachenie) 	//��������� �� ��������: ��������� ������ �� ��������
      {(point->pred)->sled=element;
	   element->pred=point->pred; 
	   element->sled=point;
	   point->pred=element;
	  }
	 else  //��������� ����� �� ��������, �.�. � �����
	  {point->sled=element; 
	   element->pred=point;
	  }
   }
}

void printList1()
{struct spisok1 *point;
 point=start_for_print;
 if(start_for_print==NULL)  //���� ������ ������
  {printf("massiv pust ^__^\n"); 
   return;
  } 
 while(point!=NULL) //�� ������
  {printf("%d => ", point->znachenie);
   point=point->sled;
  } 
 printf("\n");
}

void printList2()
{struct spisok1 *point;
 point=start_rab;
 if(start_rab==NULL)  //���� ������ ������
  {printf("massiv pust ^__^\n"); 
   return;
  } 
 while(point!=NULL) //�� ������
  {printf("%d => ", point->znachenie);
   point=point->sled;
  } 
 printf("\n");
}

void copyList()
{struct spisok1 *point;
 point=start_rab;
 if(start_rab==NULL)  //���� ������ ������
  {printf("massiv pust ^__^\n"); 
   return;
  }
 while(point!=NULL) //�� ������
  {start_for_print=point;
   point=point->pred;
  } 
}