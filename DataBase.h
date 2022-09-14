
/**********************************
* Created by    : Eng/ Ali Shawky *
* Copy Rights to: AMIT Learning   *
**********************************/


#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

/*we should include the data types which will be used in this project*/
#include "Standard_DataTypes.h"



/*the  size of the data base*/
#define DataBase_Size   10



/*the Simple Data base of each student*/
typedef struct
{

    uint8 Student_ID;
    uint8 Student_Year;

    uint8 Course1_ID;
    uint8 Course1_Grade;

    uint8 Course2_ID;
    uint8 Course2_Grade;

    uint8 Course3_ID;
    uint8 Course3_Grade;

}SimpleDb;




/*we should define then Data Base Functions Prototypes*/
/***********************************************
 this function checks if the Data Base is full
 returns 1 if the database is full, otherwise 0
************************************************/
bool SDB_IsFULL(void);


/***********************************************
 this function get the number of entries in
 the Data Base and return it
************************************************/
uint8 SDB_GetUsedSize(void);


/***********************************************
 this function adds a new entry in the data base
 and returns 1 if the new entry is successfully
 added, otherwise 0
************************************************/
bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades );


/*************************************************
 this function deletes the entry with the given id
**************************************************/
void SDB_DeleteEntry(uint8 id);


/***************************************************
 this function reads the entry matching the given id
 returns 1 if the entry is exist , otherwise 0
****************************************************/
bool SDB_ReadEntry(uint8 id, uint8* year, uint8* subjects, uint8* grades );


/*********************************************
 this function get the list of id of students
**********************************************/
void SDB_GetIdList(uint8* Count,uint8* List);


/**********************************************************
 this function checks if the provided students id exists
 returns 1 if the provided students id exists, otherwise 0
**********************************************************/
bool SDB_IsIdExist(uint8 ID);

#endif // DATABASE_H_INCLUDED
