#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#define MAX 100
int likepost(post *head, int likeno, usr *likeduser);
void deletepost(post *user, char *job, int counter);
void printfile(usr *head);
int main()
{
    int nodes = 0;
    usr *head = NULL;
    head = (usr *)malloc(sizeof(usr));
    usr *temporary;
    temporary = (usr *)malloc(sizeof(usr));
   

    temporary = head;
    int logoutno = 1;
    int n;
    int counterpost = 0;
    char input[MAX];
    int postid ;
    while (1)  /*main loop of program*/
    {

        logoutno = 1;
        printf("Enter 1 for sign up and 2 for login\n");
        postid=0 ;
        scanf("%d", &n);
        logoutno = 1;
        while (logoutno == 1)
        {
            if (n == 1)
            {
                usr *new = insert(new);
                set_new_usr_next_of_head(&head, new);
                nodes++;
                printf("%d", nodes);
                for (int i = 0; i < 10; i++)
                {
                    printf("%c", head->next->username[i]);
                }
                if (strcmp(head->next->username, "\0") != 0)
                {
                    n = 3;
                }
            }
            
            if (n == 2)
            {
                char *job;
                char *job1;
                int loop = 1;
                int counter = 0;
                postid= 0;
                usr ch;
                ch = login(head, nodes);  /*user that logs in*/
                usr *userlogin;
                userlogin = (usr *)malloc(sizeof(usr));
                userlogin = &ch;
                for (int i = 0; i < 5; i++)
                {
                    printf("%c", ch.username[i]);
                }
                printf("\n");
                post *headpost;
                headpost = (post *)malloc(sizeof(post));
                headpost = userlogin->newpost;

                while (loop == 1)
                {    /*after login loop*/
                    counter = 0;
                    printf("write what you want to do\n");
                    job = (char *)malloc(sizeof(char));

                    
                    job[counter] = getchar();
                    while ((job[counter] != '\n'))
                    {
                        counter++;
                        job = (char *)realloc(job, sizeof(char) * (counter + 1));
                        job[counter] = getchar();
                    }
                    job[counter] = '\0';
                    printf("%d", counter);
                   /*if clauses are different tasks you can do after logging in*/
                    if (strncmp(job, "logout", 6) == 0)
                    {
                        printf("b");
                        n = MAX;
                        free(job);
                        counter = 0;
                        loop = 0;
                    }
                    else if (strncmp(job, "info", 4) == 0)
                    {
                        printf("a");
                        printinfo(userlogin);
                        free(job);
                        job = NULL;
                        counter = 0;
                        
                    }
                    else if (strncmp(job, "post", 4) == 0)
                    {
                        printf("a");
                        post *temp;
                        temp = (post *)malloc(sizeof(post));
                        temp = headpost;
                        post *newp = malloc(sizeof(post));
                        postid++ ;
                        printf("%d",postid) ;
                        newp = insertpost(newp, job, counter,postid);
                        
                        set_new_post_next_of_head(userlogin, newp);
                        
                        userlogin->postcounter=postid ;         
                        int countpost=userlogin->postcounter ;
                        printf("%d",countpost) ;
                        printf("\n");
                        printf("postid:%d", postid);
                        printf("xx");
                        counterpost++;
                        for (int i = 0; i <= countpost; i++)
                        {
                            printf("%d", temp->id);
                            printf("%s", temp->txt);
                            temp = temp->next;
                        }
                        printf("cnt%d", userlogin->postcounter);
                        //temp = NULL;
                        free(temp) ;
                        //free(newp);
                        free(job);
                        counter = 0;
                    }
                    else if (strncmp(job, "find", 4) == 0)
                    {
                        printf("find");
                        int find = finduser(head, nodes, counter, job);
                        job = NULL;
                        free(job);
                        counter = 0;
                    }
                    else if (strncmp(job, "like", 4) == 0)
                    {
                        
                        post *firstpost;
                        firstpost = (post *)malloc(sizeof(post));
                        char *str;
                        char str1[MAX] ;
                        printf("xxlike");
                        usr likedusr;
                        likedusr = finduserlike(head, nodes, counter, job);
                        usr *likeduser;
                        likeduser = (usr *)malloc(sizeof(usr));
                        likeduser=&(likedusr);
                        printf("%d",likeduser->postcounter) ;
                        printinfo(likeduser);
                        firstpost = (likeduser->newpost->next);
                        printf("id:%d\n", firstpost->id);
                        // for (int i = 0; i <0; i++)
                        //{
                        //printf("%d", likedusr.newpost.next->id);
                        //printf("%s", likedusr.newpost.next->txt);
                        //likedusr.newpost.next = likedusr.newpost.next->next;
                        //}
                        //printf("%d",counter) ;
                        printf("%d",job[counter-1]) ;
                        //str[0]=job[counter-1] ;
                        /*for (int i = 0; i < 1; i++)
                        {
                            str[i] = job[counter -  + i];
                        }  
                        str[1]='\0' ; */
                        int likeno = job[counter-1]-48;  
                        printf("likeno:%d\n", likeno);
                        //printf("%d", counterpost);
                        int likestate = likepost(firstpost, likeno, likeduser);
                        printf("state:%d", firstpost->like);
                        free(job);
                        //firstpost = NULL;
                        //str = NULL;
                        //job = NULL;
                        //counter = 0;
                    }
                    else if (strncmp(job, "delete", 6) == 0)
                    {
                        printf("delete");
                        printf("%d", counter);
                        deletepost(headpost, job, counter);
                        userlogin->postcounter--;
                        free(job);
                        counter = 0;
                    }
                    else if (strncmp(job, "exit", 4) == 0)
                    {
                        printf("ex") ;
                        printfile(head);
                        loop = 0;
                    }
                }
            }
            if (n == MAX)
            { /*logout after login*/
                logoutno = 0;
                counterpost = 0;
                postid=0 ;
                printf("You logged out succesfully\n");
            }
            if (n == 3)
            { /*logout after signup*/
                scanf("%s", input);
                if (strcmp(input, "logout") == 0)
                {
                    logoutno = 0;
                    printf("You logged out succesfully\n");
                }
            }
        }
    }
}
int likepost(post *head, int likeno, usr *likeduser)
{
    int counter1 = likeduser->postcounter;
    printf("counter:%d\n", counter1);
    printf("%d\n", likeno);
    post *temp;
    temp = (post *)malloc(sizeof(post));
    temp = head;
    //printf("%d\n", temp->next->id);
    int state = 0;
    /*while (temp!=NULL) {
        if ()
        temp=temp->next
    } */
    for (int i = 0; i < MAX; i++)
    {
        if (temp->id == likeno)
        {
            printf("xx");
            temp->like++;
            i = MAX;
            state = 1;
        }
        if (temp == NULL)
        {
            state = 0;
            i = MAX;
        }
        temp = temp->next;
    }

    if (state == 1)
    {
        printf("post liked succesfully\n");
        //printf("%d",temp->id) ;
    }
    else
    {
        printf("post not found\n");
    }
    //temp = NULL;
    return state;
}

