#include <stdio.h>
int main() {

int changed=0;
int editor=0;
int newline=0;

while((editor=getchar())!=EOF) {
int countline=0;
if(editor>='0' && editor<='9') {
++changed;
countline=0;//any time the counter for newlines indicates the end of consecutive newlines the count is reset in case another group occurs, used in every branch
}
else if((editor>='A') && (editor <= 'Z')) {//Courtesy of C by Discovery 4th Edition Foster & Foster "epp8.c" for the code regarding upper and lowercase chars
putchar(editor+32);
++changed;
countline=0;
}
else if((editor>='a') && (editor<='z')) {
putchar(editor-32);
++changed;
countline=0;
}
else if( editor=='\n' && countline==0) {//if it is the first newline encountered the counter is increment
++countline;
}
else if(editor=='\n' && countline==1 ) {//if the previous branch is true this one will always execute indicating non consecutive newline
putchar('\n');
++countline;
}
else if(editor=='\n' && countline>=2) {//any time its consecutive you increment to prevent the exeucting the else statement which prints the current char
++countline;
}

else if(editor==' ') {
putchar(' ');//for every space print a space twice since two spaces in single quotes is a multi character
putchar(' ');
++changed;
countline=0;
}


else{
putchar(editor);//if none of the above criteria are met, then the input is fair game and is to be outputted
}


}
close(editor);
if(changed>0) {//any time a statement executes a change the counter is incremented thus any change made will trigger the return statement
return 0;
}
else {
return 1;//if changed is = to 0 then it falls to this statement returning the desired value
}

}
