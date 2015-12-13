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
 if(start_rab==NULL) //если был пустым
  start_rab=element; 
  else  //не был пустым
   {point=start_rab;
    while(point->sled!=NULL) //шагаем по списку и ищем место, куда надо будет вставить новый элемент
	  {if(element->znachenie<point->znachenie) break;
	   point=point->sled;
	  }
    if(start_rab==point)//если элемент единственный
	 {if(element->znachenie<point->znachenie) //и введенная строка структуры меньше
	    {element->sled=point; 
		 point->pred=element;
		 start_rab=element; //смещаем начало списка на ставший первым элемент
		}
	   else   //введенное позже по алфавиту
	    {point->sled=element; 
	     element->pred=point;
	    }
	 }
    else //если не единственный элемент
     if(element->znachenie<point->znachenie) 	//вставляем до текущего: введенное раньше по алфавиту
      {(point->pred)->sled=element;
	   element->pred=point->pred; 
	   element->sled=point;
	   point->pred=element;
	  }
	 else  //введенное позже по алфавиту, т.о. в конец
	  {point->sled=element; 
	   element->pred=point;
	  }
   }
}

void printList1()
{struct spisok1 *point;
 point=start_for_print;
 if(start_for_print==NULL)  //если список пустой
  {printf("massiv pust ^__^\n"); 
   return;
  } 
 while(point!=NULL) //не пустой
  {printf("%d => ", point->znachenie);
   point=point->sled;
  } 
 printf("\n");
}

void printList2()
{struct spisok1 *point;
 point=start_rab;
 if(start_rab==NULL)  //если список пустой
  {printf("massiv pust ^__^\n"); 
   return;
  } 
 while(point!=NULL) //не пустой
  {printf("%d => ", point->znachenie);
   point=point->sled;
  } 
 printf("\n");
}

void copyList()
{struct spisok1 *point;
 point=start_rab;
 if(start_rab==NULL)  //если список пустой
  {printf("massiv pust ^__^\n"); 
   return;
  }
 while(point!=NULL) //не пустой
  {start_for_print=point;
   point=point->pred;
  } 
}