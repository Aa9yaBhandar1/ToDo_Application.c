#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//program constants 
#define FILENAME "task.txt"
#define MAX_TASKS 100

//Function prototypes 
void load_task();
void add_task();
void view_task();
void update_task();
void delete_task();
void save_task();

//global variable 
int num_tasks=0;

//structure for task 
struct tasks
{
    char title[100];
    char description[300];
    int due_date[30];
}task[MAX_TASKS];
int main()
{
    load_task();
    int c;
    do
    {    printf("\n=============================");
        printf("\n Welcome to ToDo Application");
        printf("\n============================= \n");
        printf(" 1.Add a new task \n 2.View existing tasks \n 3.Update a task \n 4.Delete a task \n 5.Exit \n");
        scanf("%d",&c);
    switch(c)
    {
        case 1:{add_task(); break;}
        case 2:{view_task(); break;}
        case 3:{update_task(); break;}
        case 4:{delete_task();break;}
        case 5:
        { 
            save_task();
            printf("Exiting the program...\n");
            exit(0);
        }
        default:{printf("Invalid Input\n"); break;}
    }}while(5);
}
void load_task() {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    while (fscanf(fp, "%[^|]|%[^|]|%[^|]|\n", task[num_tasks].title, task[num_tasks].description, task[num_tasks].due_date)!= EOF) {
        num_tasks++;
    }
    fclose(fp);
    printf("Tasks loaded from file.\n");
}
    void save_task()
    {
        FILE *fp=fopen(FILENAME,"w");
        if(fp==NULL){printf("Error opening file!!!\n");}
        else
        { 
            for(int i=0;i<num_tasks;i++)
            {
                fprintf(fp,"%s|%s|%s|\n", task[i].title, task[i].description, task[i].due_date);
            }
            fclose(fp);
            printf("Task data saved to file.\n");
        }
    }

    void add_task()
    {
        printf("\n Adding the task...\n");
        fflush(stdin);
        printf("Enter the task title:\n");
        scanf(" %[^\n]", task[num_tasks].title);
        printf("Enter description:\n");
        fflush(stdin);
        scanf(" %[^\n]", task[num_tasks].description);
        printf("Enter the due date:\n");
        fflush(stdin);
        scanf(" %[^\n]", task[num_tasks].due_date);
        num_tasks++;
        
        //Adding the task 
        save_task();
     }
     //to view existing tasks 
    void view_task()
    {
       printf("Viewing existing tasks...\n");
       if(num_tasks==0){ printf("No task exists!!!");}
      for(int i=0;i<num_tasks;i++)
      {
         printf("Task %d\n",i+1);
         printf("Task title:%s\n",task[i].title);
        printf("Task description:%s\n",task[i].description);
        printf("Task Due Date:%s\n",task[i].due_date);
        printf("\n");
      }
      
    }
    //to delete the user selected tasks
    void delete_task()
    {
        int task_index;
        printf("Deleting the task...\n");
        printf("Enter the index of task you want to delete:\n");
        scanf("%d",&task_index);
        if(task_index<1 || task_index>num_tasks){ printf("Invalid Task Index!!!\n");}
        else
        {
            for(int i=task_index-1; i<num_tasks-1;i++){
                task[i]=task[i+1];
            }num_tasks--;
            printf("Task deleted successfully!!!\n");
            //save tasks to file after deleting 
            save_task();
        }
    }
    void update_task()
    {
        int task_index;
        printf("\n Updating the task...\n");
        printf("Enter the index of task you want to update:\n");
        scanf("%d",&task_index);
        if(task_index<1 || task_index>num_tasks){printf("Invalid Task Index!!!\n");}
        else
        {
            printf("Enter new task title:\n");
            scanf(" %[^\n]", task[task_index - 1].title);
            printf("Enter new task description:\n");
            scanf(" %[^\n]", task[task_index - 1].description);
            printf("Enter new task's due date:\n");
            scanf(" %[^\n]", task[task_index - 1].due_date);
            printf("Task updated successfully.\n");
            //save task after updating it to the file
            save_task();
        }
    }

