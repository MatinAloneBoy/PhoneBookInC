#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Person
{
    char name[50];
    char familyName[50];
    char uniNum[50];
    char major[50];
    char idNum[50];
    char homeNumber[50];
    char phoneNumber[50];
    char address[1000];
    char sex[10];
    char nezamCode[50];
}person[1000],sortedByName[1000],sortedByLastName[1000],sortedByUniNumber[1000];
int codeUValidation(char str[50]);
int numberValidaion(char str[50]);
int stringValidator(char str[50]);
void sortByName(int n);
void sortByLastName(int n);
void sortByUniNum(int n);
char names[1000][40];
char lastNames[1000][40];
char uniNumbers[1000][40];
int main(){
  char scanner[1000];
  char command[50];
  char *scan2[50];
  int validation=1;
  int i=0,j=0;
  FILE *tp=fopen("phonebook.txt", "w+");
  fclose(tp);
  FILE *fp=fopen("phonebook.txt", "a+");
  fclose(fp);
  printf("Enter your command : \n (add,Sort By Name,Sort By LastName,Sort By UniNum,edit,remove,remove info)\n");
  scanf("%[^\n]%*c",command);
  while(strcmp(command,"exit")!=0){
    fp=fopen("phonebook.txt", "a+");
    if(strcmp(command,"add")==0){
        
      j=0;
      scanf("%[^\n]%*c", scanner);
      char *token = strtok(scanner, " ");
      while (token != NULL)
      {
        scan2[j++]=token;
        token = strtok(NULL, " ");
      }
      if(strcmp(scan2[8],"male")==0){
        if(stringValidator(scan2[0])==0)
        {
          strcpy(person[i].name,scan2[0]);
          validation=0;
          strcpy(names[i],scan2[0]);
        }
        else{printf("Enter Name Correctly\n");validation=1;}

        if(stringValidator(scan2[1])==0){strcpy(person[i].familyName,scan2[1]);validation=0; strcpy(lastNames[i],scan2[1]);}
        else{printf("Enter LastName Correctly\n");validation=1;}
        
        if(stringValidator(scan2[3])==0){strcpy(person[i].major,scan2[3]);validation=0;}
        else{printf("Enter Major Correctly\n");validation=1;}

        if(stringValidator(scan2[7])==0){strcpy(person[i].address,scan2[7]);validation=0;}
        else{printf("Enter Address Correctly\n");validation=1;}

        if(stringValidator(scan2[8])==0){strcpy(person[i].sex,scan2[8]);validation=0;}
        else{printf("Enter Sex Correctly\n");validation=1;}

        if(numberValidaion(scan2[5])==0){strcpy(person[i].homeNumber,scan2[5]);
        validation=0;}
        else if(numberValidaion(scan2[5])==1){printf("Enter Phone Correctly\n");validation=1;}
        else if(numberValidaion(scan2[5])==-1){printf("Enter Phone With City Code Or Enter It Correctly\n");validation=1;}

        if(numberValidaion(scan2[6])==0){strcpy(person[i].phoneNumber,scan2[6]);validation=0;}
        else if(numberValidaion(scan2[6])==1){printf("Enter Phone Correctly\n");validation=1;}
        else if(numberValidaion(scan2[6])==-1){printf("Enter Complete Phone Number Or Enter It Correctly\n");validation=1;}

        if(codeUValidation(scan2[2])==0){strcpy(person[i].uniNum,scan2[2]);validation=0; strcpy(uniNumbers[i],scan2[2]);}
        else{printf("Enter UniNumber Correctly\n");validation=1;}
        
        if(codeUValidation(scan2[4])==0){strcpy(person[i].idNum,scan2[4]);validation=0;}
        else{printf("Enter IdNumber Correctly\n");validation=1;}
        
        if(codeUValidation(scan2[9])==0){strcpy(person[i].nezamCode,scan2[9]);validation=0;}
        else{printf("Enter NezamCode Correctly\n");validation=1;};
        
        if(validation==0){
          fprintf(fp,"%s %s %s %s %s %s %s %s %s %s\n",person[i].name,person[i].familyName,person[i].uniNum,person[i].major,person[i].idNum,person[i].homeNumber,person[i].phoneNumber,person[i].address,person[i].sex,person[i].nezamCode);
          i++;
        }
      }
      else{
        if(stringValidator(scan2[0])==0){strcpy(person[i].name,scan2[0]);
        validation=0; strcpy(names[i],scan2[0]);}
        else{printf("Enter Name Correctly\n");validation=1;}

        if(stringValidator(scan2[1])==0){strcpy(person[i].familyName,scan2[1]);validation=0; strcpy(lastNames[i],scan2[1]);}
        else{printf("Enter LastName Correctly\n");validation=1;}
        
        if(stringValidator(scan2[3])==0){strcpy(person[i].major,scan2[3]);validation=0;}
        else{printf("Enter Major Correctly\n");validation=1;}

        if(stringValidator(scan2[7])==0){strcpy(person[i].address,scan2[7]);validation=0;}
        else{printf("Enter Address Correctly\n");validation=1;}

        if(stringValidator(scan2[8])==0){strcpy(person[i].sex,scan2[8]);validation=0;}
        else{printf("Enter Sex Correctly\n");validation=1;}

        if(numberValidaion(scan2[5])==0){strcpy(person[i].homeNumber,scan2[5]);
        validation=0;}
        else if(numberValidaion(scan2[5])==1){printf("Enter Phone Correctly\n");validation=1;}
        else if(numberValidaion(scan2[5])==-1){printf("Enter Phone With City Code Or Enter It Correctly\n");validation=1;}

        if(numberValidaion(scan2[6])==0){strcpy(person[i].phoneNumber,scan2[6]);validation=0;}
        else if(numberValidaion(scan2[6])==1){printf("Enter Phone Correctly\n");validation=1;}
        else if(numberValidaion(scan2[6])==-1){printf("Enter Complete Phone Number Or Enter It Correctly\n");validation=1;}

        if(codeUValidation(scan2[2])==0){strcpy(person[i].uniNum,scan2[2]);validation=0; strcpy(uniNumbers[i],scan2[2]);}
        else{printf("Enter UniNumber Correctly\n");validation=1;}
        
        if(codeUValidation(scan2[4])==0){strcpy(person[i].idNum,scan2[4]);validation=0;}
        else{printf("Enter IdNumber Correctly\n");validation=1;}
        
        strcpy(person[i].nezamCode,"-");
        
        if(validation==0){
          fprintf(fp,"%s %s %s %s %s %s %s %s %s %s\n",person[i].name,person[i].familyName,person[i].uniNum,person[i].major,person[i].idNum,person[i].homeNumber,person[i].phoneNumber,person[i].address,person[i].sex,person[i].nezamCode);
          i++;
        }
      }
      fclose(fp);
    }
    else if(strcmp(command,"Sort By Name")==0){
      sortByName(i);
      for(int q=0;q<i;q++){
        for(int z=0;z<i;z++){
          if(strcmp(names[q], person[z].name)==0){
            sortedByName[q]=person[z];
          }
        }
      }
      fp=fopen("phonebook.txt", "w+");
      fp=fopen("phonebook.txt", "a+");
      for(int q=0;q<i;q++){
        fprintf(fp,"%s %s %s %s %s %s %s %s %s %s\n",sortedByName[q].name,sortedByName[q].familyName,sortedByName[q].uniNum,sortedByName[q].major,sortedByName[q].idNum,sortedByName[q].homeNumber,sortedByName[q].phoneNumber,sortedByName[q].address,sortedByName[q].sex,sortedByName[q].nezamCode);
      }
      fclose(fp);
    }
    else if(strcmp(command,"Sort By UniNum")==0){
      sortByUniNum(i);
      for(int q=0;q<i;q++){
        for(int z=0;z<i;z++){
          if(strcmp(uniNumbers[q], person[z].uniNum)==0){
            sortedByUniNumber[q]=person[z];
          }
        }
      }
      fp=fopen("phonebook.txt", "w+");
      fp=fopen("phonebook.txt", "a+");
      for(int q=0;q<i+1;q++){
        fprintf(fp,"%s %s %s %s %s %s %s %s %s %s\n",sortedByUniNumber[q].name,sortedByUniNumber[q].familyName,sortedByUniNumber[q].uniNum,sortedByUniNumber[q].major,sortedByUniNumber[q].idNum,sortedByUniNumber[q].homeNumber,sortedByUniNumber[q].phoneNumber,sortedByUniNumber[q].address,sortedByUniNumber[q].sex,sortedByUniNumber[q].nezamCode);
      }
      fclose(fp);
    }
    else if(strcmp(command,"Sort By LastName")==0){
      sortByLastName(i);
      for(int q=0;q<i;q++){
        for(int z=0;z<i;z++){
          if(strcmp(lastNames[q], person[z].familyName)==0){
            sortedByLastName[q]=person[z];
          }
        }
      }
      fp=fopen("phonebook.txt", "w+");
      fp=fopen("phonebook.txt", "a+");
      for(int q=0;q<i+1;q++){
        fprintf(fp,"%s %s %s %s %s %s %s %s %s %s\n",sortedByLastName[q].name,sortedByLastName[q].familyName,sortedByLastName[q].uniNum,sortedByLastName[q].major,sortedByLastName[q].idNum,sortedByLastName[q].homeNumber,sortedByLastName[q].phoneNumber,sortedByLastName[q].address,sortedByLastName[q].sex,sortedByLastName[q].nezamCode);
      }
      fclose(fp);
    }
    else if(strcmp(command,"Search By Name")==0){
      char enteredname[30];
      int exist=1;
      printf("Enter name : ");
      scanf("%[^\n]%*c",enteredname);
      for(int ls=0;ls<=i;ls++){
      if(strcmp(person[ls].name,enteredname)==0){
            printf("%s %s %s %s %s %s %s %s %s %s\n",person[ls].name,person[ls].familyName,person[ls].uniNum,person[ls].major,person[ls].idNum,person[ls].homeNumber,person[ls].phoneNumber,person[ls].address,person[ls].sex,person[ls].nezamCode);
            exist=0;
            break;
          }
      }
      if(exist==1){
          printf("That Name Does Not Exist Or Not Correctly\n");
      }
    }
    else if(strcmp(command,"edit")==0){
      char enteredname[30];
      int exist=1;
      char enteredpart[30];
      char newpart[30];
      printf("Enter name : ");
      scanf("%[^\n]%*c",enteredname);
      printf("Which Part : ");
      scanf("%[^\n]%*c",enteredpart);
      printf("To Be Change To : ");
      scanf("%[^\n]%*c",newpart);
      for(int ls=0;ls<=i;ls++){
        if(strcmp(person[ls].name,enteredname)==0){
          if(strcmp(enteredpart,"Name")==0)
          {
            strcpy(person[ls].name,newpart);
          }
          if(strcmp(enteredpart,"LastName")==0){
             strcpy(person[ls].familyName,newpart);
          }
          if(strcmp(enteredpart,"UniNum")==0){
             strcpy(person[ls].uniNum,newpart);
          }
          if(strcmp(enteredpart,"Major")==0){
            strcpy(person[ls].major,newpart);
          }
          if(strcmp(enteredpart,"IdNum")==0){
            strcpy(person[ls].idNum,newpart);
          }
          if(strcmp(enteredpart,"HomeNumber")==0){
            strcpy(person[ls].homeNumber,newpart);
          }
          if(strcmp(enteredpart,"PhoneNumber")==0){
            strcpy(person[ls].phoneNumber,newpart);
          }
          if(strcmp(enteredpart,"Address")==0){
            strcpy(person[ls].address,newpart);
          }
          if(strcmp(enteredpart,"Sex")==0){
            strcpy(person[ls].sex,newpart);
          }
          if(strcmp(enteredpart,"NezamCode")==0){
            strcpy(person[ls].nezamCode,newpart);
          }
          exist=0;
        }
        
      }
      fp=fopen("phonebook.txt", "w+");
      for(int q=0;q<i;q++){
        fprintf(fp,"%s %s %s %s %s %s %s %s %s %s\n",person[q].name,person[q].familyName,person[q].uniNum,person[q].major,person[q].idNum,person[q].homeNumber,person[q].phoneNumber,person[q].address,person[q].sex,person[q].nezamCode);
      }
      if(exist==1){printf("That Name Does Not Exist Or Not Correctly\n");}
      fclose(fp);
    }
    else if(strcmp(command,"remove")==0){
      char enteredname[30];
      int exist=1;
      printf("Enter name : ");
      scanf("%[^\n]%*c",enteredname);
      for(int rl=0;rl<=i;rl++){
        if(strcmp(enteredname, person[rl].name)==0){
          for(int r=rl; r<i-1; r++)
          {
            person[r] = person[r+1];
          }
          exist=0;
        }
      }
      i--;
      fp=fopen("phonebook.txt", "w+");
      fp=fopen("phonebook.txt", "a+");
      for(int q=0;q<i;q++){
        fprintf(fp,"%s %s %s %s %s %s %s %s %s %s\n",person[q].name,person[q].familyName,person[q].uniNum,person[q].major,person[q].idNum,person[q].homeNumber,person[q].phoneNumber,person[q].address,person[q].sex,person[q].nezamCode);
      }
      if(exist==1){printf("That Name Does Not Exist Or Not Correctly");}
      fclose(fp);
    }
    else if(strcmp(command,"remove info")==0){
      char enteredname[30];
      int exist=1;
      char enteredpart[30];
      printf("Enter name : ");
      scanf("%[^\n]%*c",enteredname);
      printf("Which Part : ");
      scanf("%[^\n]%*c",enteredpart);
      for(int ls=0;ls<=i;ls++){
        if(strcmp(person[ls].name,enteredname)==0){
          if(strcmp(enteredpart,"Name")==0)
          {
            strcpy(person[ls].name," ");
          }
          if(strcmp(enteredpart,"LastName")==0){
             strcpy(person[ls].familyName," ");
          }
          if(strcmp(enteredpart,"UniNum")==0){
             strcpy(person[ls].uniNum," ");
          }
          if(strcmp(enteredpart,"Major")==0){
            strcpy(person[ls].major," ");
          }
          if(strcmp(enteredpart,"IdNum")==0){
            strcpy(person[ls].idNum," ");
          }
          if(strcmp(enteredpart,"HomeNumber")==0){
            strcpy(person[ls].homeNumber," ");
          }
          if(strcmp(enteredpart,"PhoneNumber")==0){
            strcpy(person[ls].phoneNumber," ");
          }
          if(strcmp(enteredpart,"Address")==0){
            strcpy(person[ls].address," ");
          }
          if(strcmp(enteredpart,"Sex")==0){
            strcpy(person[ls].sex," ");
          }
          if(strcmp(enteredpart,"NezamCode")==0){
            strcpy(person[ls].nezamCode," ");
          }
          exist=0;
        }
      
      }
      fp=fopen("phonebook.txt", "w+");
      fp=fopen("phonebook.txt", "a+");
      for(int q=0;q<i;q++){
        fprintf(fp,"%s %s %s %s %s %s %s %s %s %s\n",person[q].name,person[q].familyName,person[q].uniNum,person[q].major,person[q].idNum,person[q].homeNumber,person[q].phoneNumber,person[q].address,person[q].sex,person[q].nezamCode);
      }
      if(exist==1){printf("That Name Does Not Exist Or Not Correctly");}
      fclose(fp);
    }
    else{printf("Enter correct command\n");}
    printf("Enter your command : ");
    scanf("%[^\n]%*c",command);
  }
}
int numberValidaion(char str[50]){
  int check=0;
  int checking=1;
  while(check<strlen(str)){
    if(str[check]>= '0' && str[check]<='9'){
      checking=0;
    } 
    else{
      checking=1;
    }
    check++;
  }
  if(checking==0 && check==11){
      return 0;
    } 
  else if(checking!=0){
      return 1;
  }
  else if(check!=11){
    return -1;
  }
  else{return 2;};
}
void sortByName(int n){
  int i, j;
  char temp[40];
  for (i = 0; i < n-1; i++)
  {
        for (j = 0; j < (n-i-1); j++)
        {
          if(names[j][0]>names[j+1][0]){
            strcpy(temp,names[j]);
            strcpy(names[j],names[j+1]);
            strcpy(names[j+1],temp);
          }
          else if(names[j][0]==names[j+1][0] && names[j][1]>names[j+1][1]){
            strcpy(temp,names[j]);
            strcpy(names[j],names[j+1]);
            strcpy(names[j+1],temp);
          }
        }
  }
  
}
void sortByLastName(int n){
  int i, j;
  char temp[40];
  for (i = 0; i < n-1; i++)
  {
        for (j = 0; j < (n-i-1); j++)
        {
          if(lastNames[j][0]>lastNames[j+1][0]){
            strcpy(temp,lastNames[j]);
            strcpy(lastNames[j],lastNames[j+1]);
            strcpy(lastNames[j+1],temp);
          }
          else if(lastNames[j][0]==lastNames[j+1][0] && lastNames[j][1]>lastNames[j+1][1]){
            strcpy(temp,lastNames[j]);
            strcpy(lastNames[j],lastNames[j+1]);
            strcpy(lastNames[j+1],temp);
          }
        }
  }
}
void sortByUniNum(int n){
  int i, j;
  int x,y;
  char temp[40];
  for (i = 0; i < n-1; i++)
  {
        for (j = 0; j < (n-i-1); j++)
        {
          if(atoi(uniNumbers[j])>atoi(uniNumbers[j+1])){
            strcpy(temp,uniNumbers[j]);
            strcpy(uniNumbers[j],uniNumbers[j+1]);
            strcpy(uniNumbers[j+1],temp);
          }
        }
  }
}
int stringValidator(char str[50]){
  int check=0;
  int checking=1;
  while(check<strlen(str)){
    if((str[check]>= 'a' && str[check]<='z') || (str[check]>= 'A' && str[check]<='Z')){
      checking=0;
    } 
    else{
      checking=1;
    }
    check++;
  }
  if(checking==0){
      return 0;
    } 
  else{
    return 1;
  }
}
int codeUValidation(char str[50]){
  int check=0;
  int checking=1;
  while(check<strlen(str)){
    if(str[check]>= '0' && str[check]<='9'){
      checking=0;
    } 
    else{
      checking=1;
    }
    check++;
  }
  if(checking==0){
    return 0;
  }
  else{
    return 1;
  }
}