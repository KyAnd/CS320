#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
// CS320, Dr. John Carroll, Due 4-30-18, Andrew Botros, cssc0118 program 4
int main ( int argc, char *argv[] ) {
     FILE *fp;
     FILE *ofp;
// I tried setting return values using errno when a file error was encountered but the number 3 or a large number would appear
//exit messed up my file pointers I believe, and failed to do anything about the return value for JUST file errors.

int g=1;
int noarg=0;
int d=0;
int n=0;
int o=0;
int done=0;
int y=1;
int e=1;
int opflag=0;
int h=1;
if(argv[1]==NULL) {
    fp=stdin;
    ofp=stdout;
    dothis(fp,ofp);

}
else {

while(g<argc) {
   while(argv[g][0]!= '-' && argv[e]!=NULL) {
        //if the character is equal to a hyphen then it is safe to assume the other branches will take care of it
              if(argv[e][0]=='-') {
            break;
        }


        fp=fopen(argv[e],"r");
        if(fp==NULL) {
            fprintf(stderr, "You made an error \n");
            ++e; // you want to go through the loop even if one error exists

        }



        else {
            ofp=stdout;
            dothis(fp,ofp);
            ++e;

        }

    }


 if(strcmp (argv[g],"-o")==0 && argc!=2) {

if(argc==3) {//if there are 3 arguments the naturally all you would have to do is check the
    fp=stdin;
}
else {
    fp=fopen(argv[g-1],"r"); //if there is a dash o you want to grab the argument before it for writing,
     //the check at the top ensures there are atleast 2 args
}
ofp=fopen(argv[g+1],"w");

dothis(fp,ofp);
}

 if (strcmp(argv[g],"-o")==0 && argc==2) {//if there are 2 arguments at all with -o it simply will never work
        fprintf(stderr, "Incorrect use of -o ");
 }



      if(strcmp(argv[g],"-d")==0) {
d=g;

        if(argv[d+1]==NULL) {
            fprintf( stderr, "Incorrect parameters");
             break;
        }
        else {
         ++d;
        for(;argv[d]!=NULL;++d) { //start a loop under the if condition that does -d until -o or any hyphen is reached
                if(argv[d][0]=='-' && strcmp(argv[d],"-o")!=0) {
                    break;
                }
                 if( strcmp(argv[d],"-o")==0) {
                if(argv[d+1]==NULL) {
                    fprintf(stderr,"Invalid use of -o", 22);

                }
                else {

                    ofp=fopen(argv[d+1],"w");
                    noarg=1;
                }
                 }

if(noarg==1) {
    fp=fopen(argv[d-1],"r");//this checks to make sure that the file can be read in the event a -o is here
}
else {
        fp=fopen(argv[d],"r");
}
        if(fp==NULL) {
                fprintf(stderr,"File does not exist\n");

        }
        else {
                if(noarg==1) {
                    trythis(fp,ofp);
                    noarg=0; //reset no arg so the outer while doesn't interfere
                }
                else {
                    ofp=stdout;
                    trythis(fp,ofp);
                }


        }




        }

        }
       }
        if(strcmp(argv[g],"-n")==0)  {

 n=g;
        if(argv[n+1]==NULL) {
            fprintf( stderr, "Incorrect parameters");
             break;
        }
        else { //same process for the above continue -n until a hyphen or -o is reached since both lead to the same conclusion aka stop doing this process
         ++n;
        for(;argv[n]!=NULL;++n) {
             if(argv[n][0]=='-' && strcmp(argv[n],"-o")!=0) {
                    break;
                }
                  if( strcmp(argv[n],"-o")==0) {
                if(argv[n+1]==NULL) {
                    fprintf(stderr,"Invalid use of -o",22);

                }
                else {

                    ofp=fopen(argv[n+1],"w");
                    noarg=1;
                }
                 }

if(noarg==1) {
    fp=fopen(argv[n-1],"r");
}
else {
        fp=fopen(argv[n],"r");
}
        if(fp==NULL) {
                fprintf(stderr,"File does not exist\n");

        }
        else {
                if(noarg==1) {
                    dothis(fp,ofp);
                    noarg=0;
                }
                else {
                    ofp=stdout;
                    dothis(fp,ofp);
                }


        }
        }

        }
        }









    ++g; //increment g so every condition can be checked until there are no more left
}

}
}

#define MAX 80
int dothis(FILE *fp,FILE *ofp) {
int array1[MAX];
int array2[MAX];
int limit1=0;
int change1=0;
int a=1;
int b=0;
int i=0;
int x=0;
int z=0;
int flag=0;
int changed=0;
int matches=0;
int editor=0;
int last=0;
int lines=0;
int s=0;
while(!(feof(fp))) { //make sure we don't gather data from a non existent source
for(i=0;i<MAX;++i) {

//get 80 chars at max, if a newline is encountered or a EOF is, leave this for loop
    array1[i]=getc(fp);
if(array1[i]==EOF) {
         last=1;
    limit1=i;
    break;

}
if(array1[i]=='\n') {
limit1=i+1;
    break;
}

}
if(i==MAX) {
        ++lines;
   limit1=i;

}





for(x=0;x<limit1;++x) {
if(array1[x]!=array2[x]) {
flag=1;
break; //if at any time they are different, then they are not identical so the loop is not needed and the flag is set
}
else { //if it goes through every character and != is false, then they are identical
    flag=0;
}

}

if(flag==0 ) {


        i=0;
x=0; //if they are the same reset the appropriate variables and continue to the outermost while loop, essentially restart the process
    continue;
}


else {



        for(z=0;z<limit1;++z) {
 array2[z]=array1[z]; //copy array1 into array2 if they are found to be distinct lines
}
//most of this was taken and adapted from p1.c and that inspiration and guideline was provided by the Sebesta text epp8.c in particular

for(change1=0;change1<limit1;++change1) {
    if(array1[change1]>='A' && array1[change1] <= 'Z') {
putc(array1[change1]+32,ofp);
++changed;
    }
 else if(array1[change1]>='a' && array1[change1] <= 'z') {

putc(array1[change1]-32, ofp);
++changed;
 }
  else if(array1[change1]>='0' && array1[change1]<='9') {
     ++changed;
}

else if(array1[change1]==' ') {
putc(' ',ofp);//for every space print a space twice since two spaces in single quotes is a multi character
putc(' ',ofp);
++changed;

}
else if(array1[change1]== '\n') {
    putc('\n',ofp);
    ++changed;
}

else{
putc(array1[change1],ofp);//if none of the above criteria are met, then the input is fair game and is to be outputted
}
}
if(i==MAX) { //this is the edge test case for over maxchars, function seemed to break on some of the if statements above and printing stray characters
        //such as a letter would appear randomly, most likely do to the various loops and if statements that crossed over
    while (1) {
        editor=getc(fp);
if((editor>='A') && (editor <= 'Z')) {
    editor=editor+32;
}
else if((editor>='a') && (editor<='z')) {
        editor=editor-32;
}

            putc(editor,ofp);
            if(editor=='\n') {
                break;

            }
    }



       if(lines==1 && i==MAX) { //test the edge case, always print the first line because there is no previous
  while(1) {
        if(s==2) {
            break;
        }
        int fix=getc(fp);
        if(fix=='\n') { //grab the appropriate characters off the stream
        ++s;
        }
     }

    }

    }

z=0;
i=0;
x=0;
change1=0;
limit1=0;
}//close else

}

if(changed==3) {
    return 1; //this is the magic number, somehow regardless of output changed is always 3 if nothing was changed
}
else {
    return 0;
}


}



int trythis(FILE *fp,FILE *ofp) {
int array1[MAX];
int array2[MAX];
int array3[MAX];
int limit1=0;
int change1=0;
int i=0;
int x=0;
int z=0;
int r=0;
int t=0;
int flag=0;
int changed=0;
int matches=0;
int lastcheck=0;
int s=0;
while(!(feof(fp))) {
for(i=0;i<80;++i) {
    array1[i]=getc(fp);
if(array1[i]==EOF) {
    limit1=i;
    lastcheck=1;
    break;
}
if(array1[i]=='\n') {
limit1=i+1;
    break;
}
else {
    limit1=i+1;
}
}
for(r=0;r<80;++r) {
    array2[r]=getc(fp);
if(array2[r]==EOF) {
    limit1=r;
    lastcheck=1;
    break; //check for the last line so we don't eat up past the EOF
}
if(array2[r]=='\n') {
limit1=r+1; //if a newline is encountered you want to grab the newline in the less than for loop, meaning the limit should be one higher
    break;
}
else {
    limit1=r+1;
} //same as above, grab the necessary chars including the last one
}


        for(s=0;s<limit1;++s) {
 array3[s]=array1[s]; //when you grab the first two lines, store the first one into a copy
}


for(x=0;x<limit1;++x) {
if(array1[x]!=array2[x]) {
flag=0;
break;
} //same match checking in the other function
else {
    flag=1;


}
if(flag==1) {
   for(t=0;t<limit1;++t) {
 if(array3[t]!=array1[t] ) {
    flag=0;
  break; //if they are different, check to make sure it isn't a duplicate with the copy array
}
else {
    flag=1; // then if that is not true then it matches with array3 it is a duplicate
}
   }
}




if(flag==0) {
        i=0;
x=0;
s=0;
r=0;
    continue;
}

if(lastcheck!=1) {
        for(z=0;z<limit1;++z) {
 array2[z]=array1[z]; //if the second line is the last line don't try to grab another line after EOF
}

for(change1=0;change1<limit1;++change1) {
    if(array1[change1]>='A' && array1[change1] <= 'Z') {
putc(array1[change1]+32,ofp);
++changed;
    }
 else if(array1[change1]>='a' && array1[change1] <= 'z') {

putc(array1[change1]-32, ofp);
++changed;
 }
  else if(array1[change1]>='0' && array1[change1]<='9') {
++changed;

}

else if(array1[change1]==' ') {
putc(' ',ofp);//for every space print a space twice since two spaces in single quotes is a multi character
putc(' ',ofp);
++changed;

}
else if(array1[change1]== '\n') {
    putc('\n',ofp);
}

else{
putc(array1[change1],ofp);//if none of the above criteria are met, then the input is fair game and is to be outputted
}
}

z=0;
i=0;
x=0;
change1=0;
limit1=0;
}//close else
}
}
if(changed==3) {
    return 1;
}
else {
    return 0; //same magic numbers as before, I don't get it either....
}
}


