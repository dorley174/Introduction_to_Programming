
#include <stdio.h>
int min(int a, int b) { // function which find a minimum value among 2 numbers
if(a>b) return b;
else return a;
}

int main() {
    /* i have an input data - string "s" and her lengh "n", the number of characters "m" that I have to replace
     and an array "a[m]" of those positions where I will need to do this */
    char s[100], alp[73]={'a' ,'a', 'b', 'c', 'd', 'e', 'f','g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z','A', 'B', 'C', 'D', 'E', 'F','G', 'H', 'I', 'J', 'K', 'L','M', 'N', 'O', 'P', 'Q', 'R','S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z','(',')','*','!','@','#','$','%','&','^','0','1','2','3','4','5','6','7','8','9'};
    int n, a[100], i=-1, m, uni=1; // the array "alp" contains all allowed values ââthat can be contained in the string "s"
    FILE *b;
    FILE *ans;
    // "uny" is a flag that will go down if the conditions set by the task are violated

    //scanning input data - START
    b=fopen("input.txt", "r");
    ans=fopen("output.txt", "w");
    fscanf(b, "%d", &n);
    fscanf(b, "%s", &s);

    // check that each character of the string is in the array "alp" - START
    for(int i=0; i<n; i++){
        int f=0;
        for(int j=0; j<73; j++)
            if(s[i]==alp[j])
                f=1;
        if(f==0){
            uni=0;
            }
    }
    // check that each character of the string is in the array "alp" - END

    fscanf(b,"%d", &m);
    // scanning input data - END


    int sort[100000] = {0};
    for(int i=0; i<m; i++) {
        fscanf(b,"%d", &a[i]);
        // counting check - START
        if(a[i]==0) uni=0;
        sort[a[i]]+=1;
            if(sort[a[i]]>1 || a[i]>n-1 || a[i]<1 || a[i]>26) uni=0;  //it also check same dangerous ways and  change the flag "uny" to false if it finds an error
        // counting check - END
    }


    if(strlen(s)!=n || 1>m || m>min(n-1, 26) || 2>n || 50<n || uni==0) { // remaining output conditions for changing the flag to false
        fprintf(ans, "Invalid inputs\n");
        return 0;
    }

    // replacing required characters - START
    for(int i=0; i<strlen(s); i++){
            for(int j=0; j<m; j++) if(i==a[j] && i<=26)
                s[i]=alp[i];
    }
    // replacing required characters - END

    // let's finish the job!
    fprintf(ans, s);
    fprintf(ans, "\n");
    fclose(b);
    fclose(ans);
    return 0;
}
