
/**********************************
* Created by    : Eng/ Ali Shawky *
* Copy Rights to: AMIT Learning   *
**********************************/


#include"DataBase.h"


/*the Data Base of Students*/
SimpleDb DataBase[DataBase_Size];


/*the position in the data base*/
uint8 Position = 0;

/*the implementation of the Data Base functions*/
bool SDB_IsFULL(void)
{

 if(Position == DataBase_Size)
 {
     return True;
 }
 else
 {
    return False;
 }

}


uint8 SDB_GetUsedSize(void)
{

    return (Position);

}




bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades )
{

    uint8 id_cnt = 0;
    uint8 grade_cnt = 0;

if( Position == DataBase_Size)
{
    return False;
}
else
{
    DataBase[Position].Student_ID = id;
    DataBase[Position].Student_Year = year;

    DataBase[Position].Course1_ID = subjects[id_cnt++];
    DataBase[Position].Course2_ID = subjects[id_cnt++];
    DataBase[Position].Course3_ID = subjects[id_cnt];

    DataBase[Position].Course1_Grade = grades[grade_cnt++];
    DataBase[Position].Course2_Grade = grades[grade_cnt++];
    DataBase[Position].Course3_Grade = grades[grade_cnt];

    Position++;

    return True;
}


return -1;

}

void SDB_DeleteEntry(uint8 id)
{

 uint8 search_cnt = 0;
 uint8 delete_cnt = 0;

 for(search_cnt = 0 ; search_cnt < Position ; search_cnt++)
 {
     if(DataBase[search_cnt].Student_ID == id)
     {
         delete_cnt = search_cnt;
         break;
     }

 }

 if(delete_cnt != 0)
 {
     while(delete_cnt < Position-1 )
     {
         DataBase[delete_cnt] = DataBase[delete_cnt+1];
         delete_cnt++;
     Position--;
 }
 else
     {
         printf("the student with that id not found in the data base");
         return ;
     }

}


bool SDB_ReadEntry(uint8 id, uint8* year, uint8* subjects, uint8* grades )
{

  uint8 search_cnt = 0;
  uint8 id_cnt     = 0;
  uint8 grade_cnt  = 0;

  for(search_cnt = 0 ; search_cnt < Position ; search_cnt++)
 {
      if(DataBase[search_cnt].Student_ID == id)
     {

       *year =  DataBase[search_cnt].Student_Year;

       subjects[id_cnt++] = DataBase[search_cnt].Course1_ID;
       subjects[id_cnt++] = DataBase[search_cnt].Course2_ID;
       subjects[id_cnt]   = DataBase[search_cnt].Course3_ID ;

       grades[grade_cnt++] = DataBase[search_cnt].Course1_Grade;
       grades[grade_cnt++] = DataBase[search_cnt].Course2_Grade;
       grades[grade_cnt]   = DataBase[search_cnt].Course3_Grade;

       return True;

     }

 }



 return False;

}


void SDB_GetIdList(uint8* Count,uint8* List)
{

 uint8 database_cnt = 0;
 uint8 List_cnt     = 0;

if(Position > 0)
{

 for(database_cnt = 0 ; database_cnt < Position ; database_cnt++)
 {
    List[List_cnt] = DataBase[database_cnt].Student_ID;
    List_cnt++;
 }

 *Count = List_cnt-1;

}
else
{
    *Count = 0;
}

}


bool SDB_IsIdExist(uint8 ID)
{

   uint8 search_cnt = 0;


  for(search_cnt = 0 ; search_cnt < Position ; search_cnt++)
  {
     if(DataBase[search_cnt].Student_ID == ID)
     {
         return True;
     }

  }

  return False;

}
