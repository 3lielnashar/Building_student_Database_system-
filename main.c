
/**********************************
* Created by    : Eng/ Ali Shawky *
* Copy Rights to: AMIT Learning   *
**********************************/


#include <stdio.h>
#include <stdlib.h>

#include "DataBase.h"

uint8 user_input = 0;


void Check_theUserinput(void)
{
    printf("\n  ---------------------------------------------------------------------------------------\n");
    printf(" | -->if you need to enter new student press                                    [ 1 ]      |\n ");
    printf("| -->if you need to check if the data base is full press                       [ 2 ]      |\n ");
    printf("| -->if you need to know the number of students in the data base press         [ 3 ]      |\n ");
    printf("| -->if you need to delete an student from the data base press                 [ 4 ]      |\n ");
    printf("| -->if you need to read the data of a specific student press                  [ 5 ]      |\n ");
    printf("| -->if you need to get the ids of the students in the data base student press [ 6 ]      |\n ");
    printf("| -->if you need to check if a specific student's id exists press              [ 7 ]      |\n ");
    printf("| -->if you need to exit                                                       [ 8 ]      |\n ");
    printf(" ----------------------------------------------------------------------------------------\n");

    scanf("%d",&user_input);

}

int main()
{


    uint8 entered_id = 0;
    uint8 entered_year = 0;
    uint8 Subjects[3] = {0};
    uint8 Grades[3] = {0};
    uint8 id_list[10] = {0};
    uint8 id_list_size = 0;
    uint8 i = 0;
    bool check_status = 2;



    Check_theUserinput();



  while( user_input != 8)
  {

   switch(user_input)
  {

   case 1:

      printf(" enter the new student's id\n");
      scanf("%d",&entered_id);

      printf(" enter the new student's year\n");
      scanf("%d",&entered_year);

      printf(" enter the new student's subject ids\n");
      for(i = 0 ; i < 3 ; i ++)
      {
        printf("subject %d id:\n", i+1);
        scanf("%d",&Subjects[i]);
      }

      printf(" enter the new student's subject grades\n");
      for(i = 0 ; i < 3 ; i ++)
      {
        printf("subject %d grade:\n", i+1);
        scanf("%d",&Grades[i]);
      }


     check_status = SDB_AddEntry(entered_id, entered_year, Subjects, Grades );

     if(check_status == True)
     {
         printf("\nthe student was added successfully\n");
     }
     else
     {
         printf("\nthe student wasn't added successfully\n");
     }

     Check_theUserinput();

     break;



   case 2:

        check_status = SDB_IsFULL();

        if(check_status == True)
        {
            printf("the data base is full\n");
        }
        else
        {
            printf("the data base is not full\n");
        }

     Check_theUserinput();

     break;



   case 3:


    printf("the number of students in the data base is%d students",SDB_GetUsedSize());

    Check_theUserinput();

     break;



   case 4:


     printf(" enter the id of the student you want to delete\n");
     scanf("%d",&entered_id);

     SDB_DeleteEntry(entered_id );

     Check_theUserinput();

     break;



    case 5:

      printf("enter the id of the student you want to read his data\n");
      scanf("%d",&entered_id);

     SDB_ReadEntry(entered_id, &entered_year, Subjects, Grades );

     printf(" the student's year : %d\n", entered_year);


      for(i = 0 ; i < 3 ; i ++)
      {
        printf("the subject number %d id is:%d\n", i+1, Subjects[i]);

      }

      for(i = 0 ; i < 3 ; i ++)
      {
        printf("the subject number %d grade is:%d\n", i+1, Grades[i]);

      }

     Check_theUserinput();

     break;



    case 6:

    SDB_GetIdList(&id_list_size, id_list);

    if(id_list_size > 0)
    {
      for( i = 0 ; i <= id_list_size ; i ++)
      {
          printf("the student number: %d has the ID: %d\n",i+1, id_list[i]);
      }
    }
    else
    {
        printf("the list is empty");
    }


     Check_theUserinput();

     break;



    case 7:

      printf("enter the id of the student you want to check if exists in the data base\n");
      scanf("%d",&entered_id);

     check_status = SDB_IsIdExist(entered_id);

     if(check_status == True)
     {
         printf("the student exists in the data base");
     }
     else
     {
         printf("the student does not exist in the data base");

     }

     Check_theUserinput();

     break;



    default:

        printf("undefined enter");
        Check_theUserinput();
        break;

  }
}

printf("\n\nThanks For Using Our Application\n\n");
    return 0;
}
