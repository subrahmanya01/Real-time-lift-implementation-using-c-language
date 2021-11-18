#include<stdio.h>
int current;
int cal_arr[10];
int dest_arr[10];
void init(int* ptr)
{
    int i;
    for(i=0;i<10;i++)
      *(ptr+i)=-1;
}
void sort(int* ptr)
{
	int i, j, t;
	for (i = 0; i <10; i++) {

		for (j = i + 1; j < 10; j++) {

			if (*(ptr + j) < *(ptr + i)) {

				t = *(ptr + i);
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = t;
			}
		}
	}
}
void door_open_function()
{
    int dest;
    printf("Door opens\n");
    printf("Enter the destination floor\n");
    scanf("%d",&dest);
    dest_arr[0]=dest;
    sort(dest_arr);
    printf("Door closes\n");
}
void display(int arr[])
{
    int i;
    for(i=0;i<10;i++)
      printf("%d ",arr[i]);
    printf("\n");
}
void make_minus(int* ptr,int number)
{
    int i;
    for(i=0;i<10;i++)
    {
        if (*(ptr + i) == number)
        {
            *(ptr+i)=-1;
            break;
        }
    }
    sort(ptr);
}
void move(int from,int to)
{
    int i,j;
    int call,next_cal_at=-1,next_lift_at=-1;
    if(from<to)
    {
        for(i=from+1;i<=to;i++)
        {
            printf("Lift at %d\n",i);
            display(cal_arr);
            display(dest_arr);
            printf("Enter the call(if not press 17)");
            scanf("%d",&call);
               if(call==12)
						 {
							 
							 printf("Emergency\nlift is mooving to gnd");
							 for(i=0;i<10;i++)
							 {
								 make_minus(dest_arr,dest_arr[i]);
								 make_minus(cal_arr,cal_arr[i]);
							 }
							 for(i=current;i>=0;i--)
							   {
									 current=i;
									 printf("lift at %d\n",current);
                                     printf("Open the door");
								 }
                                break;	
                            		 
						 }
             else if(call!=17)
             {
                 cal_arr[0]=call;
                 sort(cal_arr);
             }
            current=i;
            for(j=0;j<=10;j++)
            {
                if(cal_arr[j]>=current)
                {
                    next_cal_at=cal_arr[j];
                    break;
                }
            }
             for(j=0;j<10;j++)
            {
                if(dest_arr[j]>=current)
                {
                    next_lift_at=dest_arr[j];
                    break;
                }
            }    
            printf("\nNext door open for pick %d\n",next_cal_at);
            printf("Next door open for lieve %d\n",next_lift_at);

            if(next_lift_at==current && next_cal_at==current)
            {
                door_open_function();
                make_minus(cal_arr,next_cal_at);
                make_minus(dest_arr,next_lift_at);
                next_cal_at=-1;
                next_lift_at=-1;
            }
            else if(next_cal_at==current)
            {
                door_open_function();
                make_minus(cal_arr,next_cal_at);
                next_cal_at=-1;
            }    
            else if(next_lift_at==current)
            {
                printf("open door\nclose door\n");
                make_minus(dest_arr,next_lift_at);
                next_lift_at=-1;
                next_cal_at=-1;
            }

            for(j=0;j<=10;j++)
            {
                if(cal_arr[j]>=current)
                {
                    next_cal_at=cal_arr[j];
                    break;
                }
            }
             for(j=0;j<10;j++)
            {
                if(dest_arr[j]>=current)
                {
                    next_lift_at=dest_arr[j];
                    break;
                }
            }
            if(next_cal_at>to)
            to=next_cal_at;
            if(next_lift_at>to)
            to=next_lift_at;
        }
    }
    else
    {
        
         for(i=from-1;i>=to;i--)
        {
            printf("Lift at %d\n",i);
            display(cal_arr);
            display(dest_arr);
            printf("Enter the call(if not press 17)");
            scanf("%d",&call);
             
             if(call==12)
						 {
							 
							 printf("Emergency\nlift is mooving to gnd");
							 for(i=0;i<10;i++)
							 {
								 make_minus(dest_arr,dest_arr[i]);
								 make_minus(cal_arr,cal_arr[i]);
							 }
							 for(i=current;i>=0;i--)
							   {
									 current=i;
									 printf("lift at %d\n",current);
                                     printf("Open the door");
								 }	
                                 break;
                            		 
						 }
            else if(call!=17)
             {
                 cal_arr[0]=call;
                 sort(cal_arr);
             }
            current=i;
            for(j=9;j>=0;j--)
            {
                if(cal_arr[j]<=current && cal_arr[j]>-1)
                {
                    next_cal_at=cal_arr[j];
                    break;
                }
            }
             for(j=9;j>=0;j--)
            {
                if(dest_arr[j]<=current  && dest_arr[j]>-1)
                {
                    next_lift_at=dest_arr[j];
                    break;
                }
            }    
            printf("\nNext door open for pick %d\n",next_cal_at);
            printf("Next door open for lieve %d\n",next_lift_at);
            if(next_lift_at==current && next_cal_at==current)
            {
                door_open_function();
                make_minus(cal_arr,next_cal_at);
                make_minus(dest_arr,next_lift_at);
                next_cal_at=-1;
                next_lift_at=-1;
            }
            else if(next_cal_at==current)
            {
                door_open_function();
                make_minus(cal_arr,next_cal_at);
                next_cal_at=-1;
            }    
            else if(next_lift_at==current)
            {
                printf("open door\nclose door\n");
                make_minus(dest_arr,next_lift_at);
                next_lift_at=-1;
            }
            for(j=9;j>=0;j--)
            {
                if(cal_arr[j]<=current && cal_arr[j]>-1)
                {
                    next_cal_at=cal_arr[j];
                    break;
                }
            }
             for(j=9;j>=0;j--)
            {
                if(dest_arr[j]>=current && dest_arr[j]>-1)
                {
                    next_lift_at=dest_arr[j];
                    break;
                }
            }
            if(next_cal_at>to)
            to=next_cal_at;
            if(next_lift_at>to)
            to=next_lift_at;
        }
        
    }
}
int main()
{
 current=0;
 int cal_lift,dest,j;
 init(cal_arr);
 init(dest_arr);
 while(1)
 {
     printf("Current floor of the lift %d\n",current);
     printf("Enter the call(if not press 17)");
     scanf("%d",&cal_lift);

      if(cal_lift==current)
      {
        door_open_function();
         for(j=0;j<10;j++)
            {
                if(dest_arr[j]>=current)
                {
                    dest=dest_arr[j];
                    break;
                }
            }
        move(current,dest);   
      }
     else if(cal_lift!=17)
      {
                 cal_arr[0]=cal_lift;
                 sort(cal_arr);
                 move(current,cal_lift);
      }
      else if(cal_lift==17)
      {
          for(j=0;j<10;j++)
            {
                if(dest_arr[j]>=current)
                {
                    dest=dest_arr[j];
                    break;
                }
            }
        move(current,dest);
      }
          
 }
 return 0;
}