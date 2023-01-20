#define MAX 100
typedef struct userinfo usr;
typedef struct posts post;
struct posts
{
    int like;
    int id;
    char *txt;
    post *next;
};
struct userinfo
{
    char *username;
    char *password;
    int postcounter;
    struct posts *newpost;
    usr *next;
};
usr *insert(usr *newnode)
{
    int usern = 0;
    int passn = 0;
    char arr[MAX];
    newnode = (usr *)malloc(sizeof(usr));
    newnode->password = (char *)malloc(sizeof(char));
    newnode->username = (char *)malloc(sizeof(char));
    if (newnode->username == NULL)
    {
        printf("failed");
    }
    if (newnode->password == NULL)
    {
        printf("failed\n");
    }
    printf("Now enter your password and username\n");
    newnode->username[usern] = getchar();    
    while (newnode->username[usern] != ' ')   /*inputing username with dynamic array*/
    {
        usern++;
        newnode->username = (char *)realloc(newnode->username, sizeof(char) * (usern + 1));
        newnode->username[usern] = getchar();
    }
    newnode->password[passn] = getchar();
    while (newnode->password[passn] != '\n') /*inputing password with dynamic array*/
    {
        passn++;
        newnode->password = (char *)realloc(newnode->password, sizeof(char) * (passn + 1));
        newnode->password[passn] = getchar();
    }
    newnode->username[usern] = '\0';
    newnode->password[passn] = '\0';
    newnode->next = NULL;
    newnode->postcounter = 0;
    newnode->newpost=(post*)malloc(sizeof(post)) ;
    newnode->newpost->like = 0;
    newnode->newpost->id = 0;
    newnode->newpost->next = NULL;
    for (int i = 0; i < usern; i++)
    {
        printf("%c", newnode->username[i]);
    }
    return newnode;
}
void addnode(usr *head_of_list, usr *new_usr)
{
    if (new_usr == NULL || head_of_list == NULL)
        head_of_list->next = new_usr;
    new_usr = head_of_list;
}
usr login(usr *temp, int number_of_nodes)
{
    usr fail;
    fail.username = "\0";
    fail.password = "\0";
    int usern = 0;
    char *name;
    char *pass;
    int passn = 0;
    char arr[MAX];
    pass = (char *)malloc(sizeof(char));
    name = (char *)malloc(sizeof(char));
    if (name == NULL)
    {
        printf("failed");
    }
    if (name == NULL)
    {
        printf("failed\n");
    }

    printf("Now enter your password and username\n");
    name[usern] = getchar();
    while (name[usern] != ' ')     /*inputing written username and passowrd by user*/
    {
        usern++;
        name = (char *)realloc(name, sizeof(char) * (usern + 1));
        name[usern] = getchar();
    }
    pass[passn] = getchar();
    while (pass[passn] != '\n')
    {
        passn++;
        pass = (char *)realloc(pass, sizeof(char) * (passn + 1));
        pass[passn] = getchar();
    }
    name[usern] = '\0';
    pass[passn] = '\0';
    usr x;
    usr *previous = temp->next;
    int s;
    int modify = 0;
    int ab = 0;
    for (int i = 0; i < number_of_nodes; i++)  /*find user with username and passowrd*/
    {
        if (previous == NULL)
        {
            ab = 0;
        }

        if ((strcmp(previous->username, name) == 0) && (strcmp(previous->password, pass) == 0))
        {
            ab = 1;
            x = *previous;
            i = MAX;
        }
        previous = previous->next;
    }
    printf("ab=%d", ab);
    if (ab == 0)
    {
        printf("incorrect username name or password");
        x = fail;
    }
    else
    {
        printf("login succesfull");
    }
    return x;
}

void set_new_usr_next_of_head(usr **head, usr *newNode)
{
    if (*head == NULL)
        *head = newNode;
    //Otherwise, find the last node and add the newNode
    else
    {
        usr *lastNode = *head;

        //last node's next address will be NULL.
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }
}
int printinfo(usr* ch)
{
    printf("username:%s\n", ch->username);
    printf("password:%s\n", ch->password);
   
    return 1;
    
}
post *insertpost(post *new, char *job, int counter,int id)
{
    new = malloc(sizeof(post));
    char *ptxt;
    ptxt = malloc(sizeof(char) * counter);
    new->txt = malloc(sizeof(char));
    int count = 0;
    int counters = 0;
    strcpy(ptxt, job);
    for (int x = 0; x < counter - 5; x++)   
    {
        ptxt[x] = ptxt[x + 5];   /*puting post text into a single array*/
        counters++;
    }
    ptxt = (char *)realloc(ptxt, sizeof(char) * counters + 1);
    ptxt[counters] = '\0';
    printf("bbb");
    for (int i = 0; i < counters; i++)
    {
        printf("%c", ptxt[i]);
    }
    new->txt = realloc(new->txt, sizeof(char) * (counters + 1));
    strcpy(new->txt, ptxt);
    (new->txt[counters]) = '\0';
    //id++ ;
    new->id=id ;
    return new;
}
void set_new_post_next_of_head(usr *ch, post *newNode)
{
    //ch->postcounter=ch->postcounter+1 ;
    post *head = ch->newpost ;
    post *lastNode ;
    lastNode=(post*)malloc(sizeof(post)) ;
    lastNode = head;

    //Otherwise, find the last node and add the newNode
    //last node's next address will be NULL.
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    //add the newNode at the end of the linked list
    lastNode->next = newNode;
    free(lastNode) ;
}

int idtonew(usr *ch,post *newp, int id)
{
    id++;
    newp->id = id;  /*giving the postid*/
    ch->postcounter++ ;
    newp->like = 0;
    return id;
}
int findpost(int id, post *head, int counter)
{
    post *last = head;
    for (int i = 0; i < counter; i++)
    {
        if (last->id == id)
        {
            i = counter + 1;
        }
        last = last->next;
    }
    return 1;
}
int finduser(usr *temp, int number_of_nodes, int counter, char *job)
{
    char *uname;
    usr fail;
    printf("%d", counter);
    int counters = 0;
    uname = malloc(sizeof(char) * (counter + 1));
    strcpy(uname, job);
    for (int i = 0; i < counter - 4; i++)
    {
        uname[i] = uname[i + 5];
        counters++;
    }
    uname = realloc(uname, sizeof(char) * (counters + 1));
    uname[counters] = '\0';
    usr x;
    usr *previous = temp->next;
    int s;
    int modify = 0;
    int ab = 0;
    for (int i = 0; i < number_of_nodes; i++)  /*find user with username same as login function */
    {
        int xx = 0;
        while (previous->username[xx] != '\0')
        {
            xx++;
        }
        for (int i = 0; i < xx; i++)
        {

            previous->username[i] = previous->username[i + 1];
        }
        if (previous == NULL)
        {
            ab = 0;
        }

        if (strcmp(previous->username, uname) == 0)
        {
            ab = 1;
            x = *previous;
            i = MAX;
        }
        previous = previous->next;
    }
    printf("ab=%d", ab);
    if (ab == 0)
    {
        printf("\nthere is no user with this username\n");
        x = fail;
    }
    else
    {
        printf("\nuser found\n");
    }
    usr *tempo=&x ;
    post *head=(tempo->newpost->next) ;
    for (int i=0 ; i<=tempo->postcounter ; i++) {
        if (head==NULL) {
            i=MAX ;
            break ;
        }
        printf("post text:%s\n",head->txt) ;
        printf("post likes:%d\n",head->like) ;
        printf("postid:%d\n",head->id) ;
        printf("next post:") ;
        head=head->next ;
    }
    return ab;
}
usr finduserlike(usr *temp, int number_of_nodes, int counter, char *job)
{
    char *uname;
    usr fail;
    printf("%d", counter);
    int counters = 0;
    uname = malloc(sizeof(char) * (counter + 1));
    strcpy(uname, job);
    for (int i = 0; i < counter - 7; i++)
    {
        uname[i] = uname[i + 5];
        counters++;
    }
    for (int i = 0; i < counters; i++)
    {
        printf("%c", uname[i]);
    }
    uname = realloc(uname, sizeof(char) * (counters + 1));
    uname[counters] = '\0';
    usr x;
    usr *previous = temp->next;
    int s;
    int modify = 0;
    int ab = 0;
    for (int i = 0; i < number_of_nodes; i++)  /*finding user same az functions above*/
    {
        int xx = 0;
        while (previous->username[xx] != '\0')
        {
            xx++;
        }
        for (int i = 0; i < xx; i++)
        {

            previous->username[i] = previous->username[i + 1];
        }
        if (previous == NULL)
        {
            ab = 0;
        }

        if (strcmp(previous->username, uname) == 0)
        {
            ab = 1;
            x = *previous;
            i = MAX;
        }
        previous = previous->next;
    }
    printf("ab=%d", ab);
    if (ab == 0)
    {
        printf("\nthere is no user with this username\n");
        x = fail;
    }
    else
    {
        printf("\nuser found\n");
    }
    return x;
}

post *postnext(post *head_of_list, post *new_post)
{
    post *x = head_of_list;
    if (new_post == NULL || x == NULL)
        printf("NO");
    x->next = new_post;
    
    x = new_post;
    return x;
}
void deletepost(post *head, char *job, int counter)
{
    post *deletepost;
    deletepost = (post *)malloc(sizeof(post));
    deletepost = head;
    char str[100];
    //temp = (char*)malloc(sizeof(char) * (counter + 1));
    //strcpy(temp, job);
    for (int i = 0; i < 2; i++)
    {
        str[i] = job[counter - 1 + i];
    }
    int postid = atoi(str);
    printf("%d", postid);
    while (1)
    {
        if (deletepost->next->id == postid) //find the post which the user wants to delete it
        {
            deletepost->next = deletepost->next->next; //delete it from the link list
            break;
        }
        deletepost = deletepost->next;
    }

    //ree(deletepost) ;
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
    temp = NULL;
    return state;
}
void printfile(usr *head)
{
    usr *temp = head->next;
    
    FILE *users = fopen("users.txt", "w");
    FILE *posts = fopen("posts.txt", "w");
    while (temp!= NULL)
    {
        post *temppost = temp->newpost->next;
        fprintf(users, "username:%s\n", temp->username);
        fprintf(users, "password:%s\n", temp->password);
        fprintf(users, "number of posts:%d\n", temp->postcounter);
        
        while(temppost!=NULL) {
            fprintf(posts, "post text:%s\n", temppost->txt);
            fprintf(posts, "post id:%d\n", temppost->id);
            fprintf(posts, "likes:%d\n", temppost->like);
             temppost=temppost->next ;
             
        }
        temp = temp->next ;
         }
    fclose(users);
    fclose(posts);
}
