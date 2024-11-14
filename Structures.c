#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//enum of positions of players in the team
enum pos {
        Forward=1,
        Goalkeeper=2,
        Defender=3,
        Midfielder=4,
    };

//structure where we can write all characteristics of a person
struct person {
    int id;
    char name[1000];
    enum pos position;
    int age;
    int goals;
};

//transformation enum input data to string to put it in p[k].pos
enum pos transformation(char s[]){
    if (strcmp(s,"Forward")==0)
        return Forward;
    if (strcmp(s,"Goalkeeper")==0)
        return Goalkeeper;
    if (strcmp(s,"Defender")==0)
        return Defender;
    if (strcmp(s,"Midfielder")==0)
        return Midfielder;
    return -1;
}

int main() {
    FILE *a = fopen("input.txt", "r");                 // a - to read, b - to write
    FILE *b = fopen("output.txt", "w");
    char alp[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char n[30]="a", s[100];
    int k=0, h, f=0, flag=0, update_ind, delete_ind; // f and flag - flags in 2 other situations
    struct person p[100];

    while(strcmp(n, "Display")!=0) {
        fscanf(a, "%s", n);                            // scan command "Add", "Delete", "Search" and "Update"
        //ADD command
        if(strcmp(n, "Add")==0) {

            //ID SCAN - START
            fscanf(a, "%d", &p[k].id);
            if(k>0) {
                for(int i=0; i<k; i++)               /// e) check that new ID is unique
                    if(p[k].id==p[i].id) {
                    fprintf(b, "Invalid inputs\n");
                    return 0;
                }
            }
            //ID SCAN - END

            //NAME SCAN - START
            fscanf(a, "%s", p[k].name);
            for(int i=0; i<26; i++) {               /// check a) name starts with a capital letter
                if(p[k].name[0]==alp[i]) flag=1;
            }
            if(flag==0) {
                fprintf(b, "Invalid inputs\n");
                return 0;
            }
            flag=0;
            for(int j=0; j<strlen(p[k].name); j++) { /// check c) name contains only English letters
                for(int i=0; i<52; i++) {
                    if(p[k].name[j]==alp[i]) f=1;
                }
                if(f==0) {
                    fprintf( b, "Invalid inputs\n");
                    return 0;
                }
                f=0;
            }
            if(strlen(p[k].name)<2 || strlen(p[k].name)>15) { /// check b) 2 <= name length <= 15
                fprintf(b, "Invalid inputs\n");
                return 0;
            }
            //NAME SCAN - END

            //POS SCAN - START
            fscanf(a, "%s", s); //use enum type to write person's position data
            p[k].position = transformation(s);

            //POS SCAN - END

            //AGE SCAN - START
            fscanf(a, "%d", &p[k].age);

            if(p[k].age<18 || p[k].age>100) {   ///check f) 18 <  age < 100
                fprintf(b, "Invalid inputs\n");
                return 0;
            }
            //AGE SCAN - END

            //GOALS SCAN - START
            fscanf(a, "%d", &p[k].goals);
            if(p[k].goals<0 || p[k].goals>=1000) { /// check g) 0 <= goals <= 1000
                fprintf(b, "Invalid inputs\n");
                return 0;
            }
            //GOALS SCAN - END
            k=k+1;


        }
        //UPDATE
        else if(strcmp(n, "Update")==0) {
            fscanf(a, "%d", &h);
            for(int i=0; i<k; i++)
                if(p[i].id==h){
                    f=1;
                    update_ind=i;
                }
            if(f==0) {
                fprintf(b, "Invalid inputs\n"); //print error if we can't find existed id
                return 0;
            }

            else {
                //SCAN NAME FOR UPDATE - START
                fscanf(a, "%s", p[update_ind].name);
                for(int i=0; i<26; i++) {
                    if(p[update_ind].name[0]==alp[i]) flag=1;
                }
                if(flag==0) {
                    fprintf(b, "Invalid inputs\n");
                    return 0;
                }
                flag=0;
                for(int j=0; j<strlen(p[update_ind].name); j++) {
                    for(int i=0; i<52; i++) {
                        if(p[update_ind].name[j]==alp[i]) f=1;
                    }
                    if(f==0) {
                        fprintf(b, "Invalid inputs\n");
                        return 0;
                        }
                    f=0;
                }
                if(strlen(p[update_ind].name)<2 || strlen(p[update_ind].name)>15) {
                    fprintf(b, "Invalid inputs\n");
                    return 0;
                }
                //SCAN NAME FOR UPDATE - END

                //SCAN POS FOR UPDATE - START
                fscanf(a, "%s", s);
                p[update_ind].position = transformation(s);
                //SCAN POS FOR UPDATE - END

                //SCAN AGE FOR UPDATE - START
                fscanf(a, "%d", &p[update_ind].age);
                if(p[update_ind].age<18 || p[update_ind].age>100) {
                    fprintf( b, "Invalid inputs\n");
                    return 0;
                }
                //SCAN AGE FOR UPDATE - END

                //SCAN GOALS FOR UPDATE - START
                fscanf(a, "%d", &p[update_ind].goals);
                if(p[update_ind].goals<0 || p[update_ind].goals>=1000) {
                    fprintf(b, "Invalid inputs\n");
                    return 0;
                }
                //SCAN GOALS FOR UPDATE - END
            }
            f=0;


        }

        //DELETE
        else if(strcmp(n, "Delete")==0) {
            //SCAN ID TO DELETE
            fscanf(a, "%d", &h);
            for(int i=0; i<k; i++)
                if(p[i].id==h){
                    f=1;
                    delete_ind=i;
                }
            if(f==0) {
                fprintf(b, "Impossible to delete\n");
            }

            else {
                p[delete_ind].id=0;
                p[delete_ind].age=0;
                p[delete_ind].goals=0;
            }
            f=0;

        }

        //SEARCH
        else if(strcmp(n, "Search")==0) {
            //SCAN ID TO SEARCH
            fscanf(a, "%d", &h);
            for(int i=0; i<k; i++)
                if(p[i].id==h)
                    f=1;
            if(f==1)
                fprintf(b, "Found\n");
            else
                fprintf(b, "Not found\n");
            f=0;
        }
        else if(strcmp(n, "Display")!=0) {
            fprintf(b, "Invalid inputs\n");
            return 0;
        }

    /// the last line "Display" was entered, let`s show the received data:
    }
    if(k==0) {
            fprintf(b, "Invalid inputs\n"); // check if input file contains inly command "Display"
            return 0;
    }
    for(int i=0; i<k; i++) // check if we delete all added persons
        if(p[i].id!=0)
            f=1;
    if(!f){
            fprintf(b, "Invalid inputs\n");
            return 0;
    }
    for(int i=0; i<k; i++)  {
        if(p[i].id!=0) {
            switch(p[i].position) {                
                case 1:
                    fprintf(b, "ID: %d, ", p[i].id);
                    fprintf(b, "Name: %s, ", p[i].name);
                    fprintf(b, "Position: Forward, ");
                    break;
                case 2:
                    fprintf(b, "ID: %d, ", p[i].id);
                    fprintf(b, "Name: %s, ", p[i].name);
                    fprintf(b, "Position: Goalkeeper, ");
                    break;
                case 3:
                    fprintf(b, "ID: %d, ", p[i].id);
                    fprintf(b, "Name: %s, ", p[i].name);
                    fprintf(b, "Position: Defender, ");
                    break;
                case 4:
                    fprintf(b, "ID: %d, ", p[i].id);
                    fprintf(b, "Name: %s, ", p[i].name);
                    fprintf(b, "Position: Midfielder, ");
                    break;
                default:
                    fprintf(b, "Invalid inputs\n");     //invalid if position is another word 
                    return 0;
                    break;
            }
            fprintf(b, "Age: %d, ", p[i].age);          //age
            fprintf(b, "Goals: %d\n", p[i].goals);      //goals

        }

    }
    fclose(a); //close files
    fclose(b);

}
