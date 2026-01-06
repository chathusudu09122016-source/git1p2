#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Day{
    char*name;
    int date;
    char*description;
}Day;

Day*createCalender(){
    Day*calender = (Day*)malloc(7*sizeof(Day));

if(!calender){
    printf("Error:Memory allocation failed.\n ");
    exit(1);
    }
for (int i= 0;i<7;i++){
    calender[i].name =(char*)malloc(20*sizeof(char));
    calender[i].description=(char*)malloc(100*sizeof(char));

}
return calender;
}

void readData(Day*calender){
    for(int i=0;i<7;i++){
        printf("Enter day name:");
        scanf("%s",calender[i].name);
        printf("Enter date:");
        scanf("%d",&calender[i].date);
        printf("Enter activity description:");
        scanf("%*c");
        fgets(calender[i].description,100,stdin);
    }
}

void displayReport(Day*calender){
    printf("Weekly Activity report\n");
    printf("Weekly Activity Report \n\n");
    for (int i=0; i<7;i++){
        printf("%s - %d:%s\n",calender[i].name,calender[i].date,calender[i].description);
    }
}

int main(){

Day*calendar = createCalender();
readData(calendar);
displayReport(calendar);
for (int i =0;i < 7;i++){
    free(calendar[i].name);
    free(calendar[i].description);

}
free(calendar);
return 0;
}

